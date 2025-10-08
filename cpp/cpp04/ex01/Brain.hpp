#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>


class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &cpy);
        Brain &operator=(const Brain &rhs);
        std::string getIdea(int index);
        void  setIdea(int index,std::string idea);
        ~Brain();
       
};


#endif