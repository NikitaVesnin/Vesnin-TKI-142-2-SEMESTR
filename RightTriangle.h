#pragma once
#include <cmath>  

class RightTriangle {
private:
    double a;  
    double b;  

public:
    RightTriangle();  
    RightTriangle(double cathet1, double cathetus2);  

    
    double calculateArea() const;          
    double calculateCircumradius() const;  

    double getA() const { return a; }
    double getB() const { return b; }
};