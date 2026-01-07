#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "Constructeur défault" << std::endl;
        Array<int> a;
        std::cout << "Size a: " << a.size() << std::endl;

        std::cout << "\nTry whit size" << std::endl;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i * 10;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        std::cout << "\n Try Constructeur de copie" << std::endl;
        Array<int> c = b;
        c[0] = 1000;
        std::cout << "b[0] = " << b[0] << " original" << std::endl;
        std::cout << "c[0] = " << c[0] << " deep copie" << std::endl;

        std::cout << "\n Test Operateur =" << std::endl;
        Array<int> d;
        d = b;
        d[1] = 2000;
        std::cout << "b[1] = " << b[1] << " original" << std::endl;
        std::cout << "d[1] = " << d[1] << " deep copie" << std::endl;

        std::cout << "\n Test Operateur []" << std::endl;
        try
        {
            std::cout << b[10] << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Exception catch out of limit array" << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cout << "Other Exception" << e.what() << std::endl;
    }

    return 0;
}
