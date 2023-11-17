#ifndef RECT_H
#define RECT_H


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
       setcolor(this->getColor());
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

// istream Rec
istream &operator>>(istream &in, Rect &rec)
{
    int x1,y1,x2,y2,c;

    cout << "Enter Top left point x , y " << endl;
    cin >> x1;
    cin >> y1;

    cout << "Enter Right bottom point x , y " << endl;
    cin >> x2;
    cin >> y2;

    cout << "Enter Color"<< endl;
    cin >> c;

    rec.setPoints(x1,y1,x2,y2);
    rec.setColor(c);
}

#endif // RECT_H
