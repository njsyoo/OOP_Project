#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "Account.h"
#include "String.h"

class NormalAccount : public Account // 보통 예금 계좌
    {
    public:
        NormalAccount (int accID, String name, int balance, int interest) : Account(accID, name, balance), interestRate(interest) {}

        int GetInterestRate (void) { return interestRate; }
        
        void Deposit (int balance)
        {
            int interest = (GetBalance() + balance) * interestRate / 100;

            Account::Deposit(balance + interest);
        }

        void ShowAccountInfo(void) const
        {
            Account::ShowAccountInfo();
            cout << "Interest Rate: " << interestRate << endl;
        }

    private:
        int interestRate;
    };

#endif