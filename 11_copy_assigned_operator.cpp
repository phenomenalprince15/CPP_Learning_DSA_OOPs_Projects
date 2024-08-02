#include <iostream>
using namespace std;

/*
Copy Constructor
- The copy assignment operator pergorms a deep copy of resources from one object to another.
- It's used when assigning a value to an already existing object.
- It assigns the contents of one object to another existing object of the same class.
- Unlike the copy assignment operator, which initializes a new object, the copy assignment assigns a value to an 
--- already existing object.
- ClassName& operator=(const ClassName &obj)
*/
class Example {
    private:
        int *data;
    
    public:
        Example (int value){
            data = new int(value);
            cout << "Constructor : Resource allocated at " << data << endl;
        }

        // Copy constructor
        Example (const Example &obj){
            data = new int(*obj.data);
            cout << "Copy Constructor : Resource copied to " << data << endl;
        }

        // Copy Assignment Operator
        Example& operator=(const Example &obj){
            if (this != &obj) { // Self-assigned check
                delete data; // free existing resource
                data = new int(*obj.data); // Deep copy
                cout << "Copy Assignment Operator : Resource assigned to " << data << endl;
            }
            return *this;
        }

        // Destreuctor
        ~Example() {
            delete data;
            cout << "Destructor : Resource freed at " << data << endl;
        }

        void display () const {
            cout << "value : " << *data << endl;
        }
};

int main()
{
    Example obj1(10); // Constructor
    Example obj2(20); // Constructor

    Example obj3 = obj1; // Copy Constructor (create a new object as a copy of an exisiting object)

    obj2 = obj1; // copy assignment operator Constructor (assign value from an existing object to another existing object)

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}
