#include <cstdlib>
#include <iostream>
#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        int const _gradeToSign;
        int const _gradeToExecute;
        bool _isSIgned;
    public:
        Form(std::string name,int gradeTosign,int gradeToExecute);
        Form &operator=(Form const &other);
        Form(const Form &cpy);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() 
                {
                    return "Grade too High !";
                }
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw() 
                {
                    return "Grade too low !";
                }
        };
        std::string getName() const;
        int  getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat const &b);

};
std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif