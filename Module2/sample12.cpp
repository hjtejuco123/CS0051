#include <iostream>
#include <thread>

using namespace std;

int main() {
    int cores = thread::hardware_concurrency();
    cout << "This system can run " << cores << " threads concurrently\n";
    return 0;
}
