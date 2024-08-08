#include <iostream>
#include <thread>

/*
- Thread Local Storage (TLS) allows each thread to have it's own instance of a variable. This is useful when threads need to
    maintain state independently from each other.
- Why use thread local storage ?
--- Avoid data races by giving each thread it's own copy of a variable, you avoid the need for synchronization mechanisms
    like mutexes, as each thread operates on it's own independent data.
--- Thread-specific data, it is useful for storing data that is specific to a thread, such as thread IDs, thread-specific counters,
or thread-speicific caches.
*/

thread_local int threadId = 0;

void setThreadId(int id) {
    threadId = id;
    std::cout << "Thread " << id << " has thread-local ID : " << threadId << std::endl;
}

int main()
{
    std::thread t1(setThreadId, 1);
    std::thread t2(setThreadId, 2);

    t1.join();
    t2.join();

    return 0;
}
