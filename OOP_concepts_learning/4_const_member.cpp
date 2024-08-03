#include <iostream>
using namespace std;

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            // Constructor but with better initialization
            Car (string b, string m, int y) : brand(b), model(m), year(y) {
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }

/*
Const member functions ::
- A const member function guarantees that it will not modify member variables of the object.
- if you try modifying any new member variable inside a const member function, the comiler will throw an error.
*/
            void displayInfo () const { // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
            // void changeYear (int newYear) const {
            //     year = newYear; // throws an error
            // }
};

int main ()
{
    cout << "hello world !!!" << endl;

    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();


    return 0;
}