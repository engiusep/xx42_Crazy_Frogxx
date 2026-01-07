#pragma once

#include <vector> 

class Span
{
    private:
        std::vector<int> _array;
        unsigned int _sizeSpan;
    public:

        Span(unsigned int N);
        ~Span();    
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
    };
