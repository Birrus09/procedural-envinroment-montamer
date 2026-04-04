#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int option = 0;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    
    while (true) {
        std::cout << "Waiting for a client to connect..." << std::endl;
        int client_fd = accept(server_fd, nullptr, nullptr);
        std::cout << "Client connected!" << std::endl;
        do {            
            // Buffer to receive data from client
            char buffer[4096] = {0};
            
            // Receive data from client
            std::string response = "ciao nigga, questo è il server di sburbix\n 1) login \n 2) register\n 0) quit\n";
            send(client_fd, response.c_str(), response.length(), 0);
            ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
            std::string received_string(buffer, bytes_received);
            if (received_string == "1\n") {
                option = 1;
            } else if (received_string == "2\n") {
                option = 2;
            }
            else if (received_string == "0\n") {
                option = 0;

            }
            else{
                option = 3;
            }
            

            if (option == 1){
                response = "inserisci username (no spazi): \n";
                send(client_fd, response.c_str(), response.length(), 0);
                recv(client_fd, buffer, sizeof(buffer) - 1, 0);
                std::string username(buffer, bytes_received);
                std::ifstream filein(username + ".txt");
                if (filein.is_open()) {
                    response = "login avvenuto con successo\n";
                } else {
                    response = "utente non trovato\n";
                }
                filein.close();
            }
            if (option == 2){
                response = "inserisci il nome utente (no spazi): \n";
                send(client_fd, response.c_str(), response.length(), 0);
                recv(client_fd, buffer, sizeof(buffer) - 1, 0);
                std::string username(buffer, bytes_received);
                std::ofstream file(username + ".txt");
                file << "username: " << username << std::endl;
                file.close();
                response = "registrazione avvenuta con successo\n";
            }



            if (option == 3){
                response = "invia un messsaggio valido\n ";
            }




            send(client_fd, response.c_str(), response.length(), 0);
        }  while (option != 0);
        close(client_fd);
        std::cout << "Client disconnected" << std::endl;
    }
    
    close(server_fd);
    return 0;
}
