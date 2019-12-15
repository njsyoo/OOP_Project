#include "BankingSystem.h"

using namespace BankingSystem;
using namespace std;

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

    return 0;
}