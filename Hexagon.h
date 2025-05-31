#pragma once
#include "Polygon.h"
#include <vector>

class Hexagon : public Polygon {
private:
    std::vector<Point> vertices;
    
    bool IsValid() const;
    double SideLength() const;
    
public:
    Hexagon();
    Hexagon(const std::vector<Point>& points);
    Hexagon(const std::vector<std::pair<double, double>>& coords);
    
    std::string ToString() const override;
    double Area() const override;
    double Perimeter() const override;
    double Circumradius() const override;
    
    void Read(std::istream& is) override;
    
    bool operator==(const Hexagon& other) const;
    bool operator!=(const Hexagon& other) const;
    
    static Hexagon FromString(const std::string& str);
};