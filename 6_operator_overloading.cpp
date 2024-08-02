#include <iostream>
using namespace std;

class Complex {
    private :
        float real;
        float imag;
    
    public :
        // Constructor
        Complex (float r=0, float i=0) : real(r), imag(i) {}

        // Operator overloading for "+"
        Complex operator+(const Complex &obj){
            Complex temp;
            temp.real = real + obj.real; // or this->real can be used.
            temp.imag = imag  + obj.imag;
            return temp;
        }
        void display() const {
            cout << real << " + " << imag << "i" << endl;
        }
};

int main ()
{
    Complex c1(3.4, 5.5);
    Complex c2(2.3, 4.4);
/*
- Operator "+" is overloaded to handle expressions like c1 + c2 work naturally with user-defined types.
*/
    Complex c3 = c1 + c2; // using overloaded "+" operator
    c3.display();
}