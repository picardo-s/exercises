#include <iostream>

const int DAYS = 7;

void bsort(const char** arr, int n);
void order(const char** str1,const char** str2);

int main()
{
    const char* arrptrs[DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday" };

    bsort(arrptrs, DAYS);

    for (int i = 0; i < DAYS; i++)
        std::cout << arrptrs[i] << " ";

    //std::cout << '\n';                  
    //std::cout << '\n';
    //std::cout << arrptrs;
    //std::cout << '\n';
    //std::cout << arrptrs + 2;
    //std::cout << '\n';
    //std::cout << *(arrptrs + 4);
    //std::cout << '\n';
    //std::cout << *(*(arrptrs + 2)+2);
}

void bsort(const char** arr, int n)
{
    int j, k;
    for (int j = 0; j < DAYS - 1; j++)
        for (k = j + 1; k < DAYS; k++)
            order(arr + j, arr + k);
}
void order(const char** str1, const char** str2)
{
    if (strcmp(*str1, *str2) > 0)
    {
        const char* temp = *str1;
        *str1 = *str2;
        *str2 = temp;
    }
}