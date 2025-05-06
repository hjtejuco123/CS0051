#include <iostream>
#include <thread>

using namespace std;

void busyWork() {
    for (int i = 0; i < 5; i++) {
        cout << "Working... from thread ID: " << this_thread::get_id() << "\n";
        this_thread::yield();  // Let other threads run
    }
}

int main() {
    // Create two threads that run the busyWork function
    thread worker1(busyWork);
    thread worker2(busyWork);

    // Wait for both threads to finish
    worker1.join();
    worker2.join();

    cout << "Main program ends..." << endl;
    return 0;
}
