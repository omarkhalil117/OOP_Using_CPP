// Shallow

#include <iostream>

using namespace std;


class Stack{

    int *arr ;
    int t ;
    int S ;



public:

    Stack(int s)
    {
    this -> t = -1 ;
    this -> S = s ;
    this-> arr = new int[this->S] ;
    cout<<"Stack Created"<< endl;
    }
    ~Stack()
    {
        cout<<"Queue Terminated"<<endl ;
        delete []arr ;
    }
    void push(int x)
    {
        if (t == this->S-1)
        {
           cout<<"Sorry the stack is full"<<endl;
        }
        else
        {
           this->t = this->t + 1 ;
           this->arr[this->t] = x ;
        }
    }

    int pop()
    {
        if (this->t == -1)
        {
           cout<<"Sorry the stack is Empty"<<endl;
           return 0 ;
        }
        else
        {
           this->t--;
           return this->arr[this->t+1];
        }
    }

    void printStack()
    {
        if(t == -1)
        {
            cout<<"Stack is empty can't print rn."<<endl;
        }
        for (int i=0 ; i<= this -> t ; i++)
        {
            cout<<arr[i]<<"\t" ;
        }
        cout<<"\n";
    }


};

void function(Stack s);


int main()
{
    //int siz = 3 ;
    int c = 0 ;
    Stack s(3);

    s.push(1);
    s.push(2);
    s.push(3);


    s.printStack();

    c = s.pop() ;
    cout<<"Popped : "<< c << endl;
    //c = s.pop() ;
    //cout<<"Popped : "<< c << endl;
    //c = s.pop() ;
    //cout<<"Popped : "<< c << endl;
    //c = s.pop() ;
    cout<<"Function Start."<< endl;
    function(s);
    cout<<"Function End."<< endl;
    c = s.pop();
    cout<<"Popped : "<< c << endl;
    c = s.pop();
    cout<<"Popped : "<< c << endl;
    s.printStack();

    return 0;
}


void function(Stack s)
{
    s.push(5);
    s.push(10);
}


// arr = new int(size) {0}

//~decon delete arr[]
