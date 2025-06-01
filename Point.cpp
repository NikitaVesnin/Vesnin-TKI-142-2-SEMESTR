#include "Point.h"
/**
 * @brief Конструктор точки
 * @param x Координата x (по умолчанию 0)
 * @param y Координата y (по умолчанию 0)
 */
Point::Point(double x, double y) : x(x), y(y) {}
/**
 * @brief Получение координаты x
 * @return Значение координаты x
 */
double Point::getX() const { return x; }
/**
 * @brief Получение координаты y
 * @return Значение координаты y
 */
double Point::getY() const { return y; }
/**
 * @brief Оператор сравнения на равенство
 * @param other Сравниваемая точка
 * @return true если точки совпадают, false иначе
 */
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}
/**
 * @brief Оператор сравнения на неравенство
 * @param other Сравниваемая точка
 * @return true если точки различаются, false иначе
 */
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
/**
 * @brief Оператор ввода из потока
 * @param is Входной поток
 * @param p Точка для ввода
 * @return Поток после ввода
 */
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
/**
 * @brief Оператор вывода в поток
 * @param os Выходной поток
 * @param p Точка для вывода
 * @return Поток после вывода
 */
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}