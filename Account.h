#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

const int MAX_ACCOUNT = 100;

class Account
{
public:
    Account (int accID, char* name, int balance);
    Account (const Account &ref);

    ~Account();

    virtual void Deposit (int _balance);
    void Withdraw (int balance);
    int GetBalance (void) const;
    int GetAccountID (void) const;
    virtual void ShowAccountInfo(void) const;

private:
    int accID;
    int balance;
    char* cusName;
};

#endif