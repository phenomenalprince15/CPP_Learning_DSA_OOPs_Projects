#include <iostream>
using namespace std;

/*
In single inheritance, one class inherits from a single base class.
*/

// Base Class
class Animal {
    public:
        void eat() {
            cout << "Animal is eating..." << endl;
        }
};

// Derived Class
class Dog : public Animal {
    public:
        void bark() {
            cout << "Dog is barking..." << endl;
        }
};

int main ()
{   
    Dog myDog;
    myDog.bark();
    myDog.eat();

    return 0;
}