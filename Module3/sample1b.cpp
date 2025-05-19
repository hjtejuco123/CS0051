// Sharing of resources using thread 
// problems -> race condition for thread -> corrupt counter
#include <iostream>
#include <thread>
using namespace std;

int counter = 0; //global variable

void incrementCounter(int iterations);

int main()
{
    const int iterations = 5;
    
    thread t1(incrementCounter,iterations); //first call 
    thread t2(incrementCounter,iterations); //second call
    t1.join();
    t2.join();
    
    return 0;
}

//increment
void incrementCounter(int iterations)
{
    for (int i = 0; i<iterations;i++){
        ++counter; //race condition risks
        cout << "Counter " << counter 
                << " ,iteration: " << i+1 << endl;
    }
}
