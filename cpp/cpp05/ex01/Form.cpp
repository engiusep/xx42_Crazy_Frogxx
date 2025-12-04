#include "Form.hpp"
#include "Bureaucrat.hpp"



Form::Form(std::string name,int gradeTosign,int gradeToExecute)
    : _name(name), _gradeToSign(gradeTosign), _gradeToExecute(gradeToExecute), _isSIgned(false)
{
    if (gradeTosign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeTosign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign),_gradeToExecute(cpy._gradeToExecute) ,_isSIgned(cpy._isSIgned) {}

void    Form::beSigned(Bureaucrat const &b)
{
    if(b.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSIgned = true;
}

int  Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

int  Form::getGradeToSign() const
{
    return _gradeToSign;
}
std::string Form::getName() const
{
    return _name;
}
bool  Form::getIsSigned() const
{
   return _isSIgned;

}
Form &Form::operator=(const Form &other)
{
    if(this != &other)
        _isSIgned = other._isSIgned;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
    out << f.getName() 
        << ", form grade to sign " << f.getGradeToSign()
        << ", grade to execute " << f.getGradeToExecute()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return out;
}
Form::~Form(){}