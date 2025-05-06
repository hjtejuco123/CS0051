
#include <iostream>
#include <thread>
using namespace std;

void hello();

int main()
{
    cout << "Hello from Main Function " 
        << this_thread::get_id() <<  endl;
    thread t1(hello); //created the thread
    t1.join(); //wait fro the thread to finish
    cout << "Main function ends... " << endl;
    return 0;
}

void hello(){
    cout << "Hi from function Hello with Thread ID " 
        << this_thread::get_id() << endl;
    
    
}
