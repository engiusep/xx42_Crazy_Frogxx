#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {} 

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy), _target(cpy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
void ShrubberyCreationForm::executeAction() const
{
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


