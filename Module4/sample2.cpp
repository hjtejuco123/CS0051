//counting semaphore
//parking lot (available slot)
//count -> max (3) min (1) 

#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;

counting_semaphore<3> parkingSlots(3); //3 cars are allowed in at once

void parkCar(int carId);

int main()
{
    thread cars[5];
    for (int i = 0; i<5; i++){
        cars[i] = thread(parkCar, i+1);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    for (int i = 0; i<5;i++){
        cars[i].join();
    }

    return 0;
}

void parkCar(int carId)
{
    cout << "Car " << carId << " is waiting for a parking slot ...\n";
    parkingSlots.acquire(); //decremented from parkingSlots(3)
    cout << "Car " << carId << " has parked ... \n";
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Car " << carId << " is leaving the parking lot ... \n";
    parkingSlots.release(); // incremented from the parkingSlots()
}




