#pragma once
class CircularList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int value) : data(value), next(nullptr) {}
    };
    
    Node* head; 
};
