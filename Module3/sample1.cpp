// Sharing of resources
#include <iostream>
using namespace std;

int counter = 0; //global variable

void incrementCounter(int iterations);

int main()
{
    const int iterations = 5;
    
    incrementCounter(iterations); //first call 
    incrementCounter(iterations); //second call
    return 0;
}

//increment
void incrementCounter(int iterations)
{
    for (int i = 0; i<iterations;i++){
        ++counter;
        cout << "Counter " << counter 
                << " ,iteration: " << i+1 << endl;
    }
}
