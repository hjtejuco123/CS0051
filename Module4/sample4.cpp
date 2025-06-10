
//counting semaphore
//try_acquire_for

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

counting_semaphore<1> parkingLot(0); // no spots available

void carTryFor(int id);

int main()
{
    thread car1 (carTryFor,2);
    car1.join();
    return 0;
}


void carTryFor(int id)
{
    cout << "Car " << id << " is waiting up to 3 seconds for a parking slot ... \n";
    if (parkingLot.try_acquire_for(chrono::seconds(3))){
        cout << "Car " << id << " parked successfully \n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Car " << id << " is leaving \n";
        parkingLot.release();
    }else{
        cout << "Car " << id << " gave up wating and left ... \n ";
    }
}





