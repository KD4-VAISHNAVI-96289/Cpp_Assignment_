#include<iostream>
using namespace std;
class Volume{
    private:
    int length;
    int width;
    int height;

public: 
    Volume( void ){
       this->length= 10;
       this->width = 20;
       this->height = 30;  
          
    }
    Volume (int value)
    { 
        this-> length = value;
        this-> width = value;
        this-> height = value;
        
    }
    Volume (int length, int width, int heigth)
    {
        this->length = length;
        this->width = width;
        this->height = heigth;
        
    }

    void printRecord( void )
    {
       cout<<"Volume: "<<this->length<<"* "<<this->width<<"* "<<this->height<<"* "<<"= "<<endl;
       cout<<"volume: "<<this->length * this->width * this->height<<endl;
    }
};
int menuList(void)
{
    int choice;
    printf("0.Exit.\n");
    printf("1.initDate.\n");
    printf("2.acceptDateOnConsole.\n");
    printf("3.printDateOnConsole.\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int choice;
    while ((choice = menuList())!=0)
    {
        switch (choice)
        {
            case 1:
                   Volume v1;
                   v1.printRecord();
                   break;
            case 2: 
                    Volume v2(10);
                    v2.printRecord();
                    break;
            case 3:
                    Volume v3(10,20 ,30);
                    v3.printRecord();
                    break;
                 
        }
    }
    
    return 0;
}