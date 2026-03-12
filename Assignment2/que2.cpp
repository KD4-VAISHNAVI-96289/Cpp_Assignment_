#include<iostream>
using namespace std;

class Toolboth{
    unsigned int total_car;
    int paying_car;
    int NotPaying_car;
    double Total_cash;
    public:
    Toolboth(void){
        total_car =0;
        paying_car = 0;
        NotPaying_car = 0;
        Total_cash = 0;
    }

    void Paying_car(void){
        total_car++;
        paying_car++;
        Total_cash +=0.50;
    }

    void NoPayCar(void)
    {
        total_car++;
        NotPaying_car++;
    }

    void printOnConsole(){
        cout<<total_car<<endl;
        cout<<paying_car<<endl;
        cout<<NotPaying_car<<endl;
        cout<<Total_cash<<endl;
    }
    
};

int main()
{
    Toolboth t1;
    t1.Paying_car();
    t1.Paying_car();
    t1.NoPayCar();
    t1.Paying_car();
    t1.printOnConsole();

    return 0;
}