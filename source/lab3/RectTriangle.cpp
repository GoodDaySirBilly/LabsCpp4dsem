//
// Created by user on 4/15/2024.
//

#include "RectTriangle.h"

double RectTriangle::square() {
    return _a*_b/2.;
}

RectTriangle::RectTriangle(double a, double b) : _a(a), _b(b){}

RectTriangle::RectTriangle() : _a(1), _b(1){}

RectTriangle::RectTriangle(const RectTriangle &another):
        _a(another._a),
        _b(another._b) {}

std::ostream &RectTriangle::operator<<(std::ostream &os) {
    return os<<_a<<" "<<_b;
}

RectTriangle::~RectTriangle() = default;
