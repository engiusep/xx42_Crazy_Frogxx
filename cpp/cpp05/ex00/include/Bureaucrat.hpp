#include <iostream>


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(const std::string name, int _grade);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &other);
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

        void IncrementGrade();
        void DecrementGrade();
        std::string const getName() const;
        int getGrade() const ;
        ~Bureaucrat();   
};

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs);
#endif