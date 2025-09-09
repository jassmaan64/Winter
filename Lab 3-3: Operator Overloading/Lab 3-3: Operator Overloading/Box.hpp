//----------------------------
//          Box
//----------------------------
//- length : double
//- width : double
//- height : double
//----------------------------
//+ Box(double,double,double)
//+ volume() : double
//+ setLength(double): void
//+ setWidth(double): void
//+ setHeight(double): void
//+ getLength(): double
//+ getWidth(): double
//+ getHeight(): double
//+ operator==(Box) : void
//+ operator>(Box) : void
//+ operator<(Box) : void
//+ operator>=(Box) : void
//+ operator<=(Box) : void
//----------------------------

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;
public:
    // Constructor definitions
    Box(){length=width=height= 2.0;}
    Box(double, double, double);
    //volume(): to get volume
    //Arguments: none | Returns: double
    double volume() { return length * width * height; }
    void setLength(double);
    void setWidth(double);
    void setHeight(double);
    double getLength(){return length;}
    double getWidth(){return width;}
    double getHeight(){return height;}
    void operator==(Box);
    void operator>(Box);
    void operator<(Box);
    void operator>=(Box);
    void operator<=(Box);
};


#endif /* Box_hpp */
