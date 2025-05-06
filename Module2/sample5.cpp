//you - chop vegetables (main thread)
//friend - cook rice (new thread)
///join (wait)
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
void cookRice(){
    cout << "Friend: Cooking rice (5 sec) " << endl;
    this_thread::sleep_for(chrono::seconds(5)); //cooking time 
    cout << "Friend: Rice is ready ... " <<endl;
    
}

int main()
{
    cout << "YOU: Start chopping vegetables " << endl;
    thread friendThread(cookRice); //start to cook the rice 
    friendThread.join(); //WAIT for your friend to finish cooking the rice
    cout << "YOU: Serve meal together " << endl;
    return 0;
}
