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

@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/treegram.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/topdowng.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/treegen.Ppo@am__quote@

noinst_LTLIBRARIES = libautomata.la

libautomata_la_sources_pcc = \
	treegram.pcc topdowng.pcc treegen.pcc

EXTRA_DIST = $(libautomata_la_sources_pcc)

libautomata_la_SOURCES = \
	$(libautomata_la_sources_pcc:.pcc=.cc) \
	ac.cc acgen.cc bottomup.cc lr0.cc compdfa.cc densedfa.cc \
	gentable.cc grammar.cc lr1.cc lalr1gen.cc \
	lexer.cc lexergen.cc ll1.cc ll1gen.cc ll1parse.cc lrgen.cc \
	llk.cc llkgen.cc lrk.cc lrparser.cc lookahd.cc \
	scanner.cc sparsdfa.cc topdown.cc \
	treeauto.cc regexmat.cc \
	nullable.cc firstset.cc follow.cc first_k.cc follow_k.cc operprec.cc \
	nfa.cc nfa_node.cc nfa32.cc lr1gen.cc lrkgen.cc gla.cc lexerbuf.cc \
	iolexerbuf.cc iolexerstack.cc item.cc firstset2.cc fastac.cc

