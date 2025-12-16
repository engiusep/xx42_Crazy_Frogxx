#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void testForm(AForm &form, Bureaucrat &bureaucrat)
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Form: " << form.getName() << std::endl;
    std::cout << "Bureaucrat: " << bureaucrat.getName()
              << " (grade " << bureaucrat.getGrade() << ")" << std::endl;

    try
    {
        std::cout << "Signing..." << std::endl;
        bureaucrat.signForm(form);

        std::cout << "Executing..." << std::endl;
        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat low("Bob", 150);

    Bureaucrat high("Alice", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Paul");

    std::cout << "\n=== TEST AVEC GRADE TROP BAS ===" << std::endl;
    testForm(shrub, low);
    testForm(robot, low);
    testForm(pardon, low);

    std::cout << "\n=== TEST AVEC GRADE SUFFISANT ===" << std::endl;
    testForm(shrub, high);
    testForm(robot, high);
    testForm(pardon, high);

    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    return 0;
}


