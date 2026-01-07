#pragma once

#include <vector>
#include <iostream>
#include <poll.h>

class Client;

class Server
{
    private:
        int _server_fd;
        char _buffer[512];
        std::vector<pollfd> _fds;
        std::vector<Client> _client;
    public:
        Server();
        ~Server();
        void add_to_poll(int client_fd);
        void listening();
        void disconnect_client(int client_fd);
};


