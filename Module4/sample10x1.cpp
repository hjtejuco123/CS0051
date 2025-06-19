
//add program simulation
#include <iostream>
#include <future>
#include <chrono>

using namespace std;

string loadContent();

int main()
{
    cout << "[Main] - Prepare designing the Interface\n";
    //launch background task
    future<string> content = async(launch::async,loadContent);
    
    
    for (int i = 1; i<=2; i++){
        cout << "[Main] - working on UI preparation..task "<< i << ")\n";
        this_thread::sleep_for(chrono::milliseconds(500)); //delay 
    
    }
    
    cout << "[Main]Waiting for the content to download...\n";
    cout << content.get() << endl;
    
    cout << "[Main] - Display final UI with Content..\n";
    return 0;
}

// long-running task
string loadContent()
{
    for (int i = 1; i<=3; i++){
        cout << "[Loading Content] - Loading part of " << i << " /3 task ...\n"; 
        this_thread::sleep_for(chrono::seconds(1)); //delay 
    
    }
    return "[Loaded] - Page content loaded..";
}










