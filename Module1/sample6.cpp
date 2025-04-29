//multi-threaded simulation
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void task(string taskName);
int main()
{
    cout << "== Multi-Threaded Simulation ==" <<endl;
    
    //create 3 task 
    thread t1 (task, "Task 1");
    thread t2 (task, "Task 2");
    thread t2 (task, "Task 3");
    
    t1.join();
    t2.join();
    t3.join();
    
    cout << "All task is complete (multi-threaded) " <<endl;
    return 0;
}

void task(string taskName) {
    
    cout << "Starting Task " << taskName << " ... " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << taskName << " done! " <<endl;
}



