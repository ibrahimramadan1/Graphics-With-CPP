#ifndef POINT_H
#define POINT_H

class point
{
    public:
        int x,y;
        point();
        point(int x , int y);
        bool inCircle(point x,point c , point r);

};

#endif // POINT_H
