///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "parsegen.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "parsegen.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file contains the definitions used in the parser generator
//  and meta syntax compiler.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef parser_generator_h
#define parser_generator_h

#include <AD/automata/grammar.h>
#include "basics.h"
#include "ir.h"
#include "codegen.h"
#include "classdef.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Forward declarations
//
///////////////////////////////////////////////////////////////////////////////

class Grammar;      // grammar class
class LALR1Gen;     // lalr1 parser class
class OpPrecedence; // operator precedence class

#line 27 "parsegen.ph"
#line 78 "parsegen.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Exp
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Exp_defined
#define datatype_Exp_defined
  class a_Exp;
  typedef a_Exp * Exp;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Decl
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Decl_defined
#define datatype_Decl_defined
  class a_Decl;
  typedef a_Decl * Decl;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for GramExp
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_GramExp_defined
#define datatype_GramExp_defined
  class a_GramExp;
  typedef a_GramExp * GramExp;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for BNF
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_BNF_defined
#define datatype_BNF_defined
  class a_BNF;
  typedef a_BNF * BNF;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for PrecRule
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_PrecRule_defined
#define datatype_PrecRule_defined
  class a_PrecRule;
  typedef a_PrecRule * PrecRule;
#endif

enum PrecMode {
  LEFTassoc = 0, RIGHTassoc = 1, NONassoc = 2
};



///////////////////////////////////////////////////////////////////////////////
// Definition of type ProductionSymbols
///////////////////////////////////////////////////////////////////////////////
#line 73 "parsegen.ph"
typedef a_List<ProductionSymbol> *  ProductionSymbols;

///////////////////////////////////////////////////////////////////////////////
// Definition of type PrecRules
///////////////////////////////////////////////////////////////////////////////
#line 74 "parsegen.ph"
typedef a_List<PrecRule> *  PrecRules;

///////////////////////////////////////////////////////////////////////////////
// Definition of type BNFs
///////////////////////////////////////////////////////////////////////////////
#line 75 "parsegen.ph"
typedef a_List<BNF> *  BNFs;

///////////////////////////////////////////////////////////////////////////////
// Definition of type GramExps
///////////////////////////////////////////////////////////////////////////////
#line 76 "parsegen.ph"
typedef a_List<GramExp> *  GramExps;

///////////////////////////////////////////////////////////////////////////////
// Definition of type ShiftReduceErrors
///////////////////////////////////////////////////////////////////////////////
#line 77 "parsegen.ph"
typedef int ShiftReduceErrors;

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype GramExp
//
///////////////////////////////////////////////////////////////////////////////
class a_GramExp : public Loc {
public:
  enum Tag_GramExp {
    tag_EXPgram = 0, tag_POLYgram = 1, tag_UNIONgram = 2, 
    tag_RESTRICTgram = 3, tag_APPgram = 4
  };

public:
  const Tag_GramExp tag__; // variant tag
protected:
  inline a_GramExp(Tag_GramExp t__) : tag__(t__) {}
public:
};
inline int boxed(const a_GramExp *) { return 1; }
inline int untag(const a_GramExp * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GramExp::EXPgram
//
///////////////////////////////////////////////////////////////////////////////
class GramExp_EXPgram : public a_GramExp {
public:
#line 36 "parsegen.ph"
  a_List<PrecRule> *  _1; ShiftReduceErrors _2; a_List<BNF> *  _3; 
  GramExp_EXPgram (a_List<PrecRule> *  x_1, ShiftReduceErrors x_2, a_List<BNF> *  x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GramExp::POLYgram
//
///////////////////////////////////////////////////////////////////////////////
class GramExp_POLYgram : public a_GramExp {
public:
#line 38 "parsegen.ph"
  int _1; Id * _2; GramExp _3; 
  GramExp_POLYgram (int x_1, Id * x_2, GramExp x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GramExp::UNIONgram
//
///////////////////////////////////////////////////////////////////////////////
class GramExp_UNIONgram : public a_GramExp {
public:
#line 39 "parsegen.ph"
  GramExp _1; GramExp _2; 
  GramExp_UNIONgram (GramExp x_1, GramExp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GramExp::RESTRICTgram
//
///////////////////////////////////////////////////////////////////////////////
class GramExp_RESTRICTgram : public a_GramExp {
public:
#line 40 "parsegen.ph"
  GramExp RESTRICTgram; 
  GramExp_RESTRICTgram (GramExp x_RESTRICTgram);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GramExp::APPgram
//
///////////////////////////////////////////////////////////////////////////////
class GramExp_APPgram : public a_GramExp {
public:
#line 41 "parsegen.ph"
  GramExp _1; GramExp _2; 
  GramExp_APPgram (GramExp x_1, GramExp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for GramExp
//
///////////////////////////////////////////////////////////////////////////////
extern a_GramExp * EXPgram (a_List<PrecRule> *  x_1, ShiftReduceErrors x_2, a_List<BNF> *  x_3);
extern a_GramExp * POLYgram (int x_1, Id * x_2, GramExp x_3);
extern a_GramExp * UNIONgram (GramExp x_1, GramExp x_2);
extern a_GramExp * RESTRICTgram (GramExp x_RESTRICTgram);
extern a_GramExp * APPgram (GramExp x_1, GramExp x_2);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor BNF::BNFrule
//
///////////////////////////////////////////////////////////////////////////////
class a_BNF : public Loc {
public:
#line 49 "parsegen.ph"
  Id _1; Ty _2; a_List<ProductionSymbols> *  _3; 
  a_BNF (Id x_1, Ty x_2, a_List<ProductionSymbols> *  x_3);
};
inline int boxed(const a_BNF *) { return 1; }
inline int untag(const a_BNF *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for BNF
//
///////////////////////////////////////////////////////////////////////////////
extern a_BNF * BNFrule (Id x_1, Ty x_2, a_List<ProductionSymbols> *  x_3);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor PrecRule::PRECrule
//
///////////////////////////////////////////////////////////////////////////////
class a_PrecRule : public Loc {
public:
#line 57 "parsegen.ph"
  PrecMode _1; int _2; ProductionSymbols _3; 
  a_PrecRule (PrecMode x_1, int x_2, ProductionSymbols x_3);
};
inline int boxed(const a_PrecRule *) { return 1; }
inline int untag(const a_PrecRule *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for PrecRule
//
///////////////////////////////////////////////////////////////////////////////
extern a_PrecRule * PRECrule (PrecMode x_1, int x_2, ProductionSymbols x_3);


#line 78 "parsegen.ph"
#line 78 "parsegen.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing methods.
//
///////////////////////////////////////////////////////////////////////////////

extern std::ostream& operator << (std::ostream&, ProductionSymbol);
extern std::ostream& operator << (std::ostream&, ProductionSymbols);
extern std::ostream& operator << (std::ostream&, PrecRule);
extern std::ostream& operator << (std::ostream&, PrecRules);
extern std::ostream& operator << (std::ostream&, BNF);
extern std::ostream& operator << (std::ostream&, BNFs);
extern std::ostream& operator << (std::ostream&, GramExp);
extern std::ostream& operator << (std::ostream&, GramExps);

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent a syntax class
//
///////////////////////////////////////////////////////////////////////////////

class SyntaxClass : public ClassDefinition
{
  SyntaxClass(const SyntaxClass&);
  void operator = (const SyntaxClass&);

public:

  typedef Grammar::Terminal    Terminal;
  typedef Grammar::NonTerminal NonTerminal;
  typedef Grammar::Action      Action;
  typedef Grammar::Production  Production;

protected:

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Internal data for generating a parser
  //
  ////////////////////////////////////////////////////////////////////////////
  BNFs                 production_rules;       // production rules
  PrecRules            precedence_rules;       // precedence rules
  Production *         productions;            // products array
  Grammar *            G;                      // Grammar object
  LALR1Gen *           parserGen;              // Parser generator object
  OpPrecedence *       prec;                   // operator precedence object
  int                  number_of_productions;  // Number of productions
  HashTable            nonterm_map;            // map nonterm -> Nonterminal
  HashTable            action_map;             // map Action -> Decls
  HashTable            inner_action_map;       //
  HashTable            line_map;               // map Action -> line#
  HashTable            predicate_map;          // ??
  Terminal             min_term;               // min Terminal #
  Terminal             max_term;               // max Terminal #
  Terminal             error_term;             // error Terminal #
  NonTerminal          max_nonterm;            // max NonTerminal #
  NonTerminal          start_symbol;           // start symbol of grammar
  Action               min_action;             // min Action #
  Id *                 symbol_names;           // map NonTerminal -> Id
  Ty *                 ty_map;                 // map NonTerminal -> Ty

public:
  SyntaxClass( CLASS_TYPE, Id, Inherits, TyQual, Decls);
  ~SyntaxClass();

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to generate a syntax class
  //
  ////////////////////////////////////////////////////////////////////////////

  virtual void gen_parser( CodeGen&, GramExp);
  virtual void gen_class_interface( CodeGen&);
  virtual void gen_class_implementation( CodeGen&, Tys, DefKind);

private:
  // compile a set of rules
  virtual void compile_rules( CodeGen&, PrecRules, ShiftReduceErrors, BNFs);
  // compile a grammar expression
  virtual void compile_grammar( CodeGen&, GramExp);

  // Various phases of the compilation process
  void initialize();
  void cleanup();
  void preprocess_grammar();
  void translate_into_grammar();
  void define_operator_precedence();
  void process_parser_errors(ShiftReduceErrors);

  // Various phases of the code generation process
  void generate_semantic_stack_definition( CodeGen&);
  void generate_semantic_stack_growth( CodeGen&);
  void generate_semantic_stack_adjustment( CodeGen&);
  void generate_debugging_tables( CodeGen&);
  void generate_parse_method( CodeGen&);
  void generate_parser_tables( CodeGen&);
  void generate_action_driver( CodeGen&);
  virtual void generate_semantic_actions( CodeGen&);

  virtual void gen_class_constructor_initializers( CodeGen&, Tys, DefKind);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Definition of the parser generator
//
///////////////////////////////////////////////////////////////////////////////

class ParserCompiler : virtual public CodeGen
{
  ParserCompiler( const ParserCompiler&);  // no copy constructor
  void operator = ( const ParserCompiler&); // no assignment

public:
  ParserCompiler();
  ~ParserCompiler();

  ////////////////////////////////////////////////////////////////////////////
  //  Method to generate a syntax class
  ////////////////////////////////////////////////////////////////////////////
  virtual void  gen_parser( Id, GramExp);
};

#endif
#line 204 "parsegen.ph"
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
