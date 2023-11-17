#ifndef LINE_H
#define LINE_H
using namespace std;

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
       cout<<"Override Line"<<endl ;
       setcolor(this->getColor());
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

// istream Line
istream &operator>>(istream &in, Line &lin)
{
    int x1,y1,x2,y2,c;

    cout << "Enter Start point x , y " << endl;
    cin >> x1;
    cin >> y1;

    cout << "Enter End point x , y " << endl;
    cin >> x2;
    cin >> y2;

    cout << "Enter Color"<< endl;
    cin >> c;
    lin.setPoints(x1,y1,x2,y2);
    lin.setColor(c);
}

#endif // LINE_H
