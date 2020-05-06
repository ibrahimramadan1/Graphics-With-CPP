#ifndef CURVE_H
#define CURVE_H
#include <tchar.h>
#include <windows.h>
#include<bits/stdc++.h>
#include "point.h"
using namespace std;
class Vector4
{
    double v[4];
public:
    Vector4(double a=0,double b=0,double c=0,double d=0)
    {
        v[0]=a;
        v[1]=b;
        v[2]=c;
        v[3]=d;
    }
    Vector4(double a[])
    {
        memcpy(v,a,4*sizeof(double));
    }
    double& operator[](int i)
    {
        return v[i];
    }
};
class Matrix4
{
    Vector4 M[4];
public:
    Matrix4(double A[])
    {
        memcpy(M,A,16*sizeof(double));
    }
    Vector4& operator[](int i)
    {
        return M[i];
    }


};
class curve
{
public:
    curve();

    double DotProduct(Vector4& a,Vector4& b);
    Vector4 GetHermiteCoeff(double x0,double s0,double x1,double s1);
    void DrawHermiteCurve(HDC hdc,point& P0,point& T0,point& P1,point& T1,int numpoints,point c,point r);
    void DrawBezierCurve(HDC hdc,point& P0,point& P1,point& P2,point& P3,int numpoints,point c,point r);
    void draw(HDC hdc,point& P0,point& P1,point& P2,point& P3,point c,point r);
    virtual ~curve();

protected:

private:
};

#endif // CURVE_H
