#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main (void)
{
    int user_input = 0;
    AccountHandler AccHandler;

    while (1)
    {
        AccHandler.ShowMenu();

        cout << "Select: ";
        cin >> user_input;
        cout << endl;

        if(user_input == EXIT)
        {
            break;
        }

        try
        {
            switch (user_input)
            {
                case MAKE:
                    AccHandler.MakeAccount();
                    break;
                case DEPOSIT:
                    AccHandler.UpdateBalance(DEPOSIT);
                    break;
                case WITHDRAW:
                    AccHandler.UpdateBalance(WITHDRAW);
                    break;
                case INQUIRE:
                    AccHandler.ShowAllAccInfo();
                    break;
                case EXIT:
                    return 0;
                default:
                    cout << "Wrong Input!" << endl;
                    return 0;
            }
        }
        catch(...)
        {

        }
    }

    return 0;
}