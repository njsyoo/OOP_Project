#include "BankingSystem.h"

using namespace std;
using namespace BankingSystem;


Account accArr[MAX_ACCOUNT];
int accNum = 0;

void BankingSystem::ShowMenu (void)
{
    cout << "-----Menu-----" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Print all Account" << endl;
    cout << "5. Exit Program" << endl;
}

void BankingSystem::MakeAccount (void)
{
    int accID;
    int balance;
    char name[NAME_LEN];

    cout << "[Create Account]" << endl;
    cout << "Account ID:";
    cin >> accID;

    if(GetAccount(accID) == -1)
    {
        accArr[accNum].accID = accID;
    }
    else
    {
        cout << "[Error] The Accoun ID already exist" << endl;
        return;
    }

    cout << "Name:";
    cin >> name;

    strcpy (accArr[accNum].cusName, name);

    cout << "Deposit:";
    cin >> balance;

    accArr[accNum].balance = balance;

    accNum++;
}

void BankingSystem::UpdateBalance (int action)
{
    int accID = -1;
    int index = 0;
    int balance;

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

    index = GetAccount(accID);

    if(index == -1)
    {
        cout << "[Error] Wrong Account ID." << endl;
        return;
    }

    cout << "Amount of Money:";
    cin >> balance;

    if(action == DEPOSIT)
    {
        accArr[index].balance += balance;
    }
    else
    {
        if (accArr[index].balance >= balance)
        {
            accArr[index].balance -= balance;
        }
        else
        {
            cout << "[Error] The balance is not enough: " << accArr[index].balance << endl;
            return;
        }       
    }

    cout << "Complete" << endl;
}


void BankingSystem::ShowAllAccInfo (void)
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "Account ID: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}

int BankingSystem::GetAccount (int accID)
{
    for (int i = 0; i < BankingSystem::MAX_ACCOUNT; i++)
    {
        if(accArr[i].accID == accID)
        {
            return i;
        }
    }

    return -1;
}