#include <iostream>
#include <thread>
#include <barrier>
#include <chrono>

using namespace std;

barrier syncPoint(3, [](){
    cout << ">>> All threads reached sync point — moving to next phase\n";
});

void worker(int id) {
    cout << "Worker " << id << " preparing phase 1\n";
    this_thread::sleep_for(chrono::milliseconds(100 * id));
    syncPoint.arrive_and_wait();  // Arrive and wait
    cout << "Worker " << id << " doing phase 1 work\n";
    this_thread::sleep_for(chrono::milliseconds(100 * id));

    cout << "Worker " << id << " preparing phase 2\n";
    this_thread::sleep_for(chrono::milliseconds(50 * id));

    if (id == 3) {
        syncPoint.arrive_and_drop();  // Signal arrival and leave
        cout << "Worker " << id << " has dropped out\n";
        return;
    }

    syncPoint.arrive_and_wait();  // Normal arrive-and-wait
    cout << "Worker " << id << " doing phase 2 work\n";
}

int main() {
    thread t1(worker, 1), t2(worker, 2), t3(worker, 3);

    t1.join(); t2.join(); t3.join();

    cout << "All work complete.\n";
    return 0;
}
