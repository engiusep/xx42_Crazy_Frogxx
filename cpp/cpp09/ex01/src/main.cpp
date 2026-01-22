#include "../include/RPN.hpp"






int main(int argc,char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error : usage ./RPN 1 2 +" << std::endl;
        return 1;
    }

    RPN calculator;

    calculator.processExpression(argv[1]);
}