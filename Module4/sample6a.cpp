//race

#include <iostream>
#include <thread>
#include <barrier>
#include <chrono>
#include <mutex>

using namespace std;

const int NUM_RUNNER = 5;
int arrivedCount = 0;   //shared counter 
mutex countMutex;       //protect access to the arrivedCount

//barrier 
barrier staringLine(NUM_RUNNER, []() {
    cout << "\n>>> All runners are at the starting line. Ready. Set. Go.!\n\n";   
});

void runner(int id);

int main(){
    thread runners[NUM_RUNNER];
    for (int i = 0; i<NUM_RUNNER; i++) {
        runners[i] = thread(runner,i+1);
    }
    
    for (int i = 0; i<NUM_RUNNER; i++) {
        runners[i].join();
    }
    
    cout << "\n All runners have started the race \n";
    return 0;
}

void runner(int id){
    cout << "Runner " << id << " is warming up...\n";
    this_thread::sleep_for(chrono::milliseconds(300*id));
    //mutex 
    {
        lock_guard<mutex> lock(countMutex);
        arrivedCount++;
        cout << "Runner "<<id<< " is ready at the staring line. "
            << "( Arrived " << arrivedCount << "/" << NUM_RUNNER << ")\n";
        
    }
    staringLine.arrive_and_wait(); //block until all the runners are ready 
    
    cout << "Runner " << id << " starts running \n";
}

