
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>

using namespace std;

const int NUM_MODELS = 3;

mutex coutMutex;
bool modelTrained[NUM_MODELS]; // training flags

// Model training (per thread)
void trainModel(int id) {
    for (int epoch = 1; epoch <= 5; ++epoch) {
        lock_guard<mutex> lock(coutMutex);
        cout << "[Training M" << id << "] Epoch " << epoch << "/5\n";
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    {
        lock_guard<mutex> lock(coutMutex);
        cout << "[Training M" << id << "] Training complete.\n";
        modelTrained[id] = true;
    }
}

// Prediction (async task)
string predict(int id) {
    for (int i = 1; i <= 3; ++i) {
        lock_guard<mutex> lock(coutMutex);
        cout << "[Prediction M" << id << "] Step " << i << "/3\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    return "[Prediction M" + to_string(id) + "] Predicted class: 'PASS'";
}

// Input preparation (main thread)
void prepareInput() {
    for (int i = 1; i <= 5; ++i) {
        lock_guard<mutex> lock(coutMutex);
        cout << "[Input Prep] Preparing data sample " << i << "/5\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    lock_guard<mutex> lock(coutMutex);
    cout << "[Input Prep] Input preparation done.\n";
}

int main() {
    cout << "ML Simulation with Array of Models (Threads + Futures)\n\n";

    thread trainers[NUM_MODELS];
    future<string> predictions[NUM_MODELS];

    // Launch model trainers
    for (int i = 0; i < NUM_MODELS; ++i) {
        modelTrained[i] = false;
        trainers[i] = thread(trainModel, i);
    }

    // Main thread prepares input
    prepareInput();

    // Wait for training to complete
    for (int i = 0; i < NUM_MODELS; ++i) {
        trainers[i].join();
    }

    // Launch predictions asynchronously
    for (int i = 0; i < NUM_MODELS; ++i) {
        predictions[i] = async(launch::async, predict, i);
    }

    // Collect prediction results
    for (int i = 0; i < NUM_MODELS; ++i) {
        cout << predictions[i].get() << endl;
    }

    cout << "\n✅ All models trained and predictions complete.\n";
    return 0;
}
