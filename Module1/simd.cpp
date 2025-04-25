//SIMD
//Single instruction, Multiple data 
//GPU Processing 


#include <iostream>
using namespace std;

int main(){
    int data[4] = {10,20,30,40};
    cout << "SIMD " << endl;
    for (int i = 0; i<4;i++){
        cout << "Processor: " << i+1 << " x2 " << endl;
        data[i] = data[i] * 2;
        cout << data[i] << endl;
        
    }
    
    
    return 0;
}

