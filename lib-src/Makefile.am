# Copyright (c) 2011 Argonne National Laboratory
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

EXTRA_DIST = VarArrayTest.cpp
SUBDIRS = \
	automata \
	contain \
	csp \
	gc \
	generic \
	graph \
	graphtype \
	hash \
	memory \
	numeric \
	persist \
	pretty \
	prettypr \
	prop \
	rete \
	rewrite \
	strings \
	symbolic \
	trees \
	tries \
	backend-tools \
	visualize

lib_LTLIBRARIES = libprop.la
libprop_la_SOURCES =
libprop_la_LIBADD = \
	automata/libautomata.la \
	contain/libcontain.la \
	csp/libcsp.la \
	gc/libgc.la \
	generic/libgeneric.la \
	graph/libgraph.la \
	graphtype/libgraphtype.la \
	hash/libhash.la \
	memory/libmemory.la \
	numeric/libnumeric.la \
	persist/libpersist.la \
	pretty/libpretty.la \
	prettypr/libprettypr.la \
	prop/libprop.la \
	rete/librete.la \
	rewrite/librewrite.la \
	strings/libstrings.la \
	symbolic/libsymbolic.la \
	trees/libtrees.la \
	tries/libtries.la \
	backend-tools/libbackend-tools.la \
	visualize/libvisualize.la
nodist_EXTRA_libprop_la_SOURCES = dummy.cc
libprop_la_LDFLAGS = -version-info @VERSION_MINOR@:@VERSION_POINT@:@VERSION_AGE@

