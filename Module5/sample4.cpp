// File-Based IPC – Message via File
//Demonstrates file as a medium for communication.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Writer process
void studentWriter() {
    ofstream file("message.txt"); // Create or open file for writing
    if (file.is_open()) {
        file << "Don't forget: Meeting at 3 PM!" << endl;
        file.close();
    } else {
        cout << "Error writing to file." << endl;
    }
}

// Reader process
void studentReader() {
    ifstream file("message.txt"); // Open file for reading
    string message;

    if (file.is_open()) {
        while (getline(file, message)) {
            cout << "Student reads: " << message << endl;
        }
        file.close();
    } else {
        cout << "Error reading from file." << endl;
    }
}

int main() {
    studentWriter();  // Simulate writing to file
    studentReader();  // Simulate reading from file
    return 0;
}
