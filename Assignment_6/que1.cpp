#include<iostream>
using namespace std;
class Product
{
    protected:
    int id;
    string title;
    double price;
    public:
    Product( void ) :id(0), title(" "), price(0.0)
    {  }
    virtual void acceptRecord( void )
    {
        cout<<"Id: ";
        cin>>id;
        cout<<"Title: ";
        cin>>title;
        cout<<"Price: ";
        cin>>price;
    }
    virtual void printRecord( void )
    {
        cout<<"Id: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }
    virtual double CalculateBill(void)=0;

};
class Book : public Product
{
    protected:
    string author;
    public:
    Book( void ) : author("")
    { }
    void acceptRecord( void )
    {
        Product::acceptRecord( );
        cout<<"Author: ";
        cin>>author; 
    }
    void printRecord( void )
    {
        Product::printRecord( );
        cout<<"Author: "<<author<<endl;
    }
    double CalculateBill(void)
    {
        return price - (price * 0.10);
    }
};
class Tape : public Product
{
    private:
    string artist;
    public:
    Tape( void ) : artist("")
    { }
    void acceptRecord( void )
    {  
        Product::acceptRecord( );
        cout<<"Artist: ";
        cin>>artist;
    }
    void printRecord( void )
    {
        Product::printRecord( );
        cout<<"Artist: "<<artist<<endl;
    } 
    double CalculateBill(void)
    {
        return price - (price * 0.5);
    }

};

int MenuList(){
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1.Book"<<endl;
    cout<<"2.Tape"<<endl;
    cout<<"3.Display and Total Bill: "<<endl;
    cout<<"Enter choce: ";
    cin>>choice;
    return choice;
}
int main()
{

    
    int choice;
    int index = 0;
    Product* arr[3];
    while((choice=MenuList())!=0)
    {
         
        
        switch (choice)
        {
        case 1:
            arr[index] = new Book();
            arr[index]->acceptRecord();
            index ++;
            break;
        
        case 2:
            arr[index] = new Tape();
            arr[index]->acceptRecord();
            index ++;
            break;

        case 3:
            double total;
            for(int i=0;i<index;i++)
            {
               arr[i]->printRecord( );
               total += arr[i]->CalculateBill( );
            }
            cout<<"The total bill is : "<<total<<endl;
        }
    }
    for(int i; i<3 ; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}