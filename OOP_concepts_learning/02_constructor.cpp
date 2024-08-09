#include <iostream>
using namespace std;

/*
Class ::
- A class is just a blueprint for creating objects.
- It defines a datatype by bundling data and methods that work on data into a single unit.

Constructor ::
- It's a special member function that is automatically called when an object is created.
- it initializes the data members of the object.
- They have the same name as class, but don't have return type.

Destructor ::
- It's a special member function that is automatically called when an object is destroyed,
---  (goes out of scope or explicitly deleted)
- It's name is same as the class, but it is preceded by a tilde (~)
- They are used for cleanup, like releasing memory or resources.
 */

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            // Constructor
            Car (string b, string m, int y){
                brand = b;
                model = m;
                year = y;
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }

            void displayInfo (){ // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

int main ()
{
    cout << "hello world !!!" << endl;
    // Car car1;
    // car1.brand = "Toyota";
    // car1.model = "Corolla";
    // car1.year = 2000;

    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();


    return 0;
}