//
// Created by user on 4/15/2024.
//

#include "Trapezoid.h"

double Trapezoid::square() {
    return (_a+_b)/2
    *sqrt(_c*_c-((_a-_b)*(_a-_b)+_c*_c-_d*_d)
    /(2*_a-2*_b));
}

Trapezoid::Trapezoid(double a, double b, double c, double d):
_a(a), _b(b), _c(c), _d(d){}

Trapezoid::Trapezoid() : _a(0), _b(0), _c(0), _d(0){}

Trapezoid::Trapezoid(const Trapezoid &another) :
        _a(another._a), _b(another._b),
        _c(another._c), _d(another._d){}

std::ostream &Trapezoid::operator<<(std::ostream &os) {
    return os<<_a<<" "<<_b<<" "<<_c<<" "<<_d;
}

Trapezoid::~Trapezoid() = default;
