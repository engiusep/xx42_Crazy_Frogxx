#include "Brain.hpp"



Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = "empty idea";
    }
}

Brain::~Brain()
{

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

void    Brain::setIdea(int index,std::string idea)
{
    _ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
   return _ideas[index];
}




