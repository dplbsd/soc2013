# $FreeBSD: soc2013/dpl/head/usr.bin/clang/clang-tblgen/Makefile 250624 2013-04-12 17:57:40Z dim $

NO_MAN=
.include <bsd.own.mk>

PROG_CXX=clang-tblgen

SRCDIR=	tools/clang/utils/TableGen
SRCS=	ClangASTNodesEmitter.cpp \
	ClangAttrEmitter.cpp \
	ClangCommentCommandInfoEmitter.cpp \
	ClangCommentHTMLNamedCharacterReferenceEmitter.cpp \
	ClangCommentHTMLTagsEmitter.cpp \
	ClangDiagnosticsEmitter.cpp \
	ClangSACheckersEmitter.cpp \
	NeonEmitter.cpp \
	OptParserEmitter.cpp \
	TableGen.cpp

LIBDEPS=llvmtablegen \
	llvmsupport

.include "../clang.prog.mk"
