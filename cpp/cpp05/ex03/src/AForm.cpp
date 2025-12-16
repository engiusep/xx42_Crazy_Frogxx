#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"


const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too High");
} 
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too Low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed !");
}

void AForm::execute(Bureaucrat const & executor) const 
{
    if (!_isSigned)
    {
        throw AForm::FormNotSignedException();
        return;
    }

    if (executor.getGrade() > _gradeToExecute)
    {
        throw GradeTooLowException();
        return;
    }
    executeAction();
}

AForm::AForm(std::string name,int gradeTosign,int gradeToExecute)
    : _name(name), _gradeToSign(gradeTosign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeTosign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeTosign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign),_gradeToExecute(cpy._gradeToExecute) ,_isSigned(cpy._isSigned) {}

void    AForm::beSigned(Bureaucrat const &b)
{
    if(b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

int  AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

int  AForm::getGradeToSign() const
{
    return _gradeToSign;
}
std::string AForm::getName() const
{
    return _name;
}
bool  AForm::getIsSigned() const
{
   return _isSigned;

}
AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        _isSigned = other._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
    out << f.getName() 
        << ", form grade to sign " << f.getGradeToSign()
        << ", grade to execute " << f.getGradeToExecute()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return out;
}
AForm::~AForm(){}