#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/*
- async is a high level API for running tasks asynchronously.
- It returns std::future object that you can use to retrieve the result. 
*/

int computedSquare(int x)
{
    return x*x;
}

int main()
{
    std::future<int> f = std::async(std::launch::async, computedSquare, 5);

    int result = f.get();
    std::cout << "Square of 5 is : " << result << std::endl;

    return 0;

}

/*
- async launches a task asynchronously in a seperate thread.
- f.get() waits for the task to complete and returns the result.
*/
