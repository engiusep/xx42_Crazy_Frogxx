#include <iostream>
#include <cstdlib>
#include "../include/Base.hpp"
#include "../include/C.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"


void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Pointer is not A/B/C" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Reference is not A/B/C" << std::endl;
}