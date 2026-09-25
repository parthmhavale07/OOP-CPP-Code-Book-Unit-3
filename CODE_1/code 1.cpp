#include <iostream>
#include <string>
using namespace std;

int add(int first, int second)
{
    return first + second;
}

double add(double first, double second)
{
    return first + second;
}

int add(int first, int second, int third)
{
    return first + second + third;
}

string add(string first, string second)
{
    return first + second;
}

int main()
{
    cout << "Sum of two integers: " << add(10, 20) << endl;
    cout << "Sum of two doubles: " << add(2.5, 3.7) << endl;
    cout << "Sum of three integers: " << add(10, 20, 30) << endl;
    cout << "Joined strings: " << add("Hello ", "World") << endl;

    return 0;
}
