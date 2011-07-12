///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "matchcom.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "matchcom.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the interface to the pattern matching compiler.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef match_compiler_h
#define match_compiler_h

#include <iostream>
#include "ir.h"
#include "ast.h"
#include "patenv.h"
#include "hashtab.h"
#include "labelgen.h"
#include "codegen.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Forward type declarations.
//
///////////////////////////////////////////////////////////////////////////////

class BitSet;       // bit sets

///////////////////////////////////////////////////////////////////////////////
//
//  Pattern matching decision tree (dag)
//
///////////////////////////////////////////////////////////////////////////////

struct MatchBase : public MEM
{
  int shared;
  Id label;
  MatchBase();
};

#line 40 "matchcom.ph"
#line 76 "matchcom.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Match
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Match_defined
#define datatype_Match_defined
  class a_Match;
  typedef a_Match * Match;
#endif

#  define FAILmatch 0
#  define DONTCAREmatch 1

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Cost
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Cost_defined
#define datatype_Cost_defined
  class a_Cost;
  typedef a_Cost * Cost;
#endif

#  define NOcost 0

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Pos
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Pos_defined
#define datatype_Pos_defined
  class a_Pos;
  typedef a_Pos * Pos;
#endif

#  define POSzero 0
#  define POSinfinity 1

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Match
//
///////////////////////////////////////////////////////////////////////////////
class a_Match : public MatchBase {
public:
  enum Tag_Match {
    tag_SUCCESSmatch = 0, tag_SUCCESSESmatch = 1, tag_COSTmatch = 2, 
    tag_GUARDmatch = 3, tag_LITERALmatch = 4, tag_RANGEmatch = 5, 
    tag_CONSmatch = 6, tag_TREECOSTmatch = 7, tag_TREELABELmatch = 8, 
    tag_BACKEDGEmatch = 9
  };

public:
  const Tag_Match tag__; // variant tag
protected:
  inline a_Match(Tag_Match t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Match * x) { return (unsigned long)x >= 2; }
inline int untag(const a_Match * x) { return boxed(x) ? x->tag__ + 2 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::SUCCESSmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_SUCCESSmatch : public a_Match {
public:
#line 42 "matchcom.ph"
  int _1; MatchRule _2; 
  Match_SUCCESSmatch (int x_1, MatchRule x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::SUCCESSESmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_SUCCESSESmatch : public a_Match {
public:
#line 43 "matchcom.ph"
  int _1; BitSet * _2; MatchRules _3; 
  Match_SUCCESSESmatch (int x_1, BitSet * x_2, MatchRules x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::COSTmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_COSTmatch : public a_Match {
public:
#line 44 "matchcom.ph"
  int _1; Cost * _2; BitSet * _3; MatchRules _4; 
  Match_COSTmatch (int x_1, Cost * x_2, BitSet * x_3, MatchRules x_4);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::GUARDmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_GUARDmatch : public a_Match {
public:
#line 45 "matchcom.ph"
  Exp _1; Match _2; Match _3; 
  Match_GUARDmatch (Exp x_1, Match x_2, Match x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::LITERALmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_LITERALmatch : public a_Match {
public:
#line 46 "matchcom.ph"
  Pos _1; Exp _2; Literal * _3; int _4; Match * _5; Match _6; 
  Match_LITERALmatch (Pos x_1, Exp x_2, Literal * x_3, int x_4, Match * x_5, Match x_6);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::RANGEmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_RANGEmatch : public a_Match {
public:
#line 47 "matchcom.ph"
  Pos _1; Exp _2; int _3; int _4; Match _5; Match _6; 
  Match_RANGEmatch (Pos x_1, Exp x_2, int x_3, int x_4, Match x_5, Match x_6);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::CONSmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_CONSmatch : public a_Match {
public:
#line 48 "matchcom.ph"
  Pos _1; Exp _2; Ty _3; Ty _4; int _5; Match * _6; Match _7; 
  Match_CONSmatch (Pos x_1, Exp x_2, Ty x_3, Ty x_4, int x_5, Match * x_6, Match x_7);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::TREECOSTmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_TREECOSTmatch : public a_Match {
public:
#line 50 "matchcom.ph"
  Match _1; BitSet * _2; MatchRules _3; 
  Match_TREECOSTmatch (Match x_1, BitSet * x_2, MatchRules x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::TREELABELmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_TREELABELmatch : public a_Match {
public:
#line 51 "matchcom.ph"
  Match _1; Ty _2; Ty _3; int _4; 
  Match_TREELABELmatch (Match x_1, Ty x_2, Ty x_3, int x_4);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Match::BACKEDGEmatch
//
///////////////////////////////////////////////////////////////////////////////
class Match_BACKEDGEmatch : public a_Match {
public:
#line 53 "matchcom.ph"
  int _1; Id _2; Match _3; 
  Match_BACKEDGEmatch (int x_1, Id x_2, Match x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Match
//
///////////////////////////////////////////////////////////////////////////////
extern a_Match * SUCCESSmatch (int x_1, MatchRule x_2);
extern a_Match * SUCCESSESmatch (int x_1, BitSet * x_2, MatchRules x_3);
extern a_Match * COSTmatch (int x_1, Cost * x_2, BitSet * x_3, MatchRules x_4);
extern a_Match * GUARDmatch (Exp x_1, Match x_2, Match x_3);
extern a_Match * LITERALmatch (Pos x_1, Exp x_2, Literal * x_3, int x_4, Match * x_5, Match x_6);
extern a_Match * RANGEmatch (Pos x_1, Exp x_2, int x_3, int x_4, Match x_5, Match x_6);
extern a_Match * CONSmatch (Pos x_1, Exp x_2, Ty x_3, Ty x_4, int x_5, Match * x_6, Match x_7);
extern a_Match * TREECOSTmatch (Match x_1, BitSet * x_2, MatchRules x_3);
extern a_Match * TREELABELmatch (Match x_1, Ty x_2, Ty x_3, int x_4);
extern a_Match * BACKEDGEmatch (int x_1, Id x_2, Match x_3);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Cost
//
///////////////////////////////////////////////////////////////////////////////
class a_Cost : public MEM {
public:
  enum Tag_Cost {
    tag_EXPcost = 0, tag_INTcost = 1
  };

public:
};
inline int boxed(const a_Cost * x) { return x != 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Embbeded tag extraction functions
//
///////////////////////////////////////////////////////////////////////////////
inline int untagp(const a_Cost * x)
  { return (unsigned long)x & 3; }
inline a_Cost * derefp(const a_Cost * x)
  { return (a_Cost*)((unsigned long)x & ~3); }
inline int untag(const a_Cost * x) { return x ? untagp(x)+1 : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Cost::EXPcost
//
///////////////////////////////////////////////////////////////////////////////
class Cost_EXPcost : public a_Cost {
public:
#line 62 "matchcom.ph"
  Exp _1; Ty _2; 
  Cost_EXPcost (Exp x_1, Ty x_2 = NOty);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Cost::INTcost
//
///////////////////////////////////////////////////////////////////////////////
class Cost_INTcost : public a_Cost {
public:
#line 63 "matchcom.ph"
  int INTcost; 
  Cost_INTcost (int x_INTcost);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Cost
//
///////////////////////////////////////////////////////////////////////////////
extern a_Cost * EXPcost (Exp x_1, Ty x_2 = NOty);
extern a_Cost * INTcost (int x_INTcost);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Pos
//
///////////////////////////////////////////////////////////////////////////////
class a_Pos : public MEM {
public:
  enum Tag_Pos {
    tag_POSint = 0, tag_POSlabel = 1, tag_POSadaptive = 2
  };

public:
};
inline int boxed(const a_Pos * x) { return (unsigned long)x >= 2; }
///////////////////////////////////////////////////////////////////////////////
//
// Embbeded tag extraction functions
//
///////////////////////////////////////////////////////////////////////////////
inline int untagp(const a_Pos * x)
  { return (unsigned long)x & 3; }
inline a_Pos * derefp(const a_Pos * x)
  { return (a_Pos*)((unsigned long)x & ~3); }
inline int untag(const a_Pos * x) { return boxed(x) ? untagp(x) + 2 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pos::POSint
//
///////////////////////////////////////////////////////////////////////////////
class Pos_POSint : public a_Pos {
public:
#line 73 "matchcom.ph"
  int _1; Pos _2; 
  Pos_POSint (int x_1, Pos x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pos::POSlabel
//
///////////////////////////////////////////////////////////////////////////////
class Pos_POSlabel : public a_Pos {
public:
#line 74 "matchcom.ph"
  Id _1; Pos _2; 
  Pos_POSlabel (Id x_1, Pos x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pos::POSadaptive
//
///////////////////////////////////////////////////////////////////////////////
class Pos_POSadaptive : public a_Pos {
public:
#line 75 "matchcom.ph"
  int _1; int * _2; Pos _3; 
  Pos_POSadaptive (int x_1, int * x_2, Pos x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Pos
//
///////////////////////////////////////////////////////////////////////////////
extern a_Pos * POSint (int x_1, Pos x_2);
extern a_Pos * POSlabel (Id x_1, Pos x_2);
extern a_Pos * POSadaptive (int x_1, int * x_2, Pos x_3);

#line 76 "matchcom.ph"
#line 76 "matchcom.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printer for matching trees.
//
///////////////////////////////////////////////////////////////////////////////

extern std::ostream& operator << (std::ostream&, Match);

///////////////////////////////////////////////////////////////////////////////
//
//  Function to reverse the polarity of a pattern.
//
///////////////////////////////////////////////////////////////////////////////

extern Polarity rev( Polarity);

///////////////////////////////////////////////////////////////////////////////
//
//  Function to compute the match variables for a list of match expressions.
//  Match variables are temporaries generated for complex expressions to
//  prevent redundent evaluations.
//
///////////////////////////////////////////////////////////////////////////////

extern void compute_match_variables( MatchExps);

///////////////////////////////////////////////////////////////////////////////
//
//  Function to convert a string into an array pattern.  This converts string
//  patterns to be decomposed into a web of character patterns, allowing
//  (potentially) more efficient matching.
//
///////////////////////////////////////////////////////////////////////////////

extern Pats make_string_pattern( const char *);

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to decorate the pattern for projection bindings.
//  These are called to annotate a pattern with pattern variable bindings.
//  The new bindings are entered into the pattern variable environments.
//  These are called from the parser.
//
///////////////////////////////////////////////////////////////////////////////

extern void decor( Pat, Exp, Polarity, Bool, PatternVarEnv&, int&);
extern void decor( MatchExps, Pat, Polarity, Bool, PatternVarEnv&, int&);
extern void decor( MatchExps&, Pat, PatternVarEnv&, int&, int = -1);

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to decorate the pattern for attribute and cost bindings
//  inside rewrite rules.  These are also called from the parser.
//
///////////////////////////////////////////////////////////////////////////////

extern int decor_rewrite( Pat,  int, int, PatternVarEnv&);
extern int decor_rewrite( Pats, int, int, PatternVarEnv&);
extern int decor_rewrite( Pat,  int, PatternVarEnv&);

///////////////////////////////////////////////////////////////////////////////
//
//  Auxiliary function to retrieve the position vector of a decision tree.
//  This is used during the pattern matching compilation process.
//
///////////////////////////////////////////////////////////////////////////////

extern Pos get_pos( Match);

///////////////////////////////////////////////////////////////////////////////
//
//  Auxiliary functions to compute information on a matching tree.
//  These are used during the pattern matching compilation process to
//  eliminate redundant tests and for error detection.
//
///////////////////////////////////////////////////////////////////////////////

Bool          refutable( Match);                  // Is the pattern refutable?
void          matchables( Match, BitSet&);        // Set of matchable rules.
void          always_matchables( Match, BitSet&); // Set of always matching
const BitSet& always_matchables( Match, int);     // rules.

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to perform substitutions on expressions.
//  All INDexp(i) nodes are substituted with the corresponding replacement.
//
///////////////////////////////////////////////////////////////////////////////

extern Exp     subst (Exp,     Exp replacements[]);
extern Exps    subst (Exps,    Exp replacements[]);
extern LabExps subst (LabExps, Exp replacements[]);

///////////////////////////////////////////////////////////////////////////////
//
//  Hashing and equality for literals.
//  These are used in the matching tree -> dag conversion process.
//
///////////////////////////////////////////////////////////////////////////////

extern unsigned int literal_hash  (HashTable::Key);
extern Bool         literal_equal (HashTable::Key, HashTable::Key);

///////////////////////////////////////////////////////////////////////////////
//
//  Hashing and equality for position vectors.
//  These are used in the matching tree -> dag conversion process.
//
///////////////////////////////////////////////////////////////////////////////

extern unsigned int pos_hash  (HashTable::Key);
extern Bool         pos_equal (HashTable::Key, HashTable::Key);

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to check for refutability of a pattern.  These are used
//  in the pattern sindexing scheme.
//
///////////////////////////////////////////////////////////////////////////////

extern Bool is_refutable  (Pat);
extern Bool is_refutable  (Pats);
extern Bool is_refutable  (LabPats);

///////////////////////////////////////////////////////////////////////////////
//
//  The current index map.  This map is computed when using the adaptive
//  pattern matching scheme.
//
///////////////////////////////////////////////////////////////////////////////

extern HashTable * current_index_map;

///////////////////////////////////////////////////////////////////////////////
//
//  Methods for compute indexing information of a pattern.  These are
//  used in the adaptive scheme.
//
///////////////////////////////////////////////////////////////////////////////

extern void indexing (int, Pat, Pos, HashTable&);
extern void indexing (int, Pats, Pos, HashTable&);
extern void indexing (MatchRules, HashTable&);

extern       Bool same_selectors;

extern Exp select (Exp, Cons, Ty = NOty);

///////////////////////////////////////////////////////////////////////////////
//
//   Equality on expressions.
//
///////////////////////////////////////////////////////////////////////////////

extern Bool equal (Exp, Exp);
extern Bool equal (Exps, Exps);
extern Bool equal (LabExps, LabExps);

///////////////////////////////////////////////////////////////////////////////
//
//  Substitution functions on patterns.  These are used to implement
//  pattern laws.
//
///////////////////////////////////////////////////////////////////////////////

extern Pat     subst (Pat,     Pat [], Bool);
extern Pats    subst (Pats,    Pat [], Bool);
extern LabPats subst (LabPats, Pat [], Bool);

///////////////////////////////////////////////////////////////////////////////
//
//  Methods to translate a match tree into an anotated tree with tree parsing
//  cost.
//
///////////////////////////////////////////////////////////////////////////////

extern Match translate_treecost (Match, MatchRules);

///////////////////////////////////////////////////////////////////////////////
//
//  Methods to enter and lookup a pattern constructor.
//  These interact with the pattern/constructor environment.
//  Called from the parser.
//
///////////////////////////////////////////////////////////////////////////////

extern Pat  apply_pat  (Pat, Pat);

///////////////////////////////////////////////////////////////////////////////
//
//  The following is the interface definition of the pattern matching compiler.
//
///////////////////////////////////////////////////////////////////////////////

class MatchCompiler : virtual public CodeGen
{
  MatchCompiler(const MatchCompiler&);    // no copy constructor
  void operator = (const MatchCompiler&); // no assignment

protected:
  LabelGen vars, labels;                         // labels generators
  int merges, ifs, switches, gotos, goto_labels; // match compiler statistics
  MatchOptions     current_options;
  MatchRule        current_rule;

  static HashTable quark_map;
  static LabelGen  quark_labels;

public:
  ////////////////////////////////////////////////////////////////////////////
  //
  //  Constructor and destructor
  //
  ////////////////////////////////////////////////////////////////////////////
           MatchCompiler();
  virtual ~MatchCompiler();

  static Id quark_name(Id);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to compute the selection/projection function from a datatype
  //  domain.  This is used in the pattern binding annotation process.
  //
  ////////////////////////////////////////////////////////////////////////////
  static Exp untag(Exp, Ty);
  static Exp untag_one(Exp, Cons);
  static Exp make_select (Exp, Cons, Ty = NOty, Id = 0);
  static Exp tag_name_of (Cons, Bool normalized);

protected:
  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to compile pattern matching.
  //
  ////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to for translation a pattern into a pattern matching tree.
  //
  ////////////////////////////////////////////////////////////////////////////
  Match trans          (Pat, Pos, Bool, Match, Match);
  Match trans          (Pats, int, Pos, Bool, Match, Match);
  Match trans          (Pats, Pos, Bool, Match, Match, int []);
  Match trans          (LabPats, Pos, Bool, Match, Match);
  Match trans_merge    (int, MatchRules, int, Cost *);
  Match trans_no_merge (int, int, MatchRules, int, Cost *);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to for tree composition/merging and tree to dag conversion.
  //
  ////////////////////////////////////////////////////////////////////////////
  Match compose        (Match, Match);
  Match merge          (Match, Match);
  Match make_dag       (Match, MatchOptions, MatchRules);
  Match match_of       (int, MatchRules, MatchOptions);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods for generating high level statements and trace instrumentation.
  //
  ////////////////////////////////////////////////////////////////////////////
  void gen_match_stmt              (MatchExps, MatchRules,
                                    MatchOptions = MATCHnone, Ty = NOty);
  void gen_fun_def                 (FunDefs);
  void gen_match_variables         (MatchExps, Ty);
  void gen                         (Match, MatchOptions=MATCHnone, Ty=NOty);
  void gen_matchall_suffix         (int, Match, MatchRules, Bool);
  void gen_match_cost_minimization (int, Match, MatchRules, Bool);
  void gen_success_match           (int, const BitSet *, MatchRules);
  void gen_cost_success_match      (int, const BitSet *, MatchRules);
  virtual void gen_treecost_match  (Match, const BitSet *, MatchRules) = 0;
  virtual void gen_treelabel_match (Match, Ty, Ty, int) = 0;

  void instrument_trace            (MatchRules);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Method for generating range matching
  //
  ////////////////////////////////////////////////////////////////////////////
  void gen_range_match (Pos, Exp, int, int, Match, Match, Match);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Method for generating view matching
  //
  ////////////////////////////////////////////////////////////////////////////
  void gen_view_match (Id, Exp, Exp, int, Cons [], Match [], Match,
                       TyOpt, TyQual);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Low level methods for specific pattern matching constructs:
  //  C/C++ switches, binary search on literals, regular expression matching,
  //  and quarks matching code.
  //
  ////////////////////////////////////////////////////////////////////////////
  void gen_switch  (Id, Exp, Ty, int, Cons [], Match [], Match, int shared,
                    Bool, Bool, TyOpt, Bool);
  void gen_binary_search_on_literals(Exp, int, Literal [], Match [], Match);
  void gen_regexp_match
       (Exp, int, Literal [], Match [], Match, MatchOptions, Ty);
  void gen_quark_match
       (Exp, int, Literal [], Match [], Match, MatchOptions);

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to generating debugging code.
  //
  ////////////////////////////////////////////////////////////////////////////
  int current_rule_line () const;
  const char * current_rule_text () const;

private:
  ///////////////////////////////////////////////////////////////////////////////
  //
  //  Functions for allocating arrays of Literal and Match.
  //  Used during the pattern matching compilation process.
  //
  ///////////////////////////////////////////////////////////////////////////////
  Literal * Literals (int);
  Match *   Matches  (int);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Object to mark the current rule
//
///////////////////////////////////////////////////////////////////////////////

class MarkCurrentRule
{
  MarkCurrentRule();
  MarkCurrentRule(const MarkCurrentRule&);
  void operator = (const MarkCurrentRule&);
  MatchRule& current_rule;
  MatchRule  old_rule;
protected:
  MarkCurrentRule(MatchRule&, MatchRule);
  ~MarkCurrentRule();
  friend class MatchCompiler;
  friend class RewritingCompiler;
};

#endif
#line 426 "matchcom.ph"
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
