#include <iostream>
#include <thread>

using namespace std;

void task1() { cout << "Task 1\n"; }
void task2() { cout << "Task 2\n"; }

int main() {
    thread t1(task1);
    thread t2(task2);
    
    cout << "Before swap:\n";
    cout << "t1 ID: " << t1.get_id() << endl;
    cout << "t2 ID: " << t2.get_id() << endl;
    
    t1.swap(t2);
    
    cout << "After swap:\n";
    cout << "t1 ID: " << t1.get_id() << endl;
    cout << "t2 ID: " << t2.get_id() << endl;
    
    t1.join();
    t2.join();
    return 0;
}
