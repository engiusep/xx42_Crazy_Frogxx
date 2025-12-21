#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {(void)cpy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

static bool isPseudoinput(const std::string& s) 
{
    return (s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff");
}

static bool isChar(const std::string& s) 
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isInt(const std::string& s) 
{
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i >= s.length())
        return false;

    for (; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& s) 
{
    bool dot = false;
    size_t i = 0;

    if (s[s.length() - 1] != 'f')
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < s.length() - 1; i++) {
        if (s[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot;
}

static bool isDouble(const std::string& s) 
{
    bool dot = false;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < s.length(); i++) {
        if (s[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot;
}

static void printChar(double d) 
{
    if (std::isnan(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double d) 
{
    if (std::isnan(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) 
{
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double d) 
{
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    double value;

    if (isPseudoinput(input)) 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (input[input.length() - 1] == 'f') 
        {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        } else 
        {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        return;
    }
    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isInt(input))
        value = static_cast<double>(std::strtol(input.c_str(), NULL, 10));
    else if (isFloat(input)) 
        value = std::strtod(input.c_str(), NULL);
    else if (isDouble(input)) 
        value = std::strtod(input.c_str(), NULL);
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
