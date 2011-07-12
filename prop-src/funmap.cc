///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "funmap.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _f_u_n_m_a_pco_c_c_Q3("##");
static const Quark _f_u_n_m_a_pco_c_c_Q4("$$");
static const Quark _f_u_n_m_a_pco_c_c_Q1("#");
static const Quark _f_u_n_m_a_pco_c_c_Q2("$");
#line 1 "funmap.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the FunctorMap data structure
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <strstream>
#include <AD/automata/treegram.h>
#include <AD/automata/treegen.h>
#include <AD/rewrite/burs_gen.h>
#include <AD/strings/quark.h>
#include "funmap.h"
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "hashtab.h"
#include "datagen.h"
#include "config.h"
#include "rwgen.h"
#include "options.h"
#include "list.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Import some type definitions from the tree grammar and hash table
//  classes.
//
///////////////////////////////////////////////////////////////////////////////

typedef TreeGrammar::TreeProduction TreeProduction;
typedef TreeGrammar::Cost           TreeCost;
typedef HashTable::Key              Key;
typedef HashTable::Value            Value;

TreeTerm new_term(Mem& mem, short int f, unsigned char n, TreeTerm * subterms);
///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the vector id type
//
///////////////////////////////////////////////////////////////////////////////

#line 45 "funmap.pcc"
#line 45 "funmap.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype VectorId
//
///////////////////////////////////////////////////////////////////////////////
#line 45 "funmap.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype VectorId
//
///////////////////////////////////////////////////////////////////////////////
#line 45 "funmap.pcc"
a_VectorId::a_VectorId (Cons x_cons, Ty x_ty, int x_arity)
 : cons(x_cons), ty(x_ty), arity(x_arity)
{
}
a_VectorId * vector_id (Cons x_cons, Ty x_ty, int x_arity)
{
  return new a_VectorId (x_cons, x_ty, x_arity);
}


#line 45 "funmap.pcc"
#line 45 "funmap.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Hashing and equality on vector id's
//
///////////////////////////////////////////////////////////////////////////////

unsigned int vector_id_hash( HashTable::Key k)
{
  VectorId id = (VectorId)k;
  return (unsigned int)id->cons + ty_hash(id->ty) + id->arity;
}

Bool vector_id_equal( HashTable::Key a, HashTable::Key b)
{
  VectorId x = (VectorId) a;
  VectorId y = (VectorId) b;
  return x->cons == y->cons && x->arity == y->arity && ty_equal(x->ty,y->ty);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to decorate cost expression and attribute bindings for
//  a pattern.
//
///////////////////////////////////////////////////////////////////////////////

int decor_rewrite( Pat pat, int rule, int kid, PatternVarEnv& E)
{
  
#line 75 "funmap.pcc"
#line 104 "funmap.pcc"
{
  for (;;) {
    if (pat) {
      switch (pat->tag__) {
        case a_Pat::tag_APPpat: {
#line 81 "funmap.pcc"
         pat = ((Pat_APPpat *)pat)->_2; 
#line 81 "funmap.pcc"
          } break;
        case a_Pat::tag_TYPEDpat: {
#line 79 "funmap.pcc"
         pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 79 "funmap.pcc"
          } break;
        case a_Pat::tag_ASpat: {
#line 95 "funmap.pcc"
          
          Id attrib_name = 
#line 96 "funmap.pcc"
#line 96 "funmap.pcc"
          _f_u_n_m_a_pco_c_c_Q1
#line 96 "funmap.pcc"
#line 96 "funmap.pcc"
         + ((Pat_ASpat *)pat)->_1;
          Id cost_name   = 
#line 97 "funmap.pcc"
#line 97 "funmap.pcc"
          _f_u_n_m_a_pco_c_c_Q2
#line 97 "funmap.pcc"
#line 97 "funmap.pcc"
         + ((Pat_ASpat *)pat)->_1;
          Ty ty = mkvar();
          E.add( attrib_name, SYNexp( kid, rule, mkvar(), true), ty, ISpositive);
          E.add( cost_name, COSTexp(kid),  ty, ISpositive);
          kid = kid+1;
          pat = ((Pat_ASpat *)pat)->_2;
          
#line 103 "funmap.pcc"
          } break;
        case a_Pat::tag_CONTEXTpat: {
#line 82 "funmap.pcc"
         pat = ((Pat_CONTEXTpat *)pat)->_2; 
#line 82 "funmap.pcc"
          } break;
        case a_Pat::tag_TUPLEpat: {
#line 84 "funmap.pcc"
         return decor_rewrite( ((Pat_TUPLEpat *)pat)->TUPLEpat, rule, kid, E); 
#line 84 "funmap.pcc"
          } break;
        case a_Pat::tag_LISTpat: {
#line 86 "funmap.pcc"
         kid = decor_rewrite( ((Pat_LISTpat *)pat)->head, rule, kid, E); pat = ((Pat_LISTpat *)pat)->tail; 
#line 86 "funmap.pcc"
          } break;
        case a_Pat::tag_VECTORpat: {
#line 88 "funmap.pcc"
          
          kid = decor_rewrite(((Pat_VECTORpat *)pat)->elements, rule, decor_rewrite(((Pat_VECTORpat *)pat)->array, rule, kid, E), E);
          if (((Pat_VECTORpat *)pat)->head_flex || ((Pat_VECTORpat *)pat)->tail_flex)
            error( "%Lflexible vector pattern currently not supported in rewriting: %p\n", pat);
          pat = ((Pat_VECTORpat *)pat)->len;
          
#line 93 "funmap.pcc"
          } break;
        case a_Pat::tag_GUARDpat: {
#line 80 "funmap.pcc"
         pat = ((Pat_GUARDpat *)pat)->_1; 
#line 80 "funmap.pcc"
          } break;
        case a_Pat::tag_MARKEDpat: {
#line 78 "funmap.pcc"
         pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 78 "funmap.pcc"
          } break;
        case a_Pat::tag_CONSpat:
        case a_Pat::tag_LITERALpat: {
          L2:; 
#line 77 "funmap.pcc"
         return kid; 
#line 77 "funmap.pcc"
          } break;
        default: {
#line 104 "funmap.pcc"
         return kid; 
#line 104 "funmap.pcc"
          } break;
      }
    } else { goto L2; }
  }
}
#line 105 "funmap.pcc"
#line 105 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate a pattern list.
//
///////////////////////////////////////////////////////////////////////////////

int decor_rewrite (Pats pats, int rule, int kid, PatternVarEnv& E)
{
  for_each ( Pat, p, pats)
    kid = decor_rewrite( p, rule, kid, E);
  return kid;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate rewriting patterns.
//
///////////////////////////////////////////////////////////////////////////////

int decor_rewrite( Pat pat, int rule, PatternVarEnv& E)
{
  Ty ty = mkvar();
  E.add( 
#line 130 "funmap.pcc"
#line 130 "funmap.pcc"
_f_u_n_m_a_pco_c_c_Q3
#line 130 "funmap.pcc"
#line 130 "funmap.pcc"
, THISSYNexp(rule,mkvar(),true), ty, ISpositive);
  E.add( 
#line 131 "funmap.pcc"
#line 131 "funmap.pcc"
_f_u_n_m_a_pco_c_c_Q4
#line 131 "funmap.pcc"
#line 131 "funmap.pcc"
, THISCOSTexp(), ty, ISpositive);
  return decor_rewrite( pat, rule, 0, E);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor of the functor mapping table.
//
///////////////////////////////////////////////////////////////////////////////

FunctorMap::FunctorMap(Id name, MatchRules rules)
  : literal_map( literal_hash, literal_equal, 129),
    var_map( string_hash, string_equal),
    type_map( ty_hash, ty_equal),
    vector_map( vector_id_hash, vector_id_equal),
    rule_map( ty_hash, ty_equal),
    topdown_rule_map(ty_hash, ty_equal),
    before_rule_map(ty_hash, ty_equal),
    preorder_rule_map( ty_hash, ty_equal),
    postorder_rule_map( ty_hash, ty_equal),
    protocols( ty_hash, ty_equal),
    nonterm_map( string_hash, string_equal),
    nonterm_rules( string_hash, string_equal),
    nonterm_rules_bits( string_hash, string_equal),
    chain_rules( string_hash, string_equal),
    bottomup_rules(
#line 156 "funmap.pcc"
#line 156 "funmap.pcc"
nil_1_
#line 156 "funmap.pcc"
#line 156 "funmap.pcc"
)
{
  ///////////////////////////////////////////////////////////////////////////
  //
  //  Initialize the internals.
  //
  ///////////////////////////////////////////////////////////////////////////

  class_name      = name;
  N               = length(rules);
  functors        = 0;
  variables       = 0;
  tree_gen        = 0;
  topdown_gen     = 0;
  use_compression = true;
  has_guard       = false;
  has_replacement = false;
  has_cost        = false;
  has_cost_exp    = false;
  has_syn_attrib  = false;
  is_applicative  = false;
  gen_reducers    = false;
  dynamic_search  = false;
  max_arity       = 1;
  functor_names   = 0;
  variable_names  = 0;
  is_ok           = true;

  rule_maps[MatchRuleInfo::BOTTOMUP]  = &rule_map;
  rule_maps[MatchRuleInfo::TOPDOWN]   = &topdown_rule_map;
  rule_maps[MatchRuleInfo::BEFORE]    = &before_rule_map;
  rule_maps[MatchRuleInfo::PREORDER]  = &preorder_rule_map;
  rule_maps[MatchRuleInfo::POSTORDER] = &postorder_rule_map;

  TyQual qual = RewritingCompiler::lookup_qual(class_name);
  if (qual & QUALtreeparser)  gen_reducers = true;
  if (qual & QUALapplicative) is_applicative = true;

  int last_errors = errors;
  enter_protocols();             // enter the protocols
                                 // partition rule by type
  bottomup_rules = partition_rules(rules);
  check_for_missing_protocols();

  if (errors != last_errors)
  {
    is_ok = false;
    return;
  }

  build_tree_grammar(bottomup_rules);

  // BUG fix, always use dynamic search algorithm when treeparser
  // mode is on, since the class interface has to match.
  //dynamic_search = gen_reducers && (has_cost || has_cost_exp);

  dynamic_search = gen_reducers;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to enter the protocols into the protocol map
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::enter_protocols()
{
  Protocols Ps = RewritingCompiler::lookup_protocols( class_name);
  {
    for_each (Protocol, p, Ps)
    {
      
#line 226 "funmap.pcc"
#line 234 "funmap.pcc"
{
#line 229 "funmap.pcc"
  
  encode(p->ty);
  protocols.insert( p->ty, p);
  if (p->syn != NOty)
    has_syn_attrib = true;
  
#line 234 "funmap.pcc"
}
#line 235 "funmap.pcc"
#line 235 "funmap.pcc"

    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Checks for missing protocol
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::check_for_missing_protocols()
{
  foreach_entry (e, type_map)
  {
    Ty ty = Ty( type_map.key(e));
    if ( !protocols.contains(ty))
    {
      error("%Lmissing type %T in the traversal list of rewrite class %s\n",
             ty, class_name);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Otherwise, build the tree grammar and the functor/variable name maps.
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::build_tree_grammar( MatchRules rules)
{
  N = length(rules);
  TreeProduction * Ps =
      (TreeProduction *) mem_pool.c_alloc( sizeof( TreeProduction) * N);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Translate patterns into terms
  //
  ////////////////////////////////////////////////////////////////////////////

  {
    int i = 0;
    for_each (MatchRule, r, rules)
    {
      
#line 282 "funmap.pcc"
#line 300 "funmap.pcc"
{
#line 285 "funmap.pcc"
  
  int rule_no = r->_1 ? var_map[r->_1] : 0;
  int cst;
  
#line 288 "funmap.pcc"
#line 292 "funmap.pcc"
  {
    Cost _V1 = r->_4;
    if (_V1) {
      if (untagp(_V1)) {
        
#line 291 "funmap.pcc"
       cst = ((Cost_INTcost *)derefp(_V1))->INTcost; has_cost = true; 
#line 291 "funmap.pcc"
      } else {
        
#line 292 "funmap.pcc"
       cst = 0; has_cost_exp = true; 
#line 292 "funmap.pcc"
      }
    } else {
#line 290 "funmap.pcc"
     cst = 0; 
#line 290 "funmap.pcc"
    }
  }
#line 293 "funmap.pcc"
#line 293 "funmap.pcc"
  
  Ps[i] = TreeProduction(rule_no,trans(r->_2),cst);
  if (r->_3 != NOexp || (r->option & MatchRuleInfo::FAILREWRITE))
    has_guard = true;
  if (r->option & MatchRuleInfo::REPLACEMENT)
    has_replacement = true;
  i++;
  
#line 300 "funmap.pcc"
}
#line 301 "funmap.pcc"
#line 301 "funmap.pcc"

    }
  }

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Compute the functor/variable names
  //
  ////////////////////////////////////////////////////////////////////////////
  compute_names();

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Compile the tree grammar
  //
  ////////////////////////////////////////////////////////////////////////////
  G.compile (N, Ps, functor_names, variable_names, 0, functors - 1, 0);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to convert literal patterns inside a set of matching rules
//  into guards
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::make_guard( MatchRules rules)
{
  
#line 328 "funmap.pcc"
#line 334 "funmap.pcc"
{
  for (;;) {
    if (rules) {
#line 331 "funmap.pcc"
      
      rules->_1->_2   = make_guard( rules->_1->_2, rules->_1->_3);
      rules = rules->_2;
      
#line 334 "funmap.pcc"
    } else { goto L3; }
  }
  L3:;
}
#line 335 "funmap.pcc"
#line 335 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to convert literal patterns into guards.
//
///////////////////////////////////////////////////////////////////////////////

Pat FunctorMap::make_guard( Pat pat, Exp& e)
{
  Pat new_pat;
  // return pat; // BUG fix
  
#line 348 "funmap.pcc"
#line 383 "funmap.pcc"
{
  if (pat) {
    switch (pat->tag__) {
      case a_Pat::tag_APPpat: {
#line 355 "funmap.pcc"
       new_pat = APPpat( make_guard( ((Pat_APPpat *)pat)->_1, e), make_guard( ((Pat_APPpat *)pat)->_2, e)); 
#line 355 "funmap.pcc"
        } break;
      case a_Pat::tag_TYPEDpat: {
#line 351 "funmap.pcc"
       new_pat = TYPEDpat( make_guard( ((Pat_TYPEDpat *)pat)->_1, e), ((Pat_TYPEDpat *)pat)->_2); 
#line 351 "funmap.pcc"
        } break;
      case a_Pat::tag_ASpat: {
#line 350 "funmap.pcc"
       new_pat = ASpat( ((Pat_ASpat *)pat)->_1, make_guard( ((Pat_ASpat *)pat)->_2, e), ((Pat_ASpat *)pat)->_3, ((Pat_ASpat *)pat)->_4); 
#line 350 "funmap.pcc"
        } break;
      case a_Pat::tag_LITERALpat: {
        switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
          case a_Literal::tag_INTlit:
          case a_Literal::tag_BOOLlit:
          case a_Literal::tag_CHARlit:
          case a_Literal::tag_REALlit: {
#line 357 "funmap.pcc"
            
            Exp guard_exp = BINOPexp( "==", pat->selector, LITERALexp(((Pat_LITERALpat *)pat)->LITERALpat));
            e = e == NOexp ? guard_exp : BINOPexp( "&&", e, guard_exp);
            new_pat = WILDpat();
            
#line 361 "funmap.pcc"
            } break;
          default: {
            L4:; 
#line 383 "funmap.pcc"
           new_pat = pat; 
#line 383 "funmap.pcc"
            } break;
        }
        } break;
      case a_Pat::tag_TUPLEpat: {
#line 353 "funmap.pcc"
       new_pat = TUPLEpat( make_guard( ((Pat_TUPLEpat *)pat)->TUPLEpat, e)); 
#line 353 "funmap.pcc"
        } break;
      case a_Pat::tag_RECORDpat: {
#line 354 "funmap.pcc"
       new_pat = RECORDpat( make_guard( ((Pat_RECORDpat *)pat)->_1, e), ((Pat_RECORDpat *)pat)->_2); 
#line 354 "funmap.pcc"
        } break;
      case a_Pat::tag_LISTpat: {
#line 363 "funmap.pcc"
        
        new_pat = 
#line 364 "funmap.pcc"
#line 364 "funmap.pcc"
        LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, make_guard(((Pat_LISTpat *)pat)->head,e), make_guard(((Pat_LISTpat *)pat)->tail,e))
#line 369 "funmap.pcc"
#line 369 "funmap.pcc"
        ;
        
#line 370 "funmap.pcc"
        } break;
      case a_Pat::tag_VECTORpat: {
#line 372 "funmap.pcc"
        
        new_pat = 
#line 373 "funmap.pcc"
#line 373 "funmap.pcc"
        VECTORpat(((Pat_VECTORpat *)pat)->cons, make_guard(((Pat_VECTORpat *)pat)->len,e), make_guard(((Pat_VECTORpat *)pat)->array,e), make_guard(((Pat_VECTORpat *)pat)->elements,e), ((Pat_VECTORpat *)pat)->head_flex, ((Pat_VECTORpat *)pat)->tail_flex)
#line 381 "funmap.pcc"
#line 381 "funmap.pcc"
        ;
        
#line 382 "funmap.pcc"
        } break;
      case a_Pat::tag_MARKEDpat: {
#line 352 "funmap.pcc"
       new_pat = MARKEDpat( ((Pat_MARKEDpat *)pat)->_1, make_guard( ((Pat_MARKEDpat *)pat)->_2, e)); 
#line 352 "funmap.pcc"
        } break;
      default: { goto L4; } break;
    }
  } else { goto L4; }
}
#line 384 "funmap.pcc"
#line 384 "funmap.pcc"

  if (new_pat != pat && boxed(new_pat))
  {
    new_pat->ty = pat->ty;
    new_pat->selector = pat->selector;
  }
  return new_pat;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Unguard a pattern list
//
///////////////////////////////////////////////////////////////////////////////

Pats FunctorMap::make_guard( Pats ps, Exp& e)
{
  
#line 401 "funmap.pcc"
#line 404 "funmap.pcc"
{
  if (ps) {
#line 404 "funmap.pcc"
   return 
#line 404 "funmap.pcc"
#line 404 "funmap.pcc"
    list_1_(make_guard(ps->_1,e),make_guard(ps->_2,e))
#line 404 "funmap.pcc"
#line 404 "funmap.pcc"
    ; 
#line 404 "funmap.pcc"
  } else {
#line 403 "funmap.pcc"
   return 
#line 403 "funmap.pcc"
#line 403 "funmap.pcc"
    nil_1_
#line 403 "funmap.pcc"
#line 403 "funmap.pcc"
    ; 
#line 403 "funmap.pcc"
  }
}
#line 405 "funmap.pcc"
#line 405 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Unguard a labeled pattern list
//
///////////////////////////////////////////////////////////////////////////////

LabPats FunctorMap::make_guard( LabPats ps, Exp& e)
{
  
#line 416 "funmap.pcc"
#line 424 "funmap.pcc"
{
  if (ps) {
#line 419 "funmap.pcc"
    
    LabPat lab_pat;
    lab_pat.label = ps->_1.label;
    lab_pat.pat   = make_guard( ps->_1.pat, e);
    return 
#line 423 "funmap.pcc"
#line 423 "funmap.pcc"
    list_1_(lab_pat,make_guard(ps->_2,e))
#line 423 "funmap.pcc"
#line 423 "funmap.pcc"
    ;
    
#line 424 "funmap.pcc"
  } else {
#line 418 "funmap.pcc"
   return 
#line 418 "funmap.pcc"
#line 418 "funmap.pcc"
    nil_1_
#line 418 "funmap.pcc"
#line 418 "funmap.pcc"
    ; 
#line 418 "funmap.pcc"
  }
}
#line 425 "funmap.pcc"
#line 425 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Check whether we know of the type
//
///////////////////////////////////////////////////////////////////////////////

Bool FunctorMap::is_known_type( Ty ty)
{
  return type_map.contains(ty)      ||
         ty_equal(ty, string_ty)    ||
         ty_equal(ty, quark_ty)
//       ty_equal(ty, integer_ty)   ||
//       ty_equal(ty, bool_ty)      ||
//       ty_equal(ty, real_ty)      ||
//       ty_equal(ty, character_ty)
  ;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Check whether we the type is rewritable.
//
///////////////////////////////////////////////////////////////////////////////

Bool FunctorMap::is_rewritable_type( Ty ty) { return type_map.contains(ty); }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign variable encoding to a non-terminal
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::encode( Id id)
{
  if ( !var_map.contains( id))
  {
    ++variables;
    var_map.insert( id, variables);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign functor encoding to a type
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::encode( Ty ty)
{
  
#line 477 "funmap.pcc"
#line 489 "funmap.pcc"
{
  Ty _V2 = deref_all(ty);
  if (_V2) {
    switch (_V2->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V2)->_1)) {
          switch (((Ty_TYCONty *)_V2)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 480 "funmap.pcc"
              
              if (! type_map.contains(_V2))
              {
                type_map.insert( _V2, functors);
                functors += ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->arg;
              }
              
#line 486 "funmap.pcc"
              } break;
            default: {
              L5:; 
#line 487 "funmap.pcc"
            for_each(Ty, ty, ((Ty_TYCONty *)_V2)->_2) encode(ty); 
#line 487 "funmap.pcc"
              } break;
          }
        } else { goto L5; }
        } break;
      default: {
        L6:; } break;
    }
  } else { goto L6; }
}
#line 489 "funmap.pcc"
#line 489 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign functor encoding to a pattern.
//  Assign a functor value to each distinct literal and pattern constructor.
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::encode( Pat pat)
{
  
#line 501 "funmap.pcc"
#line 579 "funmap.pcc"
{
  for (;;) {
    if (pat) {
      switch (pat->tag__) {
        case a_Pat::tag_CONSpat: {
          if (((Pat_CONSpat *)pat)->CONSpat) {
            if (((Pat_CONSpat *)pat)->CONSpat->alg_ty) {
              switch (((Pat_CONSpat *)pat)->CONSpat->alg_ty->tag__) {
                case a_Ty::tag_TYCONty: {
                  if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)) {
                    switch (((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1->tag__) {
                      case a_TyCon::tag_DATATYPEtycon: {
#line 539 "funmap.pcc"
                        
                        if (pat->ty != NOty && ! type_map.contains( pat->ty))
                        {  type_map.insert( pat->ty, functors);
                           functors += ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->arg;
                        }
                        return;
                        
#line 545 "funmap.pcc"
                        } break;
                      default: {
                        L8:; 
#line 579 "funmap.pcc"
                       error ("%LSorry: pattern not supported in rewriting: %p\n", pat); return; 
#line 579 "funmap.pcc"
                        } break;
                    }
                  } else { goto L8; }
                  } break;
                default: { goto L8; } break;
              }
            } else { goto L8; }
          } else { goto L8; }
          } break;
        case a_Pat::tag_APPpat: {
#line 546 "funmap.pcc"
         encode(pat->ty); pat = ((Pat_APPpat *)pat)->_2; 
#line 546 "funmap.pcc"
          } break;
        case a_Pat::tag_TYPEDpat: {
#line 505 "funmap.pcc"
         pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 505 "funmap.pcc"
          } break;
        case a_Pat::tag_ASpat: {
#line 504 "funmap.pcc"
         pat = ((Pat_ASpat *)pat)->_2; 
#line 504 "funmap.pcc"
          } break;
        case a_Pat::tag_LITERALpat: {
          switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
            case a_Literal::tag_BIGINTlit: { goto L8; } break;
            case a_Literal::tag_STRINGlit:
            case a_Literal::tag_REGEXPlit:
            case a_Literal::tag_QUARKlit: {
#line 526 "funmap.pcc"
              
              if (! literal_map.contains(((Pat_LITERALpat *)pat)->LITERALpat))
              {
                literal_map.insert( ((Pat_LITERALpat *)pat)->LITERALpat, functors);
                functors++;
              }
              return;
              
#line 533 "funmap.pcc"
              } break;
            default: {
#line 535 "funmap.pcc"
             bug ("%Luntransformed literal pattern %p found in rewriting\n",pat); 
#line 535 "funmap.pcc"
              } break;
          }
          } break;
        case a_Pat::tag_TUPLEpat: {
#line 508 "funmap.pcc"
          
          int i = 0;
          for_each (Pat, p, ((Pat_TUPLEpat *)pat)->TUPLEpat)
            { i++; encode(p); }
          if (max_arity < i)
            max_arity = i;
          return;
          
#line 515 "funmap.pcc"
          } break;
        case a_Pat::tag_RECORDpat: {
#line 517 "funmap.pcc"
          
          for_each (LabPat, p, ((Pat_RECORDpat *)pat)->_1)
            encode(p.pat);
          int arity = arity_of(pat->ty);
          if (max_arity < arity)
            max_arity = arity;
          return;
          
#line 524 "funmap.pcc"
          } break;
        case a_Pat::tag_LISTpat: {
#line 548 "funmap.pcc"
          
          Pat new_pat = CONSpat(((Pat_LISTpat *)pat)->nil);
          new_pat->ty = pat->ty;
          encode( new_pat);
          for_each (Pat, i, ((Pat_LISTpat *)pat)->head)
            encode(i);
          if (max_arity < 2)
            max_arity = 2;
          pat = ((Pat_LISTpat *)pat)->tail;
          
#line 557 "funmap.pcc"
          } break;
        case a_Pat::tag_VECTORpat: {
#line 559 "funmap.pcc"
          
          Pat new_pat = CONSpat(((Pat_VECTORpat *)pat)->cons);
          new_pat->ty = pat->ty;
          encode(new_pat);
          for_each (Pat, p, ((Pat_VECTORpat *)pat)->elements)
            encode(p);
          int l = length(((Pat_VECTORpat *)pat)->elements);
          if (max_arity < l)
            max_arity = l;
          if (pat->ty != NOty)
          {
            VectorId vec_id = vector_id( ((Pat_VECTORpat *)pat)->cons, pat->ty, l);
            if ( ! vector_map.contains(vec_id))
            {
              vector_map.insert(vec_id, functors);
              functors++;
            }
          }
          return;
          
#line 578 "funmap.pcc"
          } break;
        case a_Pat::tag_MARKEDpat: {
#line 506 "funmap.pcc"
         pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 506 "funmap.pcc"
          } break;
        case a_Pat::tag_WILDpat:
        case a_Pat::tag_IDpat: {
          L9:; 
#line 503 "funmap.pcc"
         return; 
#line 503 "funmap.pcc"
          } break;
        default: { goto L8; } break;
      }
    } else { goto L9; }
  }
}
#line 580 "funmap.pcc"
#line 580 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to translate a pattern into a term.
//
///////////////////////////////////////////////////////////////////////////////

TreeTerm FunctorMap::trans( Pat pat)
{
  
#line 591 "funmap.pcc"
#line 694 "funmap.pcc"
{
  for (;;) {
    if (pat) {
      switch (pat->tag__) {
        case a_Pat::tag_WILDpat: {
          L11:; 
#line 593 "funmap.pcc"
         return wild_term; 
#line 593 "funmap.pcc"
          } break;
        case a_Pat::tag_IDpat: {
#line 602 "funmap.pcc"
          
          return var_map.contains(((Pat_IDpat *)pat)->_1) ? var_term(var_map[((Pat_IDpat *)pat)->_1]) : wild_term;
          
#line 604 "funmap.pcc"
          } break;
        case a_Pat::tag_CONSpat: {
          if (((Pat_CONSpat *)pat)->CONSpat) {
#line 668 "funmap.pcc"
           return new_term( mem_pool, type_map[pat->ty] + ((Pat_CONSpat *)pat)->CONSpat->tag); 
#line 668 "funmap.pcc"
          } else {
            L12:; 
#line 694 "funmap.pcc"
           error ("%LSorry: pattern not supported: %p\n", pat); return wild_term; 
#line 694 "funmap.pcc"
          }
          } break;
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
#line 654 "funmap.pcc"
                              
                              TreeTerm a = trans(((Pat_APPpat *)pat)->_2);
                              
#line 656 "funmap.pcc"
#line 664 "funmap.pcc"
                              {
                                int _V4 = arity_of(((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->ty);
                                switch (_V4) {
                                  case 1: {
#line 659 "funmap.pcc"
                                   return new_term( mem_pool, type_map[pat->ty] + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit + ((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag, 1, &a); 
#line 659 "funmap.pcc"
                                  } break;
                                  default: {
                                    if (a) {
                                      switch (a->tag__) {
                                        case a_TreeTerm::tag_tree_term: {
#line 661 "funmap.pcc"
                                        ((TreeTerm_tree_term *)a)->_1 = type_map[pat->ty] + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit + ((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag; return a; 
#line 661 "funmap.pcc"
                                          } break;
                                        default: {
                                          L13:; 
#line 663 "funmap.pcc"
                                        return new_term( mem_pool, type_map[pat->ty] + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit + ((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag, _V4);
                                          
#line 664 "funmap.pcc"
                                          } break;
                                      }
                                    } else { goto L13; }
                                  }
                                }
                              }
#line 665 "funmap.pcc"
#line 665 "funmap.pcc"
                              
                              
#line 666 "funmap.pcc"
                              } break;
                            default: { goto L12; } break;
                          }
                        } else { goto L12; }
                        } break;
                      default: { goto L12; } break;
                    }
                  } else { goto L12; }
                } else { goto L12; }
                } break;
              default: { goto L12; } break;
            }
          } else { goto L12; }
          } break;
        case a_Pat::tag_TYPEDpat: {
#line 595 "funmap.pcc"
         pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 595 "funmap.pcc"
          } break;
        case a_Pat::tag_ASpat: {
#line 594 "funmap.pcc"
         pat = ((Pat_ASpat *)pat)->_2; 
#line 594 "funmap.pcc"
          } break;
        case a_Pat::tag_LITERALpat: {
          switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
            case a_Literal::tag_STRINGlit:
            case a_Literal::tag_REGEXPlit:
            case a_Literal::tag_QUARKlit: {
#line 598 "funmap.pcc"
             return new_term(mem_pool,literal_map[((Pat_LITERALpat *)pat)->LITERALpat]); 
#line 598 "funmap.pcc"
              } break;
            default: {
#line 600 "funmap.pcc"
             return wild_term; 
#line 600 "funmap.pcc"
              } break;
          }
          } break;
        case a_Pat::tag_TUPLEpat: {
#line 606 "funmap.pcc"
          
          int arity = length (((Pat_TUPLEpat *)pat)->TUPLEpat);
          TreeTerm * subterms =
             (TreeTerm *)mem_pool.c_alloc( sizeof( TreeTerm) * arity);
          int i = 0;
          for_each (Pat, p, ((Pat_TUPLEpat *)pat)->TUPLEpat)
            subterms[i++] = trans(p);
          return new_term( mem_pool, 0, arity, subterms);
          
#line 614 "funmap.pcc"
          } break;
        case a_Pat::tag_RECORDpat: {
#line 616 "funmap.pcc"
          
          
#line 617 "funmap.pcc"
#line 647 "funmap.pcc"
          {
            Ty _V3 = deref(pat->ty);
            if (_V3) {
              switch (_V3->tag__) {
                case a_Ty::tag_TYCONty: {
                  if (boxed(((Ty_TYCONty *)_V3)->_1)) {
                    switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                      case a_TyCon::tag_RECORDtycon: {
#line 620 "funmap.pcc"
                        
                        Bool relevant[256];
                        int i;
                        int arity;
                        
                        i = arity = 0;
                        for_each(Ty, t, ((Ty_TYCONty *)_V3)->_2)
                          if (relevant[i++] = is_known_type(t))
                            arity++;
                        TreeTerm * subterms =
                           (TreeTerm *)mem_pool.c_alloc( sizeof( TreeTerm) * arity);
                        for (i = 0; i < arity; i++)
                           subterms[i] = wild_term;
                        for_each (LabPat, p, ((Pat_RECORDpat *)pat)->_1)
                        {
                          Ids labs; Tys ts;
                          for (i = 0, labs = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V3)->_1)->_1, ts = ((Ty_TYCONty *)_V3)->_2;
                               labs && ts; labs = labs->_2, ts = ts->_2)
                          {
                            if (p.label == labs->_1)
                              {  subterms[i] = trans(p.pat); break; }
                            if (is_known_type(ts->_1))
                              i++;
                          }
                        }
                        return new_term( mem_pool, 0, arity,subterms);
                        
#line 646 "funmap.pcc"
                        } break;
                      default: {
                        L14:; 
#line 647 "funmap.pcc"
                       bug( "%Lillegal record pattern %p\n", pat); 
#line 647 "funmap.pcc"
                        } break;
                    }
                  } else { goto L14; }
                  } break;
                default: { goto L14; } break;
              }
            } else { goto L14; }
          }
#line 648 "funmap.pcc"
#line 648 "funmap.pcc"
          
          
#line 649 "funmap.pcc"
          } break;
        case a_Pat::tag_LISTpat: {
          if (((Pat_LISTpat *)pat)->head) {
#line 673 "funmap.pcc"
            
            Pat new_tail = 
#line 674 "funmap.pcc"
#line 674 "funmap.pcc"
            LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, ((Pat_LISTpat *)pat)->head->_2, ((Pat_LISTpat *)pat)->tail)
#line 674 "funmap.pcc"
#line 674 "funmap.pcc"
            ;
            Pat new_p    = APPpat( CONSpat( ((Pat_LISTpat *)pat)->cons), TUPLEpat(
#line 675 "funmap.pcc"
#line 675 "funmap.pcc"
            list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(new_tail))
#line 675 "funmap.pcc"
#line 675 "funmap.pcc"
            ));
            new_p->ty    = new_tail->ty = pat->ty;
            pat = new_p;
            
#line 678 "funmap.pcc"
          } else {
            if (((Pat_LISTpat *)pat)->tail) {
#line 671 "funmap.pcc"
            pat = ((Pat_LISTpat *)pat)->tail; 
#line 671 "funmap.pcc"
            } else {
#line 670 "funmap.pcc"
             Pat p = CONSpat(((Pat_LISTpat *)pat)->nil); p->ty = pat->ty; pat = p; 
#line 670 "funmap.pcc"
            }
          }
          } break;
        case a_Pat::tag_VECTORpat: {
#line 680 "funmap.pcc"
          
          TreeTerm a     = trans( TUPLEpat(((Pat_VECTORpat *)pat)->elements));
          int      arity = length(((Pat_VECTORpat *)pat)->elements);
          
#line 683 "funmap.pcc"
#line 691 "funmap.pcc"
          {
            if (a) {
              switch (a->tag__) {
                case a_TreeTerm::tag_tree_term: {
#line 686 "funmap.pcc"
                  
                  ((TreeTerm_tree_term *)a)->_1 = vector_map[ vector_id( ((Pat_VECTORpat *)pat)->cons, pat->ty, arity)];
                  return a;
                  
#line 689 "funmap.pcc"
                  } break;
                default: {
                  L15:; 
#line 691 "funmap.pcc"
                 bug ("%Lillegal pattern: %p\n", pat); return wild_term; 
#line 691 "funmap.pcc"
                  } break;
              }
            } else { goto L15; }
          }
#line 692 "funmap.pcc"
#line 692 "funmap.pcc"
          
          
#line 693 "funmap.pcc"
          } break;
        case a_Pat::tag_MARKEDpat: {
#line 596 "funmap.pcc"
         pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 596 "funmap.pcc"
          } break;
        default: { goto L12; } break;
      }
    } else { goto L11; }
  }
}
#line 695 "funmap.pcc"
#line 695 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute std::ceil(ln(2))
//
///////////////////////////////////////////////////////////////////////////////

int ln2 (int n)
{
  int bits = 0;
  while (n > 0)
    { n >>= 1; bits++; }
  return bits;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the rhs non-terminal (if it is a chain rule)
//  Otherwise, returns NIL.
//
///////////////////////////////////////////////////////////////////////////////

Id FunctorMap::chain_rule_rhs( Pat pat)
{
  
#line 721 "funmap.pcc"
#line 727 "funmap.pcc"
{
  if (pat) {
    switch (pat->tag__) {
      case a_Pat::tag_IDpat: {
#line 723 "funmap.pcc"
       return var_map.contains(((Pat_IDpat *)pat)->_1) ? ((Pat_IDpat *)pat)->_1 : 0; 
#line 723 "funmap.pcc"
        } break;
      case a_Pat::tag_TYPEDpat: {
#line 726 "funmap.pcc"
       return chain_rule_rhs(((Pat_TYPEDpat *)pat)->_1); 
#line 726 "funmap.pcc"
        } break;
      case a_Pat::tag_ASpat: {
#line 724 "funmap.pcc"
       return chain_rule_rhs(((Pat_ASpat *)pat)->_2); 
#line 724 "funmap.pcc"
        } break;
      case a_Pat::tag_MARKEDpat: {
#line 725 "funmap.pcc"
       return chain_rule_rhs(((Pat_MARKEDpat *)pat)->_2); 
#line 725 "funmap.pcc"
        } break;
      default: {
        L16:; 
#line 727 "funmap.pcc"
       return 0; 
#line 727 "funmap.pcc"
        } break;
    }
  } else { goto L16; }
}
#line 728 "funmap.pcc"
#line 728 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to partition the set of rules according to the types of the
//  patterns.  Also encode the patterns in the process.
//
///////////////////////////////////////////////////////////////////////////////

MatchRules FunctorMap::partition_rules( MatchRules rules)
{
  bottomup_rules = 
#line 740 "funmap.pcc"
#line 740 "funmap.pcc"
nil_1_
#line 740 "funmap.pcc"
#line 740 "funmap.pcc"
;
  // First, we assign a new type variable for each lhs non-terminal.
  {
    for_each (MatchRule, r, rules)
    {
      
#line 745 "funmap.pcc"
#line 773 "funmap.pcc"
{
#line 748 "funmap.pcc"
  
  if (r->mode == MatchRuleInfo::BOTTOMUP)
  {
    bottomup_rules = 
#line 751 "funmap.pcc"
#line 751 "funmap.pcc"
  list_1_(r,bottomup_rules)
#line 751 "funmap.pcc"
#line 751 "funmap.pcc"
  ;
  if (r->_1)
  {
    HashTable::Entry * lhs_entry = nonterm_map.lookup(r->_1);
    if (! lhs_entry)
      nonterm_map.insert(r->_1,mkvar());
    encode(r->_1);  // compute encoding for the variable
    HashTable::Entry * e = nonterm_rules.lookup(r->_1);
    if ( !e)
      nonterm_rules.insert( r->_1, 
#line 760 "funmap.pcc"
#line 760 "funmap.pcc"
  list_1_(r)
#line 760 "funmap.pcc"
#line 760 "funmap.pcc"
  );
  else
    { e->v = 
#line 762 "funmap.pcc"
#line 762 "funmap.pcc"
  list_1_(r,MatchRules(e->v))
#line 762 "funmap.pcc"
#line 762 "funmap.pcc"
  ; }
  }
  else if (dynamic_search)
    error( "%!missing non-terminal in tree grammar rule: %r\n",
           r->loc(), r);
  }
  else if (r->_1)
  {
  error( "%!illegal non-terminal in non bottom-up rule: %r\n",
         r->loc(), r);
  }
  
#line 773 "funmap.pcc"
}
#line 774 "funmap.pcc"
#line 774 "funmap.pcc"

    }
  }

  bottomup_rules = rev(bottomup_rules);

  // Compute the size needed to encode each non-terminal

  {
    foreach_entry (e, nonterm_rules)
    {
      int bits = ln2( length( MatchRules( e->v))+1);
      nonterm_rules_bits.insert( e->k, HashTable::Value( bits));
    }
  }

  // Type check all the rules next.
  // We have to also compute the type map for each lhs non-terminal.
  // Of course, a non-terminal but have only one single type.
  // This is done by unifying all occurances of a non-terminal.

  patvar_typemap = &nonterm_map; // set the pattern variable type map

  for_each (MatchRule, r, bottomup_rules)
  {
    
#line 799 "funmap.pcc"
#line 835 "funmap.pcc"
{
#line 802 "funmap.pcc"
  
  r->set_loc();
  Ty ty = r->ty = type_of(r->_2);
  
  // Check the type of the non-terminal (if any).
  if (r->_1)
  {
    Ty lhs_ty = Ty(nonterm_map.lookup(r->_1)->v);
    if (! unify(lhs_ty, ty))
    {
      error( "%!type mismatch between nonterminal %s(type %T) and rule %r(type %T)\n",
             r->loc(),r->_1,lhs_ty,r,ty);
    }
  }
  
  if ( !is_datatype(ty))
     error( "%!rule %r is of a non datatype: %T\n",r->loc(),r,ty);
  
  // Collect chain rules.
  
  if (r->_1)
  {
    Id rhs = chain_rule_rhs(r->_2);
    if (rhs)
    {
      HashTable::Entry * cr = chain_rules.lookup(rhs);
      if (! cr)
        chain_rules.insert( rhs, 
#line 829 "funmap.pcc"
#line 829 "funmap.pcc"
  list_1_(r)
#line 829 "funmap.pcc"
#line 829 "funmap.pcc"
  );
  else
    { cr->v = 
#line 831 "funmap.pcc"
#line 831 "funmap.pcc"
  list_1_(r,MatchRules(cr->v))
#line 831 "funmap.pcc"
#line 831 "funmap.pcc"
  ; }
  r->is_chain_rule = true;
  }
  }
  
#line 835 "funmap.pcc"
}
#line 836 "funmap.pcc"
#line 836 "funmap.pcc"

  }

  patvar_typemap = 0; // reset the pattern variable type map

  // Now partition rules by type and assign functor encoding.
  // Since we have also typed the rules, this is quite simple: just
  // another pass.  We have to make sure that after the type inference
  // we don't have any more polymorphic types inside the patterns.
  int rule_num = 0;
  for_each (MatchRule, R, rules)
  {
    
#line 848 "funmap.pcc"
#line 882 "funmap.pcc"
{
  if (
#line 850 "funmap.pcc"
  (R->mode != MatchRuleInfo::BOTTOMUP)
#line 850 "funmap.pcc"
) {
    
#line 851 "funmap.pcc"
    
    R->set_loc();
    R->ty = type_of(R->_2);
    HashTable::Entry * e = rule_maps[R->mode]->lookup(R->ty);
    if (e)
      e->v = 
#line 856 "funmap.pcc"
#line 856 "funmap.pcc"
    list_1_(R,MatchRules(e->v))
#line 856 "funmap.pcc"
#line 856 "funmap.pcc"
    ;
    else
      rule_maps[ R->mode]->insert( R->ty, 
#line 858 "funmap.pcc"
#line 858 "funmap.pcc"
    list_1_(R)
#line 858 "funmap.pcc"
#line 858 "funmap.pcc"
    );
    
#line 859 "funmap.pcc"
  } else {
    
#line 861 "funmap.pcc"
    
    if (! is_ground(R->ty))
      error( "%!rule %r has incomplete type %T\n", R->loc(), R, R->ty);
    
    HashTable::Entry * e = rule_map.lookup(R->ty);
    if (e)
      e->v = 
#line 867 "funmap.pcc"
#line 867 "funmap.pcc"
    list_1_(R,MatchRules(e->v))
#line 867 "funmap.pcc"
#line 867 "funmap.pcc"
    ;
    else
      rule_map.insert( R->ty, 
#line 869 "funmap.pcc"
#line 869 "funmap.pcc"
    list_1_(R)
#line 869 "funmap.pcc"
#line 869 "funmap.pcc"
    );
    
            // convert literals into guards
            // BUG: 2-6-97  This doesn't work right since
            // the guard testing is not prioritized properly !!!
    
            R->_2 = make_guard( R->_2, R->_3);
    
            // assign functor encoding
    
            encode( R->_2);
    
            R->rule_number = rule_num++;
          
#line 882 "funmap.pcc"
  }
}
#line 883 "funmap.pcc"
#line 883 "funmap.pcc"

  }

  return bottomup_rules;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the functor and variable table.
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::compute_names()
{
   functor_names  = (Id *) mem_pool.c_alloc( sizeof(Id) * functors);
   variable_names = (Id *) mem_pool.c_alloc( sizeof(Id) * (variables + N + 4));

   {  for (int i = N + variables - 1; i >= 0; i--) variable_names[i] = 0; }
   {  for (int i = functors - 1; i >= 0; i--)  functor_names[i] = "???"; }
   variable_names[0] = "_";

   // Compute variable names

   {
     foreach_entry (i,var_map)
       variable_names[var_map.value(i)] = (Id)var_map.key(i);
   }

   // Compute literal names
   {
     foreach_entry (i,literal_map)
     {
       Literal l = (Literal)literal_map.key(i);
       Functor f = literal_map.value(i);
       char buf[1024];
       std::ostrstream b(buf,sizeof(buf));
       std::ostream& s = b;
       s << l << std::ends;
       functor_names[f] = Quark(buf);
     }
   }

   // Compute constructor names
   {
     foreach_entry (i,type_map)
     {
       Ty      t = (Ty)type_map.key(i);
       Functor f = type_map.value(i);
       
#line 931 "funmap.pcc"
#line 948 "funmap.pcc"
{
  Ty _V5 = deref(t);
  if (_V5) {
    switch (_V5->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V5)->_1)) {
          switch (((Ty_TYCONty *)_V5)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 934 "funmap.pcc"
              
              int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->arg;
              for (int j = 0; j < arity; j++)
              {
                
#line 938 "funmap.pcc"
#line 945 "funmap.pcc"
              {
                Cons _V6 = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->terms[j];
                if (_V6) {
#line 941 "funmap.pcc"
                  
                  functor_names[f + (_V6->ty == NOty ? _V6->tag : _V6->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->unit)] = _V6->name;
                  
#line 943 "funmap.pcc"
                } else {}
              }
#line 945 "funmap.pcc"
#line 945 "funmap.pcc"
              
              }
              
#line 947 "funmap.pcc"
              } break;
            default: {
              L17:; 
#line 948 "funmap.pcc"
             bug ("compute_names()"); 
#line 948 "funmap.pcc"
              } break;
          }
        } else { goto L17; }
        } break;
      default: { goto L17; } break;
    }
  } else { goto L17; }
}
#line 949 "funmap.pcc"
#line 949 "funmap.pcc"

     }
   }

   // Compute vector constructor names
   {
     foreach_entry (i, vector_map)
     {
       VectorId id = (VectorId) vector_map.key(i);
       Functor  f  = vector_map.value(i);
       if (id->cons)
         functor_names[f] = id->cons->name;
     }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a report detailing the functor/variable encoding,
//  the tree grammar and the generated table size.
//
///////////////////////////////////////////////////////////////////////////////

void FunctorMap::print_report( std::ostream& log)
{
  if (var_map.size() > 0)
  {
    log << "Variable encoding:\n";
    foreach_entry (e, var_map)
    {
      log << "\tnon-terminal \"" << (Id)var_map.key(e) << "\"\t=\t"
          << var_map.value(e) << '\n';
    }
  }

  if (literal_map.size() > 0)
  {
    log << "\nFunctor encoding for literals:\n";
    foreach_entry (e, literal_map)
    {
      log << "literal " << (Literal)literal_map.key(e) << "\t=\t"
          << literal_map.value(e) << '\n';
    }
  }

  log << "\nFunctor encoding for constructors:\n";

  {
    foreach_entry (e, type_map)
    {
      Ty      t = (Ty)type_map.key(e);
      Functor f = type_map.value(e);
      log << "datatype " << t << ":\n";
      
#line 1002 "funmap.pcc"
#line 1021 "funmap.pcc"
{
  Ty _V7 = deref(t);
  if (_V7) {
    switch (_V7->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V7)->_1)) {
          switch (((Ty_TYCONty *)_V7)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 1005 "funmap.pcc"
              
              int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg;
              for (int i = 0; i < arity; i++)
              {
                
#line 1009 "funmap.pcc"
#line 1017 "funmap.pcc"
              {
                Cons _V8 = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->terms[i];
                if (_V8) {
#line 1012 "funmap.pcc"
                  
                  log << '\t' << _V8->name << "\t=\t"
                      << f + (_V8->ty == NOty ? _V8->tag : _V8->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->unit) << '\n';
                  
#line 1015 "funmap.pcc"
                } else {}
              }
#line 1017 "funmap.pcc"
#line 1017 "funmap.pcc"
              
              }
              
#line 1019 "funmap.pcc"
              } break;
            default: {
              L18:; } break;
          }
        } else { goto L18; }
        } break;
      default: { goto L18; } break;
    }
  } else { goto L18; }
}
#line 1021 "funmap.pcc"
#line 1021 "funmap.pcc"

    }
  }

  if (tree_gen)
  {
    log << "\nIndex compression is "
        << (use_compression ? "enabled" : "disabled")
        << "\nAlgorithm is " << tree_gen->algorithm();
    tree_gen->print_report(log);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to return the cost expression for a pattern.
//
///////////////////////////////////////////////////////////////////////////////

Exp FunctorMap::cost_expr( Id lhs, Pat pat)
{
  
#line 1042 "funmap.pcc"
#line 1045 "funmap.pcc"
{
  if (pat) {
#line 1045 "funmap.pcc"
   return cost_expr( lhs, pat, LITERALexp( INTlit(1))); 
#line 1045 "funmap.pcc"
  } else {
#line 1044 "funmap.pcc"
   return LITERALexp( INTlit(0)); 
#line 1044 "funmap.pcc"
  }
}
#line 1046 "funmap.pcc"
#line 1046 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a pattern
//
///////////////////////////////////////////////////////////////////////////////

Exp FunctorMap::cost_expr( Id lhs, Pat pat, Exp exp)
{
  
#line 1057 "funmap.pcc"
#line 1077 "funmap.pcc"
{
  if (pat) {
    switch (pat->tag__) {
      case a_Pat::tag_WILDpat: {} break;
      case a_Pat::tag_IDpat: {} break;
      case a_Pat::tag_APPpat: {
#line 1064 "funmap.pcc"
       return cost_expr(lhs,((Pat_APPpat *)pat)->_2,exp); 
#line 1064 "funmap.pcc"
        } break;
      case a_Pat::tag_TYPEDpat: {
#line 1062 "funmap.pcc"
       return cost_expr(lhs,((Pat_TYPEDpat *)pat)->_1,exp); 
#line 1062 "funmap.pcc"
        } break;
      case a_Pat::tag_ASpat: {
#line 1060 "funmap.pcc"
       return cost_expr(lhs,((Pat_ASpat *)pat)->_2,exp); 
#line 1060 "funmap.pcc"
        } break;
      case a_Pat::tag_CONTEXTpat: {
#line 1065 "funmap.pcc"
       return cost_expr(lhs,((Pat_CONTEXTpat *)pat)->_2,exp); 
#line 1065 "funmap.pcc"
        } break;
      case a_Pat::tag_ARRAYpat: {
#line 1068 "funmap.pcc"
       return cost_expr(lhs,((Pat_ARRAYpat *)pat)->_1,exp); 
#line 1068 "funmap.pcc"
        } break;
      case a_Pat::tag_TUPLEpat: {
#line 1066 "funmap.pcc"
       return cost_expr(lhs,((Pat_TUPLEpat *)pat)->TUPLEpat,exp); 
#line 1066 "funmap.pcc"
        } break;
      case a_Pat::tag_EXTUPLEpat: {
#line 1067 "funmap.pcc"
       return cost_expr(lhs,((Pat_EXTUPLEpat *)pat)->EXTUPLEpat,exp); 
#line 1067 "funmap.pcc"
        } break;
      case a_Pat::tag_RECORDpat: {
#line 1069 "funmap.pcc"
       return cost_expr(lhs,((Pat_RECORDpat *)pat)->_1,exp); 
#line 1069 "funmap.pcc"
        } break;
      case a_Pat::tag_LISTpat: {
#line 1071 "funmap.pcc"
       return cost_expr(lhs,((Pat_LISTpat *)pat)->head,cost_expr(lhs,((Pat_LISTpat *)pat)->tail,exp)); 
#line 1071 "funmap.pcc"
        } break;
      case a_Pat::tag_VECTORpat: {
#line 1073 "funmap.pcc"
       return cost_expr(lhs,((Pat_VECTORpat *)pat)->len,cost_expr(lhs,((Pat_VECTORpat *)pat)->array,
        cost_expr(lhs,((Pat_VECTORpat *)pat)->elements,exp))); 
#line 1074 "funmap.pcc"
        } break;
      case a_Pat::tag_GUARDpat: {
#line 1063 "funmap.pcc"
       return cost_expr(lhs,((Pat_GUARDpat *)pat)->_1,exp); 
#line 1063 "funmap.pcc"
        } break;
      case a_Pat::tag_MARKEDpat: {
#line 1061 "funmap.pcc"
       return cost_expr(lhs,((Pat_MARKEDpat *)pat)->_2,exp); 
#line 1061 "funmap.pcc"
        } break;
      case a_Pat::tag_CONSpat:
      case a_Pat::tag_LITERALpat: {
        L19:; 
#line 1059 "funmap.pcc"
       return exp; 
#line 1059 "funmap.pcc"
        } break;
      default: {
#line 1077 "funmap.pcc"
       return exp; 
#line 1077 "funmap.pcc"
        } break;
    }
  } else { goto L19; }
}
#line 1078 "funmap.pcc"
#line 1078 "funmap.pcc"


  // BUG fix: if the argument type is not a datatype or
  // not rewritable, then there is no cost to consider.

  if ( !is_datatype(pat->ty) || !is_rewritable_type(pat->ty))
     return exp;

  Ty state_rec_ty = mkptrty( mkidty( Quark( class_name,"_StateRec"),
#line 1086 "funmap.pcc"
#line 1086 "funmap.pcc"
nil_1_
#line 1086 "funmap.pcc"
#line 1086 "funmap.pcc"
));
  Exp cost_e =
     INDEXexp(
       ARROWexp(
          CASTexp( state_rec_ty,
              APPexp( ARROWexp( pat->selector, "get_state_rec"), TUPLEexp(
#line 1091 "funmap.pcc"
#line 1091 "funmap.pcc"
nil_1_
#line 1091 "funmap.pcc"
#line 1091 "funmap.pcc"
))),
              "cost"), LITERALexp( INTlit( int( var_map[lhs]))));

  return exp == NOexp ? cost_e : BINOPexp( "+", cost_e,exp);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a pattern list
//
///////////////////////////////////////////////////////////////////////////////

Exp FunctorMap::cost_expr( Id lhs, Pats pats, Exp exp)
{
  
#line 1105 "funmap.pcc"
#line 1108 "funmap.pcc"
{
  if (pats) {
#line 1108 "funmap.pcc"
   return cost_expr( lhs, pats->_1, cost_expr( lhs, pats->_2, exp)); 
#line 1108 "funmap.pcc"
  } else {
#line 1107 "funmap.pcc"
   return exp; 
#line 1107 "funmap.pcc"
  }
}
#line 1109 "funmap.pcc"
#line 1109 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a labeled pattern list
//
///////////////////////////////////////////////////////////////////////////////

Exp FunctorMap::cost_expr( Id lhs, LabPats pats, Exp exp)
{
  
#line 1120 "funmap.pcc"
#line 1123 "funmap.pcc"
{
  if (pats) {
#line 1123 "funmap.pcc"
   return cost_expr( lhs, pats->_1.pat, cost_expr( lhs, pats->_2, exp)); 
#line 1123 "funmap.pcc"
  } else {
#line 1122 "funmap.pcc"
   return exp; 
#line 1122 "funmap.pcc"
  }
}
#line 1124 "funmap.pcc"
#line 1124 "funmap.pcc"

}
#line 1126 "funmap.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 352
Number of ifs generated      = 37
Number of switches generated = 25
Number of labels             = 15
Number of gotos              = 34
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
