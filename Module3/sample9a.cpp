//deadlock
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1, m2; // Two mutex locks
//m1 - pen 
//m2 - notebook
void studentAlice() {
    m1.lock(); 
    cout << "Alice has the pen." << endl;
    this_thread::sleep_for(chrono::milliseconds(100)); 
    m2.lock(); 
    cout << "Alice has the notebook." << endl;
    m2.unlock();
    m1.unlock();
}

void studentBob() {
    m1.lock(); 
    cout << "Bob has the pen." << endl;
    this_thread::sleep_for(chrono::milliseconds(100)); 
    m2.lock(); 
    cout << "Bob has the notebook." << endl;
    m2.unlock();
    m1.unlock();
}

int main() {
    thread t1(studentAlice);
    thread t2(studentBob);

    t1.join();
    t2.join();

    return 0;
}
