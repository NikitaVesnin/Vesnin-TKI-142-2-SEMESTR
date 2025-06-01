#include "Hexagon.h"
#include <iostream>
/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении, 1 при ошибке
 */
int main() {
    try {
        std::vector<Point> points = {
            Point(1, 0),
            Point(0.5, sqrt(3)/2),
            Point(-0.5, sqrt(3)/2),
            Point(-1, 0),
            Point(-0.5, -sqrt(3)/2),
            Point(0.5, -sqrt(3)/2)
        };
        
        Hexagon h1(points);
        std::cout << h1 << std::endl;
        std::cout << "Area: " << h1.Area() << std::endl;
        std::cout << "Perimeter: " << h1.Perimeter() << std::endl;
        std::cout << "Circumradius: " << h1.Circumradius() << std::endl;
        
        std::cout << "Enter 6 points (x y) for hexagon: ";
        Hexagon h2;
        std::cin >> h2;
        std::cout << h2 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}