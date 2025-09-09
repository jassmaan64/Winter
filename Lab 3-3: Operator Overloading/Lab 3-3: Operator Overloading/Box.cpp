
#include "Box.hpp"
Box:: Box( double l, double w, double h)
{
    if(l<1.0)l=1.0;
        length=l;
    if(w<1.0)w=1.0;
        width=w;
    if(h<1.0)h=1.0;
        height=h;
}
//setLength(): to set length
//Arguments: double | Returns: none
void Box:: setLength(double l)
{
    if(l<1.0)l=1.0;
        length=l;
}
//setWidth(): to set width
//Arguments: double | Returns: none
void Box:: setWidth(double l)
{
    if(l<1.0)l=1.0;
        width=l;
}
//setHeight(): to set height
//Arguments: double | Returns: none
void Box:: setHeight(double l)
{
    if(l<1.0)l=1.0;
        height=l;
}
//operator==(): overloding operator
//Arguments: box | Returns: none
void Box:: operator==(Box b)
{
    bool vol= false;
    if((b.length*b.width*b.height)==(length*width*height))
        vol=true;
    if(vol == true)cout << "true";
    else
        cout << "false";
}
//operator>(): overloding operator
//Arguments: box | Returns: none
void Box:: operator>(Box b)
{
    bool vol= false;
    if((b.length*b.width*b.height)<(length*width*height))
        vol=true;
    if(vol == true)cout << "true";
    else
        cout << "false";
}
//operator<(): overloding operator
//Arguments: box | Returns: none
void Box:: operator<(Box b)
{
    bool vol= false;
    if((b.length*b.width*b.height)>(length*width*height))
        vol=true;
    if(vol == true)cout << "true";
    else
        cout << "false";
}
//operator>=(): overloding operator
//Arguments: box | Returns: none
void Box:: operator>=(Box b)
{
    bool vol= false;
    if((length>b.length)and(width>b.width)and(height>b.height))vol=true;
    else if((length==b.length)and(width==b.width)and(height==b.height))vol=true;
    if(vol == true)cout << "true";
    else
        cout << "false";
}
//operator<=(): overloding operator
//Arguments: box | Returns: none
void Box:: operator<=(Box b)
{
    bool vol= false;
    if((length<b.length)and(width<b.width)and(height<b.height))vol=true;
    else if((length==b.length)and(width==b.width)and(height==b.height))vol=true;
    if(vol == true)cout << "true";
    else
        cout << "false";
}
