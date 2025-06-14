#include <iostream>
#include <thread>
#include <latch>
#include <chrono>

using namespace std;

latch buildLatch(3); 

void compileModule(int id) {
    cout << "Compiling module " << id << "...\n";
    this_thread::sleep_for(chrono::milliseconds(500 * id));
    cout << "Module " << id << " compiled.\n";
    buildLatch.count_down(); 
}

void tryFinalLink() {
    cout << "Checking if ready for linking (non-blocking)...\n";
    if (buildLatch.try_wait()) {
        cout << "All modules compiled. Linking now.\n";
    } else {
        cout << "Not ready yet, will block until done.\n";
        buildLatch.wait(); 
        cout << "Count reached zero. Now linking.\n";
    }
}

int main() {
    thread t1(compileModule, 1);
    thread t2(compileModule, 2);
    thread t3(compileModule, 3);
    thread linker(tryFinalLink);

    t1.join(); t2.join(); t3.join();
    linker.join();

    cout << "Build process complete.\n";
    return 0;
}
