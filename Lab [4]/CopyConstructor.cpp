// Deep Copy

#include <iostream>

using namespace std;

class Stack
{

    int *arr;
    int t;
    int S;

public:
    Stack(int s)
    {
        this->t = -1;
        this->S = s;
        this->arr = new int[s];
        cout << "Stack Created" << endl;
    }
    // Copy Constructor
    Stack(Stack &s)
    {
        t = s.t;
        S = s.S;
        
        int *temp = new int[S];
        for (int i = 0; i < S; i++)
        {
            temp[i] = s.arr[i];
        }
        arr = temp ;
        cout<<"Copy"<<endl;
    }

    ~Stack()
    {
        cout << "Queue Terminated" << endl;
        delete[] arr;
    }
    void push(int x)
    {
        if (t == this->S - 1)
        {
            cout << "Sorry the stack is full" << endl;
        }
        else
        {
            this->t = this->t + 1;
            this->arr[this->t] = x;
        }
    }

    int pop()
    {
        if (this->t == -1)
        {
            cout << "Sorry the stack is Empty" << endl;
            return 0;
        }
        else
        {
            this->t--;
            return this->arr[this->t + 1];
        }
    }

    void printStack()
    {
        if (t == -1)
        {
            cout << "Stack is empty can't print rn." << endl;
        }
        for (int i = 0; i <= this->t; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << "\n";
    }
};

void function(Stack s);

int main()
{
    // int siz = 3 ;
    int c = 0;
    Stack s(3);

    s.push(1);
    s.push(2);
    // s.push(3);
    Stack s2 = s;
   
    s.printStack();
    s2.push(5);
    s2.printStack();
    // s.printStack();


    return 0;
}

void function(Stack s)
{
    s.pop();
    s.push(10);
}