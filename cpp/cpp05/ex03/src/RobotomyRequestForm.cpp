#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm(cpy), _target(cpy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
void RobotomyRequestForm::executeAction() const
{
    if (std::rand() % 2)
        std::cout << "* drilling noises * " << _target
                  << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << std::endl;
}
