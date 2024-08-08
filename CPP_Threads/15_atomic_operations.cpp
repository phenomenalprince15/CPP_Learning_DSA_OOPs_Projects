#include <iostream>
#include <thread>
#include <atomic>

/*
- Atomic operations on data that are completed in a single step without the possibility of being interrupred by other threads,
std::atmoic provides a way to perform these operations on shared data, ensuring thread safety without the need for locks.

- They are faster than using mutexes becz they don't require the overhead of locking and unlocking.
- They provide a simple to manage shared data in a mutli-threaded envirionment.
*/

std::atomic<int> count(0);

void incrementCount() {
    for (int i=0; i<1000; i++) {
        count++;
    }
}

int main()
{
    std::thread t1(incrementCount);
    std::thread t2(incrementCount);

    t1.join();
    t2.join();

    std::cout << "Final count value : " << count << std::endl;

    return 0;
}

/*
- atomic is a special type which ensures the counter variable is incremented atomically, meaning no other thread can interrupt
increment operation.
- counter++ is safe-operation as it guarantees that no threads will modify the variable at the same time.
*/

