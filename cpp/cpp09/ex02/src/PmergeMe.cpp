#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) 
{
    *this = src;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs) 
    {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool isValidPositiveInt(const std::string& str) 
{
    if (str.empty())
        return false;
    
    if (str[0] == '-')
        return false;
    
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (!isdigit(str[i]))
            return false;
    }
    
    std::istringstream iss(str);
    long num;
    iss >> num;
    
    if (num < 0 || num > 2147483647)
        return false;
    
    return true;
}

bool parseArgumentsVector(int argc, char **argv, std::vector<int>& container) 
{
    for (int i = 1; i < argc; i++) 
    {
        std::string arg = argv[i];
        if (!isValidPositiveInt(arg)) 
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        int num = atoi(arg.c_str());
        container.push_back(num);
    }
    return true;
}

bool parseArgumentsDeque(int argc, char **argv, std::deque<int>& container) 
{
    for (int i = 1; i < argc; i++) 
    {
        std::string arg = argv[i];
        
        if (!isValidPositiveInt(arg)) 
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        int num = atoi(arg.c_str());
        container.push_back(num);
    }
    return true;
}

void PmergeMe::printVector(const std::string& prefix, const std::vector<int>& container) 
{
    std::cout << prefix;
    size_t count = 0;
    for (std::vector<int>::const_iterator it = container.begin(); 
         it != container.end(); ++it) 
        {
        if (count >= 5 && container.size() > 8) 
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it;
        if (it + 1 != container.end())
            std::cout << " ";
        count++;
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::string& prefix, const std::deque<int>& container) 
{
    std::cout << prefix;
    
    size_t count = 0;
    for (std::deque<int>::const_iterator it = container.begin(); 
         it != container.end(); ++it) 
        {
        if (count >= 5 && container.size() > 8) 
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it;
        if (it + 1 != container.end())
            std::cout << " ";
        count++;
    }
    std::cout << std::endl;
}

void PmergeMe::generateJacobsthalSequence(size_t n, std::vector<size_t>& jacobsthal) 
{
    if (n == 0)
        return;
    jacobsthal.push_back(0);
    if (n == 1)
        return;
    jacobsthal.push_back(1);
    size_t idx = 1;
    while (true) 
    {
        size_t next = jacobsthal[idx] + 2 * jacobsthal[idx - 1];
        if (next >= n)
            break;
        jacobsthal.push_back(next);
        idx++;
    }
}


void PmergeMe::binaryInsertVector(std::vector<int>& sorted, int value, size_t left, size_t right) 
{
    if (left >= right) 
    {
        sorted.insert(sorted.begin() + left, value);
        return;
    }
    size_t mid = left + (right - left) / 2;
    if (sorted[mid] < value)
        binaryInsertVector(sorted, value, mid + 1, right);
    else 
        binaryInsertVector(sorted, value, left, mid);
}
void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec) 
{
    size_t n = vec.size();
    if (n <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < n; i += 2)
     {
        int first = vec[i];
        int second = vec[i + 1];
        if (first > second) 
            pairs.push_back(std::make_pair(first, second));
        else 
            pairs.push_back(std::make_pair(second, first));
    }

    if (n % 2 != 0) 
    {
        straggler = vec[n - 1];
        hasStraggler = true;
    }
    
    if (pairs.size() > 1) 
    {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) 
            largerElements.push_back(pairs[i].first);
        fordJohnsonSortVector(largerElements);
        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) 
        {
            for (size_t j = 0; j < pairs.size(); j++)
             {
                if (pairs[j].first == largerElements[i])
                {
                    sortedPairs.push_back(pairs[j]);
                    pairs[j].first = -1;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        mainChain.push_back(pairs[i].first);
        pendingElements.push_back(pairs[i].second);
    }
    if (!pendingElements.empty()) 
    {
        mainChain.insert(mainChain.begin(), pendingElements[0]);
        pendingElements.erase(pendingElements.begin());
    }
    std::vector<size_t> jacobsthal;
    generateJacobsthalSequence(pendingElements.size() + 1, jacobsthal);
    std::vector<bool> inserted(pendingElements.size(), false);
    for (size_t i = 1; i < jacobsthal.size(); i++) 
    {
        size_t pos = jacobsthal[i];
        size_t prevPos = 0;
        
        if (i > 1) 
            prevPos = jacobsthal[i - 1];
        for (size_t j = pos; j > prevPos; j--) 
        {
            size_t idx = j - 1;
            if (idx < pendingElements.size() && !inserted[idx]) 
            {
                size_t searchLimit = idx + i + 1;
                if (searchLimit > mainChain.size()) 
                    searchLimit = mainChain.size();
                binaryInsertVector(mainChain, pendingElements[idx], 0, searchLimit);
                inserted[idx] = true;
            }
        }
    }
    for (size_t i = 0; i < pendingElements.size(); i++) 
    {
        if (!inserted[i]) 
            binaryInsertVector(mainChain, pendingElements[i], 0, mainChain.size());
    }
    if (hasStraggler) 
        binaryInsertVector(mainChain, straggler, 0, mainChain.size());
    vec = mainChain;
}
void PmergeMe::binaryInsertDeque(std::deque<int>& sorted, int value, size_t left, size_t right) 
{
    if (left >= right)
    {
        sorted.insert(sorted.begin() + left, value);
        return;
    }
    size_t mid = left + (right - left) / 2;
    if (sorted[mid] < value) 
        binaryInsertDeque(sorted, value, mid + 1, right);
    else 
        binaryInsertDeque(sorted, value, left, mid);
}
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq) 
{
    size_t n = deq.size();
    if (n <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    for (size_t i = 0; i + 1 < n; i += 2) 
    {
        int first = deq[i];
        int second = deq[i + 1];
        if (first > second) 
            pairs.push_back(std::make_pair(first, second));
        else 
            pairs.push_back(std::make_pair(second, first));
    }
    if (n % 2 != 0) 
    {
        straggler = deq[n - 1];
        hasStraggler = true;
    }
    if (pairs.size() > 1)
     {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) 
            largerElements.push_back(pairs[i].first);
        fordJohnsonSortDeque(largerElements);
        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) 
        {
            for (size_t j = 0; j < pairs.size(); j++)
             {
                if (pairs[j].first == largerElements[i]) 
                {
                    sortedPairs.push_back(pairs[j]);
                    pairs[j].first = -1;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    std::deque<int> mainChain;
    std::deque<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        mainChain.push_back(pairs[i].first);
        pendingElements.push_back(pairs[i].second);
    }
    if (!pendingElements.empty()) 
    {
        mainChain.push_front(pendingElements[0]);
        pendingElements.erase(pendingElements.begin());
    }
    std::vector<size_t> jacobsthal;
    generateJacobsthalSequence(pendingElements.size() + 1, jacobsthal);
    
    std::vector<bool> inserted(pendingElements.size(), false);
    for (size_t i = 1; i < jacobsthal.size(); i++) 
    {
        size_t pos = jacobsthal[i];
        size_t prevPos = 0;
        
        if (i > 1)
            prevPos = jacobsthal[i - 1];
        for (size_t j = pos; j > prevPos; j--) 
        {
            size_t idx = j - 1;
            
            if (idx < pendingElements.size() && !inserted[idx]) 
            {
                size_t searchLimit = idx + i + 1;
                if (searchLimit > mainChain.size()) 
                    searchLimit = mainChain.size();
                binaryInsertDeque(mainChain, pendingElements[idx], 0, searchLimit);
                inserted[idx] = true;
            }
        }
    }
    for (size_t i = 0; i < pendingElements.size(); i++) 
    {
        if (!inserted[i]) 
            binaryInsertDeque(mainChain, pendingElements[i], 0, mainChain.size());
    }
    if (hasStraggler) 
        binaryInsertDeque(mainChain, straggler, 0, mainChain.size());
    deq = mainChain;
}

bool PmergeMe::run(int argc, char **argv) 
{
    if (argc < 2) 
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    if (!parseArgumentsVector(argc, argv, vec)) 
        return 1;
    std::deque<int> deq;
    if (!parseArgumentsDeque(argc, argv, deq)) 
        return 1;
    printVector("Before: ", vec);
    clock_t startVec = clock();
    fordJohnsonSortVector(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    clock_t startDeq = clock();
    fordJohnsonSortDeque(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    printVector("After:  ", vec);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
    
    return 0;
}
