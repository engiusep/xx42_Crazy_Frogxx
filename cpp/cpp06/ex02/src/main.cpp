#include "../include/Base.hpp"
#include "../include/Generate.hpp"
#include "../include/Identify.hpp"
#include <iostream>

int main()
{
    Base* p = generate();

    std::cout << "Identify using pointer: ";

    identify(p);
    std::cout << "Identify using reference: ";

    identify(*p);

    delete p;
    return 0;
}