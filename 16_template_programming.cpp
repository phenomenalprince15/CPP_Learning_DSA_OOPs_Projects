#include <iostream>
using namespace std;

/*
Templace Programming
- It allows you to write generic and reusable code that works with any data type.
- Templates are a powerful feature in C++ that enable functions and classes to operate with genertic types making the code more flexible.

-- Types ::
--- Functional, Class, Template specialization and Variadic templates.

*** Functional Templates ***
- It creates a single function that can work with different data types.
- template <typename T>
T functionName(T param) {
    // Function implementation
}
--- T is a placeholder that will be replaced by actual type when function is called.
*/

template <typename T>
T add(T a, T b)
{
    return a + b;
}

/*
*** Class Templates ***
- It allows you to create a generic class that can work with any data type.
- template <typename T>
    class ClassName {
        private:
            T member;
        public:
            ClassName(T arg) : member(arg) {}
        T getMember() {
            return member;
        }
    };
*/

template <typename T>
class Box {
    private:
        T value;
    public:
        Box(T v) : value(v) {}
        T getValue() {
            return value;
        }
};

/*
Template Specialization ::
- It allows you to create a specific implementation of a template for a particular data type.
- template <>
    class ClassName<SpecifierType> {
        // Specialized implementaion
    }
*/

template <typename T>
class Calculator {
    public:
        T add(T a, T b){
            return a + b;
        }
};

template <>
class Calculator<string> {
    public:
        string add (string a, string b){
            return a + " " + b;
        }
};

/*
variadic Templates ::
- It allows you to create functions or classes that accept a variable number of template parameters.
- template <typename... Args>
void functionName(Args... args) {
    // code
}
*/

template <typename... Args>
void print(Args... args) {
    (cout << ... << args) << endl; // Fold expression C++17
}

int main()
{
    cout << add(3, 4) << endl;
    cout << add(3.4, 5.6) << endl;

    Box<int> intBox(123);
    Box<double> doubleBox(123.456);
    cout << "intBox : " << intBox.getValue() << endl;
    cout << "doubleBox : " << doubleBox.getValue() << endl;

    Calculator<int> intCalc;
    Calculator<string> stringCalc;
    cout << intCalc.add(3, 4) << endl; // Uses the generic template.
    cout << stringCalc.add("Hello", "World ~") << endl; // Uses the special template.

    // Variadic
    print(1," ", 2," ", 3.5, " ", "Hello", " ", 'c');

    return 0;
}