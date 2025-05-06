//joinable //true or false 
#include <thread>
#include <iostream>
using namespace std;

void simpleTask();

int main()
{
    thread t(simpleTask);
    t.join();
    if (t.joinable()) {
        cout << "Thread can be joined \n";
       
    }else{
        cout << "Thread cannot be joined. \n";
        
    }

    return 0;
}

void simpleTask(){
    cout << "Task running \n";
}
