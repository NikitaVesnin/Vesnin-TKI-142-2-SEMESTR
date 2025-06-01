// main.cpp - Демонстрационная программа
#include <iostream>
#include "CircularList.h"

int main() {
    // Создание списка разными способами
    CircularList list1 = {1, 2, 3, 4, 5};
    CircularList list2;
    CircularList list3(list1);
    
    std::cout << "List1: " << list1.toString() << std::endl;
    std::cout << "List2 (empty): " << list2.toString() << std::endl;
    std::cout << "List3 (copy of list1): " << list3.toString() << std::endl;
    
    // Добавление элементов
    list2.insert(10);
    list2.insert(20);
    list2.insert(30);
    std::cout << "List2 after insertions: " << list2.toString() << std::endl;
    
    // Удаление элементов
    list1.remove(3);
    std::cout << "List1 after removing 3: " << list1.toString() << std::endl;
    
    // Проверка на наличие элемента
    std::cout << "List1 contains 5? " << (list1.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "List1 contains 10? " << (list1.contains(10) ? "Yes" : "No") << std::endl;
    
    // Проверка на пустоту
    std::cout << "Is list1 empty? " << (list1.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is list2 empty? " << (list2.isEmpty() ? "Yes" : "No") << std::endl;
    
    return 0;
}