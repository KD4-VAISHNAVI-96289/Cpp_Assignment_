#include<iostream>
using namespace std;

class Time{
      private:
      int h;
      int m;
      int s;

      public:
      Time( void ):h(0), m(0), s(0)
      {  }
      Time(int h,int m, int s): h(h), m(m), s(s)
      {  }
      
      int getHour(void)
      {
        return this->h;
      }
      int getMinute(void)
      {
        return this->m;
      }
      int getSeconds(void)
      {
        return this->s;
      }
      void accceptTime(void)
      {
        cout<<"hrs: ";
        cin>>h;
        cout<<"min: ";
        cin>>m;
        cout<<"sec: ";
        cin>>s;
      }
      void printTime(void)
      {
        cout<<h<<":"<<m<<":"<<s<<endl;
      }
      void setHour(int h){
        this->h = h;
      }
      void setMinute(int m){
         this->m = m;
      }
      void setSeconds(int s){
        this->s = s;
      }
};
int menuList(void)
{
    int choice;
    cout<<"0.Exit."<<endl;
    cout<<"1.Add Time."<<endl;
    cout<<"2.Display All Time"<<endl;
    cout<<"3.Display only hrs of all time objects."<<endl;
    cout<<"Enter the choice : "<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    Time **arr = new Time*[2];
    int choice;
    while ((choice = menuList())!=0)
    {
        switch (choice)
        {
        case 1:
               for(int index = 0; index<2; index++)
                   arr[index]->accceptTime();     
               break;

        case 2:
               for(int index = 0; index<2; index++)
                   arr[index]->printTime();     
               break;
        case 3:
               for(int index = 0; index<2; index++)
                   cout<<arr[index]->getHour( )<<endl;     
               break;
        }
         
    }
    for(int index = 0; index < 2; index++){
        delete arr[index];
        arr[index] = NULL;
    }

    delete[] arr;
    arr = NULL;
    return 0;
}