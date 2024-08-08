#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>

/*
- Creating and destroying threads frequently can be expensive. Thread pools reduce this overhead by reusing reusing threads.
- You can control number of threads in the pool, preventing the system from being overwhelmed by too many concurrent threads.
- Thread pools help you manage how tasks are executed in parallel, which is essential for scalable, high-performance applications.
- Key Components :: Worker Threads, Task Queue, Synchronization mechanisms.
--- Worker threads :: These threads execute tasks, they wait for the task to be added to a task queue.
--- Task Queue :: where tasks are stored until a worker thread is available to execute them.
--- Sync mechanism :: Mutexes and condition variables are used to ensure that access to task queue is thread-safe and to notify worker
    threads when tasks are available.
*/

class ThreadPool {
    public:
        ThreadPool(size_t numThreads);
        ~ThreadPool();

        void enqueueTask(std::function<void()> task);
    
    private:
        std::vector<std::thread> workers; // Threads in the pool
        std::queue<std::function<void()>> tasks; // Task queue
        std::mutex queueMutex; // Mutex for task queue
        std::condition_variable condition; // Condition variable to notify worker threads
        std::atomic<bool> stop; // Flag to stop the pool
        
        void workerThread();
    
};

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i=0; i < numThreads; i++) {
        workers.emplace_back([this] {
            this->workerThread();
        });
    }
}

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

void ThreadPool::enqueueTask(std::function<void()> task) {
    std::lock_guard<std::mutex> lock(queueMutex);
    tasks.push(std::move(task));

    condition.notify_one();
}

void ThreadPool::workerThread() {
    while (!stop) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this]{
                return stop || !tasks.empty(); // makes the thread wait until there's a task available or pool is stopped.
            });

            if (stop && tasks.empty()) {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

int main()
{
    ThreadPool pool(4);

    for (int i=0; i<8; i++) {
        pool.enqueueTask({
            [i] {
                std::cout << "Task " << i << " is running on thread " << std::this_thread::get_id() << std::endl;
            }
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Give time for tasks to complete

    return 0;
}
