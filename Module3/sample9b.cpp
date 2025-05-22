//deadlock solution
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1, m2; // Two mutex locks

void studentAlice() {
    lock(m1, m2); 
    lock_guard<mutex> lg1(m1, adopt_lock);
    lock_guard<mutex> lg2(m2, adopt_lock);

    cout << "Alice has the pen and notebook." << endl;
}

void studentBob() {
    lock(m1, m2); 
    lock_guard<mutex> lg1(m1, adopt_lock);
    lock_guard<mutex> lg2(m2, adopt_lock);

    cout << "Bob has the pen and notebook." << endl;
}

int main() {
    thread t1(studentAlice);
    thread t2(studentBob);

    t1.join();
    t2.join();

    return 0;
}
