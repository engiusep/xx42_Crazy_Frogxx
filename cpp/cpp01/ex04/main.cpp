#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char**argv)
{
    if(argc != 4)
        std::cerr << "Error ./a.out <filename> <s1> <s2>" << std::endl;
      if(std::string(argv[2]).empty())
    {
        std::cerr << "Error: s1 is empty" << std::endl;
        return 1;
    }

    std::ifstream fichier("test.txt");
    std::ofstream newfichier("test.replace");
    if(fichier.is_open())
    {
        std::string line;
        while(std::getline(fichier,line))
        {
            size_t pos = 0;
            while((pos = line.find(argv[2],pos)) != std::string::npos)
            {
                line = line.substr(0, pos) + argv[3] + line.substr(pos + strlen(argv[2]));
                pos += strlen(argv[3]);
            }
            if(newfichier.is_open())
                newfichier << line << std::endl;
        }

    }
    fichier.close();
    return 0;
}