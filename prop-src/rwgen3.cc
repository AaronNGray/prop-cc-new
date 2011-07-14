///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "rwgen3.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "rwgen3.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the dynamic tree parser algorithm, which is
//  used to parse a tree grammar with associated reduction cost functions.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <AD/contain/bitset.h>
#include "funmap.h"
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "hashtab.h"
#include "rwgen.h"
#include "list.h"
#include "options.h"


extern Id redex_name(Ty);

///////////////////////////////////////////////////////////////////////////////
//
//  Top level method to generate a dynamic tree parser.
//  We use a simple dynamic programming algorithm.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::gen_dynamic_rewriter( FunctorMap& F)
{
  generate_state_record(F);        // generate the state record definition
  generate_accept_rules_tables(F); // generate the accept rule tables
  generate_closures(F);            // generate the closure routines
  generate_dynamic_labelers(F);    // generate the labeler functions
  generate_reducers(F);            // generate the reducer functions

  // Generate report

  if (options.generate_report)
    F.print_report(open_logfile());
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the state record.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::generate_state_record( FunctorMap& F)
{
  pr(
      "\n"
      "%^%/"
      "%^// State record for rewrite class %s"
      "%^%/"
      "%^struct %s_StateRec {\n"
      "%^  TreeTables::Cost cost[%i]; // cost for each non-terminal"
      "%^  struct { // accept rule number",
      F.class_name, F.class_name, F.nonterm_map.size()+1
    );

  foreach_entry (e, F.nonterm_rules_bits)
  {
    Id  lhs  = Id(e->k);
    int bits = int(e->v);
    pr("%^    unsigned int _%S : %i;", lhs, bits);
  }

  pr("%^  } rule;"
     "%^};\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the accept rule tables.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::generate_accept_rules_tables( FunctorMap& F)
{
  pr(
      "%^%/"
      "%^// Accept rules tables for rewrite class %s"
      "%^%/",
      F.class_name
    );

  foreach_entry (e, F.nonterm_rules)
  {
    Id         lhs   = Id(e->k);
    MatchRules rules = MatchRules(e->v);
    int max_rule     = 0;

    
#line 95 "rwgen3.pcc"
#line 102 "rwgen3.pcc"
{
  for (;;) {
    if (rules) {
#line 98 "rwgen3.pcc"
      
      if (max_rule < rules->_1->rule_number)
        max_rule = rules->_1->rule_number;
      rules = rules->_2;
      
#line 102 "rwgen3.pcc"
    } else { goto L1; }
  }
  L1:;
}
#line 103 "rwgen3.pcc"
#line 103 "rwgen3.pcc"


    Id storage_class = max_rule < 128 ? "char" : "short";

    pr ("%^const %s %s_%S_accept[] = { -1, ",
        storage_class, F.class_name, lhs);

    rules = MatchRules(e->v);
    
#line 111 "rwgen3.pcc"
#line 117 "rwgen3.pcc"
{
  for (;;) {
    if (rules) {
#line 114 "rwgen3.pcc"
      
      pr ("%i%s", rules->_1->rule_number, (rules->_2 != 
#line 115 "rwgen3.pcc"
#line 115 "rwgen3.pcc"
      nil_1_
#line 115 "rwgen3.pcc"
#line 115 "rwgen3.pcc"
     ? ", " : ""));
      rules = rules->_2;
      
#line 117 "rwgen3.pcc"
    } else { goto L2; }
  }
  L2:;
}
#line 118 "rwgen3.pcc"
#line 118 "rwgen3.pcc"

    pr (" };\n\n");
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the closure routines for each non-terminal
//  which appears the rhs of a chain rule.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::generate_closures( FunctorMap& F)
{
  pr(
      "%^%/"
      "%^// Closure methods for rewrite class %s"
      "%^%/",
      F.class_name
    );

  // Generate the headers first
  {
    foreach_entry (e, F.chain_rules)
    {
      Id         rhs   = Id(e->k);
      MatchRules rules = MatchRules(e->v);
      Ty         ty    = rules->_1->ty; // type of states.
      pr(
          "%^static void %s_%S_closure(%t,int cost);\n",
          F.class_name, rhs, ty, "redex"
        );
    }
  }

  pr("\n");

  // Then generate the definitions.
  {
    foreach_entry (e, F.chain_rules)
    {
      Id         rhs   = Id(e->k);
      MatchRules rules = MatchRules(e->v);
      gen_closure(F,rhs,rules);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the closure routine for one non-terminal.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::gen_closure( FunctorMap& F, Id rhs, MatchRules rules)
{
  Ty ty = rules->_1->ty; // type of states.

  pr(
      "%^static void %s_%S_closure(%t,int cost__)\n"
      "%^{%+"
      "%^%s_StateRec * _state_rec = (%s_StateRec *)(%s->get_state_rec());",
       F.class_name, rhs, ty, "redex", F.class_name,
       F.class_name, redex_name(ty)
    );

  int rule_no = 1;
  rules = rev(rules);
  
#line 186 "rwgen3.pcc"
#line 226 "rwgen3.pcc"
{
  for (;;) {
    if (rules) {
#line 189 "rwgen3.pcc"
      
      Exp cost_exp;
      
#line 191 "rwgen3.pcc"
#line 200 "rwgen3.pcc"
      {
        Cost _V1 = rules->_1->_4;
        if (_V1) {
          if (untagp(_V1)) {
            
#line 194 "rwgen3.pcc"
           cost_exp = LITERALexp(INTlit(((Cost_INTcost *)derefp(_V1))->INTcost)); 
#line 194 "rwgen3.pcc"
          } else {
            
#line 196 "rwgen3.pcc"
          // Avoid recomputation of cost
            Id v = vars.new_label();
            pr ("%^const int %s = %e;", v, ((Cost_EXPcost *)_V1)->_1);
            cost_exp = IDexp(v);
            
#line 200 "rwgen3.pcc"
          }
        } else {
#line 193 "rwgen3.pcc"
         cost_exp = LITERALexp(INTlit(0)); 
#line 193 "rwgen3.pcc"
        }
      }
#line 201 "rwgen3.pcc"
#line 201 "rwgen3.pcc"
      
      int nonterm_number = int(F.var_map[rules->_1->_1]);
      
      if (nonterm_number > 0)
      {
        pr(
            "%^if (cost__ + %e < _state_rec->cost[%i])"
            "%^{  _state_rec->cost[%i] = cost__ + %e;"
            "%^  _state_rec->rule._%S = %i;",
            cost_exp, nonterm_number, nonterm_number, cost_exp, rules->_1->_1, rule_no
          );
      
        // Chain rules
        if (F.chain_rules.contains(rules->_1->_1))
        {
          pr(
              "%^  %s_%S_closure(redex,cost__ + %e);",
              F.class_name, rules->_1->_1, cost_exp
            );
        }
      
        pr ("%^}");
      }
      rule_no++;
      rules = rules->_2;
      
#line 226 "rwgen3.pcc"
    } else { goto L3; }
  }
  L3:;
}
#line 227 "rwgen3.pcc"
#line 227 "rwgen3.pcc"


   pr ("%-%^}\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the dynamic labelers
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::generate_dynamic_labelers( FunctorMap& F)
{
  ////////////////////////////////////////////////////////////////////////////
  //  Generate a dynamic labeler for each datatype
  ////////////////////////////////////////////////////////////////////////////
  foreach_entry (e, F.type_map)
  {
    Ty ty = Ty(F.type_map.key(e));
    debug_msg("[Rewrite class %s: generating dynamic labeler for datatype %T\n",
               F.class_name, ty);
    gen_dynamic_datatype_labeler(F, ty);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a labeler routine for one datatype.
//
///////////////////////////////////////////////////////////////////////////////
void RewritingCompiler::gen_dynamic_datatype_labeler( FunctorMap& F, Ty ty)
{
  ///////////////////////////////////////////////////////////////////////////
  // Generate the protocol of this labeler routine
  ///////////////////////////////////////////////////////////////////////////
  pr(
      "%^void %s::labeler (%t)"
      "%^{%+"
      "%^int cost__;",
      F.class_name, ty, "redex"
    );

  ///////////////////////////////////////////////////////////////////////////
  // Name of the redex inside this routine.
  ///////////////////////////////////////////////////////////////////////////
  Id redex = redex_name(ty);

  ///////////////////////////////////////////////////////////////////////////
  //
  // Allocate and initialize a state record.
  //
  ///////////////////////////////////////////////////////////////////////////
  pr(
      "%^%s_StateRec * _state_rec = (%s_StateRec *)mem[sizeof(%s_StateRec)];"
      "%^%s->set_state_rec(_state_rec);"
      "%^_state_rec->cost[0] = 0;",
      F.class_name, F.class_name, F.class_name, redex
    );

  for ( int i = 1; i <= F.nonterm_map.size(); i++)
  {
    pr("%^_state_rec->cost[%i] = ", i);
  }

  pr( "%i;\n", TreeTables::infinite_cost);

  ///////////////////////////////////////////////////////////////////////////
  // Generate code for bottomup traversal on the datatype
  ///////////////////////////////////////////////////////////////////////////
  gen_dynamic_traversals( F, ty);

  ///////////////////////////////////////////////////////////////////////////
  // Update the state record.
  ///////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  // End of this routine
  ///////////////////////////////////////////////////////////////////////////
  pr( "%^%-%^}\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate code for dynamic traversals of one datatype.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::gen_dynamic_traversals( FunctorMap& F, Ty ty)
{
  if (!F.rule_map.contains(ty))
  {
    bug( "%Lgen_dynamic_traversals: %t\n", ty);
  }

  MatchRules rules = MatchRules( F.rule_map[ty]);
  MatchExps  exps  = 
#line 322 "rwgen3.pcc"
#line 322 "rwgen3.pcc"
list_1_(MATCHexp(IDexp("redex"),0))
#line 322 "rwgen3.pcc"
#line 322 "rwgen3.pcc"
;
  rules = rev( rules);
  gen_match_stmt( exps, rules,
     MATCHnocheck + MATCHnotrace + MATCHall + MATCHwithtreecost);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to annotate the matching tree with tree reduction cost nodes.
//  Return the set of rules that matches.  The idea is to hoist
//  the cost minimalization rules as near the root as possible.
//
///////////////////////////////////////////////////////////////////////////////

const BitSet * label_treecost( Match& m, int, MatchRules rules);
const BitSet * label_treecost( Match& m, int, MatchRules rules, Match&, Match&);
const BitSet * label_treecost( Match& m, int, MatchRules rules, int, Match[], Match&, Bool);

const BitSet * label_treecost( Match& m, int N, MatchRules rules)
{
  
#line 342 "rwgen3.pcc"
#line 356 "rwgen3.pcc"
{
  if (boxed(m)) {
    switch (m->tag__) {
      case a_Match::tag_SUCCESSmatch: {
        L4:; 
#line 344 "rwgen3.pcc"
       return 0; 
#line 344 "rwgen3.pcc"
        } break;
      case a_Match::tag_SUCCESSESmatch: {
#line 347 "rwgen3.pcc"
       return ((Match_SUCCESSESmatch *)m)->_2; 
#line 347 "rwgen3.pcc"
        } break;
      case a_Match::tag_COSTmatch: {
#line 346 "rwgen3.pcc"
       return ((Match_COSTmatch *)m)->_3; 
#line 346 "rwgen3.pcc"
        } break;
      case a_Match::tag_GUARDmatch: {
#line 349 "rwgen3.pcc"
      return label_treecost(m,N,rules,((Match_GUARDmatch *)m)->_2,((Match_GUARDmatch *)m)->_3); 
#line 349 "rwgen3.pcc"
        } break;
      case a_Match::tag_LITERALmatch: {
#line 353 "rwgen3.pcc"
      return label_treecost(m,N,rules,((Match_LITERALmatch *)m)->_4,((Match_LITERALmatch *)m)->_5,((Match_LITERALmatch *)m)->_6,false); 
#line 353 "rwgen3.pcc"
        } break;
      case a_Match::tag_RANGEmatch: {
#line 355 "rwgen3.pcc"
      return label_treecost(m,N,rules,((Match_RANGEmatch *)m)->_5,((Match_RANGEmatch *)m)->_6); 
#line 355 "rwgen3.pcc"
        } break;
      case a_Match::tag_CONSmatch: {
#line 351 "rwgen3.pcc"
      return label_treecost(m,N,rules,((Match_CONSmatch *)m)->_5,((Match_CONSmatch *)m)->_6,((Match_CONSmatch *)m)->_7,true); 
#line 351 "rwgen3.pcc"
        } break;
      case a_Match::tag_TREECOSTmatch: {
#line 345 "rwgen3.pcc"
       return ((Match_TREECOSTmatch *)m)->_2; 
#line 345 "rwgen3.pcc"
        } break;
      default: {
        L5:; 
#line 356 "rwgen3.pcc"
       bug("label_treecost: %M", m); return 0; 
#line 356 "rwgen3.pcc"
        } break;
    }
  } else {
    if (m) {
       goto L5; } else {
       goto L4; }
  }
}
#line 357 "rwgen3.pcc"
#line 357 "rwgen3.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to annotate the matching tree with tree reduction cost nodes.
//  Return the set of rules that matches.
//
///////////////////////////////////////////////////////////////////////////////

const BitSet * label_treecost( Match& m, int N, MatchRules rules, Match& a, Match& b)
{
  const BitSet * s1 = label_treecost(a,N,rules);
  const BitSet * s2 = label_treecost(b,N,rules);
  if (s1 == 0 || s2 == 0)
    return 0;
  BitSet * S = new (mem_pool, N) BitSet;
  S->Intersect(*s1,*s2);
  if (S->count() == 0)
    return 0;
  m = TREECOSTmatch(m,S,rules);
  m->label = 0; m->shared = 0;
  return S;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to annotate the matching tree with tree reduction cost nodes.
//  Return the set of rules that matches.
//
///////////////////////////////////////////////////////////////////////////////

const BitSet * label_treecost( Match& m, int N, MatchRules rules,
                              int fanout, Match a[], Match& b, Bool ignore)
{
  const BitSet * Sb = label_treecost(b,N,rules);
  BitSet * S = new (mem_pool, N) BitSet;
  Bool empty = ! ignore && Sb == 0;

  if (! ignore)
    S->copy(*Sb);
  else
    S->complement();

  for (int i = 0; i < fanout; i++)
  {
    const BitSet * Sa = label_treecost(a[i],N,rules);
    if (Sa)
    {
      if (!empty)
        S->Intersect(*Sa);
    }
    else
      empty = true;
  }

  if (empty || S->count() == 0)
    return 0;
  m = TREECOSTmatch(m,S,rules);
  debug_msg("[NEW TREE]\n");
  m->label = 0; m->shared = 0;
  return S;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to prune the matching tree with tree reduction cost nodes.
//  We reduce unnecessary cost minimalization nodes.
//
///////////////////////////////////////////////////////////////////////////////

void prune_treecost( Match& m, const BitSet * ignore)
{
  
#line 430 "rwgen3.pcc"
#line 493 "rwgen3.pcc"
{
  if (boxed(m)) {
    switch (m->tag__) {
      case a_Match::tag_SUCCESSmatch: {
        L6:; 
#line 432 "rwgen3.pcc"
       return; 
#line 432 "rwgen3.pcc"
        } break;
      case a_Match::tag_SUCCESSESmatch: {
#line 443 "rwgen3.pcc"
        
        if (ignore)
        {
          ((Match_SUCCESSESmatch *)m)->_2->Difference(*ignore);
          if (((Match_SUCCESSESmatch *)m)->_2->count() == 0)
            m = FAILmatch;
        }
        
#line 450 "rwgen3.pcc"
        } break;
      case a_Match::tag_COSTmatch: {
#line 434 "rwgen3.pcc"
        
        if (ignore)
        {
          ((Match_COSTmatch *)m)->_3->Difference(*ignore);
          if (((Match_COSTmatch *)m)->_3->count() == 0)
            m = FAILmatch;
        }
        
#line 441 "rwgen3.pcc"
        } break;
      case a_Match::tag_GUARDmatch: {
#line 471 "rwgen3.pcc"
        
        prune_treecost(((Match_GUARDmatch *)m)->_2,ignore);
        prune_treecost(((Match_GUARDmatch *)m)->_3,ignore);
        
#line 474 "rwgen3.pcc"
        } break;
      case a_Match::tag_LITERALmatch: {
#line 487 "rwgen3.pcc"
        
        for (int i = 0; i < ((Match_LITERALmatch *)m)->_4; i++)
          prune_treecost(((Match_LITERALmatch *)m)->_5[i],ignore);
        prune_treecost(((Match_LITERALmatch *)m)->_6,ignore);
        
#line 491 "rwgen3.pcc"
        } break;
      case a_Match::tag_RANGEmatch: {
#line 476 "rwgen3.pcc"
        
        prune_treecost(((Match_RANGEmatch *)m)->_5,ignore);
        prune_treecost(((Match_RANGEmatch *)m)->_6,ignore);
        
#line 479 "rwgen3.pcc"
        } break;
      case a_Match::tag_CONSmatch: {
#line 481 "rwgen3.pcc"
        
        for (int i = 0; i < ((Match_CONSmatch *)m)->_5; i++)
          prune_treecost(((Match_CONSmatch *)m)->_6[i],ignore);
        prune_treecost(((Match_CONSmatch *)m)->_7,ignore);
        
#line 485 "rwgen3.pcc"
        } break;
      case a_Match::tag_TREECOSTmatch: {
#line 452 "rwgen3.pcc"
        
        BitSet * new_ignore;
        if (ignore)
        {
          new_ignore = new (mem_pool, ignore->size()) BitSet;
          new_ignore->Union(*((Match_TREECOSTmatch *)m)->_2);
        }
        else
          new_ignore = ((Match_TREECOSTmatch *)m)->_2;
        
        prune_treecost(((Match_TREECOSTmatch *)m)->_1,new_ignore);
        
        if (ignore)
        {
          ((Match_TREECOSTmatch *)m)->_2->Difference(*ignore);
          if (((Match_TREECOSTmatch *)m)->_2->count() == 0) m = ((Match_TREECOSTmatch *)m)->_1;
        }
        
#line 469 "rwgen3.pcc"
        } break;
      default: {
        L7:; 
#line 493 "rwgen3.pcc"
       bug("prune_treecost: %M", m); 
#line 493 "rwgen3.pcc"
        } break;
    }
  } else {
    if (m) {
       goto L7; } else {
       goto L6; }
  }
}
#line 494 "rwgen3.pcc"
#line 494 "rwgen3.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to insert traversal code
//
///////////////////////////////////////////////////////////////////////////////

void add_traversal( Match& m)
{
  
#line 505 "rwgen3.pcc"
#line 515 "rwgen3.pcc"
{
  if (boxed(m)) {
    switch (m->tag__) {
      case a_Match::tag_CONSmatch: {
#line 508 "rwgen3.pcc"
        
        for (int i = 0; i < ((Match_CONSmatch *)m)->_5; i++)
          ((Match_CONSmatch *)m)->_6[i] = TREELABELmatch(((Match_CONSmatch *)m)->_6[i],((Match_CONSmatch *)m)->_3,((Match_CONSmatch *)m)->_4,i);
        
#line 511 "rwgen3.pcc"
        } break;
      case a_Match::tag_TREECOSTmatch: {
#line 513 "rwgen3.pcc"
       add_traversal(((Match_TREECOSTmatch *)m)->_1); 
#line 513 "rwgen3.pcc"
        } break;
      default: {
        L8:; 
#line 515 "rwgen3.pcc"
       bug ("add_traversal: %M", m); 
#line 515 "rwgen3.pcc"
        } break;
    }
  } else { goto L8; }
}
#line 516 "rwgen3.pcc"
#line 516 "rwgen3.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to translate the matching tree into a tree with
//  tree reduction cost nodes.
//
///////////////////////////////////////////////////////////////////////////////

Match translate_treecost( Match m, MatchRules rules)
{
  debug_msg( "%Ltranslating rules into treecost\n");
  label_treecost( m, length( rules), rules);
  prune_treecost( m, 0);
  add_traversal( m);
  return m;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Return the encoded rule number.
//
///////////////////////////////////////////////////////////////////////////////

static int rule_of( FunctorMap *Fmap, Id lhs, int r)
{
  int rule_no = 1;
  MatchRules rules = MatchRules( Fmap->nonterm_rules[lhs]);
  
#line 545 "rwgen3.pcc"
#line 553 "rwgen3.pcc"
{
  for (;;) {
    if (rules) {
#line 548 "rwgen3.pcc"
      
      if (rules->_1->rule_number == r)
        return rule_no;
      rules = rules->_2;
      rule_no++;
      
#line 553 "rwgen3.pcc"
    } else { goto L9; }
  }
  L9:;
}
#line 554 "rwgen3.pcc"
#line 554 "rwgen3.pcc"

  bug( "rule_of");
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method for generating labeling code for pattern parsing.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::gen_treelabel_match( Match m, Ty ty, Ty alg_ty, int k)
{  // Generate traversal code
  
#line 567 "rwgen3.pcc"
#line 604 "rwgen3.pcc"
{
  Ty _V2 = deref_all(ty);
  if (alg_ty) {
    switch (alg_ty->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)alg_ty)->_1)) {
          switch (((Ty_TYCONty *)alg_ty)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
              if (_V2) {
                switch (_V2->tag__) {
                  case a_Ty::tag_TYCONty: {
#line 570 "rwgen3.pcc"
                    
                    Cons cons = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)alg_ty)->_1)->terms[k];
                    Ty arg_ty = apply_ty(cons->cons_ty,((Ty_TYCONty *)_V2)->_2);
                    Exp e     = select(IDexp("redex"),cons);
                    	  if (cons->ty == NOty)
                    {
                      error("%Ltree parsing mode cannot be used on datatype with unit constructors: %T\n", alg_ty);
                    }
                    
                    
#line 579 "rwgen3.pcc"
#line 600 "rwgen3.pcc"
                    {
                      if (arg_ty) {
                        switch (arg_ty->tag__) {
                          case a_Ty::tag_TYCONty: {
                            if (boxed(((Ty_TYCONty *)arg_ty)->_1)) {
                              switch (((Ty_TYCONty *)arg_ty)->_1->tag__) {
                                case a_TyCon::tag_RECORDtycon: {
#line 592 "rwgen3.pcc"
                                  
                                  Ids ids; Tys xtys = ((Ty_TYCONty *)_V2)->_2 = ((Ty_TYCONty *)arg_ty)->_2;
                                  for (ids = ((TyCon_RECORDtycon *)((Ty_TYCONty *)arg_ty)->_1)->_1; ids && ((Ty_TYCONty *)arg_ty)->_2; ids = ids->_2, ((Ty_TYCONty *)_V2)->_2 = ((Ty_TYCONty *)_V2)->_2->_2)
                                  {
                                    if (Fmap->is_rewritable_type(((Ty_TYCONty *)_V2)->_2->_1))
                                      pr( "%^labeler(%e);", DOTexp(e,ids->_1));
                                  }
                                  
#line 599 "rwgen3.pcc"
                                  } break;
                                default: {
                                  L10:; 
#line 600 "rwgen3.pcc"
                                 if (Fmap->is_rewritable_type(arg_ty)) pr("%^labeler(%e);",e); 
#line 600 "rwgen3.pcc"
                                  } break;
                              }
                            } else {
                              switch ((int)((Ty_TYCONty *)arg_ty)->_1) {
                                case ((int)v_TUPLEtycon): {
#line 583 "rwgen3.pcc"
                                  
                                  int i = 1;
                                  for_each(Ty, t, ((Ty_TYCONty *)arg_ty)->_2)
                                  {
                                    if (Fmap->is_rewritable_type(t))
                                      pr("%^labeler(%e);", DOTexp(e,index_of(i))); i++;
                                  }
                                  
#line 590 "rwgen3.pcc"
                                  } break;
                                default: { goto L10; } break;
                              }
                            }
                            } break;
                          default: { goto L10; } break;
                        }
                      } else {}
                    }
#line 601 "rwgen3.pcc"
#line 601 "rwgen3.pcc"
                    
                    
#line 602 "rwgen3.pcc"
                    } break;
                  default: {
                    L11:; 
#line 604 "rwgen3.pcc"
                   bug( "RewritingCompiler::gen_treelabel_match"); 
#line 604 "rwgen3.pcc"
                    } break;
                }
              } else { goto L11; }
              } break;
            default: { goto L11; } break;
          }
        } else { goto L11; }
        } break;
      default: { goto L11; } break;
    }
  } else { goto L11; }
}
#line 605 "rwgen3.pcc"
#line 605 "rwgen3.pcc"


  // Generate labeling code
  gen( m);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method for generating treecost minimalization code from a pattern
//  matching tree.
//
///////////////////////////////////////////////////////////////////////////////

void RewritingCompiler::gen_treecost_match( Match m, const BitSet * set,
                                            MatchRules rules)
{
  gen(m);
  int rule_no = 0;
  
#line 623 "rwgen3.pcc"
#line 661 "rwgen3.pcc"
{
  for (;;) {
    if (rules) {
#line 626 "rwgen3.pcc"
      
      if (set->contains(rule_no))
      {
        if (rules->_1->_1)
        {
          pr ("%^// %r\n", rules->_1);
          Exp cost_exp;
          
#line 633 "rwgen3.pcc"
#line 641 "rwgen3.pcc"
      {
        Cost _V3 = rules->_1->_4;
        if (_V3) {
          if (untagp(_V3)) {
            
#line 636 "rwgen3.pcc"
           cost_exp = LITERALexp(INTlit(((Cost_INTcost *)derefp(_V3))->INTcost)); 
#line 636 "rwgen3.pcc"
          } else {
            
#line 638 "rwgen3.pcc"
            
            cost_exp = IDexp(vars.new_label());
            pr("%^int %e = %e;",cost_exp,((Cost_EXPcost *)_V3)->_1);
            
#line 641 "rwgen3.pcc"
          }
        } else {
#line 635 "rwgen3.pcc"
         cost_exp = LITERALexp(INTlit(0)); 
#line 635 "rwgen3.pcc"
        }
      }
#line 642 "rwgen3.pcc"
#line 642 "rwgen3.pcc"
      
      int nonterm_number = int(Fmap->var_map[rules->_1->_1]);
      pr(
          "%^cost__ = %e + %e;"
          "%^if (cost__ < _state_rec->cost[%i])"
          "%^{   _state_rec->cost[%i] = cost__;"
          "%^    _state_rec->rule._%S = %i;",
          cost_exp, Fmap->cost_expr(rules->_1->_1,rules->_1->_2),
          nonterm_number, nonterm_number,
          rules->_1->_1, rule_of(Fmap,rules->_1->_1,rules->_1->rule_number)
        );
      
      if (Fmap->chain_rules.contains(rules->_1->_1))
        pr( "%^  %s_%S_closure(redex, cost__);",
            Fmap->class_name, rules->_1->_1);
      pr( "%^}");
      }
      }
      rules = rules->_2; rule_no++;
      
#line 661 "rwgen3.pcc"
    } else { goto L12; }
  }
  L12:;
}
#line 662 "rwgen3.pcc"
#line 662 "rwgen3.pcc"

}
#line 664 "rwgen3.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 77
Number of ifs generated      = 19
Number of switches generated = 9
Number of labels             = 7
Number of gotos              = 12
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
