#include <iostream>

void addArrays(const float* arr1, const float* arr2, float* sum, const int len);

int main()
{
    const int LEN = 10;
    float arr1[LEN] = { 12.1, 15, 12.5, 65, 0.5, -2, 34.8, 54.4, 78.1, 90.2 };
    float arr2[LEN] = { 22.3, -45.1, 32.5, 61, -10.5, 12, 4.8, 41.3, 18.1, 0.2 };
    float arr3[LEN];
    addArrays(arr1, arr2, arr3, LEN);

    for (int i = 0; i < LEN; i++)
        std::cout << *(arr3 + i) << " ";
}

void addArrays(const float* arr1, const float* arr2, float* sum, const int len)
{
    for (int i = 0; i < len; i++)
    {
        *(sum + i) = *(arr1 + i) + *(arr2 + i);
    }
}