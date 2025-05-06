#include <iostream>
#include <thread>

using namespace std;

void busyWork() {
    for (int i = 0; i < 5; i++) {
        cout << "Working...\n";
        this_thread::yield();  // Let other threads run
    }
}

int main() {
    thread worker(busyWork);
    worker.join();
    return 0;
}
