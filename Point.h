#pragma once
#include <iostream>
#include <cmath>

class Point {
private:
    double x; 
    double y; 

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Point();

    /**
     * @brief Основной конструктор
     * @param x Координата x
     * @param y Координата y
     */
    Point(double x, double y);

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
     * @brief Вычислить расстояние до другой точки
     * @param other Другая точка
     * @return Расстояние между точками
     */
    double distanceTo(const Point& other) const;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другая точка
     * @return true если точки равны, false иначе
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другая точка
     * @return true если точки не равны, false иначе
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param point Точка для ввода
     * @return Поток после ввода
     */
    friend std::istream& operator>>(std::istream& is, Point& point);

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param point Точка для вывода
     * @return Поток после вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};