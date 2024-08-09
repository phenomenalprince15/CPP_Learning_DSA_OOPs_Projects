#include <iostream>
using namespace std;

/*
Friend functions ::
- A function that is not a member of a class but still has access to it's private and protected members.
- Useful when you want an external function to access the class private's data.
*/

class Box {
    private:
        double width;
    public:
        Box (double w) : width(w) {}

        // Friend function
        friend void printWidth (Box &box) {
            cout << box.width << endl;
        }
};

int main ()
{
    Box b(10.5);
    printWidth(b); //Accessing private member

    return 0;
}
