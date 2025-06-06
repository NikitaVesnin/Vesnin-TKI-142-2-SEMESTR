#include <iostream>
#include "CircularList.h"

int main() {
    try {
        
        CircularList list1 = {1, 2, 3, 4, 5};
        std::cout << "list1: " << list1.toString() << std::endl;

        
        std::cout << "list1 пуст? " << (list1.isEmpty() ? "Да" : "Нет") << std::endl;

        
        list1 << 0 << -1;
        std::cout << "list1 после добавления 0 и -1: " << list1.toString() << std::endl;

        
        int removed = list1 >> 0;
        std::cout << "Удален элемент: " << removed << std::endl;
        std::cout << "list1 после удаления: " << list1.toString() << std::endl;

        
        CircularList list2 = list1;
        std::cout << "list2 (копия list1): " << list2.toString() << std::endl;

        
        CircularList list3;
        list3 = list2;
        std::cout << "list3 (присвоен list2): " << list3.toString() << std::endl;

        
        CircularList list4 = std::move(list3);
        std::cout << "list4 (перемещен из list3): " << list4.toString() << std::endl;
        std::cout << "list3 после перемещения: " << list3.toString() << std::endl;

        
        list4.clear();
        std::cout << "list4 после очистки: " << list4.toString() << std::endl;
        std::cout << "list4 пуст? " << (list4.isEmpty() ? "Да" : "Нет") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}