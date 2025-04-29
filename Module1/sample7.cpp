//using THREAD ID
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void task();

int main()
{
    
    thread t1(task);
    thread t2(task);
    
    cout << "Main thread ID " << this_thread::get_id() << endl;
    t1.join();
    t2.join();
    
    cout << "All task is complete ... " <<endl;
    return 0;
}

void task() {
    cout << "Task is running with THREAD ID " << this_thread::get_id()<<endl;
}



