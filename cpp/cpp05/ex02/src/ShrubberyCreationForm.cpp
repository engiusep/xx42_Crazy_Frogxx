#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>


const char*  ShrubberyCreationForm::CannotExec::what() const throw()
{
    return ("Cannot exec !");
}
const char*  ShrubberyCreationForm::CannotSign::what() const throw()
{
    return ("Cannot Sign !");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target,int gradeTosign,int gradeToExecute) : AForm("ShrubberyCreationForm", gradeTosign, gradeToExecute), _target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
// {

// }
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    AForm::operator=(rhs);
    return *this;
}


void ShrubberyCreationForm::executeAction() const
{

    if(getGradeToExecute() != 137)
    {
       throw ShrubberyCreationForm::CannotExec();
       return;
    }
    if(getGradeToSign() != 145)
    {
        throw ShrubberyCreationForm::CannotSign();
        return;
    }

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) return;

    file <<
    "        ccee88oo\n"
    "     C8O8O8Q8PoOb o8oo\n"
    "   dOB69QO8PdUOpugoO9bD\n"
    "  CgggbU8OU qOp qOdoUOdcb\n"
    "     6OuU  /p u gcoUodpP\n"
    "       \\\\//  /douUP\n"
    "         \\\\////\n"
    "          |||\n"
    "          |||\n"
    "          |||\n"
    "          |||\n"
    "    .....//||||\\....\n"
    "        ccee88oo\n"
    "     C8O8O8Q8PoOb o8oo\n"
    "   dOB69QO8PdUOpugoO9bD\n"
    "  CgggbU8OU qOp qOdoUOdcb\n"
    "     6OuU  /p u gcoUodpP\n"
    "       \\\\//  /douUP\n"
    "         \\\\////\n"
    "          |||\n"
    "          |||\n"
    "          |||\n"
    "          |||\n"
    "    .....//||||\\....\n";

    file.close();
}


