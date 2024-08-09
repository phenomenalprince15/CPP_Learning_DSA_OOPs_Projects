#include <iostream>
#include <thread>

/*
- When multiple threads access shared data, there is a risk of a RACE CONDITION,
where the outcome depends on the timing of threads.

- To prevent race conditions, we can use MUTEXES to synchronize access to shared data.
*/

int count = 0;

void incrementCount()
{
    for (int i=0; i<100000; i++){
        count++;
    }
}

int main()
{
    std::thread t1(incrementCount);
    std::thread t2(incrementCount);

    t1.join();
    t2.join();

    std::cout << "Final Count Value : " << count << "\n";
    /*
    - In this, both threads are incrementing counter simulatneously without synchronizing.
    */

    return 0;
}
