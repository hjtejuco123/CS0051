//Concurrency computing 

#include <iostream>
#include <chrono> //delays time computation
#include <thread> //this_thread::sleep_for
using namespace std;

void concurrentComputing(){
    cout << "Concurrent Computing \n";
    int odd = 1, even = 2;
    while(odd <= 9 || even <= 10) {
        if (odd <=9) {
            cout << "Odd " << odd << "\n";
            odd += 2;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        if (even <= 10) {
            cout << "Even " << even << "\n";
            even += 2;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }
}


int main(){
    concurrentComputing();
    return 0;
}
