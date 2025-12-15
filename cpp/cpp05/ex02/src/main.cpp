#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm f("home",100,124);

        std::cout << "Tentative de signature..." << std::endl;
        bob.signForm(f); 

        std::cout << "Tentative d'exécution..." << std::endl;
        bob.executeForm(f); 

        std::cout << "Test terminé !" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

