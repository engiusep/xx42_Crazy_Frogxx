
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
        ShrubberyCreationForm(std::string const &target);
        ~ ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
};

#endif