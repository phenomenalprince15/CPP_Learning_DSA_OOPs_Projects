#include <iostream>
#include <thread>

void task()
{
    std::cout << "Task is going on.\n";
}

int main()
{
    std::thread t(task);
    t.detach(); // Detach the thread
    std::cout << "Thread is detached.\n";

    return 0;
}

/*
- Program may exit before the detached thread finishes.

$ g++ 3_detach_thread.cpp 
$ ./a.exe 
Thread is detached.

$ g++ 3_detach_thread.cpp
$ ./a.exe
Thread is detached.

$ g++ 3_detach_thread.cpp
$ ./a.exe
Thread is detached.
Task is going on.

- Detached threads should be used with caution because if the main program exits while detached threads are
still going on, the detached threads may not be able to finish work.

- Joined threads ensures that a thread has completed it's task before the program proceeds, provides a way
to manage thread lifetimes explicitly.
*/