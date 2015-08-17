/*-
 * Copyright (c) 2002-2010 M. Warner Losh.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * my_system is a variation on lib/libc/stdlib/system.c:
 *
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * DEVD control daemon.
 */

// TODO list:
//	o devd.conf and devd man pages need a lot of help:
//	  - devd needs to document the unix domain socket
//	  - devd.conf needs more details on the supported statements.

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: soc2013/dpl/head/sbin/devd/devd.cc 251387 2013-05-02 17:02:50Z eadler $");

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/un.h>

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>

#include <dirent.h>
#include <err.h>
#include <fcntl.h>
#include <libutil.h>
#include <paths.h>
#include <poll.h>
#include <regex.h>
#include <unistd.h>

#include <algorithm>
#include <map>
#include <string>
#include <list>
#include <vector>

#include "devd.h"		/* C compatible definitions */
#include "devd.hh"		/* C++ class definitions */

#define PIPE "/var/run/devd.pipe"
#define CF "/etc/devd.conf"
#define SYSCTL "hw.bus.devctl_disable"

using namespace std;

extern FILE *yyin;
extern int lineno;

static const char notify = '!';
static const char nomatch = '?';
static const char attach = '+';
static const char detach = '-';

static struct pidfh *pfh;

int Dflag;
int dflag;
int nflag;
static volatile sig_atomic_t romeo_must_die = 0;

static const char *configfile = CF;

static void event_loop(void);
static void usage(void);

template <class T> void
delete_and_clear(vector<T *> &v)
{
	typename vector<T *>::const_iterator i;

	for (i = v.begin(); i != v.end(); ++i)
		delete *i;
	v.clear();
}

config cfg;

event_proc::event_proc() : _prio(-1)
{
	_epsvec.reserve(4);
}

event_proc::~event_proc()
{
	delete_and_clear(_epsvec);
}

void
event_proc::add(eps *eps)
{
	_epsvec.push_back(eps);
}

bool
event_proc::matches(config &c) const
{
	vector<eps *>::const_iterator i;

	for (i = _epsvec.begin(); i != _epsvec.end(); ++i)
		if (!(*i)->do_match(c))
			return (false);
	return (true);
}

bool
event_proc::run(config &c) const
{
	vector<eps *>::const_iterator i;
		
	for (i = _epsvec.begin(); i != _epsvec.end(); ++i)
		if (!(*i)->do_action(c))
			return (false);
	return (true);
}

action::action(const char *cmd)
	: _cmd(cmd) 
{
	// nothing
}

action::~action()
{
	// nothing
}

static int
my_system(const char *command)
{
	pid_t pid, savedpid;
	int pstat;
	struct sigaction ign, intact, quitact;
	sigset_t newsigblock, oldsigblock;

	if (!command)		/* just checking... */
		return(1);

	/*
	 * Ignore SIGINT and SIGQUIT, block SIGCHLD. Remember to save
	 * existing signal dispositions.
	 */
	ign.sa_handler = SIG_IGN;
	::sigemptyset(&ign.sa_mask);
	ign.sa_flags = 0;
	::sigaction(SIGINT, &ign, &intact);
	::sigaction(SIGQUIT, &ign, &quitact);
	::sigemptyset(&newsigblock);
	::sigaddset(&newsigblock, SIGCHLD);
	::sigprocmask(SIG_BLOCK, &newsigblock, &oldsigblock);
	switch (pid = ::fork()) {
	case -1:			/* error */
		break;
	case 0:				/* child */
		/*
		 * Restore original signal dispositions and exec the command.
		 */
		::sigaction(SIGINT, &intact, NULL);
		::sigaction(SIGQUIT,  &quitact, NULL);
		::sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
		/*
		 * Close the PID file, and all other open descriptors.
		 * Inherit std{in,out,err} only.
		 */
		cfg.close_pidfile();
		::closefrom(3);
		::execl(_PATH_BSHELL, "sh", "-c", command, (char *)NULL);
		::_exit(127);
	default:			/* parent */
		savedpid = pid;
		do {
			pid = ::wait4(savedpid, &pstat, 0, (struct rusage *)0);
		} while (pid == -1 && errno == EINTR);
		break;
	}
	::sigaction(SIGINT, &intact, NULL);
	::sigaction(SIGQUIT,  &quitact, NULL);
	::sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
	return (pid == -1 ? -1 : pstat);
}

bool
action::do_action(config &c)
{
	string s = c.expand_string(_cmd.c_str());
	if (Dflag)
		fprintf(stderr, "Executing '%s'\n", s.c_str());
	my_system(s.c_str());
	return (true);
}

match::match(config &c, const char *var, const char *re) :
	_inv(re[0] == '!'),
	_var(var),
	_re(c.expand_string(_inv ? re + 1 : re, "^", "$"))
{
	regcomp(&_regex, _re.c_str(), REG_EXTENDED | REG_NOSUB | REG_ICASE);
}

match::~match()
{
	regfree(&_regex);
}

bool
match::do_match(config &c)
{
	const string &value = c.get_variable(_var);
	bool retval;

	if (Dflag)
		fprintf(stderr, "Testing %s=%s against %s, invert=%d\n",
		    _var.c_str(), value.c_str(), _re.c_str(), _inv);

	retval = (regexec(&_regex, value.c_str(), 0, NULL, 0) == 0);
	if (_inv == 1)
		retval = (retval == 0) ? 1 : 0;

	return retval;
}

#include <sys/sockio.h>
#include <net/if.h>
#include <net/if_media.h>

media::media(config &, const char *var, const char *type)
	: _var(var), _type(-1)
{
	static struct ifmedia_description media_types[] = {
		{ IFM_ETHER,		"Ethernet" },
		{ IFM_TOKEN,		"Tokenring" },
		{ IFM_FDDI,		"FDDI" },
		{ IFM_IEEE80211,	"802.11" },
		{ IFM_ATM,		"ATM" },
		{ -1,			"unknown" },
		{ 0, NULL },
	};
	for (int i = 0; media_types[i].ifmt_string != NULL; ++i)
		if (strcasecmp(type, media_types[i].ifmt_string) == 0) {
			_type = media_types[i].ifmt_word;
			break;
		}
}

media::~media()
{
}

bool
media::do_match(config &c)
{
	string value;
	struct ifmediareq ifmr;
	bool retval;
	int s;

	// Since we can be called from both a device attach/detach
	// context where device-name is defined and what we want,
	// as well as from a link status context, where subsystem is
	// the name of interest, first try device-name and fall back
	// to subsystem if none exists.
	value = c.get_variable("device-name");
	if (value.empty())
		value = c.get_variable("subsystem");
	if (Dflag)
		fprintf(stderr, "Testing media type of %s against 0x%x\n",
		    value.c_str(), _type);

	retval = false;

	s = socket(PF_INET, SOCK_DGRAM, 0);
	if (s >= 0) {
		memset(&ifmr, 0, sizeof(ifmr));
		strncpy(ifmr.ifm_name, value.c_str(), sizeof(ifmr.ifm_name));

		if (ioctl(s, SIOCGIFMEDIA, (caddr_t)&ifmr) >= 0 &&
		    ifmr.ifm_status & IFM_AVALID) {
			if (Dflag)
				fprintf(stderr, "%s has media type 0x%x\n", 
				    value.c_str(), IFM_TYPE(ifmr.ifm_active));
			retval = (IFM_TYPE(ifmr.ifm_active) == _type);
		} else if (_type == -1) {
			if (Dflag)
				fprintf(stderr, "%s has unknown media type\n", 
				    value.c_str());
			retval = true;
		}
		close(s);
	}

	return retval;
}

const string var_list::bogus = "_$_$_$_$_B_O_G_U_S_$_$_$_$_";
const string var_list::nothing = "";

const string &
var_list::get_variable(const string &var) const
{
	map<string, string>::const_iterator i;

	i = _vars.find(var);
	if (i == _vars.end())
		return (var_list::bogus);
	return (i->second);
}

bool
var_list::is_set(const string &var) const
{
	return (_vars.find(var) != _vars.end());
}

void
var_list::set_variable(const string &var, const string &val)
{
	if (Dflag)
		fprintf(stderr, "setting %s=%s\n", var.c_str(), val.c_str());
	_vars[var] = val;
}

void
config::reset(void)
{
	_dir_list.clear();
	delete_and_clear(_var_list_table);
	delete_and_clear(_attach_list);
	delete_and_clear(_detach_list);
	delete_and_clear(_nomatch_list);
	delete_and_clear(_notify_list);
}

void
config::parse_one_file(const char *fn)
{
	if (Dflag)
		fprintf(stderr, "Parsing %s\n", fn);
	yyin = fopen(fn, "r");
	if (yyin == NULL)
		err(1, "Cannot open config file %s", fn);
	lineno = 1;
	if (yyparse() != 0)
		errx(1, "Cannot parse %s at line %d", fn, lineno);
	fclose(yyin);
}

void
config::parse_files_in_dir(const char *dirname)
{
	DIR *dirp;
	struct dirent *dp;
	char path[PATH_MAX];

	if (Dflag)
		fprintf(stderr, "Parsing files in %s\n", dirname);
	dirp = opendir(dirname);
	if (dirp == NULL)
		return;
	readdir(dirp);		/* Skip . */
	readdir(dirp);		/* Skip .. */
	while ((dp = readdir(dirp)) != NULL) {
		if (strcmp(dp->d_name + dp->d_namlen - 5, ".conf") == 0) {
			snprintf(path, sizeof(path), "%s/%s",
			    dirname, dp->d_name);
			parse_one_file(path);
		}
	}
	closedir(dirp);
}

class epv_greater {
public:
	int operator()(event_proc *const&l1, event_proc *const&l2) const
	{
		return (l1->get_priority() > l2->get_priority());
	}
};

void
config::sort_vector(vector<event_proc *> &v)
{
	stable_sort(v.begin(), v.end(), epv_greater());
}

void
config::parse(void)
{
	vector<string>::const_iterator i;

	parse_one_file(configfile);
	for (i = _dir_list.begin(); i != _dir_list.end(); ++i)
		parse_files_in_dir((*i).c_str());
	sort_vector(_attach_list);
	sort_vector(_detach_list);
	sort_vector(_nomatch_list);
	sort_vector(_notify_list);
}

void
config::open_pidfile()
{
	pid_t otherpid;
	
	if (_pidfile.empty())
		return;
	pfh = pidfile_open(_pidfile.c_str(), 0600, &otherpid);
	if (pfh == NULL) {
		if (errno == EEXIST)
			errx(1, "devd already running, pid: %d", (int)otherpid);
		warn("cannot open pid file");
	}
}

void
config::write_pidfile()
{
	
	pidfile_write(pfh);
}

void
config::close_pidfile()
{
	
	pidfile_close(pfh);
}

void
config::remove_pidfile()
{
	
	pidfile_remove(pfh);
}

void
config::add_attach(int prio, event_proc *p)
{
	p->set_priority(prio);
	_attach_list.push_back(p);
}

void
config::add_detach(int prio, event_proc *p)
{
	p->set_priority(prio);
	_detach_list.push_back(p);
}

void
config::add_directory(const char *dir)
{
	_dir_list.push_back(string(dir));
}

void
config::add_nomatch(int prio, event_proc *p)
{
	p->set_priority(prio);
	_nomatch_list.push_back(p);
}

void
config::add_notify(int prio, event_proc *p)
{
	p->set_priority(prio);
	_notify_list.push_back(p);
}

void
config::set_pidfile(const char *fn)
{
	_pidfile = fn;
}

void
config::push_var_table()
{
	var_list *vl;
	
	vl = new var_list();
	_var_list_table.push_back(vl);
	if (Dflag)
		fprintf(stderr, "Pushing table\n");
}

void
config::pop_var_table()
{
	delete _var_list_table.back();
	_var_list_table.pop_back();
	if (Dflag)
		fprintf(stderr, "Popping table\n");
}

void
config::set_variable(const char *var, const char *val)
{
	_var_list_table.back()->set_variable(var, val);
}

const string &
config::get_variable(const string &var)
{
	vector<var_list *>::reverse_iterator i;

	for (i = _var_list_table.rbegin(); i != _var_list_table.rend(); ++i) {
		if ((*i)->is_set(var))
			return ((*i)->get_variable(var));
	}
	return (var_list::nothing);
}

bool
config::is_id_char(char ch) const
{
	return (ch != '\0' && (isalpha(ch) || isdigit(ch) || ch == '_' || 
	    ch == '-'));
}

void
config::expand_one(const char *&src, string &dst)
{
	int count;
	string buffer;

	src++;
	// $$ -> $
	if (*src == '$') {
		dst += *src++;
		return;
	}
		
	// $(foo) -> $(foo)
	// Not sure if I want to support this or not, so for now we just pass
	// it through.
	if (*src == '(') {
		dst += '$';
		count = 1;
		/* If the string ends before ) is matched , return. */
		while (count > 0 && *src) {
			if (*src == ')')
				count--;
			else if (*src == '(')
				count++;
			dst += *src++;
		}
		return;
	}
	
	// $[^A-Za-z] -> $\1
	if (!isalpha(*src)) {
		dst += '$';
		dst += *src++;
		return;
	}

	// $var -> replace with value
	do {
		buffer += *src++;
	} while (is_id_char(*src));
	dst.append(get_variable(buffer));
}

const string
config::expand_string(const char *src, const char *prepend, const char *append)
{
	const char *var_at;
	string dst;

	/*
	 * 128 bytes is enough for 2427 of 2438 expansions that happen
	 * while parsing config files, as tested on 2013-01-30.
	 */
	dst.reserve(128);

	if (prepend != NULL)
		dst = prepend;

	for (;;) {
		var_at = strchr(src, '$');
		if (var_at == NULL) {
			dst.append(src);
			break;
		}
		dst.append(src, var_at - src);
		src = var_at;
		expand_one(src, dst);
	}

	if (append != NULL)
		dst.append(append);

	return (dst);
}

bool
config::chop_var(char *&buffer, char *&lhs, char *&rhs) const
{
	char *walker;
	
	if (*buffer == '\0')
		return (false);
	walker = lhs = buffer;
	while (is_id_char(*walker))
		walker++;
	if (*walker != '=')
		return (false);
	walker++;		// skip =
	if (*walker == '"') {
		walker++;	// skip "
		rhs = walker;
		while (*walker && *walker != '"')
			walker++;
		if (*walker != '"')
			return (false);
		rhs[-2] = '\0';
		*walker++ = '\0';
	} else {
		rhs = walker;
		while (*walker && !isspace(*walker))
			walker++;
		if (*walker != '\0')
			*walker++ = '\0';
		rhs[-1] = '\0';
	}
	while (isspace(*walker))
		walker++;
	buffer = walker;
	return (true);
}


char *
config::set_vars(char *buffer)
{
	char *lhs;
	char *rhs;

	while (1) {
		if (!chop_var(buffer, lhs, rhs))
			break;
		set_variable(lhs, rhs);
	}
	return (buffer);
}

void
config::find_and_execute(char type)
{
	vector<event_proc *> *l;
	vector<event_proc *>::const_iterator i;
	const char *s;

	switch (type) {
	default:
		return;
	case notify:
		l = &_notify_list;
		s = "notify";
		break;
	case nomatch:
		l = &_nomatch_list;
		s = "nomatch";
		break;
	case attach:
		l = &_attach_list;
		s = "attach";
		break;
	case detach:
		l = &_detach_list;
		s = "detach";
		break;
	}
	if (Dflag)
		fprintf(stderr, "Processing %s event\n", s);
	for (i = l->begin(); i != l->end(); ++i) {
		if ((*i)->matches(*this)) {
			(*i)->run(*this);
			break;
		}
	}

}


static void
process_event(char *buffer)
{
	char type;
	char *sp;

	sp = buffer + 1;
	if (Dflag)
		fprintf(stderr, "Processing event '%s'\n", buffer);
	type = *buffer++;
	cfg.push_var_table();
	// No match doesn't have a device, and the format is a little
	// different, so handle it separately.
	switch (type) {
	case notify:
		sp = cfg.set_vars(sp);
		break;
	case nomatch:
		//? at location pnp-info on bus
		sp = strchr(sp, ' ');
		if (sp == NULL)
			return;	/* Can't happen? */
		*sp++ = '\0';
		while (isspace(*sp))
			sp++;
		if (strncmp(sp, "at ", 3) == 0)
			sp += 3;
		sp = cfg.set_vars(sp);
		while (isspace(*sp))
			sp++;
		if (strncmp(sp, "on ", 3) == 0)
			cfg.set_variable("bus", sp + 3);
		break;
	case attach:	/*FALLTHROUGH*/
	case detach:
		sp = strchr(sp, ' ');
		if (sp == NULL)
			return;	/* Can't happen? */
		*sp++ = '\0';
		cfg.set_variable("device-name", buffer);
		while (isspace(*sp))
			sp++;
		if (strncmp(sp, "at ", 3) == 0)
			sp += 3;
		sp = cfg.set_vars(sp);
		while (isspace(*sp))
			sp++;
		if (strncmp(sp, "on ", 3) == 0)
			cfg.set_variable("bus", sp + 3);
		break;
	}
	
	cfg.find_and_execute(type);
	cfg.pop_var_table();
}

int
create_socket(const char *name)
{
	int fd, slen;
	struct sockaddr_un sun;

	if ((fd = socket(PF_LOCAL, SOCK_STREAM, 0)) < 0)
		err(1, "socket");
	bzero(&sun, sizeof(sun));
	sun.sun_family = AF_UNIX;
	strlcpy(sun.sun_path, name, sizeof(sun.sun_path));
	slen = SUN_LEN(&sun);
	unlink(name);
	if (fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
	    	err(1, "fcntl");
	if (::bind(fd, (struct sockaddr *) & sun, slen) < 0)
		err(1, "bind");
	listen(fd, 4);
	chown(name, 0, 0);	/* XXX - root.wheel */
	chmod(name, 0666);
	return (fd);
}

unsigned int max_clients = 10;	/* Default, can be overriden on cmdline. */
unsigned int num_clients;
list<int> clients;

void
notify_clients(const char *data, int len)
{
	list<int>::iterator i;

	/*
	 * Deliver the data to all clients.  Throw clients overboard at the
	 * first sign of trouble.  This reaps clients who've died or closed
	 * their sockets, and also clients who are alive but failing to keep up
	 * (or who are maliciously not reading, to consume buffer space in
	 * kernel memory or tie up the limited number of available connections).
	 */
	for (i = clients.begin(); i != clients.end(); ) {
		if (write(*i, data, len) != len) {
			--num_clients;
			close(*i);
			i = clients.erase(i);
		} else
			++i;
	}
}

void
check_clients(void)
{
	int s;
	struct pollfd pfd;
	list<int>::iterator i;

	/*
	 * Check all existing clients to see if any of them have disappeared.
	 * Normally we reap clients when we get an error trying to send them an
	 * event.  This check eliminates the problem of an ever-growing list of
	 * zombie clients because we're never writing to them on a system
	 * without frequent device-change activity.
	 */
	pfd.events = 0;
	for (i = clients.begin(); i != clients.end(); ) {
		pfd.fd = *i;
		s = poll(&pfd, 1, 0);
		if ((s < 0 && s != EINTR ) ||
		    (s > 0 && (pfd.revents & POLLHUP))) {
			--num_clients;
			close(*i);
			i = clients.erase(i);
		} else
			++i;
	}
}

void
new_client(int fd)
{
	int s;

	/*
	 * First go reap any zombie clients, then accept the connection, and
	 * shut down the read side to stop clients from consuming kernel memory
	 * by sending large buffers full of data we'll never read.
	 */
	check_clients();
	s = accept(fd, NULL, NULL);
	if (s != -1) {
		shutdown(s, SHUT_RD);
		clients.push_back(s);
		++num_clients;
	}
}

static void
event_loop(void)
{
	int rv;
	int fd;
	char buffer[DEVCTL_MAXBUF];
	int once = 0;
	int server_fd, max_fd;
	int accepting;
	timeval tv;
	fd_set fds;

	fd = open(PATH_DEVCTL, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		err(1, "Can't open devctl device %s", PATH_DEVCTL);
	server_fd = create_socket(PIPE);
	accepting = 1;
	max_fd = max(fd, server_fd) + 1;
	while (!romeo_must_die) {
		if (!once && !dflag && !nflag) {
			// Check to see if we have any events pending.
			tv.tv_sec = 0;
			tv.tv_usec = 0;
			FD_ZERO(&fds);
			FD_SET(fd, &fds);
			rv = select(fd + 1, &fds, &fds, &fds, &tv);
			// No events -> we've processed all pending events
			if (rv == 0) {
				if (Dflag)
					fprintf(stderr, "Calling daemon\n");
				cfg.remove_pidfile();
				cfg.open_pidfile();
				daemon(0, 0);
				cfg.write_pidfile();
				once++;
			}
		}
		/*
		 * When we've already got the max number of clients, stop
		 * accepting new connections (don't put server_fd in the set),
		 * shrink the accept() queue to reject connections quickly, and
		 * poll the existing clients more often, so that we notice more
		 * quickly when any of them disappear to free up client slots.
		 */
		FD_ZERO(&fds);
		FD_SET(fd, &fds);
		if (num_clients < max_clients) {
			if (!accepting) {
				listen(server_fd, max_clients);
				accepting = 1;
			}
			FD_SET(server_fd, &fds);
			tv.tv_sec = 60;
			tv.tv_usec = 0;
		} else {
			if (accepting) {
				listen(server_fd, 0);
				accepting = 0;
			}
			tv.tv_sec = 2;
			tv.tv_usec = 0;
		}
		rv = select(max_fd, &fds, NULL, NULL, &tv);
		if (rv == -1) {
			if (errno == EINTR)
				continue;
			err(1, "select");
		} else if (rv == 0)
			check_clients();
		if (FD_ISSET(fd, &fds)) {
			rv = read(fd, buffer, sizeof(buffer) - 1);
			if (rv > 0) {
				notify_clients(buffer, rv);
				buffer[rv] = '\0';
				while (buffer[--rv] == '\n')
					buffer[rv] = '\0';
				process_event(buffer);
			} else if (rv < 0) {
				if (errno != EINTR)
					break;
			} else {
				/* EOF */
				break;
			}
		}
		if (FD_ISSET(server_fd, &fds))
			new_client(server_fd);
	}
	close(fd);
}

/*
 * functions that the parser uses.
 */
void
add_attach(int prio, event_proc *p)
{
	cfg.add_attach(prio, p);
}

void
add_detach(int prio, event_proc *p)
{
	cfg.add_detach(prio, p);
}

void
add_directory(const char *dir)
{
	cfg.add_directory(dir);
	free(const_cast<char *>(dir));
}

void
add_nomatch(int prio, event_proc *p)
{
	cfg.add_nomatch(prio, p);
}

void
add_notify(int prio, event_proc *p)
{
	cfg.add_notify(prio, p);
}

event_proc *
add_to_event_proc(event_proc *ep, eps *eps)
{
	if (ep == NULL)
		ep = new event_proc();
	ep->add(eps);
	return (ep);
}

eps *
new_action(const char *cmd)
{
	eps *e = new action(cmd);
	free(const_cast<char *>(cmd));
	return (e);
}

eps *
new_match(const char *var, const char *re)
{
	eps *e = new match(cfg, var, re);
	free(const_cast<char *>(var));
	free(const_cast<char *>(re));
	return (e);
}

eps *
new_media(const char *var, const char *re)
{
	eps *e = new media(cfg, var, re);
	free(const_cast<char *>(var));
	free(const_cast<char *>(re));
	return (e);
}

void
set_pidfile(const char *name)
{
	cfg.set_pidfile(name);
	free(const_cast<char *>(name));
}

void
set_variable(const char *var, const char *val)
{
	cfg.set_variable(var, val);
	free(const_cast<char *>(var));
	free(const_cast<char *>(val));
}



static void
gensighand(int)
{
	romeo_must_die = 1;
}

static void
usage()
{
	fprintf(stderr, "usage: %s [-Ddn] [-l connlimit] [-f file]\n",
	    getprogname());
	exit(1);
}

static void
check_devd_enabled()
{
	int val = 0;
	size_t len;

	len = sizeof(val);
	if (sysctlbyname(SYSCTL, &val, &len, NULL, 0) != 0)
		errx(1, "devctl sysctl missing from kernel!");
	if (val) {
		warnx("Setting " SYSCTL " to 0");
		val = 0;
		sysctlbyname(SYSCTL, NULL, NULL, &val, sizeof(val));
	}
}

/*
 * main
 */
int
main(int argc, char **argv)
{
	int ch;

	check_devd_enabled();
	while ((ch = getopt(argc, argv, "Ddf:l:n")) != -1) {
		switch (ch) {
		case 'D':
			Dflag++;
			break;
		case 'd':
			dflag++;
			break;
		case 'f':
			configfile = optarg;
			break;
		case 'l':
			max_clients = MAX(1, strtoul(optarg, NULL, 0));
			break;
		case 'n':
			nflag++;
			break;
		default:
			usage();
		}
	}

	cfg.parse();
	if (!dflag && nflag) {
		cfg.open_pidfile();
		daemon(0, 0);
		cfg.write_pidfile();
	}
	signal(SIGPIPE, SIG_IGN);
	signal(SIGHUP, gensighand);
	signal(SIGINT, gensighand);
	signal(SIGTERM, gensighand);
	event_loop();
	return (0);
}