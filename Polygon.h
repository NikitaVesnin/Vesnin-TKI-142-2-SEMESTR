#pragma once
#include <string>
#include <vector>
#include "Point.h"

class Polygon {
public:
    virtual ~Polygon() = default;
    
    virtual std::string ToString() const = 0;
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Circumradius() const = 0;
    
    virtual void Read(std::istream& is) = 0;
    
    friend std::istream& operator>>(std::istream& is, Polygon& p);
    friend std::ostream& operator<<(std::ostream& os, const Polygon& p);
};