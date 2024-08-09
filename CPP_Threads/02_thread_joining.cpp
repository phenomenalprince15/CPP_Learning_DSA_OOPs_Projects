#include <iostream>
#include <thread>

void task()
{
    std::cout << "Task is running." << std::endl;
}

int main()
{
    std::thread t(task);
    std::cout << "Waiting for thread to finish it's task." << std::endl;
    t.join(); // wait for thread to complete
    std::cout << "Thread has finished execution." << std::endl;

    return 0;
}
