//Scenario: Two clerks selling concert tickets, but only 10 tickets exist.
//Problem: Without a mutex, both might sell the same last ticket!

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex ticket_mutex;
int tickets_left = 10;

void sellTicket(string clerk) {
    while (true) {
        ticket_mutex.lock();
        if (tickets_left > 0) {
            cout << clerk << " sold ticket #" << tickets_left << endl;
            tickets_left--;
            ticket_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(100)); // Selling time
        } else {
            cout << clerk << ": Sorry, sold out!" << endl;
            ticket_mutex.unlock();
            break;
        }
    }
}

int main() {
    thread clerk1(sellTicket, "Clerk A");
    thread clerk2(sellTicket, "Clerk B");
    
    clerk1.join();
    clerk2.join();
}
