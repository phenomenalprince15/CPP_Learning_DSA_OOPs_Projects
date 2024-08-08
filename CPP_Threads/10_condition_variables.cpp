#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void printMessage(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return ready;}); // Wait "ready" is true
    std::cout << "Thread " << id << " is running.\n";
}

void setReady()
{
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_all(); // Notify all waiting threads
}

int main()
{
    std::thread t1(printMessage, 1);
    std::thread t2(printMessage, 2);
    std::thread t3(printMessage, 3);

    std::thread signalThread(setReady);

    t1.join();
    t2.join();
    t3.join();
    signalThread.join();

    return 0;
}

/*
- condition_variable allows threads to wait until they are notified by another thread that some condition is true.
- cv.wait() waits until the ready flag is set to true. This function will automatically unlocks the mutex an dputs threads in waiting state.
- cv.notify_all() wakes up all waiting threads once the condition is met.
*/
