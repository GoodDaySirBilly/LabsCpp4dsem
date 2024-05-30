//
// Created by user on 4/15/2024.
//

#ifndef CMAKEPROJECT_RECTANGLE_H
#define CMAKEPROJECT_RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure{
private:
    double _a,_b;

public:
    explicit Rectangle(double a, double b);
    explicit Rectangle();
    Rectangle(const Rectangle& another);
    virtual ~Rectangle();

    double square() override;

    std::ostream &operator<<(std::ostream &os) override;

};


#endif //CMAKEPROJECT_RECTANGLE_H
