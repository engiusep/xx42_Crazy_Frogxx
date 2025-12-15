#include "Bureaucrat.hpp"
#include "Form.hpp"



Bureaucrat::Bureaucrat(const std::string name,int grade) : _name(name)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        _grade = grade;
    }

    

}
void Bureaucrat::signForm(Form &f)
{
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " 
                  << f.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name) , _grade(cpy._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        _grade = other._grade;
    return *this;
}


void Bureaucrat::IncrementGrade()
{
    if(_grade -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::DecrementGrade()
{
    if(_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}
std::string const Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    
    return _grade;
}

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."; 
    return (o);
}
