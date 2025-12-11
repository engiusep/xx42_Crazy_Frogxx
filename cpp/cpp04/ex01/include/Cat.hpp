#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &rhs);
        void    makeSound(void) const;

        ~Cat();

        
};

#endif