#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

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
    String name;

    cout << "[Select Account Type]" << endl;
    cout << "1. Normal Account, 2. High Credit Account" << endl;
    cin >> accountType;

    if (accountType == ACCOUNT_TYPE_NORMAL)
    {
        cout << "[Create Normal Account]" << endl;
    }
    else if (accountType == ACCOUNT_TYPE_CREDIT)
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

        if (accountType == ACCOUNT_TYPE_CREDIT)
        {
            cout << "Credit Level (1toA, 2toB, 3toC): ";
            cin >> creditLevel;

            if (creditLevel > 3)
            {
                cout << "Wrong credit level" << endl;
                return;
            } 
        }

        if (accountType == ACCOUNT_TYPE_NORMAL)
        {
            accArr[accNum++] = new NormalAccount(accID, name, balance, interestRate);
        }
        else if (accountType == ACCOUNT_TYPE_CREDIT)
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

    try
    {
        cout << "Amount of Money:";
        cin >> balance;

        if (balance < 0)
        {
            throw InputMoneyException(balance);
        }
    }
    catch(AccountException& except)
    {
        except.ShowExceptionReason();
        throw;
    }

    if(action == DEPOSIT)
    {
        pAcc->Deposit(balance);
    }
    else
    {
        try 
        {
            if (pAcc->GetBalance() < balance)
            {
                throw WithdrawException(balance);
            }
            pAcc->Withdraw(balance);
        }
        catch(AccountException& except)
        {
            except.ShowExceptionReason();
            throw;
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