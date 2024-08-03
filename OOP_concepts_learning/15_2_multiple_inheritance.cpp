#include <iostream>
using namespace std;

/*
In multiple inheritance, a class inherits from more than one base class.
*/

// Base Class 1
class Animal {
    public:
        void eat() {
            cout << "Animal is eating..." << endl;
        }
};

// Base Class 2
class Pet {
    public:
        void play() {
            cout << "Pet is playing." << endl;
        }
};

// Derived Class
class Dog : public Animal, public Pet {
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
    myDog.play();

    return 0;
}