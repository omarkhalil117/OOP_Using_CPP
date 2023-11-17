#ifndef CIRCLE_H
#define CIRCLE_H


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
       cout<<"Override Circle"<<endl ;
       setcolor(this->getColor());
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

// istream Circle
istream &operator>>(istream &in, Circle &cir)
{
    int x,y,r,c;

    cout<<"Enter Center point x , y "<<endl;
    cin>>x;
    cin>>y;

    cout<<"Enter Radius"<<endl;
    cin>>r;

    cout << "Enter Color"<< endl;
    cin >> c;

    cir.setCircle(x,y,r);
    cir.setColor(c);
}

#endif // CIRCLE_H
