#include "../includes/Client.hpp"



Client::Client(int fd) : _fd(fd), _buffer("") , _name("") 
{
    std::cout << _fd << std::endl;
}

Client::~Client()
{
}