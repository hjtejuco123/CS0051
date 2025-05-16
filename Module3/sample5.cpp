//try lock
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int sharedData = 0;

void updateData(int id){
    if (mtx.try_lock()){
        cout << "Thread " << id << " acquired the lock " << endl;
        sharedData += 1;
        mtx.unlock();
    }else{
         cout << "Thread " << id << " could not acquire the lock " << endl;
    }
}

int main()
{
    
    thread t1 (updateData, 1);
    thread t2 (updateData, 2);
    
    t1.join();
    t2.join();

    cout << "Final value of SharedData " << sharedData << endl;
    return 0;
}
