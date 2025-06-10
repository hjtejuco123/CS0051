//counting semaphore
//parking lot (available slot)
//count -> max (3) min (1) 

#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>
#include <mutex>
#include <atomic> //safely share the resources. it prevent race condition

using namespace std;

const int MAX_SLOTS = 3;
counting_semaphore<MAX_SLOTS> parkingSlots(MAX_SLOTS); //3 cars are allowed in at once

//internal count ng semaphore 
atomic<int> occupiedSlots(0); 
mutex printMutex;

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

    {
        lock_guard<mutex> lock(printMutex);
        cout << "Car " << carId << " is arriving.\n";
    }
    
    if (occupiedSlots == MAX_SLOTS) {
        cout << "Car " << carId << ": Parking is FULL and waiting for slot..\n";
    }else{
        cout << "Car " << carId << " is waiting for a parking slot...\n";
    }
    
    parkingSlots.acquire(); //acquire a slot 
    int current = ++occupiedSlots;
    
    {
        lock_guard<mutex> lock(printMutex);
        cout << "Car " << carId << " has parked. (Occupied: " 
            << current << "/" << MAX_SLOTS << ")\n" ;
    }
    
    this_thread::sleep_for(chrono::seconds(3));
    current = --occupiedSlots;
    parkingSlots.release(); 
    
    {
        lock_guard<mutex> lock(printMutex);
        cout << "Car " << carId << " is leaving. (Occupied: " 
            << current << "/" << MAX_SLOTS << ")\n" ;
        if (current < MAX_SLOTS) {
            cout << "Slot is Empty. Available slots: " << (MAX_SLOTS-current) << "\n";
            
        }
    }
    
}
