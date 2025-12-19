#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];

    // 1. Create Socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("[-] Socket error");
        exit(1);
    }
    printf("[+] Server Socket Created.\n");

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    // 2. Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("[-] Bind error");
        exit(1);
    }
    printf("[+] Bind to Port 8080 Successful.\n");

    // 3. Listen
    if (listen(server_socket, 5) == 0) {
        printf("[...] Listening...\n");
    } else {
        perror("[-] Listen error");
    }

    // 4. Accept Connection
    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+] Client Connected.\n");

    // 5. Receive Data
    bzero(buffer, 1024);
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client says: %s\n", buffer);

    // 6. Send Reply
    bzero(buffer, 1024);
    strcpy(buffer, "Hello from Server! I got your message.");
    printf("Server: Sending reply...\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // 7. Close
    close(client_socket);
    close(server_socket);
    printf("[+] Connection Closed.\n");

    return 0;
}