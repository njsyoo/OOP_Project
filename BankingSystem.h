#include <iostream>
#include <cstring>

namespace BankingSystem
{
    const int NAME_LEN = 20;
    const int MAX_ACCOUNT = 100;

    enum
    {
        MAKE = 1,
        DEPOSIT,
        WITHDRAW,
        INQUIRE,
        EXIT
    };

    typedef struct 
    {
        int accID;
        int balance;
        char cusName[NAME_LEN];
    }Account;
    
    void ShowMenu (void);
    void MakeAccount (void);
    void UpdateBalance (int action);
    void ShowAllAccInfo (void);

    int GetAccount (int accID); 
}