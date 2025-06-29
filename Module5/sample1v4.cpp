//with PID

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h> // For wait()

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
        const char* msg = "Hello from parent";

        cout << "[Parent] PID: " << getpid() << endl;

        write(pipefd[1], msg, strlen(msg) + 1); // Write message to pipe
        close(pipefd[1]); // Close writing end

        wait(NULL); // Wait for child to finish
    } 
    else if (pid == 0) { // Child process
        close(pipefd[1]); // Close writing end

        cout << "[Child]  PID: " << getpid() << ", PPID: " << getppid() << endl;

        read(pipefd[0], buffer, sizeof(buffer)); // Read message from pipe
        cout << "Child received: " << buffer << endl;
        close(pipefd[0]); // Close reading end
    } 
    else { // Fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}
