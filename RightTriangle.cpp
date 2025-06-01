#include "RightTriangle.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

RightTriangle::RightTriangle() : a(1.0), b(1.0) {}

RightTriangle::RightTriangle(double cathetusA, double cathetusB) 
    : a(cathetusA), b(cathetusB) {
    validateSides();
}

void RightTriangle::validateSides() const {
    if (a <= 0 || b <= 0) {
        throw std::invalid_argument("Катеты должны быть положительными числами");
    }
}

double RightTriangle::getA() const { 
    return a; 
}

double RightTriangle::getB() const { 
    return b; 
}

double RightTriangle::calculateArea() const {
    return 0.5 * a * b;
}

double RightTriangle::calculateHypotenuse() const {
    return sqrt(a * a + b * b);
}

double RightTriangle::calculateCircumradius() const {
    return calculateHypotenuse() / 2.0;
}

std::string RightTriangle::toString() const {
    std::ostringstream oss;
    oss << "Прямоугольный треугольник с катетами " << a << " и " << b;
    return oss.str();
}