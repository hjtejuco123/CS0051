
//counting semaphore
//try_acquire()

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

counting_semaphore<1> parkingLot(0); // no spots available

void carTryAcquire(int id);

int main()
{
    thread car1 (carTryAcquire,1);
    car1.join();
    return 0;
}


void carTryAcquire(int id)
{
    cout << "Car " << id << " attempts to park immediately ....\n";
    if (parkingLot.try_acquire()){
        cout << "Car " << id << " parked successfully \n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Car " << id << " is leaving \n";
        parkingLot.release();
    }else{
        cout << "Car " << id << " could not find a parking slot.. \n ";
    }
}





