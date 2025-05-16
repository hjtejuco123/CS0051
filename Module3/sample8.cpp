
//c++17
#include <iostream>
#include <thread>
#include <shared_mutex>
using namespace std;

shared_mutex rwLock;
int sharedData = 0;

void reader(int id) {
    rwLock.lock_shared(); 
    cout << "Reader " << id << " reads: " << sharedData << endl;
    rwLock.unlock_shared();
}

void writer(int id) {
    rwLock.lock(); 
    sharedData += 1;
    cout << "Writer " << id << " writes: " << sharedData << endl;
    rwLock.unlock(); 
}

int main() {
    thread readers[] = {thread(reader, 1), thread(reader, 2)};
    thread writers[] = {thread(writer, 1), thread(writer, 2)};

    for (auto& t : readers) t.join();
    for (auto& t : writers) t.join();

    return 0;
}
