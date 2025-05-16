
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
    //version 1
    // thread readers[] = {thread(reader, 1), thread(reader, 2)};
    // thread writers[] = {thread(writer, 1), thread(writer, 2)};

    // for (auto& t : readers) t.join();
    // for (auto& t : writers) t.join();
    

    //version 2
     // Create reader threads
    thread readers[2];
    readers[0] = thread(reader, 1);
    readers[1] = thread(reader, 2);

    // Create writer threads
    thread writers[2];
    writers[0] = thread(writer, 1);
    writers[1] = thread(writer, 2);

    // Join reader threads
    for (int i = 0; i < 2; i++) {
        readers[i].join();
    }

    // Join writer threads
    for (int i = 0; i < 2; i++) {
        writers[i].join();
    }

    return 0;
}
