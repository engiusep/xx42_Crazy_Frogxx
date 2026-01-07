#pragma once

#include <vector>
#include <iostream>
#include <poll.h>

class Client;
class Topic;

class Server
{
    private:
        int _server_fd;
        std::vector<pollfd> _fds;
        std::vector<Client> _clients;
        std::vector<Topic> _topics;
        std::string _password;
        int _port;
    public:
        Server(int port,std::string password);
        ~Server();
        void init();
        int check_entry();
        void add_poll_and_client(int client_fd);
        void listening();
        void disconnect_client(int client_fd);
};


