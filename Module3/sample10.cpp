//starvation
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx; // Mutex to protect shared resource

void greedyStudent() {
    while (true) {
        mtx.lock();
        cout << "Greedy student is using the computer." << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); 
        mtx.unlock();
    }
}

void starvingStudent(int id) {
    while (true) {
        mtx.lock();
        cout << "Student " << id << " finally got access to the computer." << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(100)); 
    }
}

int main() {
    thread t1(greedyStudent);
    thread t2(starvingStudent, 1);
    thread t3(starvingStudent, 2);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
