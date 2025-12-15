#include "Bureaucrat.hpp"



int main()
{
    try
    {
        Bureaucrat Hugo("Hugo",1);
        std::cout << Hugo << std::endl;
        Hugo.IncrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << "Error incrementaion" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat Liam("Liam",150);
        std::cout << Liam << std::endl;
        Liam.DecrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error Decremantation" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat Mat("Mat",0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error creation" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat Mat2("Mat",151);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error creation" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    
    
}