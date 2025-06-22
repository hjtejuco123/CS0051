#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

// Simulated ML model training (in background)
//An epoch in machine learning represents one complete pass through the
//entire training dataset. It ensures that every data sample is used to 
//update the model’s parameters, optimizing performance over multiple epochs.
string trainModel() {
    for (int epoch = 1; epoch <= 5; ++epoch) {
        cout << "[Training] Epoch " << epoch << "/5 - Adjusting weights...\n";
        this_thread::sleep_for(chrono::milliseconds(600));
    }
    return "[Training] Model training complete.";
}

// Simulated prediction preparation (runs in main thread)
void preparePredictionInput() {
    for (int i = 1; i <= 5; ++i) {
        cout << "[Input Prep] Preparing sample " << i << "/5...\n";
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << "[Input Prep] Input preparation complete.\n";
}

// Simulated model prediction (after training)
string makePrediction() {
    for (int step = 1; step <= 3; ++step) {
        cout << "[Prediction] Running inference step " << step << "/3...\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return "[Prediction] Predicted class: 'PASS'";
}

int main() {
    cout << "Machine Learning Workflow Simulation Started\n\n";

    // Launch training in the background
    future<string> trainingFuture = async(launch::async, trainModel);

    // Prepare input data while model is training
    preparePredictionInput();

    // Wait for training to complete
    cout << trainingFuture.get() << endl;

    // After training, simulate prediction in background
    future<string> predictionFuture = async(launch::async, makePrediction);

    // Wait for prediction to finish
    cout << predictionFuture.get() << endl;

    cout << "\n✅ Machine Learning simulation complete.\n";
    return 0;
}
