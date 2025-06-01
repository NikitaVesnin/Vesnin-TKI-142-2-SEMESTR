#include "CircularList.h"
#include "Node.h"
#include <sstream>
#include <stdexcept>

CircularList::CircularList() : head(nullptr), size(0) {}

CircularList::CircularList(std::initializer_list<int> init) : CircularList() {
    for (int value : init) {
        insert(value);
    }
}

CircularList::CircularList(const CircularList& other) : CircularList() {
    if (other.head) {
        Node* current = other.head;
        do {
            insert(current->data);
            current = current->next;
        } while (current != other.head);
    }
}

CircularList::CircularList(CircularList&& other) noexcept 
    : head(other.head), size(other.size) {
    other.head = nullptr;
    other.size = 0;
}

CircularList::~CircularList() {
    clear();
}

void CircularList::clear() {
    if (!head) return;
    
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
    size = 0;
}

CircularList& CircularList::operator=(const CircularList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        if (current) {
            do {
                insert(current->data);
                current = current->next;
            } while (current != other.head);
        }
    }
    return *this;
}

CircularList& CircularList::operator=(CircularList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        size = other.size;
        other.head = nullptr;
        other.size = 0;
    }
    return *this;
}

bool CircularList::isEmpty() const {
    return size == 0;
}

size_t CircularList::getSize() const {
    return size;
}

std::string CircularList::toString() const {
    std::ostringstream oss;
    if (!head) return "[]";
    
    Node* current = head;
    oss << "[";
    do {
        oss << current->data;
        if (current->next != head) oss << ", ";
        current = current->next;
    } while (current != head);
    oss << "]";
    return oss.str();
}

void CircularList::insert(int value) {
    Node* newNode = new Node(value);
    
    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    size++;
}

void CircularList::remove(int value) {
    if (!head) return;
    
    Node* current = head;
    Node* prev = nullptr;
    
    do {
        if (current->data == value) {
            if (current == head && head->next == head) {
                delete head;
                head = nullptr;
            } else {
                if (current == head) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = current->next;
                }
                delete current;
            }
            size--;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
}

bool CircularList::contains(int value) const {
    if (!head) return false;
    
    Node* current = head;
    do {
        if (current->data == value) return true;
        current = current->next;
    } while (current != head);
    
    return false;
}