#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <string>

class PmergeMe 
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        double _timeVec;
        double _timeDeq;

        bool isValidPositiveInt(const std::string& str);
        void generateJacobsthalSequence(size_t n, std::vector<size_t>& jacobsthal);
        
        void printVector(const std::string& prefix, const std::vector<int>& container);
        void printDeque(const std::string& prefix, const std::deque<int>& container);

        void binaryInsertVector(std::vector<int>& sorted, int value, size_t left, size_t right);
        void fordJohnsonSortVector(std::vector<int>& vec);

        void binaryInsertDeque(std::deque<int>& sorted, int value, size_t left, size_t right);
        void fordJohnsonSortDeque(std::deque<int>& deq);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);

        bool run(int argc, char **argv);
};

#endif