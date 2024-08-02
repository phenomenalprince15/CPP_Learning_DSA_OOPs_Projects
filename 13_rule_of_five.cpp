#include <iostream>
using namespace std;

/*
- Defining any of these functions usually implies that your class manages resources, and
--- able to handle copying and moving explicitly to avoid resource leaks and undefined behavior.
*/

class Example {
    private:
        int *data;
    
    public:
        // Constructor
        Example(int value) : data(new int(value)) {}
        
        // Destructor
        ~Example() {
            delete data;
            cout << "Destructor : Resource freed at " << data << endl;
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

        // Move Constructor
        Example (Example &&obj) noexcept {
            data = obj.data;
            obj.data = nullptr;
            cout << "Move Constructor : Resource moved to " << data << endl;
        }

        // Move Assigned Operator
        Example& operator=(Example &&obj) noexcept {
            if (this != &obj) {
                delete data;
                data = obj.data;
                obj.data = nullptr;
                cout << "Move assignment Operator : Resource allocated to " << data << endl;
            }
            return *this;
        }

         void display() const {
            if (data){
                cout << "Value : " << *data << endl;
            }else {
                cout << "No data available" << endl;
            }
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

    Example ex4(10);
    ex4.display();
    Example ex5(20);
    ex5.display();

    Example ex6 = move(ex4); // move constructor
    ex4.display();
    ex6.display();
    ex5 = move(ex6); // move assigned constructor
    ex5.display();
}
