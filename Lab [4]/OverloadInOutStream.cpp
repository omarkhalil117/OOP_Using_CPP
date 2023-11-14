#include <iostream>
#include <string.h>
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

    // Give access to ostream & istream to private attributes
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);

    // Map Complex through indexing
    int &operator[](int i)
    {
        if (i == 0)
        {
            return this->real;
        }
        else if (i == 1)
        {
            return this->imag;
        }
    }

    // Map Complex through "real" & "imag"
    int &operator[](string s)
    {
        if (s == "real")
        {
            return this->real;
        }
        else if (s == "imag")
        {
            return this->imag;
        }
    }

}; // end class

ostream &operator<<(ostream &out, const Complex &c) // stand alone ostream overloading
{
    out << c.real;
    if (c.imag < 0)
    {
        out << c.imag << "j" << endl;
    }
    else
    {
        out << "+" << c.imag << "j" << endl;
    }
    return out;
}

istream &operator>>(istream &in, Complex &c) // stand alone istream overloading
{
    cout << "Enter Real ";
    in >> c.real;
    cout << "Enter Imag ";
    in >> c.imag;
    return in;
}

int main()
{

    Complex c2(1, 2);
    Complex c3;

    cout << c2;

    cin >> c3;

    cout << c3;

    cout << "From Brackets [0] = " << c3[0] << endl;
    cout << "From Brackets [1] = " << c3[1] << endl;

    cout << "From Brackets [\"real\"] = " << c3["real"] << endl;
    cout << "From Brackets [\"imag\"] = " << c3["imag"] << endl;

    return 0;
}
