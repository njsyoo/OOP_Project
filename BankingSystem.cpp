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
    int accountType;
    int interestRate;
    int creditLevel;
    char name[NAME_LEN];

    cout << "[Select Account Type]" << endl;
    cout << "1. Normal Account, 2. High Credit Account" << endl;
    cin >> accountType;

    if (accountType == 1)
    {
        cout << "[Create Normal Account]" << endl;
    }
    else if (accountType == 2)
    {
        cout << "[Create High Credit Account]" << endl;
    }
    else
    {
        cout << "Wrong Account Type" << endl;
        return;
    }  

    cout << "Account ID:";
    cin >> accID;

    if (GetAccount(accID) == NULL)
    {
        cout << "Name: ";
        cin >> name;

        cout << "Deposit: ";
        cin >> balance;

        cout << "Interest Rate: ";
        cin >> interestRate;

        if (accountType == 2)
        {
            cout << "Credit Level (1toA, 2toB, 3toC): ";
            cin >> creditLevel;

            if (creditLevel > 3)
            {
                cout << "Wrong credit level" << endl;
                return;
            } 
        }

        if (accountType == 1)
        {
            accArr[accNum++] = new NormalAccount(accID, name, balance, interestRate);
        }
        else if (accountType == 2)
        {
            accArr[accNum++] = new HighCreditAccount(accID, name, balance, interestRate, creditLevel);
        }
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
        cout << endl;
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
    cout << "Balance: " << balance << endl;
}