/*
Client makes a call (connects)
Server picks up (listens and responds
*/

#include <iostream>
#include <string>

using namespace std;

// Socket buffer
string socketBuffer;

// Server process
void server() {
    if (!socketBuffer.empty()) {
        cout << "[Server] Message received: " << socketBuffer << endl;
        cout << "[Server] Sending reply: Message received!" << endl;
        socketBuffer = "Message received!";  // reply back
    } else {
        cout << "[Server] No message received." << endl;
    }
}

// Client process
void client() {
    socketBuffer = "Hello, server! This is client.";
    cout << "[Client] Sending message to server..." << endl;
    server(); // Simulate sending message
    cout << "[Client] Server replied: " << socketBuffer << endl;
}

int main() {
    client(); // Start the client process
    return 0;
}
