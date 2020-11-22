#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <iostream>
using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason(void) = 0;
};

class WithdrawException : public AccountException
{
private:
    int balance;
public:
    WithdrawException(int money) : balance(money) {}

    void ShowExceptionReason(void)
    {
        cout << "Try to withdraw more than balance: " << balance << endl;
    }
};

class InputMoneyException : public AccountException
{
private:
    int input;
public:
    InputMoneyException(int money) : input(money) {}

    void ShowExceptionReason(void)
    {
        cout << "Wrong input money: " << input << endl;
    }
};

#endif