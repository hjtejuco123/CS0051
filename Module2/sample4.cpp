
#include <iostream>
#include <thread>
using namespace std;

void studentTask(string name);

int main()
{
    cout << "Teacher (main thread) start the class " << endl;
    thread student1(studentTask, "Hadji");
    thread student2(studentTask, "John");
    cout << "Teacher prepares for the next lesson " << endl;
    student1.join(); //wait for hadji to finish
    student2.join(); //wait for john to finish the task 
    cout << "Class dismissed " << endl;
    return 0;
}
void studentTask(string name)
{
    cout << name << " is doing their homework " << endl;
}
