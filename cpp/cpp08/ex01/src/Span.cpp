#include "../include/Span.hpp"
#include <iostream>




const char *Span::ArrayIsFull::what() const throw()
{
    return ("Array is Full");
}
const char *Span::MinimunSizeArray::what() const throw()
{
    return ("Need 2 number for get a Span");
}
Span::Span(unsigned int N) : _sizeSpan(N) {}

int Span::shortestSpan() const
{
    if(_array.size() < 2)
        throw Span::MinimunSizeArray();

    std::vector<int> tmp  = _array;
    std::sort(tmp.begin(),tmp.end());

    int minSpan = tmp[1] - tmp[0];

    for(size_t i = 2; i < tmp.size();i++)
    {
        int span = tmp[i] - tmp[i - 1];
        if(span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if(_array.size() < 2)
        throw Span::MinimunSizeArray();

    int max = *std::max_element(_array.begin(),_array.end());
    int min = *std::min_element(_array.begin(),_array.end());
    return max - min;
}

void Span::addNumber(int n)
{
    if(_array.size() == _sizeSpan)
        throw Span::ArrayIsFull(); 
    _array.push_back(n);
}

Span::~Span() {};