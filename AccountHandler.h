#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

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
    BoundCheckArray<Account*> accArr;
    int accNum;
};

#endif