//
// Created by user on 4/15/2024.
//

#ifndef CMAKEPROJECT_FIGURE_H
#define CMAKEPROJECT_FIGURE_H

#include <iostream>
class Figure {
public:
    virtual double square() = 0;
    virtual std::ostream& operator<<(std::ostream &os) = 0;
};



#endif //CMAKEPROJECT_FIGURE_H
