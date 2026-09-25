#include <iostream>
using namespace std;

class Balance
{
private:
    int balance;

public:
    Balance(int value)
    {
        balance = value;
    }

    Balance operator-() const
    {
        return Balance(-balance);
    }

    void display() const
    {
        cout << balance << endl;
    }
};

int main()
{
    Balance first(5000);
    Balance second = -first;

    cout << "Original Balance: ";
    first.display();

    cout << "Negative Balance: ";
    second.display();

    return 0;
}
