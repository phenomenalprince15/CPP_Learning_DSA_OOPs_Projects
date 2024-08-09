#include <iostream>
using namespace std;

/*
Copy Constructor ::
- It's a special constructor used to create a new object as a copy of an existing object.
- You can define yout own copy constructor, or the compiler provides a default one, which performs a shallow copy.
- Shallow copy, in that objects share same memory location. (it just duplicated pointers)
- Custom copy constructor will do a deep copy. (duplicates the actual data)

General copy constructor ::
-- ClassName (const ClassName &obj); // reference top object that is being copied and const ensures that it can't be modified.
*/

class Line {
    private:
        int *length;

        public:
        Line(int l) {
            length = new int;
            *length = l;
        }

        // copy constructor
        Line (const Line &obj){
            length = new int;
            *length = *(obj.length);
        }

        void display() {
            cout << "Length : " << *length << endl;
        }

        // Destructor
        ~Line() {
            delete length;
        }

};

int main ()
{
    Line line1(10);
    Line line2 = line1; // copy constructor is called

    line1.display();
    line2.display();

}