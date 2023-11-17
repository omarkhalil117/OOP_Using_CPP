#ifndef POINT_H
#define POINT_H

class Point
{
    int x;
    int y;

    public:

    Point(int _x =0 , int _y = 0)
    {
      x = _x ;
      y = _y ;
    }

    void setX(int _x)
    {
        x = _x;
    }
    void setY(int _y)
    {
        y = _y;
    }

    int getX(void)
    {
        return x;
    }

    int getY(void)
    {
        return y;
    }

};  //end class Point

#endif // POINT_H
