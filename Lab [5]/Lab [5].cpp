#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
        cout << "Point Constructor" << endl;
    }
    void print_point(void)
    {
        cout << "(" << x << "," << y << ")" << endl;
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

}; // end class point

class Rectangle
{
    Point tl;
    Point br;

public:
    Rectangle() : tl(5, 6), br(1, 2)
    {
        cout << "Rectangle Constructor" << endl;
    }
}; // end Rectangle

class Circle
{
    Point center;
    int radius;
    Point *ct;

public:
    Circle()
    {
        ct = NULL;
    }
    ~Circle()
    {
        ct = NULL;
        cout << "Destructor Circle" << endl;
    }

    // Composition
    /*
    Circle() : center(0, 0)
    {
        radius = 0;
        cout << "Circle Constructor" << endl;
    }
    */

    void print_cnter(Point *c)
    {
        cout << "X = " << c->getX() << " Y = " << c->getY() << endl;
    }
}; // end calss circle

class Line
{
    Point *start;
    Point *ende;

    Point st;
    Point en;

public:
    Line()
    {
        start = NULL;
        ende = NULL;
    }

    ~Line()
    {
        start = NULL;
        ende = NULL;
        cout << "Destructor Line" << endl;
    }

    // Composition
    /*
    Line() : st(1, 3), en(5, 7)
    {
    }
    */

    // association
    void displayPoints(Point p1, Point p2)
    {
        cout << "x1 = " << p1.getX() << " y1 = " << p1.getY() << endl;
        cout << "x2 = " << p2.getX() << " y2 = " << p2.getY() << endl;
    }

    // Aggregation
    void initiateLine(Point *start, Point *ende)
    {
        this->start = start;
        this->ende = ende;
    }
    void printLine(Point *start, Point *ende)
    {
        cout << "x1 = " << start->getX() << " y1 = " << start->getY() << endl;
        cout << "x2 = " << ende->getX() << " y2 = " << ende->getY() << endl;
    }
    void displayLine()
    {
        cout << "x1 = " << start->getX() << " y1 = " << start->getY() << endl;
        cout << "x2 = " << ende->getX() << " y2 = " << ende->getY() << endl;
    }

}; // end class line

int main()
{
    // Composition
    Rectangle r;

    Point p1(1, 2);
    Point p2(5, 6);
    Point p3(7, 11);
    Point p4(9, 18);

    cout << "----------Print Point----------" << endl;
    p1.print_point();

    Line l;

    cout << "----------Print Line----------" << endl;
    l.printLine(&p1, &p2);

    cout << "----------Display Points----------" << endl;
    l.displayPoints(p1, p2);

    cout << "----------Initialized Points----------" << endl;
    l.initiateLine(&p3, &p4);
    l.displayLine();

    Circle c;

    cout << "----------Print Centre----------" << endl;
    c.print_cnter(&p1);

    return 0;
}
