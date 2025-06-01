#pragma once
#include "Polygon.h"
#include <vector>

class Hexagon : public Polygon {
private:
    std::vector<Point> vertices;
    /**
     * @brief Проверка правильности шестиугольника
     * @return true, если шестиугольник правильный, иначе false
     */
    bool IsValid() const;
    /**
     * @brief Вычисление длины стороны
     * @return Длина стороны шестиугольника
     */
    double SideLength() const;
    
public:
    Hexagon();
    /**
     * @brief Конструктор через вектор точек
     * @param points Вектор из 6 точек
     * @throw std::invalid_argument Если точки не образуют правильный шестиугольник
     */
    Hexagon(const std::vector<Point>& points);
    /**
     * @brief Конструктор через пары координат
     * @param coords Вектор из 6 пар координат
     * @throw std::invalid_argument Если точки не образуют правильный шестиугольник
     */
    Hexagon(const std::vector<std::pair<double, double>>& coords);
    
    std::string ToString() const override;
    double Area() const override;
    double Perimeter() const override;
    double Circumradius() const override;
    void Read(std::istream& is) override;
    /**
     * @brief Оператор сравнения ==
     * @param other Другой шестиугольник
     * @return true, если шестиугольники равны, иначе false
     */
    bool operator==(const Hexagon& other) const;
     /**
     * @brief Оператор сравнения !=
     * @param other Другой шестиугольник
     * @return true, если шестиугольники не равны, иначе false
     */
    bool operator!=(const Hexagon& other) const;
    /**
     * @brief Создание шестиугольника из строки
     * @param str Строка с координатами вершин
     * @return Объект Hexagon
     */
    static Hexagon FromString(const std::string& str);
};