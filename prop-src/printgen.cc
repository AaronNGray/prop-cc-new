///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "printgen.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _p_r_i_n_t_g_e_nco_c_c_Q1("obj__");
#line 1 "printgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the pretty printer generator.
//
///////////////////////////////////////////////////////////////////////////////

#include <cctype>
#include <cstring>
#include <AD/strings/quark.h>
#include <AD/strings/charesc.h>
#include "ir.h"
#include "ast.h"
#include "datatype.h"
#include "type.h"
#include "matchcom.h"
#include "list.h"
#include "codegen.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the interface definition for the pretty printers
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeClass::generate_print_interface( CodeGen& C)
{
}

void DatatypeHierarchy::generate_print_interface( CodeGen& C)
{
  C.pr(
        "%^%/"
        "%^//"
        "%^//  Pretty printing methods for %s%V"
        "%^//"
        "%^%/"
        "%^class PrettyOStream;"
          "%^%Hextern std::ostream& operator<<(std::ostream&, %s%v);"
          "%^%Hextern PrettyOStream& operator<<(PrettyOStream&, %s%v);",
        datatype_name, parameters,
        parameters, datatype_name, parameters,
        parameters, datatype_name, parameters
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the pretty printer implementation.
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeClass::generate_print_implementation( CodeGen&, Tys, DefKind)
{
}

void DatatypeHierarchy::generate_print_implementation
   ( CodeGen& C, Tys tys, DefKind k)
{
  Ty ty = NOty;
  
#line 60 "printgen.pcc"
#line 65 "printgen.pcc"
{
  if (datatype_ty) {
    switch (datatype_ty->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)datatype_ty)->_1)) {
          switch (((Ty_TYCONty *)datatype_ty)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 63 "printgen.pcc"
             ty =  apply_ty(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)datatype_ty)->_1)->polyty,tys); 
#line 63 "printgen.pcc"
              } break;
            default: {
              L1:; } break;
          }
        } else { goto L1; }
        } break;
      default: { goto L1; } break;
    }
  } else { goto L1; }
}
#line 65 "printgen.pcc"
#line 65 "printgen.pcc"


  C.pr(
        "%^%/"
        "%^//"
        "%^// Pretty printing methods for %s%P"
        "%^//"
        "%^%/",
        datatype_name, tys
      );

  //
  // Generate the std::ostream based method
  //

  C.pr( "%^std::ostream& operator << (std::ostream& strm__, %t obj__)", ty, "");

  if (k == EXTERNAL_INSTANTIATION)
     C.pr( "%^{  PrettyOStream S(strm__); S << obj__; return strm__; }\n\n");
  else
     C.pr( ";");

  //
  // Generate the PrettyOStream based method
  //

  C.pr(
        "%^PrettyOStream& operator << (PrettyOStream& strm__, %t obj__)",
        ty,""
      );

  if (k == EXTERNAL_INSTANTIATION)
     C.pr( "%^{%+");
  else
     C.pr( ";");

  if (k != EXTERNAL_INSTANTIATION) return;

  if (arity > 1)
    C.pr( "%^switch (%U)%^{%+", IDexp(
#line 104 "printgen.pcc"
#line 104 "printgen.pcc"
_p_r_i_n_t_g_e_nco_c_c_Q1
#line 104 "printgen.pcc"
#line 104 "printgen.pcc"
), ty);

  for (int i = 0; i < arity; i++)
  {
    Cons term = constructor_terms[i];
    if (arity > 1)
      C.pr( "%^case %*: %+", term, true);
    generate_printer( C, tys, k, ty, term);
    if (arity > 1)
      C.pr( "%^break;%-");
  }

  if (arity > 1)
    C.pr( "%-%^}");
  C.pr(
        "%^return strm__;"
        "%-%^}"
      );

  C.pr( "\n\n");
}


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printer for one single variant
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeHierarchy::generate_printer
   (CodeGen& C, Tys tys, DefKind k, Ty mono_ty, Cons cons)
{
  
#line 136 "printgen.pcc"
#line 149 "printgen.pcc"
{
  if (cons) {
#line 139 "printgen.pcc"
    
    cons_arg_ty = cons->ty == NOty ? NOty : apply_ty(cons->cons_ty,tys);
    
    if (cons->print_formats == 
#line 142 "printgen.pcc"
#line 142 "printgen.pcc"
    nil_1_
#line 142 "printgen.pcc"
#line 142 "printgen.pcc"
    )
    generate_default_printer( C, tys, k, mono_ty, cons, cons_arg_ty);
    else
    generate_formatted_printer( C, tys, k, mono_ty,
        cons, cons_arg_ty, cons->print_formats);
    
#line 147 "printgen.pcc"
  } else {}
}
#line 149 "printgen.pcc"
#line 149 "printgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a default pretty printer
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeHierarchy::generate_default_printer
   (CodeGen& C, Tys tys, DefKind k, Ty mono_ty, Cons cons, Ty ty)
{
  PrintFormats fmt = 
#line 161 "printgen.pcc"
#line 161 "printgen.pcc"
nil_1_
#line 161 "printgen.pcc"
#line 161 "printgen.pcc"
;
  
#line 162 "printgen.pcc"
#line 218 "printgen.pcc"
{
  Ty _V1 = deref_all(ty);
  if (cons) {
    if (_V1) {
      switch (_V1->tag__) {
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)_V1)->_1)) {
            switch (((Ty_TYCONty *)_V1)->_1->tag__) {
              case a_TyCon::tag_RECORDtycon: {
#line 199 "printgen.pcc"
                
                Ids ls; Tys ts;
                fmt = 
#line 201 "printgen.pcc"
#line 201 "printgen.pcc"
                list_1_(TERMsym('{'),list_1_(TERMSTRINGsym(cons->name)))
#line 201 "printgen.pcc"
#line 201 "printgen.pcc"
                ;
                Bool comma = false;
                for( ls = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V1)->_1)->_1, ts = ((Ty_TYCONty *)_V1)->_2; ls && ts; ls = ls->_2, ts = ts->_2)
                {
                  if (comma)
                    fmt = 
#line 206 "printgen.pcc"
#line 206 "printgen.pcc"
                list_1_(TERMsym(','),fmt)
#line 206 "printgen.pcc"
#line 206 "printgen.pcc"
                ;
                fmt = 
#line 207 "printgen.pcc"
#line 207 "printgen.pcc"
                list_1_(SPECIALsym('_'),list_1_(TERMsym('='),list_1_(TERMSTRINGsym(ls->_1),fmt)))
#line 207 "printgen.pcc"
#line 207 "printgen.pcc"
                ;
                comma = true;
                }
                fmt = 
#line 210 "printgen.pcc"
#line 210 "printgen.pcc"
                list_1_(TERMsym('}'),fmt)
#line 210 "printgen.pcc"
#line 210 "printgen.pcc"
                ;
                fmt = rev(fmt);
                
#line 212 "printgen.pcc"
                } break;
              default: {
                L2:; 
#line 214 "printgen.pcc"
                
                fmt = 
#line 215 "printgen.pcc"
#line 215 "printgen.pcc"
                list_1_(TERMSTRINGsym(cons->name),list_1_(TERMsym('('),list_1_(SPECIALsym('_'),list_1_(TERMsym(')')))))
#line 215 "printgen.pcc"
#line 215 "printgen.pcc"
                ;
                
#line 216 "printgen.pcc"
                } break;
            }
          } else {
            switch ((int)((Ty_TYCONty *)_V1)->_1) {
              case ((int)TUPLEtycon): {
                if (((Ty_TYCONty *)_V1)->_2) {
                  if (((Ty_TYCONty *)_V1)->_2->_2) {
                    if (((Ty_TYCONty *)_V1)->_2->_2->_2) {
                      L3:; 
#line 171 "printgen.pcc"
                      
                      Tys ts;
                      fmt = 
#line 173 "printgen.pcc"
#line 173 "printgen.pcc"
                      list_1_(TERMsym(')'))
#line 173 "printgen.pcc"
#line 173 "printgen.pcc"
                      ;
                      Bool comma = false;
                      for( ts = ((Ty_TYCONty *)_V1)->_2; ts; ts = ts->_2)
                      {
                        if (comma)
                          fmt = 
#line 178 "printgen.pcc"
#line 178 "printgen.pcc"
                      list_1_(TERMsym(','),fmt)
#line 178 "printgen.pcc"
#line 178 "printgen.pcc"
                      ;
                      fmt = 
#line 179 "printgen.pcc"
#line 179 "printgen.pcc"
                      list_1_(SPECIALsym('_'),fmt)
#line 179 "printgen.pcc"
#line 179 "printgen.pcc"
                      ;
                      comma = true;
                      }
                      fmt = 
#line 182 "printgen.pcc"
#line 182 "printgen.pcc"
                      list_1_(TERMSTRINGsym(cons->name),list_1_(TERMsym('('),fmt))
#line 182 "printgen.pcc"
#line 182 "printgen.pcc"
                      ;
                      
#line 183 "printgen.pcc"
                    } else {
                      if (
#line 168 "printgen.pcc"
                      is_list_constructor(cons->name)
#line 168 "printgen.pcc"
) {
                        
#line 169 "printgen.pcc"
                       fmt = 
#line 169 "printgen.pcc"
#line 169 "printgen.pcc"
                        list_1_(SPECIALsym('['),list_1_(SPECIALsym('L'),list_1_(SPECIALsym(']'))))
#line 169 "printgen.pcc"
#line 169 "printgen.pcc"
                        ; 
#line 169 "printgen.pcc"
                      } else {
                         goto L3; }
                    }
                  } else { goto L3; }
                } else { goto L3; }
                } break;
              case ((int)EXTUPLEtycon): {
#line 185 "printgen.pcc"
                
                Tys ts;
                fmt = 
#line 187 "printgen.pcc"
#line 187 "printgen.pcc"
                list_1_(TERMsym(')'))
#line 187 "printgen.pcc"
#line 187 "printgen.pcc"
                ;
                Bool comma = false;
                for( ts = ((Ty_TYCONty *)_V1)->_2; ts; ts = ts->_2)
                {
                  if (comma)
                    fmt = 
#line 192 "printgen.pcc"
#line 192 "printgen.pcc"
                list_1_(TERMsym(','),fmt)
#line 192 "printgen.pcc"
#line 192 "printgen.pcc"
                ;
                fmt = 
#line 193 "printgen.pcc"
#line 193 "printgen.pcc"
                list_1_(SPECIALsym('_'),fmt)
#line 193 "printgen.pcc"
#line 193 "printgen.pcc"
                ;
                comma = true;
                }
                fmt = 
#line 196 "printgen.pcc"
#line 196 "printgen.pcc"
                list_1_(TERMSTRINGsym(cons->name),list_1_(TERMsym('('),fmt))
#line 196 "printgen.pcc"
#line 196 "printgen.pcc"
                ;
                
#line 197 "printgen.pcc"
                } break;
              default: { goto L2; } break;
            }
          }
          } break;
        default: { goto L2; } break;
      }
    } else {
      if (
#line 164 "printgen.pcc"
      is_list_constructor(cons->name)
#line 164 "printgen.pcc"
) {
        
#line 165 "printgen.pcc"
       fmt = 
#line 165 "printgen.pcc"
#line 165 "printgen.pcc"
        list_1_(SPECIALsym('['),list_1_(SPECIALsym(']')))
#line 165 "printgen.pcc"
#line 165 "printgen.pcc"
        ; 
#line 165 "printgen.pcc"
      } else {
        
#line 167 "printgen.pcc"
       fmt = 
#line 167 "printgen.pcc"
#line 167 "printgen.pcc"
        list_1_(TERMSTRINGsym(cons->name))
#line 167 "printgen.pcc"
#line 167 "printgen.pcc"
        ; 
#line 167 "printgen.pcc"
      }
    }
  } else {}
}
#line 218 "printgen.pcc"
#line 218 "printgen.pcc"

  generate_formatted_printer( C, tys, k, mono_ty, cons, ty, fmt);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a formatted pretty printer
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeHierarchy::generate_formatted_printer
   (CodeGen& C, Tys tys, DefKind k, Ty mono_ty,
    Cons cons, Ty ty, PrintFormats fmt)
{
  Tys tyl  = 
#line 232 "printgen.pcc"
#line 232 "printgen.pcc"
nil_1_
#line 232 "printgen.pcc"
#line 232 "printgen.pcc"
;
  Ids label_list = 
#line 233 "printgen.pcc"
#line 233 "printgen.pcc"
nil_1_
#line 233 "printgen.pcc"
#line 233 "printgen.pcc"
;

  
#line 235 "printgen.pcc"
#line 240 "printgen.pcc"
{
  Ty _V2 = deref_all(ty);
  if (_V2) {
    switch (_V2->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V2)->_1)) {
          switch (((Ty_TYCONty *)_V2)->_1->tag__) {
            case a_TyCon::tag_RECORDtycon: {
#line 239 "printgen.pcc"
             tyl = ((Ty_TYCONty *)_V2)->_2; label_list = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V2)->_1)->_1; 
#line 239 "printgen.pcc"
              } break;
            default: {
              L4:; 
#line 240 "printgen.pcc"
             tyl = 
#line 240 "printgen.pcc"
#line 240 "printgen.pcc"
              list_1_(_V2)
#line 240 "printgen.pcc"
#line 240 "printgen.pcc"
              ; 
#line 240 "printgen.pcc"
              } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)_V2)->_1) {
            case ((int)TUPLEtycon): {
#line 238 "printgen.pcc"
             tyl = ((Ty_TYCONty *)_V2)->_2; 
#line 238 "printgen.pcc"
              } break;
            default: { goto L4; } break;
          }
        }
        } break;
      default: { goto L4; } break;
    }
  } else {
#line 237 "printgen.pcc"
   tyl = 
#line 237 "printgen.pcc"
#line 237 "printgen.pcc"
    nil_1_
#line 237 "printgen.pcc"
#line 237 "printgen.pcc"
    ; 
#line 237 "printgen.pcc"
  }
}
#line 241 "printgen.pcc"
#line 241 "printgen.pcc"


  int N = length(tyl);
  int index = 1;

  Exp exp = select(IDexp("obj__"),cons,mono_ty);

  for_each (ProductionSymbol, f, fmt)
  {
    
#line 250 "printgen.pcc"
#line 330 "printgen.pcc"
{
  switch (f->tag__) {
    case a_ProductionSymbol::tag_TERMsym: {
#line 256 "printgen.pcc"
     C.pr( "%^strm__ << '%s';", print_char(((ProductionSymbol_TERMsym *)f)->TERMsym)); 
#line 256 "printgen.pcc"
      } break;
    case a_ProductionSymbol::tag_TERMSTRINGsym: {
#line 258 "printgen.pcc"
      
      int len = std::strlen(((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym);
      if (len == 1)
      {
        C.pr( "%^strm__ << '%s';",((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym);
      }
      else if (len == 3 && ((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym[0] == '"' && ((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym[2] == '"' && !std::isalnum(((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym[1]))
      {
        C.pr( "%^strm__ << '%s';",print_char(((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym[1]));
      }
      else
      {
        Id quote = ((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym[0] == '"' ? "" : "\"";
        C.pr( "%^strm__ << %s%s%s;",quote,((ProductionSymbol_TERMSTRINGsym *)f)->TERMSTRINGsym,quote);
      }
      
#line 273 "printgen.pcc"
      } break;
    case a_ProductionSymbol::tag_NONTERMsym: {
#line 252 "printgen.pcc"
     gen_print_field(C,DOTexp(exp,((ProductionSymbol_NONTERMsym *)f)->NONTERMsym),component_ty(ty,((ProductionSymbol_NONTERMsym *)f)->NONTERMsym)); 
#line 252 "printgen.pcc"
      } break;
    case a_ProductionSymbol::tag_POSNONTERMsym: {
#line 254 "printgen.pcc"
     gen_print_field(C,DOTexp(exp,index_of(((ProductionSymbol_POSNONTERMsym *)f)->POSNONTERMsym)),component_ty(ty,((ProductionSymbol_POSNONTERMsym *)f)->POSNONTERMsym)); 
#line 254 "printgen.pcc"
      } break;
    case a_ProductionSymbol::tag_SPECIALsym: {
      switch (((ProductionSymbol_SPECIALsym *)f)->SPECIALsym) {
        case '/': {
#line 304 "printgen.pcc"
         C.pr("%^strm__.newline().tab();"); 
#line 304 "printgen.pcc"
        } break;
        case 'L': {
#line 282 "printgen.pcc"
          
          char nil_name[4];
          nil_name[0] = '#'; nil_name[1] = cons->name[1];
          nil_name[2] = cons->name[5]; nil_name[3] = '\0';
          Cons nil = lookup_cons(nil_name);
          C.pr(
                "%^{%+"
                "%^int comma__ = 0;"
                "%^for (%S%P * l__ = obj__; l__ != %S; l__ = %e)"
                "%^{%+"
                "%^if (comma__) strm__ << ',';"
                       "%^strm__ << %e;"
                "%^comma__ = 1;"
                "%-%^}"
                "%-%^}",
                class_name, tys, nil->name,
                DOTexp(select(IDexp("l__"),cons,mono_ty),"_2"),
                DOTexp(select(IDexp("l__"),cons,mono_ty),"_1")
              );
          
#line 301 "printgen.pcc"
        } break;
        case '[': {
#line 275 "printgen.pcc"
         C.pr("%^strm__ << '%c';", (int)cons->name[1]); 
#line 275 "printgen.pcc"
        } break;
        case ']': {
#line 277 "printgen.pcc"
          
          char c = cons->name[std::strlen(cons->name)-1];
          C.pr("%^strm__ << '%c';", (int)c);
          
#line 280 "printgen.pcc"
        } break;
        case '_': {
          if (
#line 305 "printgen.pcc"
          (tyl != nil_1_)
#line 305 "printgen.pcc"
) {
            
#line 306 "printgen.pcc"
            
            if (N == 1)
              gen_print_field(C, exp, ty);
            else if (label_list == 
#line 309 "printgen.pcc"
#line 309 "printgen.pcc"
            nil_1_
#line 309 "printgen.pcc"
#line 309 "printgen.pcc"
            )
            gen_print_field( C, DOTexp( exp, index_of( index)),tyl->_1);
            else
            gen_print_field( C, DOTexp( exp, label_list->_1),tyl->_1);
            
            C.pr(" // %T", tyl->_1);
            if (tyl != 
#line 315 "printgen.pcc"
#line 315 "printgen.pcc"
            nil_1_
#line 315 "printgen.pcc"
#line 315 "printgen.pcc"
            )
            tyl = tyl->_2;
            if (label_list != 
#line 317 "printgen.pcc"
#line 317 "printgen.pcc"
            nil_1_
#line 317 "printgen.pcc"
#line 317 "printgen.pcc"
            )
            label_list = label_list->_2;
            index++;
            
#line 320 "printgen.pcc"
          } else {
            
            L5:; 
#line 322 "printgen.pcc"
            
            error( "%!illegal print format '%c' in constructor %s %T\n",
            cons->location, (int)((ProductionSymbol_SPECIALsym *)f)->SPECIALsym, cons->name, ty);
            
#line 325 "printgen.pcc"
          }
        } break;
        case '{': {
#line 302 "printgen.pcc"
         C.pr("%^strm__.indent().newline().tab();"); 
#line 302 "printgen.pcc"
        } break;
        case '}': {
#line 303 "printgen.pcc"
         C.pr("%^strm__.unindent().newline().tab();"); 
#line 303 "printgen.pcc"
        } break;
        default: { goto L5; }
      }
      } break;
    default: {
#line 327 "printgen.pcc"
      
      bug( "%!illegal print format in constructor %s %T\n",
           cons->location, cons->name, ty);
      
#line 330 "printgen.pcc"
      } break;
  }
}
#line 331 "printgen.pcc"
#line 331 "printgen.pcc"

  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a formatted pretty printer for a field
//
///////////////////////////////////////////////////////////////////////////////

void DatatypeHierarchy::gen_print_field( CodeGen& C, Exp exp, Ty ty)
{
  Id stream =
      (
        ty_equal(ty,integer_ty) ||
        ty_equal(ty,character_ty) ||
        ty_equal(ty,string_ty) ||
        ty_equal(ty,bool_ty) ||
        ty_equal(ty,real_ty) ||
        ty_equal(ty,quark_ty) ||
        has_qual(QUALprintable,ty) ||
        has_qual(QUALprintable,deref_all(ty))
      ) ? "" : ".stream()";
  C.pr( "%^strm__%s << %e;", stream, exp);
}
#line 356 "printgen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 77
Number of ifs generated      = 14
Number of switches generated = 10
Number of labels             = 5
Number of gotos              = 11
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
