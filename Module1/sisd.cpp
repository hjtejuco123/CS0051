//SISD 
//Single instruction, Single data 
//One instruction, one data stream 
//Basic Calculator

#include <iostream>
using namespace std;

int main(){
    int data = 10;
    cout << "SISD " << endl;
    cout << "Initial Data " << data << endl;
    data = data * 2;
    cout << "After processing " << data << endl;
    return 0;
}

