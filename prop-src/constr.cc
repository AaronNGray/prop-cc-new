///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "constr.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "constr.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file simply instantiates all the datatypes used in the Prop -> C++
//  translator.
//
///////////////////////////////////////////////////////////////////////////////

#include "ir.h"
#include "ast.h"
#include "matchcom.h"

#line 12 "constr.pcc"
#line 12 "constr.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Ty
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype TyCon
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Pat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Cons
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Pos
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Match
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Decl
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype MatchExp
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Inherit
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Literal
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Cost
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype MatchRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Protocol
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype DatatypeDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype TyDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype TermDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype ViewDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype LawDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype FunDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype QualId
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype InferenceRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Conclusion
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype LogicalPat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Scope
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Polarity
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Ty>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Pat>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Exp>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Pos>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Decl>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Inherit>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<MatchExp>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<MatchRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Protocol>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<DatatypeDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<TyDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<TermDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<ViewDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<LawDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<FunDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<QualId>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<InferenceRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Conclusion>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Scope>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Pid
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Pair<Id, Tys>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Generator
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Generator>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<RewriteIndexing *>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Ty
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Ty_VARty::Ty_VARty (Ty x_VARty)
 : a_Ty(tag_VARty), VARty(x_VARty)
{
}
a_Ty * VARty (Ty x_VARty)
{
  return new Ty_VARty (x_VARty);
}
Ty_INDty::Ty_INDty (Id x_1, int x_2)
 : a_Ty(tag_INDty), _1(x_1), _2(x_2)
{
}
a_Ty * INDty (Id x_1, int x_2)
{
  return new Ty_INDty (x_1, x_2);
}
Ty_QUALty::Ty_QUALty (TyQual x_1, Ty x_2)
 : a_Ty(tag_QUALty), _1(x_1), _2(x_2)
{
}
a_Ty * QUALty (TyQual x_1, Ty x_2)
{
  return new Ty_QUALty (x_1, x_2);
}
Ty_TYCONty::Ty_TYCONty (TyCon x_1, a_List<Ty> *  x_2)
 : a_Ty(tag_TYCONty), _1(x_1), _2(x_2)
{
}
a_Ty * TYCONty (TyCon x_1, a_List<Ty> *  x_2)
{
  return new Ty_TYCONty (x_1, x_2);
}
Ty_POLYty::Ty_POLYty (Ty x_1, int x_2, TyVar * x_3)
 : a_Ty(tag_POLYty), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Ty * POLYty (Ty x_1, int x_2, TyVar * x_3)
{
  return new Ty_POLYty (x_1, x_2, x_3);
}
Ty_DEFVALty::Ty_DEFVALty (Ty x_1, Exp x_2)
 : a_Ty(tag_DEFVALty), _1(x_1), _2(x_2)
{
}
a_Ty * DEFVALty (Ty x_1, Exp x_2)
{
  return new Ty_DEFVALty (x_1, x_2);
}
Ty_NESTEDty::Ty_NESTEDty (Ty x_1, Ty x_2)
 : a_Ty(tag_NESTEDty), _1(x_1), _2(x_2)
{
}
a_Ty * NESTEDty (Ty x_1, Ty x_2)
{
  return new Ty_NESTEDty (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype TyCon
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
TyCon_IDtycon::TyCon_IDtycon (Id x_IDtycon)
 : a_TyCon(tag_IDtycon), IDtycon(x_IDtycon)
{
}
a_TyCon * IDtycon (Id x_IDtycon)
{
  return new TyCon_IDtycon (x_IDtycon);
}
TyCon_RECORDtycon::TyCon_RECORDtycon (a_List<Id> *  x_1, Bool x_2)
 : a_TyCon(tag_RECORDtycon), _1(x_1), _2(x_2)
{
}
a_TyCon * RECORDtycon (a_List<Id> *  x_1, Bool x_2)
{
  return new TyCon_RECORDtycon (x_1, x_2);
}
TyCon_ARRAYtycon::TyCon_ARRAYtycon (Exp x_ARRAYtycon)
 : a_TyCon(tag_ARRAYtycon), ARRAYtycon(x_ARRAYtycon)
{
}
a_TyCon * ARRAYtycon (Exp x_ARRAYtycon)
{
  return new TyCon_ARRAYtycon (x_ARRAYtycon);
}
TyCon_BITFIELDtycon::TyCon_BITFIELDtycon (int x_width, Bool x_is_signed)
 : a_TyCon(tag_BITFIELDtycon), width(x_width), is_signed(x_is_signed)
{
}
a_TyCon * BITFIELDtycon (int x_width, Bool x_is_signed)
{
  return new TyCon_BITFIELDtycon (x_width, x_is_signed);
}
TyCon_DATATYPEtycon::TyCon_DATATYPEtycon (Id x_id, int x_unit, int x_arg, Cons * x_terms, TyVars x_tyvars, Ty x_polyty, a_List<Inherit> *  x_inherit, TyQual x_qualifiers, TyOpt x_opt, a_List<Decl> *  x_body, Exp x_view_match, Loc const * x_location, DatatypeHierarchy * x_hierarchy)
 : a_TyCon(tag_DATATYPEtycon), id(x_id), unit(x_unit), arg(x_arg), terms(x_terms), tyvars(x_tyvars), polyty(x_polyty), inherit(x_inherit), qualifiers(x_qualifiers), opt(x_opt), body(x_body), view_match(x_view_match), location(x_location), hierarchy(x_hierarchy)
{
}
a_TyCon * DATATYPEtycon (Id x_id, int x_unit, int x_arg, Cons * x_terms, TyVars x_tyvars, Ty x_polyty, a_List<Inherit> *  x_inherit, TyQual x_qualifiers, TyOpt x_opt, a_List<Decl> *  x_body, Exp x_view_match, Loc const * x_location, DatatypeHierarchy * x_hierarchy)
{
  return new TyCon_DATATYPEtycon (x_id, x_unit, x_arg, x_terms, x_tyvars, x_polyty, x_inherit, x_qualifiers, x_opt, x_body, x_view_match, x_location, x_hierarchy);
}
TyCon_COLtycon::TyCon_COLtycon (CollectionDesc x_COLtycon)
 : a_TyCon(tag_COLtycon), COLtycon(x_COLtycon)
{
}
a_TyCon * COLtycon (CollectionDesc x_COLtycon)
{
  return new TyCon_COLtycon (x_COLtycon);
}
TyCon_GRAPHtycon::TyCon_GRAPHtycon (GraphTypeDef * x_GRAPHtycon)
 : a_TyCon(tag_GRAPHtycon), GRAPHtycon(x_GRAPHtycon)
{
}
a_TyCon * GRAPHtycon (GraphTypeDef * x_GRAPHtycon)
{
  return new TyCon_GRAPHtycon (x_GRAPHtycon);
}
TyCon_NODEtycon::TyCon_NODEtycon (NodeDef * x_NODEtycon)
 : a_TyCon(tag_NODEtycon), NODEtycon(x_NODEtycon)
{
}
a_TyCon * NODEtycon (NodeDef * x_NODEtycon)
{
  return new TyCon_NODEtycon (x_NODEtycon);
}
TyCon_EDGEtycon::TyCon_EDGEtycon (EdgeDef * x_EDGEtycon)
 : a_TyCon(tag_EDGEtycon), EDGEtycon(x_EDGEtycon)
{
}
a_TyCon * EDGEtycon (EdgeDef * x_EDGEtycon)
{
  return new TyCon_EDGEtycon (x_EDGEtycon);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Pat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Pat_WILDpat::Pat_WILDpat ()
 : a_Pat(tag_WILDpat)
{
}
a_Pat * WILDpat ()
{
  return new Pat_WILDpat ;
}
Pat_INDpat::Pat_INDpat (Id x_1, int x_2, Ty x_3)
 : a_Pat(tag_INDpat), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pat * INDpat (Id x_1, int x_2, Ty x_3)
{
  return new Pat_INDpat (x_1, x_2, x_3);
}
Pat_POLYpat::Pat_POLYpat (Id x_1, int x_2, Ids x_3, Pat x_4, Exp x_5, Bool x_6)
 : a_Pat(tag_POLYpat), _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6)
{
}
a_Pat * POLYpat (Id x_1, int x_2, Ids x_3, Pat x_4, Exp x_5, Bool x_6)
{
  return new Pat_POLYpat (x_1, x_2, x_3, x_4, x_5, x_6);
}
Pat_IDpat::Pat_IDpat (Id x_1, Ty x_2, Exp x_3)
 : a_Pat(tag_IDpat), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pat * IDpat (Id x_1, Ty x_2, Exp x_3)
{
  return new Pat_IDpat (x_1, x_2, x_3);
}
Pat_CONSpat::Pat_CONSpat (Cons x_CONSpat)
 : a_Pat(tag_CONSpat), CONSpat(x_CONSpat)
{
}
a_Pat * CONSpat (Cons x_CONSpat)
{
  return new Pat_CONSpat (x_CONSpat);
}
Pat_APPpat::Pat_APPpat (Pat x_1, Pat x_2)
 : a_Pat(tag_APPpat), _1(x_1), _2(x_2)
{
}
a_Pat * APPpat (Pat x_1, Pat x_2)
{
  return new Pat_APPpat (x_1, x_2);
}
Pat_TYPEDpat::Pat_TYPEDpat (Pat x_1, Ty x_2)
 : a_Pat(tag_TYPEDpat), _1(x_1), _2(x_2)
{
}
a_Pat * TYPEDpat (Pat x_1, Ty x_2)
{
  return new Pat_TYPEDpat (x_1, x_2);
}
Pat_ASpat::Pat_ASpat (Id x_1, Pat x_2, Ty x_3, Exp x_4)
 : a_Pat(tag_ASpat), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Pat * ASpat (Id x_1, Pat x_2, Ty x_3, Exp x_4)
{
  return new Pat_ASpat (x_1, x_2, x_3, x_4);
}
Pat_LITERALpat::Pat_LITERALpat (Literal x_LITERALpat)
 : a_Pat(tag_LITERALpat), LITERALpat(x_LITERALpat)
{
}
a_Pat * LITERALpat (Literal x_LITERALpat)
{
  return new Pat_LITERALpat (x_LITERALpat);
}
Pat_CONTEXTpat::Pat_CONTEXTpat (Conses x_1, Pat x_2)
 : a_Pat(tag_CONTEXTpat), _1(x_1), _2(x_2)
{
}
a_Pat * CONTEXTpat (Conses x_1, Pat x_2)
{
  return new Pat_CONTEXTpat (x_1, x_2);
}
Pat_LEXEMEpat::Pat_LEXEMEpat (Id x_1, Ty x_2, int x_3, Cons * x_4)
 : a_Pat(tag_LEXEMEpat), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Pat * LEXEMEpat (Id x_1, Ty x_2, int x_3, Cons * x_4)
{
  return new Pat_LEXEMEpat (x_1, x_2, x_3, x_4);
}
Pat_ARRAYpat::Pat_ARRAYpat (a_List<Pat> *  x_1, Bool x_2)
 : a_Pat(tag_ARRAYpat), _1(x_1), _2(x_2)
{
}
a_Pat * ARRAYpat (a_List<Pat> *  x_1, Bool x_2)
{
  return new Pat_ARRAYpat (x_1, x_2);
}
Pat_TUPLEpat::Pat_TUPLEpat (a_List<Pat> *  x_TUPLEpat)
 : a_Pat(tag_TUPLEpat), TUPLEpat(x_TUPLEpat)
{
}
a_Pat * TUPLEpat (a_List<Pat> *  x_TUPLEpat)
{
  return new Pat_TUPLEpat (x_TUPLEpat);
}
Pat_EXTUPLEpat::Pat_EXTUPLEpat (a_List<Pat> *  x_EXTUPLEpat)
 : a_Pat(tag_EXTUPLEpat), EXTUPLEpat(x_EXTUPLEpat)
{
}
a_Pat * EXTUPLEpat (a_List<Pat> *  x_EXTUPLEpat)
{
  return new Pat_EXTUPLEpat (x_EXTUPLEpat);
}
Pat_RECORDpat::Pat_RECORDpat (a_List<LabPat> *  x_1, Bool x_2)
 : a_Pat(tag_RECORDpat), _1(x_1), _2(x_2)
{
}
a_Pat * RECORDpat (a_List<LabPat> *  x_1, Bool x_2)
{
  return new Pat_RECORDpat (x_1, x_2);
}
Pat_LISTpat::Pat_LISTpat (Cons x_cons, Cons x_nil, a_List<Pat> *  x_head, Pat x_tail)
 : a_Pat(tag_LISTpat), cons(x_cons), nil(x_nil), head(x_head), tail(x_tail)
{
}
a_Pat * LISTpat (Cons x_cons, Cons x_nil, a_List<Pat> *  x_head, Pat x_tail)
{
  return new Pat_LISTpat (x_cons, x_nil, x_head, x_tail);
}
Pat_VECTORpat::Pat_VECTORpat (Cons x_cons, Pat x_len, Pat x_array, a_List<Pat> *  x_elements, Bool x_head_flex, Bool x_tail_flex)
 : a_Pat(tag_VECTORpat), cons(x_cons), len(x_len), array(x_array), elements(x_elements), head_flex(x_head_flex), tail_flex(x_tail_flex)
{
}
a_Pat * VECTORpat (Cons x_cons, Pat x_len, Pat x_array, a_List<Pat> *  x_elements, Bool x_head_flex, Bool x_tail_flex)
{
  return new Pat_VECTORpat (x_cons, x_len, x_array, x_elements, x_head_flex, x_tail_flex);
}
Pat_APPENDpat::Pat_APPENDpat (Pat x_1, Pat x_2, Ty x_3)
 : a_Pat(tag_APPENDpat), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pat * APPENDpat (Pat x_1, Pat x_2, Ty x_3)
{
  return new Pat_APPENDpat (x_1, x_2, x_3);
}
Pat_GUARDpat::Pat_GUARDpat (Pat x_1, Exp x_2)
 : a_Pat(tag_GUARDpat), _1(x_1), _2(x_2)
{
}
a_Pat * GUARDpat (Pat x_1, Exp x_2)
{
  return new Pat_GUARDpat (x_1, x_2);
}
Pat_LOGICALpat::Pat_LOGICALpat (LogicalPat x_1, Pat x_2, Pat x_3)
 : a_Pat(tag_LOGICALpat), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pat * LOGICALpat (LogicalPat x_1, Pat x_2, Pat x_3)
{
  return new Pat_LOGICALpat (x_1, x_2, x_3);
}
Pat_BACKEDGEpat::Pat_BACKEDGEpat (int x_1, Id x_2, Pat x_3)
 : a_Pat(tag_BACKEDGEpat), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pat * BACKEDGEpat (int x_1, Id x_2, Pat x_3)
{
  return new Pat_BACKEDGEpat (x_1, x_2, x_3);
}
Pat_UNIFYpat::Pat_UNIFYpat (Pat x_1, Exp x_2)
 : a_Pat(tag_UNIFYpat), _1(x_1), _2(x_2)
{
}
a_Pat * UNIFYpat (Pat x_1, Exp x_2)
{
  return new Pat_UNIFYpat (x_1, x_2);
}
Pat_MARKEDpat::Pat_MARKEDpat (Loc x_1, Pat x_2)
 : a_Pat(tag_MARKEDpat), _1(x_1), _2(x_2)
{
}
a_Pat * MARKEDpat (Loc x_1, Pat x_2)
{
  return new Pat_MARKEDpat (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Exp_LITERALexp::Exp_LITERALexp (Literal x_LITERALexp)
 : a_Exp(tag_LITERALexp), LITERALexp(x_LITERALexp)
{
}
a_Exp * LITERALexp (Literal x_LITERALexp)
{
  return new Exp_LITERALexp (x_LITERALexp);
}
Exp_IDexp::Exp_IDexp (Id x_IDexp)
 : a_Exp(tag_IDexp), IDexp(x_IDexp)
{
}
a_Exp * IDexp (Id x_IDexp)
{
  return new Exp_IDexp (x_IDexp);
}
Exp_RELexp::Exp_RELexp (int x_RELexp)
 : a_Exp(tag_RELexp), RELexp(x_RELexp)
{
}
a_Exp * RELexp (int x_RELexp)
{
  return new Exp_RELexp (x_RELexp);
}
Exp_DOTexp::Exp_DOTexp (Exp x_1, Id x_2)
 : a_Exp(tag_DOTexp), _1(x_1), _2(x_2)
{
}
a_Exp * DOTexp (Exp x_1, Id x_2)
{
  return new Exp_DOTexp (x_1, x_2);
}
Exp_SELECTORexp::Exp_SELECTORexp (Exp x_1, Cons x_2, Ty x_3)
 : a_Exp(tag_SELECTORexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * SELECTORexp (Exp x_1, Cons x_2, Ty x_3)
{
  return new Exp_SELECTORexp (x_1, x_2, x_3);
}
Exp_DEREFexp::Exp_DEREFexp (Exp x_DEREFexp)
 : a_Exp(tag_DEREFexp), DEREFexp(x_DEREFexp)
{
}
a_Exp * DEREFexp (Exp x_DEREFexp)
{
  return new Exp_DEREFexp (x_DEREFexp);
}
Exp_ARROWexp::Exp_ARROWexp (Exp x_1, Id x_2)
 : a_Exp(tag_ARROWexp), _1(x_1), _2(x_2)
{
}
a_Exp * ARROWexp (Exp x_1, Id x_2)
{
  return new Exp_ARROWexp (x_1, x_2);
}
Exp_INDEXexp::Exp_INDEXexp (Exp x_1, Exp x_2)
 : a_Exp(tag_INDEXexp), _1(x_1), _2(x_2)
{
}
a_Exp * INDEXexp (Exp x_1, Exp x_2)
{
  return new Exp_INDEXexp (x_1, x_2);
}
Exp_BINOPexp::Exp_BINOPexp (Id x_1, Exp x_2, Exp x_3)
 : a_Exp(tag_BINOPexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * BINOPexp (Id x_1, Exp x_2, Exp x_3)
{
  return new Exp_BINOPexp (x_1, x_2, x_3);
}
Exp_PREFIXexp::Exp_PREFIXexp (Id x_1, Exp x_2)
 : a_Exp(tag_PREFIXexp), _1(x_1), _2(x_2)
{
}
a_Exp * PREFIXexp (Id x_1, Exp x_2)
{
  return new Exp_PREFIXexp (x_1, x_2);
}
Exp_POSTFIXexp::Exp_POSTFIXexp (Id x_1, Exp x_2)
 : a_Exp(tag_POSTFIXexp), _1(x_1), _2(x_2)
{
}
a_Exp * POSTFIXexp (Id x_1, Exp x_2)
{
  return new Exp_POSTFIXexp (x_1, x_2);
}
Exp_APPexp::Exp_APPexp (Exp x_1, Exp x_2)
 : a_Exp(tag_APPexp), _1(x_1), _2(x_2)
{
}
a_Exp * APPexp (Exp x_1, Exp x_2)
{
  return new Exp_APPexp (x_1, x_2);
}
Exp_ASSIGNexp::Exp_ASSIGNexp (Exp x_1, Exp x_2)
 : a_Exp(tag_ASSIGNexp), _1(x_1), _2(x_2)
{
}
a_Exp * ASSIGNexp (Exp x_1, Exp x_2)
{
  return new Exp_ASSIGNexp (x_1, x_2);
}
Exp_IFexp::Exp_IFexp (Exp x_1, Exp x_2, Exp x_3)
 : a_Exp(tag_IFexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * IFexp (Exp x_1, Exp x_2, Exp x_3)
{
  return new Exp_IFexp (x_1, x_2, x_3);
}
Exp_TUPLEexp::Exp_TUPLEexp (a_List<Exp> *  x_TUPLEexp)
 : a_Exp(tag_TUPLEexp), TUPLEexp(x_TUPLEexp)
{
}
a_Exp * TUPLEexp (a_List<Exp> *  x_TUPLEexp)
{
  return new Exp_TUPLEexp (x_TUPLEexp);
}
Exp_EXTUPLEexp::Exp_EXTUPLEexp (a_List<Exp> *  x_EXTUPLEexp)
 : a_Exp(tag_EXTUPLEexp), EXTUPLEexp(x_EXTUPLEexp)
{
}
a_Exp * EXTUPLEexp (a_List<Exp> *  x_EXTUPLEexp)
{
  return new Exp_EXTUPLEexp (x_EXTUPLEexp);
}
Exp_RECORDexp::Exp_RECORDexp (a_List<LabExp> *  x_RECORDexp)
 : a_Exp(tag_RECORDexp), RECORDexp(x_RECORDexp)
{
}
a_Exp * RECORDexp (a_List<LabExp> *  x_RECORDexp)
{
  return new Exp_RECORDexp (x_RECORDexp);
}
Exp_LISTexp::Exp_LISTexp (Cons x_1, Cons x_2, a_List<Exp> *  x_3, Exp x_4)
 : a_Exp(tag_LISTexp), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Exp * LISTexp (Cons x_1, Cons x_2, a_List<Exp> *  x_3, Exp x_4)
{
  return new Exp_LISTexp (x_1, x_2, x_3, x_4);
}
Exp_VECTORexp::Exp_VECTORexp (Cons x_1, a_List<Exp> *  x_2)
 : a_Exp(tag_VECTORexp), _1(x_1), _2(x_2)
{
}
a_Exp * VECTORexp (Cons x_1, a_List<Exp> *  x_2)
{
  return new Exp_VECTORexp (x_1, x_2);
}
Exp_CONSexp::Exp_CONSexp (Cons x_1, a_List<Exp> *  x_2, Exp x_3)
 : a_Exp(tag_CONSexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * CONSexp (Cons x_1, a_List<Exp> *  x_2, Exp x_3)
{
  return new Exp_CONSexp (x_1, x_2, x_3);
}
Exp_CASTexp::Exp_CASTexp (Ty x_1, Exp x_2)
 : a_Exp(tag_CASTexp), _1(x_1), _2(x_2)
{
}
a_Exp * CASTexp (Ty x_1, Exp x_2)
{
  return new Exp_CASTexp (x_1, x_2);
}
Exp_QUALexp::Exp_QUALexp (Ty x_1, Id x_2)
 : a_Exp(tag_QUALexp), _1(x_1), _2(x_2)
{
}
a_Exp * QUALexp (Ty x_1, Id x_2)
{
  return new Exp_QUALexp (x_1, x_2);
}
Exp_EQexp::Exp_EQexp (Ty x_1, Exp x_2, Exp x_3)
 : a_Exp(tag_EQexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * EQexp (Ty x_1, Exp x_2, Exp x_3)
{
  return new Exp_EQexp (x_1, x_2, x_3);
}
Exp_UNIFYexp::Exp_UNIFYexp (Ty x_1, Exp x_2, Exp x_3)
 : a_Exp(tag_UNIFYexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * UNIFYexp (Ty x_1, Exp x_2, Exp x_3)
{
  return new Exp_UNIFYexp (x_1, x_2, x_3);
}
Exp_LTexp::Exp_LTexp (Ty x_1, Exp x_2, Exp x_3)
 : a_Exp(tag_LTexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * LTexp (Ty x_1, Exp x_2, Exp x_3)
{
  return new Exp_LTexp (x_1, x_2, x_3);
}
Exp_HASHexp::Exp_HASHexp (Ty x_1, Exp x_2)
 : a_Exp(tag_HASHexp), _1(x_1), _2(x_2)
{
}
a_Exp * HASHexp (Ty x_1, Exp x_2)
{
  return new Exp_HASHexp (x_1, x_2);
}
Exp_THISCOSTexp::Exp_THISCOSTexp ()
 : a_Exp(tag_THISCOSTexp)
{
}
a_Exp * THISCOSTexp ()
{
  return new Exp_THISCOSTexp ;
}
Exp_COSTexp::Exp_COSTexp (ChildNo x_COSTexp)
 : a_Exp(tag_COSTexp), COSTexp(x_COSTexp)
{
}
a_Exp * COSTexp (ChildNo x_COSTexp)
{
  return new Exp_COSTexp (x_COSTexp);
}
Exp_THISSYNexp::Exp_THISSYNexp (RuleNo x_1, Ty x_2, Bool x_3)
 : a_Exp(tag_THISSYNexp), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Exp * THISSYNexp (RuleNo x_1, Ty x_2, Bool x_3)
{
  return new Exp_THISSYNexp (x_1, x_2, x_3);
}
Exp_SYNexp::Exp_SYNexp (ChildNo x_1, RuleNo x_2, Ty x_3, Bool x_4)
 : a_Exp(tag_SYNexp), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Exp * SYNexp (ChildNo x_1, RuleNo x_2, Ty x_3, Bool x_4)
{
  return new Exp_SYNexp (x_1, x_2, x_3, x_4);
}
Exp_SENDexp::Exp_SENDexp (Id x_1, a_List<Exp> *  x_2)
 : a_Exp(tag_SENDexp), _1(x_1), _2(x_2)
{
}
a_Exp * SENDexp (Id x_1, a_List<Exp> *  x_2)
{
  return new Exp_SENDexp (x_1, x_2);
}
Exp_SETLexp::Exp_SETLexp (SETLOp x_1, Exps x_2)
 : a_Exp(tag_SETLexp), _1(x_1), _2(x_2)
{
}
a_Exp * SETLexp (SETLOp x_1, Exps x_2)
{
  return new Exp_SETLexp (x_1, x_2);
}
Exp_LISTCOMPexp::Exp_LISTCOMPexp (Exp x_exp, a_List<Generator> *  x_generators, Exp x_guard)
 : a_Exp(tag_LISTCOMPexp), exp(x_exp), generators(x_generators), guard(x_guard)
{
}
a_Exp * LISTCOMPexp (Exp x_exp, a_List<Generator> *  x_generators, Exp x_guard)
{
  return new Exp_LISTCOMPexp (x_exp, x_generators, x_guard);
}
Exp_FORALLexp::Exp_FORALLexp (Id x_1, Exp x_2)
 : a_Exp(tag_FORALLexp), _1(x_1), _2(x_2)
{
}
a_Exp * FORALLexp (Id x_1, Exp x_2)
{
  return new Exp_FORALLexp (x_1, x_2);
}
Exp_EXISTSexp::Exp_EXISTSexp (Id x_1, Exp x_2)
 : a_Exp(tag_EXISTSexp), _1(x_1), _2(x_2)
{
}
a_Exp * EXISTSexp (Id x_1, Exp x_2)
{
  return new Exp_EXISTSexp (x_1, x_2);
}
Exp_MARKEDexp::Exp_MARKEDexp (Loc x_1, Exp x_2)
 : a_Exp(tag_MARKEDexp), _1(x_1), _2(x_2)
{
}
a_Exp * MARKEDexp (Loc x_1, Exp x_2)
{
  return new Exp_MARKEDexp (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Cons
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_Cons::a_Cons (Id x_name, Ty x_alg_ty, Ty x_cons_ty, Ty x_ty, int x_tag, PrintFormats x_print_formats, Loc const * x_location, a_List<Inherit> *  x_inherit, a_List<Decl> *  x_body, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate, Exp * x_view_selectors, Pat x_lexeme_pattern, DatatypeClass * x_class_def)
 : name(x_name), alg_ty(x_alg_ty), cons_ty(x_cons_ty), ty(x_ty), tag(x_tag), print_formats(x_print_formats), location(x_location), inherit(x_inherit), body(x_body), opt(x_opt), qual(x_qual), view_predicate(x_view_predicate), view_selectors(x_view_selectors), lexeme_pattern(x_lexeme_pattern), class_def(x_class_def)
{
}
a_Cons * ONEcons (Id x_name, Ty x_alg_ty, Ty x_cons_ty, Ty x_ty, int x_tag, PrintFormats x_print_formats, Loc const * x_location, a_List<Inherit> *  x_inherit, a_List<Decl> *  x_body, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate, Exp * x_view_selectors, Pat x_lexeme_pattern, DatatypeClass * x_class_def)
{
  return new a_Cons (x_name, x_alg_ty, x_cons_ty, x_ty, x_tag, x_print_formats, x_location, x_inherit, x_body, x_opt, x_qual, x_view_predicate, x_view_selectors, x_lexeme_pattern, x_class_def);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Pos
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Pos_POSint::Pos_POSint (int x_1, Pos x_2)
 : _1(x_1), _2(x_2)
{
}
a_Pos * POSint (int x_1, Pos x_2)
{
  return (a_Pos*)((unsigned long)(new Pos_POSint (x_1, x_2))|a_Pos::tag_POSint);
}
Pos_POSlabel::Pos_POSlabel (Id x_1, Pos x_2)
 : _1(x_1), _2(x_2)
{
}
a_Pos * POSlabel (Id x_1, Pos x_2)
{
  return (a_Pos*)((unsigned long)(new Pos_POSlabel (x_1, x_2))|a_Pos::tag_POSlabel);
}
Pos_POSadaptive::Pos_POSadaptive (int x_1, int * x_2, Pos x_3)
 : _1(x_1), _2(x_2), _3(x_3)
{
}
a_Pos * POSadaptive (int x_1, int * x_2, Pos x_3)
{
  return (a_Pos*)((unsigned long)(new Pos_POSadaptive (x_1, x_2, x_3))|a_Pos::tag_POSadaptive);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Match
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Match_SUCCESSmatch::Match_SUCCESSmatch (int x_1, MatchRule x_2)
 : a_Match(tag_SUCCESSmatch), _1(x_1), _2(x_2)
{
}
a_Match * SUCCESSmatch (int x_1, MatchRule x_2)
{
  return new Match_SUCCESSmatch (x_1, x_2);
}
Match_SUCCESSESmatch::Match_SUCCESSESmatch (int x_1, BitSet * x_2, MatchRules x_3)
 : a_Match(tag_SUCCESSESmatch), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Match * SUCCESSESmatch (int x_1, BitSet * x_2, MatchRules x_3)
{
  return new Match_SUCCESSESmatch (x_1, x_2, x_3);
}
Match_COSTmatch::Match_COSTmatch (int x_1, Cost * x_2, BitSet * x_3, MatchRules x_4)
 : a_Match(tag_COSTmatch), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Match * COSTmatch (int x_1, Cost * x_2, BitSet * x_3, MatchRules x_4)
{
  return new Match_COSTmatch (x_1, x_2, x_3, x_4);
}
Match_GUARDmatch::Match_GUARDmatch (Exp x_1, Match x_2, Match x_3)
 : a_Match(tag_GUARDmatch), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Match * GUARDmatch (Exp x_1, Match x_2, Match x_3)
{
  return new Match_GUARDmatch (x_1, x_2, x_3);
}
Match_LITERALmatch::Match_LITERALmatch (Pos x_1, Exp x_2, Literal * x_3, int x_4, Match * x_5, Match x_6)
 : a_Match(tag_LITERALmatch), _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6)
{
}
a_Match * LITERALmatch (Pos x_1, Exp x_2, Literal * x_3, int x_4, Match * x_5, Match x_6)
{
  return new Match_LITERALmatch (x_1, x_2, x_3, x_4, x_5, x_6);
}
Match_RANGEmatch::Match_RANGEmatch (Pos x_1, Exp x_2, int x_3, int x_4, Match x_5, Match x_6)
 : a_Match(tag_RANGEmatch), _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6)
{
}
a_Match * RANGEmatch (Pos x_1, Exp x_2, int x_3, int x_4, Match x_5, Match x_6)
{
  return new Match_RANGEmatch (x_1, x_2, x_3, x_4, x_5, x_6);
}
Match_CONSmatch::Match_CONSmatch (Pos x_1, Exp x_2, Ty x_3, Ty x_4, int x_5, Match * x_6, Match x_7)
 : a_Match(tag_CONSmatch), _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6), _7(x_7)
{
}
a_Match * CONSmatch (Pos x_1, Exp x_2, Ty x_3, Ty x_4, int x_5, Match * x_6, Match x_7)
{
  return new Match_CONSmatch (x_1, x_2, x_3, x_4, x_5, x_6, x_7);
}
Match_TREECOSTmatch::Match_TREECOSTmatch (Match x_1, BitSet * x_2, MatchRules x_3)
 : a_Match(tag_TREECOSTmatch), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Match * TREECOSTmatch (Match x_1, BitSet * x_2, MatchRules x_3)
{
  return new Match_TREECOSTmatch (x_1, x_2, x_3);
}
Match_TREELABELmatch::Match_TREELABELmatch (Match x_1, Ty x_2, Ty x_3, int x_4)
 : a_Match(tag_TREELABELmatch), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Match * TREELABELmatch (Match x_1, Ty x_2, Ty x_3, int x_4)
{
  return new Match_TREELABELmatch (x_1, x_2, x_3, x_4);
}
Match_BACKEDGEmatch::Match_BACKEDGEmatch (int x_1, Id x_2, Match x_3)
 : a_Match(tag_BACKEDGEmatch), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Match * BACKEDGEmatch (int x_1, Id x_2, Match x_3)
{
  return new Match_BACKEDGEmatch (x_1, x_2, x_3);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Decl
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Decl_OPAQUEdecl::Decl_OPAQUEdecl (char const * x_OPAQUEdecl)
 : a_Decl(tag_OPAQUEdecl), OPAQUEdecl(x_OPAQUEdecl)
{
}
a_Decl * OPAQUEdecl (char const * x_OPAQUEdecl)
{
  return new Decl_OPAQUEdecl (x_OPAQUEdecl);
}
Decl_DATATYPEdecl::Decl_DATATYPEdecl (DatatypeDefs x_1, ViewDefs x_2, LawDefs x_3, TyDefs x_4)
 : a_Decl(tag_DATATYPEdecl), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Decl * DATATYPEdecl (DatatypeDefs x_1, ViewDefs x_2, LawDefs x_3, TyDefs x_4)
{
  return new Decl_DATATYPEdecl (x_1, x_2, x_3, x_4);
}
Decl_INSTANTIATEdecl::Decl_INSTANTIATEdecl (Bool x_1, Tys x_2)
 : a_Decl(tag_INSTANTIATEdecl), _1(x_1), _2(x_2)
{
}
a_Decl * INSTANTIATEdecl (Bool x_1, Tys x_2)
{
  return new Decl_INSTANTIATEdecl (x_1, x_2);
}
Decl_CLASSDEFdecl::Decl_CLASSDEFdecl (ClassDefinition * x_CLASSDEFdecl)
 : a_Decl(tag_CLASSDEFdecl), CLASSDEFdecl(x_CLASSDEFdecl)
{
}
a_Decl * CLASSDEFdecl (ClassDefinition * x_CLASSDEFdecl)
{
  return new Decl_CLASSDEFdecl (x_CLASSDEFdecl);
}
Decl_INFERENCEdecl::Decl_INFERENCEdecl (Id x_1, InferenceRules x_2)
 : a_Decl(tag_INFERENCEdecl), _1(x_1), _2(x_2)
{
}
a_Decl * INFERENCEdecl (Id x_1, InferenceRules x_2)
{
  return new Decl_INFERENCEdecl (x_1, x_2);
}
Decl_REWRITEdecl::Decl_REWRITEdecl (Id x_1, RewriteIndexings x_2, MatchRules x_3)
 : a_Decl(tag_REWRITEdecl), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Decl * REWRITEdecl (Id x_1, RewriteIndexings x_2, MatchRules x_3)
{
  return new Decl_REWRITEdecl (x_1, x_2, x_3);
}
Decl_REWRITINGdecl::Decl_REWRITINGdecl (Protocols x_1, Exp x_2, Exp x_3, RewriteIndexings x_4, MatchRules x_5, TyQual x_6)
 : a_Decl(tag_REWRITINGdecl), _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6)
{
}
a_Decl * REWRITINGdecl (Protocols x_1, Exp x_2, Exp x_3, RewriteIndexings x_4, MatchRules x_5, TyQual x_6)
{
  return new Decl_REWRITINGdecl (x_1, x_2, x_3, x_4, x_5, x_6);
}
Decl_REPLACEMENTdecl::Decl_REPLACEMENTdecl (Exp x_1, MatchRuleInfo::RewritingMode x_2)
 : a_Decl(tag_REPLACEMENTdecl), _1(x_1), _2(x_2)
{
}
a_Decl * REPLACEMENTdecl (Exp x_1, MatchRuleInfo::RewritingMode x_2)
{
  return new Decl_REPLACEMENTdecl (x_1, x_2);
}
Decl_CUTREWRITEdecl::Decl_CUTREWRITEdecl (Exp x_1, MatchRuleInfo::RewritingMode x_2)
 : a_Decl(tag_CUTREWRITEdecl), _1(x_1), _2(x_2)
{
}
a_Decl * CUTREWRITEdecl (Exp x_1, MatchRuleInfo::RewritingMode x_2)
{
  return new Decl_CUTREWRITEdecl (x_1, x_2);
}
Decl_FAILREWRITEdecl::Decl_FAILREWRITEdecl (MatchRuleInfo::RewritingMode x_FAILREWRITEdecl)
 : a_Decl(tag_FAILREWRITEdecl), FAILREWRITEdecl(x_FAILREWRITEdecl)
{
}
a_Decl * FAILREWRITEdecl (MatchRuleInfo::RewritingMode x_FAILREWRITEdecl)
{
  return new Decl_FAILREWRITEdecl (x_FAILREWRITEdecl);
}
Decl_INJECTdecl::Decl_INJECTdecl (int x_node_number, EntryDirection x_direction)
 : a_Decl(tag_INJECTdecl), node_number(x_node_number), direction(x_direction)
{
}
a_Decl * INJECTdecl (int x_node_number, EntryDirection x_direction)
{
  return new Decl_INJECTdecl (x_node_number, x_direction);
}
Decl_GOTOdecl::Decl_GOTOdecl (Id x_GOTOdecl)
 : a_Decl(tag_GOTOdecl), GOTOdecl(x_GOTOdecl)
{
}
a_Decl * GOTOdecl (Id x_GOTOdecl)
{
  return new Decl_GOTOdecl (x_GOTOdecl);
}
Decl_SETSTATEdecl::Decl_SETSTATEdecl (int x_SETSTATEdecl)
 : a_Decl(tag_SETSTATEdecl), SETSTATEdecl(x_SETSTATEdecl)
{
}
a_Decl * SETSTATEdecl (int x_SETSTATEdecl)
{
  return new Decl_SETSTATEdecl (x_SETSTATEdecl);
}
Decl_CONSTRAINTdecl::Decl_CONSTRAINTdecl (Id x_1, ConstraintSet x_2)
 : a_Decl(tag_CONSTRAINTdecl), _1(x_1), _2(x_2)
{
}
a_Decl * CONSTRAINTdecl (Id x_1, ConstraintSet x_2)
{
  return new Decl_CONSTRAINTdecl (x_1, x_2);
}
Decl_SYNTAXdecl::Decl_SYNTAXdecl (Id x_1, GramExp x_2)
 : a_Decl(tag_SYNTAXdecl), _1(x_1), _2(x_2)
{
}
a_Decl * SYNTAXdecl (Id x_1, GramExp x_2)
{
  return new Decl_SYNTAXdecl (x_1, x_2);
}
Decl_ATTRIBUTEGRAMMARdecl::Decl_ATTRIBUTEGRAMMARdecl (Id x_1, GramExp x_2)
 : a_Decl(tag_ATTRIBUTEGRAMMARdecl), _1(x_1), _2(x_2)
{
}
a_Decl * ATTRIBUTEGRAMMARdecl (Id x_1, GramExp x_2)
{
  return new Decl_ATTRIBUTEGRAMMARdecl (x_1, x_2);
}
Decl_FUNdecl::Decl_FUNdecl (FunDefs x_FUNdecl)
 : a_Decl(tag_FUNdecl), FUNdecl(x_FUNdecl)
{
}
a_Decl * FUNdecl (FunDefs x_FUNdecl)
{
  return new Decl_FUNdecl (x_FUNdecl);
}
Decl_MATCHdecl::Decl_MATCHdecl (MatchExps x_1, MatchRules x_2, MatchOptions x_3, Ty x_4)
 : a_Decl(tag_MATCHdecl), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Decl * MATCHdecl (MatchExps x_1, MatchRules x_2, MatchOptions x_3, Ty x_4)
{
  return new Decl_MATCHdecl (x_1, x_2, x_3, x_4);
}
Decl_BITFIELDdecl::Decl_BITFIELDdecl (Id x_name, int x_width, FieldDefs x_field_names, FieldLaws x_laws)
 : a_Decl(tag_BITFIELDdecl), name(x_name), width(x_width), field_names(x_field_names), laws(x_laws)
{
}
a_Decl * BITFIELDdecl (Id x_name, int x_width, FieldDefs x_field_names, FieldLaws x_laws)
{
  return new Decl_BITFIELDdecl (x_name, x_width, x_field_names, x_laws);
}
Decl_SETLSTMTdecl::Decl_SETLSTMTdecl (Stmt x_SETLSTMTdecl)
 : a_Decl(tag_SETLSTMTdecl), SETLSTMTdecl(x_SETLSTMTdecl)
{
}
a_Decl * SETLSTMTdecl (Stmt x_SETLSTMTdecl)
{
  return new Decl_SETLSTMTdecl (x_SETLSTMTdecl);
}
Decl_SETLDEFdecl::Decl_SETLDEFdecl (Def x_SETLDEFdecl)
 : a_Decl(tag_SETLDEFdecl), SETLDEFdecl(x_SETLDEFdecl)
{
}
a_Decl * SETLDEFdecl (Def x_SETLDEFdecl)
{
  return new Decl_SETLDEFdecl (x_SETLDEFdecl);
}
Decl_GRAPHREWRITEdecl::Decl_GRAPHREWRITEdecl (Id x_name, LabTys x_args, GraphRewritingRules x_rules)
 : a_Decl(tag_GRAPHREWRITEdecl), name(x_name), args(x_args), rules(x_rules)
{
}
a_Decl * GRAPHREWRITEdecl (Id x_name, LabTys x_args, GraphRewritingRules x_rules)
{
  return new Decl_GRAPHREWRITEdecl (x_name, x_args, x_rules);
}
Decl_DATAFLOWdecl::Decl_DATAFLOWdecl (Id x_name)
 : a_Decl(tag_DATAFLOWdecl), name(x_name)
{
}
a_Decl * DATAFLOWdecl (Id x_name)
{
  return new Decl_DATAFLOWdecl (x_name);
}
Decl_CLASSOFdecl::Decl_CLASSOFdecl (Id x_CLASSOFdecl)
 : a_Decl(tag_CLASSOFdecl), CLASSOFdecl(x_CLASSOFdecl)
{
}
a_Decl * CLASSOFdecl (Id x_CLASSOFdecl)
{
  return new Decl_CLASSOFdecl (x_CLASSOFdecl);
}
Decl_TYPEEXPdecl::Decl_TYPEEXPdecl (Ty x_TYPEEXPdecl)
 : a_Decl(tag_TYPEEXPdecl), TYPEEXPdecl(x_TYPEEXPdecl)
{
}
a_Decl * TYPEEXPdecl (Ty x_TYPEEXPdecl)
{
  return new Decl_TYPEEXPdecl (x_TYPEEXPdecl);
}
Decl_EXPdecl::Decl_EXPdecl (Exp x_exp, char const * x_prefix, char const * x_suffix)
 : a_Decl(tag_EXPdecl), exp(x_exp), prefix(x_prefix), suffix(x_suffix)
{
}
a_Decl * EXPdecl (Exp x_exp, char const * x_prefix, char const * x_suffix)
{
  return new Decl_EXPdecl (x_exp, x_prefix, x_suffix);
}
Decl_MARKEDdecl::Decl_MARKEDdecl (Loc x_1, Decl x_2)
 : a_Decl(tag_MARKEDdecl), _1(x_1), _2(x_2)
{
}
a_Decl * MARKEDdecl (Loc x_1, Decl x_2)
{
  return new Decl_MARKEDdecl (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype MatchExp
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_MatchExp::a_MatchExp (Exp x_1, Id x_2)
 : _1(x_1), _2(x_2)
{
}
a_MatchExp * MATCHexp (Exp x_1, Id x_2)
{
  return new a_MatchExp (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Inherit
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_Inherit::a_Inherit (Ty x_super_class, Scope x_scope, TyQual x_qualifiers)
 : super_class(x_super_class), scope(x_scope), qualifiers(x_qualifiers)
{
}
a_Inherit * INHERIT (Ty x_super_class, Scope x_scope, TyQual x_qualifiers)
{
  return new a_Inherit (x_super_class, x_scope, x_qualifiers);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Literal
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Literal_INTlit::Literal_INTlit (int x_INTlit)
 : a_Literal(tag_INTlit), INTlit(x_INTlit)
{
}
a_Literal * INTlit (int x_INTlit)
{
  return new Literal_INTlit (x_INTlit);
}
Literal_BOOLlit::Literal_BOOLlit (Bool x_BOOLlit)
 : a_Literal(tag_BOOLlit), BOOLlit(x_BOOLlit)
{
}
a_Literal * BOOLlit (Bool x_BOOLlit)
{
  return new Literal_BOOLlit (x_BOOLlit);
}
Literal_CHARlit::Literal_CHARlit (char x_CHARlit)
 : a_Literal(tag_CHARlit), CHARlit(x_CHARlit)
{
}
a_Literal * CHARlit (char x_CHARlit)
{
  return new Literal_CHARlit (x_CHARlit);
}
Literal_REALlit::Literal_REALlit (double x_REALlit)
 : a_Literal(tag_REALlit), REALlit(x_REALlit)
{
}
a_Literal * REALlit (double x_REALlit)
{
  return new Literal_REALlit (x_REALlit);
}
Literal_STRINGlit::Literal_STRINGlit (char const * x_STRINGlit)
 : a_Literal(tag_STRINGlit), STRINGlit(x_STRINGlit)
{
}
a_Literal * STRINGlit (char const * x_STRINGlit)
{
  return new Literal_STRINGlit (x_STRINGlit);
}
Literal_REGEXPlit::Literal_REGEXPlit (char const * x_REGEXPlit)
 : a_Literal(tag_REGEXPlit), REGEXPlit(x_REGEXPlit)
{
}
a_Literal * REGEXPlit (char const * x_REGEXPlit)
{
  return new Literal_REGEXPlit (x_REGEXPlit);
}
Literal_QUARKlit::Literal_QUARKlit (char const * x_QUARKlit)
 : a_Literal(tag_QUARKlit), QUARKlit(x_QUARKlit)
{
}
a_Literal * QUARKlit (char const * x_QUARKlit)
{
  return new Literal_QUARKlit (x_QUARKlit);
}
Literal_BIGINTlit::Literal_BIGINTlit (char const * x_BIGINTlit)
 : a_Literal(tag_BIGINTlit), BIGINTlit(x_BIGINTlit)
{
}
a_Literal * BIGINTlit (char const * x_BIGINTlit)
{
  return new Literal_BIGINTlit (x_BIGINTlit);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Cost
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Cost_EXPcost::Cost_EXPcost (Exp x_1, Ty x_2)
 : _1(x_1), _2(x_2)
{
}
a_Cost * EXPcost (Exp x_1, Ty x_2)
{
  return (a_Cost*)((unsigned long)(new Cost_EXPcost (x_1, x_2))|a_Cost::tag_EXPcost);
}
Cost_INTcost::Cost_INTcost (int x_INTcost)
 : INTcost(x_INTcost)
{
}
a_Cost * INTcost (int x_INTcost)
{
  return (a_Cost*)((unsigned long)(new Cost_INTcost (x_INTcost))|a_Cost::tag_INTcost);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype MatchRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_MatchRule::a_MatchRule (Id x_1, Pat x_2, Exp x_3, Cost x_4, a_List<Decl> *  x_5)
 : _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5)
{
}
a_MatchRule * MATCHrule (Id x_1, Pat x_2, Exp x_3, Cost x_4, a_List<Decl> *  x_5)
{
  return new a_MatchRule (x_1, x_2, x_3, x_4, x_5);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Protocol
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_Protocol::a_Protocol (Ty x_ty, Ty x_inh, Ty x_syn)
 : ty(x_ty), inh(x_inh), syn(x_syn)
{
}
a_Protocol * PROTOCOL (Ty x_ty, Ty x_inh, Ty x_syn)
{
  return new a_Protocol (x_ty, x_inh, x_syn);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype DatatypeDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_DatatypeDef::a_DatatypeDef (Id x_1, TyVars x_2, Inherits x_3, TyQual x_4, TermDefs x_5, Decls x_6)
 : _1(x_1), _2(x_2), _3(x_3), _4(x_4), _5(x_5), _6(x_6)
{
}
a_DatatypeDef * DATATYPEdef (Id x_1, TyVars x_2, Inherits x_3, TyQual x_4, TermDefs x_5, Decls x_6)
{
  return new a_DatatypeDef (x_1, x_2, x_3, x_4, x_5, x_6);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype TyDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_TyDef::a_TyDef (Id x_1, TyVars x_2, Ty x_3, Bool x_4)
 : _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_TyDef * TYdef (Id x_1, TyVars x_2, Ty x_3, Bool x_4)
{
  return new a_TyDef (x_1, x_2, x_3, x_4);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype TermDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_TermDef::a_TermDef (Id x_id, Ty x_ty, Decls x_decls, Inherits x_inherits, Pat x_pat, PrintFormats x_print_formats, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate)
 : id(x_id), ty(x_ty), decls(x_decls), inherits(x_inherits), pat(x_pat), print_formats(x_print_formats), opt(x_opt), qual(x_qual), view_predicate(x_view_predicate)
{
}
a_TermDef * TERMdef (Id x_id, Ty x_ty, Decls x_decls, Inherits x_inherits, Pat x_pat, PrintFormats x_print_formats, TyOpt x_opt, TyQual x_qual, Exp x_view_predicate)
{
  return new a_TermDef (x_id, x_ty, x_decls, x_inherits, x_pat, x_print_formats, x_opt, x_qual, x_view_predicate);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype ViewDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_ViewDef::a_ViewDef (Pat x_1, Exp x_2, a_List<LabExp> *  x_3)
 : _1(x_1), _2(x_2), _3(x_3)
{
}
a_ViewDef * VIEWdef (Pat x_1, Exp x_2, a_List<LabExp> *  x_3)
{
  return new a_ViewDef (x_1, x_2, x_3);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype LawDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_LawDef::a_LawDef (Id x_id, Ids x_args, Exp x_guard, Pat x_pat, Bool x_invert, Ty x_ty)
 : id(x_id), args(x_args), guard(x_guard), pat(x_pat), invert(x_invert), ty(x_ty)
{
}
a_LawDef * LAWdef (Id x_id, Ids x_args, Exp x_guard, Pat x_pat, Bool x_invert, Ty x_ty)
{
  return new a_LawDef (x_id, x_args, x_guard, x_pat, x_invert, x_ty);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype FunDef
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_FunDef::a_FunDef (QualId x_1, Ty x_2, Ty x_3, MatchRules x_4)
 : _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_FunDef * FUNdef (QualId x_1, Ty x_2, Ty x_3, MatchRules x_4)
{
  return new a_FunDef (x_1, x_2, x_3, x_4);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype QualId
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
QualId_NESTEDid::QualId_NESTEDid (Ty x_1, QualId x_2)
 : _1(x_1), _2(x_2)
{
}
a_QualId * NESTEDid (Ty x_1, QualId x_2)
{
  return (a_QualId*)((unsigned long)(new QualId_NESTEDid (x_1, x_2))|a_QualId::tag_NESTEDid);
}
QualId_SIMPLEid::QualId_SIMPLEid (Id x_SIMPLEid)
 : SIMPLEid(x_SIMPLEid)
{
}
a_QualId * SIMPLEid (Id x_SIMPLEid)
{
  return (a_QualId*)((unsigned long)(new QualId_SIMPLEid (x_SIMPLEid))|a_QualId::tag_SIMPLEid);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype InferenceRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_InferenceRule::a_InferenceRule (MatchRules x_1, Exp x_2, Conclusions x_3)
 : _1(x_1), _2(x_2), _3(x_3)
{
}
a_InferenceRule * INFERENCErule (MatchRules x_1, Exp x_2, Conclusions x_3)
{
  return new a_InferenceRule (x_1, x_2, x_3);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Conclusion
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
Conclusion_ASSERTaction::Conclusion_ASSERTaction (Exp x_ASSERTaction)
 : ASSERTaction(x_ASSERTaction)
{
}
a_Conclusion * ASSERTaction (Exp x_ASSERTaction)
{
  return (a_Conclusion*)((unsigned long)(new Conclusion_ASSERTaction (x_ASSERTaction))|a_Conclusion::tag_ASSERTaction);
}
Conclusion_RETRACTaction::Conclusion_RETRACTaction (Exp x_RETRACTaction)
 : RETRACTaction(x_RETRACTaction)
{
}
a_Conclusion * RETRACTaction (Exp x_RETRACTaction)
{
  return (a_Conclusion*)((unsigned long)(new Conclusion_RETRACTaction (x_RETRACTaction))|a_Conclusion::tag_RETRACTaction);
}
Conclusion_STMTaction::Conclusion_STMTaction (Decls x_STMTaction)
 : STMTaction(x_STMTaction)
{
}
a_Conclusion * STMTaction (Decls x_STMTaction)
{
  return (a_Conclusion*)((unsigned long)(new Conclusion_STMTaction (x_STMTaction))|a_Conclusion::tag_STMTaction);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype LogicalPat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Scope
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Polarity
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Ty>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Ty>;
template a_List<Ty> * list_1_(RewriteIndexing * x_1, a_List<RewriteIndexing *> *  x_2);
template a_List<Ty> * list_1_(RewriteIndexing * x_list_1_);
template int boxed(const a_List<Ty> *);
template int untag(const a_List<Ty> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Pat>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Pat>;
template a_List<Pat> * list_1_(Ty x_1, a_List<Ty> *  x_2);
template a_List<Pat> * list_1_(Ty x_list_1_);
template int boxed(const a_List<Pat> *);
template int untag(const a_List<Pat> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Exp>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Exp>;
template a_List<Exp> * list_1_(Pat x_1, a_List<Pat> *  x_2);
template a_List<Exp> * list_1_(Pat x_list_1_);
template int boxed(const a_List<Exp> *);
template int untag(const a_List<Exp> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Pos>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Pos>;
template a_List<Pos> * list_1_(Exp x_1, a_List<Exp> *  x_2);
template a_List<Pos> * list_1_(Exp x_list_1_);
template int boxed(const a_List<Pos> *);
template int untag(const a_List<Pos> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Decl>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Decl>;
template a_List<Decl> * list_1_(Pos x_1, a_List<Pos> *  x_2);
template a_List<Decl> * list_1_(Pos x_list_1_);
template int boxed(const a_List<Decl> *);
template int untag(const a_List<Decl> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Inherit>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Inherit>;
template a_List<Inherit> * list_1_(Decl x_1, a_List<Decl> *  x_2);
template a_List<Inherit> * list_1_(Decl x_list_1_);
template int boxed(const a_List<Inherit> *);
template int untag(const a_List<Inherit> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<MatchExp>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<MatchExp>;
template a_List<MatchExp> * list_1_(Inherit x_1, a_List<Inherit> *  x_2);
template a_List<MatchExp> * list_1_(Inherit x_list_1_);
template int boxed(const a_List<MatchExp> *);
template int untag(const a_List<MatchExp> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<MatchRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<MatchRule>;
template a_List<MatchRule> * list_1_(MatchExp x_1, a_List<MatchExp> *  x_2);
template a_List<MatchRule> * list_1_(MatchExp x_list_1_);
template int boxed(const a_List<MatchRule> *);
template int untag(const a_List<MatchRule> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Protocol>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Protocol>;
template a_List<Protocol> * list_1_(MatchRule x_1, a_List<MatchRule> *  x_2);
template a_List<Protocol> * list_1_(MatchRule x_list_1_);
template int boxed(const a_List<Protocol> *);
template int untag(const a_List<Protocol> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<DatatypeDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<DatatypeDef>;
template a_List<DatatypeDef> * list_1_(Protocol x_1, a_List<Protocol> *  x_2);
template a_List<DatatypeDef> * list_1_(Protocol x_list_1_);
template int boxed(const a_List<DatatypeDef> *);
template int untag(const a_List<DatatypeDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<TyDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<TyDef>;
template a_List<TyDef> * list_1_(DatatypeDef x_1, a_List<DatatypeDef> *  x_2);
template a_List<TyDef> * list_1_(DatatypeDef x_list_1_);
template int boxed(const a_List<TyDef> *);
template int untag(const a_List<TyDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<TermDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<TermDef>;
template a_List<TermDef> * list_1_(TyDef x_1, a_List<TyDef> *  x_2);
template a_List<TermDef> * list_1_(TyDef x_list_1_);
template int boxed(const a_List<TermDef> *);
template int untag(const a_List<TermDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<ViewDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<ViewDef>;
template a_List<ViewDef> * list_1_(TermDef x_1, a_List<TermDef> *  x_2);
template a_List<ViewDef> * list_1_(TermDef x_list_1_);
template int boxed(const a_List<ViewDef> *);
template int untag(const a_List<ViewDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<LawDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<LawDef>;
template a_List<LawDef> * list_1_(ViewDef x_1, a_List<ViewDef> *  x_2);
template a_List<LawDef> * list_1_(ViewDef x_list_1_);
template int boxed(const a_List<LawDef> *);
template int untag(const a_List<LawDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<FunDef>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<FunDef>;
template a_List<FunDef> * list_1_(LawDef x_1, a_List<LawDef> *  x_2);
template a_List<FunDef> * list_1_(LawDef x_list_1_);
template int boxed(const a_List<FunDef> *);
template int untag(const a_List<FunDef> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<QualId>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<QualId>;
template a_List<QualId> * list_1_(FunDef x_1, a_List<FunDef> *  x_2);
template a_List<QualId> * list_1_(FunDef x_list_1_);
template int boxed(const a_List<QualId> *);
template int untag(const a_List<QualId> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<InferenceRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<InferenceRule>;
template a_List<InferenceRule> * list_1_(QualId x_1, a_List<QualId> *  x_2);
template a_List<InferenceRule> * list_1_(QualId x_list_1_);
template int boxed(const a_List<InferenceRule> *);
template int untag(const a_List<InferenceRule> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Conclusion>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Conclusion>;
template a_List<Conclusion> * list_1_(InferenceRule x_1, a_List<InferenceRule> *  x_2);
template a_List<Conclusion> * list_1_(InferenceRule x_list_1_);
template int boxed(const a_List<Conclusion> *);
template int untag(const a_List<Conclusion> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Scope>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Scope>;
template a_List<Scope> * list_1_(Conclusion x_1, a_List<Conclusion> *  x_2);
template a_List<Scope> * list_1_(Conclusion x_list_1_);
template int boxed(const a_List<Scope> *);
template int untag(const a_List<Scope> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Pid
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_Pid::a_Pid (char const * x_PERSISTid)
 : PERSISTid(x_PERSISTid)
{
}
a_Pid * PERSISTid (char const * x_PERSISTid)
{
  return new a_Pid (x_PERSISTid);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Pair<Id, Tys>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_Pair<Id, Tys>;
template a_Pair<Id, Tys> * makepair(Id x_fst, Tys x_snd);
template int boxed(const a_Pair<Id, Tys> *);
template int untag(const a_Pair<Id, Tys> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Generator
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
a_Generator::a_Generator (Pat x_pat, Exp x_guard, Exp x_exp)
 : pat(x_pat), guard(x_guard), exp(x_exp)
{
}
a_Generator * GENERATOR (Pat x_pat, Exp x_guard, Exp x_exp)
{
  return new a_Generator (x_pat, x_guard, x_exp);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Generator>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Generator>;
template a_List<Generator> * list_1_(Scope x_1, a_List<Scope> *  x_2);
template a_List<Generator> * list_1_(Scope x_list_1_);
template int boxed(const a_List<Generator> *);
template int untag(const a_List<Generator> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<RewriteIndexing *>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "constr.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<RewriteIndexing *>;
template a_List<RewriteIndexing *> * list_1_(Generator x_1, a_List<Generator> *  x_2);
template a_List<RewriteIndexing *> * list_1_(Generator x_list_1_);
template int boxed(const a_List<RewriteIndexing *> *);
template int untag(const a_List<RewriteIndexing *> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

#line 23 "constr.pcc"
#line 23 "constr.pcc"

#line 24 "constr.pcc"
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
