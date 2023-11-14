#include <iostream>
#include <graphics.h>
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

    void draw()
    {

    }


};  //end class Shape

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

class Line :public Shape
{
    Point start;
    Point ende;

    public:

    Line():start(0,0),ende(0,0)
    {

    }

    void draw()
    {
       cout<<"Over ride Line"<<endl ;
       line(start.getX(), start.getY(), ende.getX(), ende.getY());
    }

    void setPoints(int x1 , int y1 , int x2 , int y2)
    {
        start.setX(x1);
        start.setY(y1);
        ende.setX(x2);
        ende.setY(y2);
    }
    friend istream &operator>>(istream &in, Line &lin);
}; //end class Line


class Circle : public Shape
{
    Point center ;
    int r ;

    public:

    Circle()
    {
       center.setX(0);
       center.setY(0);
    }

    void draw()
    {
       cout<<"Over ride Circle"<<endl ;
       circle(center.getX(), center.getY(), r );
    }

    void setCircle(int x ,int y , int rad)
    {
        center.setX(x);
        center.setY(y);
        r = rad ;
    }
    friend istream &operator>>(istream &in, Circle &cir);

};  // end class Circle

class Rect : public Shape
{
    Point tl ;
    Point rb ;

    public:

    Rect():tl(0,0),rb(0,0)
    {

    }

    void draw()
    {
       cout<<"Override Rect"<<endl ;
       rectangle(tl.getX(),tl.getY(),rb.getX(),rb.getY());
    }

    void setPoints(int x1 , int y1 , int x2 , int y2)
    {
        tl.setX(x1);
        tl.setY(y1);
        rb.setX(x2);
        rb.setY(y2);
    }

    friend istream &operator>>(istream &in, Rect &rec);
}; // end class Rect

// istream Line
istream &operator>>(istream &in, Line &lin)
{
    int x1,y1,x2,y2;

    cout<<"Enter Start point x , y "<<endl;
    cin>>x1;
    cin>>y1;

    cout<<"Enter End point x , y "<<endl;
    cin>>x2;
    cin>>y2;

    lin.setPoints(x1,y1,x2,y2);

}

// istream Circle
istream &operator>>(istream &in, Circle &cir)
{
    int x,y,r;

    cout<<"Enter Start point x , y "<<endl;
    cin>>x;
    cin>>y;

    cout<<"Enter Radius"<<endl;
    cin>>r;
    cir.setCircle(x,y,r);

}

// istream Rec
istream &operator>>(istream &in, Rect &rec)
{
    int x1,y1,x2,y2;

    cout<<"Enter Top left point x , y "<<endl;
    cin>>x1;
    cin>>y1;

    cout<<"Enter Right bottom point x , y "<<endl;
    cin>>x2;
    cin>>y2;

    rec.setPoints(x1,y1,x2,y2);
}






int main()
{

    Line ls[10];
    Circle cs[10];
    Rect rs[10];
    int counts [3] ={0,0,0} ;
    int n = 0 ;
    int code = 0;

    cout<<"Enter Number of shapes"<<endl;
    cin>>n ;

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter Shape codes"<<endl;
        cout<<"Line [1] Rectangle [2] Circle [3]"<<endl;
        cin>>code ;

        if(1==code)
        {
           Line l;
           cin >> l ;
           ls[counts[0]] = l ;
           counts[0] += 1 ;

        }
        else if(2==code)
        {
           Rect r;
           cin >> r ;
           rs[counts[1]] =  r ;
           counts[1] += 1 ;

        }
        else if(3==code)
        {
           Circle c ;
           cin >> c ;
           cs[counts[2]] =  c ;
           counts[2] += 1 ;
        }
        else
        {
            cout<<"Invalid code Focus Please !!!"<<endl;
            i--;
        }
    }


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // print Lines
    for(int i=0 ; i<counts[0]; i++)
    {
        setcolor(3);
        ls[i].draw();
    }

    // print Rectangles
    for(int i=0 ; i<counts[1] ; i++)
    {
        setcolor(4);
        rs[i].draw();
    }

    // print Circles
    for(int i=0 ; i<counts[2] ; i++)
    {
        setcolor(5);
        cs[i].draw();
    }
    getch();
    closegraph();

    /*
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

     Rect r;
     Line l;

     Circle c;

     l.draw();
     r.draw();
     c.draw();

     getch();
     closegraph();
     */

    return 0;
}
