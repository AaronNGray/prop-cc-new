///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "setltype.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_TUPLE2_USED
#include <propdefs.h>
#line 1 "setltype.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the type checker for the SETL-like sublanguage.
//
///////////////////////////////////////////////////////////////////////////////

#include "ir.h"
#include "ast.h"
#include "setl-ast.h"
#include "setlgen.h"
#include "type.h"
#include "env.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Method to elaborate a definition.
//
///////////////////////////////////////////////////////////////////////////////

Env type_of( Def def, const Env& E)
{
  return E;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to elaborate a definition list.
//
///////////////////////////////////////////////////////////////////////////////
Env type_of( Defs defs, const Env& E)
{
  return E;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to unify two expressions type.
//
///////////////////////////////////////////////////////////////////////////////
Bool unify( Exp exp, Ty a, Ty b)
{
  if (! unify(a,b))
  {
    error( "%Ltype mismatch in expression: %f\n"
           "%Lexpecting '%T' but found '%T'\n", exp, a, b);
    return false;
  }
  else
    return true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to infer the type of an expression.
//
///////////////////////////////////////////////////////////////////////////////

Ty type_of( Exp exp, const Env& E)
{
  Ty ty = NOty;
  
#line 61 "setltype.pcc"
#line 121 "setltype.pcc"
{
  if (exp) {
    switch (exp->tag__) {
      case a_Exp::tag_LITERALexp: {
#line 63 "setltype.pcc"
       ty = type_of(((Exp_LITERALexp *)exp)->LITERALexp); 
#line 63 "setltype.pcc"
        } break;
      case a_Exp::tag_IDexp: {
#line 64 "setltype.pcc"
       ty = mkvar(); 
#line 64 "setltype.pcc"
        } break;
      case a_Exp::tag_RELexp: {
#line 73 "setltype.pcc"
       ty = mkvar(); 
#line 73 "setltype.pcc"
        } break;
      case a_Exp::tag_DOTexp: {
#line 74 "setltype.pcc"
       ty = component_ty(type_of(((Exp_DOTexp *)exp)->_1,E),((Exp_DOTexp *)exp)->_2); 
#line 74 "setltype.pcc"
        } break;
      case a_Exp::tag_SELECTORexp: {
#line 75 "setltype.pcc"
       ty = component_ty(type_of(((Exp_SELECTORexp *)exp)->_1,E),((Exp_SELECTORexp *)exp)->_2); 
#line 75 "setltype.pcc"
        } break;
      case a_Exp::tag_DEREFexp: {
#line 76 "setltype.pcc"
       ty = mkvar(); 
#line 76 "setltype.pcc"
        } break;
      case a_Exp::tag_ARROWexp: {
#line 77 "setltype.pcc"
       ty = mkvar(); 
#line 77 "setltype.pcc"
        } break;
      case a_Exp::tag_INDEXexp: {
#line 78 "setltype.pcc"
       ty = mkvar(); 
#line 78 "setltype.pcc"
        } break;
      case a_Exp::tag_BINOPexp: {
#line 79 "setltype.pcc"
       ty = mkvar(); 
#line 79 "setltype.pcc"
        } break;
      case a_Exp::tag_PREFIXexp: {
#line 80 "setltype.pcc"
       ty = mkvar(); 
#line 80 "setltype.pcc"
        } break;
      case a_Exp::tag_POSTFIXexp: {
#line 81 "setltype.pcc"
       ty = mkvar(); 
#line 81 "setltype.pcc"
        } break;
      case a_Exp::tag_APPexp: {
#line 82 "setltype.pcc"
       ty = mkvar(); 
#line 82 "setltype.pcc"
        } break;
      case a_Exp::tag_ASSIGNexp: {
#line 83 "setltype.pcc"
       ty = mkvar(); 
#line 83 "setltype.pcc"
        } break;
      case a_Exp::tag_IFexp: {
#line 84 "setltype.pcc"
       ty = mkvar(); 
#line 84 "setltype.pcc"
        } break;
      case a_Exp::tag_TUPLEexp: {
#line 85 "setltype.pcc"
       return mktuplety(type_of(((Exp_TUPLEexp *)exp)->TUPLEexp,E)); 
#line 85 "setltype.pcc"
        } break;
      case a_Exp::tag_EXTUPLEexp: {
#line 86 "setltype.pcc"
       return extuplety(type_of(((Exp_EXTUPLEexp *)exp)->EXTUPLEexp,E)); 
#line 86 "setltype.pcc"
        } break;
      case a_Exp::tag_RECORDexp: {
#line 88 "setltype.pcc"
        
        
#line 89 "setltype.pcc"
Tuple2<Ids, Tys>  
#line 89 "setltype.pcc"
       t = type_of( ((Exp_RECORDexp *)exp)->RECORDexp, E);
        return mkrecordty( t._1, t._2, false);
        } break;
      case a_Exp::tag_LISTexp: {
        if (((Exp_LISTexp *)exp)->_1) {
#line 94 "setltype.pcc"
          
          Tys head_tys = type_of( ((Exp_LISTexp *)exp)->_3, E);
          	  Ty  tail_ty  = type_of( ((Exp_LISTexp *)exp)->_4, E);
          	  Ty  arg_ty   = mkvar();
          	  for_each (Ty, one_ty, head_tys)
          	    unify( exp, one_ty, arg_ty);
          Ty fun_ty = inst( ((Exp_LISTexp *)exp)->_1->cons_ty);
          	  ty = mkvar();
          	  unify( exp, fun_ty, mkfunty( mktuplety( 
#line 102 "setltype.pcc"
#line 102 "setltype.pcc"
          list_1_(arg_ty,list_1_(mkvar()))
#line 102 "setltype.pcc"
#line 102 "setltype.pcc"
          ), ty));
          if (((Exp_LISTexp *)exp)->_4 != NOexp)
            unify( exp, tail_ty, ty);
          
#line 105 "setltype.pcc"
        } else {
          L1:; 
#line 121 "setltype.pcc"
         ty = NOty; 
#line 121 "setltype.pcc"
        }
        } break;
      case a_Exp::tag_VECTORexp: {
#line 106 "setltype.pcc"
       return mkvar(); 
#line 106 "setltype.pcc"
        } break;
      case a_Exp::tag_CONSexp: {
        if (((Exp_CONSexp *)exp)->_1) {
          if (((Exp_CONSexp *)exp)->_3) {
#line 69 "setltype.pcc"
          Ty fun_ty   = inst(((Exp_CONSexp *)exp)->_1->cons_ty);
            	ty = mkvar();
            	unify(exp,fun_ty,mkfunty(type_of(((Exp_CONSexp *)exp)->_3,E),ty));
                
#line 72 "setltype.pcc"
          } else {
#line 67 "setltype.pcc"
          ty = inst(((Exp_CONSexp *)exp)->_1->cons_ty); 
#line 67 "setltype.pcc"
          }
        } else { goto L1; }
        } break;
      case a_Exp::tag_CASTexp: {
#line 107 "setltype.pcc"
       type_of(((Exp_CASTexp *)exp)->_2,E); return ((Exp_CASTexp *)exp)->_1; 
#line 107 "setltype.pcc"
        } break;
      case a_Exp::tag_QUALexp: {
#line 108 "setltype.pcc"
       return mkvar(); 
#line 108 "setltype.pcc"
        } break;
      case a_Exp::tag_EQexp: {
#line 109 "setltype.pcc"
       return bool_ty; 
#line 109 "setltype.pcc"
        } break;
      case a_Exp::tag_UNIFYexp: {
#line 110 "setltype.pcc"
       return NOty; 
#line 110 "setltype.pcc"
        } break;
      case a_Exp::tag_LTexp: {
#line 111 "setltype.pcc"
       return bool_ty; 
#line 111 "setltype.pcc"
        } break;
      case a_Exp::tag_HASHexp: {
#line 112 "setltype.pcc"
       return integer_ty; 
#line 112 "setltype.pcc"
        } break;
      case a_Exp::tag_THISCOSTexp: {
#line 113 "setltype.pcc"
       return integer_ty; 
#line 113 "setltype.pcc"
        } break;
      case a_Exp::tag_COSTexp: {
#line 114 "setltype.pcc"
       return integer_ty; 
#line 114 "setltype.pcc"
        } break;
      case a_Exp::tag_THISSYNexp: {
#line 115 "setltype.pcc"
       return ((Exp_THISSYNexp *)exp)->_2; 
#line 115 "setltype.pcc"
        } break;
      case a_Exp::tag_SYNexp: {
#line 116 "setltype.pcc"
       return ((Exp_SYNexp *)exp)->_3; 
#line 116 "setltype.pcc"
        } break;
      case a_Exp::tag_SENDexp: {
#line 92 "setltype.pcc"
       return mkvar(); 
#line 92 "setltype.pcc"
        } break;
      case a_Exp::tag_SETLexp: {
#line 117 "setltype.pcc"
       ty = NOty; 
#line 117 "setltype.pcc"
        } break;
      case a_Exp::tag_LISTCOMPexp: {
#line 118 "setltype.pcc"
       ty = NOty; 
#line 118 "setltype.pcc"
        } break;
      case a_Exp::tag_FORALLexp: {
#line 119 "setltype.pcc"
       ty = NOty; 
#line 119 "setltype.pcc"
        } break;
      case a_Exp::tag_EXISTSexp: {
#line 120 "setltype.pcc"
       ty = NOty; 
#line 120 "setltype.pcc"
        } break;
      default: {
#line 65 "setltype.pcc"
       ((Exp_MARKEDexp *)exp)->_1.set_loc(); ty = type_of(((Exp_MARKEDexp *)exp)->_2,E); 
#line 65 "setltype.pcc"
        } break;
    }
  } else {
#line 62 "setltype.pcc"
   ty = NOty; 
#line 62 "setltype.pcc"
  }
}
#line 122 "setltype.pcc"
#line 122 "setltype.pcc"


  ty = deref(ty);
  if (boxed(exp))
    exp->ty = ty;
  return ty;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to infer the type of an expression list.
//
///////////////////////////////////////////////////////////////////////////////

Tys type_of( Exps es, const Env& E)
{
  
#line 138 "setltype.pcc"
#line 140 "setltype.pcc"
{
  if (es) {
#line 140 "setltype.pcc"
    return list_1_(type_of(es->_1,E),type_of(es->_2,E));
#line 140 "setltype.pcc"
  } else {
#line 139 "setltype.pcc"
    return nil_1_;
#line 139 "setltype.pcc"
  }
}
#line 141 "setltype.pcc"
#line 141 "setltype.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to infer the type of an labeled expression list.
//
///////////////////////////////////////////////////////////////////////////////

#line 150 "setltype.pcc"
Tuple2<Ids, Tys>  
#line 150 "setltype.pcc"
 type_of( LabExps es, const Env& E)
{  Ids labels = 
#line 151 "setltype.pcc"
nil_1_
#line 151 "setltype.pcc"
#line 151 "setltype.pcc"
;
   Tys tys    = 
#line 152 "setltype.pcc"
#line 152 "setltype.pcc"
nil_1_
#line 152 "setltype.pcc"
#line 152 "setltype.pcc"
;
   
#line 153 "setltype.pcc"
#line 160 "setltype.pcc"
{
  for (;;) {
    if (es) {
#line 156 "setltype.pcc"
      
      labels = 
#line 157 "setltype.pcc"
#line 157 "setltype.pcc"
      list_1_(es->_1.label,labels)
#line 157 "setltype.pcc"
#line 157 "setltype.pcc"
      ;
      	   tys = 
#line 158 "setltype.pcc"
#line 158 "setltype.pcc"
      list_1_(type_of(es->_1.exp,E),tys)
#line 158 "setltype.pcc"
#line 158 "setltype.pcc"
      ;
      	   es = es->_2;
           
#line 160 "setltype.pcc"
    } else { goto L2; }
  }
  L2:;
}
#line 161 "setltype.pcc"
#line 161 "setltype.pcc"

   return 
#line 162 "setltype.pcc"
#line 162 "setltype.pcc"
mkTuple2(labels,tys)
#line 162 "setltype.pcc"
#line 162 "setltype.pcc"
;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to infer the type of a statement.
//
///////////////////////////////////////////////////////////////////////////////

void type_of (Stmt s, const Env& E)
{
  
#line 173 "setltype.pcc"
#line 185 "setltype.pcc"
{
  if (s) {
    switch (s->tag__) {
      case a_Stmt::tag_ASSIGNstmt: {} break;
      case a_Stmt::tag_BLOCKstmt: {} break;
      case a_Stmt::tag_WHILEstmt: {} break;
      case a_Stmt::tag_IFstmt: {} break;
      case a_Stmt::tag_MATCHstmt: {} break;
      case a_Stmt::tag_REWRITEstmt: {} break;
      case a_Stmt::tag_REPLACEMENTstmt: {} break;
      case a_Stmt::tag_FORALLstmt: {} break;
      default: {} break;
    }
  } else {}
}
#line 185 "setltype.pcc"
#line 185 "setltype.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to infer the type of a list of statements.
//
///////////////////////////////////////////////////////////////////////////////

void type_of( Stmts ss, const Env& E)
{
  
#line 196 "setltype.pcc"
#line 198 "setltype.pcc"
{
  for (;;) {
    if (ss) {
#line 198 "setltype.pcc"
     type_of( ss->_1, E); ss = ss->_2; 
#line 198 "setltype.pcc"
    } else { goto L3; }
  }
  L3:;
}
#line 199 "setltype.pcc"
#line 199 "setltype.pcc"

}
#line 201 "setltype.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 43
Number of ifs generated      = 8
Number of switches generated = 2
Number of labels             = 1
Number of gotos              = 1
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
