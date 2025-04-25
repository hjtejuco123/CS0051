//MISD
//Multiple instruction, Single data 

#include <iostream>
using namespace std;

int main(){
    int data = 50;
    cout << "MISD " << endl;
    cout << "Processor 1 (add 10) " << data + 10 << endl;
    cout << "Processor 2 (Square) " << data * data << endl;
    cout << "Processor 3 (Divide by 2) " << data / 2 << endl;
    
    return 0;
}

