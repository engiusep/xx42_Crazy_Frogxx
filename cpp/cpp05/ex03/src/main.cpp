#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat high("Alice", 1);  
    Bureaucrat low("Bob", 150);   
    AForm* form;
    
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) 
    {
        low.signForm(*form);  
        high.signForm(*form); 
        low.executeForm(*form);  
        high.executeForm(*form); 
        delete form;
    }

    std::cout << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) 
    {
        high.signForm(*form);
        high.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form) 
    {
        high.signForm(*form);
        high.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form)
        delete form;
    return 0;
}
