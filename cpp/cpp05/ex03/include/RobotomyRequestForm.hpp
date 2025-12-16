#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &cpy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();

    protected:
        void executeAction() const;
};

#endif