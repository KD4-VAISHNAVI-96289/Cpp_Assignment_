#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(void) : day(0), month(0), year(0)
    {
    }
    Date(int day, int month, int year) : day(day), month(month), year(year)
    {
    }
    void acceptDate(void)
    {
        cout << "Day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;
    }
    void displayDate(void)
    {
        cout << day << "/" << month << "/" << year;
    }
};
class Person
{
private:
    string name;
    string address;
    Date birthdate;

public:
    Person(void) : name(""), address("")
    {
    }
    Person(string name, string address,int day, int month, int year) : name(name), address(address), birthdate(day, month, year)
    {
    }
    void accceptPerson(void)
    {
        cout << "Name: ";
        cin >> name;
        cout << "Address: ";
        cin >> address;
        cout << "BirthDate: ";
        this->birthdate.acceptDate();
    }
    void displayPerson(void)
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "BirthDate: ";
        this->birthdate.displayDate();
    }
};

class Student{
    private:
    int student_Id;
    int marks;
    public:
    string course;
    Date joindate;
    Date End_date;
    Student( void ) : student_Id(0), marks(0),course("")
    {  }
    Student(int student_Id, int marks, string course, int sd, int sm, int sy,int ed, int em, int ey) : student_Id(student_Id), marks(marks), course(course), joindate(sd, sm, sy), End_date(ed, em, ey)
    {  }
    void acceptstudent( void )
    {
        cout<<"Students Id: ";
        cin>>student_Id;
        cout<<"marks: ";
        cin>>marks;
        cout<<"course: ";
        cin>>course;
        cout<<"Joindate: ";
        this->joindate.acceptDate();
        cout<<"EndDate: ";
        this->End_date.acceptDate();
    }
    void displayStudent( void )
    {
        cout<<"Student Id: "<<student_Id<<endl;
        cout<<"marks: "<<marks<<endl;
        cout<<"course: "<<course<<endl;
        cout<<"Join Date: ";
        this->joindate.displayDate();
        cout<<"End Date: ";
        cout<<endl;
        this->joindate.displayDate();
    } 
};
int main()
{
    // Student s1(123, 95, "Dac", 25, 02, 2026,31,07,2026);
    // s1.displayStudent();
    Student s2;
    s2.acceptstudent( );
    s2.displayStudent( );
    return 0;
}
int main1()
{
    // Person p1("Vai","Satara",18,02,2003);
    // p1.displayPerson( );
    Person p2;
    p2.accceptPerson( );
    p2.displayPerson( );
    return 0;
}