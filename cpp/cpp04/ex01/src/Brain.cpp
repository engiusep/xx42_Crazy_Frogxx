#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
    *this = cpy;
    
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





