#include <iostream>
#include <cstring>

void reversit(char st[])
{
    int length = strlen(st);

    int begin = 0, end = length - 1;
    unsigned char temp;
    for (; begin < end; begin++, end--)
    {
        temp = st[begin];           //std::swap(st[begin], st[end]);
        st[begin] = st[end];
        st[end] = temp;
    }
}

int main()
{
    const int MAX = 100;
    char str[MAX];
    std::cout << "Enter text: ";
    std::cin.get(str, MAX);
    reversit(str);
    std::cout << "Reversed text: " << str;
}
