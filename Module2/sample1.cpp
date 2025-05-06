#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void task (string taskName);

int main()
{
    cout << "Main thread id " << this_thread::get_id() <<endl;    
    task("Task 1");
    task("Task 2");
    task("Task 3");
    return 0;
}

void task (string taskName)
{
    //start the task -> get id -> sleep(2) -> done 
    cout << " Starting Task " << taskName 
        << " on thread ID " << this_thread::get_id() << " ... " << endl;
    this_thread::sleep_for (chrono::seconds(2));
    cout << taskName << "done ! " << endl; 
    
}
