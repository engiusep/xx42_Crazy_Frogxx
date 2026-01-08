#include "../include/Span.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "Try whith Array Full" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
         std::cout << "Execption = " << e.what() << std::endl;
    }


    try
    {
        std::cout << "Try whit Array good" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
         std::cout << "Execption = " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Try shortest Span" << std::endl;
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        std::cout <<"Shortest span :" <<sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Execption = " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Try longest Span" << std::endl;
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        std::cout <<"Longest span :" << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Execption = " << e.what() << std::endl;
    }
    try
    {
        std::cout << "Test addRange() with 10 000 numbers" << std::endl;

        std::vector<int> v(10000);
        srand(time(NULL));
        for (int i = 0; i < 10000; i++)
            v[i] = rand();

        Span sp(10000);
        sp.addRange(v.begin(), v.end());
        std::cout << "Shortest span addRange : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span  addRange : " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception = " << e.what() << std::endl;
    }


    try
    {
        std::cout << "Try span with only one number" << std::endl;
        Span sp(5);
        sp.addNumber(42);
        sp.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << "Execption = " << e.what() << std::endl;
    }   


    return 0;
}


