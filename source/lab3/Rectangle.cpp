//
// Created by user on 4/15/2024.
//

#include "Rectangle.h"

double Rectangle::square() {
    return _a*_b;
}

std::ostream &Rectangle::operator<<(std::ostream &os) {
    return os<<_a<<" "<<_b;
}

Rectangle::Rectangle(double a, double b) : _a(a), _b(b){}

Rectangle::Rectangle() : _a(1), _b(1){}

Rectangle::Rectangle(const Rectangle &another) :
                            _a(another._a),
                            _b(another._b) {}

Rectangle::~Rectangle() =default;
