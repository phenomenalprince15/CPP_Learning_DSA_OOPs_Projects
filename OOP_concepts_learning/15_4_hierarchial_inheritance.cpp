#include <iostream>
using namespace std;

/*
In hierarchial inheritance, multiple classess inherit from the same base class.
*/

// Base Class
class Animal {
    public:
        void eat() {
            cout << "Animal is eating..." << endl;
        }
};

// Derived Class 1
class Cat : public Animal {
    public:
        void meow() {
            cout << "Cat is meowing." << endl;
        }
};

// Derived Class 2
class Dog : public Animal {
    public:
        void bark() {
            cout << "Dog is barking..." << endl;
        }
};

int main ()
{   
    Dog myDog;
    Cat myCat;

    myDog.bark();
    myDog.eat();

    myCat.eat();
    myCat.meow();

    return 0;
}