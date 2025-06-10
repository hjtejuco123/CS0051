
//counting semaphore
//try_acquire_until

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

counting_semaphore<1> parkingLot(0); // no spots available

void carTryUntil(int id);

int main()
{
    thread car1 (carTryUntil,3);
    car1.join();
    return 0;
}


void carTryUntil(int id)
{
    chrono::steady_clock::time_point deadline = chrono::steady_clock::now() + chrono::seconds(4);
    cout << "Car " << id << " will wait until a deadline of 4 seconds ... \n";
    if (parkingLot.try_acquire_until(deadline)){
        cout << "Car " << id << " parked before dealine \n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Car " << id << " is leaving \n";
        parkingLot.release();
    }else{
        cout << "Car " << id << " time out and left ... \n ";
    }
}





