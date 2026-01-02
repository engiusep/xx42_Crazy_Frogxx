#include "../include/Generate.hpp"
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/C.hpp"
#include "../include/B.hpp"
#include <ctime>
#include <cstdlib>


Base * generate(void) 
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    return new C;
}