#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;



Account::Account(int initial_deposit): _amount(initial_deposit),_nbDeposits(0),_nbWithdrawals(0)
{
    _displayTimestamp(); 
    _accountIndex = _nbAccounts++;
    _totalAmount = initial_deposit;

    std::cout
        << "index:" << _accountIndex << ";" 
        << "deposit:"   << initial_deposit << ";"
        << "created"    << std::endl;
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp(); 
    int p_amount = _amount;
   if(withdrawal > _amount)
   {
        std::cout << "p_amout:" << p_amount <<";withdrawal:refused" << std::endl;
        return (false); 
   }
   else
   {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << "p_amount:" << p_amount << ";" << "whitdrawal:" << _amount << std::endl;
   }
   return (true);
}
void Account::makeDeposit(int deposit)
{
    _displayTimestamp(); 
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;

       std::cout
        << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:" << deposit << ";"
        << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits
        << std::endl;
}
Account::~Account()
{
    _displayTimestamp(); 
     std::cout
        << "index:" << _accountIndex << ";" 
        << "amout" << _totalAmount << ";"
        << "close"    << std::endl;
}

int	Account::checkAmount( void ) const {
    return _amount;
}

void Account::_displayTimestamp( void ) {
    char buffer[20];
    std::time_t now = std::time(NULL);
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", std::localtime(&now));
    std::cout << buffer << " ";
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout 
        << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() 
        << std::endl;
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";" 
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals
        << std::endl;
}
