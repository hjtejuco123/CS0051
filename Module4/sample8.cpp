//A latch is a countdown counter. Threads wait until the counter reaches zero – one-time use only.


#include <iostream>
#include <thread>
#include <latch>
#include <chrono>

using namespace std;

latch launchChecklist(3);

void systemCheck(const string& systemName) {
    cout << systemName << " check in progress...\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << systemName << " check complete.\n";
    launchChecklist.count_down(); 
}

void launchRocket() {
    cout << "Waiting for all systems to be ready...\n";
    launchChecklist.wait(); 
    cout << "All systems go. Rocket launching!\n";
}

int main() {
    thread t1(systemCheck, "Engine");
    thread t2(systemCheck, "Fuel");
    thread t3(systemCheck, "Weather");
    thread t4(launchRocket);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
