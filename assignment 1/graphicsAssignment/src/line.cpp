#include "point.h"
#include "line.h"
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include<bits/stdc++.h>
#include "point.h"
#include "line.h"
#include "circle.h"
using namespace std;
line::line()
{
    //ctor
}
line::line(point a,point b){
    this->a.x=a.x;
    this->a.y=a.y;

    this->b.x=b.x;
    this->b.y=b.y;
}
void line::draw(HDC hdc,point a, point b,COLORREF color){
    int dx=b.x-a.x;
    int dy=b.y-a.y;
    SetPixel(hdc,a.x,a.y,color);
    if(abs(dx)>=abs(dy))
    {
        int x=a.x;
        int incrementX;
        if(dx>0)
            incrementX=1;
        else
            incrementX=-1;

        double y=a.y;
        double incrementY=(double)dy/dx*incrementX;
        while(x!=b.x){
            x+=incrementX;
            y+=incrementY;
            SetPixel(hdc,x,round(y),color);
        }
    }
    else
    {
        int y=a.y;
        int incrementY;
        if( dy>0)
            incrementY= 1;
        else
            incrementY=-1;
        double x=a.x;
        double incrementX=(double)dx/dy*incrementY;
        while(y!=b.y)
        {
            x+=incrementX;
            y+=incrementY;
            SetPixel(hdc,round(x),y,color);
        }
    }
}
int line::length(point a,point b)
{
    return sqrt(pow((a.y-b.y),2)+pow((a.x-b.x),2));

}
