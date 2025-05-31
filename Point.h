#pragma once
#include <iostream>

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0);
    
    double getX() const;
    double getY() const;
    
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};