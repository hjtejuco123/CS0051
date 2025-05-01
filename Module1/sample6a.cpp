#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void doChore(string choreName);

int main() {
    cout << "== Multi-Threaded House Chores Simulation ==" << endl;

    // Start all chores at the same time using threads
    thread person1(doChore, "Washing dishes");
    thread person2(doChore, "Sweeping the floor");
    thread person3(doChore, "Doing laundry");

    // Wait for all chores to finish
    person1.join();
    person2.join();
    person3.join();

    cout << "All chores are finished! (multi-threaded)" << endl;
    return 0;
}
// Simulate a house chore
void doChore(string choreName) {
    cout << "Starting: " << choreName << "..." << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Simulate time taken
    cout << choreName << " is done!" << endl;
}
