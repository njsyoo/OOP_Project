 #include "BankingCommonDecl.h"
 #include "Account.h"

Account::Account (int accID, String name, int balance):accID(accID), balance(balance)
{
    cusName = name;
}

void Account::Deposit (int _balance) 
{
    this->balance += balance;
}

void Account::Withdraw (int balance)
{
    this->balance -= balance;
}

int Account::GetBalance (void) const
{
    return balance;
}

int Account::GetAccountID (void) const
{
    return accID;
}

void Account::ShowAccountInfo(void) const
{
    cout << "Account ID: " << accID << endl;
    cout << "Name: " << cusName << endl;
    cout << "Balance: " << balance << endl;
}