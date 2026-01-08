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
        template <typename Iterator>
            void addRange(Iterator first, Iterator last)
            {
                if (_array.size() + std::distance(first, last) > _sizeSpan)
                    throw ArrayIsFull();

                _array.insert(_array.end(), first, last);
            }
        class ArrayIsFull : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class MinimunSizeArray : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
    };
