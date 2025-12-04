#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1 : Création valide ===" << std::endl;
    try {
        Form f1("FormA", 50, 20);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2 : Grade trop haut ===" << std::endl;
    try {
        Form f2("FormB", 0, 10);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3 : Grade trop bas ===" << std::endl;
    try {
        Form f3("FormC", 150, 200);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4 : Signature réussie ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 20);
        Form f4("Contract", 30, 10);

        std::cout << bob << std::endl;
        std::cout << f4 << std::endl;

        bob.signForm(f4);
        std::cout << f4 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5 : Signature échouée ===" << std::endl;
    try {
        Bureaucrat jim("Jim", 120);
        Form f5("Classified", 50, 20);

        std::cout << jim << std::endl;
        std::cout << f5 << std::endl;

        jim.signForm(f5);
        std::cout << f5 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
