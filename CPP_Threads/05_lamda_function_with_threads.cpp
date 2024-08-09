#include <iostream>
#include <thread>

int main()
{
    int value = 5;
    std::thread t(
        [&value]{
            value *= 2;
            std::cout << "value in thread : " << value << std::endl;
        }
    );

    std::cout << "value in main thread before thread completes : " << value << std::endl;
    t.join();
    std::cout << "value in main thread after thread completes : " << value << std::endl;

    return 0;
}
