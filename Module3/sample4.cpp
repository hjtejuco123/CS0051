//deadlock
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//reentrant mutex
mutex mtx;
int counter = 0;

void incrementCounter(){
    //mtx.lock();
    mtx.unlock(); //this will cause deadlock if the mutex is locked
    cout << "Thread ID " << this_thread::get_id()
         <<  "    | Counter " << ++counter << endl;
    //mtx.unlock();
}

void nestedFunction(){
    mtx.lock(); //lock mutex 
    incrementCounter(); //lock -> DEADLOCK
    mtx.unlock();
    
}


int main()
{
   
    thread t1 (nestedFunction);
    thread t2 (nestedFunction);
    
    t1.join();
    t2.join();
    
    return 0;
}
