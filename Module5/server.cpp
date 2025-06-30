#include <iostream>
#include <string>
#include <vector>
#include <algorithm>      
#include <cstring>        
#include <unistd.h>       
#include <sys/socket.h>   // socket, bind, listen, accept, send, recv
#include <arpa/inet.h>    // inet_ntoa, htons, etc.
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct ClientInfo {
    int socket;
    std::string name;
};

std::vector<ClientInfo> clients;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const std::string& sender,
                       const std::string& message,
                       int sender_socket)
{
    pthread_mutex_lock(&clients_mutex);
    for (const auto& client : clients) {
        if (client.socket != sender_socket) {
            std::string formatted = sender + ": " + message;
            send(client.socket, formatted.c_str(), formatted.size(), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void* handle_client(void* arg)
{
    int client_socket = *static_cast<int*>(arg);
    delete static_cast<int*>(arg);               // free heap copy

    char buffer[BUFFER_SIZE]{};

    /* Get client name */
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
        close(client_socket);
        return nullptr;
    }
    std::string client_name(buffer);

    /* Add to list */
    pthread_mutex_lock(&clients_mutex);
    clients.push_back({client_socket, client_name});
    pthread_mutex_unlock(&clients_mutex);

    std::cout << client_name << " joined the chat.\n";
    broadcast_message("Server", client_name + " has joined the chat!", client_socket);

    /* Chat loop */
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (n <= 0) break;                       // client quit / error

        std::cout << client_name << ": " << buffer << '\n';
        broadcast_message(client_name, buffer, client_socket);
    }

    /* Remove client */
    pthread_mutex_lock(&clients_mutex);
    clients.erase(std::remove_if(clients.begin(), clients.end(),
        [client_socket](const ClientInfo& c){ return c.socket == client_socket; }),
        clients.end());
    pthread_mutex_unlock(&clients_mutex);

    broadcast_message("Server", client_name + " has left the chat.", client_socket);
    close(client_socket);
    return nullptr;
}

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) { perror("socket"); return 1; }

    /* Allow fast restart (optional) */
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in server_addr{};
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port        = htons(PORT);

    if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind"); return 1;
    }
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen"); return 1;
    }
    std::cout << "Server listening on port " << PORT << "...\n";

    while (true) {
        sockaddr_in client_addr{};
        socklen_t   len = sizeof(client_addr);
        int client_socket = accept(server_socket, (sockaddr*)&client_addr, &len);
        if (client_socket < 0) { perror("accept"); continue; }

        int* p = new int(client_socket);         // per-thread copy
        pthread_t tid;
        pthread_create(&tid, nullptr, handle_client, p);
        pthread_detach(tid);
    }
    close(server_socket);
}
