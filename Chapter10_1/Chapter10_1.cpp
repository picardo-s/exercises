#include <iostream>

int main()
{
    float arr[100];
    int count = 0;
    int* ptr_count = &count;
    char manip;
    char* ptr_manip = &manip;

    do
    {
        std::cout << "Enter the float number: ";
        std::cin >> *(arr + (*ptr_count)++);
        std::cout << "Continue? (y/n): ";
        std::cin >> *ptr_manip;
    } while (*ptr_manip != 'n');

    float result = 0;
    float* ptr_result = &result;

    for(int i = 0; i < *ptr_count; i++)
        *ptr_result += *(arr + i);

    std::cout << "\nThe average is " << *ptr_result / *ptr_count;
}
