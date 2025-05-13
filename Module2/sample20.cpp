
//ATM Machine
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//Shared Resource
int accoutBalance = 1000; //Initial Balance
mutex atmMutex; // protect the access to the accounts

void withdrawMoney(string userName, int amount);
int main()
{
    //Users 
    thread user1(withdrawMoney, "Hadji", 400);
    thread user2(withdrawMoney, "Joan", 700);
    thread user3(withdrawMoney, "James", 500);

    user1.join();
    user2.join();
    user3.join();
    
    cout << "Final Account Balance " << accoutBalance << endl;

    return 0;
}

void withdrawMoney(string userName, int amount)
{
    atmMutex.lock(); //lock 
    
    if (accoutBalance >= amount) {
        cout << userName << " is withdrawing " << amount << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); //processing
        accoutBalance -= amount;
        cout << userName << " successfully widrew " << amount <<endl;
        cout << "Remaining balance is " << accoutBalance << endl;
    }else {
        cout << userName << " failed to withdraw " << amount << endl;    
    }
    
    atmMutex.unlock(); //lock 
    
}
