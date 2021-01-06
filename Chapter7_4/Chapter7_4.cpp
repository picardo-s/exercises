#include <iostream>

int maxInt(int arr[], int size);

int main()
{
    const int MAX = 20;
    int intArr[MAX];
    int count = 0;
    char manip;

    do
    {
        std::cout << "Enter a number: ";
        std::cin >> intArr[count++];
        std::cout << "Continue?(n/y): ";
        std::cin >> manip;
    } while (manip != 'n' && count < MAX);

    std::cout << "\nThe max integer is " << maxInt(intArr, count);
}

int maxInt(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}