/**
 * @file RightTriangle.h
 * @brief Заголовочный файл класса RightTriangle
 */
#pragma once
/**
 * @class RightTriangle
 * @brief Класс прямоугольного треугольника
 */
class RightTriangle {
private:
    double a; 
    double b; 

    /**
     * @brief Проверка валидности сторон треугольника
     * @throw std::invalid_argument Если катеты неположительные
     */
    void validateSides() const;

public:
    /**
     * @brief Конструктор по умолчанию
     * 
     * Создает треугольник с катетами 1 и 1
     */
    RightTriangle();

    /**
     * @brief Основной конструктор
     * @param cathetusA Первый катет
     * @param cathetusB Второй катет
     * @throw std::invalid_argument Если катеты неположительные
     */
    RightTriangle(double cathetusA, double cathetusB);

    /**
     * @brief Получить первый катет
     * @return Длина первого катета
     */
    double getA() const;

    /**
     * @brief Получить второй катет
     * @return Длина второго катета
     */
    double getB() const;

    /**
     * @brief Вычислить площадь треугольника
     * @return Площадь 
     */
    double calculateArea() const;

    /**
     * @brief Вычислить гипотенузу
     * @return Длина гипотенузы 
     */
    double calculateHypotenuse() const;

    /**
     * @brief Вычислить радиус описанной окружности
     * @return Радиус 
     */
    double calculateCircumradius() const;

    /**
     * @brief Преобразовать в строку
     * @return Строковое представление треугольника
     */
    std::string toString() const;
};