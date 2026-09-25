#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;

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
};

int main()
{
    Rectangle rectangle(8.0, 4.0);
    Triangle triangle(6.0, 4.0);

    cout << "Rectangle Area: " << rectangle.area() << endl;
    cout << "Triangle Area: " << triangle.area() << endl;

    return 0;
}
