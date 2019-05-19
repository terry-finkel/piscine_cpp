#include "Account.class.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account (int initial_deposit) :    _accountIndex(Account::_nbAccounts), _amount(initial_deposit),
                                            _nbDeposits(0), _nbWithdrawals(0) {

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
}

Account::Account () : _accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {

    Account::_nbAccounts += 1;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
}

Account::~Account () {

    Account::_nbAccounts -= 1;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

int
Account::checkAmount () const {

    return this->_amount;
}

void
Account::displayAccountsInfos () {

    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:"
        << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void
Account::displayStatus () const {

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:"
        << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void
Account::_displayTimestamp () {

    std::time_t now = std::time(0);
    tm          *nowPtr = localtime(&now);

    std::cout << "["
        << std::setfill('0') << std::setw(4) << nowPtr->tm_year + 1900
        << std::setfill('0') << std::setw(2) << nowPtr->tm_mon + 1
        << std::setfill('0') << std::setw(2) << nowPtr->tm_mday << "_"
        << std::setfill('0') << std::setw(2) << nowPtr->tm_hour
        << std::setfill('0') << std::setw(2) << nowPtr->tm_min
        << std::setfill('0') << std::setw(2) << nowPtr->tm_sec <<  "]";
}

int
Account::getNbAccounts () {

    return Account::_nbAccounts;
}

int
Account::getNbDeposits () {

    return Account::_totalNbDeposits;
}

int
Account::getNbWithdrawals () {

    return Account::_totalNbWithdrawals;
}

int
Account::getTotalAmount () {

    return Account::_totalAmount;
}

void
Account::makeDeposit (int deposit) {

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit;

    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    std::cout << ";amount:" << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool
Account::makeWithdrawal (int withdrawal) {

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:";

    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
    return true;
}
