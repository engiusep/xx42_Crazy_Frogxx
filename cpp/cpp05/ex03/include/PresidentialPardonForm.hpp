#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &cpy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();

    protected:
        void executeAction() const;
};

#endif