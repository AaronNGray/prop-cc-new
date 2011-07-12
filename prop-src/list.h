///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "list.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "list.ph"
#ifndef list_operations_h
#define list_operations_h

#include "basics.h"

template <class T>
  int length( 
#line 7 "list.ph"
a_List<T> *  
#line 7 "list.ph"
 l)
  {
    int len = 0;
    
#line 12 "list.ph"
{
  for (;;) {
    if (l) {
#line 12 "list.ph"
     l = l->_2; len++; 
#line 12 "list.ph"
    } else { goto L1; }
  }
  L1:;
}
#line 13 "list.ph"
#line 13 "list.ph"

    return len;
  }

template <class T>
  
#line 18 "list.ph"
a_List<T> *  
#line 18 "list.ph"
 append( a_List<T> *  
#line 18 "list.ph"
 a, a_List<T> *  
#line 18 "list.ph"
 b)
  {
    
#line 23 "list.ph"
{
  if (a) {
#line 23 "list.ph"
   return 
#line 23 "list.ph"
#line 23 "list.ph"
    list_1_(a->_1,append(a->_2,b))
#line 23 "list.ph"
#line 23 "list.ph"
    ; 
#line 23 "list.ph"
  } else {
#line 22 "list.ph"
   return b; 
#line 22 "list.ph"
  }
}
#line 24 "list.ph"
#line 24 "list.ph"

  }

template <class T>
  
#line 28 "list.ph"
a_List<T> *  
#line 28 "list.ph"
 rev( a_List<T> *  
#line 28 "list.ph"
 a)
  {
    a_List<T> *  
#line 30 "list.ph"
 b = 
#line 30 "list.ph"
nil_1_
#line 30 "list.ph"
#line 30 "list.ph"
;
    
#line 31 "list.ph"
#line 33 "list.ph"
{
  for (;;) {
    if (a) {
#line 33 "list.ph"
     b = 
#line 33 "list.ph"
#line 33 "list.ph"
      list_1_(a->_1,b)
#line 33 "list.ph"
#line 33 "list.ph"
      ; a = a->_2; 
#line 33 "list.ph"
    } else { goto L2; }
  }
  L2:;
}
#line 34 "list.ph"
#line 34 "list.ph"

    return b;
  }

#endif
#line 39 "list.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2
Number of ifs generated      = 3
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
