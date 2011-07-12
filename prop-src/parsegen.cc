///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "parsegen.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _p_a_r_s_e_g_e_nco_c_c_Q1("'");
#line 1 "parsegen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the syntax/syntax class constructs of Prop.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <AD/strings/charesc.h>
#include <AD/strings/quark.h>
#include <AD/automata/grammar.h>
#include <AD/automata/operprec.h>
#include <AD/automata/lalr1gen.h>
#include "ir.h"
#include "ast.h"
#include "parsegen.h"
#include "datagen.h"
#include "hashtab.h"
#include "type.h"
#include "list.h"
#include "options.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the parser/grammar related datatypes
//
///////////////////////////////////////////////////////////////////////////////

#line 29 "parsegen.pcc"
#line 29 "parsegen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype GramExp
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<GramExp>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype BNF
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<BNF>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype ProductionSymbol
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<ProductionSymbol>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype PrecRule
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<PrecRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<a_List<ProductionSymbol> * >
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype GramExp
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
GramExp_EXPgram::GramExp_EXPgram (a_List<PrecRule> *  x_1, ShiftReduceErrors x_2, a_List<BNF> *  x_3)
 : a_GramExp(tag_EXPgram), _1(x_1), _2(x_2), _3(x_3)
{
}
a_GramExp * EXPgram (a_List<PrecRule> *  x_1, ShiftReduceErrors x_2, a_List<BNF> *  x_3)
{
  return new GramExp_EXPgram (x_1, x_2, x_3);
}
GramExp_POLYgram::GramExp_POLYgram (int x_1, Id * x_2, GramExp x_3)
 : a_GramExp(tag_POLYgram), _1(x_1), _2(x_2), _3(x_3)
{
}
a_GramExp * POLYgram (int x_1, Id * x_2, GramExp x_3)
{
  return new GramExp_POLYgram (x_1, x_2, x_3);
}
GramExp_UNIONgram::GramExp_UNIONgram (GramExp x_1, GramExp x_2)
 : a_GramExp(tag_UNIONgram), _1(x_1), _2(x_2)
{
}
a_GramExp * UNIONgram (GramExp x_1, GramExp x_2)
{
  return new GramExp_UNIONgram (x_1, x_2);
}
GramExp_RESTRICTgram::GramExp_RESTRICTgram (GramExp x_RESTRICTgram)
 : a_GramExp(tag_RESTRICTgram), RESTRICTgram(x_RESTRICTgram)
{
}
a_GramExp * RESTRICTgram (GramExp x_RESTRICTgram)
{
  return new GramExp_RESTRICTgram (x_RESTRICTgram);
}
GramExp_APPgram::GramExp_APPgram (GramExp x_1, GramExp x_2)
 : a_GramExp(tag_APPgram), _1(x_1), _2(x_2)
{
}
a_GramExp * APPgram (GramExp x_1, GramExp x_2)
{
  return new GramExp_APPgram (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<GramExp>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<GramExp>;
template a_List<GramExp> * list_1_(a_List<ProductionSymbol> *  x_1, a_List<a_List<ProductionSymbol> * > *  x_2);
template a_List<GramExp> * list_1_(a_List<ProductionSymbol> *  x_list_1_);
template int boxed(const a_List<GramExp> *);
template int untag(const a_List<GramExp> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype BNF
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
a_BNF::a_BNF (Id x_1, Ty x_2, a_List<ProductionSymbols> *  x_3)
 : _1(x_1), _2(x_2), _3(x_3)
{
}
a_BNF * BNFrule (Id x_1, Ty x_2, a_List<ProductionSymbols> *  x_3)
{
  return new a_BNF (x_1, x_2, x_3);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<BNF>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<BNF>;
template a_List<BNF> * list_1_(GramExp x_1, a_List<GramExp> *  x_2);
template a_List<BNF> * list_1_(GramExp x_list_1_);
template int boxed(const a_List<BNF> *);
template int untag(const a_List<BNF> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype ProductionSymbol
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
ProductionSymbol_TERMsym::ProductionSymbol_TERMsym (char x_TERMsym)
 : a_ProductionSymbol(tag_TERMsym), TERMsym(x_TERMsym)
{
}
a_ProductionSymbol * TERMsym (char x_TERMsym)
{
  return new ProductionSymbol_TERMsym (x_TERMsym);
}
ProductionSymbol_TERMSTRINGsym::ProductionSymbol_TERMSTRINGsym (char const * x_TERMSTRINGsym)
 : a_ProductionSymbol(tag_TERMSTRINGsym), TERMSTRINGsym(x_TERMSTRINGsym)
{
}
a_ProductionSymbol * TERMSTRINGsym (char const * x_TERMSTRINGsym)
{
  return new ProductionSymbol_TERMSTRINGsym (x_TERMSTRINGsym);
}
ProductionSymbol_TERMREGEXPsym::ProductionSymbol_TERMREGEXPsym (char const * x_TERMREGEXPsym)
 : a_ProductionSymbol(tag_TERMREGEXPsym), TERMREGEXPsym(x_TERMREGEXPsym)
{
}
a_ProductionSymbol * TERMREGEXPsym (char const * x_TERMREGEXPsym)
{
  return new ProductionSymbol_TERMREGEXPsym (x_TERMREGEXPsym);
}
ProductionSymbol_TOKENsym::ProductionSymbol_TOKENsym (Cons x_TOKENsym)
 : a_ProductionSymbol(tag_TOKENsym), TOKENsym(x_TOKENsym)
{
}
a_ProductionSymbol * TOKENsym (Cons x_TOKENsym)
{
  return new ProductionSymbol_TOKENsym (x_TOKENsym);
}
ProductionSymbol_NONTERMsym::ProductionSymbol_NONTERMsym (Id x_NONTERMsym)
 : a_ProductionSymbol(tag_NONTERMsym), NONTERMsym(x_NONTERMsym)
{
}
a_ProductionSymbol * NONTERMsym (Id x_NONTERMsym)
{
  return new ProductionSymbol_NONTERMsym (x_NONTERMsym);
}
ProductionSymbol_POSNONTERMsym::ProductionSymbol_POSNONTERMsym (int x_POSNONTERMsym)
 : a_ProductionSymbol(tag_POSNONTERMsym), POSNONTERMsym(x_POSNONTERMsym)
{
}
a_ProductionSymbol * POSNONTERMsym (int x_POSNONTERMsym)
{
  return new ProductionSymbol_POSNONTERMsym (x_POSNONTERMsym);
}
ProductionSymbol_ACTIONsym::ProductionSymbol_ACTIONsym (a_List<Decl> *  x_ACTIONsym)
 : a_ProductionSymbol(tag_ACTIONsym), ACTIONsym(x_ACTIONsym)
{
}
a_ProductionSymbol * ACTIONsym (a_List<Decl> *  x_ACTIONsym)
{
  return new ProductionSymbol_ACTIONsym (x_ACTIONsym);
}
ProductionSymbol_PREDICATEsym::ProductionSymbol_PREDICATEsym (Exp x_PREDICATEsym)
 : a_ProductionSymbol(tag_PREDICATEsym), PREDICATEsym(x_PREDICATEsym)
{
}
a_ProductionSymbol * PREDICATEsym (Exp x_PREDICATEsym)
{
  return new ProductionSymbol_PREDICATEsym (x_PREDICATEsym);
}
ProductionSymbol_PRECsym::ProductionSymbol_PRECsym (Cons x_PRECsym)
 : a_ProductionSymbol(tag_PRECsym), PRECsym(x_PRECsym)
{
}
a_ProductionSymbol * PRECsym (Cons x_PRECsym)
{
  return new ProductionSymbol_PRECsym (x_PRECsym);
}
ProductionSymbol_ERRORsym::ProductionSymbol_ERRORsym ()
 : a_ProductionSymbol(tag_ERRORsym)
{
}
a_ProductionSymbol * ERRORsym ()
{
  return new ProductionSymbol_ERRORsym ;
}
ProductionSymbol_SPECIALsym::ProductionSymbol_SPECIALsym (char x_SPECIALsym)
 : a_ProductionSymbol(tag_SPECIALsym), SPECIALsym(x_SPECIALsym)
{
}
a_ProductionSymbol * SPECIALsym (char x_SPECIALsym)
{
  return new ProductionSymbol_SPECIALsym (x_SPECIALsym);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<ProductionSymbol>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<ProductionSymbol>;
template a_List<ProductionSymbol> * list_1_(BNF x_1, a_List<BNF> *  x_2);
template a_List<ProductionSymbol> * list_1_(BNF x_list_1_);
template int boxed(const a_List<ProductionSymbol> *);
template int untag(const a_List<ProductionSymbol> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype PrecRule
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
a_PrecRule::a_PrecRule (PrecMode x_1, int x_2, ProductionSymbols x_3)
 : _1(x_1), _2(x_2), _3(x_3)
{
}
a_PrecRule * PRECrule (PrecMode x_1, int x_2, ProductionSymbols x_3)
{
  return new a_PrecRule (x_1, x_2, x_3);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<PrecRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<PrecRule>;
template a_List<PrecRule> * list_1_(ProductionSymbol x_1, a_List<ProductionSymbol> *  x_2);
template a_List<PrecRule> * list_1_(ProductionSymbol x_list_1_);
template int boxed(const a_List<PrecRule> *);
template int untag(const a_List<PrecRule> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<a_List<ProductionSymbol> * >
//
///////////////////////////////////////////////////////////////////////////////
#line 29 "parsegen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<a_List<ProductionSymbol> * >;
template a_List<a_List<ProductionSymbol> * > * list_1_(PrecRule x_1, a_List<PrecRule> *  x_2);
template a_List<a_List<ProductionSymbol> * > * list_1_(PrecRule x_list_1_);
template int boxed(const a_List<a_List<ProductionSymbol> * > *);
template int untag(const a_List<a_List<ProductionSymbol> * > *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

#line 33 "parsegen.pcc"
#line 33 "parsegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

ParserCompiler:: ParserCompiler() {}
ParserCompiler::~ParserCompiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing methods for grammar
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a production symbol
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, ProductionSymbol sym)
{
  
#line 58 "parsegen.pcc"
#line 72 "parsegen.pcc"
{
  switch (sym->tag__) {
    case a_ProductionSymbol::tag_TERMsym: {
#line 60 "parsegen.pcc"
    f << '\'' << print_char(((ProductionSymbol_TERMsym *)sym)->TERMsym) << '\''; 
#line 60 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_TERMSTRINGsym: {
#line 66 "parsegen.pcc"
    f << ((ProductionSymbol_TERMSTRINGsym *)sym)->TERMSTRINGsym; 
#line 66 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_TERMREGEXPsym: {
#line 67 "parsegen.pcc"
    f << ((ProductionSymbol_TERMREGEXPsym *)sym)->TERMREGEXPsym; 
#line 67 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_TOKENsym: {
      if (((ProductionSymbol_TOKENsym *)sym)->TOKENsym) {
#line 62 "parsegen.pcc"
      f << ((ProductionSymbol_TOKENsym *)sym)->TOKENsym->name; 
#line 62 "parsegen.pcc"
      } else {
#line 61 "parsegen.pcc"
      f << "<?>"; 
#line 61 "parsegen.pcc"
      }
      } break;
    case a_ProductionSymbol::tag_NONTERMsym: {
#line 63 "parsegen.pcc"
    f << ((ProductionSymbol_NONTERMsym *)sym)->NONTERMsym; 
#line 63 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_POSNONTERMsym: {
#line 64 "parsegen.pcc"
    f << ((ProductionSymbol_POSNONTERMsym *)sym)->POSNONTERMsym; 
#line 64 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_ACTIONsym: {
#line 65 "parsegen.pcc"
    f << "{ ... }"; 
#line 65 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_PREDICATEsym: {
#line 68 "parsegen.pcc"
    f << '(' << ((ProductionSymbol_PREDICATEsym *)sym)->PREDICATEsym << ')'; 
#line 68 "parsegen.pcc"
      } break;
    case a_ProductionSymbol::tag_PRECsym: {
      if (((ProductionSymbol_PRECsym *)sym)->PRECsym) {
#line 69 "parsegen.pcc"
      f << "prec: " << ((ProductionSymbol_PRECsym *)sym)->PRECsym->name; 
#line 69 "parsegen.pcc"
      } else {
#line 70 "parsegen.pcc"
      f << "prec: ???"; 
#line 70 "parsegen.pcc"
      }
      } break;
    case a_ProductionSymbol::tag_ERRORsym: {
#line 71 "parsegen.pcc"
    f << '?'; 
#line 71 "parsegen.pcc"
      } break;
    default: {
#line 72 "parsegen.pcc"
    f << "???"; 
#line 72 "parsegen.pcc"
      } break;
  }
}
#line 73 "parsegen.pcc"
#line 73 "parsegen.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a list of production symbols
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, ProductionSymbols P)
{
  for (ProductionSymbols l = P; l; l = l->_2)
  {
    f << l->_1;
    if (l->_2)
      f << " ";
  }
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a BNF
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, BNF bnf)
{
  
#line 102 "parsegen.pcc"
#line 112 "parsegen.pcc"
{
#line 105 "parsegen.pcc"
  
  f << bnf->_1;
  if (bnf->_2 != NOty)
    f << ' ' << bnf->_2 << ' ';
  f << ':';
  for_each (ProductionSymbols, p, bnf->_3)
    {  f << '\t' << p << '\n'; }
  
#line 112 "parsegen.pcc"
}
#line 113 "parsegen.pcc"
#line 113 "parsegen.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a list of alternatives
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, BNFs rules)
{
  for_each( BNF, rule, rules)
    f << rule;
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a precedence rule
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, PrecRule r)
{
  
#line 138 "parsegen.pcc"
#line 149 "parsegen.pcc"
{
#line 141 "parsegen.pcc"
  
  
#line 142 "parsegen.pcc"
#line 146 "parsegen.pcc"
  {
    PrecMode _V1 = r->_1;
    switch (_V1) {
      case LEFTassoc: {
#line 144 "parsegen.pcc"
       f << "left: "; 
#line 144 "parsegen.pcc"
        } break;
      case RIGHTassoc: {
#line 145 "parsegen.pcc"
       f << "right: "; 
#line 145 "parsegen.pcc"
        } break;
      default: {
#line 146 "parsegen.pcc"
       f << "nonfix: "; 
#line 146 "parsegen.pcc"
        } break;
    }
  }
#line 147 "parsegen.pcc"
#line 147 "parsegen.pcc"
  
  f << r->_2 << ' ' << r->_3 << '\n';
  
#line 149 "parsegen.pcc"
}
#line 150 "parsegen.pcc"
#line 150 "parsegen.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a list of precedence rules
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, 
#line 160 "parsegen.pcc"
a_List<PrecRule> *  
#line 160 "parsegen.pcc"
 rules)
{
  for_each (PrecRule, r, rules)
    f << r;
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a grammar expression
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, GramExp exp)
{
  
#line 180 "parsegen.pcc"
{
  switch (exp->tag__) {
    case a_GramExp::tag_EXPgram: {
#line 178 "parsegen.pcc"
     f << ((GramExp_EXPgram *)exp)->_1 << ((GramExp_EXPgram *)exp)->_3; 
#line 178 "parsegen.pcc"
      } break;
    default: {} break;
  }
}
#line 180 "parsegen.pcc"
#line 180 "parsegen.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create a syntax class
//
///////////////////////////////////////////////////////////////////////////////

SyntaxClass::SyntaxClass( CLASS_TYPE ct, Id id, Inherits i, TyQual q, Decls body)
    : ClassDefinition( ct, id, 
#line 191 "parsegen.pcc"
#line 191 "parsegen.pcc"
nil_1_
#line 191 "parsegen.pcc"
#line 191 "parsegen.pcc"
, add_inherit( "LR1Parser", 
#line 191 "parsegen.pcc"
#line 191 "parsegen.pcc"
nil_1_
#line 191 "parsegen.pcc"
#line 191 "parsegen.pcc"
, i), q, body),
      production_rules(
#line 192 "parsegen.pcc"
#line 192 "parsegen.pcc"
nil_1_
#line 192 "parsegen.pcc"
#line 192 "parsegen.pcc"
),
      precedence_rules(
#line 193 "parsegen.pcc"
#line 193 "parsegen.pcc"
nil_1_
#line 193 "parsegen.pcc"
#line 193 "parsegen.pcc"
),
      G(0), parserGen(0), prec(0),
      nonterm_map(string_hash, string_equal),
      action_map(integer_hash, integer_equal),
      inner_action_map(integer_hash, integer_equal),
      line_map  (integer_hash, integer_equal),
      predicate_map(integer_hash, integer_equal)
    {
    }
SyntaxClass::~SyntaxClass() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the interface of a parser class
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::gen_class_interface (CodeGen& C)
{
  C.pr(
        "%-%^public:%+"
        "%^%/"
        "%^// Parser table type definitions"
        "%^%/"
        "%^typedef LR1Parser               Super;"
        "%^typedef Super::Offset           Offset;"
        "%^typedef Super::State            State;"
        "%^typedef Super::Rule             Rule;"
        "%^typedef Super::Symbol           Symbol;"
        "%^typedef Super::ProductionLength ProductionLength;"
        "%^typedef Super::ShortSymbol      ShortSymbol;"
        "%^typedef Super::EquivMap         EquivMap;"
        "%^enum { INITIAL_STACK_SIZE_ = 256,"
        "%^       MAX_STACK_SIZE_     = 8192"
        "%^     };"
        "%-%^protected:%+"
        "%^%/"
        "%^// Semantic value stack"
        "%^%/"
        "%^union %s_semantic_stack_type * t__, * bot__;"
        "%^int stack_size__;"
        "%^int heap_allocated__;"
        "%-%^public:%+"
        "%^%/"
        "%^// Constructor and parsing method"
        "%^%/"
        "%^%s();"
        "%^virtual void parse();"
        "%^void action_driver(const Rule);"
        "%-%^private:%+"
        "%^void adjust_stack(int);\n"
        "%^void grow_semantic_stack();",
        class_name, class_name
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a parser given a grammar expression.
//
///////////////////////////////////////////////////////////////////////////////

void ParserCompiler::gen_parser(Id id, GramExp e)
{
  // if (debug) std::cerr << id << ":\n" << e;

  SyntaxClass * C = (SyntaxClass*)
      ClassDefinition::lookup_class( ClassDefinition::SYNTAX_CLASS, id);
  if (C) C->gen_parser( *this, e);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a parser given a grammar expression.
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::gen_parser( CodeGen& C, GramExp e)
{
   initialize();
   compile_grammar(C, e);
   cleanup();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compile a grammar
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::compile_grammar( CodeGen& C, GramExp e)
{
  
#line 285 "parsegen.pcc"
#line 292 "parsegen.pcc"
{
  switch (e->tag__) {
    case a_GramExp::tag_EXPgram: {
#line 288 "parsegen.pcc"
      
      compile_rules(C, ((GramExp_EXPgram *)e)->_1, ((GramExp_EXPgram *)e)->_2, ((GramExp_EXPgram *)e)->_3);
      
#line 290 "parsegen.pcc"
      } break;
    default: {
#line 292 "parsegen.pcc"
     bug("SyntaxClass::compile_grammar"); 
#line 292 "parsegen.pcc"
      } break;
  }
}
#line 293 "parsegen.pcc"
#line 293 "parsegen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Collect the names of the non-terminals
//  and count the number of productions.
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::preprocess_grammar ()
{
  number_of_productions = 0;

  ////////////////////////////////////////////////////////////////////////////
  //  Compute the terminal and action encoding
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each(BNF, r, production_rules)
    {
      
#line 313 "parsegen.pcc"
#line 342 "parsegen.pcc"
{
#line 316 "parsegen.pcc"
  
  for_each ( ProductionSymbols, p, r->_3)
  {
    Bool no_action = true;
    for_each (ProductionSymbol, s, p)
    {
      s->set_loc();
      
#line 323 "parsegen.pcc"
#line 336 "parsegen.pcc"
  {
    switch (s->tag__) {
      case a_ProductionSymbol::tag_TOKENsym: {
        if (((ProductionSymbol_TOKENsym *)s)->TOKENsym) {
          if (((ProductionSymbol_TOKENsym *)s)->TOKENsym->alg_ty) {
            switch (((ProductionSymbol_TOKENsym *)s)->TOKENsym->alg_ty->tag__) {
              case a_Ty::tag_TYCONty: {
                if (boxed(((Ty_TYCONty *)((ProductionSymbol_TOKENsym *)s)->TOKENsym->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)((ProductionSymbol_TOKENsym *)s)->TOKENsym->alg_ty)->_1->tag__) {
                    case a_TyCon::tag_DATATYPEtycon: {
#line 328 "parsegen.pcc"
                      
                      if ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((ProductionSymbol_TOKENsym *)s)->TOKENsym->alg_ty)->_1)->qualifiers & QUALlexeme) == 0)
                        error("%Lconstructor %s is not a lexeme\n",((ProductionSymbol_TOKENsym *)s)->TOKENsym->name);
                      if (tag_of(((ProductionSymbol_TOKENsym *)s)->TOKENsym) > max_term)
                        max_term = tag_of(((ProductionSymbol_TOKENsym *)s)->TOKENsym);
                      
#line 333 "parsegen.pcc"
                      } break;
                    default: {
                      L1:; } break;
                  }
                } else { goto L1; }
                } break;
              default: { goto L1; } break;
            }
          } else { goto L1; }
        } else { goto L1; }
        } break;
      case a_ProductionSymbol::tag_ACTIONsym: {
#line 334 "parsegen.pcc"
       no_action = false; 
#line 334 "parsegen.pcc"
        } break;
      default: { goto L1; } break;
    }
  }
#line 336 "parsegen.pcc"
#line 336 "parsegen.pcc"
  
  }
  if (r->_2 != NOty && no_action)
    msg("%!%wmissing synthesized value in production: %s %T:",
          r->loc(), r->_1, r->_2) << p << '\n';
  }
  
#line 342 "parsegen.pcc"
}
#line 343 "parsegen.pcc"
#line 343 "parsegen.pcc"

    }
  }

  ////////////////////////////////////////////////////////////////////////////
  //  Set the error token
  ////////////////////////////////////////////////////////////////////////////
  error_term  = ++max_term;
  max_nonterm = max_term + 1;

  ////////////////////////////////////////////////////////////////////////////
  //  Compute the non-terminals encoding.
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each(BNF, r, production_rules)
    {
      
#line 359 "parsegen.pcc"
#line 369 "parsegen.pcc"
{
#line 362 "parsegen.pcc"
  
  if (! nonterm_map.contains(r->_1))
    {
      max_nonterm++;
      nonterm_map.insert(r->_1,(HashTable::Value)max_nonterm);
    }
  number_of_productions += length(r->_3);
  
#line 369 "parsegen.pcc"
}
#line 370 "parsegen.pcc"
#line 370 "parsegen.pcc"

    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate rules into grammar form.
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::translate_into_grammar ()
{
  int i = 0; // production number
  min_action = Grammar::First_action;
  for_each(BNF, r, production_rules)
  {
    
#line 387 "parsegen.pcc"
#line 450 "parsegen.pcc"
{
#line 390 "parsegen.pcc"
  
  Grammar::NonTerminal A = (Grammar::NonTerminal)nonterm_map[r->_1];
  symbol_names[A] = r->_1;
  for_each (ProductionSymbols, p, r->_3)
  {
    int j = 1;
    int non_terms_or_actions = 0;
    ty_map[i] = r->_2;
    Grammar::Production P =
        (Grammar::Production)mem_pool.c_alloc
          (sizeof(Grammar::Symbol) * (length(p) + 2));
    P[0] = A;
    for (
#line 402 "parsegen.pcc"
a_List<ProductionSymbol> *  
#line 402 "parsegen.pcc"
 L = p; L; L = L->_2)
  {
    ProductionSymbol X = L->_1;
    X->set_loc();
    
#line 443 "parsegen.pcc"
  {
    switch (X->tag__) {
      case a_ProductionSymbol::tag_TERMsym: {
#line 409 "parsegen.pcc"
        
        P[j] = ((ProductionSymbol_TERMsym *)X)->TERMsym;
        if (symbol_names[((ProductionSymbol_TERMsym *)X)->TERMsym] == 0)
          symbol_names[((ProductionSymbol_TERMsym *)X)->TERMsym] = 
#line 412 "parsegen.pcc"
#line 412 "parsegen.pcc"
        _p_a_r_s_e_g_e_nco_c_c_Q1
#line 412 "parsegen.pcc"
#line 412 "parsegen.pcc"
       + print_char(((ProductionSymbol_TERMsym *)X)->TERMsym) + 
#line 412 "parsegen.pcc"
#line 412 "parsegen.pcc"
        _p_a_r_s_e_g_e_nco_c_c_Q1
#line 412 "parsegen.pcc"
#line 412 "parsegen.pcc"
        ;
        
#line 413 "parsegen.pcc"
        } break;
      case a_ProductionSymbol::tag_TOKENsym: {
        if (((ProductionSymbol_TOKENsym *)X)->TOKENsym) {
#line 423 "parsegen.pcc"
          
          P[j] = tag_of(((ProductionSymbol_TOKENsym *)X)->TOKENsym);
          symbol_names[P[j]] = ((ProductionSymbol_TOKENsym *)X)->TOKENsym->name;
          
#line 426 "parsegen.pcc"
        } else {
#line 427 "parsegen.pcc"
         P[j] = ' '; 
#line 427 "parsegen.pcc"
        }
        } break;
      case a_ProductionSymbol::tag_NONTERMsym: {
#line 415 "parsegen.pcc"
        
        if (! nonterm_map.contains(((ProductionSymbol_NONTERMsym *)X)->NONTERMsym))
          error("%Lundefined non-terminal %s\n",((ProductionSymbol_NONTERMsym *)X)->NONTERMsym);
        else
          P[j] = (Grammar::NonTerminal) nonterm_map[((ProductionSymbol_NONTERMsym *)X)->NONTERMsym];
        ++non_terms_or_actions;
        
#line 421 "parsegen.pcc"
        } break;
      case a_ProductionSymbol::tag_ACTIONsym: {
#line 429 "parsegen.pcc"
        
        P[j] = min_action;
        action_map.insert( HashTable::Key( min_action), ((ProductionSymbol_ACTIONsym *)X)->ACTIONsym);
        line_map.insert( HashTable::Key( min_action),
                        HashTable::Value( X->begin_line));
        if (L->_2 != 
#line 434 "parsegen.pcc"
#line 434 "parsegen.pcc"
        nil_1_
#line 434 "parsegen.pcc"
#line 434 "parsegen.pcc"
        )
        inner_action_map.insert( HashTable::Key( min_action),
           HashTable::Value( non_terms_or_actions));
        min_action--;
        ++non_terms_or_actions;
        
#line 439 "parsegen.pcc"
        } break;
      case a_ProductionSymbol::tag_ERRORsym: {
#line 441 "parsegen.pcc"
       P[j] = error_term; 
#line 441 "parsegen.pcc"
        } break;
      default: {
#line 443 "parsegen.pcc"
       bug("translate_into_grammar()"); 
#line 443 "parsegen.pcc"
        } break;
    }
  }
#line 444 "parsegen.pcc"
#line 444 "parsegen.pcc"
  
  j++;
  }
  P[j] = Grammar::END_PRODUCTION;
  productions[i++] = P;
  }
  
#line 450 "parsegen.pcc"
}
#line 451 "parsegen.pcc"
#line 451 "parsegen.pcc"

  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to enter the precedence information
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::define_operator_precedence ()
{
  for_each (PrecRule, r, precedence_rules)
  {
  
#line 465 "parsegen.pcc"
#line 497 "parsegen.pcc"
{
#line 468 "parsegen.pcc"
  
  OpPrecedence::Associativity a;
  
#line 470 "parsegen.pcc"
#line 474 "parsegen.pcc"
  {
    PrecMode _V2 = r->_1;
    switch (_V2) {
      case LEFTassoc: {
#line 472 "parsegen.pcc"
       a = OpPrecedence::Left; 
#line 472 "parsegen.pcc"
        } break;
      case RIGHTassoc: {
#line 473 "parsegen.pcc"
       a = OpPrecedence::Right; 
#line 473 "parsegen.pcc"
        } break;
      default: {
#line 474 "parsegen.pcc"
       a = OpPrecedence::None; 
#line 474 "parsegen.pcc"
        } break;
    }
  }
#line 475 "parsegen.pcc"
#line 475 "parsegen.pcc"
  
  for_each(ProductionSymbol, s, r->_3)
  {
    
#line 478 "parsegen.pcc"
#line 494 "parsegen.pcc"
  {
    switch (s->tag__) {
      case a_ProductionSymbol::tag_TERMsym: {
#line 481 "parsegen.pcc"
        
        prec->precedence(G->map(((ProductionSymbol_TERMsym *)s)->TERMsym),r->_2);
        prec->associativity(G->map(((ProductionSymbol_TERMsym *)s)->TERMsym),a);
        
#line 484 "parsegen.pcc"
        } break;
      case a_ProductionSymbol::tag_TOKENsym: {
#line 486 "parsegen.pcc"
        
        prec->precedence(G->map(tag_of(((ProductionSymbol_TOKENsym *)s)->TOKENsym)),r->_2);
        prec->associativity(G->map(tag_of(((ProductionSymbol_TOKENsym *)s)->TOKENsym)),a);
        
#line 489 "parsegen.pcc"
        } break;
      default: {
#line 491 "parsegen.pcc"
        
        s->set_loc();
        error("%Lprecedence symbol must be a terminal: ") << s << '\n';
        
#line 494 "parsegen.pcc"
        } break;
    }
  }
#line 495 "parsegen.pcc"
#line 495 "parsegen.pcc"
  
  }
  
#line 497 "parsegen.pcc"
}
#line 498 "parsegen.pcc"
#line 498 "parsegen.pcc"

  }
}

///////////////////////////////////////////////////////////////////////////////
//
// Add a new reference of a non-terminal
//
///////////////////////////////////////////////////////////////////////////////

static void add_use( HashTable& table, Id nonterm, int item_number)
{
  HashTable::Entry * e = table.lookup(nonterm);
  if (e)
  {
    
#line 513 "parsegen.pcc"
a_List<int> *  
#line 513 "parsegen.pcc"
 old_uses = (a_List<int> *  
#line 513 "parsegen.pcc"
) table.value(e);
    table.insert( nonterm, 
#line 514 "parsegen.pcc"
list_1_(item_number,old_uses)
#line 514 "parsegen.pcc"
#line 514 "parsegen.pcc"
);
  }
  else
  table.insert( nonterm, 
#line 517 "parsegen.pcc"
#line 517 "parsegen.pcc"
list_1_(item_number)
#line 517 "parsegen.pcc"
#line 517 "parsegen.pcc"
);
}

///////////////////////////////////////////////////////////////////////////////
//
// Generate the semantic stack definition
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_semantic_stack_definition( CodeGen& C)
{
  ////////////////////////////////////////////////////////////////////////////
  //  Mapping from nonterminal to type
  ////////////////////////////////////////////////////////////////////////////
  HashTable nonterm_to_ty(string_hash,string_equal);
  HashTable nonterm_to_uses(string_hash,string_equal);

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the semantic stack definition.
  ////////////////////////////////////////////////////////////////////////////
  C.pr(
        "%^%/"
        "%^// Semantic value stack for syntax class %s"
        "%^%/"
        "%^union %s_semantic_stack_type {%+"
        "%^int dummy;",
        class_name, class_name
      );

  ////////////////////////////////////////////////////////////////////////////
  //
  //  First, we'll make sure that all productions with the same non-terminal
  //  have the same synthesized attribute type.
  //
  ////////////////////////////////////////////////////////////////////////////
  for_each (BNF, rl, production_rules)
  {
    
#line 554 "parsegen.pcc"
#line 569 "parsegen.pcc"
{
#line 557 "parsegen.pcc"
  
  HashTable::Entry * e = nonterm_to_ty.lookup( rl->_1);
  if (e)
  {
    Ty last_ty = (Ty) nonterm_to_ty.value( e);
    if (! ty_equal( rl->_2, last_ty))
    {
      rl->set_loc();
      error("%Lexpecting type '%T' but found '%T'\n", last_ty, rl->_2);
    }
  }
  nonterm_to_ty.insert( rl->_1, rl->_2);
  
#line 569 "parsegen.pcc"
}
#line 570 "parsegen.pcc"
#line 570 "parsegen.pcc"

  }

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Now, we found out all references of all non-terminals.
  //
  ////////////////////////////////////////////////////////////////////////////
  int item_number = 0;

  for_each (BNF, r, production_rules)
  {
    
#line 582 "parsegen.pcc"
#line 610 "parsegen.pcc"
{
#line 585 "parsegen.pcc"
  
  for_each ( ProductionSymbols, p, r->_3)
  {
    ++item_number;
    if (r->_2 != NOty)
      add_use( nonterm_to_uses, r->_1, item_number);
    for_each ( ProductionSymbol, X, p)
    {
      ++item_number;
      
#line 594 "parsegen.pcc"
#line 607 "parsegen.pcc"
  {
    switch (X->tag__) {
      case a_ProductionSymbol::tag_NONTERMsym: {
#line 597 "parsegen.pcc"
        
        HashTable::Entry * e = nonterm_to_ty.lookup(((ProductionSymbol_NONTERMsym *)X)->NONTERMsym);
        if (e)
        {
          Ty this_ty = (Ty) nonterm_to_ty.value( e);
          if (this_ty != NOty)
            add_use( nonterm_to_uses, ((ProductionSymbol_NONTERMsym *)X)->NONTERMsym, item_number);
        }
        
#line 605 "parsegen.pcc"
        } break;
      default: {} break;
    }
  }
#line 607 "parsegen.pcc"
#line 607 "parsegen.pcc"
  
  }
  }
  
#line 610 "parsegen.pcc"
}
#line 611 "parsegen.pcc"
#line 611 "parsegen.pcc"

  }

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Then we print out the type definitions for all the synthesized
  //  attributes.
  //
  ////////////////////////////////////////////////////////////////////////////
  {
    int i = 0;
    for_each (BNF, r, production_rules)
    {
      
#line 624 "parsegen.pcc"
#line 641 "parsegen.pcc"
{
#line 627 "parsegen.pcc"
  
  if (r->_2 != NOty)
  {
    
#line 630 "parsegen.pcc"
a_List<int> *  
#line 630 "parsegen.pcc"
 uses = (a_List<int> *  
#line 630 "parsegen.pcc"
  )nonterm_to_uses[r->_1];
  if (uses != 
#line 631 "parsegen.pcc"
  nil_1_
#line 631 "parsegen.pcc"
#line 631 "parsegen.pcc"
  )
  {
    C.pr ("%#" "%^typedef %tATTRIBUTE_%i;" "%^ATTRIBUTE_%i ",
          r->begin_line, r->file_name, r->_2, "", i, i);
    for (
#line 635 "parsegen.pcc"
a_List<int> *  
#line 635 "parsegen.pcc"
 l = uses; l; l = l->_2)
  { C.pr ("_%i", l->_1); if (l->_2) C.pr(", "); }
  C.pr (";\n");
  i++;
  }
  }
  
}
#line 642 "parsegen.pcc"
#line 642 "parsegen.pcc"

    }
  }
  C.pr( "%-%^};\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Generate debugging tables
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_debugging_tables( CodeGen& C)
{
  C.pr(
        "%^%/"
        "%^// Debugging tables for syntax class %s"
        "%^%/"
        "\n#ifdef DEBUG_%s",
        class_name, class_name
      );

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the mapping from rule number to source code line number.
  ////////////////////////////////////////////////////////////////////////////

  C.pr( "%^static const int %s_line[] =%^{%+%^", class_name);
  {
    int * line_table = (int *)mem_pool.c_alloc(G->size() * sizeof(int));

    for (Grammar::Action a = Grammar::First_action; a > min_action; a--)
    {
      int r = G->rule_of(a);
      if (r >= 0)
        line_table[r] = (int)line_map[HashTable::Key(a)];
    }

    for (int r = 0; r < G->size(); r++)
    {
      C.pr ("%i", line_table[r]);
      if (r < G->size() - 1)
        C.pr( ", ");
      if (r % 8 == 7)
        C.pr( "%^");
    }
  }
  C.pr( "%-%^};\n\n");

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the mapping from equivalence class number to name.
  ////////////////////////////////////////////////////////////////////////////

  C.pr( "%^static const char * const %s_symbolname[] =%^{%+%^", class_name);

  {
    Id * sym_map = (Id *)
          mem_pool.c_alloc( (G->max_non_terminal() + 1) * sizeof(Id));
    for (int c = 0; c <= max_nonterm; c++)
      if (symbol_names[c])
        sym_map[G->map(c)] = symbol_names[c];
    for (int i = 0; i <= G->max_non_terminal(); i++)
    {
      C.pr( "%s", sym_map[i] ? make_quoted_string( sym_map[i]) : "\"???\"");
      if (i < G->max_non_terminal())
        C.pr( ", ");
      if (i % 8 == 7) C.pr( "%^");
    }
  }
  C.pr( "%-%^};\n\n");

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the mapping from rule number to production.
  ////////////////////////////////////////////////////////////////////////////

  {
    for (int r = 0; r < G->size(); r++)
    {
      C.pr( "%^static const DFATables::ShortSymbol %s_rhs_%i[] = { ",
            class_name, r);
      int len = G->length(G->rhs(r));
      for (int i = 0; i < len; i++)
        C.pr( "%i, ", (int)G->rhs(r)[i]);
      C.pr( " -1 };");
    }
  }
  {
    C.pr( "%^static const DFATables::ShortSymbol * %s_rhs[] =%^{%+",
          class_name);

    for (int r = 0; r < G->size(); r++)
    {
      C.pr( "%^%s_rhs_%i", class_name, r);
      if (r < G->size() - 1)
        C.pr( ", ");
    }
    C.pr( "%-%^};\n\n");
  }
  C.pr( "\n#endif\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Generate the parser tables
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_parser_tables( CodeGen& C)
{
  ////////////////////////////////////////////////////////////////////////////
  //  Generate the parser tables.
  ////////////////////////////////////////////////////////////////////////////

  C.pr(
        "%^%/"
        "%^// Encoded parser tables for syntax class %s"
        "%^%/",
        class_name
      );
  parserGen->gen_code( C.pr(""), class_name);
}

void SyntaxClass::generate_action_driver( CodeGen& C)
{
  ////////////////////////////////////////////////////////////////////////////
  //
  //  Generate the parser driver header.
  //
  ////////////////////////////////////////////////////////////////////////////
  C.pr(
        "\n"
        "%^%/"
        "%^// Parser driver for syntax class %s"
        "%^%/"
        "%^inline void %s::action_driver(const Rule _r_)"
        "%^{\n%+"
        "%^%s_semantic_stack_type syn_ = t__[0];",
        class_name, class_name, class_name
      );

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the debugging function
  ////////////////////////////////////////////////////////////////////////////

  C.pr(
        "\n%^%/"
        "%^// Tracing code for syntax class %s"
        "%^%/"
        "#ifdef DEBUG_%s"
        "%^{ std::cerr << \"Reducing via rule \" << _r_ << \" at line \""
        "%^       << %s_line[_r_] << \", \""
        "%^       << %s_symbolname[%s_lhs[_r_]] << \" <- \";"
        "%^  for (const DFATables::ShortSymbol * _p_ = %s_rhs[_r_]; *_p_ >= 0; _p_++)"
        "%^     std::cerr << %s_symbolname[*_p_] << ' ';"
        "%^  std::cerr << '\\n';"
        "%^}"
        "\n#endif\n\n",
        class_name, class_name, class_name, class_name,
        class_name, class_name, class_name, class_name, class_name
      );

  generate_semantic_actions(C);

  C.pr( "%-%^}\n\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate the parse method
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_parse_method( CodeGen& C)
{
  C.pr(
        "%^%/"
        "%^// Parsing method for parser class %s"
        "%^%/"
        "%^void %s::parse()"
        "%^{"
        "%^  %s_semantic_stack_type stack__[INITIAL_STACK_SIZE_];"
        "%^  t__ = bot__ = stack__;"
        "%^  stack_size__ = sizeof(stack__)/sizeof(stack__[0]) - 1;"
        "%^  heap_allocated__ = 0;"
        "%^  parser_prefix();"
        "%^  LR1ParserDriver<%s,(LR1Parser::State)%i> drv;"
        "%^  drv.driver(*this);"
        "%^  parser_suffix();"
        "%^  if (bot__ != stack__) delete [] bot__;"
        "%^}\n\n",
        class_name, class_name, class_name,
        class_name, (int)parserGen->final_state()
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the semantic actions
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_semantic_actions( CodeGen& C)
{
  ////////////////////////////////////////////////////////////////////////////
  //  Generate the switch on the reduction rules.
  ////////////////////////////////////////////////////////////////////////////

  C.pr(
        "%^%/"
        "%^// Actions for syntax class %s"
        "%^%/"
        "%^t__ -= %s_ncount[_r_];"
        "%^switch (_r_) {\n%+",
        class_name, class_name, class_name, class_name
      );

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the parsing actions
  ////////////////////////////////////////////////////////////////////////////

  C.pr(
        "\n"
        "#undef to__\n"
        "#define to__ 0\n"
      );

  for (Grammar::Action a = Grammar::First_action; a > min_action; a--)
  {
    HashTable::Entry * e = inner_action_map.lookup(HashTable::Key(a));
    if (e)
    {
      C.pr(
            "\n"
            "#undef to__\n"
            "#define to__ -%i",
            (int)(e->v)
          );
    }

    C.pr( "%^case %i: {%+%&%-} break;",
          (int)G->rule_of(a), action_map[HashTable::Key(a)]);

    if (e)
    {
      C.pr(
            "\n"
            "#undef to__\n"
            "#define to__ 0\n"
          );
    }
  }

  C.pr(
        "%-%^}"
        "%^if (t__ >= bot__ + stack_size__) grow_semantic_stack();"
        "%^*++t__ = syn_;"
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to initialize the data structures
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::initialize()
{
  number_of_productions = 0;
  min_term              = 0;
  max_term              = 255;
  error_term            = 255;
  max_nonterm           = 255;
  start_symbol          = 0;
  min_action            = Grammar::First_action;
  symbol_names          = 0;
  productions           = 0;
  ty_map                = 0;
  G                     = 0;
  parserGen             = 0;
  prec                  = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to cleanup all the data structures
//
///////////////////////////////////////////////////////////////////////////////

void SyntaxClass::cleanup()
{
  nonterm_map.clear();
  action_map.clear();
  inner_action_map.clear();
  line_map.clear();
  predicate_map.clear();
  productions  = 0;
  symbol_names = 0;
  ty_map       = 0;
  delete G;
  delete parserGen;
  delete prec;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compile a set of production rules
//
///////////////////////////////////////////////////////////////////////////////
void SyntaxClass::compile_rules
   (
     CodeGen&          C,
     PrecRules         prec_rules,
     ShiftReduceErrors expected_errors,
     BNFs              p_rules
   )
{
  int last_errors = errors;

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Initialize all the data structures used
  //
  ////////////////////////////////////////////////////////////////////////////

  production_rules = p_rules;
  precedence_rules = prec_rules;

  ////////////////////////////////////////////////////////////////////////////
  //
  // Collect the names of the non-terminals in this grammar
  //
  ////////////////////////////////////////////////////////////////////////////

  preprocess_grammar();

  ////////////////////////////////////////////////////////////////////////////
  //
  // Translate into grammar form.
  //
  ////////////////////////////////////////////////////////////////////////////

  productions  = (Grammar::Production *)mem_pool.c_alloc
       ( sizeof(Grammar::Production) * number_of_productions);
  symbol_names = (Id *)mem_pool.c_alloc(sizeof(Id) * (max_nonterm + 1));
  ty_map       = (Ty *)mem_pool.c_alloc(sizeof(Ty) * number_of_productions);
  translate_into_grammar();
  symbol_names[error_term] = "?";
  if (last_errors < errors)
    return;
  if (number_of_productions > 0)
     start_symbol = productions[0][0];

  ////////////////////////////////////////////////////////////////////////////
  // Create the grammar and put it into canonical form
  ////////////////////////////////////////////////////////////////////////////
  Grammar G0( productions, number_of_productions, min_term, max_term,
              start_symbol, symbol_names);
  G = new Grammar( G0.makeCanonical());

  ////////////////////////////////////////////////////////////////////////////
  // Compile the grammar into tables.
  ////////////////////////////////////////////////////////////////////////////

  parserGen = new LALR1Gen;
  prec      = new OpPrecedence( *G);
  define_operator_precedence();
  parserGen->compile( *G, *prec);

  ////////////////////////////////////////////////////////////////////////////
  //
  // Process errors
  //
  ////////////////////////////////////////////////////////////////////////////

  process_parser_errors( expected_errors);

  ////////////////////////////////////////////////////////////////////////////
  //
  // Generate a report
  //
  ////////////////////////////////////////////////////////////////////////////
  if (options.generate_report)
  {
    std::ostream& log = open_logfile();
    log << "[Syntax class " << class_name << "]\n";
    parserGen->print_report( log, options.verbosity) << '\n';
  }

  gen_class_implementation( C, 
#line 1029 "parsegen.pcc"
#line 1029 "parsegen.pcc"
nil_1_
#line 1029 "parsegen.pcc"
#line 1029 "parsegen.pcc"
, EXTERNAL_INSTANTIATION);
}

////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the implementation of the parser class.
//
////////////////////////////////////////////////////////////////////////////

void SyntaxClass::gen_class_implementation( CodeGen& C, Tys tys, DefKind k)
{
   generate_parser_tables(C);             // encoded tables
   generate_debugging_tables(C);          // auxiliary tables for debugging
   generate_semantic_stack_definition(C); // semantic stack definition
   generate_action_driver(C);             // the action driver
   generate_parse_method(C);              // the main parse method
   generate_semantic_stack_adjustment(C); // how to adjust the stack
   generate_semantic_stack_growth(C);     // how to grow the stack
   gen_class_constructor( C, tys, k);     // constructor of this class
}

////////////////////////////////////////////////////////////////////////////
//
//  Method to process parser errors
//
////////////////////////////////////////////////////////////////////////////#

void SyntaxClass::process_parser_errors( ShiftReduceErrors expected_errors)
{
  int sr_conflicts = parserGen->shift_reduce_conflicts();
  int rr_conflicts = parserGen->reduce_reduce_conflicts();

  if (sr_conflicts > 0 && expected_errors < 0)
  {
    msg(
        expected_errors == -1 ? "%Lwarning: %i%s%s\n" : "%L%w%i%s%s\n",
        sr_conflicts, " shift/reduce conflicts in syntax class ",
        class_name
        );
  }

  if (expected_errors >= 0 && sr_conflicts != expected_errors)
  {
    msg("%L%wexpecting %i shift/reduce conflicts but found %i"
        " in syntax class %s\n",
        expected_errors, sr_conflicts, class_name);
  }

  if (rr_conflicts > 0)
  {
    msg("%L%w%i reduce/reduce conflicts in syntax class %s\n",
         rr_conflicts, class_name);
  }
}

//////////////////////////////////////////////////////////////////////////////
//
// Generate the semantic stack growing method
//
//////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_semantic_stack_growth( CodeGen& C)
{
  C.pr(
        "%^void %s::grow_semantic_stack()\n"
        "%^{%+"
        "%^int N = (stack_size__ + 1) * 2;"
        "%^%s_semantic_stack_type * S = new %s_semantic_stack_type [N];"
        "%^if (N >= LR1Parser::SEMANTIC_STACK_SIZE) "
        "%^   error_report(\"Warning: semantic stack overflow\");"
        "%^std::memcpy(S, bot__, sizeof(%s_semantic_stack_type) * (stack_size__ + 1));"
        "%^if (heap_allocated__) delete [] bot__;"
        "%^t__ = S + (t__ - bot__);"
        "%^bot__ = S;"
        "%^stack_size__ = N - 1;"
        "%^heap_allocated__ = 1;"
        "%-%^}\n\n",
        class_name, class_name, class_name, class_name
      );
}

//////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the stack adjustment method
//
//////////////////////////////////////////////////////////////////////////////

void SyntaxClass::generate_semantic_stack_adjustment(CodeGen& C)
{
  C.pr( "%^void %s::adjust_stack(int offset) { t__ += offset; }\n\n",
        class_name);
}

//////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the class constructor that initializes all
//  the parser tables.
//
//////////////////////////////////////////////////////////////////////////////

void SyntaxClass::gen_class_constructor_initializers( CodeGen& C, Tys, DefKind)
{
  Id id = class_name;
  C.pr(
        "%^  : Super(%s_base,%s_check,%s_def,%s_defact,%s_next,"
        "%^          %s_len,%s_ncount,%s_lhs,%s_equiv,%i,%i,%i)",
        id, id, id, id, id, id, id, id, id,
        (int)error_term, (int)max_term, (int)max_nonterm
      );
}
#line 1139 "parsegen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 72
Number of ifs generated      = 6
Number of switches generated = 11
Number of labels             = 1
Number of gotos              = 5
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
