#include "circle.h"
#include "point.h"
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

circle::circle()
{
    //ctor
}

void circle::points(HDC hdc,point p,point c,point r,int a, int b)
{

    COLORREF blue=RGB(0,0,255);
    COLORREF red=RGB(255,0,0);
    COLORREF color=color;

        color= p.inCircle(point(p.x+a, p.y+b),c,r)?blue:red;
        SetPixel(hdc, p.x+a, p.y+b, color);

        color= p.inCircle(point(p.x-a, p.y+b),c,r)?blue:red;
        SetPixel(hdc, p.x-a, p.y+b, color);

        color= p.inCircle(point(p.x-a, p.y-b),c,r)?blue:red;
        SetPixel(hdc, p.x-a, p.y-b, color);

        color= p.inCircle(point(p.x+a, p.y-b),c,r)?blue:red;
        SetPixel(hdc, p.x+a, p.y-b, color);

        color= p.inCircle(point(p.x+b, p.y+a),c,r)?blue:red;
        SetPixel(hdc, p.x+b, p.y+a, color);

        color= p.inCircle(point(p.x-b, p.y+a),c,r)?blue:red;
        SetPixel(hdc, p.x-b, p.y+a, color);

        color= p.inCircle(point(p.x-b, p.y-a),c,r)?blue:red;
        SetPixel(hdc, p.x-b, p.y-a, color);

        color= p.inCircle(point( p.x+b, p.y-a),c,r)?blue:red;
        SetPixel(hdc, p.x+b, p.y-a, color);


}
void circle::draw(HDC hdc,point p,point c,point r, int R)
{

    int x=0,y=R;
    int d=1-R;
    points(hdc,p,c,r,x,y);
    while(x<y)
    {
        if(d<0)
            d+=2*x+2;
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;
        points(hdc,p,c,r,x,y);
    }
}

void circle::framePoints(HDC hdc,point p,int a, int b)
{
        COLORREF color=RGB(0,0,0);
        SetPixel(hdc, p.x+a, p.y+b, color);
        SetPixel(hdc, p.x-a, p.y+b, color);
        SetPixel(hdc, p.x-a, p.y-b, color);
        SetPixel(hdc, p.x+a, p.y-b, color);
        SetPixel(hdc, p.x+b, p.y+a, color);
        SetPixel(hdc, p.x-b, p.y+a, color);
        SetPixel(hdc, p.x-b, p.y-a, color);
        SetPixel(hdc, p.x+b, p.y-a, color);

}

void circle ::frame(HDC hdc,point p,int R)
{
    int x=0,y=R;
    int d=1-R;
    framePoints(hdc,p,x,y);
    while(x<y)
    {
        if(d<0)
            d+=2*x+2;
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;
        framePoints(hdc,p,x,y);
    }

}
