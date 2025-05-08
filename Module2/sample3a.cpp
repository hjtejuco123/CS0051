#include <iostream>
#include <thread>
#include <string>

using namespace std;

void printMessage(const string& message, int count) {
    for (int i = 0; i < count; ++i) {
        cout << message << " (" << i+1 << "/" << count << ")" << endl;
    }
}

class MessagePrinter {
public:
    void print(const string& message, int count) {
        for (int i = 0; i < count; ++i) {
            cout << "Object says: " << message << " (" << i+1 << "/" << count << ")" << endl;
        }
    }
};

int main() {
    
    thread t1(printMessage, "Hello from thread", 3);
    
    
    MessagePrinter mp;
    thread t2(&MessagePrinter::print, &mp, "Hello from object", 3);
    
    t1.join();
    t2.join();
    
    return 0;
}
