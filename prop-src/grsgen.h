///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "grsgen.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "grsgen.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the graph rewriting system compiler.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef graph_rewriting_system_compiler_h
#define graph_rewriting_system_compiler_h

#include "basics.h"
#include "codegen.h"
#include "matchcom.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Forward type declarations
//
///////////////////////////////////////////////////////////////////////////////

#line 20 "grsgen.ph"
#line 20 "grsgen.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Pat
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Pat_defined
#define datatype_Pat_defined
  class a_Pat;
  typedef a_Pat * Pat;
#endif

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

#line 20 "grsgen.ph"
#line 20 "grsgen.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Abstract syntax for graph rewriting rules
//
///////////////////////////////////////////////////////////////////////////////

#line 28 "grsgen.ph"
#line 52 "grsgen.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for GraphRewritingRule
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_GraphRewritingRule_defined
#define datatype_GraphRewritingRule_defined
  class a_GraphRewritingRule;
  typedef a_GraphRewritingRule * GraphRewritingRule;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for GRSPat
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_GRSPat_defined
#define datatype_GRSPat_defined
  class a_GRSPat;
  typedef a_GRSPat * GRSPat;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for GRSConclusion
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_GRSConclusion_defined
#define datatype_GRSConclusion_defined
  class a_GRSConclusion;
  typedef a_GRSConclusion * GRSConclusion;
#endif

///////////////////////////////////////////////////////////////////////////////
// Definition of type GRSConclusions
///////////////////////////////////////////////////////////////////////////////
#line 51 "grsgen.ph"
typedef a_List<GRSConclusion> *  GRSConclusions;

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GraphRewritingRule::GRSrule
//
///////////////////////////////////////////////////////////////////////////////
class a_GraphRewritingRule : public Loc {
public:
#line 29 "grsgen.ph"
  GRSPat lhs; GRSConclusions rhs; 
  a_GraphRewritingRule (GRSPat x_lhs, GRSConclusions x_rhs);
};
inline int boxed(const a_GraphRewritingRule *) { return 1; }
inline int untag(const a_GraphRewritingRule *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for GraphRewritingRule
//
///////////////////////////////////////////////////////////////////////////////
extern a_GraphRewritingRule * GRSrule (GRSPat x_lhs, GRSConclusions x_rhs);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype GRSPat
//
///////////////////////////////////////////////////////////////////////////////
class a_GRSPat : public Loc {
public:
  enum Tag_GRSPat {
    tag_EDGEgpat = 0, tag_GUARDgpat = 1, tag_NOTgpat = 2, 
    tag_ANDgpat = 3, tag_ORgpat = 4, tag_FORALLgpat = 5
  };

public:
  const Tag_GRSPat tag__; // variant tag
protected:
  inline a_GRSPat(Tag_GRSPat t__) : tag__(t__) {}
public:
};
inline int boxed(const a_GRSPat *) { return 1; }
inline int untag(const a_GRSPat * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::EDGEgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_EDGEgpat : public a_GRSPat {
public:
#line 36 "grsgen.ph"
  Id _1; a_List<Pat> *  _2; 
  GRSPat_EDGEgpat (Id x_1, a_List<Pat> *  x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::GUARDgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_GUARDgpat : public a_GRSPat {
public:
#line 38 "grsgen.ph"
  Exp GUARDgpat; 
  GRSPat_GUARDgpat (Exp x_GUARDgpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::NOTgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_NOTgpat : public a_GRSPat {
public:
#line 39 "grsgen.ph"
  GRSPat NOTgpat; 
  GRSPat_NOTgpat (GRSPat x_NOTgpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::ANDgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_ANDgpat : public a_GRSPat {
public:
#line 40 "grsgen.ph"
  GRSPat _1; GRSPat _2; 
  GRSPat_ANDgpat (GRSPat x_1, GRSPat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::ORgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_ORgpat : public a_GRSPat {
public:
#line 41 "grsgen.ph"
  GRSPat _1; GRSPat _2; 
  GRSPat_ORgpat (GRSPat x_1, GRSPat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSPat::FORALLgpat
//
///////////////////////////////////////////////////////////////////////////////
class GRSPat_FORALLgpat : public a_GRSPat {
public:
#line 42 "grsgen.ph"
  Id _1; GRSPat _2; 
  GRSPat_FORALLgpat (Id x_1, GRSPat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for GRSPat
//
///////////////////////////////////////////////////////////////////////////////
extern a_GRSPat * EDGEgpat (Id x_1, a_List<Pat> *  x_2);
extern a_GRSPat * GUARDgpat (Exp x_GUARDgpat);
extern a_GRSPat * NOTgpat (GRSPat x_NOTgpat);
extern a_GRSPat * ANDgpat (GRSPat x_1, GRSPat x_2);
extern a_GRSPat * ORgpat (GRSPat x_1, GRSPat x_2);
extern a_GRSPat * FORALLgpat (Id x_1, GRSPat x_2);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype GRSConclusion
//
///////////////////////////////////////////////////////////////////////////////
class a_GRSConclusion : public Loc {
public:
  enum Tag_GRSConclusion {
    tag_ADDEDGEaction = 0, tag_DELETEEDGEaction = 1, tag_ADDNODEaction = 2, 
    tag_DELETENODEaction = 3, tag_EMBEDDEDaction = 4
  };

public:
  const Tag_GRSConclusion tag__; // variant tag
protected:
  inline a_GRSConclusion(Tag_GRSConclusion t__) : tag__(t__) {}
public:
};
inline int boxed(const a_GRSConclusion *) { return 1; }
inline int untag(const a_GRSConclusion * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSConclusion::ADDEDGEaction
//
///////////////////////////////////////////////////////////////////////////////
class GRSConclusion_ADDEDGEaction : public a_GRSConclusion {
public:
#line 44 "grsgen.ph"
  Id _1; a_List<Exp> *  _2; 
  GRSConclusion_ADDEDGEaction (Id x_1, a_List<Exp> *  x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSConclusion::DELETEEDGEaction
//
///////////////////////////////////////////////////////////////////////////////
class GRSConclusion_DELETEEDGEaction : public a_GRSConclusion {
public:
#line 46 "grsgen.ph"
  Id _1; a_List<Exp> *  _2; 
  GRSConclusion_DELETEEDGEaction (Id x_1, a_List<Exp> *  x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSConclusion::ADDNODEaction
//
///////////////////////////////////////////////////////////////////////////////
class GRSConclusion_ADDNODEaction : public a_GRSConclusion {
public:
#line 47 "grsgen.ph"
  Exp ADDNODEaction; 
  GRSConclusion_ADDNODEaction (Exp x_ADDNODEaction);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSConclusion::DELETENODEaction
//
///////////////////////////////////////////////////////////////////////////////
class GRSConclusion_DELETENODEaction : public a_GRSConclusion {
public:
#line 48 "grsgen.ph"
  Exp DELETENODEaction; 
  GRSConclusion_DELETENODEaction (Exp x_DELETENODEaction);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor GRSConclusion::EMBEDDEDaction
//
///////////////////////////////////////////////////////////////////////////////
class GRSConclusion_EMBEDDEDaction : public a_GRSConclusion {
public:
#line 49 "grsgen.ph"
  a_List<Decl> *  EMBEDDEDaction; 
  GRSConclusion_EMBEDDEDaction (a_List<Decl> *  x_EMBEDDEDaction);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for GRSConclusion
//
///////////////////////////////////////////////////////////////////////////////
extern a_GRSConclusion * ADDEDGEaction (Id x_1, a_List<Exp> *  x_2);
extern a_GRSConclusion * DELETEEDGEaction (Id x_1, a_List<Exp> *  x_2);
extern a_GRSConclusion * ADDNODEaction (Exp x_ADDNODEaction);
extern a_GRSConclusion * DELETENODEaction (Exp x_DELETENODEaction);
extern a_GRSConclusion * EMBEDDEDaction (a_List<Decl> *  x_EMBEDDEDaction);

#line 52 "grsgen.ph"
#line 52 "grsgen.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  The interface to the graph rewriting system compiler
//
///////////////////////////////////////////////////////////////////////////////

class GraphRewritingCompiler : virtual public CodeGen,
                               virtual public MatchCompiler
{
  GraphRewritingCompiler(const GraphRewritingCompiler&);
  void operator = (const GraphRewritingCompiler&);
public:
  GraphRewritingCompiler();
  ~GraphRewritingCompiler();

  void gen_graph_rewriting_system (Id, LabTys, 
#line 69 "grsgen.ph"
a_List<GraphRewritingRule> *  
#line 69 "grsgen.ph"
);
};

#endif
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
