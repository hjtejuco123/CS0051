//Scenario: Students wait until the teacher says "Start!"
//Solution: Condition variable acts like a starting whistle.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex exam_mutex;
condition_variable exam_cv;
bool exam_started = false;

void student(int id) {
    cout << "Student " << id << " is ready!\n";
    unique_lock<mutex> lock(exam_mutex);
    exam_cv.wait(lock, []{ return exam_started; });
    cout << "Student " << id << " starts writing!\n";
}

void teacher() {
    this_thread::sleep_for(chrono::seconds(2)); // Prep time
    {
        lock_guard<mutex> lock(exam_mutex);
        exam_started = true;
        cout << "Teacher: START WRITING NOW!\n";
    }
    exam_cv.notify_all(); // Wake all students
}

int main() {
    thread t(teacher);
    thread students[3] = {
        thread(student, 1),
        thread(student, 2),
        thread(student, 3)
    };
    
    t.join();
    for (int i = 0; i < 3; i++) {
        students[i].join();
    }
    return 0;
}
