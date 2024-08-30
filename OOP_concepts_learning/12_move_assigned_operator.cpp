#include <iostream>
using namespace std;

/*
Move assginment Operator
- It is used to transfer ownership of resources from one existing to another, rather than copying it.
- ClassName& operator=(ClassName &&obj) noexcept;
*/

class Example {
    private:
        int *data;
    public:
        // Constructor
        Example(int value){
            data = new int(value); 
            cout << "Constructor : Resource allocated at " << data << endl;
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

        ~Example() {
            delete data;
            cout << "Destructor : Resource freed at : " << data << endl;
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
    Example ex1(10);
    ex1.display();
    Example ex2(20);
    ex2.display();

    Example ex3 = move(ex1); // move constructor
    ex1.display();
    ex3.display();
    ex2 = move(ex3); // move assigned constructor
    ex2.display();
        
    return 0;
}
