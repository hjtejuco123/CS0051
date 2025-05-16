
#include <iostream>
#include <mutex>
using namespace std;
recursive_mutex rmtx;  // Reentrant mutex

void recursiveFunction(int count) {
    rmtx.lock();  // Lock the reentrant mutex
    cout << "Lock acquired. Count = " << count << endl;

    if (count > 0) {
        recursiveFunction(count - 1);  // Recursive call
    }

    rmtx.unlock();  // Unlock the reentrant mutex
    cout << "Lock released. Count = " << count << endl;
}

int main() {
    cout << "Starting recursive function..." << endl;
    recursiveFunction(3);  // Call the recursive function
    recursiveFunction(5);  // Call the recursive function
    cout << "Recursive function completed." << endl;
    return 0;
}
