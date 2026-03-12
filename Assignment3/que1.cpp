#include<iostream>

using namespace std;
 class Cylinder{
    private:
    double radius;
    double height;
    static double PI;

    public:

    Cylinder( void ) : radius(0) , height(0)
    {   }
    
    Cylinder(double radius, double height): radius(radius) , height(height)
    {   }
    
    double getRadius(void)
    {
        return this->radius;
    }
    void setRadius(double radius)
    {
        this-> radius = radius;
    }

    double getHeight(void)
    {
        return this->height;
    }
    void setHeight(double height)
    {
         this->height=height;
    }

    void CalculateVolume(){
        double VP_Cylinder =  PI * this->radius * this->height; 
        cout<<"Volume of Cylinder : "<<VP_Cylinder<<endl;
    }

 };
 double Cylinder :: PI = 3.14;

 int main()
 {
    Cylinder c1(12,18);
    c1.CalculateVolume();
    return 0;
 }