///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "printing.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_STRCMP_USED
#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _p_r_i_n_t_i_n_gco_c_c_Q1("x_");
#line 1 "printing.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements various pretty printing and formating routines.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <strstream>
#include <AD/contain/bitset.h>
#include <AD/strings/charesc.h>
#include <AD/strings/quark.h>
#include <cstdio>
#include <cctype>
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "options.h"
#include "list.h"
#include "graphtype.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Flags controlling printing formats of types.
//
///////////////////////////////////////////////////////////////////////////////

Bool      pretty_print_ty      = true;
Bool      pretty_print_pattern = false;
Bool      pretty_print_exp     = false;
Bool      print_semantic_stack = false;
Bool      print_inner_action   = false;
Bool      print_default_value  = true;
Id        ty_id                = 0;
Parameter ty_parameter         = TYformal;

///////////////////////////////////////////////////////////////////////////////
//
//  Print an identifier list
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Ids vars)
{
  for( Ids vs = vars; vs; vs = vs->_2)
  {
    f << vs->_1;
    if (vs->_2)
      f << ", ";
    }
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a scope
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Scope s)
{
  
#line 63 "printing.pcc"
#line 68 "printing.pcc"
{
  switch (s) {
    case PRIVATEscope: {
#line 67 "printing.pcc"
   f << "private";
      
#line 68 "printing.pcc"
      } break;
    case PROTECTEDscope: {
#line 66 "printing.pcc"
     f << "protected";
      
#line 67 "printing.pcc"
      } break;
    default: {
#line 65 "printing.pcc"
  f << "public";
      
#line 66 "printing.pcc"
      } break;
  }
}
#line 68 "printing.pcc"
#line 68 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//  Return the label for an tuple element index
///////////////////////////////////////////////////////////////////////////////

Id index_of( int i, Id prefix)
{
  if (prefix == 0)
    prefix = "";
  return Quark( Quark( prefix, "_"), i);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a persistent id.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Pid pid)
{
  
#line 91 "printing.pcc"
#line 95 "printing.pcc"
{
  if (pid) {
#line 93 "printing.pcc"
   f << pid->PERSISTid; 
#line 93 "printing.pcc"
  } else {}
}
#line 95 "printing.pcc"
#line 95 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a literal.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Literal l)
{
  
#line 107 "printing.pcc"
#line 138 "printing.pcc"
{
  switch (l->tag__) {
    case a_Literal::tag_INTlit: {
#line 109 "printing.pcc"
     f << ((Literal_INTlit *)l)->INTlit; 
#line 109 "printing.pcc"
      } break;
    case a_Literal::tag_BOOLlit: {
#line 110 "printing.pcc"
     f << (((Literal_BOOLlit *)l)->BOOLlit ? "true" : "false"); 
#line 110 "printing.pcc"
      } break;
    case a_Literal::tag_CHARlit: {
#line 111 "printing.pcc"
     char b[32]; print_char(b,((Literal_CHARlit *)l)->CHARlit); f << '\'' << b << '\''; 
#line 111 "printing.pcc"
      } break;
    case a_Literal::tag_REALlit: {
#line 113 "printing.pcc"
      
      // use sprintf due to library problems in libg++ 2.5.8 on Linux
      char buf[256];
      sprintf( buf,"%lf", ((Literal_REALlit *)l)->REALlit);
      f << buf;
      // std::ostrstream S(buf,sizeof(buf));
      // std::ostream& S2 = S;
      // S2 << r << std::ends;
      // f << S.str();
      
#line 122 "printing.pcc"
      } break;
    case a_Literal::tag_STRINGlit: {
#line 123 "printing.pcc"
     f << ((Literal_STRINGlit *)l)->STRINGlit; 
#line 123 "printing.pcc"
      } break;
    case a_Literal::tag_REGEXPlit: {
#line 124 "printing.pcc"
     f << ((Literal_REGEXPlit *)l)->REGEXPlit; 
#line 124 "printing.pcc"
      } break;
    case a_Literal::tag_QUARKlit: {
#line 126 "printing.pcc"
      
      if (pretty_print_pattern)
        f << '#' << ((Literal_QUARKlit *)l)->QUARKlit;
      else
        f << MatchCompiler::quark_name(((Literal_QUARKlit *)l)->QUARKlit);
      
#line 131 "printing.pcc"
      } break;
    default: {
#line 133 "printing.pcc"
      
      if (pretty_print_pattern)
        f << "#" << ((Literal_BIGINTlit *)l)->BIGINTlit;
      else
        f << ((Literal_BIGINTlit *)l)->BIGINTlit;
      
#line 138 "printing.pcc"
      } break;
  }
}
#line 139 "printing.pcc"
#line 139 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type list.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Tys tys)
{
  for(Tys t = tys; t; t = t->_2)
  {
    f << t->_1;
    if (t->_2 != 
#line 154 "printing.pcc"
#line 154 "printing.pcc"
nil_1_
#line 154 "printing.pcc"
#line 154 "printing.pcc"
)
      f << ", ";
  }
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type variables (i.e. template actual arguments)
//
///////////////////////////////////////////////////////////////////////////////
void print_tyvars( std::ostream& f, Tys tys, Bool is_datatype)
{
  if (tys != 
#line 167 "printing.pcc"
#line 167 "printing.pcc"
nil_1_
#line 167 "printing.pcc"
#line 167 "printing.pcc"
)
    if (is_datatype)
      f << "(" << tys << ")";
    else
      f << '<' << tys << "> ";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type variables (i.e. formal template arguments)
//
///////////////////////////////////////////////////////////////////////////////

void print_tyvars( std::ostream& f, TyVars tyvars, char open, char close, Bool header)
{
  if (tyvars != 
#line 182 "printing.pcc"
#line 182 "printing.pcc"
nil_1_
#line 182 "printing.pcc"
#line 182 "printing.pcc"
)
  {
    if (header) f << "template ";
    f << open;
    for(TyVars t = tyvars; t; t = t->_2)
    {
      if (header)
        f << "class ";
      f << t->_1;
      if (t->_2)
        f << ", ";
    }
    f << close;
    if (header)
      f << ' ';
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a tuple type.
//
///////////////////////////////////////////////////////////////////////////////

void print_tuple(std::ostream& f, Tys tys)
{
  if (pretty_print_ty)
    f << '(' << tys << ')';
  else
  {
    f << "struct {";
    int i = 1;
    for (Tys t = tys; t; t = t->_2)
    {
      ty_id = index_of(i);
      f << t->_1 << "; ";
      ty_id = 
#line 218 "printing.pcc"
#line 218 "printing.pcc"
nil_1_
#line 218 "printing.pcc"
#line 218 "printing.pcc"
;
    }
    f << "} ";
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a mktuple type
//
///////////////////////////////////////////////////////////////////////////////

void print_mktuple( std::ostream& f, Tys tys)
{
  if (pretty_print_ty)
    f << ".[" << tys << ']';
  else
  {
    f << "Tuple" << length(tys);
    print_tyvars(f,tys,false);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a record type.
//
///////////////////////////////////////////////////////////////////////////////

void print_record( std::ostream& f, Ids labs, Tys tys, Bool flex)
{
  if ( !pretty_print_ty) f << "struct ";
  f << "{ ";
  Tys t; Ids l;
  for (t = tys, l = labs; t && l; t = t->_2, l = l->_2)
  {
    if (pretty_print_ty)
    {
      f << l->_1 << " : " << t->_1;
      if (t->_2) f << ", ";
    }
    else
    {
      ty_id = l->_1; f << t->_1 << "; ";
      ty_id = 
#line 262 "printing.pcc"
#line 262 "printing.pcc"
nil_1_
#line 262 "printing.pcc"
#line 262 "printing.pcc"
;
    }
  }
  if (pretty_print_ty && flex)
    f << " ... ";
  f << " }";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a function parameter.
//
///////////////////////////////////////////////////////////////////////////////

void print_parameter( std::ostream& f, Ty ty, Id id, Parameter p)
{
  Parameter save = ty_parameter;
  Bool      sp = pretty_print_ty;
  pretty_print_ty = false;
  ty_parameter = p;
  
#line 282 "printing.pcc"
#line 352 "printing.pcc"
{
  Ty _V1 = deref(ty);
  if (_V1) {
    switch (_V1->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V1)->_1)) {
          switch (((Ty_TYCONty *)_V1)->_1->tag__) {
            case a_TyCon::tag_RECORDtycon: {
#line 304 "printing.pcc"
              
              Ids l;
              Tys t;
              if (p == TYformal || p == TYsimpleformal ||
                  p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 308 "printing.pcc"
#line 308 "printing.pcc"
              nil_1_
#line 308 "printing.pcc"
#line 308 "printing.pcc"
              )
              f << '(';
              
              for (l = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V1)->_1)->_1, t = ((Ty_TYCONty *)_V1)->_2; l && t; l = l->_2, t = t->_2)
              {
              if (p != TYbody)
                ty_id = 
#line 314 "printing.pcc"
#line 314 "printing.pcc"
              _p_r_i_n_t_i_n_gco_c_c_Q1
#line 314 "printing.pcc"
#line 314 "printing.pcc"
             + l->_1;
              else
                ty_id = l->_1;
              if (p != TYactual)
                f << t->_1;
              else
                f << ty_id;
              if (p != TYbody)
              {
                if (t->_2)
                  f << ", ";
              }
              else
                f << "; ";
              ty_id = 
#line 328 "printing.pcc"
#line 328 "printing.pcc"
              nil_1_
#line 328 "printing.pcc"
#line 328 "printing.pcc"
              ;
              }
              
              if (p == TYformal || p == TYsimpleformal ||
                  p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 332 "printing.pcc"
#line 332 "printing.pcc"
              nil_1_
#line 332 "printing.pcc"
#line 332 "printing.pcc"
              )
              f << ')';
              
#line 334 "printing.pcc"
              } break;
            default: {
              L1:; 
#line 336 "printing.pcc"
              
              if (p != TYbody)
                f << '(';
              if (p != TYbody)
                ty_id = 
#line 340 "printing.pcc"
#line 340 "printing.pcc"
              _p_r_i_n_t_i_n_gco_c_c_Q1
#line 340 "printing.pcc"
#line 340 "printing.pcc"
             + id;
              else
                ty_id = id;
              if (p != TYactual)
                f << _V1;
              else
                f << ty_id;
              if (p == TYbody)
                f << "; ";
              ty_id = 0;
              if (p != TYbody)
                f << ')';
              
#line 352 "printing.pcc"
              } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)_V1)->_1) {
            case ((int)v_TUPLEtycon): {
#line 285 "printing.pcc"
              
              int i = 1;
              if (p == TYformal || p == TYsimpleformal ||
                  p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 288 "printing.pcc"
#line 288 "printing.pcc"
              nil_1_
#line 288 "printing.pcc"
#line 288 "printing.pcc"
              ) f << '(';
              for (Tys ts = ((Ty_TYCONty *)_V1)->_2; ts; ts = ts->_2)
              {
                ty_id = index_of(i,(p != TYbody ? "x" : ""));
                if (p != TYactual) f << ts->_1;
                else f << ty_id;
                if (p != TYbody) { if (ts->_2) f << ", "; }
                else f << "; ";
                i++;
                ty_id = 
#line 297 "printing.pcc"
#line 297 "printing.pcc"
              nil_1_
#line 297 "printing.pcc"
#line 297 "printing.pcc"
              ;
              }
              if (p == TYformal || p == TYsimpleformal ||
                  p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 300 "printing.pcc"
#line 300 "printing.pcc"
              nil_1_
#line 300 "printing.pcc"
#line 300 "printing.pcc"
              )
              f << ')';
              
#line 302 "printing.pcc"
              } break;
            default: { goto L1; } break;
          }
        }
        } break;
      default: { goto L1; } break;
    }
  } else { goto L1; }
}
#line 353 "printing.pcc"
#line 353 "printing.pcc"

  ty_parameter = save;
  pretty_print_ty = sp;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a type expression.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Ty ty)
{
  Id this_id = 0;
  if (ty_id)
  {
    this_id = ty_id;
    ty_id = 0;
  }

  ty = deref(ty);
  
#line 374 "printing.pcc"
#line 480 "printing.pcc"
{
  if (ty) {
    switch (ty->tag__) {
      case a_Ty::tag_VARty: {
#line 377 "printing.pcc"
       f << "???"; 
#line 377 "printing.pcc"
        } break;
      case a_Ty::tag_INDty: {
#line 378 "printing.pcc"
       f << ((Ty_INDty *)ty)->_1; 
#line 378 "printing.pcc"
        } break;
      case a_Ty::tag_QUALty: {
#line 446 "printing.pcc"
        
        if (((Ty_QUALty *)ty)->_1 & QUALunsigned)
          f << "unsigned ";
        if (((Ty_QUALty *)ty)->_1 & QUALsigned)
          f << "signed ";
        if ((ty_parameter == TYformal || ty_parameter == TYsimpleformal)
        	      && (((Ty_QUALty *)ty)->_1 & QUALclass))
          f << (TYCONty(REFtycon,
#line 453 "printing.pcc"
#line 453 "printing.pcc"
        list_1_(QUALty(QUALconst,((Ty_QUALty *)ty)->_2))
#line 453 "printing.pcc"
#line 453 "printing.pcc"
        ));
        else
          f << ((Ty_QUALty *)ty)->_2;
        if (((Ty_QUALty *)ty)->_1 & QUALconst)
          f << " const";
        
#line 458 "printing.pcc"
        } break;
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)ty)->_1)) {
          switch (((Ty_TYCONty *)ty)->_1->tag__) {
            case a_TyCon::tag_IDtycon: {
#line 391 "printing.pcc"
              
              if (options.new_type_format && ((Ty_TYCONty *)ty)->_2 != 
#line 392 "printing.pcc"
#line 392 "printing.pcc"
              nil_1_
#line 392 "printing.pcc"
#line 392 "printing.pcc"
              )
              {
                
#line 394 "printing.pcc"
#line 411 "printing.pcc"
              {
                Ty _V2 = deref_all(ty);
                if (_V2) {
                  switch (_V2->tag__) {
                    case a_Ty::tag_TYCONty: {
                      if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                        switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                          case a_TyCon::tag_DATATYPEtycon: {
#line 397 "printing.pcc"
                            
                            if ( !pretty_print_ty) f << "a_";
                            f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id; print_tyvars(f,((Ty_TYCONty *)ty)->_2,false);
                            if ( !pretty_print_ty)
                            {
                              if (((Ty_TYCONty *)ty)->_2 == 
#line 402 "printing.pcc"
#line 402 "printing.pcc"
                            nil_1_
#line 402 "printing.pcc"
#line 402 "printing.pcc"
                            )
                            f << ' ';
                            f << "* ";
                            }
                            
#line 406 "printing.pcc"
                            } break;
                          default: {
                            L2:; 
#line 408 "printing.pcc"
                            
                            f << ((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon;
                            print_tyvars(f,((Ty_TYCONty *)ty)->_2,false);
                            
#line 411 "printing.pcc"
                            } break;
                        }
                      } else { goto L2; }
                      } break;
                    default: { goto L2; } break;
                  }
                } else { goto L2; }
              }
#line 412 "printing.pcc"
#line 412 "printing.pcc"
              
              }
              else
              {
                f << ((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon;
                
#line 417 "printing.pcc"
#line 420 "printing.pcc"
              {
                Ty _V3 = deref_all(ty);
                if (_V3) {
                  switch (_V3->tag__) {
                    case a_Ty::tag_TYCONty: {
                      if (boxed(((Ty_TYCONty *)_V3)->_1)) {
                        switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                          case a_TyCon::tag_DATATYPEtycon: {
#line 419 "printing.pcc"
                           print_tyvars( f, ((Ty_TYCONty *)ty)->_2, !pretty_print_ty); 
#line 419 "printing.pcc"
                            } break;
                          default: {
                            L3:; 
#line 420 "printing.pcc"
                           print_tyvars( f, ((Ty_TYCONty *)ty)->_2, false); 
#line 420 "printing.pcc"
                            } break;
                        }
                      } else { goto L3; }
                      } break;
                    default: { goto L3; } break;
                  }
                } else { goto L3; }
              }
#line 421 "printing.pcc"
#line 421 "printing.pcc"
              
              }
              
#line 423 "printing.pcc"
              } break;
            case a_TyCon::tag_RECORDtycon: {
#line 389 "printing.pcc"
             print_record(f,((TyCon_RECORDtycon *)((Ty_TYCONty *)ty)->_1)->_1,((Ty_TYCONty *)ty)->_2,((TyCon_RECORDtycon *)((Ty_TYCONty *)ty)->_1)->_2); 
#line 389 "printing.pcc"
              } break;
            case a_TyCon::tag_ARRAYtycon: {
              if (((Ty_TYCONty *)ty)->_2) {
                if (((Ty_TYCONty *)ty)->_2->_2) {
                  L4:; 
#line 478 "printing.pcc"
                  
                  bug ("operator << (std::ostream&, Ty)");
                  
#line 480 "printing.pcc"
                } else {
#line 425 "printing.pcc"
                  
                  if (this_id)
                  {
                    ty_id = this_id;
                    this_id = 0;
                  }
                  f << ((Ty_TYCONty *)ty)->_2->_1 << '[' << ((TyCon_ARRAYtycon *)((Ty_TYCONty *)ty)->_1)->ARRAYtycon << ']';
                  
#line 432 "printing.pcc"
                }
              } else { goto L4; }
              } break;
            case a_TyCon::tag_DATATYPEtycon: {
              if (((Ty_TYCONty *)ty)->_2) {
#line 461 "printing.pcc"
                
                if ( !pretty_print_ty)
                  f << "a_";
                f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->id;
                print_tyvars( f, ((Ty_TYCONty *)ty)->_2, false);
                if ( !pretty_print_ty)
                {
                  if (((Ty_TYCONty *)ty)->_2 == 
#line 468 "printing.pcc"
#line 468 "printing.pcc"
                nil_1_
#line 468 "printing.pcc"
#line 468 "printing.pcc"
                )
                f << ' ';
                f << "* ";
                }
                
#line 472 "printing.pcc"
              } else {
#line 459 "printing.pcc"
               f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->id; 
#line 459 "printing.pcc"
              }
              } break;
            case a_TyCon::tag_GRAPHtycon: {
#line 384 "printing.pcc"
             f << ((TyCon_GRAPHtycon *)((Ty_TYCONty *)ty)->_1)->GRAPHtycon->class_name; 
#line 384 "printing.pcc"
              } break;
            case a_TyCon::tag_NODEtycon: {
#line 385 "printing.pcc"
             f << ((TyCon_NODEtycon *)((Ty_TYCONty *)ty)->_1)->NODEtycon->graph()->class_name <<"::"<< ((TyCon_NODEtycon *)((Ty_TYCONty *)ty)->_1)->NODEtycon->name(); 
#line 385 "printing.pcc"
              } break;
            case a_TyCon::tag_EDGEtycon: {
#line 386 "printing.pcc"
             f << "edge " << ((TyCon_EDGEtycon *)((Ty_TYCONty *)ty)->_1)->EDGEtycon->name(); 
#line 386 "printing.pcc"
              } break;
            default: { goto L4; } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)ty)->_1) {
            case ((int)v_POINTERtycon): {
              if (((Ty_TYCONty *)ty)->_2) {
                if (((Ty_TYCONty *)ty)->_2->_2) { goto L4; } else {
#line 381 "printing.pcc"
                 f << ((Ty_TYCONty *)ty)->_2->_1 << " *"; 
#line 381 "printing.pcc"
                }
              } else { goto L4; }
              } break;
            case ((int)v_REFtycon): {
              if (((Ty_TYCONty *)ty)->_2) {
                if (((Ty_TYCONty *)ty)->_2->_2) { goto L4; } else {
#line 382 "printing.pcc"
                 f << ((Ty_TYCONty *)ty)->_2->_1 << " &"; 
#line 382 "printing.pcc"
                }
              } else { goto L4; }
              } break;
            case ((int)v_TUPLEtycon): {
#line 387 "printing.pcc"
             print_tuple(f,((Ty_TYCONty *)ty)->_2); 
#line 387 "printing.pcc"
              } break;
            case ((int)v_EXTUPLEtycon): {
#line 388 "printing.pcc"
             print_mktuple(f,((Ty_TYCONty *)ty)->_2); 
#line 388 "printing.pcc"
              } break;
            case ((int)v_FUNtycon): {
              if (((Ty_TYCONty *)ty)->_2) {
                if (((Ty_TYCONty *)ty)->_2->_2) {
                  if (((Ty_TYCONty *)ty)->_2->_2->_2) { goto L4; } else {
#line 383 "printing.pcc"
                   f << ((Ty_TYCONty *)ty)->_2->_1 << " -> " << ((Ty_TYCONty *)ty)->_2->_2->_1; 
#line 383 "printing.pcc"
                  }
                } else { goto L4; }
              } else { goto L4; }
              } break;
            default: {
              if (((Ty_TYCONty *)ty)->_2) { goto L4; } else {
#line 380 "printing.pcc"
               f << "type"; 
#line 380 "printing.pcc"
              }
              } break;
          }
        }
        } break;
      case a_Ty::tag_POLYty: {
#line 379 "printing.pcc"
       f << ((Ty_POLYty *)ty)->_1; 
#line 379 "printing.pcc"
        } break;
      case a_Ty::tag_DEFVALty: {
#line 434 "printing.pcc"
        
        if (this_id)
        {
          ty_id = this_id;
          this_id = 0;
        }
        f << ((Ty_DEFVALty *)ty)->_1;
        if (ty_parameter != TYbody && ty_parameter != TYsimpleformal
        	      && print_default_value)
        	    f << " = " << ((Ty_DEFVALty *)ty)->_2;
        
#line 444 "printing.pcc"
        } break;
      default: {
#line 474 "printing.pcc"
        
        f << ((Ty_NESTEDty *)ty)->_1 << "::" << ((Ty_NESTEDty *)ty)->_2;
        
#line 476 "printing.pcc"
        } break;
    }
  } else {
#line 376 "printing.pcc"
   f << "error"; 
#line 376 "printing.pcc"
  }
}
#line 481 "printing.pcc"
#line 481 "printing.pcc"

  if (this_id)
    f << ' ' << this_id;
  return f;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern list.
//
///////////////////////////////////////////////////////////////////////////////

void print( std::ostream& f, Pats pats, Id open, Id close,
            Bool flex1, Pat p, Bool flex2 = false,
            Pat len = NOpat, Pat array = NOpat)
{
  f << open;
  if (len != NOpat)
  {
    f << " |" << len;
    if (array != NOpat)
      f << " : " << array;
    f << " |";
  }
  if (flex2)
    f << " ... ";
  for (Pats ps = pats; ps; ps = ps->_2)
  {
    f << ps->_1;
    if (ps->_2)
      f << ", ";
  }
  if (flex1 && pats != 
#line 514 "printing.pcc"
#line 514 "printing.pcc"
nil_1_
#line 514 "printing.pcc"
#line 514 "printing.pcc"
 && p != NOpat)
    f << " ... ";
  if (p != NOpat)
    f << p;
  f << close;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a labeled pattern list.
//
///////////////////////////////////////////////////////////////////////////////

void print( std::ostream& f, LabPats lab_pats, Bool flex)
{
  f << '{';
  for (LabPats ps = lab_pats; ps; ps = ps->_2)
  {
    f << ps->_1.label << " = " << ps->_1.pat;
    if (ps->_2)
      f << ", ";
  }
  f << '}';
}

///////////////////////////////////////////////////////////////////////////////
//
//  Methods extract the open and close brace of a list.
//
///////////////////////////////////////////////////////////////////////////////

Id open_of( Cons c)
{
  
#line 547 "printing.pcc"
#line 558 "printing.pcc"
{
  if (c) {
#line 550 "printing.pcc"
    
    char s[3];
    s[0] = c->name[0];
    s[1] = c->name[1];
    s[2] = '\0';
    return Quark(s);
    
#line 556 "printing.pcc"
  } else {
#line 558 "printing.pcc"
   return "<??" ">["; 
#line 558 "printing.pcc"
  }
}
#line 559 "printing.pcc"
#line 559 "printing.pcc"

}

Id close_of( Cons c)
{
  
#line 564 "printing.pcc"
#line 567 "printing.pcc"
{
  if (c) {
#line 566 "printing.pcc"
   return c->name+2; 
#line 566 "printing.pcc"
  } else {
#line 567 "printing.pcc"
   return "]"; 
#line 567 "printing.pcc"
  }
}
#line 568 "printing.pcc"
#line 568 "printing.pcc"

}

Id close_of2( Cons c)
{
  
#line 573 "printing.pcc"
#line 576 "printing.pcc"
{
  if (c) {
#line 575 "printing.pcc"
   return c->name + std::strlen( c->name) - 2; 
#line 575 "printing.pcc"
  } else {
#line 576 "printing.pcc"
   return "]"; 
#line 576 "printing.pcc"
  }
}
#line 577 "printing.pcc"
#line 577 "printing.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern list.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Pats ps)
{
  print( f, ps, "", "", false, NOpat);
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Pat p)
{
  
#line 600 "printing.pcc"
#line 654 "printing.pcc"
{
  if (p) {
    switch (p->tag__) {
      case a_Pat::tag_WILDpat: {
#line 603 "printing.pcc"
       f << '_'; 
#line 603 "printing.pcc"
        } break;
      case a_Pat::tag_INDpat: {
#line 606 "printing.pcc"
       f << '?' << ((Pat_INDpat *)p)->_1; 
#line 606 "printing.pcc"
        } break;
      case a_Pat::tag_POLYpat: {
        if (((Pat_POLYpat *)p)->_3) {
#line 631 "printing.pcc"
         f << ((Pat_POLYpat *)p)->_1 << '(' << ((Pat_POLYpat *)p)->_3 << ") = " << ((Pat_POLYpat *)p)->_4; 
#line 631 "printing.pcc"
        } else {
#line 630 "printing.pcc"
         f << ((Pat_POLYpat *)p)->_1 << " = " << ((Pat_POLYpat *)p)->_4; 
#line 630 "printing.pcc"
        }
        } break;
      case a_Pat::tag_IDpat: {
#line 605 "printing.pcc"
       f << ((Pat_IDpat *)p)->_1; 
#line 605 "printing.pcc"
        } break;
      case a_Pat::tag_CONSpat: {
        if (((Pat_CONSpat *)p)->CONSpat) {
          if (((Pat_CONSpat *)p)->CONSpat->alg_ty) {
            switch (((Pat_CONSpat *)p)->CONSpat->alg_ty->tag__) {
              case a_Ty::tag_TYCONty: {
                if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1->tag__) {
                    case a_TyCon::tag_DATATYPEtycon: {
                      if (
#line 624 "printing.pcc"
                      (((Pat_CONSpat *)p)->CONSpat->qual & QUALvariable)
#line 624 "printing.pcc"
) {
                        
#line 625 "printing.pcc"
                       f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1)->id << "?"; 
#line 625 "printing.pcc"
                      } else {
                        
                        L5:; 
#line 626 "printing.pcc"
                       f << ((Pat_CONSpat *)p)->CONSpat->name; 
#line 626 "printing.pcc"
                      }
                      } break;
                    default: { goto L5; } break;
                  }
                } else { goto L5; }
                } break;
              default: { goto L5; } break;
            }
          } else { goto L5; }
        } else {
#line 627 "printing.pcc"
         f << "<none>"; 
#line 627 "printing.pcc"
        }
        } break;
      case a_Pat::tag_APPpat: {
#line 628 "printing.pcc"
       f << ((Pat_APPpat *)p)->_1 << ' ' << ((Pat_APPpat *)p)->_2; 
#line 628 "printing.pcc"
        } break;
      case a_Pat::tag_TYPEDpat: {
#line 608 "printing.pcc"
       f << ((Pat_TYPEDpat *)p)->_1 << " : " << ((Pat_TYPEDpat *)p)->_2; 
#line 608 "printing.pcc"
        } break;
      case a_Pat::tag_ASpat: {
#line 607 "printing.pcc"
       f << ((Pat_ASpat *)p)->_1 << " as " << ((Pat_ASpat *)p)->_2; 
#line 607 "printing.pcc"
        } break;
      case a_Pat::tag_LITERALpat: {
#line 649 "printing.pcc"
        
        Bool save = pretty_print_pattern;
        pretty_print_pattern = true;
        f << ((Pat_LITERALpat *)p)->LITERALpat;
        pretty_print_pattern = save;
        
#line 654 "printing.pcc"
        } break;
      case a_Pat::tag_CONTEXTpat: {
#line 637 "printing.pcc"
        
        f << "<<";
        for (Conses ids = ((Pat_CONTEXTpat *)p)->_1; ids; ids = ids->_2)
        {
          if (ids->_1 != NOcons)
            f << ids->_1->name;
          if (ids->_2)
            f << ", ";
        }
        f << ">>" << ((Pat_CONTEXTpat *)p)->_2;
        
#line 647 "printing.pcc"
        } break;
      case a_Pat::tag_LEXEMEpat: {
#line 629 "printing.pcc"
       f << "lexeme class " << ((Pat_LEXEMEpat *)p)->_1; 
#line 629 "printing.pcc"
        } break;
      case a_Pat::tag_ARRAYpat: {
#line 611 "printing.pcc"
       print(f,((Pat_ARRAYpat *)p)->_1,"[","]",((Pat_ARRAYpat *)p)->_2,NOpat); 
#line 611 "printing.pcc"
        } break;
      case a_Pat::tag_TUPLEpat: {
#line 609 "printing.pcc"
       print(f,((Pat_TUPLEpat *)p)->TUPLEpat,"(",")",false,NOpat); 
#line 609 "printing.pcc"
        } break;
      case a_Pat::tag_EXTUPLEpat: {
#line 610 "printing.pcc"
       print(f,((Pat_EXTUPLEpat *)p)->EXTUPLEpat,".(",")",false,NOpat); 
#line 610 "printing.pcc"
        } break;
      case a_Pat::tag_RECORDpat: {
#line 612 "printing.pcc"
       print(f,((Pat_RECORDpat *)p)->_1,((Pat_RECORDpat *)p)->_2); 
#line 612 "printing.pcc"
        } break;
      case a_Pat::tag_LISTpat: {
#line 635 "printing.pcc"
       print( f, ((Pat_LISTpat *)p)->head, open_of(((Pat_LISTpat *)p)->nil), close_of(((Pat_LISTpat *)p)->nil), true, ((Pat_LISTpat *)p)->tail); 
#line 635 "printing.pcc"
        } break;
      case a_Pat::tag_VECTORpat: {
#line 633 "printing.pcc"
       print( f, ((Pat_VECTORpat *)p)->elements, open_of(((Pat_VECTORpat *)p)->cons), close_of2(((Pat_VECTORpat *)p)->cons), ((Pat_VECTORpat *)p)->tail_flex, NOpat, ((Pat_VECTORpat *)p)->head_flex, ((Pat_VECTORpat *)p)->len, ((Pat_VECTORpat *)p)->array); 
#line 633 "printing.pcc"
        } break;
      case a_Pat::tag_APPENDpat: {
#line 620 "printing.pcc"
       f << '(' << ((Pat_APPENDpat *)p)->_1 << " ; " << ((Pat_APPENDpat *)p)->_2 << ')'; 
#line 620 "printing.pcc"
        } break;
      case a_Pat::tag_GUARDpat: {
#line 619 "printing.pcc"
       f << ((Pat_GUARDpat *)p)->_1 << " | " << ((Pat_GUARDpat *)p)->_2; 
#line 619 "printing.pcc"
        } break;
      case a_Pat::tag_LOGICALpat: {
        switch (((Pat_LOGICALpat *)p)->_1) {
          case NOTpat: {
#line 613 "printing.pcc"
           f << "(! " << ((Pat_LOGICALpat *)p)->_2 << ")"; 
#line 613 "printing.pcc"
            } break;
          case ANDpat: {
#line 614 "printing.pcc"
           f << '(' << ((Pat_LOGICALpat *)p)->_2 << " && " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 614 "printing.pcc"
            } break;
          case ORpat: {
#line 615 "printing.pcc"
           f << '(' << ((Pat_LOGICALpat *)p)->_2 << " || " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 615 "printing.pcc"
            } break;
          case EQUIVpat: {
#line 617 "printing.pcc"
           f << '(' << ((Pat_LOGICALpat *)p)->_2 << " equiv: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 617 "printing.pcc"
            } break;
          case XORpat: {
#line 618 "printing.pcc"
           f << '(' << ((Pat_LOGICALpat *)p)->_2 << " xor: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 618 "printing.pcc"
            } break;
          default: {
#line 616 "printing.pcc"
           f << '(' << ((Pat_LOGICALpat *)p)->_2 << " implies: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 616 "printing.pcc"
            } break;
        }
        } break;
      case a_Pat::tag_BACKEDGEpat: {
#line 604 "printing.pcc"
       f << '<' << ((Pat_BACKEDGEpat *)p)->_2 << '>'; 
#line 604 "printing.pcc"
        } break;
      case a_Pat::tag_UNIFYpat: {
#line 621 "printing.pcc"
       f << '(' << ((Pat_UNIFYpat *)p)->_1 << " := " << ((Pat_UNIFYpat *)p)->_2 << ")"; 
#line 621 "printing.pcc"
        } break;
      default: {
#line 622 "printing.pcc"
       f << ((Pat_MARKEDpat *)p)->_2; 
#line 622 "printing.pcc"
        } break;
    }
  } else {}
}
#line 655 "printing.pcc"
#line 655 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a string into a suitable encoding
//
///////////////////////////////////////////////////////////////////////////////

void encode_string( char * buf, const char * s)
{
  while (*s)
  {
    unsigned char c = *s++;
    if (c == '"')
    {
      *buf++ = 'X';
      *buf++ = 'X';
    }
    else if (std::isalnum(c) || c == '_')
    {
      *buf++ = '_';
      *buf++ = c;
    }
    else
    {
       int lo = c % 16, hi = c / 16;
       *buf++ = hi + 'a';
       *buf++ = lo + 'a';
    }
  }
  *buf++ = '\0';
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print the mangled name of list constructors.
//
///////////////////////////////////////////////////////////////////////////////

#line 696 "printing.pcc"
#line 713 "printing.pcc"
Id mangle (char const * x_1);
Id mangle (char const * x_1)
{
  if ((x_1 == 0)) {
    
#line 696 "printing.pcc"
   return "(null)"; 
#line 696 "printing.pcc"
  } else {
    
    if (_less_string(x_1,"#{}")) {
      if (_less_string(x_1,"#[]")) {
        if (_equal_string(x_1,"#()")) {
#line 701 "printing.pcc"
       return "nil_2_"; 
#line 701 "printing.pcc"
}
        else if (_equal_string(x_1,"#(...)")) {
#line 698 "printing.pcc"
       return "list_2_"; 
#line 698 "printing.pcc"
}
        else if (_equal_string(x_1,"#[...]")) {
#line 697 "printing.pcc"
       return "list_1_"; 
#line 697 "printing.pcc"
}
        else {
        if ((x_1[0] == '\"')) {
          
#line 707 "printing.pcc"
          
          char buf[256];
          encode_string( buf, x_1);
          return Quark( buf);
          
#line 711 "printing.pcc"
        } else {
          
#line 712 "printing.pcc"
         return x_1; 
#line 712 "printing.pcc"
        }
}
      } else {
        if (_equal_string(x_1,"#[]")) {
#line 700 "printing.pcc"
       return "nil_1_"; 
#line 700 "printing.pcc"
}
        else if (_equal_string(x_1,"#{...}")) {
#line 699 "printing.pcc"
       return "list_3_"; 
#line 699 "printing.pcc"
}
        else {
        if ((x_1[0] == '\"')) {
          
#line 707 "printing.pcc"
          
          char buf[256];
          encode_string( buf, x_1);
          return Quark( buf);
          
#line 711 "printing.pcc"
        } else {
          
#line 712 "printing.pcc"
         return x_1; 
#line 712 "printing.pcc"
        }
}
      }
    } else {
      if (_equal_string(x_1,"#{}")) {
#line 702 "printing.pcc"
     return "nil_3_"; 
#line 702 "printing.pcc"
}
      else if (_equal_string(x_1,"(|...|)")) {
#line 704 "printing.pcc"
     return "vector_2_"; 
#line 704 "printing.pcc"
}
      else if (_equal_string(x_1,"[|...|]")) {
#line 703 "printing.pcc"
     return "vector_1_"; 
#line 703 "printing.pcc"
}
      else if (_equal_string(x_1,"{|...|}")) {
#line 705 "printing.pcc"
     return "vector_3_"; 
#line 705 "printing.pcc"
}
      else {
      if ((x_1[0] == '\"')) {
        
#line 707 "printing.pcc"
        
        char buf[256];
        encode_string( buf, x_1);
        return Quark( buf);
        
#line 711 "printing.pcc"
      } else {
        
#line 712 "printing.pcc"
       return x_1; 
#line 712 "printing.pcc"
      }
}
    }
  }
}
#line 713 "printing.pcc"
#line 713 "printing.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Method to print the name of a constructor
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& print_cons( std::ostream& f, Cons cons)
{
  
#line 723 "printing.pcc"
#line 734 "printing.pcc"
{
  if (cons) {
    if (cons->alg_ty) {
      switch (cons->alg_ty->tag__) {
        case a_Ty::tag_TYCONty: {
          if (cons->ty) {
            if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
              switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                case a_TyCon::tag_DATATYPEtycon: {
                  L6:; 
#line 727 "printing.pcc"
                  
                  if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->opt & OPTsubclassless)
                    f << "a_" << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->id;
                  else
                    f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->id << "_" << mangle( cons->name);
                  
#line 732 "printing.pcc"
                  } break;
                default: {
                  L7:; 
#line 734 "printing.pcc"
                bug("print_cons()"); 
#line 734 "printing.pcc"
                  } break;
              }
            } else { goto L7; }
          } else {
            L8:; 
#line 725 "printing.pcc"
          f << mangle(cons->name); 
#line 725 "printing.pcc"
          }
          } break;
        default: {
          L9:; 
          if (cons->ty) { goto L7; } else { goto L8; }
          } break;
      }
    } else { goto L9; }
  } else { goto L7; }
}
#line 735 "printing.pcc"
#line 735 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an expression list
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Exps es)
{
  for (Exps l = es; l; l = l->_2)
  {
    f << l->_1;
    if (l->_2)
      f << ',';
  }
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an expression.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Exp e)
{
  
#line 764 "printing.pcc"
#line 974 "printing.pcc"
{
  if (e) {
    switch (e->tag__) {
      case a_Exp::tag_LITERALexp: {
#line 771 "printing.pcc"
       f << ((Exp_LITERALexp *)e)->LITERALexp; 
#line 771 "printing.pcc"
        } break;
      case a_Exp::tag_IDexp: {
#line 767 "printing.pcc"
       f << ((Exp_IDexp *)e)->IDexp; 
#line 767 "printing.pcc"
        } break;
      case a_Exp::tag_RELexp: {
        if (
#line 768 "printing.pcc"
        same_selectors
#line 768 "printing.pcc"
) {
          
#line 768 "printing.pcc"
         f << "_0"; 
#line 768 "printing.pcc"
        } else {
          
#line 769 "printing.pcc"
         f << '_' << ((Exp_RELexp *)e)->RELexp; 
#line 769 "printing.pcc"
        }
        } break;
      case a_Exp::tag_DOTexp: {
        if (((Exp_DOTexp *)e)->_1) {
          switch (((Exp_DOTexp *)e)->_1->tag__) {
            case a_Exp::tag_SELECTORexp: {
              if (
#line 773 "printing.pcc"
              pretty_print_exp
#line 773 "printing.pcc"
) {
                
#line 774 "printing.pcc"
                
                f << ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_1 << '!' << ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_2->name << '.';
                	  int n = std::atol(((Exp_DOTexp *)e)->_2+1);
                	  if (n > 0)
                	    f << n;
                	  else
                	    f << ((Exp_DOTexp *)e)->_2;
                
#line 781 "printing.pcc"
              } else {
                
#line 785 "printing.pcc"
               f << MatchCompiler::make_select( ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_1, ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_2, ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_3, ((Exp_DOTexp *)e)->_2); 
#line 785 "printing.pcc"
              }
              } break;
            case a_Exp::tag_DEREFexp: {
#line 788 "printing.pcc"
             f << ((Exp_DEREFexp *)((Exp_DOTexp *)e)->_1)->DEREFexp << "->" << ((Exp_DOTexp *)e)->_2; 
#line 788 "printing.pcc"
              } break;
            default: {
              L10:; 
#line 789 "printing.pcc"
             f << ((Exp_DOTexp *)e)->_1 << '.' << ((Exp_DOTexp *)e)->_2; 
#line 789 "printing.pcc"
              } break;
          }
        } else { goto L10; }
        } break;
      case a_Exp::tag_SELECTORexp: {
        if (
#line 782 "printing.pcc"
        pretty_print_exp
#line 782 "printing.pcc"
) {
          
#line 783 "printing.pcc"
         f << ((Exp_SELECTORexp *)e)->_1 << '!' << ((Exp_SELECTORexp *)e)->_2->name; 
#line 783 "printing.pcc"
        } else {
          
#line 787 "printing.pcc"
         f << MatchCompiler::make_select( ((Exp_SELECTORexp *)e)->_1, ((Exp_SELECTORexp *)e)->_2, ((Exp_SELECTORexp *)e)->_3); 
#line 787 "printing.pcc"
        }
        } break;
      case a_Exp::tag_DEREFexp: {
#line 790 "printing.pcc"
       f << "(*" << ((Exp_DEREFexp *)e)->DEREFexp << ')'; 
#line 790 "printing.pcc"
        } break;
      case a_Exp::tag_ARROWexp: {
#line 791 "printing.pcc"
       f << ((Exp_ARROWexp *)e)->_1 << "->" << ((Exp_ARROWexp *)e)->_2; 
#line 791 "printing.pcc"
        } break;
      case a_Exp::tag_INDEXexp: {
#line 793 "printing.pcc"
       f << ((Exp_INDEXexp *)e)->_1 << '[' << ((Exp_INDEXexp *)e)->_2 << ']'; 
#line 793 "printing.pcc"
        } break;
      case a_Exp::tag_BINOPexp: {
#line 794 "printing.pcc"
       f << '(' << ((Exp_BINOPexp *)e)->_2 << ' ' << ((Exp_BINOPexp *)e)->_1 << ' ' << ((Exp_BINOPexp *)e)->_3 << ')'; 
#line 794 "printing.pcc"
        } break;
      case a_Exp::tag_PREFIXexp: {
#line 795 "printing.pcc"
       f << '(' << ((Exp_PREFIXexp *)e)->_1 << ' ' << ((Exp_PREFIXexp *)e)->_2 << ')'; 
#line 795 "printing.pcc"
        } break;
      case a_Exp::tag_POSTFIXexp: {
#line 796 "printing.pcc"
       f << '(' << ((Exp_POSTFIXexp *)e)->_2 << ' ' << ((Exp_POSTFIXexp *)e)->_1 << ')'; 
#line 796 "printing.pcc"
        } break;
      case a_Exp::tag_APPexp: {
#line 792 "printing.pcc"
       f << ((Exp_APPexp *)e)->_1 << '(' << ((Exp_APPexp *)e)->_2 << ')'; 
#line 792 "printing.pcc"
        } break;
      case a_Exp::tag_ASSIGNexp: {
#line 772 "printing.pcc"
       f << '(' << ((Exp_ASSIGNexp *)e)->_1 << " = " << ((Exp_ASSIGNexp *)e)->_2 << ')'; 
#line 772 "printing.pcc"
        } break;
      case a_Exp::tag_IFexp: {
#line 811 "printing.pcc"
       f << '(' << ((Exp_IFexp *)e)->_1 << " ? " << ((Exp_IFexp *)e)->_2 << " : " << ((Exp_IFexp *)e)->_3 <<')';
#line 811 "printing.pcc"
        } break;
      case a_Exp::tag_TUPLEexp: {
#line 809 "printing.pcc"
       f << ((Exp_TUPLEexp *)e)->TUPLEexp; 
#line 809 "printing.pcc"
        } break;
      case a_Exp::tag_EXTUPLEexp: {
#line 810 "printing.pcc"
       f << "mkTuple" << length(((Exp_EXTUPLEexp *)e)->EXTUPLEexp) << '(' << ((Exp_EXTUPLEexp *)e)->EXTUPLEexp << ')'; 
#line 810 "printing.pcc"
        } break;
      case a_Exp::tag_RECORDexp: {
#line 917 "printing.pcc"
        
        f << "{ ";
        for (LabExps l = ((Exp_RECORDexp *)e)->RECORDexp; l; l = l->_2)
          {
          f << l->_1.label << " = " << l->_1.exp;
          if (l->_2)
            f << ", ";
        }
        f << " }";
        
#line 926 "printing.pcc"
        } break;
      case a_Exp::tag_LISTexp: {
        if (
#line 927 "printing.pcc"
        pretty_print_exp
#line 927 "printing.pcc"
) {
          
#line 928 "printing.pcc"
          
          f << open_of(((Exp_LISTexp *)e)->_2);
          	  for( Exps exp_list = ((Exp_LISTexp *)e)->_3; exp_list; exp_list = exp_list->_2)
          	  {
          	    f << exp_list->_1;
          	    if (exp_list->_2)
          	      f << ", ";
          }
          	  if (((Exp_LISTexp *)e)->_4 != NOexp)
          	    f << " ... " << ((Exp_LISTexp *)e)->_4;
          f << close_of(((Exp_LISTexp *)e)->_2);
          
#line 939 "printing.pcc"
        } else {
          
          if (((Exp_LISTexp *)e)->_1) {
            if (((Exp_LISTexp *)e)->_2) {
#line 941 "printing.pcc"
              
              int i = 0;
              for( Exps exp_list = ((Exp_LISTexp *)e)->_3; exp_list; exp_list = exp_list->_2)
              	  {
              	    Exp exp = exp_list->_1;
                f << mangle(((Exp_LISTexp *)e)->_1->name) << '(' << exp;
              	    if (exp_list->_2)
              	      f << ',';
              	    i++;
              }
              if (((Exp_LISTexp *)e)->_4 != NOexp)
                f << ',' << ((Exp_LISTexp *)e)->_4;
              	  else if (((Exp_LISTexp *)e)->_3 == 
#line 953 "printing.pcc"
#line 953 "printing.pcc"
              nil_1_
#line 953 "printing.pcc"
#line 953 "printing.pcc"
              )
              	    f << mangle(((Exp_LISTexp *)e)->_2->name);
                    while (i-- > 0)
                      f << ')';
                  
#line 957 "printing.pcc"
            } else {
              L11:; }
          } else { goto L11; }
        }
        } break;
      case a_Exp::tag_VECTORexp: {
        if (((Exp_VECTORexp *)e)->_1) {
#line 960 "printing.pcc"
          
          f << mangle(((Exp_VECTORexp *)e)->_1->name) << '(';
          {
            for(Exps exps = ((Exp_VECTORexp *)e)->_2; exps; exps = exps->_2)
            {
              f << exps->_1;
              if (exps->_2 != 
#line 966 "printing.pcc"
#line 966 "printing.pcc"
          nil_1_
#line 966 "printing.pcc"
#line 966 "printing.pcc"
          )
          f << ',';
          }
          }
          f << ')';
          
#line 971 "printing.pcc"
        } else {}
        } break;
      case a_Exp::tag_CONSexp: {
        if (((Exp_CONSexp *)e)->_1) {
          if (((Exp_CONSexp *)e)->_3) {
            switch (((Exp_CONSexp *)e)->_3->tag__) {
              case a_Exp::tag_RECORDexp: {
                if (((Exp_CONSexp *)e)->_1->ty) {
                  switch (((Exp_CONSexp *)e)->_1->ty->tag__) {
                    case a_Ty::tag_TYCONty: {
                      if (boxed(((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)) {
                        switch (((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1->tag__) {
                          case a_TyCon::tag_RECORDtycon: {
                            if (((Exp_CONSexp *)e)->_3) {
                              switch (((Exp_CONSexp *)e)->_3->tag__) {
                                case a_Exp::tag_RECORDexp: {
                                  L12:; 
#line 838 "printing.pcc"
                                // rearrange arguments to
                                  if (((Exp_CONSexp *)e)->_2)
                                  {
                                    f << "new (" << ((Exp_CONSexp *)e)->_2 << ") ";
                                    print_cons( f, ((Exp_CONSexp *)e)->_1);
                                  }
                                  else
                                    f << mangle(((Exp_CONSexp *)e)->_1->name);
                                  
                                  f << '(';
                                  
                                  {
                                    for_each ( LabExp, i, ((Exp_RECORDexp *)((Exp_CONSexp *)e)->_3)->RECORDexp)
                                    {
                                      for_each ( Id, j, ((TyCon_RECORDtycon *)((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)->_1)
                                        if (i.label == j)
                                          goto next;
                                      error( "%Lillegal record label '%s' in expression: %s%e\n",
                                             i.label, ((Exp_CONSexp *)e)->_1->name, ((Exp_CONSexp *)e)->_3);
                                      next: ;
                                    }
                                  }
                                  {
                                    Bool comma = false;
                                    Ids is; Tys ts;
                                    for(is = ((TyCon_RECORDtycon *)((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)->_1, ts = ((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_2; is; is = is->_2, ts = ts->_2)
                                    {
                                      Id i = is->_1;
                                      Bool found = false;
                                      for_each (LabExp, j, ((Exp_RECORDexp *)((Exp_CONSexp *)e)->_3)->RECORDexp)
                                      {
                                        if (i == j.label) {
                                          if (found)
                                            error( "%Lduplicated label '%s' in expression: %s%e\n",
                                                   j.label, ((Exp_CONSexp *)e)->_1->name, ((Exp_CONSexp *)e)->_3);
                                          found = true;
                                          if (comma)
                                            f << ", ";
                                          comma = true;
                                          f << j.exp;
                                        }
                                      }
                                      if ( !found)
                                      {
                                        
#line 882 "printing.pcc"
#line 892 "printing.pcc"
                                  {
                                    Exp _V4 = default_val(ts->_1);
                                    if (_V4) {
#line 887 "printing.pcc"
                                      
                                      if (comma)
                                        f << ", ";
                                      comma = true;
                                      f << _V4;
                                      
#line 892 "printing.pcc"
                                    } else {
#line 885 "printing.pcc"
                                     error ("%Lmissing label '%s' in expression: %s%e\n", i, ((Exp_CONSexp *)e)->_1->name, ((Exp_CONSexp *)e)->_3); 
#line 885 "printing.pcc"
                                    }
                                  }
#line 893 "printing.pcc"
#line 893 "printing.pcc"
                                  
                                  }
                                  }
                                  }
                                  f << ')';
                                  
#line 898 "printing.pcc"
                                  } break;
                                default: {
                                  L13:; 
#line 900 "printing.pcc"
                                  
                                  error("%Lconstructor '%s' doesn't take labeled arguments\n", ((Exp_CONSexp *)e)->_1->name);
                                  
#line 902 "printing.pcc"
                                  } break;
                              }
                            } else { goto L13; }
                            } break;
                          default: { goto L13; } break;
                        }
                      } else { goto L13; }
                      } break;
                    default: { goto L13; } break;
                  }
                } else { goto L13; }
                } break;
              default: {
                L14:; 
                if (((Exp_CONSexp *)e)->_1->ty) {
                  switch (((Exp_CONSexp *)e)->_1->ty->tag__) {
                    case a_Ty::tag_TYCONty: {
                      L15:; 
                      if (boxed(((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)) {
                        switch (((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1->tag__) {
                          case a_TyCon::tag_RECORDtycon: {
                            L16:; 
                            if (((Exp_CONSexp *)e)->_3) {
                              switch (((Exp_CONSexp *)e)->_3->tag__) {
                                case a_Exp::tag_RECORDexp: { goto L12; } break;
                                default: {
                                  L17:; 
#line 906 "printing.pcc"
                                  
                                  if (((Exp_CONSexp *)e)->_2)
                                  {
                                    f << "new (" << ((Exp_CONSexp *)e)->_2 << ") ";
                                    print_cons(f,((Exp_CONSexp *)e)->_1);
                                  }
                                  else
                                    f << mangle(((Exp_CONSexp *)e)->_1->name);
                                  f << '(' << ((Exp_CONSexp *)e)->_3 << ')';
                                  
#line 915 "printing.pcc"
                                  } break;
                              }
                            } else { goto L17; }
                            } break;
                          default: { goto L17; } break;
                        }
                      } else { goto L17; }
                      } break;
                    default: { goto L17; } break;
                  }
                } else {
                  L18:; 
                  if (((Exp_CONSexp *)e)->_3) { goto L17; } else {
                    L19:; 
                    if (((Exp_CONSexp *)e)->_2) { goto L17; } else {
                      L20:; 
#line 904 "printing.pcc"
                    f << mangle(((Exp_CONSexp *)e)->_1->name); 
#line 904 "printing.pcc"
                    }
                  }
                }
                } break;
            }
          } else { goto L14; }
        } else {
          L21:; 
#line 974 "printing.pcc"
         bug("operator << (std::ostream&, Exp);"); 
#line 974 "printing.pcc"
        }
        } break;
      case a_Exp::tag_CASTexp: {
#line 798 "printing.pcc"
        
        Bool save = pretty_print_ty;
        pretty_print_ty = false;
        f << "((" << ((Exp_CASTexp *)e)->_1 << ')' << ((Exp_CASTexp *)e)->_2 << ')';
        pretty_print_ty = save;
        
#line 803 "printing.pcc"
        } break;
      case a_Exp::tag_QUALexp: {
#line 804 "printing.pcc"
       f << ((Exp_QUALexp *)e)->_1 << "::" << ((Exp_QUALexp *)e)->_2; 
#line 804 "printing.pcc"
        } break;
      case a_Exp::tag_EQexp: {
#line 805 "printing.pcc"
       f << "equality_of(" << ((Exp_EQexp *)e)->_2 << ',' << ((Exp_EQexp *)e)->_3 << ')'; 
#line 805 "printing.pcc"
        } break;
      case a_Exp::tag_UNIFYexp: {
#line 806 "printing.pcc"
       f << "unify(" << ((Exp_UNIFYexp *)e)->_2 << ',' << ((Exp_UNIFYexp *)e)->_3 << ')'; 
#line 806 "printing.pcc"
        } break;
      case a_Exp::tag_LTexp: {
#line 807 "printing.pcc"
       f << '(' << ((Exp_LTexp *)e)->_2 << " < " << ((Exp_LTexp *)e)->_3 << ')'; 
#line 807 "printing.pcc"
        } break;
      case a_Exp::tag_HASHexp: {
#line 808 "printing.pcc"
       f << "hash(" << ((Exp_HASHexp *)e)->_2 << ')'; 
#line 808 "printing.pcc"
        } break;
      case a_Exp::tag_THISCOSTexp: {
#line 834 "printing.pcc"
       f << "t__->cost"; 
#line 834 "printing.pcc"
        } break;
      case a_Exp::tag_COSTexp: {
#line 833 "printing.pcc"
       f << "t__->kids[" << ((Exp_COSTexp *)e)->COSTexp << "]->cost"; 
#line 833 "printing.pcc"
        } break;
      case a_Exp::tag_THISSYNexp: {
#line 827 "printing.pcc"
        
        if (((Exp_THISSYNexp *)e)->_3)
          f << "__";
        else // in parser
          f << "t__->u._" << ((Exp_THISSYNexp *)e)->_1;
        
#line 832 "printing.pcc"
        } break;
      case a_Exp::tag_SYNexp: {
#line 813 "printing.pcc"
        
        if (((Exp_SYNexp *)e)->_4)
          f << '_' << ((Exp_SYNexp *)e)->_1 << "__";
        else if (((Exp_SYNexp *)e)->_2 < 0) // parser semantic action
        {
          if (((Exp_SYNexp *)e)->_1 == 0)
            f << "syn_" << "._" << -((Exp_SYNexp *)e)->_2;
          else
            f << "t__[" << ((Exp_SYNexp *)e)->_1 << "+to__]._" << -((Exp_SYNexp *)e)->_2;
        }
        else
          f << "t__->kids[" << ((Exp_SYNexp *)e)->_1 << "]->u._" << ((Exp_SYNexp *)e)->_2;
        
#line 825 "printing.pcc"
        } break;
      case a_Exp::tag_MARKEDexp: {
#line 770 "printing.pcc"
       f << ((Exp_MARKEDexp *)e)->_2; 
#line 770 "printing.pcc"
        } break;
      default: { goto L21; } break;
    }
  } else {
#line 766 "printing.pcc"
   
#line 766 "printing.pcc"
  }
}
#line 975 "printing.pcc"
#line 975 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an inheritance type.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Inherit i)
{
  if (i->qualifiers & QUALvirtual)
    f << "virtual ";
  return f << i->scope << ' ' << i->super_class;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a class inheritance list.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Inherits i)
{
  for ( ;i; i = i->_2)
  {
    f << i->_1;
    if (i->_2)
      f << ", ";
  }
  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a cost expression
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Cost c)
{
  
#line 1017 "printing.pcc"
#line 1021 "printing.pcc"
{
  if (c) {
    if (untagp(c)) {
      
#line 1021 "printing.pcc"
     f << " \\ " << ((Cost_INTcost *)derefp(c))->INTcost; 
#line 1021 "printing.pcc"
    } else {
      
#line 1020 "printing.pcc"
     f << " \\ " << ((Cost_EXPcost *)c)->_1; 
#line 1020 "printing.pcc"
    }
  } else {}
}
#line 1022 "printing.pcc"
#line 1022 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a qualified identifier.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, QualId id)
{
  
#line 1034 "printing.pcc"
#line 1038 "printing.pcc"
{
  if (untagp(id)) {
    
    if (
#line 1037 "printing.pcc"
    std::isalpha(((QualId_SIMPLEid *)derefp(id))->SIMPLEid[0])
#line 1037 "printing.pcc"
) {
      
#line 1037 "printing.pcc"
     f << ((QualId_SIMPLEid *)derefp(id))->SIMPLEid; 
#line 1037 "printing.pcc"
    } else {
      
#line 1038 "printing.pcc"
     f << "operator " << ((QualId_SIMPLEid *)derefp(id))->SIMPLEid; 
#line 1038 "printing.pcc"
    }
  } else {
    
#line 1036 "printing.pcc"
   f << ((QualId_NESTEDid *)id)->_1 << "::" << ((QualId_NESTEDid *)id)->_2; 
#line 1036 "printing.pcc"
  }
}
#line 1039 "printing.pcc"
#line 1039 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//  Method to print a pattern match rule.
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, MatchRule mr)
{
  
#line 1049 "printing.pcc"
#line 1061 "printing.pcc"
{
#line 1052 "printing.pcc"
  
  Bool save = pretty_print_exp;
  	  pretty_print_exp = true;
  	  if (mr->_1)
  	    f << mr->_1 << " -> ";
  f << mr->_2;
  if (mr->_3 != NOexp) f << " | " << mr->_3;
  f << mr->_4 << ": ...";
  	  pretty_print_exp = save;
  
#line 1061 "printing.pcc"
}
#line 1062 "printing.pcc"
#line 1062 "printing.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to pretty print a decision tree.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Match m)
{
  
#line 1074 "printing.pcc"
#line 1142 "printing.pcc"
{
  if (boxed(m)) {
    switch (m->tag__) {
      case a_Match::tag_SUCCESSmatch: {
#line 1079 "printing.pcc"
       f << ((Match_SUCCESSmatch *)m)->_1; 
#line 1079 "printing.pcc"
        } break;
      case a_Match::tag_SUCCESSESmatch: {
#line 1082 "printing.pcc"
        
        f << '{';
        Bool comma = false;
        for (int i = 0; i < ((Match_SUCCESSESmatch *)m)->_1; i++)
          if ((*((Match_SUCCESSESmatch *)m)->_2)[i])
          {
            if (comma)
              f << ", ";
            f << i;
            comma = true;
          }
        f << '}';
        
#line 1094 "printing.pcc"
        } break;
      case a_Match::tag_COSTmatch: {
#line 1096 "printing.pcc"
        
        f << '{';
        Bool comma = false;
        for (int i = 0; i < ((Match_COSTmatch *)m)->_1; i++)
          if ((*((Match_COSTmatch *)m)->_3)[i])
          {
             if (comma)
               f << ", ";
             f << ((Match_COSTmatch *)m)->_2[i] << " = " << i;
             comma = true;
          }
        f << '}';
        
#line 1108 "printing.pcc"
        } break;
      case a_Match::tag_GUARDmatch: {
#line 1080 "printing.pcc"
       f << ((Match_GUARDmatch *)m)->_1 << '(' << ((Match_GUARDmatch *)m)->_2 << ',' << ((Match_GUARDmatch *)m)->_3 << ')'; 
#line 1080 "printing.pcc"
        } break;
      case a_Match::tag_LITERALmatch: {
        switch (((Match_LITERALmatch *)m)->_3[0]->tag__) {
          case a_Literal::tag_REGEXPlit: {
#line 1114 "printing.pcc"
            
            f << "[\n";
            for (int i = 0; i < ((Match_LITERALmatch *)m)->_4; i++)
              f << "  {" << i << "}" << ((Match_LITERALmatch *)m)->_3[i] << " => " << ((Match_LITERALmatch *)m)->_5[i] << ",\n";
            f << ((Match_LITERALmatch *)m)->_6 << ']';
            
#line 1119 "printing.pcc"
            } break;
          default: {
#line 1121 "printing.pcc"
            
            f << '[';
            for (int i = 0; i < ((Match_LITERALmatch *)m)->_4; i++)
              f << ((Match_LITERALmatch *)m)->_3[i] << ':' << ((Match_LITERALmatch *)m)->_5[i] << ", ";
            f << ((Match_LITERALmatch *)m)->_6 << ']';
            
#line 1126 "printing.pcc"
            } break;
        }
        } break;
      case a_Match::tag_RANGEmatch: {
#line 1140 "printing.pcc"
       f << '[' << ((Match_RANGEmatch *)m)->_3 << ".." << ((Match_RANGEmatch *)m)->_4 << ": " << ((Match_RANGEmatch *)m)->_5 << ", " << ((Match_RANGEmatch *)m)->_6 << ']'; 
#line 1140 "printing.pcc"
        } break;
      case a_Match::tag_CONSmatch: {
        if (((Match_CONSmatch *)m)->_4) {
          switch (((Match_CONSmatch *)m)->_4->tag__) {
            case a_Ty::tag_TYCONty: {
              if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 1128 "printing.pcc"
                    
                    f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->id << '[';
                    for (int i = 0; i < ((Match_CONSmatch *)m)->_5; i++)
                    {
                      f << ((Match_CONSmatch *)m)->_6[i];
                      if (i < ((Match_CONSmatch *)m)->_5 - 1) f << ", ";
                    }
                    if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible)
                      f << ", " << ((Match_CONSmatch *)m)->_7;
                    f << ']';
                    
#line 1138 "printing.pcc"
                    } break;
                  default: {
                    L22:; 
#line 1142 "printing.pcc"
                   bug("operator << (std::ostream&, Match);"); 
#line 1142 "printing.pcc"
                    } break;
                }
              } else { goto L22; }
              } break;
            default: { goto L22; } break;
          }
        } else { goto L22; }
        } break;
      case a_Match::tag_TREECOSTmatch: {
#line 1110 "printing.pcc"
       f << "TREE{" << *((Match_TREECOSTmatch *)m)->_2 << "} => " << ((Match_TREECOSTmatch *)m)->_1; 
#line 1110 "printing.pcc"
        } break;
      case a_Match::tag_TREELABELmatch: {
#line 1112 "printing.pcc"
       f << "LABEL{" << ((Match_TREELABELmatch *)m)->_2 << "(" << ((Match_TREELABELmatch *)m)->_4 << ")} => " << ((Match_TREELABELmatch *)m)->_1; 
#line 1112 "printing.pcc"
        } break;
      default: {
#line 1078 "printing.pcc"
       f << '<' << ((Match_BACKEDGEmatch *)m)->_2 << '>'; 
#line 1078 "printing.pcc"
        } break;
    }
  } else {
    if (m) {
      
#line 1077 "printing.pcc"
     f << '-'; 
#line 1077 "printing.pcc"
    } else {
      
#line 1076 "printing.pcc"
     f << '_'; 
#line 1076 "printing.pcc"
    }
  }
}
#line 1143 "printing.pcc"
#line 1143 "printing.pcc"

  return f;
}
#line 1146 "printing.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 4392
Number of ifs generated      = 77
Number of switches generated = 31
Number of labels             = 22
Number of gotos              = 47
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
