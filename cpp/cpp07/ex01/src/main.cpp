#include "../include/iter.hpp"
#include <iostream>
#include <string>


void increment(int &x) 
{
    x++;
}

void printInt(const int &x) 
{
    std::cout << x << " ";
}

void uppercase(std::string &s) 
{
    for (size_t i = 0; i < s.size(); ++i) 
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }
}

void printString(const std::string &s) 
{
    std::cout << s << " ";
}
int main() 
{

    int arr[] = {100, 101, 102};
    std::cout << "Non-const array before increment: ";
    iter(arr, 3, printInt);
    std::cout << std::endl;

    iter(arr, 3, increment);

    std::cout << "Non-const array after increment: ";
    iter(arr, 3, printInt);
    std::cout << std::endl << std::endl;

    const int constArr[] = {10, 20, 30};
    std::cout << "Const array: ";
    iter(constArr, 3, printInt);
    std::cout << std::endl << std::endl;

    std::string words[] = {"hello", "world", "template"};
    std::cout << "Strings before uppercase: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    iter(words, 3, uppercase);

    std::cout << "Strings after uppercase: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    return 0;
}
