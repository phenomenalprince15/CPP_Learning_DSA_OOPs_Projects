#include <iostream>
#include <thread>

void sayHello() {
    std::cout << "Hello from a thread!" << std::endl;
}

int main() {
    std::thread t(sayHello);  // Create a thread that runs the sayHello function
    t.join();                 // Wait for the thread to finish
    return 0;
}
