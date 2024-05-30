//
// Created by user on 4/15/2024.
//

#ifndef CMAKEPROJECT_CIRCLE_H
#define CMAKEPROJECT_CIRCLE_H

#include "Figure.h"
#include <cmath>


class Circle : public Figure{
private:
    double radius;
public:
    explicit Circle(double radius);
    explicit Circle();
    Circle(const Circle& another);
    virtual ~Circle();

    double square() override;

    std::ostream &operator<<(std::ostream &os) override;
};


#endif //CMAKEPROJECT_CIRCLE_H
