#include "../include/RobotomyRequestForm.hpp"

const char*  RobotomyRequestForm::CannotExec::what() const throw()
{
    return ("Cannot exec !");
}
const char*  RobotomyRequestForm::CannotSign::what() const throw()
{
    return ("Cannot Sign !");
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target,int gradeTosign,int gradeToExecute) : AForm(target,gradeTosign,gradeToExecute) {};

RobotomyRequestForm::~RobotomyRequestForm() {};


void RobotomyRequestForm::executeAction() const
{
     srand(time(0));
    if(getGradeToExecute() != 45)
        throw RobotomyRequestForm::CannotExec();
    if(getGradeToSign() != 72)
        throw RobotomyRequestForm::CannotSign();
    if(rand() % 2 != 0)
        std::cout << "brrr brrr " << _target << "has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed to robotomized" << _target << std::endl;
    
}