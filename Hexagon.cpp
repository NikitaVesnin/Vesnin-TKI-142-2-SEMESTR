#include "Hexagon.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iomanip>

const double PI = acos(-1.0);

Hexagon::Hexagon() : sideLength(1.0) {
    for (size_t i = 0; i < 6; ++i) {
        double angle = 2 * PI * i / 6;
        double x = std::cos(angle);
        double y = std::sin(angle);
        vertices.emplace_back(x, y);
    }
}

Hexagon::Hexagon(const Point& center, double sideLength) : sideLength(sideLength) {
    if (sideLength <= 0) {
        throw std::invalid_argument("Длина стороны должна быть положительной");
    }
    
    for (size_t i = 0; i < 6; ++i) {
        double angle = 2 * M_PI * i / 6;
        double x = center.getX() + sideLength * std::cos(angle);
        double y = center.getY() + sideLength * std::sin(angle);
        vertices.emplace_back(x, y);
    }
}

Hexagon::Hexagon(const std::vector<Point>& vertices) {
    if (vertices.size() != 6) {
        throw std::invalid_argument("Шестиугольник должен иметь 6 вершин");
    }
    this->vertices = vertices;
    validateVertices();
    sideLength = calculateSideLength();
}

Hexagon::Hexagon(std::initializer_list<Point> initList) {
    if (initList.size() != 6) {
        throw std::invalid_argument("Шестиугольник должен иметь 6 вершин");
    }
    vertices = initList;
    validateVertices();
    sideLength = calculateSideLength();
}

void Hexagon::validateVertices() const {
    double expectedDistance = vertices[0].distanceTo(vertices[1]);
    
    for (size_t i = 1; i < 6; ++i) {
        double distance = vertices[i].distanceTo(vertices[(i + 1) % 6]);
        if (std::abs(distance - expectedDistance) > 1e-6) {
            throw std::invalid_argument("Все стороны шестиугольника должны быть равны");
        }
    }
}

double Hexagon::calculateSideLength() const {
    return vertices[0].distanceTo(vertices[1]);
}

double Hexagon::getSideLength() const {
    return sideLength;
}

double Hexagon::calculatePerimeter() const {
    return 6 * sideLength;
}

double Hexagon::calculateArea() const {
    return (3 * std::sqrt(3) / 2) * sideLength * sideLength;
}

double Hexagon::calculateCircumradius() const {
    return sideLength;
}

std::string Hexagon::toString() const {
    std::ostringstream oss;
    oss << "Правильный шестиугольник:\n";
    oss << "  Длина стороны: " << sideLength << "\n";
    oss << "  Периметр: " << calculatePerimeter() << "\n";
    oss << "  Площадь: " << calculateArea() << "\n";
    oss << "  Радиус описанной окружности: " << calculateCircumradius() << "\n";
    oss << "  Вершины:\n";
    for (const auto& vertex : vertices) {
        oss << "    " << vertex << "\n";
    }
    return oss.str();
}

void Hexagon::read(std::istream& is) {
    std::vector<Point> newVertices;
    for (int i = 0; i < 6; ++i) {
        Point p;
        is >> p;
        newVertices.push_back(p);
    }
    
    if (newVertices.size() != 6) {
        throw std::invalid_argument("Шестиугольник должен иметь 6 вершин");
    }
    
    vertices = newVertices;
    validateVertices();
    sideLength = calculateSideLength();
}

bool Hexagon::operator==(const Hexagon& other) const {
    if (vertices.size() != other.vertices.size()) return false;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i] != other.vertices[i]) return false;
    }
    return true;
}

bool Hexagon::operator!=(const Hexagon& other) const {
    return !(*this == other);
}

std::string Hexagon::ToString(const Hexagon& hexagon) {
    return hexagon.toString();
}

Hexagon Hexagon::ReadFromInput() {
    Hexagon hexagon;
    std::cin >> hexagon;
    return hexagon;
}