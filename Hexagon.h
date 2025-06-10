#pragma once
#include "Polygon.h"
#include <initializer_list>

class Hexagon : public Polygon {
private:
    double sideLength; 

    /**
     * @brief Проверить валидность вершин для правильного шестиугольника
     * @throw std::invalid_argument Если вершины не образуют правильный шестиугольник
     */
    void validateVertices() const;

    /**
     * @brief Вычислить длину стороны по вершинам
     * @return Длина стороны
     */
    double calculateSideLength() const;

public:
    /**
     * @brief Конструктор по умолчанию
     * @details Создает шестиугольник с центром в (0,0) и стороной 1
     */
    Hexagon();

    /**
     * @brief Конструктор по центру и длине стороны
     * @param center Центр шестиугольника
     * @param sideLength Длина стороны
     * @throw std::invalid_argument Если длина стороны не положительна
     */
    Hexagon(const Point& center, double sideLength);

    /**
     * @brief Конструктор по списку вершин
     * @param vertices Список вершин (должно быть 6 точек)
     * @throw std::invalid_argument Если вершин не 6 или они не образуют правильный шестиугольник
     */
    Hexagon(const std::vector<Point>& vertices);

    /**
     * @brief Конструктор по списку инициализации точек
     * @param initList Список инициализации точек
     */
    Hexagon(std::initializer_list<Point> initList);

    /**
     * @brief Получить длину стороны
     * @return Длина стороны
     */
    double getSideLength() const;

    /**
     * @brief Вычислить периметр
     * @return Периметр шестиугольника
     */
    double calculatePerimeter() const override;

    /**
     * @brief Вычислить площадь
     * @return Площадь шестиугольника
     */
    double calculateArea() const override;

    /**
     * @brief Вычислить радиус описанной окружности
     * @return Радиус описанной окружности
     */
    double calculateCircumradius() const override;

    /**
     * @brief Преобразовать в строку
     * @return Строковое представление шестиугольника
     */
    std::string toString() const override;

    /**
     * @brief Прочитать шестиугольник из потока
     * @param is Входной поток
     */
    void read(std::istream& is) override;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другой шестиугольник
     * @return true если шестиугольники равны, false иначе
     */
    bool operator==(const Hexagon& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другой шестиугольник
     * @return true если шестиугольники не равны, false иначе
     */
    bool operator!=(const Hexagon& other) const;

    /**
     * @brief Статический метод преобразования в строку
     * @param hexagon Шестиугольник для преобразования
     * @return Строковое представление
     */
    static std::string ToString(const Hexagon& hexagon);

    /**
     * @brief Статический метод чтения из стандартного потока ввода
     * @return Прочитанный шестиугольник
     */
    static Hexagon ReadFromInput();
};