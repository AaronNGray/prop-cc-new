///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "aggen.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "aggen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the attribute grammar generator.
//
///////////////////////////////////////////////////////////////////////////////

#include "basics.h"
#include "ir.h"
#include "codegen.h"
#include "classdef.h"
#include "aggen.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent an attribute grammar class
//
///////////////////////////////////////////////////////////////////////////////

AttributeGrammarClass::AttributeGrammarClass
  (Id name, Inherits i, TyQual q, Decls decls)
  : SyntaxClass( ATTRIBUTE_GRAMMAR_CLASS, name, i, q, decls)
  {}

AttributeGrammarClass::~AttributeGrammarClass() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the class interface
//
///////////////////////////////////////////////////////////////////////////////

void AttributeGrammarClass::gen_class_interface( CodeGen& C)
{
  SyntaxClass::gen_class_interface(C);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the class implementation
//
///////////////////////////////////////////////////////////////////////////////

void AttributeGrammarClass::gen_class_implementation
   (CodeGen& C, Tys tys, DefKind k)
{
  SyntaxClass::gen_class_implementation( C, tys, k);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor/destructor of the attribute grammar compiler
//
///////////////////////////////////////////////////////////////////////////////

AttributeGrammarCompiler::AttributeGrammarCompiler() {}
AttributeGrammarCompiler::~AttributeGrammarCompiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the attribute grammar
//
///////////////////////////////////////////////////////////////////////////////

void AttributeGrammarCompiler::gen_attribute_grammar( Id id, GramExp e)
{
  AttributeGrammarClass * C =
    (AttributeGrammarClass*)
      ClassDefinition::lookup_class(
	    ClassDefinition::ATTRIBUTE_GRAMMAR_CLASS,id);
  if (C)
    C->gen_parser(*this,e);
}
#line 73 "aggen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
