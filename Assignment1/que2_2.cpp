#include <iostream>
using namespace std ;
class Date
{
    int day;
    int month;
    int year;
  public:
   void initDate()
   {
     day = 18;
     month = 02;
     year = 2003;
     // printf("Initialized successfully date");
     //printf("Initialized successfully date: %d - %d -%d ",day,month,year);
     cout<<"Initialized successfully date:"<<day<<"-"<<month<<"-"<<year<<endl;
    }
    void acceptDateFromConsole()
    {
      //printf("Enter Day: ");
      cout<<"Enter Day: "<<endl;
      //scanf("%d\n", day);
      cin>>day;
      //printf("Enter month: ");
      cout<<"Enter month: "<<endl;
      //scanf("%d\n", month);
      cin>>month;
      //printf("Enter year: ");
      cout<<"Enter year:"<<endl;
      //scanf("%d\n", year);
      cin>>year;
    }
    void printDateOnConsole()
    {
      //printf("%d - %d - %d ", day,month,year);
      cout<<day<<"-"<<month<<"-"<<year<<endl;
    } 
    };


int menuList(void)
{
    int choice;
    //printf("0.Exit.\n");
    cout<<"0.Exit."<<endl;
    //printf("1.initDate.\n");
    cout<<"1.initDate."<<endl;
    //printf("2.acceptDateOnConsole.\n");
    cout<<"2.acceptDateOnConsole."<<endl;
    //printf("3.printDateOnConsole.\n");
    cout<<"3.printDateOnConsole."<<endl;
    //printf("Enter the choice : ");
    cout<<"Enter the choice : ";
    //scanf("%d\n", &choice);
    cin>>choice;
    return choice;
}
int main()
{
    int choice;
    Date dt;

    while ((choice = menuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            dt.initDate();
            break;
        case 2:
            dt.acceptDateFromConsole();
            break;
        case 3:
            dt.printDateOnConsole();
            break;
        }
    }
    return 0;
}