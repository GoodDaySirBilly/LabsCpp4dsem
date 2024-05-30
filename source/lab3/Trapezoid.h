//
// Created by user on 4/15/2024.
//

#ifndef CMAKEPROJECT_TRAPEZOID_H
#define CMAKEPROJECT_TRAPEZOID_H

#include "Figure.h"
#include <cmath>

class Trapezoid : public Figure{
private:
    double _a,_b,_c,_d;
public:
    explicit Trapezoid(double a, double b,double c,double d);
    explicit Trapezoid();
    Trapezoid(const Trapezoid& another);
    virtual ~Trapezoid();

    double square() override;

    std::ostream &operator<<(std::ostream &os) override;
};


#endif //CMAKEPROJECT_TRAPEZOID_H
