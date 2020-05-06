#include "point.h"
#include <cmath>
point::point()
{
    //ctor
}

point::point(int x,int y)
{
    this->x=x;
    this->y=y;
}

bool point::inCircle(point x, point c,point r)
{
    int rad=sqrt(pow((c.y-r.y),2)+pow((c.x-r.x),2));
    rad*=rad;

    int xDiff=x.x-c.x;
    xDiff*=xDiff;

    int yDiff=x.y-c.y;
    yDiff*=yDiff;

    yDiff+=xDiff;

    return yDiff<rad;


}
