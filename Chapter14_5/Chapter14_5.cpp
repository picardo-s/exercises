#include <iostream>

template<class Type>
Type amax(Type* arr, const int size)
{
    Type max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    constexpr int SIZE = 5;
    int int_arr[SIZE] = { 3, 5, 78, 13, 101 };
    long long_arr[SIZE] = { 345, 456, 123, 905, 103 };
    double double_arr[SIZE] = { 4.3, 6.7, 1.2, 9.8, 7.4 };
    char ch_arr[SIZE] = { 'A', 'v', '1', '^', '@' };

    std::cout << "Int: " << amax(int_arr, SIZE)
        << "\nLong: " << amax(long_arr, SIZE)
        << "\nDouble: " << amax(double_arr, SIZE)
        << "\nChar: " << amax(ch_arr, SIZE);
}
