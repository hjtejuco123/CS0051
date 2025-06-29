//signal

/*
A fire alarm goes off (signal), and people inside a room take action.
This mimics signals — they don’t carry data, just notify.
*/


#include <iostream>
using namespace std;

// Signal simulation using a flag
bool fire_alarm_triggered = false;

void fireAlarmSystem() {
    fire_alarm_triggered = true; // Alarm goes off
}

void studentResponse() {
    if (fire_alarm_triggered) {
        cout << "Fire alarm triggered! Evacuate the building!" << endl;
    } else {
        cout << "All is calm. Continue studying." << endl;
    }
}

int main() {
    fireAlarmSystem();   // Trigger signal
    studentResponse();   // React to signal
    return 0;
}
