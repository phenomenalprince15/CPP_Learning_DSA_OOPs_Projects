#include <iostream>
#include <thread>
#include <mutex>

/*
- Sometimes, you want to ensure that a particular piece of code is only executed once, regardless of how many
threads attempt to execute it.
- Initialize function is only executed once.
*/

std::once_flag initFlag;

void initialize()
{
    std::cout << "Initialization code executed once." << std::endl;
}

void runTask()
{
    std::call_once(initFlag, initialize);
    std::cout << "Thread running." << std::endl;
}

int main()
{
    std::thread t1(runTask);
    std::thread t2(runTask);
    std::thread t3(runTask);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
