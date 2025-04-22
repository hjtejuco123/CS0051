//sequential computing 

#include <iostream>
#include <chrono> //delays time computation
#include <thread> //this_thread::sleep_for
using namespace std;

void sequentialComputing(){
    cout << "Sequential Computing \n";
    for (int i = 1; i<=10; i++){
        cout << "Count: " << i << "\n";
        this_thread::sleep_for (chrono::milliseconds(200));
    }
}


int main(){
    sequentialComputing();
    return 0;
}
