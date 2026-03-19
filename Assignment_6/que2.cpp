#include <iostream>
#include <typeinfo>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0)
    {
    }
    Employee(int id, double salary) : id(id), salary(salary)
    {
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary(void)
    {
        return this->salary;
    }
    virtual void accept()
    {
        cout << "Id: ";
        cin >> id;
        cout << "Salary: ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

public:
    Manager() : bonus(0.0)
    {
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus)
    {
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return this->bonus;
    }
    void accept()
    {
        Employee ::accept();
        acceptManager();
    }
    void display()
    {
        Employee ::display();
        displayManager();
    }

protected:
    void acceptManager()
    {
        cout << "Bonus";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus: " << bonus << endl;
    }
};
class Salesman : virtual public Employee
{
    double comm;

public:
    Salesman() : comm(0.0)
    {
    }
    Salesman(int id, double salary, double comm) : Employee(id, salary), comm(comm)
    {
    }
    void setCommission(double comm)
    {
        this->comm = comm;
    }
    double getCommission()
    {
        return this->comm;
    }
    void accept()
    {
        Employee ::accept();
        acceptSalesman();
    }
    void display()
    {
        // Employee::display();
        displaySalesman();
    }

protected:
    void acceptSalesman()
    {
        cout << "Commission: ";
        cin >> comm;
    }
    void displaySalesman()
    {
        cout << "Commission: " << comm << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int id, double salary, double bonus, double comm) : Employee(id, salary)
    {
    }
    void accept()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};
int main()
{
    SalesManager s1;
    s1.accept();
    s1.display();
    return 0;
}