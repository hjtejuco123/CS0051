//barrier
//A barrier forces threads to wait until all have reached a certain point before continuing.
//Example race 


#include <iostream>
#include <thread>
#include <barrier>

using namespace std;

barrier sync_point(3); 

void prepare(int id) {
    cout << "Thread " << id << " is ready.\n";
    sync_point.arrive_and_wait();
    cout << "Thread " << id << " is starting!\n";
}

int main() {
    thread t1(prepare, 1);
    thread t2(prepare, 2);
    thread t3(prepare, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
