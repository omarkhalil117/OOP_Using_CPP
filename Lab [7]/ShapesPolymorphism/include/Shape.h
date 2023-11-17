#ifndef SHAPE_H
#define SHAPE_H
using namespace std;

class Shape
{
    int color;

    public:

    Shape()
    {
        color = 1 ;
    }

    void setColor(int c)
    {
        color = c ;
    }

    int getColor(void)
    {
        return color ;
    }

    virtual void draw()=0;

};  //end class Shape

#endif // SHAPE_H
