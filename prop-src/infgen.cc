///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "infgen.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_STRCMP_USED
#include <propdefs.h>
#line 1 "infgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the inference rules compiler of Prop.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <AD/memory/mempool.h>
#include <AD/generic/ordering.h>
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "hashtab.h"
#include "config.h"
#include "infgen.h"
#include "datagen.h"
#include "datatype.h"
#include "list.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor for the inference compiler
//
///////////////////////////////////////////////////////////////////////////////

InferenceCompiler:: InferenceCompiler() {}
InferenceCompiler::~InferenceCompiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Import some type definitions.
//
///////////////////////////////////////////////////////////////////////////////

typedef HashTable::Key   Key;
typedef HashTable::Value Value;

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create an inference class.
//
///////////////////////////////////////////////////////////////////////////////

InferenceClass::InferenceClass(Id id, Inherits i, TyQual qual, Decls body)
  : ClassDefinition( INFERENCE_CLASS, id, 
#line 46 "infgen.pcc"
#line 46 "infgen.pcc"
nil_1_
#line 46 "infgen.pcc"
#line 46 "infgen.pcc"
, add_inherit( "Rete", 
#line 46 "infgen.pcc"
#line 46 "infgen.pcc"
nil_1_
#line 46 "infgen.pcc"
#line 46 "infgen.pcc"
, i), qual, body)
  {}

InferenceClass::~InferenceClass() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the interface for an inference class.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceClass::gen_class_interface( CodeGen& C)
{
  C.pr(
        "%^%s(const %s&);"
        "%^void operator = (const %s&);%-"
        "%^public:%+"
        "%^static const Node          network_table[];"
        "%^static const RelationTable relation_table[];%-"
        "%^public:%+"
        "%^%s();"
        "%^virtual const char * name_of() const;"
        "%^void initialise_axioms();%-"
        "%^protected:%+"
        "%^virtual void alpha_test (int, int, Fact *);"
        "%^virtual int  beta_test  (Join, Fact * []);"
        "%^virtual void action     (RuleId, Fact * []);%-"
        "%^private:%+",
        class_name, class_name, class_name, class_name
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Forward declarations.
//
///////////////////////////////////////////////////////////////////////////////

Bool partition( Exp e1, Exp e2, int &obj);
Bool partition( Exps exp, int &obj);
Bool partition( LabExps exp, int &obj);
int  partition_inference_rules
        (int n, InferenceRule Rs[], HashTable& rule_map, HashTable& join_map);

///////////////////////////////////////////////////////////////////////////////
//
//  Flatten an expression into conjuncts.  Also try to push down negation
//  as much as possible.  Notice that C++ short circuited ands and ors are not
//  commutative (but they are associative.)
//
///////////////////////////////////////////////////////////////////////////////

Exp * flatten( Exp exp, Exp * cnf, Bool neg)
{
  
#line 100 "infgen.pcc"
#line 113 "infgen.pcc"
{
  for (;;) {
    if (exp) {
      switch (exp->tag__) {
        case a_Exp::tag_BINOPexp: {
          if (
#line 112 "infgen.pcc"
          neg
#line 112 "infgen.pcc"
) {
            
            if (_less_string(((Exp_BINOPexp *)exp)->_1,"==")) {
              if (_equal_string(((Exp_BINOPexp *)exp)->_1,"!=")) {
              if (
#line 111 "infgen.pcc"
              neg
#line 111 "infgen.pcc"
) {
                
                L2:; 
#line 111 "infgen.pcc"
               *cnf = BINOPexp("==",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3); return cnf+1;
#line 111 "infgen.pcc"
              } else {
                
                L3:; 
#line 112 "infgen.pcc"
               *cnf = PREFIXexp("!",exp); return cnf+1;
#line 112 "infgen.pcc"
              }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"&&")) {
              if (
#line 104 "infgen.pcc"
              (! neg)
#line 104 "infgen.pcc"
) {
                
                L4:; 
#line 104 "infgen.pcc"
               cnf = flatten(((Exp_BINOPexp *)exp)->_2,cnf,neg); exp = ((Exp_BINOPexp *)exp)->_3; 
#line 104 "infgen.pcc"
              } else {
                 goto L3; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"<")) {
              if (
#line 108 "infgen.pcc"
              neg
#line 108 "infgen.pcc"
) {
                
                L5:; 
#line 108 "infgen.pcc"
               *cnf = BINOPexp(">=",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3); return cnf+1;
#line 108 "infgen.pcc"
              } else {
                 goto L3; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"<=")) {
              if (
#line 109 "infgen.pcc"
              neg
#line 109 "infgen.pcc"
) {
                
                L6:; 
#line 109 "infgen.pcc"
               *cnf = BINOPexp(">",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3);  return cnf+1;
#line 109 "infgen.pcc"
              } else {
                 goto L3; }
}
              else { goto L3; }
            } else {
              if (_equal_string(((Exp_BINOPexp *)exp)->_1,"==")) {
              if (
#line 110 "infgen.pcc"
              neg
#line 110 "infgen.pcc"
) {
                
                L7:; 
#line 110 "infgen.pcc"
               *cnf = BINOPexp("!=",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3); return cnf+1;
#line 110 "infgen.pcc"
              } else {
                 goto L3; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,">")) {
              if (
#line 106 "infgen.pcc"
              neg
#line 106 "infgen.pcc"
) {
                
                L8:; 
#line 106 "infgen.pcc"
               *cnf = BINOPexp("<=",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3); return cnf+1;
#line 106 "infgen.pcc"
              } else {
                 goto L3; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,">=")) {
              if (
#line 107 "infgen.pcc"
              neg
#line 107 "infgen.pcc"
) {
                
                L9:; 
#line 107 "infgen.pcc"
               *cnf = BINOPexp("<",((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3);  return cnf+1;
#line 107 "infgen.pcc"
              } else {
                 goto L3; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"||")) {
              if (
#line 105 "infgen.pcc"
              neg
#line 105 "infgen.pcc"
) {
                
                L10:; 
#line 105 "infgen.pcc"
               cnf = flatten(((Exp_BINOPexp *)exp)->_2,cnf,neg); exp = ((Exp_BINOPexp *)exp)->_3; 
#line 105 "infgen.pcc"
              } else {
                 goto L3; }
}
              else { goto L3; }
            }
          } else {
            
            if (_less_string(((Exp_BINOPexp *)exp)->_1,"==")) {
              if (_equal_string(((Exp_BINOPexp *)exp)->_1,"!=")) {
              if (
#line 111 "infgen.pcc"
              neg
#line 111 "infgen.pcc"
) {
                 goto L2; } else {
                
                L11:; 
#line 113 "infgen.pcc"
               *cnf = exp; return cnf+1; 
#line 113 "infgen.pcc"
              }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"&&")) {
              if (
#line 104 "infgen.pcc"
              (! neg)
#line 104 "infgen.pcc"
) {
                 goto L4; } else {
                 goto L11; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"<")) {
              if (
#line 108 "infgen.pcc"
              neg
#line 108 "infgen.pcc"
) {
                 goto L5; } else {
                 goto L11; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"<=")) {
              if (
#line 109 "infgen.pcc"
              neg
#line 109 "infgen.pcc"
) {
                 goto L6; } else {
                 goto L11; }
}
              else { goto L11; }
            } else {
              if (_equal_string(((Exp_BINOPexp *)exp)->_1,"==")) {
              if (
#line 110 "infgen.pcc"
              neg
#line 110 "infgen.pcc"
) {
                 goto L7; } else {
                 goto L11; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,">")) {
              if (
#line 106 "infgen.pcc"
              neg
#line 106 "infgen.pcc"
) {
                 goto L8; } else {
                 goto L11; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,">=")) {
              if (
#line 107 "infgen.pcc"
              neg
#line 107 "infgen.pcc"
) {
                 goto L9; } else {
                 goto L11; }
}
              else if (_equal_string(((Exp_BINOPexp *)exp)->_1,"||")) {
              if (
#line 105 "infgen.pcc"
              neg
#line 105 "infgen.pcc"
) {
                 goto L10; } else {
                 goto L11; }
}
              else { goto L11; }
            }
          }
          } break;
        case a_Exp::tag_PREFIXexp: {
          if (
#line 112 "infgen.pcc"
          neg
#line 112 "infgen.pcc"
) {
            
            if (_equal_string(((Exp_PREFIXexp *)exp)->_1,"!")) {
            L12:; 
#line 103 "infgen.pcc"
           exp = ((Exp_PREFIXexp *)exp)->_2; neg = !neg; 
#line 103 "infgen.pcc"
}
            else { goto L3; }
          } else {
            
            if (_equal_string(((Exp_PREFIXexp *)exp)->_1,"!")) { goto L12; }
            else { goto L11; }
          }
          } break;
        case a_Exp::tag_MARKEDexp: {
#line 102 "infgen.pcc"
         exp = ((Exp_MARKEDexp *)exp)->_2; 
#line 102 "infgen.pcc"
          } break;
        default: {
          L13:; 
          if (
#line 112 "infgen.pcc"
          neg
#line 112 "infgen.pcc"
) {
             goto L3; } else {
             goto L11; }
          } break;
      }
    } else { goto L13; }
  }
}
#line 114 "infgen.pcc"
#line 114 "infgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Returns true if an expression involves only one object.
//  Also returns the highest numbered object involved.
//  As a convention, the object number is -1 if the expression is a constant.
//
///////////////////////////////////////////////////////////////////////////////

Bool partition( Exp exp, int &obj)
{
  
#line 127 "infgen.pcc"
#line 155 "infgen.pcc"
{
  if (exp) {
    switch (exp->tag__) {
      case a_Exp::tag_RELexp: {
#line 139 "infgen.pcc"
       obj = ((Exp_RELexp *)exp)->RELexp; return true; 
#line 139 "infgen.pcc"
        } break;
      case a_Exp::tag_DOTexp: {
#line 134 "infgen.pcc"
       return partition(((Exp_DOTexp *)exp)->_1,obj); 
#line 134 "infgen.pcc"
        } break;
      case a_Exp::tag_SELECTORexp: {
#line 133 "infgen.pcc"
       return partition(((Exp_SELECTORexp *)exp)->_1,obj); 
#line 133 "infgen.pcc"
        } break;
      case a_Exp::tag_DEREFexp: {
#line 132 "infgen.pcc"
       return partition(((Exp_DEREFexp *)exp)->DEREFexp,obj); 
#line 132 "infgen.pcc"
        } break;
      case a_Exp::tag_ARROWexp: {
#line 135 "infgen.pcc"
       return partition(((Exp_ARROWexp *)exp)->_1,obj); 
#line 135 "infgen.pcc"
        } break;
      case a_Exp::tag_INDEXexp: {
#line 141 "infgen.pcc"
       return partition(((Exp_INDEXexp *)exp)->_1,((Exp_INDEXexp *)exp)->_2,obj); 
#line 141 "infgen.pcc"
        } break;
      case a_Exp::tag_BINOPexp: {
#line 143 "infgen.pcc"
       return partition(((Exp_BINOPexp *)exp)->_2,((Exp_BINOPexp *)exp)->_3,obj); 
#line 143 "infgen.pcc"
        } break;
      case a_Exp::tag_PREFIXexp: {
#line 130 "infgen.pcc"
       return partition(((Exp_PREFIXexp *)exp)->_2,obj); 
#line 130 "infgen.pcc"
        } break;
      case a_Exp::tag_POSTFIXexp: {
#line 131 "infgen.pcc"
       return partition(((Exp_POSTFIXexp *)exp)->_2,obj); 
#line 131 "infgen.pcc"
        } break;
      case a_Exp::tag_APPexp: {
#line 140 "infgen.pcc"
       return partition(((Exp_APPexp *)exp)->_1,((Exp_APPexp *)exp)->_2,obj); 
#line 140 "infgen.pcc"
        } break;
      case a_Exp::tag_ASSIGNexp: {
#line 142 "infgen.pcc"
       return partition(((Exp_ASSIGNexp *)exp)->_1,((Exp_ASSIGNexp *)exp)->_2,obj); 
#line 142 "infgen.pcc"
        } break;
      case a_Exp::tag_IFexp: {
#line 153 "infgen.pcc"
       return partition(
#line 153 "infgen.pcc"
#line 153 "infgen.pcc"
        list_1_(((Exp_IFexp *)exp)->_1,list_1_(((Exp_IFexp *)exp)->_2,list_1_(((Exp_IFexp *)exp)->_3)))
#line 153 "infgen.pcc"
#line 153 "infgen.pcc"
        ,obj); 
#line 153 "infgen.pcc"
        } break;
      case a_Exp::tag_TUPLEexp: {
#line 147 "infgen.pcc"
       return partition(((Exp_TUPLEexp *)exp)->TUPLEexp,obj); 
#line 147 "infgen.pcc"
        } break;
      case a_Exp::tag_RECORDexp: {
#line 148 "infgen.pcc"
       return partition(((Exp_RECORDexp *)exp)->RECORDexp,obj); 
#line 148 "infgen.pcc"
        } break;
      case a_Exp::tag_LISTexp: {
#line 151 "infgen.pcc"
       return partition(
#line 151 "infgen.pcc"
#line 151 "infgen.pcc"
        list_1_(((Exp_LISTexp *)exp)->_4,((Exp_LISTexp *)exp)->_3)
#line 151 "infgen.pcc"
#line 151 "infgen.pcc"
        , obj); 
#line 151 "infgen.pcc"
        } break;
      case a_Exp::tag_VECTORexp: {
#line 150 "infgen.pcc"
       return partition(((Exp_VECTORexp *)exp)->_2,obj); 
#line 150 "infgen.pcc"
        } break;
      case a_Exp::tag_CONSexp: {
#line 136 "infgen.pcc"
       return partition(((Exp_CONSexp *)exp)->_3,obj); 
#line 136 "infgen.pcc"
        } break;
      case a_Exp::tag_CASTexp: {
#line 138 "infgen.pcc"
       return partition(((Exp_CASTexp *)exp)->_2,obj); 
#line 138 "infgen.pcc"
        } break;
      case a_Exp::tag_EQexp: {
#line 144 "infgen.pcc"
       return partition(((Exp_EQexp *)exp)->_2,((Exp_EQexp *)exp)->_3,obj); 
#line 144 "infgen.pcc"
        } break;
      case a_Exp::tag_UNIFYexp: {
#line 145 "infgen.pcc"
       return partition(((Exp_UNIFYexp *)exp)->_2,((Exp_UNIFYexp *)exp)->_3,obj); 
#line 145 "infgen.pcc"
        } break;
      case a_Exp::tag_LTexp: {
#line 146 "infgen.pcc"
       return partition(((Exp_LTexp *)exp)->_2,((Exp_LTexp *)exp)->_3,obj); 
#line 146 "infgen.pcc"
        } break;
      case a_Exp::tag_HASHexp: {
#line 137 "infgen.pcc"
       return partition(((Exp_HASHexp *)exp)->_2,obj); 
#line 137 "infgen.pcc"
        } break;
      case a_Exp::tag_SENDexp: {
#line 149 "infgen.pcc"
       return partition(((Exp_SENDexp *)exp)->_2,obj); 
#line 149 "infgen.pcc"
        } break;
      case a_Exp::tag_SETLexp: {
#line 152 "infgen.pcc"
       return partition(((Exp_SETLexp *)exp)->_2,obj); 
#line 152 "infgen.pcc"
        } break;
      case a_Exp::tag_MARKEDexp: {
#line 129 "infgen.pcc"
       return partition(((Exp_MARKEDexp *)exp)->_2,obj); 
#line 129 "infgen.pcc"
        } break;
      case a_Exp::tag_LITERALexp:
      case a_Exp::tag_IDexp: {
        L14:; 
#line 154 "infgen.pcc"
       obj = -1; return true; 
#line 154 "infgen.pcc"
        } break;
      default: {
#line 155 "infgen.pcc"
       bug("partition: %e", exp); return false; 
#line 155 "infgen.pcc"
        } break;
    }
  } else { goto L14; }
}
#line 156 "infgen.pcc"
#line 156 "infgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Categorize two expressions.
//
///////////////////////////////////////////////////////////////////////////////

Bool partition( Exp e1, Exp e2, int &obj) { return partition(
#line 165 "infgen.pcc"
#line 165 "infgen.pcc"
list_1_(e1,list_1_(e2))
#line 165 "infgen.pcc"
#line 165 "infgen.pcc"
,obj); }

///////////////////////////////////////////////////////////////////////////////
//
//  Categorize an list of expressions.
//
///////////////////////////////////////////////////////////////////////////////

Bool partition( Exps es, int &obj)
{
  obj = -1;
  Bool single = true;
  for_each(Exp, e, es)
  {
    int obj1 = -1;
    if ( !partition( e, obj1) || (obj >= 0 && obj1 >= 0 && obj1 != obj))
      single = false;
    if (obj1 > obj)
      obj = obj1;
  }
  return single;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Categorize an labeled list of expressions.
//
///////////////////////////////////////////////////////////////////////////////

Bool partition( LabExps es, int &obj)
{
  obj = -1;
  Bool single = true;
  for_each(LabExp, e, es)
  {
    int obj1 = -1;
    if (! partition(e.exp,obj1) || (obj >= 0 && obj1 >= 0 && obj1 != obj))
      single = false;
    if (obj1 > obj) obj = obj1;
  }
  return single;
}

///////////////////////////////////////////////////////////////////////////////
//  Create an and expression.
///////////////////////////////////////////////////////////////////////////////

Exp mkandexp( Exp a, Exp b)
{
  if (a == NOexp)
    return b;
  if (b == NOexp)
    return a;
  return BINOPexp("&&",a, b);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decompose guard expressions in conjunctive normal form into
//  selections and (theta) joins.
//
//  We are given $n$ objects and $n$ booleans expressions.
//  We want to decompose these $n$ expressions into (at most)
//  $n$ single object selects and (at most) $n$ joins.
//
///////////////////////////////////////////////////////////////////////////////

int decompose( int n, Exp exps[], Exp selects[], Exp joins[])
{
  int i;
  int max_object = 0;
  for (i = 0; i < n; i++)
    selects[i] = joins[i] = NOexp;
  for (i = 0; i < n; i++)
  {
    debug_msg ("decomposing: %e\n", exps[i]);
    Exp cnf[MAX_CONJUNCTS];  // assume we don't have more than 256 conjuncts.
    Exp * last = flatten( exps[i], cnf, false); // flatten expression.
    int conjuncts = last - cnf;
    if (conjuncts > MAX_CONJUNCTS)
       bug ("Conjuncts exceeded %i in decompose()", MAX_CONJUNCTS);
    for (int j = 0; j < conjuncts; j++)
    {
      int obj;
      //////////////////////////////////////////////////////////////////////
      // Checks whether the conjunct depends on only one variable.
      // If so it can be executed as a guard during pattern matching.
      // Otherwise, it is a join and must be executed by the
      // RETE engine.  In any case hoist the conjunct as far up as possible
      // to minimize the sizes of intermediate relations.
      //////////////////////////////////////////////////////////////////////

      debug_msg ("partitioning: %e\n", cnf[j]);
      Bool depends_on_one_variable = partition( cnf[j], obj);
      if (obj < 0) obj = 0;
      if (depends_on_one_variable)
      { // expression is a select
        if (selects[obj] == NOexp)
          selects[obj] = cnf[j];
        else
          selects[obj] = mkandexp( selects[obj], cnf[j]);
        debug_msg ("select: %e\n", cnf[j]);
      }
      else
      { // expression is a join
        if (joins[obj] == NOexp)
          joins[obj] = cnf[j];
        else
          joins[obj] = mkandexp( joins[obj], cnf[j]);
        debug_msg ("join: %e\n", cnf[j]);
      }
      if (obj > max_object)
        max_object = obj;
    }
  }
  return max_object;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decompose a set of pattern matching rules and extract out the joins
//  from each of the guards.
//
///////////////////////////////////////////////////////////////////////////////

int decompose( MatchRules rules, Exp joins[], Exp guard_exp)
{
  Exp guards  [MAX_INFERENCE_RULE_ARITY];
  Exp selects [MAX_INFERENCE_RULE_ARITY];
  int n = 0;

  {
    for_each (MatchRule, r, rules)
    {
      
#line 299 "infgen.pcc"
#line 300 "infgen.pcc"
{
#line 300 "infgen.pcc"
 guards[n++] = r->_3; 
#line 300 "infgen.pcc"
}
#line 300 "infgen.pcc"
#line 300 "infgen.pcc"

    }
  }
  guards[n++] = guard_exp;

  if (n >= MAX_INFERENCE_RULE_ARITY)
    bug( "%Linference rule arity exceeds %i in decompose()",
         MAX_INFERENCE_RULE_ARITY);

  // take all the guard expressions and decompose them.
  int max_object = decompose( n, guards, selects, joins);

  // rebuild the guards.  Now they must all involve at most one
  // single object.

  {
    int i = 0;
    for_each (MatchRule, r, rules)
    {
      
#line 319 "infgen.pcc"
#line 320 "infgen.pcc"
{
#line 320 "infgen.pcc"
 r->_3 = selects[i]; i++; 
#line 320 "infgen.pcc"
}
#line 320 "infgen.pcc"
#line 320 "infgen.pcc"

    }
  }

  return n;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Top level method to compile a set of inference rules.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_inference_rules( Id id, InferenceRules rules)
{
  MemPoolMark marker = mem_pool.getMark(); // get heap marker

  ////////////////////////////////////////////////////////////////////////////
  // Mapping from type id to list of rules.
  ////////////////////////////////////////////////////////////////////////////
  HashTable rule_map( string_hash, string_equal, 129);
  HashTable join_map( integer_hash, integer_equal);

  ////////////////////////////////////////////////////////////////////////////
  // Map the rules into an array
  ////////////////////////////////////////////////////////////////////////////
  int n = length(rules);
  int max_arity;
  InferenceRule * Rs = (InferenceRule *) mem_pool[n * sizeof( InferenceRule)];
  { int i = 0; for_each (InferenceRule, r, rules) Rs[i++] = r; }

  max_arity = partition_inference_rules( n, Rs, rule_map, join_map);
  pr( "const char * %s::name_of() const { return \"%s\"; }\n\n", id, id);
  gen_alpha_tests           ( id, max_arity, rule_map);
  gen_beta_tests            ( id, n, Rs, join_map);
  gen_inference_actions     ( id, rules);
  gen_dispatch_table        ( id, rule_map);
  int m = gen_network_table ( id, n, Rs, join_map);
  gen_inference_axioms      ( id, rules);
  gen_inference_constructor ( id, m, rule_map);

  ////////////////////////////////////////////////////////////////////////////
  //  Clean up
  ////////////////////////////////////////////////////////////////////////////

  mem_pool.setMark(marker); // reclaim memory
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to partition the left hand side of each inference rule according
//  to the type of the pattern.  Patterns of the same type are grouped
//  together and compiled using the pattern matching compiler.  The steps are:
//    (a) Decompose the guard expression into selections (predicates on a
//        single object object) and joins (predicates on 2 or more objects.)
//        Both of these are hoisted upward as much as possible.
//    (b) Perform type inference on the pattern.
//    (c) Enter all the rules of the same type in the same entry of the rule
//        map
//
///////////////////////////////////////////////////////////////////////////////

int partition_inference_rules
   (int n, InferenceRule Rs[], HashTable& rule_map, HashTable& join_map)
{
  int max_arity = 0;
  int node_number = 0;  // node number in network table.
  for (int rule_no = 0; rule_no < n; rule_no++)
  {
    int positive_clauses = 0;
    int negative_clauses = 0;
    
#line 391 "infgen.pcc"
#line 452 "infgen.pcc"
{
  InferenceRule _V1 = Rs[rule_no];
#line 394 "infgen.pcc"
  
  int object_count = 0;
  Exp joins[MAX_INFERENCE_RULE_ARITY];
  // decompose multi-object test
  int n = decompose (_V1->_1, joins, _V1->_2);
  int i = 0;
  for_each (MatchRule, r, _V1->_1)
  {
    r->set_loc();
    
#line 403 "infgen.pcc"
#line 444 "infgen.pcc"
  {
#line 406 "infgen.pcc"
    
    
#line 407 "infgen.pcc"
#line 442 "infgen.pcc"
    {
      Ty _V2 = (r->ty = type_of(r->_2));
      if (_V2) {
        switch (_V2->tag__) {
          case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V2)->_1)) {
              switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                case a_TyCon::tag_DATATYPEtycon: {
                  if (
#line 410 "infgen.pcc"
                  (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->qualifiers & QUALrelation)
#line 410 "infgen.pcc"
) {
                    
#line 411 "infgen.pcc"
                  // add to table
                    HashTable::Entry * e = rule_map.lookup(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id);
                    if (e) rule_map.insert( ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id, 
#line 413 "infgen.pcc"
#line 413 "infgen.pcc"
                    list_1_(r,MatchRules(rule_map.value(e)))
#line 413 "infgen.pcc"
#line 413 "infgen.pcc"
                    );
                    else rule_map.insert( ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id, 
#line 414 "infgen.pcc"
#line 414 "infgen.pcc"
                    list_1_(r)
#line 414 "infgen.pcc"
#line 414 "infgen.pcc"
                    );
                    r->rule_number = node_number;
                    if (joins[i] != NOexp)
                    {
                      HashTable::Entry * e =
                        join_map.lookup( (HashTable::Key) node_number);
                      if (e)
                      {
                        join_map.insert( (HashTable::Key) node_number,
                           BINOPexp( "&&", (Exp) join_map.value(e), joins[i]));
                      }
                      else
                        join_map.insert( (HashTable::Key) node_number, joins[i]);
                    }
                    if (positive_clauses == 0 && !r->negated)
                      r->_5 = 
#line 429 "infgen.pcc"
#line 429 "infgen.pcc"
                    list_1_(INJECTdecl(node_number,LEFTdirection))
#line 429 "infgen.pcc"
#line 429 "infgen.pcc"
                    ;
                    else
                    {
                      r->_5 = 
#line 432 "infgen.pcc"
#line 432 "infgen.pcc"
                    list_1_(INJECTdecl(node_number,RIGHTdirection))
#line 432 "infgen.pcc"
#line 432 "infgen.pcc"
                    ;
                    node_number++;
                    }
                    if (r->negated)
                    negative_clauses++;
                    else
                    positive_clauses++;
                    
#line 439 "infgen.pcc"
                  } else {
                    
                    L15:; 
#line 442 "infgen.pcc"
                  error("%Lnon-relation type %T in pattern: %p\n", _V2, r->_2); 
#line 442 "infgen.pcc"
                  }
                  } break;
                default: { goto L15; } break;
              }
            } else { goto L15; }
            } break;
          default: { goto L15; } break;
        }
      } else {}
    }
#line 443 "infgen.pcc"
#line 443 "infgen.pcc"
    
    
#line 444 "infgen.pcc"
  }
#line 445 "infgen.pcc"
#line 445 "infgen.pcc"
  
  i++;
  object_count++;
  }
  node_number++;
  if (max_arity < object_count)
  max_arity = object_count;
  
#line 452 "infgen.pcc"
}
#line 453 "infgen.pcc"
#line 453 "infgen.pcc"

  }
  return max_arity;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the alpha (single object) tests.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_alpha_tests
   (Id id, int max_arity, HashTable& rule_map)
{
  pr(
      "%^%/%^//  Single object tests for inference class %s%^%/"
      "%^void %s::alpha_test(int predicate__, int i__, Fact * fact__)"
      "%^{%+"
      "%^Fact * f__[%i];"
      "%^switch (predicate__) {%+",
      id, id, max_arity
    );
  {
    Bool save = same_selectors;
    same_selectors = true;
    int type_number = 1;
    foreach_entry(e, rule_map)
    {
      Id         ty_name = (Id)rule_map.key(e);
      MatchRules rules   = (MatchRules)rule_map.value(e);
      pr(
          "%^case %i: {%+"
          "%^%s _0 = (%s)(f__[0] = fact__);",
          type_number, ty_name, ty_name
        );
      gen_match_stmt (
#line 488 "infgen.pcc"
#line 488 "infgen.pcc"
nil_1_
#line 488 "infgen.pcc"
#line 488 "infgen.pcc"
, rules, MATCHall | MATCHnocheck);
      pr ("} break; %-");
      type_number++;
    }
    same_selectors = save;
  }
  pr(
      "%-%^}"
      "%-%^}\n\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the beta tests(joins)
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_beta_tests
   (Id id, int n, InferenceRule rules[], HashTable& join_map)
{
  pr(
      "%^%/%^//  Joins for inference class %s%^%/"
      "%^int %s::beta_test(Join join__, Fact * f__[])"
      "%^{%+"
      "%^switch (join__) {%+",
      id, id
    );

  for (int i = 0; i < n; i++)
  {
    
#line 519 "infgen.pcc"
#line 551 "infgen.pcc"
{
  InferenceRule _V3 = rules[i];
#line 522 "infgen.pcc"
  
  for(MatchRules rs = _V3->_1; rs; rs = rs->_2)
  {
    if (rs->_2 == 
#line 525 "infgen.pcc"
#line 525 "infgen.pcc"
  nil_1_
#line 525 "infgen.pcc"
#line 525 "infgen.pcc"
 ||
  rs->_1->rule_number != rs->_2->_1->rule_number)
  {
  MatchRule r = rs->_1;
  int rule_no = r->rule_number;
  HashTable::Entry * e =
   join_map.lookup((HashTable::Key)rule_no);
  if (e)
  {
  Exp join = (Exp)join_map.value(e);
  int j = 0;
  pr( "%^case %i: {%+", rule_no);
  for_each (MatchRule, mr, _V3->_1)
  {
   pr(
       "%^%t _%i = (%t)f__[%i];",
       mr->ty, "", j, mr->ty, "", j
     );
   j++;
   if (mr == r)
     break;
  }
  pr ("%^return %e;%-%^}", join);
  }
  }
  }
  
#line 551 "infgen.pcc"
}
#line 552 "infgen.pcc"
#line 552 "infgen.pcc"

  }

  pr ("%^default: return 0;"
      "%-%^}"
      "%-%^}\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the dispatch table.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_dispatch_table(Id id, HashTable& rule_map)
{
  pr(
      "%^%/%^//  Dispatch table for inference class %s%^%/"
      "%^const %s::RelationTable %s::relation_table[] = {%+",
      id, id, id
    );
  {
    int type_number = 1;
    Bool comma = false;
    foreach_entry (e, rule_map)
    {
      Id ty_name = (Id)rule_map.key(e);
      if (comma) pr (",");
      pr(
          "%^{ &a_%s::relation_tag, %i, \"%s\" }",
          ty_name, type_number, ty_name
        );
      comma = true;
      type_number++;
    }
  }
  pr( "%-%^};\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the network table.
//
///////////////////////////////////////////////////////////////////////////////
int InferenceCompiler::gen_network_table
   (Id id, int n, InferenceRule rules[], HashTable& join_table)
{
  pr(
      "%^%/%^//  Network table for inference class %s%^%/"
      "%^const %s::Node %s::network_table[] = {%+",
      id, id, id
    );

   int entries = 0;
   Bool comma = false;
   for (int i = 0; i < n; i++)
   {
     
#line 609 "infgen.pcc"
#line 641 "infgen.pcc"
{
  InferenceRule _V4 = rules[i];
#line 612 "infgen.pcc"
  
  int max_arity = length(_V4->_1);
  int last_rule_number = -1;
  int arity = 1;
  for_each (MatchRule, r, _V4->_1)
  {
    if (last_rule_number != r->rule_number
         && (max_arity > 1 || r->negated) )
    {
      if (comma) pr( ",");
      Id  typ  = r->negated ? "Not" : "And";
      int join =
          join_table.contains((HashTable::Key)r->rule_number)
            ? r->rule_number : 0;
      pr ( "%^{ %i, %i, ReteNet::Node::%s, %i, %i } /* %i */",
          arity, max_arity, typ, join, r->rule_number + 1, entries);
      comma = true;
      arity++;
      entries++;
    }
    last_rule_number = r->rule_number;
  }
  if (comma) pr( ",");
  pr(
      "%^{ 0, %i, ReteNet::Node::Bot, %i, %i } /* %i */",
      max_arity, 0, i, entries
    );
  entries++;
  comma = true;
  
#line 641 "infgen.pcc"
}
#line 642 "infgen.pcc"
#line 642 "infgen.pcc"

   }

   pr( "%-%^};\n\n");

   return entries;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the axioms of the inference class.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_inference_axioms( Id id, InferenceRules rules)
{
   pr(
       "%^%/%^//  Axioms for inference class %s%^%/"
       "%^void %s::initialise_axioms()"
       "%^{%+",
       id, id
     );
   for_each ( InferenceRule, r, rules)
   {
     
#line 666 "infgen.pcc"
#line 670 "infgen.pcc"
{
  if (r->_1) {} else {
#line 668 "infgen.pcc"
   gen_conclusions( r->_3); 
#line 668 "infgen.pcc"
  }
}
#line 670 "infgen.pcc"
#line 670 "infgen.pcc"

   }
   pr ("%-%^}\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the action routine of the inference class
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_inference_actions( Id id, InferenceRules rules)
{
  pr(
      "%^%/%^//  Actions for inference class %s%^%/"
      "%^void %s::action(%s::RuleId r__, Fact * f__[])"
      "%^{%+"
      "%^switch (r__) {%+",
      id, id, id
    );

  int rule_no = 0;
  for_each ( InferenceRule, r, rules)
  {
    
#line 694 "infgen.pcc"
#line 709 "infgen.pcc"
{
  if (r->_1) {
#line 697 "infgen.pcc"
    
    pr ("%^case %i: {%+", rule_no);
    int i = 0;
    for_each (MatchRule, mr, r->_1)
    {
      pr ("%^%t _%i = (%t)f__[%i];", mr->ty, "", i, mr->ty, "", i);
      i++;
    }
    gen_conclusions( r->_3);
    pr ("%-%^} break;");
    
#line 707 "infgen.pcc"
  } else {}
}
#line 709 "infgen.pcc"
#line 709 "infgen.pcc"

    rule_no++;
  }
  pr(
      "%-%^}"
      "%-%^}\n\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the conclusions of the inference class.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_conclusions( Conclusions cs)
{
  for_each (Conclusion, c, cs)
    gen_conclusion(c);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate one conclusion of the inference class.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_conclusion( Conclusion c)
{
  
#line 738 "infgen.pcc"
#line 742 "infgen.pcc"
{
  switch (untagp(c)) {
    case a_Conclusion::tag_ASSERTaction: {
#line 740 "infgen.pcc"
     pr( "%^assert_fact(%e);\n", ((Conclusion_ASSERTaction *)c)->ASSERTaction); 
#line 740 "infgen.pcc"
      } break;
    case a_Conclusion::tag_RETRACTaction: {
#line 741 "infgen.pcc"
     pr( "%^retract_fact(%e);\n", ((Conclusion_RETRACTaction *)derefp(c))->RETRACTaction); 
#line 741 "infgen.pcc"
      } break;
    default: {
#line 742 "infgen.pcc"
     pr( "%^%&", ((Conclusion_STMTaction *)derefp(c))->STMTaction); 
#line 742 "infgen.pcc"
      } break;
  }
}
#line 743 "infgen.pcc"
#line 743 "infgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the constructor of the inference class.
//
///////////////////////////////////////////////////////////////////////////////

void InferenceCompiler::gen_inference_constructor
   (Id id, int entries, HashTable& rule_map)
{
   pr(
       "%^%/%^//  Constructor for inference class %s%^%/"
       "%^%s::%s()%+"
       "%^: Rete(%i,%s::network_table,%i,%s::relation_table)%+"
       "%^{ initialise_axioms(); }%-%-\n\n",
       id, id, id,
       entries, id, rule_map.size(), id
     );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the interface of a relation object.
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeClass::generate_inference_interface( CodeGen& C)
{
  if (this != root) return;

  C.pr(
        "%^%/"
        "%^//"
        "%^// Inference methods"
        "%^//"
        "%^%/"
        "%^static RelTag relation_tag;"
        "%^virtual RelTag get_tag() const;"
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the implementation of a relation object.
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeClass::generate_inference_implementation
   (CodeGen& C, Tys tys, DefKind k)
{
  if (this != root) return;

  C.pr(
        "%^%/"
        "%^//"
        "%^// Relation datatype %s%P"
        "%^//"
        "%^%/"
        "%^Fact::RelTag %s%P::relation_tag = 0;"
        "%^static InitialiseFact %s_dummy__(%s%P::relation_tag);"
        "%^Fact::RelTag %s%P::get_tag() const"
        " { return %s%P::relation_tag; }\n \n",
        root->datatype_name, tys,
        class_name, tys,
        DatatypeCompiler::temp_vars.new_label(), class_name, tys,
        class_name, tys,
        class_name, tys
      );
}
#line 814 "infgen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 169
Number of ifs generated      = 46
Number of switches generated = 5
Number of labels             = 14
Number of gotos              = 36
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
