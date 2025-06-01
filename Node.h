#pragma once
/**
 * @class Node
 * @brief Узел циклического односвязного списка
 */
class Node {
public:
    int data;    
    Node* next;
    /**
     * @brief Конструктор узла
     * @param value Значение узла
     * @param nextNode Указатель на следующий узел (по умолчанию nullptr)
     */  
    explicit Node(int value, Node* nextNode = nullptr);
};