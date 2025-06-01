#include <iostream>
#include "RightTriangle.h"
int main() {
    try {
        
        RightTriangle triangle(3.0, 4.0);
        std::cout << triangle.toString() << std::endl;
        std::cout << "Площадь: " << triangle.calculateArea() << std::endl;
        std::cout << "Гипотенуза: " << triangle.calculateHypotenuse() << std::endl;
        std::cout << "Радиус описанной окружности: " 
                  << triangle.calculateCircumradius() << std::endl;
        RightTriangle invalidTriangle(-1, 0); 
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}