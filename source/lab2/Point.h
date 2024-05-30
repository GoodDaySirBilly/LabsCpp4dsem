//
// Created by user on 3/1/2024.
//

#ifndef CMAKEPROJECT_POINT_H
#define CMAKEPROJECT_POINT_H
#include <iostream>

class Point {

private:
    double _x, _y, _z;
    double _increment, _decrement;

public:
    explicit Point();
    explicit Point(double);
    explicit Point(double, double, double);
    explicit Point(double, double, double, double ,double);

    Point(const Point &p);

    ~Point();

    bool setX(double);
    bool setY(double);
    bool setZ(double);
    bool setIncrement(double);
    bool setDecrement(double);

    bool turnAll(double step = 100.0);
    void print() const;

    [[nodiscard]] double getDecrement() const;
    [[nodiscard]] double getIncrement() const;
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    [[nodiscard]] double getZ() const;

    Point operator ! () const;
    Point &operator = (const Point&);

    Point& operator -- ();
    Point operator -- (int);

    friend Point operator ++ (Point&, int);
    friend Point& operator++( Point& );

};

#endif //CMAKEPROJECT_POINT_H