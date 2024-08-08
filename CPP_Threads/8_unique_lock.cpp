#include <iostream>
#include <thread>
#include <mutex>

/*
- lock_guard provides a simple, RAII style mechanism for acquiring and releasing a mutex.
When a lock_guard object is created, it locks the mutex, and when it goes out of scope, it automatically release the mutex.

- unique_lock provides more flexibilitythan lock_guard. It can be used for deferred locking, timed locking, and unlocking before
end of its scope. It gives more control over the locking mechanism.
*/

std::mutex mtx;

void printMessage(const std::string& message)
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << message << std::endl;
    lock.unlock();
}

int main()
{
    std::thread t1(printMessage, "Hello from thread 1");
    std::thread t2(printMessage, "Hello from thread 2");

    t1.join();
    t2.join();
    return 0;
}
