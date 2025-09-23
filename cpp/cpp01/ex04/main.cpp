#include <iostream>


int main(int argc, char**argv)
{
    if(argc != 4)
        std::cout << "Error ./a.out <filename> <s1> <s2>" << std::endl;
      if(std::string(argv[2]).empty())
    {
        std::cout << "Error: s1 is empty" << std::endl;
        return 1;
    }

}