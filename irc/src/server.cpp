#include "../include/Server.hpp"
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server()
{
}

Server::~Server()
{
}
void Server::add_to_poll(int client_fd)
{
    for (size_t i = 0; i < _fds.size(); i++)
    {
        if (_fds[i].fd == client_fd)
            return;
    }
    struct pollfd p;

    p.fd = client_fd;
    p.events = POLLIN;
    p.revents = 0;

    _fds.push_back(p);
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
                    add_to_poll(client_fd);
                }
                else
                {
                    int bytes = recv(_fds[i].fd, _buffer, 512, 0);
                    if (bytes <= 0)
                    {
                        disconnect_client(i);
                        i--;
                        // continue; si on rajotue du code ou pas 
                    }
                    else
                    {
                        _buffer[bytes] = '\0';
                        handle_irc_command(_fds[i].fd, _buffer);
                    }
                }
            }
        }
    }

}