// Deep Copy

#include <iostream>

using namespace std;

template <typename T>

class Stack
{

    T *arr;
    int t;
    int S; // Size

public:
    Stack(int s)
    {
        this->t = -1;
        this->S = s;
        this->arr = new T[s];
        cout << "Stack Created" << endl;
    }

    Stack(Stack &s)
    {
        t = -1;
        S = s.S;
        arr = new T[S];
        for (int i = 0; i <= s.t; i++)
        {
            arr[i] = s.arr[i];
        }
    }

    ~Stack()
    {
        cout << "Queue Terminated" << endl;
        delete[] arr;
    }
    void push(T x)
    {
        if (t == this->S - 1)
        {
            T *temp = new T[S * 2];
            for (int i = 0; i < t; i++)
            {
                temp[i] = arr[i];
            }
            S = S * 2;
            delete[] arr;
            arr = temp;
            cout << "Extended !!" << endl;
            // cout << "Sorry the stack is full" << endl;
        }
        else
        {
            this->t = this->t + 1;
            this->arr[this->t] = x;
        }
    }

    T pop()
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

int main()
{
    float c = 0;
    Stack<float> s(3);

    s.push(1.25);
    s.push(2.5);
    s.push(23.5);
    s.push(2.0);
    s.push(12.25);
    s.push(14.65);

    c = s.pop();
    cout << "Popped : " << c << endl;
    cout << "Function Start." << endl;
    cout << "Function End." << endl;
    c = s.pop();
    cout << "Popped : " << c << endl;
    c = s.pop();
    cout << "Popped : " << c << endl;
    s.printStack();

    return 0;
}
