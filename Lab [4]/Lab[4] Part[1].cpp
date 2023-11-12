#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imag;

public:
    Complex(int x = 0, int y = 0)
    {
        this->real = x;
        this->imag = y;
    }
    int getReal(void)
    {
        return real;
    }
    int getImag(void)
    {
        return imag;
    }
    void setReal(int _real)
    {
        real = _real;
    }
    void setImag(int _imag)
    {
        imag = _imag;
    }

    void print()
    {
        cout << real;

        if (imag > 0)
        {
            cout << "+" << imag << "j" << endl;
        }
        else if (imag < 0)
        {
            cout << imag << "j" << endl;
        }
    }

    Complex add(Complex c1, Complex c2)
    {
        Complex c3;
        c3.setReal(c1.getReal() + c2.getReal());
        c3.setImag(c1.getImag() + c2.getImag());
        return c3;
    }

    Complex sub(Complex c1, Complex c2)
    {
        Complex c3;
        c3.setReal(c1.getReal() - c2.getReal());
        c3.setImag(c1.getImag() - c2.getImag());
        return c3;
    }

    Complex operator+(Complex &c)
    {
        this->real += c.getReal();
        this->imag += c.getImag();
        return *this;
    }

    Complex operator-(Complex &c)
    {
        this->real -= c.getReal();
        this->imag -= c.getImag();
        return *this;
    }

    int operator==(Complex &c)
    {
        return this->real == c.getReal() && this->imag == c.getImag();
    }

    Complex operator++()
    {
        this->real += 1;
        return *this;
    }

    Complex operator++(int)
    {
        Complex Temp(this->real + 1, this->imag);
        this->real += 1;
        return Temp;
    }

    Complex operator--()
    {
        this->real -= 1;
        return *this;
    }

    Complex operator--(int)
    {
        Complex Temp(this->real - 1, this->imag);
        this->real -= 1;
        return Temp;
    }

    operator float()
    {
        return real;
    }

    void operator+=(Complex &c)
    {
        this->real += c.getReal();
        this->imag += c.getImag();
    }

}; // end class

int main()
{

    // Create Obj c1
    Complex c1(5, 10);
    Complex c2(1, 2);
    Complex c3;

    cout << "Addition" << endl;
    c3 = c1 + c2;
    c3.print();

    cout << "Subtraction" << endl;
    c3 = c1 - c2;
    c3.print();

    cout << "Postfix ++" << endl;
    c3 = c3++;
    c3.print();

    cout << "Prefix ++" << endl;
    c3 = ++c3;
    c3.print();

    cout << "Prefix --" << endl;
    c3 = c3--;
    c3.print();

    cout << "Prefix --" << endl;
    c3 = --c3;
    c3.print();

    cout << "Equality Between c1 , c2 = " << (c1 == c2) << endl;

    return 0;
}
