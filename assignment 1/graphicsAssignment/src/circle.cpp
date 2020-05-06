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

void circle::points(HDC hdc,point p,int a, int b)
{
    SetPixel(hdc, p.x+a, p.y+b, RGB(255,0,0));
    SetPixel(hdc, p.x-a, p.y+b, RGB(0,255,0));
    SetPixel(hdc, p.x-a, p.y-b, RGB(0,0,255));
    SetPixel(hdc, p.x+a, p.y-b, RGB(255,255,0));
    SetPixel(hdc, p.x+b, p.y+a, RGB(255,0,0));
    SetPixel(hdc, p.x-b, p.y+a, RGB(0,255,0));
    SetPixel(hdc, p.x-b, p.y-a, RGB(0,0,255));
    SetPixel(hdc, p.x+b, p.y-a, RGB(255,255,0));
}
void circle::draw(HDC hdc,point p, int R)
{

    int x=0,y=R;
    int d=1-R;
    points(hdc,p,x,y);
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
        points(hdc,p,x,y);
    }
}
