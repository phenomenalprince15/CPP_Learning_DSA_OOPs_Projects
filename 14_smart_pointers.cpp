#include <iostream>
#include <memory>
using namespace std;

/*
Smart Pointers ::
- They are template classes provided by the STL to manage dynamic memory and other resources automatically.
- They help prevent common issues like memory leaks, dangling pointers, and double deletions by ensuring that resources
--- that resources are properly cleaned up when no longer needed.
Types of Smart Pointers ::
- std::unique_ptr
--- std::unique_ptr<Type> ptr(new Type());
--- It manages a single object with unique ownership.
--- It can't be copied, only moved.
--- It automatically deletes, when it goes out of scope.

- std::shared_ptr
--- std::shared_ptr<Type> ptr1 = std::make_shared<Type>();
    std::shared_ptr<Type> ptr2 = ptr1
--- it manages a shared object with reference counting.
--- Multiple std::shared_ptr instances can own the same object.
--- The object is deleted when the last std::shared_ptr owning it is destroyed.

- std::weak_ptr
--- std::weak_ptr<Type> weakPtr = ptr1;
--- It provides a non-owning "weak" reference to an object managed by shared_ptr.
--- It helps prevent circular references which can lead to memory leaks.
--- It doesn't affect the reference count of managed object.
*/

class Example {
    public:
        Example(){
            cout << "Example constructor" << endl;
        }

        ~Example() {
            cout << "Example destructor" <<  endl;
        }
};

int main()
{
    // unique pointer
    unique_ptr<Example> ptr1 = make_unique<Example> (); // creating a unique pointer.
    //unique_ptr<Example> ptr2 = ptr1; // unique pointer can't be copied.
    unique_ptr<Example> ptr = std::move(ptr1); // moving onwership, ptr1 is now nullptr.

    // shared pointer
    shared_ptr<Example> ptr3 = make_shared<Example>(); // creating a shared ptr
    shared_ptr<Example> ptr4 = ptr3; // sharing ownership
    cout << "Use count : " << ptr3.use_count() << endl;

    // weak pointer
    shared_ptr<Example> sharedPtr = make_shared<Example> ();
    weak_ptr<Example> weakPtr = sharedPtr;

    if (auto lockedPtr = weakPtr.lock()){ // Converting weak_ptr to shared_ptr
        cout << "Object is still alive." <<  endl;
    } else {
        cout << "Object has been deleted." << endl;
    }

    sharedPtr.reset(); // Reset shared ptr, object is deleted.

    if (auto lockedPtr = weakPtr.lock()) {
        cout << "Object is still alive." << endl;
    }else {
        cout << "object has been deleted." << endl;
    }

    return 0;
}
