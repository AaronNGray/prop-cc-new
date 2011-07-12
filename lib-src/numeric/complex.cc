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

#include <cmath>
#include <AD/numeric/complex.h>

inline double sgn2(double x)
{
  return x >= 0.0 ? 0.5 : -0.5;
}

const double pi2 = 3.1415926535 / 2.0;

Complex operator / (const Complex& a, const Complex& b)
{
  double r = norm(b);
  return Complex((a.real * b.real + a.imag * b.imag) / r,
                 (a.imag * b.real - a.real * b.imag) / r);
}

Complex operator / (double a, const Complex& b)
{
  double r = norm(b);
  return Complex((a * b.real) / r, (-a * b.imag) / r);
}

////////////////////////////////////////////////////////////////////
// The following trignometric and logarithmic functions
// probably have very bad numerically properties---assuming
// that they are correct in the first place.  Use at your
// own risk.
////////////////////////////////////////////////////////////////////

Complex sin( const Complex& c)
{
  return Complex( sin(c.real) * std::cosh(c.imag), std::cos(c.real) * sinh(c.imag));
}

Complex std::cos( const Complex& c)
{
  return Complex( std::cos(c.real) * std::sinh(c.imag), -sin(c.real) * cosh(c.imag));
}

Complex std::tan( const Complex& c)
{
  double real2      = c.real * 2.0;
  double imag2      = c.imag * 2.0;
  double cos_real2  = std::cos(real2);
  double cosh_imag2 = std::cosh(imag2);
  return Complex(sin(real2) / (cos_real2 + cosh_imag2),
                 std::tanh(imag2) / (1 + cos_real2/cosh_imag2));
}

Complex std::sinh( const Complex& c)
{
  return Complex( std::sinh(c.real) * std::cos(c.imag), cosh(c.real) * sin(c.imag));
}

Complex std::cosh( const Complex& c)
{
  return Complex( std::cosh(c.real) * std::cos(c.imag), sinh(c.real) * sin(c.imag));
}

Complex std::tanh( const Complex& c)
{
  double real2      = 2.0 * c.real;
  double imag2      = 2.0 * c.imag;
  double cos_imag2  = std::cos(imag2);
  double cosh_real2 = std::cosh(real2);
  return Complex(std::tanh(real2)/(1 + cos_imag2/cosh_real2),
                 sin(imag2)/(cosh_real2 + cos_imag2));
}

/*
Complex std::asin(const Complex& c)
{  double n  = norm(c);
   double n1 = n - 1.0;
   double d  = std::sqrt(n1 * n1 + 4 * c.imag * c.imag) - n;
   return Complex(sgn2(c.real) * std::astd::cos(d),
                  sgn2(c.imag) * astd::cosh(d));
}

Complex std::astd::cos(const Complex& c)
{  double n  = norm(c);
   double n1 = n - 1.0;
   double d  = std::sqrt(n1 * n1 + 4 * c.imag * c.imag) - n;
   return Complex(pi2 - sgn2(c.real) * std::astd::cos(d),
                  -sgn2(c.imag) * astd::cosh(d));
}
*/

Complex std::log( const Complex& c)
{
  double n = norm(c);
  return Complex(std::log(n)/2.0, atan2(c.imag,c.real));
}

Complex std::exp( const Complex& c)
{
  double e_x = std::exp(c.real);
  return Complex(e_x * std::cos(c.imag), e_x * sin(c.imag));
}

Complex std::pow( const Complex& e, const Complex& x)
{
  return std::exp(log(e) * x);
}

Complex std::pow( const Complex& e, double x)
{
  return std::exp(log(e) * x);
}

Complex std::pow( double e, const Complex& x)
{
  return std::exp(log(e) * x);
}

Complex polar( double r, double theta)
{
  return Complex(r * sin(theta), r * std::cos(theta));
}

double norm( const Complex& c)
{
  return c.real * c.real + c.imag * c.imag;
}

std::ostream& operator << (std::ostream& out, const Complex& a)
{
  return out << '(' << a.real << ',' << a.imag << ')';
}
