///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "ir.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "ir.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file contains the definitions for the intermediate data structures
//  used within the Prop -> C++ translator.  Definitions for types, patterns,
//  decision trees, and pretty printing formats are located here.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef intermediate_representations_h
#define intermediate_representations_h

#include "basics.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Forward datatype declarations
//
///////////////////////////////////////////////////////////////////////////////

#line 20 "ir.ph"
#line 20 "ir.ph"
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
// Forward class definition for Stmt
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Stmt_defined
#define datatype_Stmt_defined
  class a_Stmt;
  typedef a_Stmt * Stmt;
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
// Forward class definition for MatchRule
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_MatchRule_defined
#define datatype_MatchRule_defined
  class a_MatchRule;
  typedef a_MatchRule * MatchRule;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for CollectionDesc
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_CollectionDesc_defined
#define datatype_CollectionDesc_defined
  class a_CollectionDesc;
  typedef a_CollectionDesc * CollectionDesc;
#endif

#line 20 "ir.ph"
#line 20 "ir.ph"


class GraphTypeDef;
class EdgeDef;
class NodeDef;
class DatatypeHierarchy;
class DatatypeClass;

///////////////////////////////////////////////////////////////////////////////
//
//  Qualifiers determines various implementation characteristics
//  of the type.
//
///////////////////////////////////////////////////////////////////////////////

enum
{
  QUALnone          = 0,      // no qualifiers
  QUALprintable     = 1<<0,   // pretty printable
  QUALtracable      = 1<<1,   // reference countable
  QUALcollectable   = 1<<2,   // garbage collectable
  QUALrewritable    = 1<<3,   // rewritable
  QUALrelation      = 1<<4,   // a relation
  QUALpersistent    = 1<<5,   // persistent type
  QUALclass         = 1<<6,   // class type
  QUALconst         = 1<<7,   // const
  QUALunsigned      = 1<<8,   // unsigned
  QUALsigned        = 1<<9,   // signed
  QUALvirtual       = 1<<10,  // virtual inheritance
  QUALextensible    = 1<<11,  // extensible type
  QUALview          = 1<<12,  // a view
  QUALunifiable     = 1<<13,  // an unifiable term
  QUALtaggedpointer = 1<<14,  // use tagged pointers for representation
  QUALunboxed       = 1<<15,  // use unboxed presentation if possible
  QUALfinalizable   = 1<<16,  // object should be finalized
  QUALapplicative   = 1<<17,  // applicative rewrite
  QUALtreeparser    = 1<<18,  // tree parsing
  QUALparser        = 1<<19,  // parser class
  QUALlexeme        = 1<<20,  // usable as tokens
  QUALbitfield      = 1<<21,  // an opcode or opcode bitfield
  QUALtopdown       = 1<<22,  // use topdown tree matching in rewriting
  QUALvariable      = 1<<23,  // unifiable variable
  QUALgraphtype     = 1<<24,  // a graph type
  QUALgraphnode     = 1<<25,  // a graph node
  QUALgraphedge     = 1<<26,  // a graph edge
  QUALvirtualdestr  = 1<<27,  // virtual destructor
  QUALinline        = 1<<28,  // inline methods
  QUALextern        = 1<<29   // noninline methods
};

///////////////////////////////////////////////////////////////////////////////
//
//  Optimization options
//
///////////////////////////////////////////////////////////////////////////////

enum
{
  OPTnone          = 0,     // no optimization
  OPTtagless       = 1<<0,  // omit the embedded variant tag
  OPTsubclassless  = 1<<1,  // omit the subclass hierarchy
  OPTbaseclassless = 1<<2,  // omit inheritance from base class
  OPTtaggedpointer = 1<<3,  // embedded the variant tag in lower bits
                            // of the pointer.
  OPTunboxed       = 1<<4,  // use unboxed representation if possible
  OPTtaggedvar     = 1<<5   // tagged variables
};

///////////////////////////////////////////////////////////////////////////////
//
//  Scoping
//
///////////////////////////////////////////////////////////////////////////////

#line 94 "ir.ph"
#line 377 "ir.ph"
enum Scope {
  PRIVATEscope = 0, PROTECTEDscope = 1, PUBLICscope = 2
};



enum Parameter {
  TYbody = 0, TYformal = 1, TYsimpleformal = 2, 
  TYactual = 3
};



enum Polarity {
  ISpositive = 0, ISnegative = 1, ISneither = 2
};



///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Ty
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Ty_defined
#define datatype_Ty_defined
  class a_Ty;
  typedef a_Ty * Ty;
#endif

#  define v_NOty 0

#  define NOty (Ty)v_NOty

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for TyCon
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_TyCon_defined
#define datatype_TyCon_defined
  class a_TyCon;
  typedef a_TyCon * TyCon;
#endif

#  define v_POINTERtycon 0
#  define v_REFtycon 1
#  define v_TUPLEtycon 2
#  define v_EXTUPLEtycon 3
#  define v_FUNtycon 4
#  define v_TYPEtycon 5

#  define POINTERtycon (TyCon)v_POINTERtycon
#  define REFtycon (TyCon)v_REFtycon
#  define TUPLEtycon (TyCon)v_TUPLEtycon
#  define EXTUPLEtycon (TyCon)v_EXTUPLEtycon
#  define FUNtycon (TyCon)v_FUNtycon
#  define TYPEtycon (TyCon)v_TYPEtycon

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

#  define v_NOpat 0

#  define NOpat (Pat)v_NOpat

enum LogicalPat {
  NOTpat = 0, ANDpat = 1, ORpat = 2, 
  EQUIVpat = 3, XORpat = 4, IMPLIESpat = 5
};



///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Literal
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Literal_defined
#define datatype_Literal_defined
  class a_Literal;
  typedef a_Literal * Literal;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Cons
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Cons_defined
#define datatype_Cons_defined
  class a_Cons;
  typedef a_Cons * Cons;
#endif

#  define v_NOcons 0

#  define NOcons (Cons)v_NOcons

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for ProductionSymbol
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_ProductionSymbol_defined
#define datatype_ProductionSymbol_defined
  class a_ProductionSymbol;
  typedef a_ProductionSymbol * ProductionSymbol;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Pid
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Pid_defined
#define datatype_Pid_defined
  class a_Pid;
  typedef a_Pid * Pid;
#endif

#  define v_PERSISTnone 0

#  define PERSISTnone (Pid)v_PERSISTnone

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Inherit
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Inherit_defined
#define datatype_Inherit_defined
  class a_Inherit;
  typedef a_Inherit * Inherit;
#endif

///////////////////////////////////////////////////////////////////////////////
// Definition of type TyQual
///////////////////////////////////////////////////////////////////////////////
#line 364 "ir.ph"
typedef int TyQual;

///////////////////////////////////////////////////////////////////////////////
// Definition of type TyOpt
///////////////////////////////////////////////////////////////////////////////
#line 365 "ir.ph"
typedef int TyOpt;

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabTy
///////////////////////////////////////////////////////////////////////////////
#line 366 "ir.ph"
typedef struct { Id label; Ty ty;  } LabTy;

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabPat
///////////////////////////////////////////////////////////////////////////////
#line 367 "ir.ph"
typedef struct { Id label; Pat pat;  } LabPat;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Inherits
///////////////////////////////////////////////////////////////////////////////
#line 368 "ir.ph"
typedef a_List<Inherit> *  Inherits;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Conses
///////////////////////////////////////////////////////////////////////////////
#line 369 "ir.ph"
typedef a_List<Cons> *  Conses;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Tys
///////////////////////////////////////////////////////////////////////////////
#line 370 "ir.ph"
typedef a_List<Ty> *  Tys;

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabTys
///////////////////////////////////////////////////////////////////////////////
#line 371 "ir.ph"
typedef a_List<LabTy> *  LabTys;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Pats
///////////////////////////////////////////////////////////////////////////////
#line 372 "ir.ph"
typedef a_List<Pat> *  Pats;

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabPats
///////////////////////////////////////////////////////////////////////////////
#line 373 "ir.ph"
typedef a_List<LabPat> *  LabPats;

///////////////////////////////////////////////////////////////////////////////
// Definition of type TyVar
///////////////////////////////////////////////////////////////////////////////
#line 374 "ir.ph"
typedef Id TyVar;

///////////////////////////////////////////////////////////////////////////////
// Definition of type TyVars
///////////////////////////////////////////////////////////////////////////////
#line 375 "ir.ph"
typedef a_List<TyVar> *  TyVars;

///////////////////////////////////////////////////////////////////////////////
// Definition of type PrintFormats
///////////////////////////////////////////////////////////////////////////////
#line 376 "ir.ph"
typedef a_List<ProductionSymbol> *  PrintFormats;




///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Ty
//
///////////////////////////////////////////////////////////////////////////////
class a_Ty : public MEM {
public:
  enum Tag_Ty {
    tag_VARty = 0, tag_INDty = 1, tag_QUALty = 2, 
    tag_TYCONty = 3, tag_POLYty = 4, tag_DEFVALty = 5, 
    tag_NESTEDty = 6
  };

public:
  const Tag_Ty tag__; // variant tag
protected:
  inline a_Ty(Tag_Ty t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Ty * x) { return x != 0; }
inline int untag(const a_Ty * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::VARty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_VARty : public a_Ty {
public:
#line 131 "ir.ph"
  Ty VARty; 
  Ty_VARty (Ty x_VARty);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::INDty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_INDty : public a_Ty {
public:
#line 132 "ir.ph"
  Id _1; int _2; 
  Ty_INDty (Id x_1, int x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::QUALty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_QUALty : public a_Ty {
public:
#line 133 "ir.ph"
  TyQual _1; Ty _2; 
  Ty_QUALty (TyQual x_1, Ty x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::TYCONty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_TYCONty : public a_Ty {
public:
#line 134 "ir.ph"
  TyCon _1; a_List<Ty> *  _2; 
  Ty_TYCONty (TyCon x_1, a_List<Ty> *  x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::POLYty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_POLYty : public a_Ty {
public:
#line 135 "ir.ph"
  Ty _1; int _2; TyVar * _3; 
  Ty_POLYty (Ty x_1, int x_2, TyVar * x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::DEFVALty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_DEFVALty : public a_Ty {
public:
#line 136 "ir.ph"
  Ty _1; Exp _2; 
  Ty_DEFVALty (Ty x_1, Exp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Ty::NESTEDty
//
///////////////////////////////////////////////////////////////////////////////
class Ty_NESTEDty : public a_Ty {
public:
#line 137 "ir.ph"
  Ty _1; Ty _2; 
  Ty_NESTEDty (Ty x_1, Ty x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Ty
//
///////////////////////////////////////////////////////////////////////////////
extern a_Ty * VARty (Ty x_VARty);
extern a_Ty * INDty (Id x_1, int x_2);
extern a_Ty * QUALty (TyQual x_1, Ty x_2);
extern a_Ty * TYCONty (TyCon x_1, a_List<Ty> *  x_2);
extern a_Ty * POLYty (Ty x_1, int x_2, TyVar * x_3);
extern a_Ty * DEFVALty (Ty x_1, Exp x_2);
extern a_Ty * NESTEDty (Ty x_1, Ty x_2);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype TyCon
//
///////////////////////////////////////////////////////////////////////////////
class a_TyCon : public MEM {
public:
  enum Tag_TyCon {
    tag_IDtycon = 0, tag_RECORDtycon = 1, tag_ARRAYtycon = 2, 
    tag_BITFIELDtycon = 3, tag_DATATYPEtycon = 4, tag_COLtycon = 5, 
    tag_GRAPHtycon = 6, tag_NODEtycon = 7, tag_EDGEtycon = 8
  };

public:
  const Tag_TyCon tag__; // variant tag
protected:
  inline a_TyCon(Tag_TyCon t__) : tag__(t__) {}
public:
};
inline int boxed(const a_TyCon * x) { return (unsigned long)x >= 6; }
inline int untag(const a_TyCon * x) { return boxed(x) ? x->tag__ + 6 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::IDtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_IDtycon : public a_TyCon {
public:
#line 148 "ir.ph"
  Id IDtycon; 
  TyCon_IDtycon (Id x_IDtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::RECORDtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_RECORDtycon : public a_TyCon {
public:
#line 153 "ir.ph"
  a_List<Id> *  _1; Bool _2; 
  TyCon_RECORDtycon (a_List<Id> *  x_1, Bool x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::ARRAYtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_ARRAYtycon : public a_TyCon {
public:
#line 154 "ir.ph"
  Exp ARRAYtycon; 
  TyCon_ARRAYtycon (Exp x_ARRAYtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::BITFIELDtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_BITFIELDtycon : public a_TyCon {
public:
#line 155 "ir.ph"
  int width; Bool is_signed; 
  TyCon_BITFIELDtycon (int x_width, Bool x_is_signed = false);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::DATATYPEtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_DATATYPEtycon : public a_TyCon {
public:
#line 160 "ir.ph"
  Id id; int unit; int arg; Cons * terms; TyVars tyvars; Ty polyty; a_List<Inherit> *  inherit; TyQual qualifiers; TyOpt opt; a_List<Decl> *  body; Exp view_match; Loc const * location; DatatypeHierarchy * hierarchy; 
  TyCon_DATATYPEtycon (Id x_id, int x_unit, int x_arg, Cons * x_terms, TyVars x_tyvars, Ty x_polyty, a_List<Inherit> *  x_inherit, TyQual x_qualifiers, TyOpt x_opt, a_List<Decl> *  x_body, Exp x_view_match, Loc const * x_location, DatatypeHierarchy * x_hierarchy = 0);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::COLtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_COLtycon : public a_TyCon {
public:
#line 176 "ir.ph"
  CollectionDesc COLtycon; 
  TyCon_COLtycon (CollectionDesc x_COLtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::GRAPHtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_GRAPHtycon : public a_TyCon {
public:
#line 177 "ir.ph"
  GraphTypeDef * GRAPHtycon; 
  TyCon_GRAPHtycon (GraphTypeDef * x_GRAPHtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::NODEtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_NODEtycon : public a_TyCon {
public:
#line 178 "ir.ph"
  NodeDef * NODEtycon; 
  TyCon_NODEtycon (NodeDef * x_NODEtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TyCon::EDGEtycon
//
///////////////////////////////////////////////////////////////////////////////
class TyCon_EDGEtycon : public a_TyCon {
public:
#line 179 "ir.ph"
  EdgeDef * EDGEtycon; 
  TyCon_EDGEtycon (EdgeDef * x_EDGEtycon);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for TyCon
//
///////////////////////////////////////////////////////////////////////////////
extern a_TyCon * IDtycon (Id x_IDtycon);
extern a_TyCon * RECORDtycon (a_List<Id> *  x_1, Bool x_2);
extern a_TyCon * ARRAYtycon (Exp x_ARRAYtycon);
extern a_TyCon * BITFIELDtycon (int x_width, Bool x_is_signed = false);
extern a_TyCon * DATATYPEtycon (Id x_id, int x_unit, int x_arg, Cons * x_terms, TyVars x_tyvars, Ty x_polyty, a_List<Inherit> *  x_inherit, TyQual x_qualifiers, TyOpt x_opt, a_List<Decl> *  x_body, Exp x_view_match, Loc const * x_location, DatatypeHierarchy * x_hierarchy = 0);
extern a_TyCon * COLtycon (CollectionDesc x_COLtycon);
extern a_TyCon * GRAPHtycon (GraphTypeDef * x_GRAPHtycon);
extern a_TyCon * NODEtycon (NodeDef * x_NODEtycon);
extern a_TyCon * EDGEtycon (EdgeDef * x_EDGEtycon);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Pat
//
///////////////////////////////////////////////////////////////////////////////
class a_Pat : public MEM {
public:
  enum Tag_Pat {
    tag_WILDpat = 0, tag_INDpat = 1, tag_POLYpat = 2, 
    tag_IDpat = 3, tag_CONSpat = 4, tag_APPpat = 5, 
    tag_TYPEDpat = 6, tag_ASpat = 7, tag_LITERALpat = 8, 
    tag_CONTEXTpat = 9, tag_LEXEMEpat = 10, tag_ARRAYpat = 11, 
    tag_TUPLEpat = 12, tag_EXTUPLEpat = 13, tag_RECORDpat = 14, 
    tag_LISTpat = 15, tag_VECTORpat = 16, tag_APPENDpat = 17, 
    tag_GUARDpat = 18, tag_LOGICALpat = 19, tag_BACKEDGEpat = 20, 
    tag_UNIFYpat = 21, tag_MARKEDpat = 22
  };

public:
  const Tag_Pat tag__; // variant tag
protected:
  inline a_Pat(Tag_Pat t__) : tag__(t__) {}
public:
#line 226 "ir.ph"
 Exp selector; Ty ty; 
#line 226 "ir.ph"
};
inline int boxed(const a_Pat * x) { return x != 0; }
inline int untag(const a_Pat * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::WILDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_WILDpat : public a_Pat {
public:
#line 189 "ir.ph"
  
  Pat_WILDpat ();
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::INDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_INDpat : public a_Pat {
public:
#line 190 "ir.ph"
  Id _1; int _2; Ty _3; 
  Pat_INDpat (Id x_1, int x_2, Ty x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::POLYpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_POLYpat : public a_Pat {
public:
#line 191 "ir.ph"
  Id _1; int _2; Ids _3; Pat _4; Exp _5; Bool _6; 
  Pat_POLYpat (Id x_1, int x_2, Ids x_3, Pat x_4, Exp x_5, Bool x_6);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::IDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_IDpat : public a_Pat {
public:
#line 192 "ir.ph"
  Id _1; Ty _2; Exp _3; 
  Pat_IDpat (Id x_1, Ty x_2, Exp x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::CONSpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_CONSpat : public a_Pat {
public:
#line 193 "ir.ph"
  Cons CONSpat; 
  Pat_CONSpat (Cons x_CONSpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::APPpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_APPpat : public a_Pat {
public:
#line 194 "ir.ph"
  Pat _1; Pat _2; 
  Pat_APPpat (Pat x_1, Pat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::TYPEDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_TYPEDpat : public a_Pat {
public:
#line 195 "ir.ph"
  Pat _1; Ty _2; 
  Pat_TYPEDpat (Pat x_1, Ty x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::ASpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_ASpat : public a_Pat {
public:
#line 196 "ir.ph"
  Id _1; Pat _2; Ty _3; Exp _4; 
  Pat_ASpat (Id x_1, Pat x_2, Ty x_3, Exp x_4);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::LITERALpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_LITERALpat : public a_Pat {
public:
#line 197 "ir.ph"
  Literal LITERALpat; 
  Pat_LITERALpat (Literal x_LITERALpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::CONTEXTpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_CONTEXTpat : public a_Pat {
public:
#line 198 "ir.ph"
  Conses _1; Pat _2; 
  Pat_CONTEXTpat (Conses x_1, Pat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::LEXEMEpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_LEXEMEpat : public a_Pat {
public:
#line 199 "ir.ph"
  Id _1; Ty _2; int _3; Cons * _4; 
  Pat_LEXEMEpat (Id x_1, Ty x_2, int x_3, Cons * x_4);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::ARRAYpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_ARRAYpat : public a_Pat {
public:
#line 200 "ir.ph"
  a_List<Pat> *  _1; Bool _2; 
  Pat_ARRAYpat (a_List<Pat> *  x_1, Bool x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::TUPLEpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_TUPLEpat : public a_Pat {
public:
#line 201 "ir.ph"
  a_List<Pat> *  TUPLEpat; 
  Pat_TUPLEpat (a_List<Pat> *  x_TUPLEpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::EXTUPLEpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_EXTUPLEpat : public a_Pat {
public:
#line 202 "ir.ph"
  a_List<Pat> *  EXTUPLEpat; 
  Pat_EXTUPLEpat (a_List<Pat> *  x_EXTUPLEpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::RECORDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_RECORDpat : public a_Pat {
public:
#line 203 "ir.ph"
  a_List<LabPat> *  _1; Bool _2; 
  Pat_RECORDpat (a_List<LabPat> *  x_1, Bool x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::LISTpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_LISTpat : public a_Pat {
public:
#line 204 "ir.ph"
  Cons cons; Cons nil; a_List<Pat> *  head; Pat tail; 
  Pat_LISTpat (Cons x_cons, Cons x_nil, a_List<Pat> *  x_head, Pat x_tail);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::VECTORpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_VECTORpat : public a_Pat {
public:
#line 211 "ir.ph"
  Cons cons; Pat len; Pat array; a_List<Pat> *  elements; Bool head_flex; Bool tail_flex; 
  Pat_VECTORpat (Cons x_cons, Pat x_len, Pat x_array, a_List<Pat> *  x_elements, Bool x_head_flex, Bool x_tail_flex);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::APPENDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_APPENDpat : public a_Pat {
public:
#line 220 "ir.ph"
  Pat _1; Pat _2; Ty _3; 
  Pat_APPENDpat (Pat x_1, Pat x_2, Ty x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::GUARDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_GUARDpat : public a_Pat {
public:
#line 221 "ir.ph"
  Pat _1; Exp _2; 
  Pat_GUARDpat (Pat x_1, Exp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::LOGICALpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_LOGICALpat : public a_Pat {
public:
#line 222 "ir.ph"
  LogicalPat _1; Pat _2; Pat _3; 
  Pat_LOGICALpat (LogicalPat x_1, Pat x_2, Pat x_3 = NOpat);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::BACKEDGEpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_BACKEDGEpat : public a_Pat {
public:
#line 223 "ir.ph"
  int _1; Id _2; Pat _3; 
  Pat_BACKEDGEpat (int x_1, Id x_2, Pat x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::UNIFYpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_UNIFYpat : public a_Pat {
public:
#line 224 "ir.ph"
  Pat _1; Exp _2; 
  Pat_UNIFYpat (Pat x_1, Exp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pat::MARKEDpat
//
///////////////////////////////////////////////////////////////////////////////
class Pat_MARKEDpat : public a_Pat {
public:
#line 225 "ir.ph"
  Loc _1; Pat _2; 
  Pat_MARKEDpat (Loc x_1, Pat x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Pat
//
///////////////////////////////////////////////////////////////////////////////
extern a_Pat * WILDpat ();
extern a_Pat * INDpat (Id x_1, int x_2, Ty x_3);
extern a_Pat * POLYpat (Id x_1, int x_2, Ids x_3, Pat x_4, Exp x_5, Bool x_6);
extern a_Pat * IDpat (Id x_1, Ty x_2, Exp x_3);
extern a_Pat * CONSpat (Cons x_CONSpat);
extern a_Pat * APPpat (Pat x_1, Pat x_2);
extern a_Pat * TYPEDpat (Pat x_1, Ty x_2);
extern a_Pat * ASpat (Id x_1, Pat x_2, Ty x_3, Exp x_4);
extern a_Pat * LITERALpat (Literal x_LITERALpat);
extern a_Pat * CONTEXTpat (Conses x_1, Pat x_2);
extern a_Pat * LEXEMEpat (Id x_1, Ty x_2, int x_3, Cons * x_4);
extern a_Pat * ARRAYpat (a_List<Pat> *  x_1, Bool x_2);
extern a_Pat * TUPLEpat (a_List<Pat> *  x_TUPLEpat);
extern a_Pat * EXTUPLEpat (a_List<Pat> *  x_EXTUPLEpat);
extern a_Pat * RECORDpat (a_List<LabPat> *  x_1, Bool x_2);
extern a_Pat * LISTpat (Cons x_cons, Cons x_nil, a_List<Pat> *  x_head, Pat x_tail);
extern a_Pat * VECTORpat (Cons x_cons, Pat x_len, Pat x_array, a_List<Pat> *  x_elements, Bool x_head_flex, Bool x_tail_flex);
extern a_Pat * APPENDpat (Pat x_1, Pat x_2, Ty x_3);
extern a_Pat * GUARDpat (Pat x_1, Exp x_2);
extern a_Pat * LOGICALpat (LogicalPat x_1, Pat x_2, Pat x_3 = NOpat);
extern a_Pat * BACKEDGEpat (int x_1, Id x_2, Pat x_3);
extern a_Pat * UNIFYpat (Pat x_1, Exp x_2);
extern a_Pat * MARKEDpat (Loc x_1, Pat x_2);


///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Literal
//
///////////////////////////////////////////////////////////////////////////////
class a_Literal : public MEM {
public:
  enum Tag_Literal {
    tag_INTlit = 0, tag_BOOLlit = 1, tag_CHARlit = 2, 
    tag_REALlit = 3, tag_STRINGlit = 4, tag_REGEXPlit = 5, 
    tag_QUARKlit = 6, tag_BIGINTlit = 7
  };

public:
  const Tag_Literal tag__; // variant tag
protected:
  inline a_Literal(Tag_Literal t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Literal *) { return 1; }
inline int untag(const a_Literal * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::INTlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_INTlit : public a_Literal {
public:
#line 250 "ir.ph"
  int INTlit; 
  Literal_INTlit (int x_INTlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::BOOLlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_BOOLlit : public a_Literal {
public:
#line 251 "ir.ph"
  Bool BOOLlit; 
  Literal_BOOLlit (Bool x_BOOLlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::CHARlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_CHARlit : public a_Literal {
public:
#line 252 "ir.ph"
  char CHARlit; 
  Literal_CHARlit (char x_CHARlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::REALlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_REALlit : public a_Literal {
public:
#line 253 "ir.ph"
  double REALlit; 
  Literal_REALlit (double x_REALlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::STRINGlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_STRINGlit : public a_Literal {
public:
#line 254 "ir.ph"
  char const * STRINGlit; 
  Literal_STRINGlit (char const * x_STRINGlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::REGEXPlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_REGEXPlit : public a_Literal {
public:
#line 255 "ir.ph"
  char const * REGEXPlit; 
  Literal_REGEXPlit (char const * x_REGEXPlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::QUARKlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_QUARKlit : public a_Literal {
public:
#line 256 "ir.ph"
  char const * QUARKlit; 
  Literal_QUARKlit (char const * x_QUARKlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Literal::BIGINTlit
//
///////////////////////////////////////////////////////////////////////////////
class Literal_BIGINTlit : public a_Literal {
public:
#line 257 "ir.ph"
  char const * BIGINTlit; 
  Literal_BIGINTlit (char const * x_BIGINTlit);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Literal
//
///////////////////////////////////////////////////////////////////////////////
extern a_Literal * INTlit (int x_INTlit);
extern a_Literal * BOOLlit (Bool x_BOOLlit);
extern a_Literal * CHARlit (char x_CHARlit);
extern a_Literal * REALlit (double x_REALlit);
extern a_Literal * STRINGlit (char const * x_STRINGlit);
extern a_Literal * REGEXPlit (char const * x_REGEXPlit);
extern a_Literal * QUARKlit (char const * x_QUARKlit);
extern a_Literal * BIGINTlit (char const * x_BIGINTlit);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Cons::ONEcons
//
///////////////////////////////////////////////////////////////////////////////
class a_Cons : public MEM {
public:
#line 267 "ir.ph"
  Id name; Ty alg_ty; Ty cons_ty; Ty ty; int tag; PrintFormats print_formats; Loc const * location; a_List<Inherit> *  inherit; a_List<Decl> *  body; TyOpt opt; TyQual qual; Exp view_predicate; Exp * view_selectors; Pat lexeme_pattern; DatatypeClass * class_def; 
  a_Cons (Id x_name, Ty x_alg_ty, Ty x_cons_ty, Ty x_ty, int x_tag, PrintFormats x_print_formats, Loc const * x_location, a_List<Inherit> *  x_inherit, a_List<Decl> *  x_body, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate, Exp * x_view_selectors, Pat x_lexeme_pattern, DatatypeClass * x_class_def = 0);
};
inline int boxed(const a_Cons * x) { return x != 0; }
inline int untag(const a_Cons * x) { return x ? 1 : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Cons
//
///////////////////////////////////////////////////////////////////////////////
extern a_Cons * ONEcons (Id x_name, Ty x_alg_ty, Ty x_cons_ty, Ty x_ty, int x_tag, PrintFormats x_print_formats, Loc const * x_location, a_List<Inherit> *  x_inherit, a_List<Decl> *  x_body, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate, Exp * x_view_selectors, Pat x_lexeme_pattern, DatatypeClass * x_class_def = 0);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype ProductionSymbol
//
///////////////////////////////////////////////////////////////////////////////
class a_ProductionSymbol : public Loc {
public:
  enum Tag_ProductionSymbol {
    tag_TERMsym = 0, tag_TERMSTRINGsym = 1, tag_TERMREGEXPsym = 2, 
    tag_TOKENsym = 3, tag_NONTERMsym = 4, tag_POSNONTERMsym = 5, 
    tag_ACTIONsym = 6, tag_PREDICATEsym = 7, tag_PRECsym = 8, 
    tag_ERRORsym = 9, tag_SPECIALsym = 10
  };

public:
  const Tag_ProductionSymbol tag__; // variant tag
protected:
  inline a_ProductionSymbol(Tag_ProductionSymbol t__) : tag__(t__) {}
public:
};
inline int boxed(const a_ProductionSymbol *) { return 1; }
inline int untag(const a_ProductionSymbol * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::TERMsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_TERMsym : public a_ProductionSymbol {
public:
#line 293 "ir.ph"
  char TERMsym; 
  ProductionSymbol_TERMsym (char x_TERMsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::TERMSTRINGsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_TERMSTRINGsym : public a_ProductionSymbol {
public:
#line 294 "ir.ph"
  char const * TERMSTRINGsym; 
  ProductionSymbol_TERMSTRINGsym (char const * x_TERMSTRINGsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::TERMREGEXPsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_TERMREGEXPsym : public a_ProductionSymbol {
public:
#line 295 "ir.ph"
  char const * TERMREGEXPsym; 
  ProductionSymbol_TERMREGEXPsym (char const * x_TERMREGEXPsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::TOKENsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_TOKENsym : public a_ProductionSymbol {
public:
#line 296 "ir.ph"
  Cons TOKENsym; 
  ProductionSymbol_TOKENsym (Cons x_TOKENsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::NONTERMsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_NONTERMsym : public a_ProductionSymbol {
public:
#line 297 "ir.ph"
  Id NONTERMsym; 
  ProductionSymbol_NONTERMsym (Id x_NONTERMsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::POSNONTERMsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_POSNONTERMsym : public a_ProductionSymbol {
public:
#line 298 "ir.ph"
  int POSNONTERMsym; 
  ProductionSymbol_POSNONTERMsym (int x_POSNONTERMsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::ACTIONsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_ACTIONsym : public a_ProductionSymbol {
public:
#line 299 "ir.ph"
  a_List<Decl> *  ACTIONsym; 
  ProductionSymbol_ACTIONsym (a_List<Decl> *  x_ACTIONsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::PREDICATEsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_PREDICATEsym : public a_ProductionSymbol {
public:
#line 300 "ir.ph"
  Exp PREDICATEsym; 
  ProductionSymbol_PREDICATEsym (Exp x_PREDICATEsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::PRECsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_PRECsym : public a_ProductionSymbol {
public:
#line 301 "ir.ph"
  Cons PRECsym; 
  ProductionSymbol_PRECsym (Cons x_PRECsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::ERRORsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_ERRORsym : public a_ProductionSymbol {
public:
#line 302 "ir.ph"
  
  ProductionSymbol_ERRORsym ();
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor ProductionSymbol::SPECIALsym
//
///////////////////////////////////////////////////////////////////////////////
class ProductionSymbol_SPECIALsym : public a_ProductionSymbol {
public:
#line 303 "ir.ph"
  char SPECIALsym; 
  ProductionSymbol_SPECIALsym (char x_SPECIALsym);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for ProductionSymbol
//
///////////////////////////////////////////////////////////////////////////////
extern a_ProductionSymbol * TERMsym (char x_TERMsym);
extern a_ProductionSymbol * TERMSTRINGsym (char const * x_TERMSTRINGsym);
extern a_ProductionSymbol * TERMREGEXPsym (char const * x_TERMREGEXPsym);
extern a_ProductionSymbol * TOKENsym (Cons x_TOKENsym);
extern a_ProductionSymbol * NONTERMsym (Id x_NONTERMsym);
extern a_ProductionSymbol * POSNONTERMsym (int x_POSNONTERMsym);
extern a_ProductionSymbol * ACTIONsym (a_List<Decl> *  x_ACTIONsym);
extern a_ProductionSymbol * PREDICATEsym (Exp x_PREDICATEsym);
extern a_ProductionSymbol * PRECsym (Cons x_PRECsym);
extern a_ProductionSymbol * ERRORsym ();
extern a_ProductionSymbol * SPECIALsym (char x_SPECIALsym);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Pid::PERSISTid
//
///////////////////////////////////////////////////////////////////////////////
class a_Pid : public MEM {
public:
#line 311 "ir.ph"
  char const * PERSISTid; 
  a_Pid (char const * x_PERSISTid);
};
inline int boxed(const a_Pid * x) { return x != 0; }
inline int untag(const a_Pid * x) { return x ? 1 : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Pid
//
///////////////////////////////////////////////////////////////////////////////
extern a_Pid * PERSISTid (char const * x_PERSISTid);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Inherit::INHERIT
//
///////////////////////////////////////////////////////////////////////////////
class a_Inherit : public Loc {
public:
#line 320 "ir.ph"
  Ty super_class; Scope scope; TyQual qualifiers; 
  a_Inherit (Ty x_super_class, Scope x_scope = PUBLICscope, TyQual x_qualifiers = QUALnone);
};
inline int boxed(const a_Inherit *) { return 1; }
inline int untag(const a_Inherit *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Inherit
//
///////////////////////////////////////////////////////////////////////////////
extern a_Inherit * INHERIT (Ty x_super_class, Scope x_scope = PUBLICscope, TyQual x_qualifiers = QUALnone);

#line 377 "ir.ph"
#line 377 "ir.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing methods
//
///////////////////////////////////////////////////////////////////////////////

extern std::ostream& operator << (std::ostream&, Ids);
extern std::ostream& operator << (std::ostream&, Scope);
extern std::ostream& operator << (std::ostream&, Ty);
extern std::ostream& operator << (std::ostream&, 
#line 388 "ir.ph"
a_List<Ty> *  
#line 388 "ir.ph"
);
extern std::ostream& operator << (std::ostream&, Pat);
extern std::ostream& operator << (std::ostream&, LabPat);
extern std::ostream& operator << (std::ostream&, a_List<Pat> *  
#line 391 "ir.ph"
);
extern std::ostream& operator << (std::ostream&, a_List<LabPat> *  
#line 392 "ir.ph"
);
extern std::ostream& operator << (std::ostream&, Literal);
extern std::ostream& operator << (std::ostream&, Inherit);
extern std::ostream& operator << (std::ostream&, a_List<Inherit> *  
#line 395 "ir.ph"
);
extern std::ostream& operator << (std::ostream&, Pid);

extern std::ostream& print_cons (std::ostream&, Cons);
extern void     print_parameter (std::ostream&, Ty, Id, Parameter);
extern void     print_tyvars    (std::ostream&, TyVars, char, char, Bool);
extern Id       index_of (int, Id = 0);

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
