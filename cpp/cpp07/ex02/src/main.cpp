#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "=== Test Constructeur par défaut ===" << std::endl;
        Array<int> a;
        std::cout << "Taille a: " << a.size() << std::endl; // 0

        std::cout << "\n=== Test Constructeur avec taille ===" << std::endl;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i * 10;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        std::cout << "\n=== Test Constructeur de copie ===" << std::endl;
        Array<int> c = b;
        c[0] = 1000;
        std::cout << "b[0] = " << b[0] << " (original)" << std::endl;
        std::cout << "c[0] = " << c[0] << " (copie)" << std::endl;

        std::cout << "\n=== Test Operateur d'affectation ===" << std::endl;
        Array<int> d;
        d = b;
        d[1] = 2000;
        std::cout << "b[1] = " << b[1] << " (original)" << std::endl;
        std::cout << "d[1] = " << d[1] << " (copie)" << std::endl;

        std::cout << "\n=== Test Operateur [] avec exception ===" << std::endl;
        try
        {
            std::cout << b[10] << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Exception attrapée: index hors limites" << std::endl;
        }

        std::cout << "\n=== Test Tableaux vides ===" << std::endl;
        Array<int> e;
        std::cout << "e.size() = " << e.size() << std::endl;

        std::cout << "\n=== Tous les tests terminés ===" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }

    return 0;
}
