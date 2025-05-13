

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//shared resources
const int MAX_ACCOUNTS = 3;
string accountIds[MAX_ACCOUNTS] = {"Hadji","Joan","James"};
int accoutBalances[3] = {1000,1500,800};
mutex atmMutex;

void withdrawMoney(string userName, string accountId, int amount);

int main()
{
    thread user1(withdrawMoney,"Hadji","Hadjii",400);
    thread user2(withdrawMoney,"Joan","Joan",700);
    thread user3(withdrawMoney,"James","James",900);

    user1.join();
    user2.join();
    user3.join();
    
    cout << "Final Account Balance " <<endl;
    for (int i = 0; i<MAX_ACCOUNTS;i++){
        cout << "Account "<<accountIds[i] << ": " << accoutBalances[i]<<endl;
    }
    
    return 0;
}

void withdrawMoney(string userName, string accountId, int amount)
{
    lock_guard<mutex> lock(atmMutex); //auto lock mutex
    bool accountFound = false;
    int accountIndex = -1;
    
    for (int i = 0; i<MAX_ACCOUNTS; i++){
        if (accountIds[i] == accountId){
            accountIndex = i;
            accountFound = true;
            break;
        }    
    }
    if (!accountFound){
        cout << userName << " failed to withdraw " << amount<<endl;
        cout << "Accout not found" <<endl;
        return;
    }
    
    if (accoutBalances[accountIndex]>=amount){
        
        cout << userName << " is withdrawing " << amount << endl;
        cout << "From account " << accountId << endl;
        accoutBalances[accountIndex] -= amount;
        cout << userName << " successfully withdrew " << amount << endl;
        cout << "Remaining balance is " << accoutBalances[accountIndex] <<endl;
    
    }else{
        cout << userName << " failed to withdraw " << amount<<endl;
    }

}




