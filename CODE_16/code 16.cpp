#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Employee
{
protected:
    int employeeId;
    string name;

public:
    Employee(int id, string employeeName)
    {
        employeeId = id;
        name = employeeName;
    }

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const
    {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee
{
private:
    double basicSalary;
    double allowance;

public:
    PermanentEmployee(int id, string employeeName,
                      double basic, double extra)
        : Employee(id, employeeName)
    {
        basicSalary = basic;
        allowance = extra;
    }

    double calculateSalary() const override
    {
        double grossSalary = basicSalary + allowance;

        double tax = grossSalary * 0.10;

        return grossSalary - tax;
    }
};

class ContractEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, string employeeName,
                     double rate, int hours)
        : Employee(id, employeeName)
    {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }
};

class FreelanceEmployee : public Employee
{
private:
    double projectAmount;

public:
    FreelanceEmployee(int id, string employeeName,
                      double amount)
        : Employee(id, employeeName)
    {
        projectAmount = amount;
    }

    double calculateSalary() const override
    {
        return projectAmount;
    }
};

void printPaySlip(const Employee& employee)
{
    employee.displayBasicDetails();

    cout << "Salary: Rs. "
         << employee.calculateSalary() << endl;

    cout << endl;
}

int main()
{
    vector<unique_ptr<Employee>> employees;

    employees.push_back(
        make_unique<PermanentEmployee>(
            101, "Asha", 40000.0, 8000.0));

    employees.push_back(
        make_unique<ContractEmployee>(
            102, "Vikas", 500.0, 80));

    employees.push_back(
        make_unique<FreelanceEmployee>(
            103, "Riya", 30000.0));

    double totalPayroll = 0;

    for (const auto& employee : employees)
    {
        printPaySlip(*employee);

        totalPayroll += employee->calculateSalary();
    }

    cout << "Total Payroll: Rs. "
         << totalPayroll << endl;

    return 0;
}
