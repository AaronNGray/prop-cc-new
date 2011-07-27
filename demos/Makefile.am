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

PROP_OPTS_LOCAL = -non_linear
include $(top_srcdir)/prop.am

@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/logic3.Pph@am__quote@

@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/logic.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/logic2.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/logic3.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/inference.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/persistence.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/prog.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/exp.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/rewrite-trick1.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/rewrite-trick2.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/rewrite-trick3.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/rewrite-trick4.Ppo@am__quote@
@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/rewrite-trick5.Ppo@am__quote@

logic3_headers_ph = logic3.ph

logic_sources_pcc = logic.pC
logic2_sources_pcc = logic2.pC
logic3_sources_pcc = logic3.pC
inference_sources_pcc = inference.pC
persistence_sources_pcc = persistence.pC
prog_sources_pcc = prog.pC
exp_sources_pcc = exp.pC
rewrite_trick1_sources_pcc = rewrite-trick1.pC
rewrite_trick2_sources_pcc = rewrite-trick2.pC
rewrite_trick3_sources_pcc = rewrite-trick3.pC
rewrite_trick4_sources_pcc = rewrite-trick4.pC
rewrite_trick5_sources_pcc = rewrite-trick5.pC

noinst_PROGRAMS = \
	logic logic2 logic3 \
	inference persistence prog exp \
	rewrite-trick1 rewrite-trick2 rewrite-trick3 \
	rewrite-trick4 rewrite-trick5 

nodist_logic_SOURCES = $(logic_sources_pcc:.pC=.C)
nodist_logic2_SOURCES = $(logic2_sources_pcc:.pC=.C)
nodist_logic3_SOURCES =  $(logic3_headers_ph:.ph=.h) $(logic3_sources_pcc:.pC=.C)
nodist_inference_SOURCES = $(inference_sources_pcc:.pC=.C)
nodist_persistence_SOURCES = $(persistence_sources_pcc:.pC=.C)
nodist_prog_SOURCES = $(prog_sources_pcc:.pC=.C)
nodist_exp_SOURCES = $(exp_sources_pcc:.pC=.C)
nodist_rewrite_trick1_SOURCES = $(rewrite_trick1_sources_pcc:.pC=.C)
nodist_rewrite_trick2_SOURCES = $(rewrite_trick2_sources_pcc:.pC=.C)
nodist_rewrite_trick3_SOURCES = $(rewrite_trick3_sources_pcc:.pC=.C)
nodist_rewrite_trick4_SOURCES = $(rewrite_trick4_sources_pcc:.pC=.C)
nodist_rewrite_trick5_SOURCES = $(rewrite_trick5_sources_pcc:.pC=.C)

EXTRA_DIST = \
	$(logic_sources_pcc) \
	$(logic2_sources_pcc) \
	$(logic3_headers_ph) \
	$(logic3_sources_pcc) \
	$(inference_sources_pcc) \
	$(persistence_sources_pcc) \
	$(prog_sources_pcc) \
	prog.output \
	$(exp_sources_pcc) \
	$(rewrite_trick1_sources_pcc) \
	$(rewrite_trick2_sources_pcc) \
	$(rewrite_trick3_sources_pcc) \
	$(rewrite_trick4_sources_pcc) \
	$(rewrite_trick5_sources_pcc)
 
BUILT_SOURCES = \
	$(nodist_logic_SOURCES) \
	$(nodist_logic2_SOURCES) \
	$(nodist_logic3_SOURCES) \
	$(nodist_inference_SOURCES) \
	$(nodist_persistence_SOURCES) \
	$(nodist_prog_SOURCES) \
	$(nodist_exp_SOURCES) \
	$(nodist_rewrite_trick1_SOURCES) \
	$(nodist_rewrite_trick2_SOURCES) \
	$(nodist_rewrite_trick3_SOURCES) \
	$(nodist_rewrite_trick4_SOURCES) \
	$(nodist_rewrite_trick5_SOURCES)

CLEANFILES = \
	$(BUILT_SOURCES) \
	*.report \
	persistence.dat

logic_LDADD = $(top_builddir)/lib-src/libprop.la
logic2_LDADD = $(top_builddir)/lib-src/libprop.la
logic3_LDADD = $(top_builddir)/lib-src/libprop.la
inference_LDADD = $(top_builddir)/lib-src/libprop.la
persistence_LDADD = $(top_builddir)/lib-src/libprop.la
prog_LDADD = $(top_builddir)/lib-src/libprop.la
exp_LDADD = $(top_builddir)/lib-src/libprop.la
rewrite_trick1_LDADD = $(top_builddir)/lib-src/libprop.la
rewrite_trick2_LDADD = $(top_builddir)/lib-src/libprop.la
rewrite_trick3_LDADD = $(top_builddir)/lib-src/libprop.la
rewrite_trick4_LDADD = $(top_builddir)/lib-src/libprop.la
rewrite_trick5_LDADD = $(top_builddir)/lib-src/libprop.la

