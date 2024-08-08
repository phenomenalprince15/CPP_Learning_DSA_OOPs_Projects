#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

/*
- It allows us to specify how algorithms should be executed sequentially, parallel or vectorized manner.

- Performance, They allow to leverage multiple CPU cores to perform operations faster on large data sets.
- It makes it easier to write parallel code wihtout worrying about thread management.
*/

int main()
{
    std::vector<int> numbers(1000000, 1);
    // Execute std::for_each in parallel
    std::for_each(std::execution::par, numbers.begin(), numbers.end(), 
    [](int &n) {
        n *= 2;
    });

    std::cout << "First Number : " << numbers[0] << std::endl; // should be 2

    return 0;
}

