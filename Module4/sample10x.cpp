//first prog
//simulate loading a webpage (it will take sometime) while preparing ui code
#include <iostream>
#include <future>
#include <chrono>

using namespace std;

string loadContent();

int main()
{
    cout << "Prepare designing the Interface\n";
    
    //loading the content 
    //execute async 
    future<string> content = async(launch::async,loadContent);
    
    cout << "working on UI preparation..\n";
    this_thread::sleep_for(chrono::seconds(2)); //delay 
    
    cout << "Waiting for the content to download...\n";
    cout << content.get() << endl;
    
    return 0;
}

// long-running task
string loadContent()
{
    this_thread::sleep_for(chrono::seconds(5)); //delay 
    return "Page content loaded..";
}
