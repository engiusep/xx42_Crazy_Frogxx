#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        class CannotExec : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class CannotSign : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        RobotomyRequestForm(std::string const &target,int gradeTosign,int gradeToExecute);
        ~RobotomyRequestForm();
    protected:
        void executeAction() const;
};




#endif