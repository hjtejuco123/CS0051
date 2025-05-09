//Scenario: Only one student can print at a time in the computer lab.
//Solution: Mutex acts like a "printer token" - you need it to print.
//Mutext Shared Resources   
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex printer_mutex;

void printDocument(string name) {
    printer_mutex.lock(); 
    cout << name << " is printing..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); 
    cout << name << " finished printing!" << endl;
    printer_mutex.unlock(); 
}

int main() {
    thread student1(printDocument, "Hadji");
    thread student2(printDocument, "Joan");
    
    student1.join();
    student2.join();
}
