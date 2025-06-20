//4 task
#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

//task1 upload homework
string uploadHomework(int studentId);
//task2 download lecture
string downloadLecture(int studentId);
//task3 compress project folderr
string compressProject(int studentId);
//task4 send email 
string sendEmail(int studentId);
void studentTask(int studentId);

int main(){
    
    cout << "Multiple student performing 4 task \n";
    
    const int NUM_STUDENTS = 2;
    thread students[NUM_STUDENTS];
    
    for (int i = 0; i<NUM_STUDENTS;i++){
        students[i]=thread(studentTask, i+1);
    }
    
    for (int i = 0; i<NUM_STUDENTS;i++){
        students[i].join();
    }
    
    cout << "All student completed the task.\n";
    return 0;
}

void studentTask(int studentId) {
    
    cout << "Student " << studentId << " starts multitasking...\n";
    
    //Each task run asynchronously per student 
    future<string> f1 = async(launch::async, uploadHomework,studentId);
    future<string> f2 = async(launch::async, downloadLecture,studentId);
    future<string> f3 = async(launch::async, compressProject,studentId);
    future<string> f4 = async(launch::async, sendEmail,studentId);
    
    cout << "Student " << studentId << " is waiting for task to complete \n";
    
    cout << f1.get() << endl;
    cout << f2.get() << endl;
    cout << f3.get() << endl;
    cout << f4.get() << endl;
    
    cout << "Student " << studentId << " has completed the task. \n";
}

//task1 upload homework
string uploadHomework(int studentId){
    for (int i = 1; i<=3; i++) {
        cout << "[Student " << studentId << "] [Task - Upload] - Uploading part " << i << "/3\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Upload] Student " + to_string(studentId) + " Homework Uploaded complete...";
    
}
//task2 download lecture
string downloadLecture(int studentId){
    for (int i = 1; i<=4; i++) {
        cout << "[Student " << studentId << "] [Task - Download] - Download part " << i << "/4\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Download] " + to_string(studentId) + " Lecture download complete...";
    
    
}
//task3 compress project folderr
string compressProject(int studentId){
    for (int i = 1; i<=3; i++) {
        cout << "[Student " << studentId << "] [Task - Compress] - Compressing file " << i << "/3\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Compress] " + to_string(studentId) + " Compress file complete...";
    
    
}
//task4 send email 
string sendEmail(int studentId){
   this_thread::sleep_for(chrono::milliseconds(500));
   return "[Email] " + to_string(studentId) + "Email sent to instructor.";
}
