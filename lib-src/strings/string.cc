//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the
// public domain.   The author(s) of this software reserve no copyrights on
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are free to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in
// your programs, and that this notice be preserved intact in all the source
// code.
//
// This software is still under development and we welcome any suggestions
// and help from the users.
//
// Allen Leung
// 1994
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <AD/strings/string.h>


////////////////////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Searching
////////////////////////////////////////////////////////////////////

int SubString::contains( RegExp& regexp) const
{
  return regexp.Match( get_string(), len);
}

int SubString::contains( char c) const
{  /* const char * r = (const char *)std::memchr(get_string(),c,len);
           return r ? r - get_string() : -1;
         */
  return -1;
}

int SubString::contains( const char *, int) const
{
  return 0;
}

int SubString::contains( const String&) const
{
  return 0;
}

int SubString::contains( const SubString&) const
{
  return 0;
}

////////////////////////////////////////////////////////////////////////////
//  Class String
////////////////////////////////////////////////////////////////////////////

void String::out_of_bounds(int i) const     // error handler
{
  std::cerr << "[Attempting to index location " << i << " of string: "
  << string << "]\n";
  std::exit(1);
}

////////////////////////////////////////////////////////////////////////////
//  Constructors
////////////////////////////////////////////////////////////////////////////

String::String( int initial_capacity)
{
  if (initial_capacity > 0)
  {
    string = new char [cap = initial_capacity];
    len = initial_capacity;
    string[len] = '\0';
  }
  else
  {
    string = 0;
    len = 0;
    cap = 0;
  }
}

String::String( char c, int times)
{
  if (times > 0)
  {
    string = new char [cap = (len = times) + 1];
    std::memset(string,c,len);
    string[len] = '\0';
  }
  else
  {
    string = 0;
    len = 0;
    cap = 0;
  }
}

String::String( const char * s)
{
  if (s)
  {
    string = new char [cap = (len = std::strlen(s)) + 1];
    std::memcpy(string,s,len);
    string[len] = '\0';
  }
  else
  {
    string = 0;
    len = cap = 0;
  }
}

String::String( const char * s, int l)
{
  if (s && l >= 0)
  {
    string = new char [cap = (len = l) + 1];
    std::memcpy(string,s,len);
    string[len] = '\0';
  }
  else
  {
    string = 0;
    len = cap = 0;
  }
}

String::String( const String& s)
{
  string = new char [cap = (len = s.len) + 1];
  std::memcpy(string,s.string,len);
}

///////////////////////////////////////////////////////////////////////
// String expansion
///////////////////////////////////////////////////////////////////////

void String::grow( long new_len)
{
  cap = new_len * 3 / 2 + 1;
  char * new_string = new char [cap];
  std::memcpy(new_string,string,len);
  delete [] string;
  string = new_string;
}

///////////////////////////////////////////////////////////////////////
// Assigment
///////////////////////////////////////////////////////////////////////

String& String::operator = (const String& s)
{
  if (this != &s)
  {
    if (s.len >= cap)
      grow(s.len);
    std::memcpy(string,s.string,len = s.len);
    string[len] = '\0';
  }
  return *this;
}

String& String::operator = (const char * s)
{
  if (s == 0)
    len = 0;
  else
  {
    int l = std::strlen(s);
    if (l >= cap)
      grow(l);
    std::strcpy(string,s);
    len = l;
  }
  return *this;
}

String& String::operator = (const SubString& s)
{
  if (s.length() >= cap)
    grow(s.length());
  std::memcpy(string, s.get_string(), len = s.length());
  string[len] = '\0';
  return *this;
}

////////////////////////////////////////////////////////////////////
// String splicing
////////////////////////////////////////////////////////////////////

String& String::splice( int location, int kill_len, const char * s, int size)
{
  if (size < 0)
    size = s ? std::strlen(s) : 0;
  if (kill_len < 0)
    kill_len = 0;
  if (location + kill_len >= len)
    kill_len = len - location;
  int new_len = len - kill_len + size;
  if (new_len >= cap)
    grow(new_len);
  if (kill_len > size)
  {        // shrink string
    register char * p, * q;
    register int n = len - location + kill_len;
    for (p = string + location, q = p + kill_len - size; n > 0; n--)
      *p++ = *q++;
  }
  else if (kill_len < size)
  { // expand string
    register char * p, * q;
    register int n = len - location + kill_len;
    for (p = string + location + n - 1, q = p + size - kill_len + n - 1;
         n > 0; n--)
      *q-- = *p--;
  }
  len = new_len;
  string[len] = '\0';
  std::memcpy(string + location, s, size); // now copy substring
  return *this;
}

///////////////////////////////////////////////////////////////////////
// Concatenation
///////////////////////////////////////////////////////////////////////

String operator + (const String& a, const String& b)
{
  String r((int)(a.len + b.len));
  std::memcpy(r.string, a.string, a.len);
  std::memcpy(r.string + a.len, b.string, b.len);
  return r;
}
String operator + (const String& a, const char * b)
{
  String r((int)(a.len + std::strlen(b)));
  std::memcpy(r.string, a.string, a.len);
  std::strcpy(r.string + a.len, b);
  return r;
}

String operator + (const String& a, char c)
{
  String r((int)(a.len + 1));
  std::memcpy(r.string, a.string, a.len);
  r.string[a.len] = c;
  return r;
}

String operator + (const char * a, const String& b)
{
  int a_len = std::strlen(a);
  String r((int)(a_len + b.len));
  std::memcpy(r.string, a, a_len);
  std::memcpy(r.string + a_len, b.string, b.len);
  return r;
}

String operator + (char c, const String& s)
{
  String r((int)(s.len + 1));
  r.string[0] = c;
  std::memcpy(r.string + 1, s.string, s.len);
  return r;
}

///////////////////////////////////////////////////////////////////////
//  Multiplication
///////////////////////////////////////////////////////////////////////

String operator * (const String& s, int n)
{
  String r(s.length() * n);
  char * p;
  for (p = r.string; n > 0; p += s.length())
    std::memcpy(p, s.string, s.length());
  *p = '\0';
  return r;
}

String operator * (const SubString& s, int n)
{
  return String(s) * n;
}

///////////////////////////////////////////////////////////////////////
// Append to end
///////////////////////////////////////////////////////////////////////

String& String::operator += (const String& s)
{
  int new_len = s.len + len;
  if (new_len >= cap)
    grow(new_len);
  std::memcpy(string + len, s.string, s.len);
  len = new_len;
  string[len] = '\0';
  return *this;
}

String& String::operator += (const char * s)
{
  if (s)
  {
    int s_len = std::strlen(s);
    int new_len = s_len + len;
    if (new_len >= cap)
      grow(new_len);
    std::memcpy(string + len, s, s_len);
    len = new_len;
    string[len] = '\0';
  }
  return *this;
}

String& String::operator += (char c)
{
  if (len + 1 >= cap)
    grow(len + 1);
  string[len++] = c;
  string[len]   = '\0';
  return *this;
}

///////////////////////////////////////////////////////////////////////
// Comparisons
///////////////////////////////////////////////////////////////////////

int String::compare( const String& s) const
{
  register const char * p, * q;
  register int n = len < s.len ? len : s.len;
  for (p = string, q = s.string; n > 0; n--, p++, q++)
    if (*p - *q)
      return *p - *q;
  return *p - *q;
}

int String::compare( const SubString& s) const
{
  int l = len < s.len ? len : s.len;
  int r = std::memcmp(string,s.S.string + s.start, l);
  if (r)
    return r;
  return len - s.len;
}

int String::compare( const char* s, int l) const
{
  register const char * p, * q;
  if (l < 0)
    l = std::strlen(s);
  register int n = len < l ? len : l;
  for (p = string, q = s; n > 0; n--, p++, q++)
    if (*p - *q)
      return *p - *q;
  return *p - *q;
}

int String::case_insensitive_compare( const String& s) const
{
  return case_insensitive_compare(s.string, s.len);
}

int String::case_insensitive_compare( const SubString& s) const
{
  return case_insensitive_compare(s.get_string(), s.len);
}

int String::case_insensitive_compare( const char * s, int l) const
{
  register const char * p, * q;
  register int i = len < l ? len : l;
  for (p = string, q = s; i > 0; i--, p++, q++)
    if (std::tolower(*p) - tolower(*q))
      return std::tolower(*p) - tolower(*q);
  return std::tolower(*p) - tolower(*q);
}

int String::collate( const String&) const
{
  return 0;
}

int String::collate( const SubString&) const
{
  return 0;
}

int String::collate( const char *, int) const
{
  return 0;
}

///////////////////////////////////////////////////////////////////////
// In place operations
///////////////////////////////////////////////////////////////////////

String& String::to_upper()
{
  register char * p, * q;
  for (p = string, q = string + len; p < q; p++)
    *p = std::toupper(*p);
  return *this;
}

String& String::to_lower()
{
  register char * p, * q;
  for (p = string, q = string + len; p < q; p++)
    *p = std::tolower(*p);
  return *this;
}

String& String::trunc(int length)
{
  if (length >= 0 && length < len)
  {
    len = length;
    string[len] = '\0';
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////
// Searching
///////////////////////////////////////////////////////////////////////

int String::contains( RegExp& regexp) const
{
  return regexp.Match(string,len);
}

int String::contains( char c) const
{
  const char * r = std::strchr(string,c);
  return r ? r - string : -1;
}

int String::contains( const char * s, int) const
{
  const char * r = std::strstr(string,s);
  return r ? r - string : -1;
}

int String::contains( const String& s) const
{
  const char * r = std::strstr(string,s.string);
  return r ? r - string : -1;
}

int String::contains( const SubString&) const
{
  return 0;
}

///////////////////////////////////////////////////////////////////////
//  Input and Output
///////////////////////////////////////////////////////////////////////

std::istream& operator >> (std::istream& in, String&)
{
  return in;
}
