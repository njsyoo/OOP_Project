#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

enum
{
    ACCOUNT_TYPE_NORMAL = 1,
    ACCOUNT_TYPE_CREDIT,
    ACCOUNT_TYPE_COUNT,
};

enum
{
    CREDIT_LEVEL_A = 7,
    CREDIT_LEVEL_B = 4,
    CREDIT_LEVEL_C = 2,
};

#endif