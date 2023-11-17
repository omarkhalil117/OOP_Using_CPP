#include <iostream>
#include <graphics.h>
#include<Shapes.h>
using namespace std;

int main()
{
    Shape* arr[10];
    int cnt = -1;
    int n = 0 ;
    int code = 0;

    cout<<"Enter Number of shapes"<<endl;
    cin>>n ;

    for(int i=0 ; i < n ; i++)
    {
        cout<<"Enter Shape codes"<<endl;
        cout<<"Line [1] Rectangle [2] Circle [3]"<<endl;
        cin>>code ;

        if(1==code)
        {
           cnt++;
           arr[cnt] = new Line();
           cin >> *(Line*)arr[cnt];
        }
        else if(2==code)
        {
           cnt++;
           arr[cnt] = new Rect();
           cin >> *(Rect*)arr[cnt];

        }
        else if(3==code)
        {
           cnt++;
           arr[cnt] = new Circle();
           cin >> *(Circle*)arr[cnt];
        }
        else
        {
            cout<<"Invalid code Focus Please !!!"<<endl;
            i--;
        }
    }


    //initiate window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Print Shapes
    for(int i=0 ; i<= cnt ; i++)
    {
        arr[i]->draw();
    }

    getch();
    closegraph();


    return 0;
}
