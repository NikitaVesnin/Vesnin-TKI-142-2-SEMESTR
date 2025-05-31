#include "RightTriangle.h"
#include <iostream>
#include <locale>  

int main() {
    try {
        
        RightTriangle triangle(3.0, 4.0);

        
        std::cout << "Катеты: " << triangle.getA() << " и " << triangle.getB() << std::endl;
        std::cout << "Площадь: " << triangle.calculateArea() << std::endl;
        std::cout << "Радиус описанной окружности: " << triangle.calculateCircumradius() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}