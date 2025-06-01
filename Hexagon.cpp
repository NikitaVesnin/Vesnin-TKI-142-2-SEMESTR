#include "Hexagon.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
Hexagon::Hexagon() {
    vertices.resize(6);
}
Hexagon::Hexagon(const std::vector<Point>& points) {
    if (points.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 points");
    }
    vertices = points;
    if (!IsValid()) {
        throw std::invalid_argument("Invalid hexagon points");
    }
}
Hexagon::Hexagon(const std::vector<std::pair<double, double>>& coords) {
    if (coords.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 points");
    }
    for (const auto& p : coords) {
        vertices.emplace_back(p.first, p.second);
    }
    if (!IsValid()) {
        throw std::invalid_argument("Invalid hexagon points");
    }
}
bool Hexagon::IsValid() const {
    double side = SideLength();
    for (size_t i = 1; i < 6; ++i) {
        double dx = vertices[i].getX() - vertices[i-1].getX();
        double dy = vertices[i].getY() - vertices[i-1].getY();
        double currentSide = sqrt(dx*dx + dy*dy);
        if (abs(currentSide - side) > 1e-6) {
            return false;
        }
    }
    return true;
}
double Hexagon::SideLength() const {
    double dx = vertices[1].getX() - vertices[0].getX();
    double dy = vertices[1].getY() - vertices[0].getY();
    return sqrt(dx*dx + dy*dy);
}
std::string Hexagon::ToString() const {
    std::ostringstream oss;
    oss << "Hexagon with vertices: ";
    for (const auto& p : vertices) {
        oss << p << " ";
    }
    return oss.str();
}
double Hexagon::Area() const {
    double side = SideLength();
    return 3 * sqrt(3) * side * side / 2;
}
double Hexagon::Perimeter() const {
    return 6 * SideLength();
}
double Hexagon::Circumradius() const {
    return SideLength();
}
void Hexagon::Read(std::istream& is) {
    std::vector<Point> points(6);
    for (int i = 0; i < 6; ++i) {
        is >> points[i];
    }
    *this = Hexagon(points);
}
bool Hexagon::operator==(const Hexagon& other) const {
    for (size_t i = 0; i < 6; ++i) {
        if (vertices[i] != other.vertices[i]) {
            return false;
        }
    }
    return true;
}
bool Hexagon::operator!=(const Hexagon& other) const {
    return !(*this == other);
}
Hexagon Hexagon::FromString(const std::string& str) {
    std::istringstream iss(str);
    Hexagon h;
    iss >> h;
    return h;
}