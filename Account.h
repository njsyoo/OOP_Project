#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

const int MAX_ACCOUNT = 100;

class Account
{
public:
    Account (int accID, String name, int balance);

    virtual void Deposit (int _balance);
    void Withdraw (int balance);
    int GetBalance (void) const;
    int GetAccountID (void) const;
    virtual void ShowAccountInfo(void) const;

private:
    int accID;
    int balance;
    String cusName;
};

#endif