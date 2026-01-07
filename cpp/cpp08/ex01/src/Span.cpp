#include "../include/Span.hpp"


template <typename T>
Span::Span(unsigned int N) : _sizeSpan(N) 
{
    std::vector<int> _array(N);
}

int Span::longestSpan() const
{

}

int Span::shortestSpan() const
{

}

void Span::addNumber(int n)
{
    _array.push_back(n);
}

Span::~Span() {};