#include <iostream>
using namespace std;

/*
In multi-level inheritance, a derived class is further derived by another class, creating a chain.
*/

// Base Class 1
class Animal {
    public:
        void eat() {
            cout << "Animal is eating..." << endl;
        }
};

// Intermediate Derived Class
class Mammal : public Animal {
    public:
        void walk() {
            cout << "Mammal is walking." << endl;
        }
};

// Further Derived Class
class Dog : public Mammal {
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
    myDog.walk();

    return 0;
}