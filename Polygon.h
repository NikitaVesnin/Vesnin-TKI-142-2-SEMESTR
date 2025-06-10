#pragma once
#include <vector>
#include <string>
#include "Point.h"

class Polygon {
protected:
    std::vector<Point> vertices;

public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Polygon() = default;

    /**
     * @brief Получить количество вершин
     * @return Количество вершин
     */
    size_t getVertexCount() const;

    /**
     * @brief Получить вершины многоугольника
     * @return Вектор вершин
     */
    const std::vector<Point>& getVertices() const;

    /**
     * @brief Виртуальный метод вычисления периметра
     * @return Периметр многоугольника
     */
    virtual double calculatePerimeter() const = 0;

    /**
     * @brief Виртуальный метод вычисления площади
     * @return Площадь многоугольника
     */
    virtual double calculateArea() const = 0;

    /**
     * @brief Виртуальный метод вычисления радиуса описанной окружности
     * @return Радиус описанной окружности
     */
    virtual double calculateCircumradius() const = 0;

    /**
     * @brief Виртуальный метод преобразования в строку
     * @return Строковое представление многоугольника
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Виртуальный метод чтения из потока
     * @param is Входной поток
     */
    virtual void read(std::istream& is) = 0;

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param polygon Многоугольник для ввода
     * @return Поток после ввода
     */
    friend std::istream& operator>>(std::istream& is, Polygon& polygon);

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param polygon Многоугольник для вывода
     * @return Поток после вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);
};