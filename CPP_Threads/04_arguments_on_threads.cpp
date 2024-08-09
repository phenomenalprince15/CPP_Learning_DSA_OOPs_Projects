#include <iostream>
#include <thread>

/*
- Pass by value ::
*/

void printNumbers(int x)
{
    std::cout << "Number : " << x << std::endl;
}

/*
- Pass by reference ::
*/
void increment(int& x)
{
    x++;
}

int main()
{
    std::thread t(printNumbers, 10); // Pass 10 to the thread
    t.join(); // wait for thread to finish
    
    int num = 10;
    std::thread t_inc(increment, std::ref(num)); // Pass num by reference
    t_inc.join();

    std::cout << "Increment number : " << num << "\n";
    
    return 0;
}
