//single threaded simulation
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void task(string taskName);
int main()
{
    cout << "== Single Threaded Simulation ==" <<endl;
    
    task("Task 1");
    task("Task 2");
    task("Task 3");
    
    cout << "All task is complete (single threaded) " <<endl;
    return 0;
}

void task(string taskName) {
    
    cout << "Starting Task " << taskName << " ... " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << taskName << " done! " <<endl;
}



