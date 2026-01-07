#include "../includes/Client.hpp"



Client::Client(int fd) : _fd(fd)
{
    std::cout << _fd << std::endl;
}

Client::~Client()
{
}