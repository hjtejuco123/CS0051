//Scenario: You’re waiting for pizza instead of constantly checking the door.
//Solution: Condition variable makes threads sleep until notified.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex pizza_mutex;
condition_variable pizza_cv;
bool pizza_arrived = false;

void student() {
    cout << "Student: Waiting for pizza... " << endl;
    unique_lock<mutex> lock(pizza_mutex);
    pizza_cv.wait(lock, []{ return pizza_arrived; });
    cout << "Student: Finally! Eating pizza!" << endl;
}

void deliveryGuy() {
    this_thread::sleep_for(chrono::seconds(3)); // Delivery time
    {
        lock_guard<mutex> lock(pizza_mutex);
        pizza_arrived = true;
        cout << "Delivery: Pizza is here!" << endl;
    }
    pizza_cv.notify_one(); // Wake up the student
}

int main() {
    thread t1(student);
    thread t2(deliveryGuy);
    
    t1.join();
    t2.join();
}
