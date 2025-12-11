#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &rhs);
        WrongAnimal(const WrongAnimal &cpy);
        ~WrongAnimal();
        void makeSound(void) const;

};






#endif