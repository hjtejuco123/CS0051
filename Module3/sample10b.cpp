//starvation solution
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
bool greedyStudentTurn = true;

void greedyStudent() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return greedyStudentTurn; });
        cout << "Greedy student is using the computer." << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); 
        greedyStudentTurn = false;
        cv.notify_all();
    }
}

void starvingStudent(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !greedyStudentTurn; });
        cout << "Student " << id << " is using the computer." << endl;
        this_thread::sleep_for(chrono::milliseconds(200)); 
        greedyStudentTurn = true;
        cv.notify_all();
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
