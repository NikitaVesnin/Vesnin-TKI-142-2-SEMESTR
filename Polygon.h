#pragma once
#include <string>
#include <vector>
#include "Point.h"
class Polygon {
public:
    virtual ~Polygon() = default;
    /**
     * @brief Преобразование в строку
     * @return Строковое представление многоугольника
     */
    virtual std::string ToString() const = 0;
    /**
     * @brief Вычисление площади
     * @return Площадь многоугольника
     */
    virtual double Area() const = 0;
    /**
     * @brief Вычисление периметра
     * @return Периметр многоугольника
     */
    virtual double Perimeter() const = 0;
    /**
     * @brief Вычисление радиуса описанной окружности
     * @return Радиус описанной окружности
     */
    virtual double Circumradius() const = 0;
     /**
     * @brief Чтение из потока
     * @param is Входной поток
     */
    virtual void Read(std::istream& is) = 0;
    
    friend std::istream& operator>>(std::istream& is, Polygon& p);
    friend std::ostream& operator<<(std::ostream& os, const Polygon& p);
};