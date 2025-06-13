#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;
//binary semaphore with try_acquire
binary_semaphore printer(1); //only one thread can use the printer at a time 
void tryNow(int userId);
int main()
{
    //lock the printer 
    //printer.acquire();
    thread t1(tryNow,1);
    this_thread::sleep_for(chrono::seconds(1));
    printer.release();
    
    t1.join();
    
    return 0;
}

void tryNow(int userId)
{
    cout << "User " << userId << " is waiting to use the printer ....\n";
    if (printer.try_acquire()) {
        cout << "User " << userId << " acquired the printer....\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "User " << userId << " is done printing ....\n";
         printer.release();
    }else{
        
        cout << "User " << userId << " could NOT acquire printer, Try Again \n";
    }
}





