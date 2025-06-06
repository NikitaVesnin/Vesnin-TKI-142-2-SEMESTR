#pragma once
#include <initializer_list>
#include <string>

/**
 * @class Node
 * @brief Класс узла списка
 */
class Node {
public:
    int data;    
    Node* next;  

    /**
     * @brief Конструктор узла
     * @param value Значение узла
     */
    explicit Node(int value);
};

/**
 * @class CircularList
 * @brief Класс циклического односвязного списка
 */
class CircularList {
private:
    Node* head;  
    size_t size; 
public:
    /**
     * @brief Конструктор по умолчанию
     */
    CircularList();

    /**
     * @brief Конструктор с списком инициализации
     * @param initList Список инициализации
     */
    CircularList(std::initializer_list<int> initList);

    /**
     * @brief Конструктор копирования
     * @param other Список для копирования
     */
    CircularList(const CircularList& other);

    /**
     * @brief Конструктор перемещения
     * @param other Список для перемещения
     */
    CircularList(CircularList&& other) noexcept;

    ~CircularList();

    /**
     * @brief Оператор присваивания копированием
     * @param other Список для копирования
     * @return Ссылка на текущий список
     */
    CircularList& operator=(const CircularList& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Список для перемещения
     * @return Ссылка на текущий список
     */
    CircularList& operator=(CircularList&& other) noexcept;

    /**
     * @brief Оператор сдвига влево (добавление элемента)
     * @param value Значение для добавления
     * @return Ссылка на текущий список
     */
    CircularList& operator<<(int value);

    /**
     * @brief Оператор сдвига вправо (удаление элемента)
     * @param dummy Фиктивный параметр
     * @return Удаленное значение
     */
    int operator>>(int dummy);

    /**
     * @brief Проверка на пустоту списка
     * @return true если список пуст, false иначе
     */
    bool isEmpty() const;

    /**
     * @brief Получение размера списка
     * @return Размер списка
     */
    size_t getSize() const;

    /**
     * @brief Преобразование списка в строку
     * @return Строковое представление списка
     */
    std::string toString() const;

    /**
     * @brief Добавление элемента в начало списка
     * @param value Значение для добавления
     */
    void prepend(int value);

    /**
     * @brief Удаление элемента из начала списка
     * @return Удаленное значение
     * @throw std::runtime_error если список пуст
     */
    int removeFirst();

    /**
     * @brief Очистка списка
     */
    void clear();

private:
    /**
     * @brief Копирование списка
     * @param other Список для копирования
     */
    void copyFrom(const CircularList& other);
};