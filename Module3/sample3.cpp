//recursive mutex 
//entrant lock
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//reentrant mutex
recursive_mutex mtx;
int counter = 0;

void incrementCounter(){
    mtx.lock(); //locks the mutex 
    cout << "Counter " << ++counter << endl;
    mtx.unlock();
}

void nestedFunction(){
    mtx.lock(); //lock mutex 
    incrementCounter(); //call function also lock the mutex 
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
