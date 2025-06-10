#include <iostream>
#include "Hexagon.h"

Point inputPoint(const std::string& prompt) {
    std::cout << prompt << " (введите x и y через пробел): ";
    double x, y;
    std::cin >> x >> y;
    return Point(x, y);
}

int main() {
    try {
        
        Hexagon hex1;
        std::cout << "\nШестиугольник по умолчанию:\n" << hex1 << std::endl;
        
        Point center = inputPoint("Введите центр шестиугольника");
        double sideLength;
        std::cout << "Введите длину стороны: ";
        std::cin >> sideLength;
        
        Hexagon hex2(center, sideLength);
        std::cout << "\nСозданный шестиугольник:\n" << hex2 << std::endl;
        
        std::cout << "\nВведите 6 вершин шестиугольника (x y для каждой вершины):\n";
        Hexagon hex3 = Hexagon::ReadFromInput();
        std::cout << "\nШестиугольник по вершинам:\n" << Hexagon::ToString(hex3) << std::endl;
        
        std::cout << "hex1 == hex2? " << (hex1 == hex2 ? "Да" : "Нет") << std::endl;
        std::cout << "hex1 != hex3? " << (hex1 != hex3 ? "Да" : "Нет") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}