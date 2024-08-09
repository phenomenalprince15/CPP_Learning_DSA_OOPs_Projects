#include <iostream>
using namespace std;

/*
Move constructor ::
- It's used to efficiently tranfer resources from one object to another, especially when working wotj dynamic memory.
- It prevents unneccessary deep copying.

General ::
- ClassName(ClassName &&obj);
*/

class Example {
    private:
        int *data;
    public:
        // Constructor
        Example(int value){
            data = new int(value);
            cout << "Constructor constructor, Resource allocated to " << data << endl;
        }

        // Copy Constructor
        Example(const Example &obj){
            data = new int(*(obj.data));
            cout << "Copy constructor, Resource copied to " << data << endl;
        }

        // Move constructor
        Example (Example &&obj) noexcept {
            data = obj.data; // transfer ownership of data.
            obj.data = nullptr; // nullify the source pointer.
            cout << "Move constructor, Resource moved to " << data << endl;
        }

        //Destructor
        ~Example() {
            if (data){
                cout << "Destructor : Resource freed at " << data << endl;
                delete data;
            }else{
                cout << "No resource to free" << endl;
            }
        }

        // Display
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
    Example ex1(10);
    ex1.display();
    Example ex2= move(ex1);
    ex1.display();
    ex2.display();
}