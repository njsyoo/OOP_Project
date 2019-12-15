#include "BankingSystem.h"

using namespace std;
using namespace BankingSystem;

void AccountHandler::ShowMenu (void)
{
    cout << "-----Menu-----" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Print all Account" << endl;
    cout << "5. Exit Program" << endl;
}

void AccountHandler::MakeAccount (void)
{
    int accID;
    int balance;
    char name[NAME_LEN];

    cout << "[Create Account]" << endl;
    cout << "Account ID:";
    cin >> accID;

    if(GetAccount(accID) == NULL)
    {
        cout << "Name:";
        cin >> name;

        cout << "Deposit:";
        cin >> balance;

        accArr[accNum++] = new Account(accID, name, balance);
    }
    else
    {
        cout << "[Error] The Accoun ID already exist" << endl;
        return;
    }
}

void AccountHandler::UpdateBalance (int action)
{
    int accID = -1;
    int balance;
    Account* pAcc;

    if(action == DEPOSIT)
    {
        cout << "[Deposit Money]" << endl;
    }
    else if (action == WITHDRAW)
    {
        cout << "[Withdraw Money]" << endl;
    }

    cout << "Account ID:";
    cin >> accID;

    pAcc = GetAccount(accID);

    if(pAcc == NULL)
    {
        cout << "[Error] Wrong Account ID." << endl;
        return;
    }

    cout << "Amount of Money:";
    cin >> balance;

    if(action == DEPOSIT)
    {
        pAcc->Deposit(balance);
    }
    else
    {
        if (pAcc->GetBalance() >= balance)
        {
            pAcc->Withdraw(balance);
        }
        else
        {
            cout << "[Error] The balance is not enough: " << pAcc->GetBalance() << endl;
            return;
        }       
    }

    cout << "Complete" << endl;
}


void AccountHandler::ShowAllAccInfo (void)
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccountInfo();
    }
}

Account* AccountHandler::GetAccount (int accID)
{
    for (int i = 0; i < accNum; i++)
    {
        if(accArr[i]->GetAccountID() == accID)
        {
            return accArr[i];
        }
    }

    return NULL;
}

void Account::ShowAccountInfo(void) const
{
    cout << "Account ID: " << accID << endl;
    cout << "Name: " << cusName << endl;
    cout << "Balance: " << balance << endl << endl;
}