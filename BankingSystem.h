#include <iostream>
#include <cstring>

using namespace std;

namespace BankingSystem
{
    const int MAX_ACCOUNT = 100;
    const int NAME_LEN = 20;

    enum
    {
        MAKE = 1,
        DEPOSIT,
        WITHDRAW,
        INQUIRE,
        EXIT
    };

    enum
    {
        CREDIT_LEVEL_A = 7,
        CREDIT_LEVEL_B = 4,
        CREDIT_LEVEL_C = 2,
    };

    class Account
    {
    public:
        Account (int accID, char* name, int balance):accID(accID), balance(balance)
        {
            cusName = new char[strlen(name) + 1];
            strcpy(cusName, name);
        }

        Account (const Account &ref):accID(ref.accID), balance(ref.balance)
        {
            cusName = new char[strlen(ref.cusName) + 1];
            strcpy(cusName, ref.cusName);
        }

        ~Account()
        {
            delete []cusName;
        }

        virtual void Deposit (int _balance) {this->balance += balance;}
        void Withdraw (int balance) {this->balance -= balance;}
        int GetBalance (void) const {return balance; }
        int GetAccountID (void) const { return accID; }
        virtual void ShowAccountInfo(void) const;

    private:
        int accID;
        int balance;
        char* cusName;
    };
    

    class NormalAccount : public Account // 보통 예금 계좌
    {
    public:
        NormalAccount (int accID, char* name, int balance, int interest) : Account(accID, name, balance), interestRate(interest) {}

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

    class HighCreditAccount : public NormalAccount // 신용 신뢰 계좌
    {
    public:
        HighCreditAccount (int accID, char* name, int balance, int interest, int credit) : NormalAccount(accID, name, balance, interest), creditLevel(credit) {}

        void Deposit (int balance)
        {
            int additionalRate = 0;

            if (creditLevel == BankingSystem::CREDIT_LEVEL_A)
            {
                additionalRate = 7;
            }
            else if (creditLevel == BankingSystem::CREDIT_LEVEL_B)
            {
                additionalRate = 4;
            }
            else if (creditLevel == BankingSystem::CREDIT_LEVEL_C)
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

    class AccountHandler
    {
        public:
        AccountHandler()
        {
            accNum = 0;
        }
        ~AccountHandler()
        {
            for (int i; i<accNum; i++)
            {
                delete accArr[i];
            }
        }

        void ShowMenu (void);
        void ShowAllAccInfo (void);
        void MakeAccount (void);
        void UpdateBalance (int action);

        Account* GetAccount (int accID);    

        private:
        Account* accArr[MAX_ACCOUNT];
        int accNum;
    };
}