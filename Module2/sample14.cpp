//Scenario: Students rushing to grab the last sandwich at lunch
//Problem: Two threads trying to modify shared data simultaneously

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sandwiches = 1; // Only one sandwich left!
mutex sandwich_mutex;

void student(int id) {
    sandwich_mutex.lock(); // Wait your turn in line
    
    if (sandwiches > 0) {
        cout << "Student " << id << " got the last sandwich!\n";
        sandwiches--;
    } else {
        cout << "Student " << id << " found no sandwiches left\n";
    }
    
    sandwich_mutex.unlock(); // Leave the counter
}

int main() {
    thread students[3] = {
        thread(student, 1),
        thread(student, 2),
        thread(student, 3)
    };

    // Replaced the auto& loop with explicit indexing
    for (int i = 0; i < 3; i++) {
        students[i].join();
    }

    return 0;
}
