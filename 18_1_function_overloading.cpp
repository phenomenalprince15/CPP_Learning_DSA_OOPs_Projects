#include <iostream>
using namespace std;

/*
- It allows multiple functions with the same name but different parameter lists to be defined.
- The corret function to be called is determined by the arguments passed.
*/

class Print {
    public:
        void show (int i) {
            cout << "Integer : " << i << endl;
        }
        void show (double i) {
            cout << "Double : " << i << endl;
        }
        void show (string i) {
            cout << "String : " << i << endl;
        }
};

int main()
{
/*
- Function is overloaded 3 times with different arguments.
- The compiler will determine which function to call based on argument type at the compile time.
*/
    Print p;
    p.show(10);
    p.show(10.7);
    p.show("fas4234");

    return 0;
}