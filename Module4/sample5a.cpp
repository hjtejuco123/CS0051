#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;
//binary semaphore with try_acquire_until

binary_semaphore printer(1); 

void tryUntil(int userId);

int main()
{
    //lock the printer 
    printer.acquire();
    thread t1(tryUntil,3);
    this_thread::sleep_for(chrono::seconds(5));
    printer.release();
    
    t1.join();
    
    return 0;
}

void tryUntil(int userId)
{
    chrono::steady_clock::time_point deadline = chrono::steady_clock::now() + chrono::seconds(4);
    cout << "User " << userId << " waits for 2 seconds for the printer ....\n";
    if (printer.try_acquire_until(deadline)) {
        cout << "User " << userId << " acquired printer before the deadline \n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "User " << userId << " is done printing ....\n";
         printer.release();
    }else{
        
        cout << "User " << userId << " timed out waiting for the printer \n";
    }
}





