//4 task

#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

//task1 upload homework
string uploadHomework();
//task2 download lecture
string downloadLecture();
//task3 compress project folderr
string compressProject();
//task4 send email 
string sendEmail();

int main(){
    cout << "Student starts multiple-task\n";
    
    //launch task (4 task asynchronously)
    // std::future<int> f2 = std::async(std::launch::async, []{ return 8; });
    future<string> f1 = async(launch::async, uploadHomework);
    future<string> f2 = async(launch::async, downloadLecture);
    future<string> f3 = async(launch::async, compressProject);
    future<string> f4 = async(launch::async, sendEmail);
    
    cout << "waiting for all task to complete \n";
    cout << f1.get() << endl;
    cout << f2.get() << endl;
    cout << f3.get() << endl;
    cout << f4.get() << endl;
    
    cout << "All task are done!\n";
    return 0;
}

//task1 upload homework
string uploadHomework(){
    for (int i = 1; i<=3; i++) {
        cout << "[Task - Upload] - Uploading part " << i << "/3\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Task - Upload] - Homework Uploaded complete...";
    
}
//task2 download lecture
string downloadLecture(){
    for (int i = 1; i<=4; i++) {
        cout << "[Task - Download] - Download part " << i << "/4\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Task - Download] - Lecture download complete...";
    
    
}
//task3 compress project folderr
string compressProject(){
    for (int i = 1; i<=3; i++) {
        cout << "[Task - Compress] - Compressing file " << i << "/3\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Task - Compress] -  Compress file complete...";
    
    
}
//task4 send email 
string sendEmail(){
   this_thread::sleep_for(chrono::milliseconds(500));
   return "[Task - Email] - Email sent to instructor.";
}
