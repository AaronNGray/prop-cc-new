///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "setl-ast.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "setl-ast.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the basic routines on definitions and statements
//  ASTs.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ir.h"
#include "ast.h"
#include "setl-ast.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the AST datatypes.
//
///////////////////////////////////////////////////////////////////////////////

#line 20 "setl-ast.pcc"
#line 20 "setl-ast.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Def
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Sig
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Stmt
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Def>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Sig>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<LabSig>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<Stmt>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Def
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
Def_VARdef::Def_VARdef (Id x_id, Ty x_ty, Exp x_init_exp)
 : a_Def(tag_VARdef), id(x_id), ty(x_ty), init_exp(x_init_exp)
{
}
a_Def * VARdef (Id x_id, Ty x_ty, Exp x_init_exp)
{
  return new Def_VARdef (x_id, x_ty, x_init_exp);
}
Def_FUNCTIONdef::Def_FUNCTIONdef (Id x_id, LabTys x_args, Ty x_return_ty, Defs x_local_defs, Stmts x_body)
 : a_Def(tag_FUNCTIONdef), id(x_id), args(x_args), return_ty(x_return_ty), local_defs(x_local_defs), body(x_body)
{
}
a_Def * FUNCTIONdef (Id x_id, LabTys x_args, Ty x_return_ty, Defs x_local_defs, Stmts x_body)
{
  return new Def_FUNCTIONdef (x_id, x_args, x_return_ty, x_local_defs, x_body);
}
Def_MODULEdef::Def_MODULEdef (Id x_id, LabSigs x_args, Sig x_sig, Defs x_body)
 : a_Def(tag_MODULEdef), id(x_id), args(x_args), sig(x_sig), body(x_body)
{
}
a_Def * MODULEdef (Id x_id, LabSigs x_args, Sig x_sig, Defs x_body)
{
  return new Def_MODULEdef (x_id, x_args, x_sig, x_body);
}
Def_SIGNATUREdef::Def_SIGNATUREdef (Id x_id, LabSigs x_args, Sig x_sig)
 : a_Def(tag_SIGNATUREdef), id(x_id), args(x_args), sig(x_sig)
{
}
a_Def * SIGNATUREdef (Id x_id, LabSigs x_args, Sig x_sig)
{
  return new Def_SIGNATUREdef (x_id, x_args, x_sig);
}
Def_TYPEdef::Def_TYPEdef (Decl x_TYPEdef)
 : a_Def(tag_TYPEdef), TYPEdef(x_TYPEdef)
{
}
a_Def * TYPEdef (Decl x_TYPEdef)
{
  return new Def_TYPEdef (x_TYPEdef);
}
Def_LAMBDAdef::Def_LAMBDAdef (LabTys x_1, Defs x_2)
 : a_Def(tag_LAMBDAdef), _1(x_1), _2(x_2)
{
}
a_Def * LAMBDAdef (LabTys x_1, Defs x_2)
{
  return new Def_LAMBDAdef (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Sig
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
Sig_IDsig::Sig_IDsig (Id x_IDsig)
 : a_Sig(tag_IDsig), IDsig(x_IDsig)
{
}
a_Sig * IDsig (Id x_IDsig)
{
  return new Sig_IDsig (x_IDsig);
}
Sig_DOTsig::Sig_DOTsig (Sig x_1, Id x_2)
 : a_Sig(tag_DOTsig), _1(x_1), _2(x_2)
{
}
a_Sig * DOTsig (Sig x_1, Id x_2)
{
  return new Sig_DOTsig (x_1, x_2);
}
Sig_APPsig::Sig_APPsig (Sig x_1, Sigs x_2)
 : a_Sig(tag_APPsig), _1(x_1), _2(x_2)
{
}
a_Sig * APPsig (Sig x_1, Sigs x_2)
{
  return new Sig_APPsig (x_1, x_2);
}
Sig_DEFsig::Sig_DEFsig (Defs x_DEFsig)
 : a_Sig(tag_DEFsig), DEFsig(x_DEFsig)
{
}
a_Sig * DEFsig (Defs x_DEFsig)
{
  return new Sig_DEFsig (x_DEFsig);
}
Sig_LAMBDAsig::Sig_LAMBDAsig (LabSigs x_1, Sig x_2)
 : a_Sig(tag_LAMBDAsig), _1(x_1), _2(x_2)
{
}
a_Sig * LAMBDAsig (LabSigs x_1, Sig x_2)
{
  return new Sig_LAMBDAsig (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Stmt
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
Stmt_ASSIGNstmt::Stmt_ASSIGNstmt (Exp x_1, Exp x_2)
 : a_Stmt(tag_ASSIGNstmt), _1(x_1), _2(x_2)
{
}
a_Stmt * ASSIGNstmt (Exp x_1, Exp x_2)
{
  return new Stmt_ASSIGNstmt (x_1, x_2);
}
Stmt_BLOCKstmt::Stmt_BLOCKstmt (Defs x_1, Stmts x_2)
 : a_Stmt(tag_BLOCKstmt), _1(x_1), _2(x_2)
{
}
a_Stmt * BLOCKstmt (Defs x_1, Stmts x_2)
{
  return new Stmt_BLOCKstmt (x_1, x_2);
}
Stmt_WHILEstmt::Stmt_WHILEstmt (Exp x_1, Stmt x_2)
 : a_Stmt(tag_WHILEstmt), _1(x_1), _2(x_2)
{
}
a_Stmt * WHILEstmt (Exp x_1, Stmt x_2)
{
  return new Stmt_WHILEstmt (x_1, x_2);
}
Stmt_IFstmt::Stmt_IFstmt (Exp x_1, Stmt x_2, Stmt x_3)
 : a_Stmt(tag_IFstmt), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Stmt * IFstmt (Exp x_1, Stmt x_2, Stmt x_3)
{
  return new Stmt_IFstmt (x_1, x_2, x_3);
}
Stmt_MATCHstmt::Stmt_MATCHstmt (Decl x_MATCHstmt)
 : a_Stmt(tag_MATCHstmt), MATCHstmt(x_MATCHstmt)
{
}
a_Stmt * MATCHstmt (Decl x_MATCHstmt)
{
  return new Stmt_MATCHstmt (x_MATCHstmt);
}
Stmt_REWRITEstmt::Stmt_REWRITEstmt (Decl x_REWRITEstmt)
 : a_Stmt(tag_REWRITEstmt), REWRITEstmt(x_REWRITEstmt)
{
}
a_Stmt * REWRITEstmt (Decl x_REWRITEstmt)
{
  return new Stmt_REWRITEstmt (x_REWRITEstmt);
}
Stmt_REPLACEMENTstmt::Stmt_REPLACEMENTstmt (Decl x_REPLACEMENTstmt)
 : a_Stmt(tag_REPLACEMENTstmt), REPLACEMENTstmt(x_REPLACEMENTstmt)
{
}
a_Stmt * REPLACEMENTstmt (Decl x_REPLACEMENTstmt)
{
  return new Stmt_REPLACEMENTstmt (x_REPLACEMENTstmt);
}
Stmt_FORALLstmt::Stmt_FORALLstmt (Generators x_1, Stmt x_2)
 : a_Stmt(tag_FORALLstmt), _1(x_1), _2(x_2)
{
}
a_Stmt * FORALLstmt (Generators x_1, Stmt x_2)
{
  return new Stmt_FORALLstmt (x_1, x_2);
}
Stmt_RETURNstmt::Stmt_RETURNstmt (Exp x_RETURNstmt)
 : a_Stmt(tag_RETURNstmt), RETURNstmt(x_RETURNstmt)
{
}
a_Stmt * RETURNstmt (Exp x_RETURNstmt)
{
  return new Stmt_RETURNstmt (x_RETURNstmt);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Def>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Def>;
template a_List<Def> * list_1_(Stmt x_1, a_List<Stmt> *  x_2);
template a_List<Def> * list_1_(Stmt x_list_1_);
template int boxed(const a_List<Def> *);
template int untag(const a_List<Def> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Sig>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Sig>;
template a_List<Sig> * list_1_(Def x_1, a_List<Def> *  x_2);
template a_List<Sig> * list_1_(Def x_list_1_);
template int boxed(const a_List<Sig> *);
template int untag(const a_List<Sig> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<LabSig>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<LabSig>;
template a_List<LabSig> * list_1_(Sig x_1, a_List<Sig> *  x_2);
template a_List<LabSig> * list_1_(Sig x_list_1_);
template int boxed(const a_List<LabSig> *);
template int untag(const a_List<LabSig> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<Stmt>
//
///////////////////////////////////////////////////////////////////////////////
#line 20 "setl-ast.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<Stmt>;
template a_List<Stmt> * list_1_(LabSig x_1, a_List<LabSig> *  x_2);
template a_List<Stmt> * list_1_(LabSig x_list_1_);
template int boxed(const a_List<Stmt> *);
template int untag(const a_List<Stmt> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

#line 22 "setl-ast.pcc"
#line 22 "setl-ast.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  The rest of pretty printing functions for definitions and statements
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a signature
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Sig s)
{
  
#line 38 "setl-ast.pcc"
#line 45 "setl-ast.pcc"
{
  if (s) {
    switch (s->tag__) {
      case a_Sig::tag_IDsig: {
#line 41 "setl-ast.pcc"
       f << ((Sig_IDsig *)s)->IDsig; 
#line 41 "setl-ast.pcc"
        } break;
      case a_Sig::tag_DOTsig: {
#line 42 "setl-ast.pcc"
       f << ((Sig_DOTsig *)s)->_1 << '.' << ((Sig_DOTsig *)s)->_2; 
#line 42 "setl-ast.pcc"
        } break;
      case a_Sig::tag_APPsig: {
#line 43 "setl-ast.pcc"
       f << ((Sig_APPsig *)s)->_1 << '(' << ((Sig_APPsig *)s)->_2 << ')'; 
#line 43 "setl-ast.pcc"
        } break;
      case a_Sig::tag_DEFsig: {
#line 44 "setl-ast.pcc"
       f << "<def>"; 
#line 44 "setl-ast.pcc"
        } break;
      default: {
#line 45 "setl-ast.pcc"
       f << "<lambda>"; 
#line 45 "setl-ast.pcc"
        } break;
    }
  } else {
#line 40 "setl-ast.pcc"
   f << "none"; 
#line 40 "setl-ast.pcc"
  }
}
#line 46 "setl-ast.pcc"
#line 46 "setl-ast.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a signature list
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Sigs ss)
{
  
#line 58 "setl-ast.pcc"
#line 61 "setl-ast.pcc"
{
  for (;;) {
    if (ss) {
      if (ss->_2) {
#line 61 "setl-ast.pcc"
       f << ss->_1 << ", "; ss = ss->_2; 
#line 61 "setl-ast.pcc"
      } else {
#line 60 "setl-ast.pcc"
       f << ss->_1; ss = 
#line 60 "setl-ast.pcc"
#line 60 "setl-ast.pcc"
        nil_1_
#line 60 "setl-ast.pcc"
#line 60 "setl-ast.pcc"
        ; 
#line 60 "setl-ast.pcc"
      }
    } else { goto L1; }
  }
  L1:;
}
#line 62 "setl-ast.pcc"
#line 62 "setl-ast.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a statement
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Stmt s)
{
  
#line 74 "setl-ast.pcc"
#line 92 "setl-ast.pcc"
{
  if (s) {
    switch (s->tag__) {
      case a_Stmt::tag_ASSIGNstmt: {
#line 77 "setl-ast.pcc"
       f << ((Stmt_ASSIGNstmt *)s)->_1 << " := " << ((Stmt_ASSIGNstmt *)s)->_2 << ';'; 
#line 77 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_BLOCKstmt: {
#line 78 "setl-ast.pcc"
       f << ((Stmt_BLOCKstmt *)s)->_2; 
#line 78 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_WHILEstmt: {
#line 80 "setl-ast.pcc"
       f << "while " << ((Stmt_WHILEstmt *)s)->_1 <<  " loop " << ((Stmt_WHILEstmt *)s)->_2 << " end loop"; 
#line 80 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_IFstmt: {
#line 82 "setl-ast.pcc"
       f << "if " << ((Stmt_IFstmt *)s)->_1 << " then " << ((Stmt_IFstmt *)s)->_2 << " else " << ((Stmt_IFstmt *)s)->_3 << "end if"; 
#line 82 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_MATCHstmt: {
#line 88 "setl-ast.pcc"
       f << "match ..."; 
#line 88 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_REWRITEstmt: {
#line 90 "setl-ast.pcc"
       f << "rewrite ..."; 
#line 90 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_REPLACEMENTstmt: {
#line 92 "setl-ast.pcc"
       f << "rewrite ..."; 
#line 92 "setl-ast.pcc"
        } break;
      case a_Stmt::tag_FORALLstmt: {
#line 84 "setl-ast.pcc"
       f << "forall " << ((Stmt_FORALLstmt *)s)->_1 << " loop " << ((Stmt_FORALLstmt *)s)->_2 << "end loop"; 
#line 84 "setl-ast.pcc"
        } break;
      default: {
#line 86 "setl-ast.pcc"
       f << "return " << ((Stmt_RETURNstmt *)s)->RETURNstmt << ';'; 
#line 86 "setl-ast.pcc"
        } break;
    }
  } else {
#line 76 "setl-ast.pcc"
   f << "skip;"; 
#line 76 "setl-ast.pcc"
  }
}
#line 93 "setl-ast.pcc"
#line 93 "setl-ast.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a list of statements
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Stmts s)
{
  
#line 105 "setl-ast.pcc"
#line 108 "setl-ast.pcc"
{
  for (;;) {
    if (s) {
      if (s->_2) {
#line 108 "setl-ast.pcc"
       f << s->_1 << " "; s = s->_2; 
#line 108 "setl-ast.pcc"
      } else {
#line 107 "setl-ast.pcc"
       f << s->_1; s = 
#line 107 "setl-ast.pcc"
#line 107 "setl-ast.pcc"
        nil_1_
#line 107 "setl-ast.pcc"
#line 107 "setl-ast.pcc"
        ; 
#line 107 "setl-ast.pcc"
      }
    } else { goto L2; }
  }
  L2:;
}
#line 109 "setl-ast.pcc"
#line 109 "setl-ast.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a generator expression
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Generator b)
{
  
#line 121 "setl-ast.pcc"
#line 129 "setl-ast.pcc"
{
#line 124 "setl-ast.pcc"
  
  f << b->pat;
  if (b->guard != NOexp)
    f << " | " << b->guard;
  f << " <- " << b->exp;
  
#line 129 "setl-ast.pcc"
}
#line 130 "setl-ast.pcc"
#line 130 "setl-ast.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print a list of generator expressions
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Generators b)
{
  
#line 141 "setl-ast.pcc"
#line 144 "setl-ast.pcc"
{
  for (;;) {
    if (b) {
      if (b->_2) {
#line 144 "setl-ast.pcc"
       f << b->_1 << ", "; b = b->_2; 
#line 144 "setl-ast.pcc"
      } else {
#line 143 "setl-ast.pcc"
       f << b->_1; b = 
#line 143 "setl-ast.pcc"
#line 143 "setl-ast.pcc"
        nil_1_
#line 143 "setl-ast.pcc"
#line 143 "setl-ast.pcc"
        ; 
#line 143 "setl-ast.pcc"
      }
    } else { goto L3; }
  }
  L3:;
}
#line 145 "setl-ast.pcc"
#line 145 "setl-ast.pcc"

  return f;
}
#line 148 "setl-ast.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 6
Number of ifs generated      = 8
Number of switches generated = 2
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
