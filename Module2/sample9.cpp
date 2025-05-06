//sleep_for //pause thread execution

#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

int main()
{
    cout << "Start countdown \n" ;
    for (int i = 5 ;i>0; i--){
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Liftoff !!!\n";

    return 0;
}
