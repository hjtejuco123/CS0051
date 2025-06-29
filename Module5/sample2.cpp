//Shared memory
/*
Two students share a whiteboard. One writes a reminder; the other reads it.
This mimics shared memory, where both can access the same space.
*/

#include <iostream>
#include <string>

using namespace std;

// Shared memory simulation using a global string
string shared_whiteboard;

void studentA() {
    shared_whiteboard = "Don't forget to submit the math homework!";
}

void studentB() {
    cout << "Student B reads from whiteboard: " << shared_whiteboard << endl;
}

int main() {
    studentA(); // Write to shared memory
    studentB(); // Read from shared memory
    return 0;
}

