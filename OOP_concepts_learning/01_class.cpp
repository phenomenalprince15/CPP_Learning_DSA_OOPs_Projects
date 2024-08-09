#include <iostream>
using namespace std;

/*
A class is just a blueprint for creating objects.
It defines a datatype by bundling data and methods that work on data into a single unit.
 */

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            void displayInfo (){ // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

int main ()
{
    cout << "hello world !!!" << endl;
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2000;

    car1.displayInfo();

    return 0;
}