#include <iostream>

int compstr(const char* str1, const char* str2);

int main()
{
    const char* str1 = "You are lucky";
    const char* str2 = "So what?";
    int result = compstr(str1, str2);
    if (result == -1)
        std::cout << "str1 before str2";
    else if (result == 0)
        std::cout << "str1 and str2 are equal";
    else std::cout << "str1 after str2";
}

int compstr(const char* str1, const char* str2)
{
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    int minLen = str1Len < str2Len ? str1Len : str2Len;

    for (int i = 0; i < minLen; i++)
    {
        if (*(str1 + i) < *(str2 + i))
            return -1;
        if(*(str1 + i) > *(str2 + i))
            return 1;
    }
    if (str1Len == str2Len)
        return 0;
    else if (str1Len < str2Len)
        return -1;
    else return 1;
}