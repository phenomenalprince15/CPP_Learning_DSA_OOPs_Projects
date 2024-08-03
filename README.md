# Object-Oriented Programming

## Class and Objects
```
#include <iostream>
using namespace std;

/*
A class is just a blueprint for creating objects.
It defines a datatype by bundling data and methods that work on data into a single unit.
 */

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            void displayInfo (){ // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

int main ()
{
    cout << "hello world !!!" << endl;
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2000;

    car1.displayInfo();

    return 0;
}
```

## Constructors
```
#include <iostream>
using namespace std;

/*
Class ::
- A class is just a blueprint for creating objects.
- It defines a datatype by bundling data and methods that work on data into a single unit.

Constructor ::
- It's a special member function that is automatically called when an object is created.
- it initializes the data members of the object.
- They have the same name as class, but don't have return type.

Destructor ::
- It's a special member function that is automatically called when an object is destroyed,
---  (goes out of scope or explicitly deleted)
- It's name is same as the class, but it is preceded by a tilde (~)
- They are used for cleanup, like releasing memory or resources.
 */

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            // Constructor
            Car (string b, string m, int y){
                brand = b;
                model = m;
                year = y;
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }

            void displayInfo (){ // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

int main ()
{
    cout << "hello world !!!" << endl;
    // Car car1;
    // car1.brand = "Toyota";
    // car1.model = "Corolla";
    // car1.year = 2000;

    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();


    return 0;
}
```

## Member initialization better than constructor (Modified Constructor)
```
#include <iostream>
using namespace std;

/*
Class ::
- A class is just a blueprint for creating objects.
- It defines a datatype by bundling data and methods that work on data into a single unit.

Constructor ::
- It's a special member function that is automatically called when an object is created.
- it initializes the data members of the object.
- They have the same name as class, but don't have return type.

Destructor ::
- It's a special member function that is automatically called when an object is destroyed,
---  (goes out of scope or explicitly deleted)
- It's name is same as the class, but it is preceded by a tilde (~)
- They are used for cleanup, like releasing memory or resources.
 */

class Car {
    public :
            string brand; // data member
            string model;
            int year;

/*
Member initialization list ::
- It's a more efficient way to initialize class members, especially for constant members and reference types.
- It's defined after the contructor's signature and before the constructor body.
*/

            // Constructor but with better initialization
            Car (string b, string m, int y) : brand(b), model(m), year(y) {
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            }
            // Car (string b, string m, int y){
            //     brand = b;
            //     model = m;
            //     year = y;
            //     cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            // }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }

            void displayInfo (){ // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

int main ()
{
    cout << "hello world !!!" << endl;

    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();


    return 0;
}
```

## const_member functions
```
#include <iostream>
using namespace std;

class Car {
    public :
            string brand; // data member
            string model;
            int year;

            // Constructor but with better initialization
            Car (string b, string m, int y) : brand(b), model(m), year(y) {
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }

/*
Const member functions ::
- A const member function guarantees that it will not modify member variables of the object.
- if you try modifying any new member variable inside a const member function, the comiler will throw an error.
*/
            void displayInfo () const { // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
            // void changeYear (int newYear) const {
            //     year = newYear; // throws an error
            // }
};

int main ()
{
    cout << "hello world !!!" << endl;

    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();


    return 0;
}
```
## static member function
```
#include <iostream>
using namespace std;

class Car {
/*
Static Members ::
- Static members (variables or functions) belong to the class rather than to any object of the class.
- static variables retain their values between function calls and are shared by all objects of the class.
- static functions can only access static variables.
*/
    public :
            static int CarCount; // static member variable
            string brand;
            string model;
            int year;

            // Constructor
            Car (string b, string m, int y) : brand(b), model(m), year(y) {
                cout << "Car object created for " << brand << " " << model << " " << year << endl << endl;
                CarCount++;
            }

            static void displayCarCount () {
                cout << "Total numbers of cars : " << CarCount << endl;
            }

            // Destructor
            ~Car(){
                cout << "Car object destroyed for " << brand << " " << model << " " << year << endl;
            }
            void displayInfo () const { // method call
                cout << "Brand : " << brand << "\nModel: " << model << "\nyear : " << year << endl;
            }
};

// initialize static member
int Car::CarCount = 0;

int main ()
{
/*
- CarCount is staic member variable, it will be shared by all objects of the Car Class.
- displayCarCount fucntion is static and can be called without an object (Car::displayCarCount()).
*/
    Car::displayCarCount();
    Car car1("Toyota", "Corolla", 2000);
    car1.displayInfo();
    Car::displayCarCount();
    Car car2("BMW", "X5", 2022);
    car2.displayInfo();
    Car::displayCarCount();

    return 0;
}
```

## Operator Overloading
```
#include <iostream>
using namespace std;

class Complex {
    private :
        float real;
        float imag;
    
    public :
        // Constructor
        Complex (float r=0, float i=0) : real(r), imag(i) {}

        // Operator overloading for "+"
        Complex operator+(const Complex &obj){
            Complex temp;
            temp.real = real + obj.real; // or this->real can be used.
            temp.imag = imag  + obj.imag;
            return temp;
        }
        void display() const {
            cout << real << " + " << imag << "i" << endl;
        }
};

int main ()
{
    Complex c1(3.4, 5.5);
    Complex c2(2.3, 4.4);
/*
- Operator "+" is overloaded to handle expressions like c1 + c2 work naturally with user-defined types.
*/
    Complex c3 = c1 + c2; // using overloaded "+" operator
    c3.display();
}
```

## Friend functions
```
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

```

## Copy Constructor
```
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
```

## Move Constructor
```
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
```

## Dynamic Memory Allocation
```
#include <iostream>
using namespace std;

// new and delete operators are used to allocate and deallocate memory at runtime.

class DynamicArray {
    private:
        int *array;
        int size;

    public:
        DynamicArray(int s) : size(s) {
            array = new int[size];
            cout << "Array of size " << size << " created." << endl; 
        }

        void setValue(int index, int value){
            if (index >= 0 && index < size){
                array[index] = value;
            }
        }

        int getValue(int index) const {
            if (index >=0 && index < size){
                return array[index];
            }
            cout << "Out of bounds" << endl;
            return -1; // if out of bounds
        }

        ~DynamicArray(){
            delete[] array;
            cout << "Array destroyed." << endl;
        }

};

int main()
{
    DynamicArray arr(5);

    for (int i=0; i<5; i++)
    {
        arr.setValue(i, i+1);
    }

    for (int i=0; i<5; i++)
    {
        cout << "Element" << i << " " << arr.getValue(i) << endl;
    }

    return 0;
}
```

## Copy Assigned Operator
```
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

```

## Move Assigned Operator
```
#include <iostream>
using namespace std;

/*
Move assginment Operator
- It is used to transfer ownership of resources from one existing to another, rather than copying it.
- ClassName& operator-(ClassName &&obj) noexcept;
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

```

## Rule of five
```
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

```

## Smart Pointers
```
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

```

## Inheritance and Polymorphism
```
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
```

## Single Inheritance

## Multiple Inheritance

## Multi-level Inheritance

## Hierarchial Inheritance

## Template Programming

## Lambda Expressions

## Polymorphism

## Function overloading

## Virtual Function