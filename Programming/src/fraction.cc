#include <fraction.h>

static int gcd(int a,int b) {
  int
    r;

  a = (a >= 0) ? a : -a;
  b = (b >= 0) ? b : -b;

  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

Fraction::Fraction(int n,int d) {
  int
    g;

  if (d < 0) {
    n = -n;
    d = -d;
  }

  g = gcd(n,d);

  num = n / g;
  den = d / g;
}

Fraction Fraction::operator=(Fraction rhs) {

  num = rhs.num;
  den = rhs.den;

  return rhs;
}

Fraction Fraction::operator+(Fraction rhs) {
  int
    n,d;

  n = num * rhs.den + den * rhs.num;
  d = den * rhs.den;

  return Fraction(n,d);
}

Fraction Fraction::operator-(Fraction rhs) {
  int
    n,d;

  n = num * rhs.den - den * rhs.num;
  d = den * rhs.den;

  return Fraction(n,d);
}

Fraction Fraction::operator*(Fraction rhs) {
  int
    n,d;

  n = num * rhs.num;
  d = den * rhs.den;

  return Fraction(n,d);
}

Fraction Fraction::operator/(Fraction rhs) {
  int
    n,d;

  n = num * rhs.den;
  d = den * rhs.num;

  return Fraction(n,d);
}

bool Fraction::operator==(Fraction rhs) {
  return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {
  return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<=(Fraction rhs) {
  return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {
  return num * rhs.den >= den * rhs.num;
}

bool Fraction::operator<(Fraction rhs) {
    return num * rhs.den < den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {
    return num * rhs.den > den * rhs.num;
}

std::istream &operator>>(std::istream &is,Fraction &f) {
  int
    n,d;
  char
    slash;

  is >> n >> slash >> d;

  f = Fraction(n,d);

  return is;
}

std::ostream &operator<<(std::ostream &os,Fraction f) {

  os << f.getNum() << " / " << f.getDen();

  return os;
}
