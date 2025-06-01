// CircularList.h - Заголовочный файл класса CircularList
#pragma once
#include <initializer_list>
#include <string>

class Node;

/**
 * @class CircularList
 * @brief Циклический односвязный список целых чисел
 */
class CircularList {
private:
    Node* head;     // Указатель на голову списка
    size_t size;    // Размер списка

    /**
     * @brief Очистка списка
     */
    void clear();

public:
    /**
     * @brief Конструктор по умолчанию
     */
    CircularList();
    /**
     * @brief Конструктор со списком инициализации
     * @param init Список инициализации
     */
    CircularList(std::initializer_list<int> init);
    /**
     * @brief Конструктор копирования
     * @param other Копируемый список
     */
    CircularList(const CircularList& other);
    /**
     * @brief Конструктор перемещения
     * @param other Перемещаемый список
     */
    CircularList(CircularList&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~CircularList();
    
    /**
     * @brief Оператор присваивания копированием
     * @param other Присваиваемый список
     * @return Ссылка на текущий список
     */
    CircularList& operator=(const CircularList& other);
    /**
     * @brief Оператор присваивания перемещением
     * @param other Перемещаемый список
     * @return Ссылка на текущий список
     */
    CircularList& operator=(CircularList&& other) noexcept;
    /**
     * @brief Проверка на пустоту
     * @return true если список пуст, иначе false
     */
    bool isEmpty() const;
     /**
     * @brief Получение размера списка
     * @return Количество элементов в списке
     */
    size_t getSize() const;
    /**
     * @brief Преобразование в строку
     * @return Строковое представление списка
     */
    std::string toString() const;
    /**
     * @brief Вставка элемента в конец списка
     * @param value Вставляемое значение
     */
    
    void insert(int value);
    /**
     * @brief Удаление элемента по значению
     * @param value Удаляемое значение
     */
    void remove(int value);
    /**
     * @brief Проверка наличия элемента
     * @param value Искомое значение
     * @return true если элемент найден, иначе false
     */
    bool contains(int value) const;
};