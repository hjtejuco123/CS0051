//Async Factorial Calculator
//5! = 5*4*3*2*1 
/*
    STEP 1: Current value 1 
    STEP 2: Current value 2 
    STEP 3: Current Value 6 
    STEP 4: Current Value 24 
    STEP 5: Current Value 120
*/
//Two threads (MAIN one task - Compute for the FACTORIAL)

#include <iostream>
#include <chrono>
#include <future>

using namespace std;

//factorial
int longTask(int n);


int main(){
    cout << "[MAIN] Starting async task ...\n"; 
    //launch factorial computation future asynchronouse task  
    future<int> result = async (launch::async, longTask, 5);
    //doing other task 
    cout << "[MAIN] Doing other work while waiting\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "[MAIN] Still Working....\n";
    this_thread::sleep_for(chrono::seconds(2));
    
    //retrieve result
    cout << "[MAIN] waiting for the result \n";
    int factorial = result.get();
    cout << "[MAIN] Factorial Result " << factorial << endl;
    return 0;
}

int longTask(int n)
{
    cout << "[TASK] Computing for  the factorial of " << n << "...\n";
    this_thread::sleep_for(chrono::seconds(3));
    int result = 1;
    for (int i = 1; i<=n;i++) {
        result *= i;
        cout << "[BG-TASK] STEP " << i << ": current value " << result << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "[TASK] Factorial Computation Complete.\n";
    return result;
}


