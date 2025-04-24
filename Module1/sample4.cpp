
#include <iostream>
#include <thread>
#include <chrono> // For simulating delays
using namespace std;

void countOdds() {
    for (int i = 1; i <= 9; i += 2) {
        cout << "Odd: " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void countEvens() {
    for (int i = 2; i <= 10; i += 2) {
        cout << "Even: " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void sequentialVsParallel() {
    cout << "\n=== Sequential Execution ===\n";
    for (int i = 1; i <= 10; ++i) {
        cout << "Count: " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
    
    cout << "\n=== Parallel Execution ===\n";
    thread t1(countOdds);
    thread t2(countEvens);
    
    t1.join(); // Wait for thread t1 to finish
    t2.join(); // Wait for thread t2 to finish
}

int main() {
    sequentialVsParallel();
    return 0;
}
