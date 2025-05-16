//read-write lock
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex rwLock;
int sharedData = 0;

void reader(int id){
    rwLock.lock();
    cout << "Reader "<< id << " reads: " << sharedData << endl;
    rwLock.unlock();
}
void writer(int id){
    rwLock.lock();
    sharedData += 1;
    cout << "Writer " << id << " writes: " << sharedData << endl;
    rwLock.unlock();
}

int main()
{
    thread readers[] = {thread(reader,1), thread(reader,2)};
    thread writers[] = {thread(writer,1), thread(writer,2)};
    
    readers[0].join();
    readers[1].join();
    writers[0].join();
    writers[1].join();
    
    
    return 0;
}
