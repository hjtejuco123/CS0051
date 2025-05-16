#include <iostream>
#include <mutex>

using namespace std;

recursive_mutex rmtx;  // Reentrant mutex

// Inner function
void innerFunction(int level) {
    rmtx.lock();  // Lock the reentrant mutex
    cout << "Entering innerFunction. Level = " << level << endl;
    cout << "Exiting innerFunction. Level = " << level << endl;
    rmtx.unlock();  // Unlock the reentrant mutex
}

// Middle function
void middleFunction(int level) {
    rmtx.lock();  // Lock the reentrant mutex
    cout << "Entering middleFunction. Level = " << level << endl;
    innerFunction(level + 1);  // Call the inner function
    cout << "Exiting middleFunction. Level = " << level << endl;
    rmtx.unlock();  // Unlock the reentrant mutex
}

// Outer function
void outerFunction(int level) {
    rmtx.lock();  // Lock the reentrant mutex
    cout << "Entering outerFunction. Level = " << level << endl;
    middleFunction(level + 1);  // Call the middle function
    cout << "Exiting outerFunction. Level = " << level << endl;
    rmtx.unlock();  // Unlock the reentrant mutex
}

int main() {
    cout << "Starting nested function calls with reentrant lock..." << endl;
    outerFunction(1);  // Start the nested calls with level 1
    cout << "Nested function calls completed." << endl;
    return 0;
}
