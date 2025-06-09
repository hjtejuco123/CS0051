//binary semaphore
//shared printer 
//printer can use (shared) by one user at a time
//semaphore -> prevent others from printing until (user is done using it) 

#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;

binary_semaphore printer(1); //only one thread can use the printer at a time 

void usePrinter(int userId);

int main()
{
    thread t1(usePrinter,1);
    thread t2(usePrinter,2);
    t1.join();
    t2.join();
    return 0;
}

void usePrinter(int userId)
{
    cout << "User " << userId << " is waiting to use the printer ....\n";
    printer.acquire(); //decrements (1) -> (0) -> lock the printer 
    cout << "User " << userId << " is printing ....\n";
    this_thread::sleep_for(chrono::seconds(2)); //delay
    cout << "User " << userId << " is done printing ....\n";
    printer.release(); //increments the internal counter (0) -> (1) -> printer is available
}


