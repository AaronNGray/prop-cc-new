///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "timespace.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "timespace.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the time and space complexity
//  datatypes.  These datatypes are used to represent time and space
//  complexity in the SETL-like extension language.
//
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>
#include "basics.h"
#include "timespace.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the time and space datatypes
//
///////////////////////////////////////////////////////////////////////////////

#line 21 "timespace.pcc"
#line 21 "timespace.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Complexity
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Time
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Space
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Complexity
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"
Complexity_Var::Complexity_Var (Id x_Var)
 : a_Complexity(tag_Var), Var(x_Var)
{
}
a_Complexity * Var (Id x_Var)
{
  return new Complexity_Var (x_Var);
}
Complexity_Add::Complexity_Add (Complexity x_1, Complexity x_2)
 : a_Complexity(tag_Add), _1(x_1), _2(x_2)
{
}
a_Complexity * Add (Complexity x_1, Complexity x_2)
{
  return new Complexity_Add (x_1, x_2);
}
Complexity_Mul::Complexity_Mul (Complexity x_1, Complexity x_2)
 : a_Complexity(tag_Mul), _1(x_1), _2(x_2)
{
}
a_Complexity * Mul (Complexity x_1, Complexity x_2)
{
  return new Complexity_Mul (x_1, x_2);
}
Complexity_Div::Complexity_Div (Complexity x_1, Complexity x_2)
 : a_Complexity(tag_Div), _1(x_1), _2(x_2)
{
}
a_Complexity * Div (Complexity x_1, Complexity x_2)
{
  return new Complexity_Div (x_1, x_2);
}
Complexity_Power::Complexity_Power (Complexity x_1, Complexity x_2)
 : a_Complexity(tag_Power), _1(x_1), _2(x_2)
{
}
a_Complexity * Power (Complexity x_1, Complexity x_2)
{
  return new Complexity_Power (x_1, x_2);
}
Complexity_Log::Complexity_Log (Complexity x_Log)
 : a_Complexity(tag_Log), Log(x_Log)
{
}
a_Complexity * Log (Complexity x_Log)
{
  return new Complexity_Log (x_Log);
}
Complexity_Const::Complexity_Const (double x_Const)
 : a_Complexity(tag_Const), Const(x_Const)
{
}
a_Complexity * Const (double x_Const)
{
  return new Complexity_Const (x_Const);
}
Complexity_BigOh::Complexity_BigOh (Complexity x_BigOh)
 : a_Complexity(tag_BigOh), BigOh(x_BigOh)
{
}
a_Complexity * BigOh (Complexity x_BigOh)
{
  return new Complexity_BigOh (x_BigOh);
}
Complexity_Omega::Complexity_Omega (Complexity x_Omega)
 : a_Complexity(tag_Omega), Omega(x_Omega)
{
}
a_Complexity * Omega (Complexity x_Omega)
{
  return new Complexity_Omega (x_Omega);
}
Complexity_LittleOh::Complexity_LittleOh (Complexity x_LittleOh)
 : a_Complexity(tag_LittleOh), LittleOh(x_LittleOh)
{
}
a_Complexity * LittleOh (Complexity x_LittleOh)
{
  return new Complexity_LittleOh (x_LittleOh);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Time
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"
a_Time::a_Time (Complexity x_TIME)
 : TIME(x_TIME)
{
}
a_Time * TIME (Complexity x_TIME)
{
  return new a_Time (x_TIME);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Space
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "timespace.pcc"
a_Space::a_Space (Complexity x_SPACE)
 : SPACE(x_SPACE)
{
}
a_Space * SPACE (Complexity x_SPACE)
{
  return new a_Space (x_SPACE);
}


#line 21 "timespace.pcc"
#line 21 "timespace.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print the complexity
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Complexity c)
{
  
#line 31 "timespace.pcc"
#line 42 "timespace.pcc"
{
  switch (c->tag__) {
    case a_Complexity::tag_Var: {
#line 33 "timespace.pcc"
     f << ((Complexity_Var *)c)->Var; 
#line 33 "timespace.pcc"
      } break;
    case a_Complexity::tag_Add: {
#line 34 "timespace.pcc"
     f << '(' << ((Complexity_Add *)c)->_1 << " + " << ((Complexity_Add *)c)->_2 << ')'; 
#line 34 "timespace.pcc"
      } break;
    case a_Complexity::tag_Mul: {
#line 35 "timespace.pcc"
     f << '(' << ((Complexity_Mul *)c)->_1 << " * " << ((Complexity_Mul *)c)->_2 << ')'; 
#line 35 "timespace.pcc"
      } break;
    case a_Complexity::tag_Div: {
#line 36 "timespace.pcc"
     f << '(' << ((Complexity_Div *)c)->_1 << " / " << ((Complexity_Div *)c)->_2 << ')'; 
#line 36 "timespace.pcc"
      } break;
    case a_Complexity::tag_Power: {
#line 37 "timespace.pcc"
     f << '(' << ((Complexity_Power *)c)->_1 << " ^ " << ((Complexity_Power *)c)->_2 << ')'; 
#line 37 "timespace.pcc"
      } break;
    case a_Complexity::tag_Log: {
#line 38 "timespace.pcc"
     f << "log " << ((Complexity_Log *)c)->Log; 
#line 38 "timespace.pcc"
      } break;
    case a_Complexity::tag_Const: {
#line 39 "timespace.pcc"
     f << ((Complexity_Const *)c)->Const; 
#line 39 "timespace.pcc"
      } break;
    case a_Complexity::tag_BigOh: {
#line 40 "timespace.pcc"
     f << "O(" << ((Complexity_BigOh *)c)->BigOh << ')'; 
#line 40 "timespace.pcc"
      } break;
    case a_Complexity::tag_Omega: {
#line 41 "timespace.pcc"
     f << "Omega(" << ((Complexity_Omega *)c)->Omega << ')'; 
#line 41 "timespace.pcc"
      } break;
    default: {
#line 42 "timespace.pcc"
     f << "o(" << ((Complexity_LittleOh *)c)->LittleOh << ')'; 
#line 42 "timespace.pcc"
      } break;
  }
}
#line 43 "timespace.pcc"
#line 43 "timespace.pcc"

  return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print the time complexity
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Time t)
{  return f << "Time(" << t << ")"; }

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty print the space complexity
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& f, Space s)
{  return f << "Space(" << s << ")"; }

///////////////////////////////////////////////////////////////////////////////
//
//  Function to simplify a complexity expression
//
///////////////////////////////////////////////////////////////////////////////

Complexity simplify (Complexity c)
{
  
#line 73 "timespace.pcc"
#line 79 "timespace.pcc"
  extern void  _t_i_m_e_s_p_a_c_eco_X1_rewrite(Complexity & );
  _t_i_m_e_s_p_a_c_eco_X1_rewrite(c);
#line 79 "timespace.pcc"
#line 79 "timespace.pcc"

  return c;
}
#line 82 "timespace.pcc"
class _t_i_m_e_s_p_a_c_eco_X1 : public BURS {
private:
  _t_i_m_e_s_p_a_c_eco_X1(const _t_i_m_e_s_p_a_c_eco_X1&);               // no copy constructor
  void operator = (const _t_i_m_e_s_p_a_c_eco_X1&); // no assignment
public:
  struct _t_i_m_e_s_p_a_c_eco_X1_StateRec * stack__, * stack_top__;
public:
  void labeler(const char *, int&, int);
  void labeler(Quark, int&, int);
         void  labeler(Complexity & redex, int&, int);
  inline virtual void  operator () (Complexity & redex) { int s; labeler(redex,s,0); }
private: 
  public:
    inline _t_i_m_e_s_p_a_c_eco_X1() {}
};
void  _t_i_m_e_s_p_a_c_eco_X1_rewrite(Complexity &  _x_) 
{  _t_i_m_e_s_p_a_c_eco_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__t_i_m_e_s_p_a_c_eco_X1
#define DEBUG__t_i_m_e_s_p_a_c_eco_X1(repl,redex,file,line,rule) repl
#else
static const char * _t_i_m_e_s_p_a_c_eco_X1_file_name = "timespace.pcc";
#endif

static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_theta_1[2][2] = {
   { 0, 0 },
   { 0, 2 }
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_theta_2[2][2] = {
   { 0, 0 },
   { 0, 3 }
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_theta_3[2][2] = {
   { 0, 0 },
   { 0, 4 }
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_theta_4[2][2] = {
   { 0, 0 },
   { 0, 5 }
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_theta_5[2] = {
   0, 6
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_1_0[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_1_1[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_2_0[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_2_1[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_3_0[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_3_1[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_4_0[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_4_1[7] = {
   0, 1, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _t_i_m_e_s_p_a_c_eco_X1_mu_5_0[7] = {
   0, 1, 0, 0, 0, 0, 0
};


inline void  _t_i_m_e_s_p_a_c_eco_X1::labeler(char const * redex,int& s__,int)
{
  {
s__ = 0;
  }
}

inline void  _t_i_m_e_s_p_a_c_eco_X1::labeler(Quark redex,int& s__,int)
{
  {
s__ = 0;
  }
}

void  _t_i_m_e_s_p_a_c_eco_X1::labeler (Complexity & redex, int& s__, int r__)
{
replacement__:
  switch(redex->tag__) {
    case a_Complexity::tag_Var: { 
      int s0__;
      labeler(((Complexity_Var *)redex)->Var, s0__, r__);
      s__ = 0;} break;
    case a_Complexity::tag_Add: { 
      int s0__;
      int s1__;
      labeler(((Complexity_Add *)redex)->_1, s0__, r__);
      labeler(((Complexity_Add *)redex)->_2, s1__, r__);
      s__ = _t_i_m_e_s_p_a_c_eco_X1_theta_1[_t_i_m_e_s_p_a_c_eco_X1_mu_1_0[s0__]][_t_i_m_e_s_p_a_c_eco_X1_mu_1_1[s1__]]; } break;
    case a_Complexity::tag_Mul: { 
      int s0__;
      int s1__;
      labeler(((Complexity_Mul *)redex)->_1, s0__, r__);
      labeler(((Complexity_Mul *)redex)->_2, s1__, r__);
      s__ = _t_i_m_e_s_p_a_c_eco_X1_theta_2[_t_i_m_e_s_p_a_c_eco_X1_mu_2_0[s0__]][_t_i_m_e_s_p_a_c_eco_X1_mu_2_1[s1__]]; } break;
    case a_Complexity::tag_Div: { 
      int s0__;
      int s1__;
      labeler(((Complexity_Div *)redex)->_1, s0__, r__);
      labeler(((Complexity_Div *)redex)->_2, s1__, r__);
      s__ = _t_i_m_e_s_p_a_c_eco_X1_theta_3[_t_i_m_e_s_p_a_c_eco_X1_mu_3_0[s0__]][_t_i_m_e_s_p_a_c_eco_X1_mu_3_1[s1__]]; } break;
    case a_Complexity::tag_Power: { 
      int s0__;
      int s1__;
      labeler(((Complexity_Power *)redex)->_1, s0__, r__);
      labeler(((Complexity_Power *)redex)->_2, s1__, r__);
      s__ = _t_i_m_e_s_p_a_c_eco_X1_theta_4[_t_i_m_e_s_p_a_c_eco_X1_mu_4_0[s0__]][_t_i_m_e_s_p_a_c_eco_X1_mu_4_1[s1__]]; } break;
    case a_Complexity::tag_Log: { 
      int s0__;
      labeler(((Complexity_Log *)redex)->Log, s0__, r__);
      s__ = _t_i_m_e_s_p_a_c_eco_X1_theta_5[_t_i_m_e_s_p_a_c_eco_X1_mu_5_0[s0__]]; } break;
    case a_Complexity::tag_Const: { 
      int s0__;
      s0__ = 0; // double
      s__ = 1;} break;
    case a_Complexity::tag_BigOh: { 
      int s0__;
      labeler(((Complexity_BigOh *)redex)->BigOh, s0__, r__);
      s__ = 0;} break;
    case a_Complexity::tag_Omega: { 
      int s0__;
      labeler(((Complexity_Omega *)redex)->Omega, s0__, r__);
      s__ = 0;} break;
    default: { 
      int s0__;
      labeler(((Complexity_LittleOh *)redex)->LittleOh, s0__, r__);
      s__ = 0;} break;
  }
  switch (s__) {
    case 6: {
#line 78 "timespace.pcc"
      { redex = DEBUG__t_i_m_e_s_p_a_c_eco_X1(Const(std::log(((Complexity_Const *)((Complexity_Log *)redex)->Log)->Const)),redex,_t_i_m_e_s_p_a_c_eco_X1_file_name,78,"Log Const i: ...");
        r__ = 1; goto replacement__; }
#line 79 "timespace.pcc"
} break;
    case 5: {
#line 77 "timespace.pcc"
      { redex = DEBUG__t_i_m_e_s_p_a_c_eco_X1(Const(std::exp((log(((Complexity_Const *)((Complexity_Power *)redex)->_1)->Const) * ((Complexity_Const *)((Complexity_Power *)redex)->_2)->Const))),redex,_t_i_m_e_s_p_a_c_eco_X1_file_name,77,"Power (Const i, Const j): ...");
        r__ = 1; goto replacement__; }
#line 78 "timespace.pcc"
} break;
    case 4: {
#line 76 "timespace.pcc"
      { redex = DEBUG__t_i_m_e_s_p_a_c_eco_X1(Const((((Complexity_Const *)((Complexity_Div *)redex)->_1)->Const / ((Complexity_Const *)((Complexity_Div *)redex)->_2)->Const)),redex,_t_i_m_e_s_p_a_c_eco_X1_file_name,76,"Div (Const i, Const j): ...");
        r__ = 1; goto replacement__; }
#line 77 "timespace.pcc"
} break;
    case 3: {
#line 75 "timespace.pcc"
      { redex = DEBUG__t_i_m_e_s_p_a_c_eco_X1(Const((((Complexity_Const *)((Complexity_Mul *)redex)->_1)->Const * ((Complexity_Const *)((Complexity_Mul *)redex)->_2)->Const)),redex,_t_i_m_e_s_p_a_c_eco_X1_file_name,75,"Mul (Const i, Const j): ...");
        r__ = 1; goto replacement__; }
#line 76 "timespace.pcc"
} break;
    case 2: {
#line 74 "timespace.pcc"
      { redex = DEBUG__t_i_m_e_s_p_a_c_eco_X1(Const((((Complexity_Const *)((Complexity_Add *)redex)->_1)->Const + ((Complexity_Const *)((Complexity_Add *)redex)->_2)->Const)),redex,_t_i_m_e_s_p_a_c_eco_X1_file_name,74,"Add (Const i, Const j): ...");
        r__ = 1; goto replacement__; }
#line 75 "timespace.pcc"
} break;
  }
  
}

/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 1
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
