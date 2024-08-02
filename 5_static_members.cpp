#include <iostream>
using namespace std;

class Car {
/*
Static Members ::
- Static members (variables or functions) belong to the class rather than to any object of the class.
- static variables retain their values between function calls and are shared by all objects of the class.
- static functions can only access static variables.
*/
    public :
            static int CarCount; // static member variable
            string brand;
            string model;
            int year;

            // Constructor
            Car (string b, string m, int y) : brand(b), model(m), year(y) {
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
                CarCount++;
            }

            static void displayCarCount () {
                cout << "Total numbers of cars : " << CarCount << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }
            void displayInfo () const { // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

// initialize static member
int Car::CarCount = 0;

int main ()
{
/*
- CarCount is staic member variable, it will be shared by all objects of the Car Class.
- displayCarCount fucntion is static and can be called without an object (Car::displayCarCount()).
*/
    Car::displayCarCount();
    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();
    Car::displayCarCount();
    Car car2("BMW", "X5", 2022);
    car2.displayInfo();
    Car::displayCarCount();

    return 0;
}