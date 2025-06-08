#include "CppUnitTest.h"
#include "CircularList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularListTests
{
    TEST_CLASS(CircularListTest)
    {
    public:
        TEST_METHOD(Constructor_EmptyList_IsEmpty)
        {
            CircularList list;
            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), list.getSize());
        }

        TEST_METHOD(Prepend_OneElement_NotEmpty)
        {
            CircularList list;
            list.prepend(42);
            Assert::IsFalse(list.isEmpty());
            Assert::AreEqual(static_cast<size_t>(1), list.getSize());
        }

        TEST_METHOD(RemoveFirst_OneElement_EmptyList)
        {
            CircularList list;
            list.prepend(42);
            int value = list.removeFirst();
            Assert::AreEqual(42, value);
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(RemoveFirst_EmptyList_ThrowsException)
        {
            CircularList list;
            auto func = [&list]() { list.removeFirst(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(InitializerList_Constructor_CorrectOrder)
        {
            CircularList list = {1, 2, 3};
            Assert::AreEqual(1, list.removeFirst());
            Assert::AreEqual(2, list.removeFirst());
            Assert::AreEqual(3, list.removeFirst());
        }

        TEST_METHOD(CopyConstructor_IndependentCopies)
        {
            CircularList list1;
            list1.prepend(10);
            list1.prepend(20);

            CircularList list2(list1);
            list2.removeFirst();

            Assert::AreEqual(static_cast<size_t>(2), list1.getSize());
            Assert::AreEqual(static_cast<size_t>(1), list2.getSize());
        }

        TEST_METHOD(AssignmentOperator_IndependentCopies)
        {
            CircularList list1;
            list1.prepend(10);
            list1.prepend(20);

            CircularList list2;
            list2 = list1;
            list2.removeFirst();

            Assert::AreEqual(static_cast<size_t>(2), list1.getSize());
            Assert::AreEqual(static_cast<size_t>(1), list2.getSize());
        }

        TEST_METHOD(ShiftLeftOperator_AddsElement)
        {
            CircularList list;
            list << 42;
            Assert::AreEqual(42, list.removeFirst());
        }

        TEST_METHOD(ShiftRightOperator_RemovesElement)
        {
            CircularList list;
            list.prepend(42);
            int dummy = 0;
            int value = list >> dummy;
            Assert::AreEqual(42, value);
        }

        TEST_METHOD(ToString_EmptyList_ReturnsEmptyBrackets)
        {
            CircularList list;
            Assert::AreEqual(std::string("[]"), list.toString());
        }

        TEST_METHOD(ToString_NonEmptyList_ReturnsCorrectString)
        {
            CircularList list = {1, 2, 3};
            Assert::AreEqual(std::string("[1, 2, 3]"), list.toString());
        }

        TEST_METHOD(Clear_NonEmptyList_EmptiesList)
        {
            CircularList list = {1, 2, 3};
            list.clear();
            Assert::IsTrue(list.isEmpty());
        }
    };
}