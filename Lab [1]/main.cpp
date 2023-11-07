#include <iostream>

using namespace std;

class Complex
{
     int real ;
     int imag ;


     public:
     int getReal(void)
     {
         return real ;
     }
     int getImag(void)
     {
         return imag ;
     }
     void setReal(int _real)
     {
         real = _real ;
     }
     void setImag(int _imag)
     {
         imag = _imag ;
     }

     void print()
     {
         cout<<real;

         if(imag >0)
         {
             cout<<"+"<<imag<<"j"<<endl;
         }
         else if (imag<0)
         {
             cout<<imag<<"j"<<endl ;
         }
     }

     Complex add(Complex c1 , Complex c2)
     {
         Complex c3 ;
         c3.setReal(c1.getReal() + c2.getReal());
         c3.setImag(c1.getImag() + c2.getImag());
         return c3;
     }

     Complex sub(Complex c1 , Complex c2)
     {
         Complex c3 ;
         c3.setReal(c1.getReal() - c2.getReal());
         c3.setImag(c1.getImag() - c2.getImag());
         return c3;
     }



};

void printCmplx(Complex c);
Complex addCmplx(Complex c1 , Complex c2);
Complex subCmplx(Complex c1 , Complex c2);

void swap_ref(int &x , int&y);

int main()
{
    int x = 5 , y = 7 ;
	
	cout<<"Swap: \n" ;
    swap_ref(x , y);
    cout<<"x = "<< x <<"\t"<< "y = "<<y <<endl ;

    // Create Obj c1
    Complex c1 ;
    // Initialize c1
    c1.setReal(10);
    c1.setImag(5);
    // print comp 1
    cout<<"Object c1: \n" ;
    c1.print();

    // Create Obj c2
    Complex c2 ;
    // Initialize c2
    c2.setReal(5);
    c2.setImag(2);
    // print comp 2
    cout<<"Object c2: \n" ;
    c2.print();

    // Create Objects for results
    Complex addRes ;
    Complex subRes ;
    Complex c3 ;

    cout<<"Add From class:"<<endl;
    c3 = c1.add(c1,c2);     // Add c1,c2
    c3.print();     // prinf Addition c3

    cout<<"Sub From class:"<<endl;
    c3 = c1.sub(c1,c2);     // Sub c1,c2
    c3.print();     // prinf Addition c3


    cout<<"Stand Alone print Function \n";
    printCmplx(c1);

    cout<<"Stand Alone Function:"<<endl ;
    addRes = addCmplx(c1 , c2);
    subRes = subCmplx(c1 , c2);

    cout<<"Add standalone"<<endl;
    addRes.print();

    cout<<"Sub standalone"<<endl;
    subRes.print();
	
    return 0;
}


void swap_ref(int &x , int&y)
{
    int temp = x ;
    x = y ;
    y = temp;

}

void printCmplx(Complex c)
{
    int re = c.getReal();
    int Im = c.getImag();
    cout<<re ;

    if(Im>0)
    {
        cout<<"+"<<Im<<"j"<<endl ;
    }
    else if(Im<0)
    {
        cout<<Im<<"j"<<endl ;
    }
}

Complex addCmplx(Complex c1 , Complex c2)
{
    Complex Res ;
    int totReal = c1.getReal() + c2.getReal() ;
    int totImage = c1.getImag() + c2.getImag() ;
    Res.setReal(totReal);
    Res.setImag(totImage);

    return Res ;
}

Complex subCmplx(Complex c1 , Complex c2)
{
    Complex Res ;
    int totReal = c1.getReal() - c2.getReal() ;
    int totImage = c1.getImag() - c2.getImag() ;
    Res.setReal(totReal);
    Res.setImag(totImage);

    return Res ;
}
