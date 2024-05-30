//
// Created by user on 4/15/2024.
//

#include "Circle.h"

double Circle::square() {
    return radius*radius*M_PI;
}

Circle::Circle(double radius) : radius(radius) {}

Circle::Circle() : radius(1) {}

Circle::~Circle() = default;

Circle::Circle(const Circle &another) : radius(another.radius) {}

std::ostream &Circle::operator<<(std::ostream &os) {
    os<<radius;
    return os;
}
