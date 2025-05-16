#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
recursive_mutex rmtx;  // Reentrant mutex

void recursiveFunction(int count) {
    rmtx.lock();
    cout << "Locked by thread " << std::this_thread::get_id() << ", count = " << count << endl;
    if (count > 0) {
        recursiveFunction(count - 1);  // Recursive call
    }
    rmtx.unlock();
}

int main() {
    thread t1(recursiveFunction, 3);
    thread t2(recursiveFunction, 2);
    t1.join();
    t2.join();
    return 0;
}
