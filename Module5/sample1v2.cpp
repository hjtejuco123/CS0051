

//using pipe (pipe(), fork(), read(), write())

#include <iostream>
#include <unistd.h>
#include <cstring> // strlen()
#include <sys/wait.h> //wait()

using namespace std;

int main() {

	int pipefd[2];	//pipefd[0] - read, pipefd[1] - writing
	pid_t pid;
	char buffer[100];


	//create pipe
	//if pipe is < 0 -> failed to create the pipe
	
	if (pipe(pipefd) == -1) {
		perror ("Pipe creation failed");
		return 1;
	}
	
	//fork process 
	pid = fork(); //create child process
	
	if (pid < 0) {
		perror ("Fork Failed");
		return 1;
	}

	if (pid == 0) {
		//child (customer)
		close(pipefd[0]); // close unused read end
		
		const char* order = "1 Iced Latte, extra shot";
		
		write (pipefd[1], order, strlen(order)+1); 
		
		cout <<"[Customer] Order sent to barista. PID "<< getpid() << endl;
		
		close(pipefd[1]); //close write end
	}else{
	
		//parent (barista)
		close(pipefd[1]); // close unused write end
		wait(NULL); //wait until the customer finish writing
		
		read(pipefd[0], buffer, sizeof(buffer)); //read order
		cout << "[Barista] PID: " << getpid() << endl;
		cout << "Barista reads the order " << buffer << endl;
		cout << "Barita prepares the drink " << endl;
		
		close(pipefd[0]);
	}
	
	return 0;
}
