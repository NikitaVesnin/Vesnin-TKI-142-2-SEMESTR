#include "RightTriangle.h"
#include <stdexcept>  

RightTriangle::RightTriangle() {
    a = 0;
    b = 0;
}


RightTriangle::RightTriangle(double cathet1, double cathet2) {
    if (cathet1 <= 0 || cathet2 <= 0) {
        throw std::invalid_argument("Катеты должны быть положительными!");
    }
    a = cathet1;
    b = cathet2;
}


double RightTriangle::calculateArea() const {
    return (a * b) / 2.0;
}


double RightTriangle::calculateCircumradius() const {
    double hypotenuse = sqrt(a * a + b * b);  
    return hypotenuse / 2.0;  
}