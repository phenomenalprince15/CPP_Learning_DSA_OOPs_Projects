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