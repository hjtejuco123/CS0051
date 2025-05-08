#include <iostream>
#include <thread>

using namespace std;

void worker() {
    cout << "Worker thread ID: " << this_thread::get_id() << endl;
}

int main() {
    cout << "Main thread ID: " << this_thread::get_id() << endl;
    
    thread t(worker);
    cout << "Created thread ID: " << t.get_id() << endl;
    
    t.join();
    return 0;
}
