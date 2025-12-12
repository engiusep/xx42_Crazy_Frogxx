#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain deconstructor" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
    for (int i = 0; i < 100; i++)
    {
        if(this != &cpy)
            _ideas[i] = cpy._ideas[i];
    }
    
}
Brain &Brain::operator=(const Brain &rhs)
{
    if(this != &rhs)
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = rhs._ideas[i];
    }
    return *this;
}





