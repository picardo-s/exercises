#include <iostream>

void swap(int& a_out, int& b_out);

int main()
{
    int a, b;

    std::cout << "Enter the number \'a\': ";
    std::cin >> a;
    std::cout << "Enter the number \'b\': ";
    std::cin >> b;

    swap(a, b);

    std::cout << "Now a = " << a << ", b = " << b;

}

void swap(int& a_out, int& b_out)
{
    int temp = a_out;
    a_out = b_out;
    b_out = temp;
}