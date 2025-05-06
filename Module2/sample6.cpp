//detach() //do your own thing
//you and your friend are working a project
//YOU - write the report (Main thread)
//FRIEND - collects the data (New Thread)
//detach() - dont wait - finish your work independently 
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void collectData();

int main()
{
    cout << "YOU: Starting to write the Report " << endl;
    thread friendThread (collectData); //friends starts to collect data
    friendThread.detach(); //DONT WAIT for your friend 
    cout << "YOU: Submit the report " << endl;
    this_thread::sleep_for(chrono::seconds(6)); 

    return 0;
}
void collectData(){
    cout << "FRIEND: Collecting data 5 seconds " << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "FRIND: Finish Collecting Data " << endl;

    
    
    
}
