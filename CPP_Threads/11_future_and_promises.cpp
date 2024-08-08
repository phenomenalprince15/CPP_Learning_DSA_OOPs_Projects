#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/*
- Future and promises provides a mechanism for transferring data or exceptions between threads,
with the future acting as a handle to retrieve the result of an asynchronous operation.
*/

void computeSquare(std::promise<int> p, int x)
{
    int result = x*x;
    p.set_value(result); // set the result for the promise
}

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future(); // Get the future associated with the promise

    std::thread t(computeSquare, std::move(p), 5);

    int result = f.get(); // wait for the result
    std::cout << "Square of 5 is : " << result << std::endl;

    t.join();

    return 0;
}

/*
- promise<int> A promise that will eventually hold an integer value.
- future<int> A future that can be used to retrieve the value set by the promise.
- f.get() blocks until the result is ready, then returns the value.
*/
