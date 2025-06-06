#include "CircularList.h"
#include <cassert>
#include <iostream>

void testEmptyList() {
    CircularList list;
    assert(list.isEmpty());
    assert(list.getSize() == 0);
    assert(list.toString() == "[]");
    std::cout << "testEmptyList passed" << std::endl;
}

void testInitializerList() {
    CircularList list = {1, 2, 3};
    assert(!list.isEmpty());
    assert(list.getSize() == 3);
    assert(list.toString() == "[1, 2, 3]");
    std::cout << "testInitializerList passed" << std::endl;
}

void testPrepend() {
    CircularList list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);
    assert(list.toString() == "[1, 2, 3]");
    assert(list.getSize() == 3);
    std::cout << "testPrepend passed" << std::endl;
}

void testRemoveFirst() {
    CircularList list = {1, 2, 3};
    int val = list.removeFirst();
    assert(val == 1);
    assert(list.toString() == "[2, 3]");
    assert(list.getSize() == 2);
    std::cout << "testRemoveFirst passed" << std::endl;
}

void testCopyConstructor() {
    CircularList list1 = {1, 2, 3};
    CircularList list2 = list1;
    assert(list2.toString() == "[1, 2, 3]");
    list1.removeFirst();
    assert(list2.toString() == "[1, 2, 3]");
    std::cout << "testCopyConstructor passed" << std::endl;
}

void testMoveConstructor() {
    CircularList list1 = {1, 2, 3};
    CircularList list2 = std::move(list1);
    assert(list2.toString() == "[1, 2, 3]");
    assert(list1.isEmpty());
    std::cout << "testMoveConstructor passed" << std::endl;
}

void testAssignmentOperator() {
    CircularList list1 = {1, 2, 3};
    CircularList list2;
    list2 = list1;
    assert(list2.toString() == "[1, 2, 3]");
    list1.removeFirst();
    assert(list2.toString() == "[1, 2, 3]");
    std::cout << "testAssignmentOperator passed" << std::endl;
}

void testMoveAssignmentOperator() {
    CircularList list1 = {1, 2, 3};
    CircularList list2;
    list2 = std::move(list1);
    assert(list2.toString() == "[1, 2, 3]");
    assert(list1.isEmpty());
    std::cout << "testMoveAssignmentOperator passed" << std::endl;
}

void testShiftOperators() {
    CircularList list;
    list << 3 << 2 << 1;
    assert(list.toString() == "[1, 2, 3]");
    int val = list >> 0;
    assert(val == 1);
    assert(list.toString() == "[2, 3]");
    std::cout << "testShiftOperators passed" << std::endl;
}

void testClear() {
    CircularList list = {1, 2, 3};
    list.clear();
    assert(list.isEmpty());
    assert(list.getSize() == 0);
    std::cout << "testClear passed" << std::endl;
}

int main() {
    testEmptyList();
    testInitializerList();
    testPrepend();
    testRemoveFirst();
    testCopyConstructor();
    testMoveConstructor();
    testAssignmentOperator();
    testMoveAssignmentOperator();
    testShiftOperators();
    testClear();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}