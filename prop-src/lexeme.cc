///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "lexeme.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "lexeme.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements some support routines for lexeme and regular
//  expressions handling.
//
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <AD/strings/charesc.h>
#include "ir.h"
#include "ast.h"
#include "hashtab.h"
#include "type.h"
#include "matchcom.h"

///////////////////////////////////////////////////////////////////////////////
//  Properly quote a string
///////////////////////////////////////////////////////////////////////////////

const char *make_quoted_string( const char * s)
{
  char *new_str = str_pool[std::strlen(s) * 4];
  *new_str = '"';
  char *end_str = quote_string(new_str+1,s);
  *end_str++ = '"';
  *end_str   = '\0';
  return new_str;
}

///////////////////////////////////////////////////////////////////////////////
//  Add contexts to a string/regexp pattern
///////////////////////////////////////////////////////////////////////////////

Pat add_contexts( Conses contexts, Pat pat)
{
  if (contexts == 
#line 36 "lexeme.pcc"
#line 36 "lexeme.pcc"
nil_1_
#line 36 "lexeme.pcc"
#line 36 "lexeme.pcc"
) return pat;
  
#line 37 "lexeme.pcc"
#line 91 "lexeme.pcc"
{
  if (pat) {
    switch (pat->tag__) {
      case a_Pat::tag_LITERALpat: {
        switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
          case a_Literal::tag_STRINGlit: {
#line 64 "lexeme.pcc"
            
            return add_contexts(
                  contexts, LITERALpat( REGEXPlit( convert_regexp( ((Literal_STRINGlit *)((Pat_LITERALpat *)pat)->LITERALpat)->STRINGlit))));
            
#line 67 "lexeme.pcc"
            } break;
          case a_Literal::tag_REGEXPlit: {
#line 40 "lexeme.pcc"
            
            char buffer[4096];
            char * p = buffer;
            *p++ = '/';
            *p++ = '<';
            for (Conses l = contexts; l; l = l->_2)
            {
              if (l->_1)
                std::strcpy( p, l->_1->name);
              p += std::strlen(p);
              if (l->_2)
                *p++ = ',';
            }
            *p++ = '>';
            std::strcpy(p,((Literal_REGEXPlit *)((Pat_LITERALpat *)pat)->LITERALpat)->REGEXPlit+1); p += strlen(p) - 1;
            *p = '/';
            debug_msg( "converting %p into %s\n",
                       CONTEXTpat(contexts,pat), buffer);
            Pat new_pat = LITERALpat(REGEXPlit(str_pool[buffer]));
            new_pat->selector = pat->selector;
            new_pat->ty       = pat->ty;
            return new_pat;
            
#line 62 "lexeme.pcc"
            } break;
          default: {
            L1:; 
#line 87 "lexeme.pcc"
            
            error( "%Lillegal context(s) in pattern %p\n",
                   CONTEXTpat(contexts,pat));
            return pat;
            
#line 91 "lexeme.pcc"
            } break;
        }
        } break;
      case a_Pat::tag_LEXEMEpat: {
#line 69 "lexeme.pcc"
        
        Pat this_pat = expand_lexeme_pat(pat,((Pat_LEXEMEpat *)pat)->_2,((Pat_LEXEMEpat *)pat)->_3,((Pat_LEXEMEpat *)pat)->_4);
        Pat new_pat = NOpat;
        
#line 72 "lexeme.pcc"
#line 80 "lexeme.pcc"
        {
          for (;;) {
            if (this_pat) {
              switch (this_pat->tag__) {
                case a_Pat::tag_LOGICALpat: {
                  switch (((Pat_LOGICALpat *)this_pat)->_1) {
                    case ORpat: {
#line 75 "lexeme.pcc"
                      
                      Pat one_pat = add_contexts(contexts,((Pat_LOGICALpat *)this_pat)->_3);
                      new_pat = new_pat == NOpat ? one_pat
                              : LOGICALpat(ORpat,one_pat,new_pat);
                      this_pat = ((Pat_LOGICALpat *)this_pat)->_2;
                      
#line 80 "lexeme.pcc"
                      } break;
                    default: { goto L2; } break;
                  }
                  } break;
                default: { goto L2; } break;
              }
            } else { goto L2; }
          }
          L2:;
        }
#line 81 "lexeme.pcc"
#line 81 "lexeme.pcc"
        
        Pat p = add_contexts(contexts,this_pat);
        new_pat = new_pat == NOpat ? p : LOGICALpat(ORpat,p,new_pat);
        return new_pat;
        
#line 85 "lexeme.pcc"
        } break;
      default: { goto L1; } break;
    }
  } else { goto L1; }
}
#line 92 "lexeme.pcc"
#line 92 "lexeme.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//  Convert a string pattern into a regexp pattern if necessary
///////////////////////////////////////////////////////////////////////////////

#line 99 "lexeme.pcc"
#line 103 "lexeme.pcc"
Pat convert_regexp (Pat x_1);
Pat convert_regexp (Pat x_1)
{
  if (x_1) {
    switch (x_1->tag__) {
      case a_Pat::tag_LITERALpat: {
        switch (((Pat_LITERALpat *)x_1)->LITERALpat->tag__) {
          case a_Literal::tag_STRINGlit: {
#line 100 "lexeme.pcc"
           return LITERALpat( REGEXPlit( convert_regexp(((Literal_STRINGlit *)((Pat_LITERALpat *)x_1)->LITERALpat)->STRINGlit))); 
#line 100 "lexeme.pcc"
            } break;
          default: {
            L3:; 
#line 102 "lexeme.pcc"
           return x_1; 
#line 102 "lexeme.pcc"
            } break;
        }
        } break;
      default: { goto L3; } break;
    }
  } else { goto L3; }
}
#line 103 "lexeme.pcc"
#line 103 "lexeme.pcc"


///////////////////////////////////////////////////////////////////////////////
//  Convert a string literal into a regular expression literal.
///////////////////////////////////////////////////////////////////////////////

const char *convert_regexp( const char * string, Bool quotes)
{
  char buf[4096];
  register char * p = buf;
  register const char * s = string + 1;
  if (quotes)
    *p++ = '/';
  while (*s) {
     char c;
     s = parse_char(s,c);
     
#line 119 "lexeme.pcc"
#line 126 "lexeme.pcc"
{
  switch (c) {
    case '$':
    case '(':
    case ')':
    case '*':
    case '+':
    case '.':
    case '/':
    case '<':
    case '>':
    case '?':
    case '[':
    case '\\':
    case ']':
    case '^':
    case '{':
    case '|':
    case '}': {
      L4:; 
#line 124 "lexeme.pcc"
     *p++ = '\\'; *p++ = c; 
#line 124 "lexeme.pcc"
    } break;
    default: {
#line 126 "lexeme.pcc"
     p = print_char(p,c); 
#line 126 "lexeme.pcc"
    }
  }
}
#line 127 "lexeme.pcc"
#line 127 "lexeme.pcc"

  }
  p -= 2;
  if (quotes)
    *p++ = '/';
  *p = '\0';
  debug_msg( "converting %s into %s\n", string, buf);
  return str_pool[buf];
}

///////////////////////////////////////////////////////////////////////////////
//  The global lexeme and lexeme class environments
///////////////////////////////////////////////////////////////////////////////

static HashTable lexeme_env( string_hash, string_equal);
static HashTable lexeme_class_env( string_hash, string_equal);

///////////////////////////////////////////////////////////////////////////////
//  Method to update or lookup from the lexeme class environment
///////////////////////////////////////////////////////////////////////////////

void update_lexeme_class( Id id, TermDefs terms)
{
  if (lexeme_class_env.contains(id))
    error ("%Lredefinition of lexeme class %s\n", id);
  else
    lexeme_class_env.insert( id, terms);
}

TermDefs lookup_lexeme_class( Id id)
{
  HashTable::Entry * e = lexeme_class_env.lookup(id);
  if (e)
    return TermDefs(e->v);
  else
  {
    error("%Llexeme class %s is undefined\n", id);
    return 
#line 164 "lexeme.pcc"
#line 164 "lexeme.pcc"
nil_1_
#line 164 "lexeme.pcc"
#line 164 "lexeme.pcc"
;
  }
}

///////////////////////////////////////////////////////////////////////////////
//  Method to expand a pattern taking into account of lexeme definitions.
///////////////////////////////////////////////////////////////////////////////

Pat mk_regexp_pat( const char * re)
{
  const char * p = re;
  char buf[4096];
  char * q = buf;
  if (std::strchr(re,'{') != 0)
  {
    // skip context
    if (*p == '<')
    {
      do { *q++ = *p; } while (*p && *p++ != '>'); }
      
#line 183 "lexeme.pcc"
#line 246 "lexeme.pcc"
{
  for (;;) {
    char _V1 = (*p);
    switch (_V1) {
      case '\000': { goto L5; } break;
      case '[': {
#line 186 "lexeme.pcc"
        
        do { *q++ = *p++; }
        while (p[-1] && (p[-2] == '\\' || p[-1] != ']'));
        
#line 189 "lexeme.pcc"
      } break;
      case '{': {
#line 191 "lexeme.pcc"
        
        char name[256]; char * r;
        for (r = name, p++; *p && *p != '}';) *r++ = *p++;
        if (*p == '}') p++;
        else error ("%Lmissing '}' in regular expression %s\n",re);
        *r = '\0';
        HashTable::Entry * e = lexeme_env.lookup(name);
        if (e)
        {
          Pat pattern = (Pat)e->v;
          
#line 201 "lexeme.pcc"
#line 218 "lexeme.pcc"
        {
          if (pattern) {
            switch (pattern->tag__) {
              case a_Pat::tag_LITERALpat: {
                switch (((Pat_LITERALpat *)pattern)->LITERALpat->tag__) {
                  case a_Literal::tag_STRINGlit: {
#line 211 "lexeme.pcc"
                    
                    *q++ = '(';
                    std::strcpy( q, convert_regexp( ((Literal_STRINGlit *)((Pat_LITERALpat *)pattern)->LITERALpat)->STRINGlit, false));
                    q += std::strlen(q) - 1;
                    *q++ = ')';
                    
#line 216 "lexeme.pcc"
                    } break;
                  case a_Literal::tag_REGEXPlit: {
#line 204 "lexeme.pcc"
                    
                    *q++ = '(';
                    std::strcpy( q, ((Literal_REGEXPlit *)((Pat_LITERALpat *)pattern)->LITERALpat)->REGEXPlit+1);
                    q += std::strlen(((Literal_REGEXPlit *)((Pat_LITERALpat *)pattern)->LITERALpat)->REGEXPlit)-2;
                    *q++ = ')';
                    
#line 209 "lexeme.pcc"
                    } break;
                  default: {
                    L6:; } break;
                }
                } break;
              default: { goto L6; } break;
            }
          } else { goto L6; }
        }
#line 218 "lexeme.pcc"
#line 218 "lexeme.pcc"
        
        }
        else
          error ("%Llexeme {%s} is undefined in %s\n", name, re);
        
#line 222 "lexeme.pcc"
      } break;
      default: {
#line 224 "lexeme.pcc"
        
        char ch;
        const char * r = parse_char(p,ch);
        // if (*p == '\\') *q++ = '\\';
        if (*p == '\\')
        {
          
#line 230 "lexeme.pcc"
#line 240 "lexeme.pcc"
        {
          switch (ch) {
            case '$':
            case '(':
            case ')':
            case '*':
            case '+':
            case '.':
            case '/':
            case '<':
            case '>':
            case '?':
            case '[':
            case '\\':
            case ']':
            case '^':
            case '{':
            case '|':
            case '}': {
              L7:; 
#line 235 "lexeme.pcc"
              
              *q++ = '\\';
              *q++ = ch;
              
#line 238 "lexeme.pcc"
            } break;
            default: {
#line 240 "lexeme.pcc"
            q = print_char( q, ch); 
#line 240 "lexeme.pcc"
            }
          }
        }
#line 241 "lexeme.pcc"
#line 241 "lexeme.pcc"
        
        }
        else
          q = print_char(q,ch);
        p = r;
        
#line 246 "lexeme.pcc"
      }
    }
  }
  L5:;
}
#line 247 "lexeme.pcc"
#line 247 "lexeme.pcc"

    *q++;
    debug_msg( "%s ==> %s\n", re, buf);
    re = buf;
  }
  return LITERALpat(REGEXPlit(str_pool[re]));
}

///////////////////////////////////////////////////////////////////////////////
//  Method to update the lexeme environment.
///////////////////////////////////////////////////////////////////////////////

void update_lexeme( Id id, Ids args, Pat pat)
{
  HashTable::Entry * e = lexeme_env.lookup(id);

  if (e)
    error( "%Llexeme {%s} already defined as %p\n", id, (Pat)e->v);
  else
    lexeme_env.insert( id, pat);
}

///////////////////////////////////////////////////////////////////////////////
//  Method to expand a lexeme pattern into a set of disjunctive patterns.
///////////////////////////////////////////////////////////////////////////////

Pat expand_lexeme_pat( Pat pat, Ty ty, int n, Cons terms[])
{
  
#line 275 "lexeme.pcc"
#line 303 "lexeme.pcc"
{
  Ty _V2 = deref_all(ty);
  if (_V2) {
    switch (_V2->tag__) {
      case a_Ty::tag_TYCONty: {
        if (boxed(((Ty_TYCONty *)_V2)->_1)) {
          switch (((Ty_TYCONty *)_V2)->_1->tag__) {
            case a_TyCon::tag_DATATYPEtycon: {
              if (
#line 278 "lexeme.pcc"
              ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->qualifiers | QUALlexeme) == 0)
#line 278 "lexeme.pcc"
) {
                
#line 279 "lexeme.pcc"
               error ("%Ldatatype %T is not a lexeme type\n", ty); 
#line 279 "lexeme.pcc"
              } else {
                
#line 281 "lexeme.pcc"
                
                Pat disj_pats = NOpat;
                for (int i = 0; i < n; i++)
                {
                  
#line 285 "lexeme.pcc"
#line 299 "lexeme.pcc"
                {
                  Cons _V3 = terms[i];
                  if (_V3) {
                    if (_V3->lexeme_pattern) {
#line 288 "lexeme.pcc"
                      
                      Pat new_pat = subst(convert_regexp(_V3->lexeme_pattern),0,true);
                      disj_pats = (disj_pats == NOpat) ? new_pat
                                  : LOGICALpat(ORpat,disj_pats, new_pat);
                      disj_pats->selector = pat->selector;
                      
#line 293 "lexeme.pcc"
                    } else {
#line 295 "lexeme.pcc"
                      
                      error ("%Llexeme pattern is undefined for constructor %s\n", _V3->name);
                      
#line 297 "lexeme.pcc"
                    }
                  } else {}
                }
#line 299 "lexeme.pcc"
#line 299 "lexeme.pcc"
                
                }
                return disj_pats;
                
#line 302 "lexeme.pcc"
              }
              } break;
            default: {
              L8:; 
#line 303 "lexeme.pcc"
            error ("%Lnon lexeme type %T in pattern %p\n", ty, pat); 
#line 303 "lexeme.pcc"
              } break;
          }
        } else { goto L8; }
        } break;
      default: { goto L8; } break;
    }
  } else {}
}
#line 304 "lexeme.pcc"
#line 304 "lexeme.pcc"

  return WILDpat();
}
#line 307 "lexeme.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 197
Number of ifs generated      = 9
Number of switches generated = 13
Number of labels             = 6
Number of gotos              = 8
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
