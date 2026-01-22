#include "../include/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) 
{ 
    *this = other; 
}

RPN &RPN::operator=(const RPN &other) 
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

bool RPN::isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOp(int a, int b, char op) 
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') 
    {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    return 0;
}

void RPN::processExpression(const std::string &expr) 
{
    try {
        for (size_t i = 0; i < expr.length(); i++) {
            if (isspace(expr[i])) continue;

            if (isdigit(expr[i])) {
                _stack.push(expr[i] - '0');
            } 
            else if (isOperator(expr[i])) 
            {
                if (_stack.size() < 2)
                    throw std::runtime_error("Error");
                
                int b = _stack.top(); _stack.pop();
                int a = _stack.top(); _stack.pop();
                
                _stack.push(applyOp(a, b, expr[i]));
            } 
            else {
                throw std::runtime_error("Error");
            }
        }

        if (_stack.size() != 1) 
            throw std::runtime_error("Error");
        std::cout << _stack.top() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}