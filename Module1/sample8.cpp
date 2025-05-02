#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void simulateOperation(string opName, int a, int b);

int main()
{
    cout << "Main thread " << this_thread::get_id() << "\n"<<endl;
    int a = 20, b = 4;
    
    thread add(simulateOperation,"Addition",a,b);
    thread sub(simulateOperation,"Subtraction",a,b);
    thread mul(simulateOperation,"Multiplication",a,b);
    thread divi(simulateOperation,"Division",a,b);
    
    add.join();
    sub.join();
    mul.join();
    divi.join();
    
    return 0;
}


void simulateOperation(string opName, int a, int b)
{
    cout << "Starting " << opName 
        << " on Thread ID" << this_thread::get_id() << " .. "<<endl;
    
    
    int result;
    if (opName == "Addition") result = a+b;
    else if (opName == "Subtraction") result = a-b;
    else if (opName == "Multiplication") result = a*b;
    else if (opName == "Division") result= a/b;
    
    cout << "Result: " << result 
        << " (Thread ID : " << this_thread::get_id() << ") \n" << endl;
    
}
