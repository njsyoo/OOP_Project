#include "BankingSystem.h"

using namespace BankingSystem;
using namespace std;

int main (void)
{
    int user_input = 0;

    while (1)
    {
        ShowMenu();

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
                MakeAccount();
                break;
            case DEPOSIT:
                UpdateBalance(DEPOSIT);
                break;
            case WITHDRAW:
                UpdateBalance(WITHDRAW);
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Wrong Input!" << endl;
        }

    }

    return 0;
}