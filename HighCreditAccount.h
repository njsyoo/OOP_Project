#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // 신용 신뢰 계좌
    {
    public:
        HighCreditAccount (int accID, String name, int balance, int interest, int credit) : NormalAccount(accID, name, balance, interest), creditLevel(credit) {}

        void Deposit (int balance)
        {
            int additionalRate = 0;

            if (creditLevel == CREDIT_LEVEL_A)
            {
                additionalRate = 7;
            }
            else if (creditLevel == CREDIT_LEVEL_B)
            {
                additionalRate = 4;
            }
            else if (creditLevel == CREDIT_LEVEL_C)
            {
                additionalRate = 2;
            }

            int interest = (GetBalance() + balance) * (GetInterestRate() + additionalRate) / 100;

            Account::Deposit(balance + interest);
        }

        void ShowAccountInfo(void) const
        {
            NormalAccount::ShowAccountInfo();
            cout << "Credit Level: " << creditLevel << endl;
        }

    private:
        int creditLevel;
    };

#endif