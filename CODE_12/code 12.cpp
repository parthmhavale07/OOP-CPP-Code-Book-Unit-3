#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual void displayName() const = 0;

    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area() const override
    {
        return length * width;
    }

    void displayName() const override
    {
        cout << "Rectangle";
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() const override
    {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    void displayName() const override
    {
        cout << "Circle";
    }
};

class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    double area() const override
    {
        return 0.5 * base * height;
    }

    void displayName() const override
    {
        cout << "Triangle";
    }
};

int main()
{
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(make_unique<Circle>(2.0));
    shapes.push_back(make_unique<Triangle>(6.0, 4.0));

    for (const auto& shape : shapes)
    {
        shape->displayName();
        cout << " Area: " << shape->area() << endl;
    }

    return 0;
}
