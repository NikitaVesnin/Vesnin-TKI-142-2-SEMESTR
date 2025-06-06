#include "CircularList.h"
#include <stdexcept>
#include <sstream>


Node::Node(int value) : data(value), next(nullptr) {}


CircularList::CircularList() : head(nullptr), size(0) {}

CircularList::CircularList(std::initializer_list<int> initList) : CircularList() {
    for (auto it = initList.end(); it != initList.begin(); ) {
        prepend(*(--it));
    }
}

CircularList::CircularList(const CircularList& other) : CircularList() {
    copyFrom(other);
}

CircularList::CircularList(CircularList&& other) noexcept 
    : head(other.head), size(other.size) {
    other.head = nullptr;
    other.size = 0;
}

CircularList::~CircularList() {
    clear();
}

CircularList& CircularList::operator=(const CircularList& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
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

CircularList& CircularList::operator<<(int value) {
    prepend(value);
    return *this;
}

int CircularList::operator>>(int dummy) {
    return removeFirst();
}

bool CircularList::isEmpty() const {
    return size == 0;
}

size_t CircularList::getSize() const {
    return size;
}

std::string CircularList::toString() const {
    std::ostringstream oss;
    if (isEmpty()) {
        oss << "[]";
    } else {
        oss << "[";
        Node* current = head;
        do {
            oss << current->data;
            if (current->next != head) {
                oss << ", ";
            }
            current = current->next;
        } while (current != head);
        oss << "]";
    }
    return oss.str();
}

void CircularList::prepend(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        head = newNode;
    }
    size++;
}

int CircularList::removeFirst() {
    if (isEmpty()) {
        throw std::runtime_error("Список пуст");
    }

    int value = head->data;
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Node* toDelete = head;
        head = head->next;
        last->next = head;
        delete toDelete;
    }
    size--;
    return value;
}

void CircularList::clear() {
    while (!isEmpty()) {
        removeFirst();
    }
}

void CircularList::copyFrom(const CircularList& other) {
    if (!other.isEmpty()) {
        Node* current = other.head;
        do {
            prepend(current->data);
            current = current->next;
        } while (current != other.head);
        
        CircularList temp;
        while (!isEmpty()) {
            temp.prepend(removeFirst());
        }
        *this = std::move(temp);
    }
}