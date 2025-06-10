#include "CppUnitTest.h"
#include "Point.h"
#include "Hexagon.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTest
{
    TEST_CLASS(PointTest)
    {
    public:
        TEST_METHOD(Constructor_Default_CreatesOrigin)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }
        
        TEST_METHOD(DistanceTo_SamePoint_ReturnsZero)
        {
            Point p1(1, 2);
            Point p2(1, 2);
            Assert::AreEqual(0.0, p1.distanceTo(p2));
        }
        
        TEST_METHOD(OperatorEquals_EqualPoints_ReturnsTrue)
        {
            Point p1(3, 4);
            Point p2(3, 4);
            Assert::IsTrue(p1 == p2);
        }
    };

    TEST_CLASS(HexagonTest)
    {
    public:
        TEST_METHOD(Constructor_Default_CreatesUnitHexagon)
        {
            Hexagon hex;
            Assert::AreEqual(6ull, hex.getVertexCount());
            Assert::AreEqual(1.0, hex.getSideLength());
        }
        
        TEST_METHOD(Constructor_CenterAndSide_CreatesCorrectHexagon)
        {
            Point center(1, 1);
            Hexagon hex(center, 2.0);
            Assert::AreEqual(2.0, hex.getSideLength());
        }
        
        TEST_METHOD(CalculateArea_UnitHexagon_CorrectArea)
        {
            Hexagon hex;
            double expected = (3 * sqrt(3)) / 2; // ~2.598
            Assert::AreEqual(expected, hex.calculateArea(), 0.0001);
        }
        
        TEST_METHOD(CalculatePerimeter_UnitHexagon_CorrectPerimeter)
        {
            Hexagon hex;
            Assert::AreEqual(6.0, hex.calculatePerimeter());
        }
        
        TEST_METHOD(CalculateCircumradius_UnitHexagon_CorrectRadius)
        {
            Hexagon hex;
            Assert::AreEqual(1.0, hex.calculateCircumradius());
        }
        
        TEST_METHOD(OperatorEquals_EqualHexagons_ReturnsTrue)
        {
            Hexagon hex1;
            Hexagon hex2;
            Assert::IsTrue(hex1 == hex2);
        }
    };
}