#include <iostream>
#include <cstring>

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

        void Deposit (int balance) {this->balance += balance;}
        void Withdraw (int balance) {this->balance -= balance;}
        int GetBalance (void) {return balance; }
        int GetAccountID (void) { return accID; }
        void ShowAccountInfo(void);

        private:
        int accID;
        int balance;
        char* cusName;
    };
    
    void ShowMenu (void);
    void ShowAllAccInfo (void);
    void MakeAccount (void);
    void UpdateBalance (int action);

    Account* GetAccount (int accID); 
}