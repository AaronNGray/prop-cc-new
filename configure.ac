dnl Copyright (c) 2011 Argonne National Laboratory
dnl All rights reserved.
dnl 
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions
dnl are met:
dnl 1. Redistributions of source code must retain the above copyright
dnl    notice, this list of conditions and the following disclaimer.
dnl 2. Redistributions in binary form must reproduce the above copyright
dnl    notice, this list of conditions and the following disclaimer in the
dnl    documentation and/or other materials provided with the distribution.
dnl 
dnl THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
dnl ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
dnl TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
dnl PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
dnl BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
dnl CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
dnl SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
dnl INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
dnl CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
dnl ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
dnl POSSIBILITY OF SUCH DAMAGE.

AC_INIT([prop], [2.4.1])
AC_CONFIG_HEADER(include/AD/config/config.h)
AM_INIT_AUTOMAKE

AC_PROG_SED

changequote(<<, >>)dnl
VERSION_MAJOR=`echo $VERSION | $SED 's/\([0-9]\+\)\.\([0-9]\+\)\.\([0-9]\+\)/\1/'`
VERSION_MINOR=`echo $VERSION | $SED 's/\([0-9]\+\)\.\([0-9]\+\)\.\([0-9]\+\)/\2/'`
VERSION_POINT=`echo $VERSION | $SED 's/\([0-9]\+\)\.\([0-9]\+\)\.\([0-9]\+\)/\3/'`
changequote([, ])dnl

AC_SUBST(VERSION_MAJOR)
AC_SUBST(VERSION_MINOR)
AC_SUBST(VERSION_POINT)

VERSION_AGE=0
AC_SUBST(VERSION_AGE)

AC_PROG_CXX
AC_PROG_LIBTOOL

AC_PATH_PROGS([PROP], [prop prop-cc], [nonexistent])

AC_DEFINE(PROP_BOOL_IS_DEFINED, [],
	[Define if your compiler understands the bool type.]
)
AC_DEFINE(PROP_EXPLICIT_IS_DEFINED, [],
	[Define if your compiler understands the explicit keyword.]
)

AC_CHECK_HEADER(sys/time.h)
AC_CHECK_HEADER(sys/resource.h)
AC_CHECK_FUNC(getrusage,
	AC_DEFINE(PROP_HAS_GETRUSAGE, [],
		[Define if your system has getrusage(...).]
	),
)

AC_CHECK_HEADER(sys/times.h)
AC_CHECK_FUNC(times,
	AC_DEFINE(PROP_HAS_TIMES, [],
		[Define if your system has times(...).]
	),
)

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	lib-src/Makefile
        lib-src/automata/Makefile
	lib-src/contain/Makefile
	lib-src/csp/Makefile
        lib-src/gc/Makefile
	lib-src/generic/Makefile
        lib-src/graph/Makefile
	lib-src/graphtype/Makefile
	lib-src/hash/Makefile
	lib-src/memory/Makefile
	lib-src/numeric/Makefile
	lib-src/persist/Makefile
	lib-src/pretty/Makefile
	lib-src/prettypr/Makefile
	lib-src/prop/Makefile
	lib-src/rete/Makefile
	lib-src/rewrite/Makefile
	lib-src/strings/Makefile
	lib-src/symbolic/Makefile
	lib-src/trees/Makefile
	lib-src/tries/Makefile
	lib-src/backend-tools/Makefile
	lib-src/visualize/Makefile
	prop-src/Makefile
])
AC_OUTPUT()

