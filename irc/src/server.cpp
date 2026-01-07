#include "../includes/Server.hpp"
#include "../includes/Client.hpp"
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <cstdlib>

Server::Server(int port,std::string  password) : _port(port) ,_password(password) {}

Server::~Server() {}

void Server::init()
{
    // 1️⃣ Crée le socket
    _server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_server_fd < 0)
    {
        //perror("socket");
        exit(1);
    }

    // 2️⃣ Prépare l'adresse
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;             // IPv4
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // toutes les interfaces
    addr.sin_port = htons(_port);           // port IRC classique

    // 3️⃣ bind
    if (bind(_server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        //perror("bind");
        close(_server_fd);
        exit(1);
    }

    // 4️⃣ listen
    if (listen(_server_fd, SOMAXCONN) < 0)
    {
        //perror("listen");
        close(_server_fd);
        exit(1);
    }

    std::cout << "Server initialized and listening on port 6667..." << std::endl;

    // 5️⃣ boucle principale
    listening();
}

void Server::add_poll_and_client(int client_fd)
{
    for (size_t i = 0; i < _fds.size(); i++)
    {
        if (_fds[i].fd == client_fd)
            return;
    }
    struct pollfd p;

    p.fd = client_fd;
    p.events = POLLIN | POLLOUT;
    p.revents = 0;

    _fds.push_back(p);

    _client.push_back(Client(client_fd));

}

void Server::disconnect_client(int i)
{
    close(_fds[i].fd);
    _fds.erase(_fds.begin() + i);
}
void Server::listening()
{
    while (true)
    {
        poll(_fds.data(), _fds.size(), -1);

        for (size_t i = 0; i < _fds.size(); i++)
        {
            if (_fds[i].revents & POLLIN)
            {
                if (_fds[i].fd == _server_fd)
                {
                    int client_fd = accept(_server_fd, NULL, NULL);
                    add_poll_and_client(client_fd);
                }
                // else
                // {
                //     int bytes = recv(_fds[i].fd, _buffer, 512, 0);
                //     if (bytes <= 0)
                //     {
                //         disconnect_client(i);
                //         i--;
                //         // continue; si on rajotue du code ou pas 
                //     }
                //     else
                //     {
                //         _buffer[bytes] = '\0';
                //         handle_irc_command(_fds[i].fd, _buffer);
                //     }
                // }
            }
        }
    }

}