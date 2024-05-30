//
// Created by user on 4/15/2024.
//

#ifndef CMAKEPROJECT_RECTTRIANGLE_H
#define CMAKEPROJECT_RECTTRIANGLE_H

#include "Figure.h"
#include <cmath>

class RectTriangle : public Figure{
private:
    double _a,_b;
public:
    explicit RectTriangle(double a, double b);
    explicit RectTriangle();
    RectTriangle(const RectTriangle& another);
    virtual ~RectTriangle();

    double square() override;

    std::ostream &operator<<(std::ostream &os) override;
};


#endif //CMAKEPROJECT_RECTTRIANGLE_H
