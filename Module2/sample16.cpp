//Scenario: Only one person can use a single bathroom at a time.
//Solution: Mutex acts like a locked door.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex toilet_mutex;

void useToilet(string name) {
    toilet_mutex.lock();
    cout << name << " is using the toilet ..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << name << " is done!" << endl;
    toilet_mutex.unlock();
}

int main() {
    thread person1(useToilet, "Hadji");
    thread person2(useToilet, "Joan");
    
    person1.join();
    person2.join();
}
