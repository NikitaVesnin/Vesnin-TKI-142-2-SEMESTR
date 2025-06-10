#include "Polygon.h"

size_t Polygon::getVertexCount() const {
    return vertices.size();
}

const std::vector<Point>& Polygon::getVertices() const {
    return vertices;
}

std::istream& operator>>(std::istream& is, Polygon& polygon) {
    polygon.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Polygon& polygon) {
    os << polygon.toString();
    return os;
}