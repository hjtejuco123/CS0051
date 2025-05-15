// Sharing of resources
// uses thread 
// prevent race condition ->
#include <iostream>
#include <thread> //manage the threads
#include <mutex> //protect shared resources 
using namespace std;

mutex mtx;  //mutex to protect the shared resource
int counter = 0; //global variable

void incrementCounter(int iterations);

int main()
{
    const int iterations = 5;
    
    thread t1(incrementCounter,iterations); //first call 
    thread t2(incrementCounter,iterations); //second call
    
    t1.join();
    t2.join();
    
    cout << "Final Counter value " << counter << endl;
    return 0;
}

//increment
void incrementCounter(int iterations)
{
    for (int i = 0; i<iterations;i++){
        
        mtx.lock(); //lock -> there should be only one thread can proceed
        //critical section to protect the shared resource
        ++counter;
        cout << "Thread ID: " << this_thread::get_id()
             << ", Counter: " << counter 
                << " ,iteration: " << i+1 << endl;
        mtx.unlock(); //unlock the mutex -> other threads can now proceed
    }
}







