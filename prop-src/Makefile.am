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

AM_CPPFLAGS = -I$(top_srcdir)/include

include $(top_srcdir)/prop.am

prop_headers_ph = \
	ir.ph ast.ph basics.ph parsegen.ph keywords.ph parser.ph \
	collection.ph setl-ast.ph setlgen.ph matchcom.ph \
	trs.ph timespace.ph env.ph funmap.ph metasyntax.ph \
	pat.ph list.ph grsgen.ph graphtype.ph graphedges.ph \
	aggen.ph datatype.ph rwmix.ph
#	dataflow.ph bitfield.ph wam.ph constraint.ph logicgen.ph 

prop_sources_pcc = \
	persistgen.pcc gcgen.pcc printgen.pcc \
	matchcom.pcc matchgen.pcc infgen.pcc type.pcc \
	printing.pcc datagen.pcc codegen.pcc compiler.pcc indexing.pcc \
	ast.pcc constr.pcc parsegen.pcc lexeme.pcc lexer.pcc \
	trs.pcc trs2.pcc trs3.pcc \
	rwgen.pcc rwgen2.pcc rwgen3.pcc rwgen4.pcc rwgen5.pcc \
	lawgen.pcc parser-util.pcc parser.pcc setl-ast.pcc \
	documentation.pcc collection.pcc setlgen.pcc setltype.pcc \
	timespace.pcc env.pcc funmap.pcc metasyntax.pcc \
	pat.pcc grsgen.pcc selector.pcc \
	graphtype.pcc graphrep.pcc graphops.pcc graphreport.pcc \
	classdef.pcc prop-main.pcc \
	aggen.pcc datatype.pcc instance.pcc \
	visualize.pcc visual2.pcc rwmix.pcc
#	dataflow.pcc bitfield.pcc constraint.pcc logicgen.pcc wam.pcc 

EXTRA_DIST = $(prop_headers_ph) $(prop_sources_pcc)

bin_PROGRAMS = prop

prop_SOURCES = \
	$(prop_headers_ph:.ph=.h) \
	$(prop_sources_pcc:.pcc=.cc) \
	automake.cc frontend.cc functortab.cc \
	hashtab.cc labelgen.cc options.cc \
	patchlev.cc patenv.cc process.cc textbuf.cc 
BUILT_SOURCES = \
	$(prop_headers_ph:.ph=.h) \
	$(prop_sources_pcc:.pcc=.cc)

noinst_HEADERS = \
	author.h automake.h classdef.h codegen.h compiler.h \
	config.h datagen.h functortab.h hashtab.h infgen.h labelgen.h \
	options.h rwgen.h textbuf.h type.h visualize.h

prop_LDADD = $(top_builddir)/lib-src/libprop.la

