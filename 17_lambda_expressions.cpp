#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Lambda Expressions ::
- It allows you to define anonymous functions (functions without a name) directly in the code where they are used.
- It makes the code more consise and readable, especially for short functions that are used only in a specific context.
- Syntax ::
[capture] (params) -> return type {
    // functions body
}
--- capture defines variables from surrounding scope are captures and how (by value or reference).
--- parameters specifies regular function parameters.
-- return type is optional.
*/

int main ()
{   
    // without capture
    auto add = [] (int a, int b) -> int{
        return a + b;
    };
    cout << "Sum : " << add(5, 3) << endl;

    // with capture
    int x = 10;
    int y = 20;
    auto addition = [=] () {
        return x + y; // x and y are captured by value. Change inside here won't affect original variables.
    };
    auto modify = [&] () {
        x = x + y; // x and y are captured by reference. Change inside here will affect original variables.
    };
    cout << "Sum (by value) : " << addition() << endl;

    modify();
    cout << "Modified x : " << x << endl;

    // Lambdas with STL
    vector<int> nums = {5, 2, 8, 1, 3};
    sort(nums.begin(), nums.end(), [](int a, int b){
        return a > b;
    });

    cout << "Sorted nums : " <<  endl;
    for (int n : nums){
        cout << n << " ";
    }
    cout << endl;

    // Generic lambdas C++14 and later, we can use auto to make lambda work with any type.
    auto print = [](auto x){
        cout << x << endl;
    };
    print(42);
    print(13.5);
    print("fafsd");
    print("132asfsa");

    return 0;
}