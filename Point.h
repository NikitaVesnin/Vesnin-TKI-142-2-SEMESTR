#pragma once
#include <iostream>
/**
 * @class Point
 * @brief Класс, представляющий точку на плоскости
 */
class Point {
private:
    double x, y;
public:
/**
     * @brief Конструктор точки
     * @param x Координата x 
     * @param y Координата y 
     */
    Point(double x = 0, double y = 0);
    /**
     * @brief Получить координату x
     * @return Координата x
     */
    double getX() const;
    /**
     * @brief Получить координату y
     * @return Координата y
     */
    double getY() const;
    /**
     * @brief Оператор сравнения ==
     * @param other Другая точка для сравнения
     * @return true, если точки равны, иначе false
     */
    bool operator==(const Point& other) const;
    /**
     * @brief Оператор сравнения !=
     * @param other Другая точка для сравнения
     * @return true, если точки не равны, иначе false
     */
    bool operator!=(const Point& other) const;
    /**
     * @brief Оператор ввода >>
     * @param is Поток ввода
     * @param p Точка для ввода
     * @return Поток ввода
     */
    
    friend std::istream& operator>>(std::istream& is, Point& p);
    /**
     * @brief Оператор вывода <<
     * @param os Поток вывода
     * @param p Точка для вывода
     * @return Поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};