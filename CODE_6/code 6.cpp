#include <iostream>
using namespace std;

class Distance
{
private:
    int meters;

public:
    Distance(int value)
    {
        meters = value;
    }

    bool operator>(const Distance& other) const
    {
        return meters > other.meters;
    }

    bool operator==(const Distance& other) const
    {
        return meters == other.meters;
    }

    void display() const
    {
        cout << meters << " meters" << endl;
    }
};

int main()
{
    Distance first(100);
    Distance second(100);

    cout << "First distance: ";
    first.display();

    cout << "Second distance: ";
    second.display();

    if (first == second)
        cout << "Both distances are equal" << endl;
    else
        cout << "Distances are not equal" << endl;

    return 0;
}
