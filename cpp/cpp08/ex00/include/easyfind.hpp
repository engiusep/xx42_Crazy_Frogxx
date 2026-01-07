
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename container>
typename container::const_iterator easyfind(const container &c, int value)
{
    typename container::const_iterator it = std::find(c.begin(),c.end(),value);
    if (it == c.end())
        throw std::exception();
    return it;
}

#endif