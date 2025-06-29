
//displays the PID after the parent sends the input and after the child outputs the received message. 
//This helps clearly track which process did what and when.


#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close reading end

        cout << "[Parent] PID: " << getpid() << endl;
        cout << "Enter a message for the child: ";
        string input;
        getline(cin, input); // Read user input

        write(pipefd[1], input.c_str(), input.length() + 1); // Send input to pipe
        cout << "[Parent] Message sent. PID: " << getpid() << endl;

        close(pipefd[1]); // Close writing end
        wait(NULL); // Wait for child to finish
    } 
    else if (pid == 0) { // Child process
        close(pipefd[1]); // Close writing end

        read(pipefd[0], buffer, sizeof(buffer)); // Read message from pipe
        cout << "[Child]  Message received: " << buffer << endl;
        cout << "[Child]  PID: " << getpid() << ", PPID: " << getppid() << endl;

        close(pipefd[0]); // Close reading end
    } 
    else { // Fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}
