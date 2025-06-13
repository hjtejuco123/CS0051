#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;
//binary semaphore with try_acquire_for

binary_semaphore printer(1); 

void tryFor(int userId);

int main()
{
    //lock the printer 
    printer.acquire();
    thread t1(tryFor,2);
    this_thread::sleep_for(chrono::seconds(3));
    printer.release();
    
    t1.join();
    
    return 0;
}

void tryFor(int userId)
{
    cout << "User " << userId << " waits for 2 seconds for the printer ....\n";
    if (printer.try_acquire_for(chrono::seconds(2))) {
        cout << "User " << userId << " acquired the printer....\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "User " << userId << " is done printing ....\n";
         printer.release();
    }else{
        
        cout << "User " << userId << " gave up waiting for the printer \n";
    }
}





