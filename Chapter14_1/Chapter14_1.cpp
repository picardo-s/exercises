#include <iostream>

template<class T>
T avg_arr(T arr[], int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return T(sum / size);
}

int main()
{
    constexpr int size = 5;
    int int_arr[size] = { 1, 2, 3, 4, 5 };
    long long_arr[size] = {3L, 4L, 5L, 6L, 7L};
    double double_arr[size] = { 5.1, 6.9, 7.6, 10.2, 11.5 };
    char char_arr[size] = { 'a', 'b', 'c', 'd', 'e' };
    std::cout << "int : " << avg_arr(int_arr, size)
        << "\nlong: " << avg_arr(long_arr, size)
        << "\ndouble: " << avg_arr(double_arr, size)
        << "\nchar: " << avg_arr(char_arr, size);
}

