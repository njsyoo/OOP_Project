 #include "BankingCommonDecl.h"
 #include "Account.h"

Account::Account (int accID, char* name, int balance):accID(accID), balance(balance)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account (const Account &ref):accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

Account::~Account()
{
    delete []cusName;
}

Account& Account::operator= (const Account& ref_acc)
{
    accID = ref_acc.accID;
    balance = ref_acc.balance;

    delete []cusName;
    cusName = new char[strlen(ref_acc.cusName) + 1];
    strcpy(cusName, ref_acc.cusName);

    return *this;
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