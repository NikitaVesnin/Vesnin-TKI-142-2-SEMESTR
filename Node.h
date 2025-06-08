#pragma once
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