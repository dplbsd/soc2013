# $FreeBSD: soc2013/dpl/head/etc/pam.d/Makefile 236712 2012-05-30 03:10:22Z miwi $

NO_OBJ=

FILES=	README \
	atrun \
	cron \
	ftpd \
	imap \
	login \
	other \
	passwd pop3 \
	rsh \
	sshd su system \
	telnetd \
	xdm

FILESDIR=	/etc/pam.d
FILESMODE=	644
FILESMODE_README=	444
LINKS=	${FILESDIR}/ftpd ${FILESDIR}/ftp

.include <bsd.prog.mk>
