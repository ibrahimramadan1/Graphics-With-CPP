#ifndef CIRCLE_H
#define CIRCLE_H
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
class circle
{
public:
    circle();
    void points(HDC hdc,point p,int a, int b);
    void draw(HDC hdc,point p, int R);
};

#endif // CIRCLE_H
