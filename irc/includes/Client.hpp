#pragma once
#include <iostream>
#include <vector>

class Client
{
    private:
        int _fd;
        std::vector<std::string> _msg;
        std::string _nickname;
        std::string _username;
        
    public:
        Client(int fd);
        ~Client();
};


