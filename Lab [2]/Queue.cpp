#include <iostream>

using namespace std;


class Queue{

    int *arr ;
    int bak ;
    int frt ;
    int S ;



public:

    Queue(int s)
    {
    this -> S = s ;
    this -> frt = -1 ;
    this -> bak = -1 ;
    this-> arr = new int(this->S) ;
    }
    ~Queue()
    {
        cout<<"Queue Terminated"<<endl ;
    }
    void enqueue(int x)
    {
        if (bak == S-1 && frt == 0)
        {
           cout<<"Sorry the Queue is full"<<endl;
        }
        else
        {
            if (-1 == frt)
            {
                frt = 0 ;
            }
            bak++;

            arr[bak] = x ;
        }
    }

    int dequeue()
    {

        if ( -1 == frt)
        {
           cout<<"Sorry the Queue is Empty"<<endl;
           return 0;
        }
        else
        {
            int returned ;
            returned = arr[frt] ;

            if (frt >= bak)
             {
                frt = -1;
                bak = -1;
             }
            else
             {
                frt++;

             }
             return returned ;
        }


    }

    void printQueue()
    {
        if(-1 == frt || -1 == bak)
        {
            cout<<"Stack is empty can't print rn."<<endl;
        }
        else{

        for (int i=frt ; i<=bak ; i++)
        {
            cout<<arr[i]<<"\t" ;
        }
        cout<<"\n";
        }
    }


};




int main()
{
    //int siz = 3 ;
    int c = 0 ;
    Queue *q = new Queue(3);

    q ->enqueue(1);
    q ->enqueue(2);
    q ->enqueue(3);

    q ->printQueue();

    c = q ->dequeue();
    cout<<"Popped : "<< c << endl;
    c = q ->dequeue();
    cout<<"Popped : "<< c << endl;
    c = q ->dequeue();
    cout<<"Popped : "<< c << endl;
    c = q ->dequeue();
    cout<<"Popped : "<< c << endl;
        c = q ->dequeue();
    cout<<"Popped : "<< c << endl;
    q ->printQueue();

    return 0;
}


// arr = new int(size) {0}

//~decon delete arr[]
