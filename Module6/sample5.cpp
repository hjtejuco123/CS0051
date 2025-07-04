// square_chrono_plain.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>      // timing
#include <openacc.h>   // OpenACC pragmas

using namespace std;

void generateDataFile(const string &filename, int size) {
    ofstream outFile(filename);
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; ++i) outFile << (rand() % 100) << '\n';
}

void readDataFile(const string &filename, int arr[], int size) {
    ifstream inFile(filename);
    for (int i = 0; i < size; ++i) inFile >> arr[i];
}

void writeDataFile(const string &filename, int arr[], int size) {
    ofstream outFile(filename);
    for (int i = 0; i < size; ++i) outFile << arr[i] << '\n';
}

int main() {
    int N;
    cout << "Enter the number of data points: ";
    cin  >> N;

    const string inputFile  = "data.txt";
    const string outputFile = "output.txt";

    int* arr = new int[N];              

    generateDataFile(inputFile, N);
    readDataFile(inputFile, arr, N);

    /* ---------- GPU kernel + explicit chrono timing ---------- */
    typedef std::chrono::high_resolution_clock            Clock;
    typedef std::chrono::high_resolution_clock::time_point TimePoint;
    TimePoint t_start = Clock::now();

    #pragma acc kernels
    for (int i = 0; i < N; ++i)
        arr[i] *= arr[i];                  // square in-place

    TimePoint t_end = Clock::now();
    std::chrono::duration<double, std::milli> elapsed = t_end - t_start;
    double elapsed_ms = elapsed.count();


    writeDataFile(outputFile, arr, N);

    cout << "\nFirst ten results:\n";
    int limit = (N < 10 ? N : 10);        
    for (int i = 0; i < limit; ++i) cout << arr[i] << ' ';
    cout << "\n\nKernel + transfer time: " << elapsed_ms << " ms\n";

    delete[] arr;
    return 0;
}
