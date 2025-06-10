//binary semaphore using array
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
    const int totalUsers = 5;
    thread users[totalUsers]; //Array thread 
    
    for (int i = 0; i< totalUsers; i++) {
        users[i] = thread(usePrinter, i+1);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    for (int i = 0; i < totalUsers; i++) {
        users[i].join();
    }
    
    
    return 0;
}
//printer(1)
void usePrinter(int userId)
{
    cout << "User " << userId << " is waiting to use the printer ....\n";
    printer.acquire(); //decrements (1) -> (0) -> lock the printer 
    cout << "User " << userId << " is printing ....\n";
    this_thread::sleep_for(chrono::seconds(2)); //delay
    cout << "User " << userId << " is done printing ....\n";
    printer.release(); //increments the internal counter (0) -> (1) -> printer is available
}






