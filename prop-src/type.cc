///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "type.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _t_y_p_eco_c_c_Q5("void");
static const Quark _t_y_p_eco_c_c_Q2("int");
static const Quark _t_y_p_eco_c_c_Q4("bool");
static const Quark _t_y_p_eco_c_c_Q6("Quark");
static const Quark _t_y_p_eco_c_c_Q1("char");
static const Quark _t_y_p_eco_c_c_Q7("BigInt");
static const Quark _t_y_p_eco_c_c_Q3("double");
#line 1 "type.pcc"
/////////////////////////////////////////////////////////////////////////////
//
//  This file implements the type analysis and type inference module
//  in the Prop -> C++ translator.
//
/////////////////////////////////////////////////////////////////////////////

#include <AD/strings/quark.h>
#include "hashtab.h"
#include "ir.h"
#include "ast.h"
#include "collection.h"
#include "type.h"
#include "datatype.h"
#include "list.h"
#include "options.h"

/////////////////////////////////////////////////////////////////////////////
//
//  Types for literals
//
/////////////////////////////////////////////////////////////////////////////

Ty  string_ty    = NOty,
    character_ty = NOty,
    integer_ty   = NOty,
    real_ty      = NOty,
    bool_ty      = NOty,
    void_ty      = NOty,
    quark_ty     = NOty,
    bigint_ty    = NOty;

/////////////////////////////////////////////////////////////////////////////
//
// Initialize the types
//
/////////////////////////////////////////////////////////////////////////////

void initialize_types()
{
  character_ty = mkidty( 
#line 41 "type.pcc"
#line 41 "type.pcc"
_t_y_p_eco_c_c_Q1
#line 41 "type.pcc"
#line 41 "type.pcc"
, 
#line 41 "type.pcc"
#line 41 "type.pcc"
nil_1_
#line 41 "type.pcc"
#line 41 "type.pcc"
);
  string_ty    = mkptrty( QUALty( QUALconst, character_ty));
  integer_ty   = mkidty( 
#line 43 "type.pcc"
#line 43 "type.pcc"
_t_y_p_eco_c_c_Q2
#line 43 "type.pcc"
#line 43 "type.pcc"
, 
#line 43 "type.pcc"
#line 43 "type.pcc"
nil_1_
#line 43 "type.pcc"
#line 43 "type.pcc"
);
  real_ty      = mkidty( 
#line 44 "type.pcc"
#line 44 "type.pcc"
_t_y_p_eco_c_c_Q3
#line 44 "type.pcc"
#line 44 "type.pcc"
, 
#line 44 "type.pcc"
#line 44 "type.pcc"
nil_1_
#line 44 "type.pcc"
#line 44 "type.pcc"
);
  bool_ty      = mkidty( 
#line 45 "type.pcc"
#line 45 "type.pcc"
_t_y_p_eco_c_c_Q4
#line 45 "type.pcc"
#line 45 "type.pcc"
, 
#line 45 "type.pcc"
#line 45 "type.pcc"
nil_1_
#line 45 "type.pcc"
#line 45 "type.pcc"
);
  void_ty      = mkidty( 
#line 46 "type.pcc"
#line 46 "type.pcc"
_t_y_p_eco_c_c_Q5
#line 46 "type.pcc"
#line 46 "type.pcc"
, 
#line 46 "type.pcc"
#line 46 "type.pcc"
nil_1_
#line 46 "type.pcc"
#line 46 "type.pcc"
);
  quark_ty     = mkidty( 
#line 47 "type.pcc"
#line 47 "type.pcc"
_t_y_p_eco_c_c_Q6
#line 47 "type.pcc"
#line 47 "type.pcc"
, 
#line 47 "type.pcc"
#line 47 "type.pcc"
nil_1_
#line 47 "type.pcc"
#line 47 "type.pcc"
);
  bigint_ty    = mkidty( 
#line 48 "type.pcc"
#line 48 "type.pcc"
_t_y_p_eco_c_c_Q7
#line 48 "type.pcc"
#line 48 "type.pcc"
, 
#line 48 "type.pcc"
#line 48 "type.pcc"
nil_1_
#line 48 "type.pcc"
#line 48 "type.pcc"
);
}

/////////////////////////////////////////////////////////////////////////////
//
//  Make a type variable
//
/////////////////////////////////////////////////////////////////////////////

Ty mkvar() { return VARty(NOty); }

/////////////////////////////////////////////////////////////////////////////
//
//  Constructors for some common types
//
/////////////////////////////////////////////////////////////////////////////

Ty mkptrty( Ty ty)                   { return TYCONty( POINTERtycon, 
#line 65 "type.pcc"
#line 65 "type.pcc"
list_1_(ty)
#line 65 "type.pcc"
#line 65 "type.pcc"
); }
Ty mkrefty( Ty ty)                   { return TYCONty( REFtycon, 
#line 66 "type.pcc"
#line 66 "type.pcc"
list_1_(ty)
#line 66 "type.pcc"
#line 66 "type.pcc"
); }
Ty mkfunty( Ty a, Ty b)              { return TYCONty( FUNtycon, 
#line 67 "type.pcc"
#line 67 "type.pcc"
list_1_(a,list_1_(b))
#line 67 "type.pcc"
#line 67 "type.pcc"
); }
Ty mkarrayty( Ty a, Exp e)           { return TYCONty( ARRAYtycon(e), 
#line 68 "type.pcc"
#line 68 "type.pcc"
list_1_(a)
#line 68 "type.pcc"
#line 68 "type.pcc"
); }
Ty mkidty( Id id, Tys args)          { return TYCONty( IDtycon(id), args); }
Ty mkidvarty( Id id, TyVars args)    { return TYCONty( IDtycon(id), tyvars_to_tys(args)); }
Ty mktuplety( Tys tys)               { return TYCONty( TUPLEtycon, tys); }
Ty mkrecordty( Ids l, Tys t, Bool f) { return TYCONty( RECORDtycon(l,f), t); }
Ty mktypety()                        { return TYCONty( TYPEtycon,
#line 73 "type.pcc"
#line 73 "type.pcc"
nil_1_
#line 73 "type.pcc"
#line 73 "type.pcc"
); }
Tys tyvars_to_tys ( TyVars a)
{
  
#line 76 "type.pcc"
#line 81 "type.pcc"
{
  if (a) {
#line 81 "type.pcc"
   return 
#line 81 "type.pcc"
#line 81 "type.pcc"
    list_1_(mkidty(a->_1,nil_1_),tyvars_to_tys(a->_2))
#line 81 "type.pcc"
#line 81 "type.pcc"
    ; 
#line 81 "type.pcc"
  } else {
#line 79 "type.pcc"
   return 
#line 79 "type.pcc"
#line 79 "type.pcc"
    nil_1_
#line 79 "type.pcc"
#line 79 "type.pcc"
    ; 
#line 79 "type.pcc"
  }
}
#line 82 "type.pcc"
#line 82 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
// Return the representation tag of a constructor
//
/////////////////////////////////////////////////////////////////////////////

int tag_of( Cons cons)
{
  
#line 93 "type.pcc"
#line 97 "type.pcc"
{
  if (cons) {
    if (cons->alg_ty) {
      switch (cons->alg_ty->tag__) {
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
            switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
#line 95 "type.pcc"
              return cons->tag + ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->qualifiers & QUALlexeme) ? 256 : 0); 
#line 95 "type.pcc"
                } break;
              default: {
                L1:; 
#line 97 "type.pcc"
               return 0; 
#line 97 "type.pcc"
                } break;
            }
          } else { goto L1; }
          } break;
        default: { goto L1; } break;
      }
    } else { goto L1; }
  } else { goto L1; }
}
#line 98 "type.pcc"
#line 98 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//  Convert type variables to a type list
/////////////////////////////////////////////////////////////////////////////

Tys tyvars_to_type_list(int i, TyVars tyvars)
{
  
#line 107 "type.pcc"
#line 112 "type.pcc"
{
  if (tyvars) {
#line 112 "type.pcc"
   return 
#line 112 "type.pcc"
#line 112 "type.pcc"
    list_1_(INDty(tyvars->_1,i),tyvars_to_type_list((i + 1),tyvars->_2))
#line 112 "type.pcc"
#line 112 "type.pcc"
    ; 
#line 112 "type.pcc"
  } else {
#line 110 "type.pcc"
   return 
#line 110 "type.pcc"
#line 110 "type.pcc"
    nil_1_
#line 110 "type.pcc"
#line 110 "type.pcc"
    ; 
#line 110 "type.pcc"
  }
}
#line 113 "type.pcc"
#line 113 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Make a universally quantified type
//
/////////////////////////////////////////////////////////////////////////////

Ty mkpolyty( Ty ty, TyVars tyvars)
{
  int arity = length(tyvars);
  if (arity == 0) return ty;
  Id * bound_vars = (Id *)mem_pool[arity * sizeof(Id)];
  int i = 0;
  for_each ( TyVar, tv, tyvars)
     bound_vars[i++] = tv;
  return POLYty( deref(ty), arity, bound_vars);
/*
  match (deref(ty))
  {
  TYCONty(tycon,_):
    {
      return POLYty
        (TYCONty( tycon, tyvars_to_type_list( 0, tyvars)), arity, bound_vars);
    }
  |  _:
    { bug("mkpolyty()"); }
  }
*/
}

/////////////////////////////////////////////////////////////////////////////
//
//  Dereference a type expression
//
/////////////////////////////////////////////////////////////////////////////

Ty deref_all( Ty ty)
{
  
#line 153 "type.pcc"
#line 171 "type.pcc"
{
  for (;;) {
    if (ty) {
      switch (ty->tag__) {
        case a_Ty::tag_VARty: {
          if (((Ty_VARty *)ty)->VARty) {
#line 155 "type.pcc"
           ty = ((Ty_VARty *)ty)->VARty; 
#line 155 "type.pcc"
          } else {
            L3:; 
#line 171 "type.pcc"
           return ty; 
#line 171 "type.pcc"
          }
          } break;
        case a_Ty::tag_QUALty: {
#line 156 "type.pcc"
         ty = ((Ty_QUALty *)ty)->_2; 
#line 156 "type.pcc"
          } break;
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)ty)->_1)) {
            switch (((Ty_TYCONty *)ty)->_1->tag__) {
              case a_TyCon::tag_IDtycon: {
                if (((Ty_TYCONty *)ty)->_2) {
#line 161 "type.pcc"
                  
                  
#line 162 "type.pcc"
#line 167 "type.pcc"
                  {
                    Ty _V1 = lookup_ty(((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon);
                    if (_V1) {
                      switch (_V1->tag__) {
                        case a_Ty::tag_TYCONty: {
#line 165 "type.pcc"
                         return TYCONty(((Ty_TYCONty *)_V1)->_1,((Ty_TYCONty *)ty)->_2); 
#line 165 "type.pcc"
                          } break;
                        default: {
                          L4:; 
#line 167 "type.pcc"
                         return ty; 
#line 167 "type.pcc"
                          } break;
                      }
                    } else { goto L4; }
                  }
#line 168 "type.pcc"
#line 168 "type.pcc"
                  
                  
#line 169 "type.pcc"
                } else {
#line 159 "type.pcc"
                Ty t = lookup_ty(((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon); if (t != NOty) ty = t; else return ty; 
#line 159 "type.pcc"
                }
                } break;
              default: { goto L3; } break;
            }
          } else { goto L3; }
          } break;
        case a_Ty::tag_DEFVALty: {
#line 157 "type.pcc"
         ty = ((Ty_DEFVALty *)ty)->_1; 
#line 157 "type.pcc"
          } break;
        default: { goto L3; } break;
      }
    } else { goto L3; }
  }
}
#line 172 "type.pcc"
#line 172 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Dereference a type expression.
//
/////////////////////////////////////////////////////////////////////////////

Ty deref( Ty ty)
{
  
#line 183 "type.pcc"
#line 183 "type.pcc"
{
  for (;;) {
    if (ty) {
      switch (ty->tag__) {
        case a_Ty::tag_VARty: {
          if (((Ty_VARty *)ty)->VARty) {
#line 183 "type.pcc"
           ty = ((Ty_VARty *)ty)->VARty; 
#line 183 "type.pcc"
          } else { goto L5; }
          } break;
        default: { goto L5; } break;
      }
    } else { goto L5; }
  }
  L5:;
}
#line 183 "type.pcc"
#line 183 "type.pcc"

  return ty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Get the default value of a type (if any)
//
/////////////////////////////////////////////////////////////////////////////

Exp default_val( Ty ty)
{
  
#line 195 "type.pcc"
#line 200 "type.pcc"
{
  Ty _V2 = deref(ty);
  if (_V2) {
    switch (_V2->tag__) {
      case a_Ty::tag_DEFVALty: {
#line 198 "type.pcc"
       return ((Ty_DEFVALty *)_V2)->_2; 
#line 198 "type.pcc"
        } break;
      default: {
        L6:; 
#line 200 "type.pcc"
       return NOexp; 
#line 200 "type.pcc"
        } break;
    }
  } else { goto L6; }
}
#line 201 "type.pcc"
#line 201 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test for qualifiers in a type
//
/////////////////////////////////////////////////////////////////////////////

Bool has_qual( TyQual q, Ty ty)
{
  
#line 212 "type.pcc"
#line 218 "type.pcc"
{
  for (;;) {
    if (ty) {
      switch (ty->tag__) {
        case a_Ty::tag_VARty: {
#line 214 "type.pcc"
         ty = ((Ty_VARty *)ty)->VARty; 
#line 214 "type.pcc"
          } break;
        case a_Ty::tag_QUALty: {
#line 218 "type.pcc"
         if (q & ((Ty_QUALty *)ty)->_1) return true; ty = ((Ty_QUALty *)ty)->_2; 
#line 218 "type.pcc"
          } break;
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)ty)->_1)) {
            switch (((Ty_TYCONty *)ty)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
#line 217 "type.pcc"
               return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->qualifiers & q; 
#line 217 "type.pcc"
                } break;
              default: { goto L7; } break;
            }
          } else { goto L7; }
          } break;
        case a_Ty::tag_DEFVALty: {
#line 216 "type.pcc"
         ty = ((Ty_DEFVALty *)ty)->_1; 
#line 216 "type.pcc"
          } break;
        case a_Ty::tag_NESTEDty: {
#line 215 "type.pcc"
         ty = ((Ty_NESTEDty *)ty)->_2; 
#line 215 "type.pcc"
          } break;
        default: { goto L7; } break;
      }
    } else { goto L7; }
  }
  L7:;
}
#line 219 "type.pcc"
#line 219 "type.pcc"

  return false;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is grounded (i.e. contains no type variables.)
//
/////////////////////////////////////////////////////////////////////////////

Bool is_ground( Ty ty)
{
  
#line 231 "type.pcc"
#line 238 "type.pcc"
{
  for (;;) {
    if (ty) {
      switch (ty->tag__) {
        case a_Ty::tag_VARty: {
#line 233 "type.pcc"
         ty = ((Ty_VARty *)ty)->VARty; 
#line 233 "type.pcc"
          } break;
        case a_Ty::tag_QUALty: {
#line 234 "type.pcc"
         ty = ((Ty_QUALty *)ty)->_2; 
#line 234 "type.pcc"
          } break;
        case a_Ty::tag_TYCONty: {
#line 237 "type.pcc"
         return is_ground(((Ty_TYCONty *)ty)->_2); 
#line 237 "type.pcc"
          } break;
        case a_Ty::tag_DEFVALty: {
#line 235 "type.pcc"
         ty = ((Ty_DEFVALty *)ty)->_1; 
#line 235 "type.pcc"
          } break;
        case a_Ty::tag_NESTEDty: {
#line 236 "type.pcc"
         if (! is_ground(((Ty_NESTEDty *)ty)->_1)) return false; ty = ((Ty_NESTEDty *)ty)->_2; 
#line 236 "type.pcc"
          } break;
        default: {
          L9:; 
#line 238 "type.pcc"
         return false; 
#line 238 "type.pcc"
          } break;
      }
    } else { goto L9; }
  }
}
#line 239 "type.pcc"
#line 239 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type list is grounded
//
/////////////////////////////////////////////////////////////////////////////

Bool is_ground( Tys tys)
{
  for_each (Ty, t, tys)
    if (! is_ground(t))
      return false;
  return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is an array
//
/////////////////////////////////////////////////////////////////////////////

Bool is_array_ty( Ty ty)
{
  
#line 264 "type.pcc"
#line 268 "type.pcc"
{
  Ty _V3 = deref_all(ty);
  if (_V3) {
    switch (_V3->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V3)->_1)) {
          switch (((Ty_TYCONty *)_V3)->_1->tag__) {
            case a_TyCon::tag_ARRAYtycon: {
              if (((TyCon_ARRAYtycon *)((Ty_TYCONty *)_V3)->_1)->ARRAYtycon) {
                if (((Ty_TYCONty *)_V3)->_2) {
                  L10:; 
                  if (((Ty_TYCONty *)_V3)->_2->_2) {
                    L11:; 
#line 268 "type.pcc"
                   return false; 
#line 268 "type.pcc"
                  } else {
                    L12:; 
#line 266 "type.pcc"
                   return true; 
#line 266 "type.pcc"
                  }
                } else { goto L11; }
              } else { goto L11; }
              } break;
            default: { goto L11; } break;
          }
        } else { goto L11; }
        } break;
      case a_Ty::tag_NESTEDty: {
#line 267 "type.pcc"
       return is_array_ty(((Ty_NESTEDty *)_V3)->_2); 
#line 267 "type.pcc"
        } break;
      default: { goto L11; } break;
    }
  } else { goto L11; }
}
#line 269 "type.pcc"
#line 269 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is a polymorphic datatype
//
/////////////////////////////////////////////////////////////////////////////

Bool is_poly_datatype( Ty ty)
{
  
#line 280 "type.pcc"
#line 283 "type.pcc"
{
  Ty _V4 = deref_all(ty);
  if (_V4) {
    switch (_V4->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V4)->_1)) {
          switch (((Ty_TYCONty *)_V4)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 282 "type.pcc"
             return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->tyvars != 
#line 282 "type.pcc"
#line 282 "type.pcc"
              nil_1_
#line 282 "type.pcc"
#line 282 "type.pcc"
              ; 
#line 282 "type.pcc"
              } break;
            default: {
              L13:; 
#line 283 "type.pcc"
             return false; 
#line 283 "type.pcc"
              } break;
          }
        } else { goto L13; }
        } break;
      default: { goto L13; } break;
    }
  } else { goto L13; }
}
#line 284 "type.pcc"
#line 284 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is a datatype.
//
/////////////////////////////////////////////////////////////////////////////

Bool is_datatype( Ty ty)
{
  
#line 295 "type.pcc"
#line 298 "type.pcc"
{
  Ty _V5 = deref_all(ty);
  if (_V5) {
    switch (_V5->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V5)->_1)) {
          switch (((Ty_TYCONty *)_V5)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 297 "type.pcc"
             return true; 
#line 297 "type.pcc"
              } break;
            default: {
              L14:; 
#line 298 "type.pcc"
             return false; 
#line 298 "type.pcc"
              } break;
          }
        } else { goto L14; }
        } break;
      default: { goto L14; } break;
    }
  } else { goto L14; }
}
#line 299 "type.pcc"
#line 299 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
// Add a new class to an inheritance list
//
/////////////////////////////////////////////////////////////////////////////

Inherits add_inherit( Id id, TyVars p, Inherits i, Scope s, TyQual t)
{
  Inherit inh = 
#line 310 "type.pcc"
#line 310 "type.pcc"
INHERIT(mkidty(id,tyvars_to_tys(p)), s, t)
#line 315 "type.pcc"
#line 315 "type.pcc"
;
  return 
#line 316 "type.pcc"
#line 316 "type.pcc"
list_1_(inh,i)
#line 316 "type.pcc"
#line 316 "type.pcc"
;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is garbage collectable.
//
/////////////////////////////////////////////////////////////////////////////

Bool is_gc_ty( Ty ty)
{
  
#line 327 "type.pcc"
#line 344 "type.pcc"
{
  for (;;) {
    if (ty) {
      switch (ty->tag__) {
        case a_Ty::tag_VARty: {
#line 335 "type.pcc"
         ty = ((Ty_VARty *)ty)->VARty; 
#line 335 "type.pcc"
          } break;
        case a_Ty::tag_QUALty: {
#line 336 "type.pcc"
         if (((Ty_QUALty *)ty)->_1 & QUALcollectable) return true; ty = ((Ty_QUALty *)ty)->_2; 
#line 336 "type.pcc"
          } break;
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)ty)->_1)) {
            switch (((Ty_TYCONty *)ty)->_1->tag__) {
              case a_TyCon::tag_IDtycon: {
#line 338 "type.pcc"
                
                Ty t = deref_all(ty);
                if (t == ty) return false;
                ty = t;
                
#line 342 "type.pcc"
                } break;
              case a_TyCon::tag_DATATYPEtycon: {
#line 330 "type.pcc"
               return (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->qualifiers & QUALcollectable) && (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->arg > 0); 
#line 330 "type.pcc"
                } break;
              default: {
                L16:; 
#line 344 "type.pcc"
               return false; 
#line 344 "type.pcc"
                } break;
            }
          } else {
            switch ((int)((Ty_TYCONty *)ty)->_1) {
              case ((int)v_POINTERtycon): {
                if (((Ty_TYCONty *)ty)->_2) {
                  if (((Ty_TYCONty *)ty)->_2->_2) { goto L16; } else {
#line 332 "type.pcc"
                   ty = ((Ty_TYCONty *)ty)->_2->_1; 
#line 332 "type.pcc"
                  }
                } else { goto L16; }
                } break;
              case ((int)v_REFtycon): {
                if (((Ty_TYCONty *)ty)->_2) {
                  if (((Ty_TYCONty *)ty)->_2->_2) { goto L16; } else {
#line 331 "type.pcc"
                   ty = ((Ty_TYCONty *)ty)->_2->_1; 
#line 331 "type.pcc"
                  }
                } else { goto L16; }
                } break;
              default: { goto L16; } break;
            }
          }
          } break;
        case a_Ty::tag_DEFVALty: {
#line 333 "type.pcc"
         ty = ((Ty_DEFVALty *)ty)->_1; 
#line 333 "type.pcc"
          } break;
        case a_Ty::tag_NESTEDty: {
#line 334 "type.pcc"
         ty = ((Ty_NESTEDty *)ty)->_2; 
#line 334 "type.pcc"
          } break;
        default: { goto L16; } break;
      }
    } else { goto L16; }
  }
}
#line 345 "type.pcc"
#line 345 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if type is a pointer.
//
/////////////////////////////////////////////////////////////////////////////

Bool is_pointer_ty( Ty ty)
{
  
#line 356 "type.pcc"
#line 361 "type.pcc"
{
  Ty _V6 = deref_all(ty);
  if (_V6) {
    switch (_V6->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V6)->_1)) {
          switch (((Ty_TYCONty *)_V6)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
              L17:; 
#line 359 "type.pcc"
             return true; 
#line 359 "type.pcc"
              } break;
            default: {
              L18:; 
#line 361 "type.pcc"
             return false; 
#line 361 "type.pcc"
              } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)_V6)->_1) {
            case ((int)v_POINTERtycon): { goto L17; } break;
            default: { goto L18; } break;
          }
        }
        } break;
      default: { goto L18; } break;
    }
  } else { goto L18; }
}
#line 362 "type.pcc"
#line 362 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if type is embeddable into 1 word
//
/////////////////////////////////////////////////////////////////////////////

Bool is_embeddable_ty( Ty ty)
{
  
#line 373 "type.pcc"
#line 382 "type.pcc"
{
  Ty _V7 = deref_all(ty);
  if (_V7) {
    switch (_V7->tag__) {
      case a_Ty::tag_TYCONty: {
        if (
#line 379 "type.pcc"
        ((ty_equal(_V7,integer_ty) || ty_equal(_V7,character_ty)) || ty_equal(_V7,bool_ty))
#line 381 "type.pcc"
) {
          
          if (boxed(((Ty_TYCONty *)_V7)->_1)) {
            switch (((Ty_TYCONty *)_V7)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
                if (
#line 377 "type.pcc"
                ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->opt & OPTtaggedpointer) == 0)
#line 377 "type.pcc"
) {
                  
                  L19:; 
                  switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                    case 0: {
                      L20:; 
#line 375 "type.pcc"
                     return true; 
#line 375 "type.pcc"
                    } break;
                    default: {
                      L21:; 
#line 377 "type.pcc"
                     return true; 
#line 377 "type.pcc"
                    }
                  }
                } else {
                  
                  switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                    case 0: { goto L20; } break;
                    default: {
                      L22:; 
#line 381 "type.pcc"
                     return true; 
#line 381 "type.pcc"
                    }
                  }
                }
                } break;
              default: { goto L22; } break;
            }
          } else {
            switch ((int)((Ty_TYCONty *)_V7)->_1) {
              case ((int)v_POINTERtycon): {
                if (((Ty_TYCONty *)_V7)->_2) {
                  if (((Ty_TYCONty *)_V7)->_2->_2) { goto L22; } else {
                    if (
#line 378 "type.pcc"
                    (((Ty_TYCONty *)_V7)->_2->_1 != character_ty)
#line 378 "type.pcc"
) {
                      
                      L23:; 
#line 378 "type.pcc"
                     return true; 
#line 378 "type.pcc"
                    } else {
                       goto L22; }
                  }
                } else { goto L22; }
                } break;
              default: { goto L22; } break;
            }
          }
        } else {
          
          if (boxed(((Ty_TYCONty *)_V7)->_1)) {
            switch (((Ty_TYCONty *)_V7)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
                if (
#line 377 "type.pcc"
                ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->opt & OPTtaggedpointer) == 0)
#line 377 "type.pcc"
) {
                   goto L19; } else {
                  
                  switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                    case 0: { goto L20; } break;
                    default: {
                      L24:; 
#line 382 "type.pcc"
                     return false; 
#line 382 "type.pcc"
                    }
                  }
                }
                } break;
              default: { goto L24; } break;
            }
          } else {
            switch ((int)((Ty_TYCONty *)_V7)->_1) {
              case ((int)v_POINTERtycon): {
                if (((Ty_TYCONty *)_V7)->_2) {
                  if (((Ty_TYCONty *)_V7)->_2->_2) { goto L24; } else {
                    if (
#line 378 "type.pcc"
                    (((Ty_TYCONty *)_V7)->_2->_1 != character_ty)
#line 378 "type.pcc"
) {
                       goto L23; } else {
                       goto L24; }
                  }
                } else { goto L24; }
                } break;
              default: { goto L24; } break;
            }
          }
        }
        } break;
      default: {
        L25:; 
        if (
#line 379 "type.pcc"
        ((ty_equal(_V7,integer_ty) || ty_equal(_V7,character_ty)) || ty_equal(_V7,bool_ty))
#line 381 "type.pcc"
) {
           goto L22; } else {
           goto L24; }
        } break;
    }
  } else { goto L25; }
}
#line 383 "type.pcc"
#line 383 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if constructor is an array-style constructor
//
/////////////////////////////////////////////////////////////////////////////

Bool is_array_constructor( Id id) { return id[1] == '|'; }

Bool is_list_constructor( Id id)
    {
      return id[0] == '#' &&
          (id[1] == '[' ||
          id[1] == '(' ||
          id[1] == '{');
    }

Bool is_list_constructor( Cons cons)
    { return cons != NOcons && is_list_constructor(cons->name); }

/////////////////////////////////////////////////////////////////////////////
//
//  Returns the number of boxed variants.
//
/////////////////////////////////////////////////////////////////////////////

int boxed_variants( Ty ty)
{
  
#line 413 "type.pcc"
#line 416 "type.pcc"
{
  Ty _V8 = deref_all(ty);
  if (_V8) {
    switch (_V8->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V8)->_1)) {
          switch (((Ty_TYCONty *)_V8)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 415 "type.pcc"
             return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V8)->_1)->arg; 
#line 415 "type.pcc"
              } break;
            default: {
              L26:; 
#line 416 "type.pcc"
             return 0; 
#line 416 "type.pcc"
              } break;
          }
        } else { goto L26; }
        } break;
      default: { goto L26; } break;
    }
  } else { goto L26; }
}
#line 417 "type.pcc"
#line 417 "type.pcc"

}

int unboxed_variants( Ty ty)
{
  
#line 422 "type.pcc"
#line 425 "type.pcc"
{
  Ty _V9 = deref_all(ty);
  if (_V9) {
    switch (_V9->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V9)->_1)) {
          switch (((Ty_TYCONty *)_V9)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 424 "type.pcc"
             return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V9)->_1)->unit; 
#line 424 "type.pcc"
              } break;
            default: {
              L27:; 
#line 425 "type.pcc"
             return 0; 
#line 425 "type.pcc"
              } break;
          }
        } else { goto L27; }
        } break;
      default: { goto L27; } break;
    }
  } else { goto L27; }
}
#line 426 "type.pcc"
#line 426 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Returns the arity of a type
//
/////////////////////////////////////////////////////////////////////////////

int arity_of( Ty ty)
{
  
#line 437 "type.pcc"
#line 442 "type.pcc"
{
  Ty _V10 = deref_all(ty);
  if (_V10) {
    switch (_V10->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V10)->_1)) {
          switch (((Ty_TYCONty *)_V10)->_1->tag__) {
            case a_TyCon::tag_RECORDtycon: {
              L28:; 
#line 440 "type.pcc"
             return length(((Ty_TYCONty *)_V10)->_2); 
#line 440 "type.pcc"
              } break;
            default: {
              L29:; 
#line 442 "type.pcc"
             return 1; 
#line 442 "type.pcc"
              } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)_V10)->_1) {
            case ((int)v_TUPLEtycon): { goto L28; } break;
            default: { goto L29; } break;
          }
        }
        } break;
      case a_Ty::tag_NESTEDty: {
#line 441 "type.pcc"
       return arity_of(((Ty_NESTEDty *)_V10)->_2); 
#line 441 "type.pcc"
        } break;
      default: { goto L29; } break;
    }
  } else {
#line 439 "type.pcc"
   return 0; 
#line 439 "type.pcc"
  }
}
#line 443 "type.pcc"
#line 443 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a polymorphic type scheme
//
/////////////////////////////////////////////////////////////////////////////

Ty inst( Ty ty, int n, Id bound_vars[], Ty subst[])
{
  
#line 454 "type.pcc"
#line 466 "type.pcc"
{
  Ty _V11 = deref(ty);
  if (_V11) {
    switch (_V11->tag__) {
      case a_Ty::tag_VARty: {
        L30:; 
#line 456 "type.pcc"
       return ty; 
#line 456 "type.pcc"
        } break;
      case a_Ty::tag_INDty: {
#line 458 "type.pcc"
       return subst[((Ty_INDty *)_V11)->_2] != NOty ? subst[((Ty_INDty *)_V11)->_2] : (subst[((Ty_INDty *)_V11)->_2] = mkvar()); 
#line 458 "type.pcc"
        } break;
      case a_Ty::tag_QUALty: {
#line 459 "type.pcc"
       return QUALty(((Ty_QUALty *)_V11)->_1,inst(((Ty_QUALty *)_V11)->_2,n,bound_vars,subst)); 
#line 459 "type.pcc"
        } break;
      case a_Ty::tag_TYCONty: {
#line 465 "type.pcc"
      return TYCONty(((Ty_TYCONty *)_V11)->_1, inst(((Ty_TYCONty *)_V11)->_2,n,bound_vars,subst)); 
#line 465 "type.pcc"
        } break;
      case a_Ty::tag_POLYty: {
#line 466 "type.pcc"
       bug("inst()"); return NOty; 
#line 466 "type.pcc"
        } break;
      case a_Ty::tag_DEFVALty: {
#line 460 "type.pcc"
       return DEFVALty(inst(((Ty_DEFVALty *)_V11)->_1,n,bound_vars,subst),((Ty_DEFVALty *)_V11)->_2); 
#line 460 "type.pcc"
        } break;
      default: {
#line 461 "type.pcc"
       return NESTEDty(inst(((Ty_NESTEDty *)_V11)->_1,n,bound_vars,subst),
        inst(((Ty_NESTEDty *)_V11)->_2,n,bound_vars,subst));
        
#line 463 "type.pcc"
        } break;
    }
  } else { goto L30; }
}
#line 467 "type.pcc"
#line 467 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a type list
//
/////////////////////////////////////////////////////////////////////////////

Tys inst( Tys tys, int n, Id bound_vars[], Ty subst[])
{
  
#line 478 "type.pcc"
#line 485 "type.pcc"
{
  if (tys) {
#line 482 "type.pcc"
    
    return 
#line 483 "type.pcc"
#line 483 "type.pcc"
    list_1_(inst(tys->_1,n,bound_vars,subst),inst(tys->_2,n,bound_vars,subst))
#line 484 "type.pcc"
#line 484 "type.pcc"
    ;
    
#line 485 "type.pcc"
  } else {
#line 480 "type.pcc"
   return 
#line 480 "type.pcc"
#line 480 "type.pcc"
    nil_1_
#line 480 "type.pcc"
#line 480 "type.pcc"
    ; 
#line 480 "type.pcc"
  }
}
#line 486 "type.pcc"
#line 486 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a polymorphic type scheme
//
/////////////////////////////////////////////////////////////////////////////

Ty inst( Ty polyty)
{
  
#line 497 "type.pcc"
#line 505 "type.pcc"
{
  if (polyty) {
    switch (polyty->tag__) {
      case a_Ty::tag_POLYty: {
#line 500 "type.pcc"
        
        Ty subst[256];
        for (int i = ((Ty_POLYty *)polyty)->_2 - 1; i >= 0; i--) subst[i] = NOty;
        return inst(((Ty_POLYty *)polyty)->_1, ((Ty_POLYty *)polyty)->_2, ((Ty_POLYty *)polyty)->_3, subst);
        
#line 504 "type.pcc"
        } break;
      default: {
        L31:; 
#line 505 "type.pcc"
       return polyty; 
#line 505 "type.pcc"
        } break;
    }
  } else { goto L31; }
}
#line 506 "type.pcc"
#line 506 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Construct component types
//
/////////////////////////////////////////////////////////////////////////////

Ty component_ty( Ty datatype_ty, Cons cons)
{
  
#line 517 "type.pcc"
#line 522 "type.pcc"
{
  Ty _V12 = deref_all(datatype_ty);
  if (_V12) {
    switch (_V12->tag__) {
      case a_Ty::tag_TYCONty: {
        if (cons) {
          if (boxed(((Ty_TYCONty *)_V12)->_1)) {
            switch (((Ty_TYCONty *)_V12)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
                if (((Ty_TYCONty *)_V12)->_2) {
                  if (cons) {
                    if (cons->ty) {
                      L32:; 
#line 520 "type.pcc"
                    return apply_ty(cons->cons_ty,((Ty_TYCONty *)_V12)->_2); 
#line 520 "type.pcc"
                    } else {
                      L33:; 
#line 521 "type.pcc"
                     return cons->ty; 
#line 521 "type.pcc"
                    }
                  } else { goto L33; }
                } else { goto L33; }
                } break;
              default: { goto L33; } break;
            }
          } else { goto L33; }
        } else {
          if (boxed(((Ty_TYCONty *)_V12)->_1)) {
            switch (((Ty_TYCONty *)_V12)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
                if (((Ty_TYCONty *)_V12)->_2) {
                  if (cons) {
                    if (cons->ty) { goto L32; } else {
                      L34:; 
#line 522 "type.pcc"
                     return NOty; 
#line 522 "type.pcc"
                    }
                  } else { goto L34; }
                } else { goto L34; }
                } break;
              default: { goto L34; } break;
            }
          } else { goto L34; }
        }
        } break;
      default: {
        L35:; 
        if (cons) { goto L33; } else { goto L34; }
        } break;
    }
  } else { goto L35; }
}
#line 523 "type.pcc"
#line 523 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Extract record type component
//
/////////////////////////////////////////////////////////////////////////////

Ty component_ty( Ty record_ty, Id label)
{
  
#line 534 "type.pcc"
#line 550 "type.pcc"
{
  Ty _V13 = deref_all(record_ty);
  if (_V13) {
    switch (_V13->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V13)->_1)) {
          switch (((Ty_TYCONty *)_V13)->_1->tag__) {
            case a_TyCon::tag_RECORDtycon: {
#line 537 "type.pcc"
              
              Ids ls; Tys ts;
              for (ls = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V13)->_1)->_1, ts = ((Ty_TYCONty *)_V13)->_2; ls && ts; ls = ls->_2, ts = ts->_2)
                if (ls->_1 == label)
                  return ts->_1;
              
#line 542 "type.pcc"
              } break;
            default: {
              L36:; } break;
          }
        } else {
          switch ((int)((Ty_TYCONty *)_V13)->_1) {
            case ((int)v_TUPLEtycon): {
              if (
#line 543 "type.pcc"
              (label[0] == '_')
#line 543 "type.pcc"
) {
                
#line 544 "type.pcc"
                
                int i = std::atol( label + 1);
                if (i > 0)
                  return component_ty(_V13,i);
                
#line 548 "type.pcc"
              } else {
                 goto L36; }
              } break;
            default: { goto L36; } break;
          }
        }
        } break;
      default: { goto L36; } break;
    }
  } else { goto L36; }
}
#line 550 "type.pcc"
#line 550 "type.pcc"

  error( "%Ltype %T does not have component %s\n", record_ty, label);
  return NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Extract tuple type component
//
/////////////////////////////////////////////////////////////////////////////

Ty component_ty( Ty tuple_ty, int n)
{
  
#line 563 "type.pcc"
#line 572 "type.pcc"
{
  Ty _V14 = deref_all(tuple_ty);
  if (_V14) {
    switch (_V14->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V14)->_1)) {
          L37:; } else {
          switch ((int)((Ty_TYCONty *)_V14)->_1) {
            case ((int)v_TUPLEtycon): {
#line 566 "type.pcc"
              
              int i; Tys ts;
              for (i = 1, ts = ((Ty_TYCONty *)_V14)->_2; ts; ts = ts->_2, i++)
                if (i == n) return ts->_1;
              
#line 570 "type.pcc"
              } break;
            default: { goto L37; } break;
          }
        }
        } break;
      default: { goto L37; } break;
    }
  } else { goto L37; }
}
#line 572 "type.pcc"
#line 572 "type.pcc"

  error( "%Ltype %T does not have component #%i\n",tuple_ty,n);
  return NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Apply type arguments to a ty_scheme.
//
/////////////////////////////////////////////////////////////////////////////

Ty apply_ty( Ty cons_ty, Tys tys)
{
  
#line 585 "type.pcc"
#line 620 "type.pcc"
{
  if (cons_ty) {
    switch (cons_ty->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)cons_ty)->_1)) {
          L38:; 
#line 620 "type.pcc"
         return cons_ty; 
#line 620 "type.pcc"
        } else {
          switch ((int)((Ty_TYCONty *)cons_ty)->_1) {
            case ((int)v_FUNtycon): {
              if (((Ty_TYCONty *)cons_ty)->_2) {
#line 619 "type.pcc"
               return ((Ty_TYCONty *)cons_ty)->_2->_1; 
#line 619 "type.pcc"
              } else { goto L38; }
              } break;
            default: { goto L38; } break;
          }
        }
        } break;
      case a_Ty::tag_POLYty: {
#line 588 "type.pcc"
        
        Ty subst[256]; int i; Tys ts;
        
        for (i = 0, ts = tys; i < ((Ty_POLYty *)cons_ty)->_2 && ts; i++, ts = ts->_2)
           subst[i] = ts->_1;
        
        if (ts != 
#line 594 "type.pcc"
#line 594 "type.pcc"
        nil_1_
#line 594 "type.pcc"
#line 594 "type.pcc"
        )
        {
          error( "%Ltoo many arguments %P in instantiation of type scheme %T\n",
               tys, cons_ty);
          return NOty;
        }
        if (i != ((Ty_POLYty *)cons_ty)->_2)
        {
          error( "%Ltoo few arguments %P in instantiation of type scheme %T\n",
               tys, cons_ty);
          return NOty;
        }
        Ty t = inst( ((Ty_POLYty *)cons_ty)->_1, ((Ty_POLYty *)cons_ty)->_2, ((Ty_POLYty *)cons_ty)->_3, subst);
        
        
#line 608 "type.pcc"
#line 616 "type.pcc"
        {
          Ty _V15 = deref(t);
          if (_V15) {
            switch (_V15->tag__) {
              case a_Ty::tag_TYCONty: {
                if (boxed(((Ty_TYCONty *)_V15)->_1)) {
                  L39:; 
#line 611 "type.pcc"
                 return _V15; 
#line 611 "type.pcc"
                } else {
                  switch ((int)((Ty_TYCONty *)_V15)->_1) {
                    case ((int)v_FUNtycon): {
                      if (((Ty_TYCONty *)_V15)->_2) {
                        if (((Ty_TYCONty *)_V15)->_2->_2) {
                          if (((Ty_TYCONty *)_V15)->_2->_2->_2) { goto L39; } else {
#line 610 "type.pcc"
                           return ((Ty_TYCONty *)_V15)->_2->_1; 
#line 610 "type.pcc"
                          }
                        } else { goto L39; }
                      } else { goto L39; }
                      } break;
                    default: { goto L39; } break;
                  }
                }
                } break;
              default: {
                L40:; 
#line 613 "type.pcc"
                
                error ("%Lbad constructor type %T\n",cons_ty);
                              return NOty;
                
#line 616 "type.pcc"
                } break;
            }
          } else { goto L40; }
        }
#line 617 "type.pcc"
#line 617 "type.pcc"
        
        
#line 618 "type.pcc"
        } break;
      default: { goto L38; } break;
    }
  } else { goto L38; }
}
#line 621 "type.pcc"
#line 621 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two type constructors
//
/////////////////////////////////////////////////////////////////////////////

Bool unify( TyCon a, TyCon b)
{
  
#line 632 "type.pcc"
#line 648 "type.pcc"
{
  if (boxed(a)) {
    switch (a->tag__) {
      case a_TyCon::tag_IDtycon: {
        if (boxed(b)) {
          switch (b->tag__) {
            case a_TyCon::tag_IDtycon: {
#line 637 "type.pcc"
             return ((TyCon_IDtycon *)a)->IDtycon == ((TyCon_IDtycon *)b)->IDtycon; 
#line 637 "type.pcc"
              } break;
            default: {
              L41:; 
#line 648 "type.pcc"
             return false; 
#line 648 "type.pcc"
              } break;
          }
        } else { goto L41; }
        } break;
      case a_TyCon::tag_ARRAYtycon: {
        L42:; 
        if (boxed(b)) {
          switch (b->tag__) {
            case a_TyCon::tag_ARRAYtycon: {
              L43:; 
#line 635 "type.pcc"
             return true; 
#line 635 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        } else {
          switch ((int)b) {
            case ((int)v_POINTERtycon): { goto L43; } break;
            default: { goto L41; } break;
          }
        }
        } break;
      case a_TyCon::tag_BITFIELDtycon: {
        if (boxed(b)) {
          switch (b->tag__) {
            case a_TyCon::tag_BITFIELDtycon: {
#line 647 "type.pcc"
             return ((TyCon_BITFIELDtycon *)a)->width == ((TyCon_BITFIELDtycon *)b)->width && ((TyCon_BITFIELDtycon *)a)->is_signed == ((TyCon_BITFIELDtycon *)b)->is_signed; 
#line 647 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        } else { goto L41; }
        } break;
      case a_TyCon::tag_DATATYPEtycon: {
        if (boxed(b)) {
          switch (b->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 642 "type.pcc"
             return a == b; 
#line 642 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        } else { goto L41; }
        } break;
      case a_TyCon::tag_COLtycon: {
        if (boxed(b)) {
          switch (b->tag__) {
            case a_TyCon::tag_COLtycon: {
#line 644 "type.pcc"
             return ((TyCon_COLtycon *)a)->COLtycon->name == ((TyCon_COLtycon *)b)->COLtycon->name; 
#line 644 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        } else { goto L41; }
        } break;
      default: { goto L41; } break;
    }
  } else {
    switch ((int)a) {
      case ((int)v_POINTERtycon): { goto L42; } break;
      case ((int)v_REFtycon): {
        if (boxed(b)) { goto L41; } else {
          switch ((int)b) {
            case ((int)v_REFtycon): {
#line 636 "type.pcc"
             return true; 
#line 636 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        }
        } break;
      case ((int)v_TUPLEtycon): {
        if (boxed(b)) { goto L41; } else {
          switch ((int)b) {
            case ((int)v_TUPLEtycon): {
#line 638 "type.pcc"
             return true; 
#line 638 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        }
        } break;
      case ((int)v_EXTUPLEtycon): {
        if (boxed(b)) { goto L41; } else {
          switch ((int)b) {
            case ((int)v_EXTUPLEtycon): {
#line 639 "type.pcc"
             return true; 
#line 639 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        }
        } break;
      case ((int)v_FUNtycon): {
        if (boxed(b)) { goto L41; } else {
          switch ((int)b) {
            case ((int)v_FUNtycon): {
#line 641 "type.pcc"
             return true; 
#line 641 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        }
        } break;
      default: {
        if (boxed(b)) { goto L41; } else {
          switch ((int)b) {
            case ((int)v_TYPEtycon): {
#line 640 "type.pcc"
             return true; 
#line 640 "type.pcc"
              } break;
            default: { goto L41; } break;
          }
        }
        } break;
    }
  }
}
#line 649 "type.pcc"
#line 649 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two record types
//
/////////////////////////////////////////////////////////////////////////////

Bool unify_record
   (Ty u, Ids& x, Tys& a, Bool& f,
    Ty v, Ids& y, Tys& b, Bool& g, Bool again = true)
{
  Ids i, j;
  Tys p, q;
  Bool ok = true;

  for (i = x, p = a; i; i = i->_2, p = p->_2)
  {
    Bool b_found = false;
    for (j = y, q = b; j; j = j->_2, q = q->_2)
    {
      if (i->_1 == j->_1)
      {
        if (b_found)
        {
           error( "%Lduplicated label '%s' in type %T\n", i->_1, v);
           ok = false;
        }
        b_found = true;
        if (! unify(p->_1, q->_1)) ok = false;
      }
    }
    if (! b_found && ! g)
    {
      error( "%L%s label '%s' in type %T\n",
             (again ? "missing" : "extra"), i->_1, v);
      ok = false;
    }
  }

  // unify in the other direction if not flexible
  if (again && ! f)
    unify_record( v, y, b, g, u, x, a, f, false);

  if (! f && g) { y = x; b = a; }
  if (! g && f) { x = y; a = b; }

  if (! f) g = false;
  if (! g) f = false;

  return ok;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Occurs check
//
/////////////////////////////////////////////////////////////////////////////

Bool occurs( Ty ty, Ty tyvar)
{
  
#line 711 "type.pcc"
#line 721 "type.pcc"
{
  Ty _V16 = deref_all(ty);
  if (_V16) {
    switch (_V16->tag__) {
      case a_Ty::tag_VARty: {
        if (
#line 713 "type.pcc"
        (tyvar == _V16)
#line 713 "type.pcc"
) {
          
#line 713 "type.pcc"
         return true; 
#line 713 "type.pcc"
        } else {
          
          L44:; 
#line 721 "type.pcc"
         return false; 
#line 721 "type.pcc"
        }
        } break;
      case a_Ty::tag_TYCONty: {
#line 715 "type.pcc"
        
        for_each(Ty, t, ((Ty_TYCONty *)_V16)->_2)
          if (occurs(t,tyvar))
            return true;
        return false;
        
#line 720 "type.pcc"
        } break;
      default: { goto L44; } break;
    }
  } else { goto L44; }
}
#line 722 "type.pcc"
#line 722 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two types.  Returns true iff unification succeeds.
//
/////////////////////////////////////////////////////////////////////////////

Bool unify( Ty t1, Ty t2)
{
  
#line 733 "type.pcc"
#line 774 "type.pcc"
{
  Ty _V17 = deref(t1);
  Ty _V18 = deref(t2);
  if (
#line 736 "type.pcc"
  (_V17 == _V18)
#line 736 "type.pcc"
) {
    
    if (_V17) {
      if (_V18) {
        L45:; 
#line 736 "type.pcc"
       return true; 
#line 736 "type.pcc"
      } else {
        L46:; 
#line 735 "type.pcc"
       return false; 
#line 735 "type.pcc"
      }
    } else { goto L46; }
  } else {
    
    if (_V17) {
      switch (_V17->tag__) {
        case a_Ty::tag_VARty: {
          if (_V18) {
            switch (_V18->tag__) {
              case a_Ty::tag_VARty: {
                L47:; 
#line 738 "type.pcc"
                
                if (occurs(_V17,_V18))
                {
                    error( "%Lunification fails occurs check with %T and %T\n",t1,t2);
                    return false;
                }
                else
                {
                  ((Ty_VARty *)_V18)->VARty = _V17;
                  return true;
                }
                
#line 749 "type.pcc"
                } break;
              default: {
#line 751 "type.pcc"
                
                if (occurs(_V18,_V17))
                {
                    error( "%Lunification fails occurs check with %T and %T\n",t1,t2);
                    return false;
                }
                else
                {
                  ((Ty_VARty *)_V17)->VARty = _V18;
                  return true;
                }
                
#line 762 "type.pcc"
                } break;
            }
          } else { goto L46; }
          } break;
        default: {
          if (_V18) {
            switch (_V18->tag__) {
              case a_Ty::tag_VARty: { goto L47; } break;
              default: {
                L48:; 
#line 764 "type.pcc"
                
                
#line 765 "type.pcc"
#line 772 "type.pcc"
                {
                  Ty _V19 = deref_all(t1);
                  Ty _V20 = deref_all(t2);
                  if (
#line 767 "type.pcc"
                  (_V19 == _V20)
#line 767 "type.pcc"
) {
                    
#line 767 "type.pcc"
                   return true; 
#line 767 "type.pcc"
                  } else {
                    
                    if (_V19) {
                      switch (_V19->tag__) {
                        case a_Ty::tag_TYCONty: {
                          if (_V20) {
                            switch (_V20->tag__) {
                              case a_Ty::tag_TYCONty: {
                                if (boxed(((Ty_TYCONty *)_V19)->_1)) {
                                  switch (((Ty_TYCONty *)_V19)->_1->tag__) {
                                    case a_TyCon::tag_RECORDtycon: {
                                      if (_V20) {
                                        switch (_V20->tag__) {
                                          case a_Ty::tag_TYCONty: {
                                            if (boxed(((Ty_TYCONty *)_V20)->_1)) {
                                              switch (((Ty_TYCONty *)_V20)->_1->tag__) {
                                                case a_TyCon::tag_RECORDtycon: {
                                                  L49:; 
#line 769 "type.pcc"
                                                 return unify_record( t1, ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V19)->_1)->_1, ((Ty_TYCONty *)_V19)->_2, ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V19)->_1)->_2, t2, ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V20)->_1)->_1, ((Ty_TYCONty *)_V20)->_2, ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V20)->_1)->_2); 
#line 769 "type.pcc"
                                                  } break;
                                                default: {
                                                  L50:; 
#line 770 "type.pcc"
                                                 return unify(((Ty_TYCONty *)_V19)->_1,((Ty_TYCONty *)_V20)->_1) && unify(((Ty_TYCONty *)_V19)->_2,((Ty_TYCONty *)_V20)->_2); 
#line 770 "type.pcc"
                                                  } break;
                                              }
                                            } else { goto L50; }
                                            } break;
                                          default: { goto L50; } break;
                                        }
                                      } else { goto L50; }
                                      } break;
                                    default: { goto L50; } break;
                                  }
                                } else { goto L50; }
                                } break;
                              default: {
                                L51:; 
                                if (boxed(((Ty_TYCONty *)_V19)->_1)) {
                                  switch (((Ty_TYCONty *)_V19)->_1->tag__) {
                                    case a_TyCon::tag_RECORDtycon: {
                                      L52:; 
                                      if (_V20) {
                                        switch (_V20->tag__) {
                                          case a_Ty::tag_TYCONty: {
                                            L53:; 
                                            if (boxed(((Ty_TYCONty *)_V20)->_1)) {
                                              switch (((Ty_TYCONty *)_V20)->_1->tag__) {
                                                case a_TyCon::tag_RECORDtycon: { goto L49; } break;
                                                default: {
                                                  L54:; 
#line 772 "type.pcc"
                                                 return false; 
#line 772 "type.pcc"
                                                  } break;
                                              }
                                            } else { goto L54; }
                                            } break;
                                          default: { goto L54; } break;
                                        }
                                      } else { goto L54; }
                                      } break;
                                    default: { goto L54; } break;
                                  }
                                } else { goto L54; }
                                } break;
                            }
                          } else { goto L51; }
                          } break;
                        case a_Ty::tag_NESTEDty: {
                          if (_V20) {
                            switch (_V20->tag__) {
                              case a_Ty::tag_NESTEDty: {
#line 771 "type.pcc"
                               return unify(((Ty_NESTEDty *)_V19)->_1,((Ty_NESTEDty *)_V20)->_1) && unify(((Ty_NESTEDty *)_V19)->_2,((Ty_NESTEDty *)_V20)->_2); 
#line 771 "type.pcc"
                                } break;
                              default: { goto L54; } break;
                            }
                          } else { goto L54; }
                          } break;
                        default: { goto L54; } break;
                      }
                    } else { goto L54; }
                  }
                }
#line 773 "type.pcc"
#line 773 "type.pcc"
                
                
#line 774 "type.pcc"
                } break;
            }
          } else { goto L46; }
          } break;
      }
    } else { goto L46; }
  }
}
#line 775 "type.pcc"
#line 775 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two type lists.
//
/////////////////////////////////////////////////////////////////////////////

Bool unify( Tys xs, Tys ys)
{
  Bool ok = true;
  
#line 787 "type.pcc"
#line 795 "type.pcc"
{
  for (;;) {
    if (xs) {
      if (ys) {
#line 790 "type.pcc"
        
        if (! unify(xs->_1, ys->_1))
          ok = false;
        xs = xs->_2;
        ys = ys->_2;
        
#line 795 "type.pcc"
      } else { goto L55; }
    } else { goto L55; }
  }
  L55:;
}
#line 796 "type.pcc"
#line 796 "type.pcc"

  return ok && xs == 
#line 797 "type.pcc"
#line 797 "type.pcc"
nil_1_
#line 797 "type.pcc"
#line 797 "type.pcc"
 && ys == 
#line 797 "type.pcc"
#line 797 "type.pcc"
nil_1_
#line 797 "type.pcc"
#line 797 "type.pcc"
;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two types and print error message if fails.
//
/////////////////////////////////////////////////////////////////////////////

Bool unify( Pat p, Ty a, Ty b)
{
  if (! unify(a,b))
  {
    error ("%Ltype mismatch in pattern: %p\n"
            "%Lexpecting '%T' but found '%T'\n", p, a, b);
    return false;
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of literals
//
/////////////////////////////////////////////////////////////////////////////

Ty type_of( Literal l)
{
  
#line 825 "type.pcc"
#line 833 "type.pcc"
{
  switch (l->tag__) {
    case a_Literal::tag_INTlit: {
#line 827 "type.pcc"
     return integer_ty; 
#line 827 "type.pcc"
      } break;
    case a_Literal::tag_BOOLlit: {
#line 829 "type.pcc"
     return bool_ty; 
#line 829 "type.pcc"
      } break;
    case a_Literal::tag_CHARlit: {
#line 828 "type.pcc"
     return character_ty; 
#line 828 "type.pcc"
      } break;
    case a_Literal::tag_REALlit: {
#line 830 "type.pcc"
     return real_ty; 
#line 830 "type.pcc"
      } break;
    case a_Literal::tag_QUARKlit: {
#line 831 "type.pcc"
     return quark_ty; 
#line 831 "type.pcc"
      } break;
    case a_Literal::tag_BIGINTlit: {
#line 832 "type.pcc"
     return bigint_ty; 
#line 832 "type.pcc"
      } break;
    default: {
#line 833 "type.pcc"
     return string_ty; 
#line 833 "type.pcc"
      } break;
  }
}
#line 834 "type.pcc"
#line 834 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Additional pattern variable type map.
//
/////////////////////////////////////////////////////////////////////////////

HashTable * patvar_typemap = 0;

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a pattern.
//
/////////////////////////////////////////////////////////////////////////////

Ty type_of( Pat pat)
{
  Ty t = NOty;
  
#line 854 "type.pcc"
#line 949 "type.pcc"
{
  if (pat) {
    switch (pat->tag__) {
      case a_Pat::tag_WILDpat: {
#line 857 "type.pcc"
       t = mkvar(); 
#line 857 "type.pcc"
        } break;
      case a_Pat::tag_INDpat: {
#line 858 "type.pcc"
       t = ((Pat_INDpat *)pat)->_3; 
#line 858 "type.pcc"
        } break;
      case a_Pat::tag_IDpat: {
#line 860 "type.pcc"
        
        t = ((Pat_IDpat *)pat)->_2;
        // If we have a pattern variable type map
        // also use it.
        if (patvar_typemap)
        {
          HashTable::Entry * e = patvar_typemap->lookup(((Pat_IDpat *)pat)->_1);
          if (e)
          {
            Ty nonterm_ty = Ty(e->v);
            if ( !unify( nonterm_ty, ((Pat_IDpat *)pat)->_2))
            {
              error( "%Lexpecting non-terminal %s to have type %T but found %T\n",
                    ((Pat_IDpat *)pat)->_1, nonterm_ty, ((Pat_IDpat *)pat)->_2);
            }
          }
        }
        
#line 877 "type.pcc"
        } break;
      case a_Pat::tag_CONSpat: {
        if (((Pat_CONSpat *)pat)->CONSpat) {
#line 932 "type.pcc"
        t = inst( ((Pat_CONSpat *)pat)->CONSpat->cons_ty); 
#line 932 "type.pcc"
        } else {
#line 933 "type.pcc"
        errors++; t = mkvar(); 
#line 933 "type.pcc"
        }
        } break;
      case a_Pat::tag_APPpat: {
#line 935 "type.pcc"
        
        Ty fun_ty = type_of( ((Pat_APPpat *)pat)->_1);
        Ty range  = mkvar();
        unify( pat, fun_ty, mkfunty( type_of( ((Pat_APPpat *)pat)->_2), range));
        t = deref( range);
        
#line 940 "type.pcc"
        } break;
      case a_Pat::tag_TYPEDpat: {
#line 927 "type.pcc"
        
        t = type_of( ((Pat_TYPEDpat *)pat)->_1);
        unify( ((Pat_TYPEDpat *)pat)->_1, ((Pat_TYPEDpat *)pat)->_2, t);
        
#line 930 "type.pcc"
        } break;
      case a_Pat::tag_ASpat: {
#line 878 "type.pcc"
       t = type_of( ((Pat_ASpat *)pat)->_2); unify( pat, ((Pat_ASpat *)pat)->_3, t); 
#line 878 "type.pcc"
        } break;
      case a_Pat::tag_LITERALpat: {
#line 880 "type.pcc"
       t = type_of( ((Pat_LITERALpat *)pat)->LITERALpat); 
#line 880 "type.pcc"
        } break;
      case a_Pat::tag_CONTEXTpat: {
#line 885 "type.pcc"
       t = type_of( ((Pat_CONTEXTpat *)pat)->_2); 
#line 885 "type.pcc"
        } break;
      case a_Pat::tag_LEXEMEpat: {
#line 881 "type.pcc"
       t = string_ty; 
#line 881 "type.pcc"
        } break;
      case a_Pat::tag_ARRAYpat: {
#line 898 "type.pcc"
        
        Ty ty = mkvar();
        for_each( Pat, p, ((Pat_ARRAYpat *)pat)->_1)
          unify( pat, ty, type_of( p));
        t = mkptrty( QUALty( QUALconst, ty));
        
#line 903 "type.pcc"
        } break;
      case a_Pat::tag_TUPLEpat: {
#line 882 "type.pcc"
       t = mktuplety( type_of( ((Pat_TUPLEpat *)pat)->TUPLEpat)); 
#line 882 "type.pcc"
        } break;
      case a_Pat::tag_EXTUPLEpat: {
#line 883 "type.pcc"
       t = TYCONty( EXTUPLEtycon, type_of( ((Pat_EXTUPLEpat *)pat)->EXTUPLEpat)); 
#line 883 "type.pcc"
        } break;
      case a_Pat::tag_RECORDpat: {
#line 887 "type.pcc"
        
        t = mkrecordty( labels_of( ((Pat_RECORDpat *)pat)->_1), type_of( ((Pat_RECORDpat *)pat)->_1), ((Pat_RECORDpat *)pat)->_2);
        
#line 889 "type.pcc"
        } break;
      case a_Pat::tag_LISTpat: {
        if (((Pat_LISTpat *)pat)->head) {
#line 946 "type.pcc"
        t = type_of( APPpat( CONSpat( ((Pat_LISTpat *)pat)->cons),
          TUPLEpat( 
#line 947 "type.pcc"
#line 947 "type.pcc"
          list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(LISTpat(((Pat_LISTpat *)pat)->cons,((Pat_LISTpat *)pat)->nil,((Pat_LISTpat *)pat)->head->_2,((Pat_LISTpat *)pat)->tail)))
#line 947 "type.pcc"
#line 947 "type.pcc"
          )));
          
#line 948 "type.pcc"
        } else {
          if (((Pat_LISTpat *)pat)->tail) {
#line 944 "type.pcc"
          t = type_of( ((Pat_LISTpat *)pat)->tail); 
#line 944 "type.pcc"
          } else {
#line 942 "type.pcc"
          t = type_of( CONSpat( ((Pat_LISTpat *)pat)->nil)); 
#line 942 "type.pcc"
          }
        }
        } break;
      case a_Pat::tag_VECTORpat: {
#line 905 "type.pcc"
        
        Ty arg_ty = mkvar();
        for_each( Pat, p, ((Pat_VECTORpat *)pat)->elements)
          unify( pat, arg_ty, type_of( p));
        Ty vec_ty = type_of( CONSpat( ((Pat_VECTORpat *)pat)->cons));
        Ty range_ty = mkvar();
        if (((Pat_VECTORpat *)pat)->len != NOpat)
           unify( pat, integer_ty, type_of( ((Pat_VECTORpat *)pat)->len));
        if (((Pat_VECTORpat *)pat)->array != NOpat)
           unify( pat, mkptrty( arg_ty), type_of( ((Pat_VECTORpat *)pat)->array));
        unify( pat, vec_ty, mkfunty( arg_ty, range_ty));
        t = deref( range_ty);
        
#line 917 "type.pcc"
        } break;
      case a_Pat::tag_APPENDpat: {
#line 891 "type.pcc"
        
        Ty t1 = type_of( ((Pat_APPENDpat *)pat)->_1);
        Ty t2 = type_of( ((Pat_APPENDpat *)pat)->_2);
        t = ((Pat_APPENDpat *)pat)->_3 = t1;
        unify( pat, t1, t2);
        
#line 896 "type.pcc"
        } break;
      case a_Pat::tag_GUARDpat: {
#line 884 "type.pcc"
       t = type_of( ((Pat_GUARDpat *)pat)->_1); 
#line 884 "type.pcc"
        } break;
      case a_Pat::tag_LOGICALpat: {
        switch (((Pat_LOGICALpat *)pat)->_1) {
          case NOTpat: {
#line 918 "type.pcc"
           t = type_of( ((Pat_LOGICALpat *)pat)->_2); 
#line 918 "type.pcc"
            } break;
          default: {
#line 920 "type.pcc"
            
            Ty ty1 = type_of( ((Pat_LOGICALpat *)pat)->_2);
            Ty ty2 = type_of( ((Pat_LOGICALpat *)pat)->_3);
            unify( pat, ty1, ty2);
            t = ty1;
            
#line 925 "type.pcc"
            } break;
        }
        } break;
      case a_Pat::tag_UNIFYpat: {
#line 879 "type.pcc"
       t = type_of( ((Pat_UNIFYpat *)pat)->_1); 
#line 879 "type.pcc"
        } break;
      case a_Pat::tag_MARKEDpat: {
#line 931 "type.pcc"
       t = type_of( ((Pat_MARKEDpat *)pat)->_2); 
#line 931 "type.pcc"
        } break;
      default: {
#line 949 "type.pcc"
       bug( "type_of(Pat)"); 
#line 949 "type.pcc"
        } break;
    }
  } else {
#line 856 "type.pcc"
   t = NOty; 
#line 856 "type.pcc"
  }
}
#line 950 "type.pcc"
#line 950 "type.pcc"

  if ( boxed( pat)) pat->ty = t;
  return t;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a pattern list.
//
/////////////////////////////////////////////////////////////////////////////

Tys type_of( Pats ps)
{
  
#line 963 "type.pcc"
#line 966 "type.pcc"
{
  if (ps) {
#line 966 "type.pcc"
   return 
#line 966 "type.pcc"
#line 966 "type.pcc"
    list_1_(type_of(ps->_1),type_of(ps->_2))
#line 966 "type.pcc"
#line 966 "type.pcc"
    ; 
#line 966 "type.pcc"
  } else {
#line 965 "type.pcc"
   return 
#line 965 "type.pcc"
#line 965 "type.pcc"
    nil_1_
#line 965 "type.pcc"
#line 965 "type.pcc"
    ; 
#line 965 "type.pcc"
  }
}
#line 967 "type.pcc"
#line 967 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a labeled pattern list.
//
/////////////////////////////////////////////////////////////////////////////

Tys type_of( LabPats ps)
{
  
#line 978 "type.pcc"
#line 981 "type.pcc"
{
  if (ps) {
#line 981 "type.pcc"
   return 
#line 981 "type.pcc"
#line 981 "type.pcc"
    list_1_(type_of(ps->_1.pat),type_of(ps->_2))
#line 981 "type.pcc"
#line 981 "type.pcc"
    ; 
#line 981 "type.pcc"
  } else {
#line 980 "type.pcc"
   return 
#line 980 "type.pcc"
#line 980 "type.pcc"
    nil_1_
#line 980 "type.pcc"
#line 980 "type.pcc"
    ; 
#line 980 "type.pcc"
  }
}
#line 982 "type.pcc"
#line 982 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Get the list of labels from a labeled pattern list.
//
/////////////////////////////////////////////////////////////////////////////

Ids labels_of( LabPats ps)
{
  
#line 993 "type.pcc"
#line 996 "type.pcc"
{
  if (ps) {
#line 996 "type.pcc"
   return 
#line 996 "type.pcc"
#line 996 "type.pcc"
    list_1_(ps->_1.label,labels_of(ps->_2))
#line 996 "type.pcc"
#line 996 "type.pcc"
    ; 
#line 996 "type.pcc"
  } else {
#line 995 "type.pcc"
   return 
#line 995 "type.pcc"
#line 995 "type.pcc"
    nil_1_
#line 995 "type.pcc"
#line 995 "type.pcc"
    ; 
#line 995 "type.pcc"
  }
}
#line 997 "type.pcc"
#line 997 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a set of pattern rules.
//
/////////////////////////////////////////////////////////////////////////////

Ty type_match_rules( MatchRules rules)
{
  Bool ok = true;
  MEM::use_global_pools();
  Ty ty = mkvar();
  for_each( MatchRule, r, rules)
  {
    
#line 1013 "type.pcc"
#line 1027 "type.pcc"
{
#line 1016 "type.pcc"
  
  r->set_loc();
  Ty this_ty = type_of(r->_2);
  if (this_ty == NOty)
  {
    error ("%!type error in pattern %p: %T\n",
            r->loc(), r->_2, this_ty);
    ok = false;
  }
  else if ( !unify( r->_2, ty, this_ty))
    ok = false;
  
#line 1027 "type.pcc"
}
#line 1028 "type.pcc"
#line 1028 "type.pcc"

  }
  MEM::use_local_pools();
  return ok ? ty : NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  The type and constructor environments (both are flat for now.)
//
/////////////////////////////////////////////////////////////////////////////

HashTable ty_env( string_hash, string_equal, 91);
HashTable cons_env( string_hash, string_equal, 129);
HashTable token_env( string_hash, string_equal, 129);

/////////////////////////////////////////////////////////////////////////////
//
//  Lookup the type from its name.
//
/////////////////////////////////////////////////////////////////////////////

Ty lookup_ty( Id id)
{
  HashTable::Entry * i = ty_env.lookup( id);
  return i ? inst( value_of( Ty, ty_env, i)) : NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Lookup the constructor from its name.
//
/////////////////////////////////////////////////////////////////////////////

Cons lookup_cons( Id id)
{
  Cons c = find_cons(id);
  if (c == NOcons)
  {
    error( "%Lconstructor '%s' is undefined\n", id);
  }
  return c;
}

Cons lookup_token (Id id)
{
  Cons c = NOcons;
  HashTable::Entry * i = token_env.lookup(id);
  if (i) return (Cons)i->v;
  c = find_cons(id);
  if (c == NOcons)
  {
    if (id[0] == '"')
      error( "%Llexeme %s is undefined\n", id);
    else
      error( "%Lconstructor '%s' is undefined\n", id);
  }
  return c;
}

Cons find_cons(Id id)
{
  HashTable::Entry * i = cons_env.lookup(id);
  return i ? value_of( Cons, cons_env, i) : NOcons;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Add a new type to the environment.
//
/////////////////////////////////////////////////////////////////////////////

void add_type( Id id, TyVars tyvars, Ty ty)
{
  HashTable::Entry * i = ty_env.lookup( id);

  if ( i)
  {
    error( "%Ltype %s has already been defined as %T\n",
          id, value_of(Ty,ty_env,i));
  }
  else
  {
    
#line 1111 "type.pcc"
#line 1117 "type.pcc"
{
  Ty _V21 = deref_all(ty);
  if (_V21) {
    switch (_V21->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V21)->_1)) {
          switch (((Ty_TYCONty *)_V21)->_1->tag__) {
            case a_TyCon::tag_IDtycon: {
              if (
#line 1113 "type.pcc"
              (((TyCon_IDtycon *)((Ty_TYCONty *)_V21)->_1)->IDtycon == id)
#line 1113 "type.pcc"
) {
                
#line 1114 "type.pcc"
                
                error( "%Lcyclic type definition in type %s%V = %T\n",id,tyvars,ty);
                
#line 1116 "type.pcc"
              } else {
                
                L56:; 
#line 1117 "type.pcc"
               ty_env.insert(id,mkpolyty(ty,tyvars)); 
#line 1117 "type.pcc"
              }
              } break;
            default: { goto L56; } break;
          }
        } else { goto L56; }
        } break;
      default: { goto L56; } break;
    }
  } else { goto L56; }
}
#line 1118 "type.pcc"
#line 1118 "type.pcc"

  }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to add a new datatype to the environment.
//
/////////////////////////////////////////////////////////////////////////////

void add_datatype
      (
        const Loc *     location,
        Id              id,
        TyVars          tyvars,
        Inherits        inherit,
        TyQual          qual,
        Exp             view_match,
        TermDefs        terms,
        Decls           body
      )
{
  HashTable::Entry * i = ty_env.lookup(id);
  if (i)
  {
    Ty ty = (Ty)ty_env.value(i);
    
#line 1144 "type.pcc"
#line 1153 "type.pcc"
{
  Ty _V22 = deref_all(ty);
  if (_V22) {
    switch (_V22->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V22)->_1)) {
          switch (((Ty_TYCONty *)_V22)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
#line 1147 "type.pcc"
              
              error( "%Lredefinition of datatype %s\n"
                     "%!this is where datatype %s was previously defined\n",
                     id, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V22)->_1)->location, id);
              
#line 1151 "type.pcc"
              } break;
            default: {
              L57:; 
#line 1153 "type.pcc"
             error( "%Lredefinition of datatype %s\n", id); 
#line 1153 "type.pcc"
              } break;
          }
        } else { goto L57; }
        } break;
      default: { goto L57; } break;
    }
  } else { goto L57; }
}
#line 1154 "type.pcc"
#line 1154 "type.pcc"

  }
  else
  {
    TyCon  tycon      = 
#line 1158 "type.pcc"
#line 1158 "type.pcc"
DATATYPEtycon(id, 0, 0, 0, tyvars, NOty, inherit, qual, 0, body, view_match, location, 0)
#line 1172 "type.pcc"
#line 1172 "type.pcc"
;
    Ty    this_ty       = TYCONty(tycon, tyvars_to_type_list(0,tyvars));
    int   variants      = length(terms);
    int   arg_count     = 0;
    int   unit_count    = 0;
    Cons *all_conses    = (Cons *)mem_pool[variants * sizeof(Cons)];
    int   units         = 0;
    int   args          = 0;
    int   optimizations = 0;
    int   arity         = length(tyvars);
    Id   *bound_vars    = (Id *)mem_pool[arity * sizeof(Id)];
    {
      int i = 0;
      for_each (TyVar, tv, tyvars)
        bound_vars[i++] = tv;
    }

    {
      for_each(TermDef, t, terms)
        
#line 1191 "type.pcc"
#line 1194 "type.pcc"
{
  if (t->ty) {
#line 1194 "type.pcc"
   args++; 
#line 1194 "type.pcc"
  } else {
#line 1193 "type.pcc"
   units++; 
#line 1193 "type.pcc"
  }
}
#line 1195 "type.pcc"
#line 1195 "type.pcc"

    }

    Ty poly = mkpolyty( this_ty, tyvars);

    // compute optimizations.
    if (args == 1)
      optimizations |= OPTsubclassless | OPTtagless;
    if (args > 1 && args <= options.max_embedded_tags
        && (qual & QUALvirtual) == 0
        && (options.tagged_pointer || (qual & QUALtaggedpointer)))
      optimizations |= OPTtaggedpointer | OPTtagless;
    else if (args <= 1)
      optimizations |= OPTtagless;

    int actual_boxed = 0;
    for_each(TermDef, t, terms)
    {
      
#line 1213 "type.pcc"
#line 1299 "type.pcc"
{
  if (
#line 1215 "type.pcc"
  (t->id == 0)
#line 1215 "type.pcc"
) {
    
#line 1216 "type.pcc"
  qual |= QUALextensible; 
#line 1216 "type.pcc"
  } else {
    
#line 1221 "type.pcc"
    
    int tag;
    Pat lexeme_pat =
       (qual & QUALlexeme) && t->id[0] == '"'
        ? LITERALpat(STRINGlit(t->id)) : t->pat;
    Cons last_cons = find_cons(t->id);
    if (last_cons != NOcons)
    {
      error ("%!redefinition of constructor '%s'\n"
              "%!this is where '%s' was last defined.\n",
              t->loc(), t->id, last_cons->location, t->id);
    }
    if (t->ty == NOty)
      tag = unit_count++;
    else
      tag = arg_count++;
    
    if (t->print_formats != 
#line 1238 "type.pcc"
#line 1238 "type.pcc"
    nil_1_
#line 1238 "type.pcc"
#line 1238 "type.pcc"
    )
    qual |= QUALprintable;
    
    Ty cons_ty = t->ty == NOty
      ? poly
      : POLYty(mkfunty(t->ty, this_ty), arity, bound_vars);
    
    // Use unboxed optimization
    // only if we are also using the tagged pointer rep.
    // Make sure (1) the type is embeddable into 1 word.
    //           (2) We are monomorphic.
    //           (3) We are not using any inheritance.
    
    int this_opt = OPTnone;
    
    if ((optimizations & OPTtaggedpointer) &&
      tyvars == 
#line 1254 "type.pcc"
#line 1254 "type.pcc"
    nil_1_
#line 1254 "type.pcc"
#line 1254 "type.pcc"
                  &&
    t->inherits == 
#line 1255 "type.pcc"
#line 1255 "type.pcc"
    nil_1_
#line 1255 "type.pcc"
#line 1255 "type.pcc"
          &&
    t->opt == OPTunboxed               &&
    (qual & (QUALrewritable | QUALcollectable |
              QUALrelation | QUALpersistent))
        == 0 &&
     is_embeddable_ty(t->ty))
    this_opt = OPTunboxed;
    
    Exp * view_selectors =
    (qual & QUALview) ?
      (Exp*)mem_pool.c_alloc(arity_of(t->ty) * sizeof(Exp)) : 0;
    
    Cons cons = 
#line 1267 "type.pcc"
#line 1267 "type.pcc"
    ONEcons(t->id, this_ty, cons_ty, t->ty, tag, t->print_formats, t->loc(), t->inherits, t->decls, this_opt, t->qual, t->view_predicate, view_selectors, lexeme_pat, 0)
#line 1283 "type.pcc"
#line 1283 "type.pcc"
    ;
    
              all_conses[t->ty == NOty ? tag : tag + units] = cons;
    
              if (t->ty != NOty && (this_opt & OPTunboxed) == 0)
                 actual_boxed++;
    
              // update the constructor environment
              cons_env.insert(t->id, cons);
    
              // update the token environment
              
#line 1294 "type.pcc"
#line 1298 "type.pcc"
    {
      if (lexeme_pat) {
        switch (lexeme_pat->tag__) {
          case a_Pat::tag_LITERALpat: {
            switch (((Pat_LITERALpat *)lexeme_pat)->LITERALpat->tag__) {
              case a_Literal::tag_STRINGlit: {
#line 1296 "type.pcc"
               token_env.insert(((Literal_STRINGlit *)((Pat_LITERALpat *)lexeme_pat)->LITERALpat)->STRINGlit, cons); 
#line 1296 "type.pcc"
                } break;
              default: {
                L58:; } break;
            }
            } break;
          default: { goto L58; } break;
        }
      } else { goto L58; }
    }
#line 1298 "type.pcc"
#line 1298 "type.pcc"
    
    
#line 1299 "type.pcc"
  }
}
#line 1300 "type.pcc"
#line 1300 "type.pcc"

    }

    if (actual_boxed <= 1) optimizations |= OPTsubclassless | OPTtagless;

    if (tyvars && unit_count > 1)
       error("%Lmultiple unit constructors in polymorphic type %s%V"
	       " is not supported\n",
             id, tyvars);

    
#line 1310 "type.pcc"
#line 1317 "type.pcc"
{
  if (boxed(tycon)) {
    switch (tycon->tag__) {
      case a_TyCon::tag_DATATYPEtycon: {
#line 1313 "type.pcc"
        
        ((TyCon_DATATYPEtycon *)tycon)->unit = unit_count; ((TyCon_DATATYPEtycon *)tycon)->arg = arg_count; ((TyCon_DATATYPEtycon *)tycon)->terms = all_conses;
        ((TyCon_DATATYPEtycon *)tycon)->polyty = poly; ((TyCon_DATATYPEtycon *)tycon)->opt = optimizations; ((TyCon_DATATYPEtycon *)tycon)->qualifiers = qual;
        
#line 1316 "type.pcc"
        } break;
      default: {
        L59:; } break;
    }
  } else { goto L59; }
}
#line 1318 "type.pcc"
#line 1318 "type.pcc"


    ty_env.insert( id, poly);
    if (qual & QUALlexeme)
      update_lexeme_class( id, terms);

    // Create new type hierarchy
    new DatatypeHierarchy( id, tyvars, inherit, qual, terms, body);
  }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to refine the implementation of a datatype.
//
/////////////////////////////////////////////////////////////////////////////

void update_datatype( Id id, TyVars tyvars, Inherits superclasses,
                      TyQual qual, Decls decls)
{
  
#line 1338 "type.pcc"
#line 1351 "type.pcc"
{
  Ty _V23 = lookup_ty(id);
  if (_V23) {
    switch (_V23->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V23)->_1)) {
          switch (((Ty_TYCONty *)_V23)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
              if (
#line 1340 "type.pcc"
              (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy != 0)
#line 1340 "type.pcc"
) {
                
#line 1341 "type.pcc"
                
                if (superclasses)
                	    ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->inherited_classes =
                	      append( ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->inherited_classes, superclasses);
                ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->qualifiers |= qual;
                ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->qualifiers |= qual;
                	  if (decls)
                  ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->class_body = append( ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->class_body, decls);
                
#line 1349 "type.pcc"
              } else {
                
                L60:; 
#line 1351 "type.pcc"
               error ("%Ltype %s = %T is not a datatype\n",id, _V23); 
#line 1351 "type.pcc"
              }
              } break;
            default: { goto L60; } break;
          }
        } else { goto L60; }
        } break;
      default: { goto L60; } break;
    }
  } else {
#line 1350 "type.pcc"
   /* skip */ 
#line 1350 "type.pcc"
  }
}
#line 1352 "type.pcc"
#line 1352 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to refine the implementation of a datatype constructor.
//
/////////////////////////////////////////////////////////////////////////////

void update_constructor
   (Id id, Tys ty_args, Inherits inh, PrintFormats pf, Decls decls)
{
  
#line 1364 "type.pcc"
#line 1386 "type.pcc"
{
  Cons _V24 = lookup_cons(id);
  if (_V24) {
    if (_V24->alg_ty) {
      switch (_V24->alg_ty->tag__) {
        case a_Ty::tag_TYCONty: {
          if (boxed(((Ty_TYCONty *)_V24->alg_ty)->_1)) {
            switch (((Ty_TYCONty *)_V24->alg_ty)->_1->tag__) {
              case a_TyCon::tag_DATATYPEtycon: {
#line 1372 "type.pcc"
                
                if (pf)
                {
                  if (_V24->print_formats)
                    error("%Lconstructor %s already has print formats\n",id);
                  else
                    _V24->print_formats = pf;
                  ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V24->alg_ty)->_1)->qualifiers |= QUALprintable;
                }
                	  if (decls)
                  _V24->class_def->class_body = append( _V24->class_def->class_body, decls);
                	  if (inh)
                	    _V24->class_def->inherited_classes = append( _V24->class_def->inherited_classes, inh);
                
#line 1385 "type.pcc"
                } break;
              default: {
                L61:; 
#line 1386 "type.pcc"
               /* skip */ 
#line 1386 "type.pcc"
                } break;
            }
          } else { goto L61; }
          } break;
        default: { goto L61; } break;
      }
    } else { goto L61; }
  } else { goto L61; }
}
#line 1387 "type.pcc"
#line 1387 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on types
//
/////////////////////////////////////////////////////////////////////////////

unsigned int ty_hash( HashTable::Key k)
{
  Ty ty = (Ty)k;
  
#line 1399 "type.pcc"
#line 1427 "type.pcc"
{
  Ty _V25 = deref_all(ty);
  if (_V25) {
    switch (_V25->tag__) {
      case a_Ty::tag_VARty: {
#line 1402 "type.pcc"
       return (unsigned int)_V25; 
#line 1402 "type.pcc"
        } break;
      case a_Ty::tag_TYCONty: {
#line 1404 "type.pcc"
        
        unsigned int h;
        
#line 1406 "type.pcc"
#line 1422 "type.pcc"
        {
          TyCon _V26 = ((Ty_TYCONty *)_V25)->_1;
          if (boxed(_V26)) {
            switch (_V26->tag__) {
              case a_TyCon::tag_IDtycon: {
#line 1415 "type.pcc"
               h = string_hash(((TyCon_IDtycon *)_V26)->IDtycon) + 89; 
#line 1415 "type.pcc"
                } break;
              case a_TyCon::tag_RECORDtycon: {
#line 1411 "type.pcc"
               h = 129; 
#line 1411 "type.pcc"
                } break;
              case a_TyCon::tag_ARRAYtycon: {
#line 1414 "type.pcc"
               h = 569; 
#line 1414 "type.pcc"
                } break;
              case a_TyCon::tag_BITFIELDtycon: {
#line 1417 "type.pcc"
               h = 733 + ((TyCon_BITFIELDtycon *)_V26)->width; 
#line 1417 "type.pcc"
                } break;
              case a_TyCon::tag_DATATYPEtycon: {
#line 1416 "type.pcc"
               h = string_hash(((TyCon_DATATYPEtycon *)_V26)->id) + 431; 
#line 1416 "type.pcc"
                } break;
              case a_TyCon::tag_COLtycon: {
#line 1419 "type.pcc"
               h = string_hash(((TyCon_COLtycon *)_V26)->COLtycon->name) + 1345; 
#line 1419 "type.pcc"
                } break;
              case a_TyCon::tag_GRAPHtycon: {
#line 1420 "type.pcc"
               h = (int)((TyCon_GRAPHtycon *)_V26)->GRAPHtycon; 
#line 1420 "type.pcc"
                } break;
              case a_TyCon::tag_NODEtycon: {
#line 1421 "type.pcc"
               h = (int)((TyCon_NODEtycon *)_V26)->NODEtycon; 
#line 1421 "type.pcc"
                } break;
              default: {
#line 1422 "type.pcc"
               h = (int)((TyCon_EDGEtycon *)_V26)->EDGEtycon; 
#line 1422 "type.pcc"
                } break;
            }
          } else {
            switch ((int)_V26) {
              case ((int)v_POINTERtycon): {
#line 1408 "type.pcc"
               h = 37; 
#line 1408 "type.pcc"
                } break;
              case ((int)v_REFtycon): {
#line 1409 "type.pcc"
               h = 47; 
#line 1409 "type.pcc"
                } break;
              case ((int)v_TUPLEtycon): {
#line 1412 "type.pcc"
               h = 173; 
#line 1412 "type.pcc"
                } break;
              case ((int)v_EXTUPLEtycon): {
#line 1413 "type.pcc"
               h = 467; 
#line 1413 "type.pcc"
                } break;
              case ((int)v_FUNtycon): {
#line 1410 "type.pcc"
               h = 79; 
#line 1410 "type.pcc"
                } break;
              default: {
#line 1418 "type.pcc"
               h = 1235; 
#line 1418 "type.pcc"
                } break;
            }
          }
        }
#line 1423 "type.pcc"
#line 1423 "type.pcc"
        
        return h + tys_hash(((Ty_TYCONty *)_V25)->_2);
        
#line 1425 "type.pcc"
        } break;
      case a_Ty::tag_NESTEDty: {
#line 1426 "type.pcc"
       return ty_hash( ((Ty_NESTEDty *)_V25)->_1) + ty_hash( ((Ty_NESTEDty *)_V25)->_2); 
#line 1426 "type.pcc"
        } break;
      default: {
#line 1427 "type.pcc"
       return 0; 
#line 1427 "type.pcc"
        } break;
    }
  } else {
#line 1401 "type.pcc"
   return 0; 
#line 1401 "type.pcc"
  }
}
#line 1428 "type.pcc"
#line 1428 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on type list
//
/////////////////////////////////////////////////////////////////////////////

unsigned int tys_hash( HashTable::Key k)
{
  Tys tys = (Tys)k;
  unsigned int h = 0;
  for_each (Ty, t, tys)
    h += ty_hash(t);
  return h;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality function on types
//
/////////////////////////////////////////////////////////////////////////////

Bool ty_equal( HashTable::Key a, HashTable::Key b)
{
  Ty u = (Ty) a, v = (Ty) b;

  
#line 1456 "type.pcc"
#line 1492 "type.pcc"
{
  Ty _V27 = deref_all(u);
  Ty _V28 = deref_all(v);
  if (
#line 1458 "type.pcc"
  (_V27 == _V28)
#line 1458 "type.pcc"
) {
    
#line 1458 "type.pcc"
   return true; 
#line 1458 "type.pcc"
  } else {
    
    if (_V27) {
      switch (_V27->tag__) {
        case a_Ty::tag_VARty: {
          if (_V28) {
            switch (_V28->tag__) {
              case a_Ty::tag_VARty: {
#line 1459 "type.pcc"
               return _V27 == _V28; 
#line 1459 "type.pcc"
                } break;
              default: {
                L62:; 
#line 1492 "type.pcc"
               return false; 
#line 1492 "type.pcc"
                } break;
            }
          } else { goto L62; }
          } break;
        case a_Ty::tag_TYCONty: {
          if (_V28) {
            switch (_V28->tag__) {
              case a_Ty::tag_TYCONty: {
                if (boxed(((Ty_TYCONty *)_V27)->_1)) {
                  switch (((Ty_TYCONty *)_V27)->_1->tag__) {
                    case a_TyCon::tag_RECORDtycon: {
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_RECORDtycon: {
                                  L63:; 
#line 1464 "type.pcc"
                                  
                                  Ids i, j; Tys t, u;
                                  if (length(((Ty_TYCONty *)_V27)->_2) != length(((Ty_TYCONty *)_V28)->_2)) return false;
                                  for (i = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V27)->_1)->_1, t = ((Ty_TYCONty *)_V27)->_2; i; i = i->_2, t = t->_2)
                                  {
                                    Bool found = false;
                                    for (j = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V28)->_1)->_1, u = ((Ty_TYCONty *)_V28)->_2; j; j = j->_2, u = u->_2)
                                    {
                                      if (i->_1 == j->_1)
                                      {
                                        if ( !ty_equal(t->_1, u->_2))
                                          return false;
                                        found = true;
                                        break;
                                      }
                                    }
                                    if ( !found) return false;
                                  }
                                  return true;
                                  
#line 1483 "type.pcc"
                                  } break;
                                default: {
                                  L64:; 
#line 1485 "type.pcc"
                                  
                                  if (! unify(((Ty_TYCONty *)_V27)->_1,((Ty_TYCONty *)_V28)->_1))
                                    return false;
                                  return tys_equal(((Ty_TYCONty *)_V27)->_2,((Ty_TYCONty *)_V28)->_2);
                                  
#line 1489 "type.pcc"
                                  } break;
                              }
                            } else { goto L64; }
                            } break;
                          default: { goto L64; } break;
                        }
                      } else { goto L64; }
                      } break;
                    case a_TyCon::tag_GRAPHtycon: {
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_GRAPHtycon: {
                                  L65:; 
#line 1460 "type.pcc"
                                 return ((TyCon_GRAPHtycon *)((Ty_TYCONty *)_V27)->_1)->GRAPHtycon == ((TyCon_GRAPHtycon *)((Ty_TYCONty *)_V28)->_1)->GRAPHtycon; 
#line 1460 "type.pcc"
                                  } break;
                                default: { goto L64; } break;
                              }
                            } else { goto L64; }
                            } break;
                          default: { goto L64; } break;
                        }
                      } else { goto L64; }
                      } break;
                    case a_TyCon::tag_NODEtycon: {
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_NODEtycon: {
                                  L66:; 
#line 1461 "type.pcc"
                                 return ((TyCon_NODEtycon *)((Ty_TYCONty *)_V27)->_1)->NODEtycon == ((TyCon_NODEtycon *)((Ty_TYCONty *)_V28)->_1)->NODEtycon; 
#line 1461 "type.pcc"
                                  } break;
                                default: { goto L64; } break;
                              }
                            } else { goto L64; }
                            } break;
                          default: { goto L64; } break;
                        }
                      } else { goto L64; }
                      } break;
                    case a_TyCon::tag_EDGEtycon: {
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_EDGEtycon: {
                                  L67:; 
#line 1462 "type.pcc"
                                 return ((TyCon_EDGEtycon *)((Ty_TYCONty *)_V27)->_1)->EDGEtycon == ((TyCon_EDGEtycon *)((Ty_TYCONty *)_V28)->_1)->EDGEtycon; 
#line 1462 "type.pcc"
                                  } break;
                                default: { goto L64; } break;
                              }
                            } else { goto L64; }
                            } break;
                          default: { goto L64; } break;
                        }
                      } else { goto L64; }
                      } break;
                    default: { goto L64; } break;
                  }
                } else { goto L64; }
                } break;
              default: {
                L68:; 
                if (boxed(((Ty_TYCONty *)_V27)->_1)) {
                  switch (((Ty_TYCONty *)_V27)->_1->tag__) {
                    case a_TyCon::tag_RECORDtycon: {
                      L69:; 
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            L70:; 
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_RECORDtycon: { goto L63; } break;
                                default: { goto L62; } break;
                              }
                            } else { goto L62; }
                            } break;
                          default: { goto L62; } break;
                        }
                      } else { goto L62; }
                      } break;
                    case a_TyCon::tag_GRAPHtycon: {
                      L71:; 
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            L72:; 
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_GRAPHtycon: { goto L65; } break;
                                default: { goto L62; } break;
                              }
                            } else { goto L62; }
                            } break;
                          default: { goto L62; } break;
                        }
                      } else { goto L62; }
                      } break;
                    case a_TyCon::tag_NODEtycon: {
                      L73:; 
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            L74:; 
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_NODEtycon: { goto L66; } break;
                                default: { goto L62; } break;
                              }
                            } else { goto L62; }
                            } break;
                          default: { goto L62; } break;
                        }
                      } else { goto L62; }
                      } break;
                    case a_TyCon::tag_EDGEtycon: {
                      L75:; 
                      if (_V28) {
                        switch (_V28->tag__) {
                          case a_Ty::tag_TYCONty: {
                            L76:; 
                            if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                              switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                case a_TyCon::tag_EDGEtycon: { goto L67; } break;
                                default: { goto L62; } break;
                              }
                            } else { goto L62; }
                            } break;
                          default: { goto L62; } break;
                        }
                      } else { goto L62; }
                      } break;
                    default: { goto L62; } break;
                  }
                } else { goto L62; }
                } break;
            }
          } else { goto L68; }
          } break;
        case a_Ty::tag_NESTEDty: {
          if (_V28) {
            switch (_V28->tag__) {
              case a_Ty::tag_NESTEDty: {
#line 1491 "type.pcc"
               return ty_equal(((Ty_NESTEDty *)_V27)->_1,((Ty_NESTEDty *)_V28)->_1) && ty_equal(((Ty_NESTEDty *)_V27)->_2,((Ty_NESTEDty *)_V28)->_2); 
#line 1491 "type.pcc"
                } break;
              default: { goto L62; } break;
            }
          } else { goto L62; }
          } break;
        default: { goto L62; } break;
      }
    } else { goto L62; }
  }
}
#line 1493 "type.pcc"
#line 1493 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality function on type lists
//
/////////////////////////////////////////////////////////////////////////////

Bool tys_equal( HashTable::Key a, HashTable::Key b)
{
  Tys u = (Tys)a, v = (Tys)b;
  
#line 1505 "type.pcc"
#line 1512 "type.pcc"
{
  for (;;) {
    if (u) {
      if (v) {
#line 1508 "type.pcc"
        
        if ( !ty_equal(u->_1,v->_1))
          return false;
        u = u->_2; v = v->_2;
        
#line 1512 "type.pcc"
      } else { goto L77; }
    } else { goto L77; }
  }
  L77:;
}
#line 1513 "type.pcc"
#line 1513 "type.pcc"

  return u == 
#line 1514 "type.pcc"
#line 1514 "type.pcc"
nil_1_
#line 1514 "type.pcc"
#line 1514 "type.pcc"
 && v == 
#line 1514 "type.pcc"
#line 1514 "type.pcc"
nil_1_
#line 1514 "type.pcc"
#line 1514 "type.pcc"
;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality on qualified identifiers.
//
/////////////////////////////////////////////////////////////////////////////

#line 1523 "type.pcc"
#line 1529 "type.pcc"
Bool qualid_equal (QualId x_1, QualId x_2);
Bool qualid_equal (QualId x_1, QualId x_2)
{
  if (untagp(x_1)) {
    
    if (untagp(x_2)) {
      
#line 1524 "type.pcc"
     return ((QualId_SIMPLEid *)derefp(x_1))->SIMPLEid == ((QualId_SIMPLEid *)derefp(x_2))->SIMPLEid; 
#line 1524 "type.pcc"
    } else {
      
      L78:; 
#line 1528 "type.pcc"
     return false; 
#line 1528 "type.pcc"
    }
  } else {
    
    if (untagp(x_2)) {
       goto L78; } else {
      
#line 1526 "type.pcc"
     return ty_equal(((QualId_NESTEDid *)x_1)->_1,((QualId_NESTEDid *)x_2)->_1) && qualid_equal(((QualId_NESTEDid *)x_1)->_2,((QualId_NESTEDid *)x_2)->_2); 
#line 1526 "type.pcc"
    }
  }
}
#line 1529 "type.pcc"
#line 1529 "type.pcc"

#line 1530 "type.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2865
Number of ifs generated      = 162
Number of switches generated = 116
Number of labels             = 71
Number of gotos              = 198
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
