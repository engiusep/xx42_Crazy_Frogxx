
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    protected:
        void executeAction() const;

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
        ShrubberyCreationForm(std::string const &target,int gradeTosign,int gradeToExecute);
        ~ ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
};

#endif