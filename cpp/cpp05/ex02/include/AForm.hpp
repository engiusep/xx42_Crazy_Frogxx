#include <cstdlib>
#include <iostream>
#ifndef AFROM_HPP
#define AFROM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        int const _gradeToSign;
        int const _gradeToExecute;
        bool _isSigned;
    public:
        AForm(std::string name,int gradeTosign,int gradeToExecute);
        AForm &operator=(AForm const &other);
        AForm(const AForm &cpy);
        virtual ~AForm();
    
        void execute(Bureaucrat const & executor) const;

        class FormNotSignedException : public std::exception
        {
            public:
                 virtual const char* what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        std::string getName() const;
        int  getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat const &b);
    protected:
        virtual void executeAction() const = 0;

};
std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif