#pragma once
#include <stdexcept>
#include <sstream>
#include <initializer_list>
#include <string> 

/**
 * @class CircularList
 * @brief Реализация циклического односвязного списка 
 */
class CircularList {
private:
    /**
     * @brief Внутренняя структура для хранения элементов списка
     */
    struct Node {
        int data;       
        Node* next;     
        
        /**
         * @brief Конструктор узла
         * @param value Значение для хранения в узле
         */
        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;   
    size_t size;  

    /**
     * @brief Внутренний метод для копирования данных из другого списка
     * @param other Список для копирования
     */
    void copyFrom(const CircularList& other);

public:
    /**
     * @brief Конструктор по умолчанию
     * @details Создает пустой список
     */
    CircularList();

    /**
     * @brief Конструктор из списка инициализации
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

    /**
     * @brief Деструктор
     */
    ~CircularList();

    /**
     * @brief Оператор присваивания копированием
     * @param other Список
     * @return Ссылка на текущий список
     */
    CircularList& operator=(const CircularList& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Список
     * @return Ссылка на текущий список
     */
    CircularList& operator=(CircularList&& other) noexcept;

    /**
     * @brief Оператор вставки 
     * @param value Значение для добавления
     * @return Ссылка на текущий список
     */
    CircularList& operator<<(int value);

    /**
     * @brief Оператор извлечения 
     * @return Удаленное значение
     */
    int operator>>(int dummy);

    /**
     * @brief Проверка списка на пустоту
     * @return true если список пуст, false в противном случае
     */
    bool isEmpty() const;

    /**
     * @brief Получение текущего размера списка
     * @return Количество элементов в списке
     */
    size_t getSize() const;

    /**
     * @brief Строковое представление списка
     * @return Строка формата 
     */
    std::string toString() const;

    /**
     * @brief Добавление элемента в начало списка
     * @param value Значение для добавления
     */
    void prepend(int value);

    /**
     * @brief Добавление элемента в конец списка
     * @param value Значение для добавления
     */
    void append(int value);

    /**
     * @brief Удаление элемента из начала списка
     * @return Удаленное значение
     */
    int removeFirst();

    /**
     * @brief Очистка списка
     */
    void clear();
};