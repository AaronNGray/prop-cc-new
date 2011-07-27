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

include $(top_srcdir)/prop.am

@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/treegram.Pph@am__quote@

BUILT_SOURCES = \
	AD/automata/treegram.ph

include_HEADERS = propdefs.h
nobase_include_HEADERS = \
	AD/automata/acgen.h \
	AD/automata/ac.h \
	AD/automata/bottomup.h \
	AD/automata/compdfa.h \
	AD/automata/densedfa.h \
	AD/automata/dfatable.h \
	AD/automata/first_k.h \
	AD/automata/firstset2.h \
	AD/automata/firstset.h \
	AD/automata/follow.h \
	AD/automata/follow_k.h \
	AD/automata/gentable.h \
	AD/automata/gla.h \
	AD/automata/grammar.h \
	AD/automata/iolexerbuf.h \
	AD/automata/iolexerstack.h \
	AD/automata/item.h \
	AD/automata/lalr1gen.h \
	AD/automata/lexerbuf.h \
	AD/automata/lexergen.h \
	AD/automata/lexer.h \
	AD/automata/ll1gen.h \
	AD/automata/ll1.h \
	AD/automata/llkgen.h \
	AD/automata/llk.h \
	AD/automata/lookahd.h \
	AD/automata/lr0.h \
	AD/automata/lr1gen.h \
	AD/automata/lr1.h \
	AD/automata/lrgen.h \
	AD/automata/lrkgen.h \
	AD/automata/lrk.h \
	AD/automata/lrparser.h \
	AD/automata/nfa32.h \
	AD/automata/nfa.h \
	AD/automata/nfa_node.h \
	AD/automata/nullable.h \
	AD/automata/operprec.h \
	AD/automata/regexmat.h \
	AD/automata/scanner.h \
	AD/automata/sparsdfa.h \
	AD/automata/topdowng.h \
	AD/automata/topdown.h \
	AD/automata/treeauto.h \
	AD/automata/treegen.h \
	AD/automata/treegram.h \
	AD/automata/treepat.h \
	AD/automata/treetab.h \
	AD/backend-tools/codeemit.h \
	AD/config/config.h \
	AD/contain/array2.h \
	AD/contain/array.h \
	AD/contain/basiccol.h \
	AD/contain/bitset.h \
	AD/contain/bytearry.h \
	AD/contain/charset.h \
	AD/contain/col.h \
	AD/contain/dchmap.h \
	AD/contain/dlist.h \
	AD/contain/fbitset.h \
	AD/contain/hashmap.h \
	AD/contain/intset.h \
	AD/contain/intsets.h \
	AD/contain/map.h \
	AD/contain/n_array.h \
	AD/contain/priq.h \
	AD/contain/queue.h \
	AD/contain/slink.h \
	AD/contain/slist.h \
	AD/contain/slnklist.h \
	AD/contain/stack.h \
	AD/contain/unionfnd.h \
	AD/contain/vararray.h \
	AD/contain/variset.h \
	AD/contain/varptrarray.h \
	AD/contain/varqueue.h \
	AD/contain/varstack.h \
	AD/csp/logicalterm.h \
	AD/csp/trail.h \
	AD/gc/bgc.h \
	AD/gc/cgc.h \
	AD/gc/gcbitmap.h \
	AD/gc/gcconfig.h \
	AD/gc/gc.h \
	AD/gc/gcheaps.h \
	AD/gc/gcintern.h \
	AD/gc/gcmacros.h \
	AD/gc/gcobject.h \
	AD/gc/gctimer.h \
	AD/gc/gcverify.h \
	AD/gc/markswp.h \
	AD/gc/rootset.h \
	AD/gc/userheap.h \
	AD/gc/weakptr.h \
	AD/generic/except.h \
	AD/generic/generic.h \
	AD/generic/ordering.h \
	AD/generic/tables.h \
	AD/graph/edge.h \
	AD/graph/graph_base.h \
	AD/graph/graph.h \
	AD/graph/node.h \
	AD/graphtype/graphtype.h \
	AD/hash/bhash.h \
	AD/hash/chash.h \
	AD/hash/dchash.h \
	AD/hash/dhash.h \
	AD/hash/hashfn.h \
	AD/hash/lhash2.h \
	AD/hash/lhash.h \
	AD/hash/ohash.h \
	AD/memory/arena.h \
	AD/memory/blacklistmem.h \
	AD/memory/boundtag.h \
	AD/memory/buddy.h \
	AD/memory/cleanmem.h \
	AD/memory/freelist.h \
	AD/memory/mem.h \
	AD/memory/mempool.h \
	AD/memory/ptr.h \
	AD/memory/ref.h \
	AD/memory/strpool.h \
	AD/memory/sysmem.h \
	AD/numeric/bcd.h \
	AD/numeric/bigint.h \
	AD/numeric/complex.h \
	AD/numeric/fixpt.h \
	AD/numeric/gauss.h \
	AD/numeric/matrix.h \
	AD/numeric/pmatrix.h \
	AD/numeric/primes.h \
	AD/numeric/ratio.h \
	AD/numeric/simplex.h \
	AD/numeric/tensor.h \
	AD/numeric/trapez.h \
	AD/numeric/vector3d.h \
	AD/numeric/vector.h \
	AD/numeric/z.h \
	AD/persist/pconfig.h \
	AD/persist/pconvert.h \
	AD/persist/pfactory.h \
	AD/persist/pi_impl.h \
	AD/persist/pobject.h \
	AD/persist/po_impl.h \
	AD/persist/pstream.h \
	AD/persist/ptypeentry.h \
	AD/persist/ptype.h \
	AD/pretty/postream.h \
	AD/prettypr/prettypr.h \
	AD/prop/tuple2.h \
	AD/rete/alphamem.h \
	AD/rete/betamem.h \
	AD/rete/fact.h \
	AD/rete/gen_rete.h \
	AD/rete/rete.h \
	AD/rete/retenet.h \
	AD/rete/token.h \
	AD/rewrite/b_item.h \
	AD/rewrite/b_items.h \
	AD/rewrite/b_rules.h \
	AD/rewrite/burs_gen.h \
	AD/rewrite/burs.h \
	AD/rewrite/cache.h \
	AD/rewrite/termobj.h \
	AD/rewrite/twig_gen.h \
	AD/rewrite/twig.h \
	AD/sort/heapsort.h \
	AD/sort/heapsrt2.h \
	AD/sort/insort.h \
	AD/sort/sorting2.h \
	AD/sort/sorting.h \
	AD/strings/atom.h \
	AD/strings/bm.h \
	AD/strings/charesc.h \
	AD/strings/fansu.h \
	AD/strings/kmp.h \
	AD/strings/kr.h \
	AD/strings/quark.h \
	AD/strings/regexp.h \
	AD/strings/shiftadd.h \
	AD/strings/string.h \
	AD/strings/strmatch.h \
	AD/strings/twoway.h \
	AD/symbolic/atom.h \
	AD/symbolic/bdd.h \
	AD/symbolic/expr.h \
	AD/symbolic/fouriermotzkin.h \
	AD/symbolic/linsolver.h \
	AD/symbolic/string.h \
	AD/symbolic/term.h \
	AD/trees/avl.h \
	AD/trees/fibheap.h \
	AD/trees/leftist.h \
	AD/trees/pagoda.h \
	AD/trees/rlxheap.h \
	AD/trees/splay.h \
	AD/trees/trees.h \
	AD/trees/vbpq.h \
	AD/tries/briandai.h \
	AD/tries/comptrie.h \
	AD/tries/hashtrie.h \
	AD/tries/patricia.h \
	AD/tries/trie.h \
	AD/visualize/vcg.h

