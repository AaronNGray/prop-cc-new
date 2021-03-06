///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "indexing.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "indexing.pcc"
///////////////////////////////////////////////////////////////////////////////
//  Indexing optimizations for pattern matching.
//
//  The following indexing schemes is largely inspired by the work of
//  Sekar, Ramesh and Ramakrishnan in ``Adaptive Pattern Matching.''
//  Techreport, SUNY at Stony Brook (year 91+ but unknown).
//
//  Intuitively, an index is the next position of a pattern that must be
//  inspected to determine a match(Levy and Huet).  Given a set of
//  prioritized patterns, at least an index must exist at each position.
//  The algorithm of SRR attempts to locate the index at each position
//  when constructing the the DFA-like matching automata.
//
//  In the previous algorithm I've implemented, merging of matching trees at
//  identical positions are performed and the resulting automaton guarantees
//  that the same position is only examined once.  This is an improvement
//  over Wadler's algorithm, which may examine the same position more than
//  once in a match.  However, we may examine a position even if it is not
//  needed.
//
//    For example, in
//
//       f(_,a,b):
//       f(a,a,_):
//       f(_,b,c):
//
//   We exam position 1, 2, 3 in sequence in term f even though it is
// best to exam position 2 first.
//
//  I think my algorithm is similar to the one by Graf.  In any case,
//  My, Graf's and Wadler's algorithms all use a fixed traversal order
//  (usually left-to-right).  However, the intuition is that in many instances
//  it is best if the traversal order *adapts* itself according to the
//  pattern.  This is the essential idea of SRR's algorithm.
//
//  Sekar et al. have shown that constructing a DFA-like matching
//  automata can be exponential in time and space.  They have
//  developed a polynomial time algorithm for computing indices for untyped
//  terms.  Unfortunately, in our typed case the time complexity of index
//  computation is co-NP.
//
//  So we'll just use a few heuristics to compute something close to
//  the notion of an index, and cross our fingers and hope for the best.
///////////////////////////////////////////////////////////////////////////////

#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "hashtab.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Hash function on position list
//
///////////////////////////////////////////////////////////////////////////////

unsigned int pos_hash( HashTable::Key p)
{
  Pos pos = (Pos)p;
  unsigned int h = 37;
  
#line 61 "indexing.pcc"
#line 67 "indexing.pcc"
{
  for (;;) {
    if (boxed(pos)) {
      switch (untagp(pos)) {
        case a_Pos::tag_POSint: {
#line 65 "indexing.pcc"
         h += ((Pos_POSint *)pos)->_1; pos = ((Pos_POSint *)pos)->_2; 
#line 65 "indexing.pcc"
          } break;
        case a_Pos::tag_POSlabel: {
#line 66 "indexing.pcc"
         h += (unsigned int)((Pos_POSlabel *)derefp(pos))->_1; pos = ((Pos_POSlabel *)derefp(pos))->_2; 
#line 66 "indexing.pcc"
          } break;
        default: {
#line 67 "indexing.pcc"
         h += ((Pos_POSadaptive *)derefp(pos))->_1 + 437; pos = ((Pos_POSadaptive *)derefp(pos))->_3; 
#line 67 "indexing.pcc"
          } break;
      }
    } else {
      if (pos) {
        
#line 64 "indexing.pcc"
       return h + 83; 
#line 64 "indexing.pcc"
      } else {
        
#line 63 "indexing.pcc"
       return h; 
#line 63 "indexing.pcc"
      }
    }
  }
}
#line 68 "indexing.pcc"
#line 68 "indexing.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Checks if a pattern is refutable.
//
///////////////////////////////////////////////////////////////////////////////

Bool is_refutable( Pat pat)
{
  
#line 79 "indexing.pcc"
#line 107 "indexing.pcc"
{
  for (;;) {
    if (pat) {
      switch (pat->tag__) {
        case a_Pat::tag_WILDpat: {
          L3:; 
#line 81 "indexing.pcc"
         return false; 
#line 81 "indexing.pcc"
          } break;
        case a_Pat::tag_IDpat: {
          if (((Pat_IDpat *)pat)->_3) {
            L4:; 
#line 83 "indexing.pcc"
           return true; 
#line 83 "indexing.pcc"
          } else { goto L3; }
          } break;
        case a_Pat::tag_CONSpat: {
          if (((Pat_CONSpat *)pat)->CONSpat) {
            if (((Pat_CONSpat *)pat)->CONSpat->alg_ty) {
              switch (((Pat_CONSpat *)pat)->CONSpat->alg_ty->tag__) {
                case a_Ty::tag_TYCONty: {
                  if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)) {
                    switch (((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1->tag__) {
                      case a_TyCon::tag_DATATYPEtycon: {
#line 99 "indexing.pcc"
                       return ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->arg > 1) || (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->qualifiers & QUALextensible)); 
#line 99 "indexing.pcc"
                        } break;
                      default: {
                        L5:; 
#line 107 "indexing.pcc"
                       bug("is_refutable()"); 
#line 107 "indexing.pcc"
                        } break;
                    }
                  } else { goto L5; }
                  } break;
                default: { goto L5; } break;
              }
            } else { goto L5; }
          } else { goto L5; }
          } break;
        case a_Pat::tag_APPpat: {
#line 100 "indexing.pcc"
         return is_refutable(((Pat_APPpat *)pat)->_1) || is_refutable(((Pat_APPpat *)pat)->_2); 
#line 100 "indexing.pcc"
          } break;
        case a_Pat::tag_TYPEDpat: {
#line 85 "indexing.pcc"
         pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 85 "indexing.pcc"
          } break;
        case a_Pat::tag_ASpat: {
          if (((Pat_ASpat *)pat)->_4) { goto L4; } else {
#line 84 "indexing.pcc"
           pat = ((Pat_ASpat *)pat)->_2; 
#line 84 "indexing.pcc"
          }
          } break;
        case a_Pat::tag_CONTEXTpat: {
#line 93 "indexing.pcc"
         return is_refutable(((Pat_CONTEXTpat *)pat)->_2); 
#line 93 "indexing.pcc"
          } break;
        case a_Pat::tag_ARRAYpat: {
#line 89 "indexing.pcc"
         return is_refutable(((Pat_ARRAYpat *)pat)->_1); 
#line 89 "indexing.pcc"
          } break;
        case a_Pat::tag_TUPLEpat: {
#line 88 "indexing.pcc"
         return is_refutable(((Pat_TUPLEpat *)pat)->TUPLEpat); 
#line 88 "indexing.pcc"
          } break;
        case a_Pat::tag_RECORDpat: {
#line 92 "indexing.pcc"
         return is_refutable(((Pat_RECORDpat *)pat)->_1); 
#line 92 "indexing.pcc"
          } break;
        case a_Pat::tag_LISTpat: {
#line 102 "indexing.pcc"
          
          if (is_refutable(((Pat_LISTpat *)pat)->head))
            return true;
          pat = ((Pat_LISTpat *)pat)->tail;
          
#line 106 "indexing.pcc"
          } break;
        case a_Pat::tag_VECTORpat: {
#line 91 "indexing.pcc"
         return is_refutable(((Pat_VECTORpat *)pat)->len) || is_refutable(((Pat_VECTORpat *)pat)->elements); 
#line 91 "indexing.pcc"
          } break;
        case a_Pat::tag_LOGICALpat: {
#line 87 "indexing.pcc"
         return is_refutable(((Pat_LOGICALpat *)pat)->_2) || is_refutable(((Pat_LOGICALpat *)pat)->_3); 
#line 87 "indexing.pcc"
          } break;
        case a_Pat::tag_MARKEDpat: {
#line 86 "indexing.pcc"
         pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 86 "indexing.pcc"
          } break;
        case a_Pat::tag_LITERALpat:
        case a_Pat::tag_LEXEMEpat: { goto L4; } break;
        default: { goto L5; } break;
      }
    } else { goto L3; }
  }
}
#line 108 "indexing.pcc"
#line 108 "indexing.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Is a pattern list refutable?
//
///////////////////////////////////////////////////////////////////////////////

Bool is_refutable( Pats pats)
{
  for_each (Pat, p, pats)
    if (is_refutable(p))
      return true;
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Is a labeled pattern list refutable?
//
///////////////////////////////////////////////////////////////////////////////

Bool is_refutable( LabPats pats)
{
  for_each (LabPat, p, pats)
    if (is_refutable(p.pat))
      return true;
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the indices.
//
///////////////////////////////////////////////////////////////////////////////

void indexing( int priority, Pat pat, Pos pos, HashTable& index_map)
{
  
#line 147 "indexing.pcc"
#line 167 "indexing.pcc"
{
  for (;;) {
    if (pat) {
      switch (pat->tag__) {
        case a_Pat::tag_APPpat: {
          if (((Pat_APPpat *)pat)->_1) {
            switch (((Pat_APPpat *)pat)->_1->tag__) {
              case a_Pat::tag_CONSpat: {
                if (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat) {
                  if (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty) {
                    switch (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty->tag__) {
                      case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)) {
                          switch (((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1->tag__) {
                            case a_TyCon::tag_DATATYPEtycon: {
                              if (((Pat_APPpat *)pat)->_2) {
#line 156 "indexing.pcc"
                              indexing(priority, ((Pat_APPpat *)pat)->_2, POSint(((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit, pos), index_map); return; 
#line 156 "indexing.pcc"
                              } else { goto L6; }
                              } break;
                            default: { goto L6; } break;
                          }
                        } else { goto L6; }
                        } break;
                      default: { goto L6; } break;
                    }
                  } else { goto L6; }
                } else { goto L6; }
                } break;
              default: { goto L6; } break;
            }
          } else { goto L6; }
          } break;
        case a_Pat::tag_TYPEDpat: {
#line 150 "indexing.pcc"
         pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 150 "indexing.pcc"
          } break;
        case a_Pat::tag_ASpat: {
#line 149 "indexing.pcc"
         pat = ((Pat_ASpat *)pat)->_2; 
#line 149 "indexing.pcc"
          } break;
        case a_Pat::tag_CONTEXTpat: {
#line 152 "indexing.pcc"
         pat = ((Pat_CONTEXTpat *)pat)->_2; 
#line 152 "indexing.pcc"
          } break;
        case a_Pat::tag_ARRAYpat: {
#line 158 "indexing.pcc"
         indexing(priority, ((Pat_ARRAYpat *)pat)->_1, pos, index_map); return; 
#line 158 "indexing.pcc"
          } break;
        case a_Pat::tag_TUPLEpat: {
#line 157 "indexing.pcc"
         indexing(priority, ((Pat_TUPLEpat *)pat)->TUPLEpat, pos, index_map); return; 
#line 157 "indexing.pcc"
          } break;
        case a_Pat::tag_RECORDpat: {
#line 162 "indexing.pcc"
          
          for_each(LabPat, p, ((Pat_RECORDpat *)pat)->_1)
            indexing(priority, p.pat, POSlabel(p.label,pos), index_map);
          return;
          
#line 166 "indexing.pcc"
          } break;
        case a_Pat::tag_VECTORpat: {
#line 160 "indexing.pcc"
         indexing(priority, 
#line 160 "indexing.pcc"
#line 160 "indexing.pcc"
          list_1_(((Pat_VECTORpat *)pat)->len,((Pat_VECTORpat *)pat)->elements)
#line 160 "indexing.pcc"
#line 160 "indexing.pcc"
          , pos, index_map); return; 
#line 160 "indexing.pcc"
          } break;
        case a_Pat::tag_LOGICALpat: {
#line 167 "indexing.pcc"
         indexing(priority,((Pat_LOGICALpat *)pat)->_2,pos,index_map); pat = ((Pat_LOGICALpat *)pat)->_3; 
#line 167 "indexing.pcc"
          } break;
        case a_Pat::tag_MARKEDpat: {
#line 151 "indexing.pcc"
         pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 151 "indexing.pcc"
          } break;
        default: { goto L6; } break;
      }
    } else { goto L6; }
  }
  L6:;
}
#line 168 "indexing.pcc"
#line 168 "indexing.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the indices.
//
///////////////////////////////////////////////////////////////////////////////

void indexing( int priority, Pats pats, Pos pos, HashTable& index_map)
{
  int n;
  Pat Ps[32];

  int i = 0;
  // initialize the pattern array
  { for_each (Pat, p, pats) Ps[i++] = p; }
  n = i;
  if (n <= 0 || n > 32) return;

  // compute the set of index positions for this pattern list
  unsigned long indices = 0;
  for (i = 0; i < n; i++)
    if (is_refutable(Ps[i])) indices |= 1 << i;

  // Locate the position ranking
  HashTable::Entry * e = index_map.lookup(pos);
  int * ranks;
  if (e)
  {
    // Heuristic to update the ranks given new index and priority
    // informations.
    ranks = (int*)index_map.value(e);
  }
  else
  {
    // Initialize the new ranking array.
    // Put all used positions in front and
    // the rest the the back.
    ranks = (int*)mem_pool[n * sizeof(int)];
    int j = 0;
    for (i = 0; i < n; i++) if (indices & (1 << i))     ranks[j++] = i;
    for (i = 0; i < n; i++) if (! (indices & (1 << i))) ranks[j++] = i;
    index_map.insert( pos, ranks);
  }

  // Recursive on subcomponents, and insert an adaptive rank.
  for (i = 0; i < n; i++)
    indexing( priority, Ps[i], POSadaptive( i, ranks, pos), index_map);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the indices information for a set of pattern matching
//  rules.
//
///////////////////////////////////////////////////////////////////////////////

void indexing( MatchRules rules, HashTable& index_map)
{
  int priority = 0;
  for_each (MatchRule, r, rules)
  {
    
#line 231 "indexing.pcc"
#line 237 "indexing.pcc"
{
#line 234 "indexing.pcc"
  
  indexing( priority, r->_2, POSzero, index_map);
  priority++;
  
#line 237 "indexing.pcc"
}
#line 238 "indexing.pcc"
#line 238 "indexing.pcc"

  }
}
#line 241 "indexing.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 201
Number of ifs generated      = 14
Number of switches generated = 8
Number of labels             = 3
Number of gotos              = 9
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
