#ifndef LINE_H
#define LINE_H
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


class line
{
    public:
        point a,b;
        line();
        line (point a, point b);
        void draw(HDC hdc,point a, point b,COLORREF color);
        int length(point a,point b);
};

#endif // LINE_H
