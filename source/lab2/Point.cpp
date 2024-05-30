//
// Created by user on 3/1/2024.
//

#include "Point.h"

Point::Point() : _x(0.), _y(0.), _z(0.),
                _increment(1.), _decrement(1.){}

Point::Point(double all) {
    this->_x = this->_y = this->_z = all;
    this->_increment = this->_decrement = 1.;
}

Point::Point(double x, double y, double z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_increment = this->_decrement = 1.;
}

Point::Point(double x, double y, double z,
             double increment, double decrement) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_increment = increment;
    this->_decrement = decrement;
}

Point::Point(const Point &p) {
    this->_x = p._x;
    this->_y = p._y;
    this->_z = p._z;
    this->_increment = p._increment;
    this->_decrement = p._decrement;
}

Point::~Point() = default;

bool Point::setX(double x) {
    this->_x = x;
    return true;
}

bool Point::setY(double y) {
    this->_y = y;
    return true;
}

bool Point::setZ(double z) {
    this->_z = z;
    return true;
}

bool Point::setIncrement(double increment) {
    this->_increment = increment;
    return true;
}

bool Point::setDecrement(double decrement) {
    this->_decrement = decrement;
    return true;
}

bool Point::turnAll(double step) {
    _x += step;
    _y += step;
    _z += step;
    return true;
}

void Point::print() const {
    std::cout<<_x<<" "<<_y<<" "<<_z<<std::endl;
}

double Point::getX() const {
    return this->_x;
}

double Point::getY() const {
    return this->_y;
}

double Point::getZ() const {
    return this->_z;
}

double Point::getIncrement() const {
    return this->_increment;
}

double Point::getDecrement() const {
    return this->_decrement;
}

Point Point::operator!() const {
    return Point{-_x, -_y, -_z};
}

Point &Point::operator=(const Point &p) = default;

Point &Point::operator--() {
    double max = ((_x>_y?_x:_y)>_z?(_x>_y?_x:_y):_z);
    this->_x-=max;
    this->_y-=max;
    this->_z-=max;
    return *this;
}

Point Point::operator--(int) {
    Point copy{*this};
    _x-=getDecrement();
    _y-=getDecrement();
    _z-=getDecrement();
    return copy;
}

Point operator++(Point &obj, int) {
    Point copy{obj};
    obj.setX(obj.getX()+obj.getIncrement());
    obj.setY(obj.getY()+obj.getIncrement());
    obj.setZ(obj.getZ()+obj.getIncrement());
    return copy;
}

Point &operator++(Point &obj) {
    double min = (
            (obj._x<obj._y?
             obj._x:obj._y)
            <obj._z?
            (obj._x<obj._y?
             obj._x:obj._y):
            obj._z);
    obj._x=obj._x+min;
    obj._y=obj._y+min;
    obj._z=obj._z+min;
    return obj;

}
