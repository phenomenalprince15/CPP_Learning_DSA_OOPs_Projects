#include <iostream>
using namespace std;

/*
Inheritance and Polymorphism ::
- It allows you to create hierachial relationship between classes and enable objects to be treated as instances of their base classes.

Inheritance ::
- It allows a class (derived class) to inherit attributes and methods from another class (base class).
- It promotes code reuse and establishes a natural hierarchy among classes.

Types ::
- Single inheritance : A derived class inherit from a single base class.
- Multiple inheritance : A derived class inherit from more than one base class.
- Multi-level inheritance : A class is derived from a class which is also derived from another class.
- Hierarchial inheritance : Multiple classes inherit from a single base class.
*/

// Base Class
class Animal {
    public:
        void eat() {
            cout << "Eating..." << endl;
        }
};

// Derived Class
class Dog : public Animal {
    public:
        void bark() {
            cout << "Barking..." << endl;
        }
};

int main ()
{   
    Dog myDog;
    myDog.bark();
    myDog.eat();

    return 0;
}