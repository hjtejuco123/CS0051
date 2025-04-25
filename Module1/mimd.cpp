//MIMD
//Multiple instruction, Multiple data 

#include <iostream>
using namespace std;

int main(){
    int data[4] = {5,10,15,20};
    cout << "MIMD " << endl;
    cout << "Processor 1 (Add 10) " << data[0] + 10 << endl;
    cout << "Processor 2 (Multiply by 2) " << data[1] * 2 << endl;
    cout << "Processor 3 (Subtract 5) " << data[2] - 5 << endl;
    cout << "Processor 4 (Divide by 2) " << data[3] / 2 << endl;
    
    return 0;
}

