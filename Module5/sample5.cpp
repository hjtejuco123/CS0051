/*
Simulated Message Queue in C
FIFO Behavior: First message in is the first out.
Multiple Writers & One Reader: Simulates real-world queue handling.
Uses standard <queue> to reflect OS-level message queue logic.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;
// Simulate a message queue
queue<string> messageQueue;

// Simulated sender
void studentSender(string message) {
    messageQueue.push(message);
}

// Simulated receiver
void classOfficerReader() {
    while (!messageQueue.empty()) {
        cout << "Class officer reads: " << messageQueue.front() << endl;
        messageQueue.pop();
    }
}

int main() {
    // Simulate multiple students sending messages
    studentSender("Please extend the project deadline.");
    studentSender("Can we have a review session?");
    studentSender("Request for extra lab hours.");

    // Simulate class officer reading them
    classOfficerReader();

    return 0;
}
