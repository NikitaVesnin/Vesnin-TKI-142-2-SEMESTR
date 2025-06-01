#include "Point.h"
Point::Point(double x, double y) : x(x), y(y) {}
double Point::getX() const { return x; }
double Point::getY() const { return y; }
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}