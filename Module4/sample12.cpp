//Asynchronous - > File Download with Data Processing 

#include <iostream>
#include <future>
#include <chrono>
#include <string>

using namespace std;

void simulatFileDownload(const string& filename, int fileSizeMB);
int processData(int start, int end);

int main(){
    cout << "[Main] Start async file download task...\n";
    future <void> downloadTask = async(launch::async, simulatFileDownload,"example.zip", 10);
    cout << "[Main] doing other work while waiting \n";
    
    int result = processData(1,10);
    cout << "[Main] Data processing Completed. sum of squares " << result << "\n";
    
    cout << "[Main] waiting for download to finish \n";
    downloadTask.wait();
    cout << "[Main] file download completed \n";
    
    return 0;
}


void simulatFileDownload(const string& filename, int fileSizeMB)
{
    cout << "[Task] Start to download the file " << filename << "(" << fileSizeMB 
        << "MB...\n";
    
    for (int i = 0; i<= fileSizeMB; i++){
        cout << "[Task] Downloaded " << i << " MB out of " << fileSizeMB << " MB..\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }    
    cout << "Task Download of " << filename << " Completed \n";
    
    
    
}
int processData(int start, int end)
{
    cout << "[Main] Processing data from " <<start<< " to " << end << "...\n";
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i*i;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Main processed square of " << i << " , current sum " << sum << "\n";
    }
    return sum;
    
}




