#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mtx;

void incrementCount()
{
    for (int i=0; i<100000; i++){
        std::lock_guard<std::mutex> lock(mtx);
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

    return 0;
}
