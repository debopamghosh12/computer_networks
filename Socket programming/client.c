#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // 1. Create Socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("[-] Socket error");
        exit(1);
    }
    printf("[+] Client Socket Created.\n");

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 2. Connect to Server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("[-] Connection Error");
        exit(1);
    }
    printf("[+] Connected to Server.\n");

    // 3. Send Data
    bzero(buffer, 1024);
    strcpy(buffer, "Hello Server, this is Client!");
    printf("Client: Sending message...\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // 4. Receive Reply
    bzero(buffer, 1024);
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // 5. Close
    close(client_socket);
    printf("[+] Disconnected.\n");

    return 0;
}