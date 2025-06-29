//pipe
//customer -> write (order slip) -> barista read (order) -> prepare it

#include <iostream>
#include <string>

using namespace std;

string order_slip;

void customer();
void barista();

int main(){
	
	customer(); //write into the order slip order  -> write
	barista(); //read from the order slip the order -> read
	return 0;
}

void customer(){

	order_slip = "[Customer] - ordered - 1 iced latte. extra shot";
	//cout << order_slip;
}
void barista(){
	
	cout << "[Barista] - read the order: " << order_slip << endl;
	cout << "[Barista] - will prepare the order... " << endl; 

}
