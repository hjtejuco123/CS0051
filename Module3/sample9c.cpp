//deadlock solution with 3 resources
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex pen, notebook, laptop; 

void studentAlice() {
    lock(pen, notebook, laptop); //lock resources safely
    lock_guard<mutex> lg1(pen, adopt_lock);
    lock_guard<mutex> lg2(notebook, adopt_lock);
    lock_guard<mutex> lg3(laptop, adopt_lock);

    cout << "Alice has the pen, notebook and laptop." << endl;
}

void studentBob() {
    lock(pen, notebook, laptop); 
    lock_guard<mutex> lg1(pen, adopt_lock);
    lock_guard<mutex> lg2(notebook, adopt_lock);
    lock_guard<mutex> lg3(laptop, adopt_lock);

    cout << "Bob has the pen, notebook and laptop." << endl;
}

int main() {
    thread t1(studentAlice);
    thread t2(studentBob);

    t1.join();
    t2.join();

    return 0;
}
