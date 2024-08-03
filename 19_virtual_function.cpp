#include <iostream>
using namespace std;

/*
Run-Time Polymorphism ::
- Using inheritance and virtual functions.

Virtual Functions ::
- It is a function in a base class that is over-ridden in a derived class.
- They allow the correct function to be called for an object, regardless the type of reference (or pointer) used for function call.
*/

// Base Class
class Animal {
    public:
        virtual void sound() {
            cout << "Animal makes a sound." << endl;
        }
};

/*
Declaring,
virtual void sound() = 0; // it will become a pure virtual function which has no implementation in base class.
- A class containing a pure virtual function is considered abstract and cannot be instantiated.
*/

// Derived Class
class Dog : public Animal {
    public:
        void sound() override {
            cout << "Dog barks." << endl;
        }
};

// Another Derived Class
class Cat : public Animal {
    public:
        void sound() override {
            cout << "Car meows." << endl;
        }
};

int main()
{
    Animal *animalPtr;
    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->sound();

    animalPtr = &cat;
    animalPtr->sound();
}