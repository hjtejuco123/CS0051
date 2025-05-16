
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;

void task(int id) {
    for (int i = 0; i < 3; ++i) {
        if (mtx.try_lock()) {
            cout << "Thread " << id << " acquired the lock in iteration " << i << endl;
            this_thread::sleep_for(std::chrono::seconds(1));  // Simulate work
            mtx.unlock();
        } else {
            cout << "Thread " << id << " could not acquire the lock in iteration " << i << ". Doing other work..." << endl;
        }
        this_thread::sleep_for(std::chrono::milliseconds(500));  // Wait before retrying
    }
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);
    t1.join();
    t2.join();
    return 0;
}
