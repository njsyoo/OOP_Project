#include "String.h"

String::String()
{
    len = 0;
    str = NULL;
}

String::String(const char* s)
{
    len = strlen(s) + 1;
    str = new char[len];

    strcpy (str, s);
}

String::String(const String& s)
{
    len = s.len;
    str = new char[len];

    strcpy(str, s.str);
}

String::~String()
{
    if(str != NULL)
        delete []str;
}

String& String::operator=(const String& s)
{
    if(str != NULL)
        delete []str;

    len = s.len;
    str = new char[len];

    strcpy(str, s.str);

    return *this;
}

String& String::operator+=(const String& s)
{
    char* ori_str = str;

    len = len + s.len - 1;
    str = new char[len];

    strcpy(str, ori_str);
    strcat(str, s.str);

    if(ori_str != NULL)
        delete[] ori_str;

    return *this;
}

bool String::operator == (const String& s)
{
    bool ret = true;

    for (int i=0; i<len; i++)
    {
        if (str[i] != s.str[i])
        {
            ret = false;
            break;
        }
    }

    return ret;
}

String String::operator+ (const String& s)
{
    String* new_str = new String;

    new_str->len = len + s.len - 1;
    new_str->str = new char[new_str->len];

    strcpy(new_str->str, str);
    strcat(new_str->str, s.str);
    
    return *new_str;
}

ostream& operator<< (ostream& os, const String& s)
{
    os << s.str;
    return os;
}

istream& operator>> (istream& is, String& s)
{
    char str[100];
    is >> str;
    s = String(str);
    return is;
}