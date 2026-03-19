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
        cout << "Bonus:";
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
        Employee::display();
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
int MenuList()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Manager" << endl;
    cout << "2.Salesman" << endl;
    cout << "3.SalesManager" << endl;
    cout << "4.Display the count of all employee with respect to designation" << endl;
    cout << "5.Display All Managers: " << endl;
    cout << "6.Display All Salesman: " << endl;
    cout << "7.Display All Sales Manager: " << endl;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int index = 0;
    int m = 0, s = 0, sm = 0;
    Employee *arr[3];
    while ((choice = MenuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            arr[index] = new Manager();
            arr[index]->accept();
            index++;
            m++;
            break;
        case 2:
            arr[index] = new Salesman();
            arr[index]->accept();
            index++;
            s++;
            break;
        case 3:
            arr[index] = new SalesManager();
            arr[index]->accept();
            index++;
            sm++;
            break;
        case 4:

            cout << "Count of Manager: " << m << endl;
            cout << "Count of Salesman: " << s << endl;
            cout << "Count of SalesManager: " << sm << endl;
            break;

        case 5:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
            break;

        case 6:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                }
            }
            break;

        case 7:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                }
            }
            break;
        }
    }
    for (int i = 0; i < index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}