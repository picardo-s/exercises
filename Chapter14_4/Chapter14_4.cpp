#include <iostream>

template<class Type>
void swaps(Type& arg1, Type& arg2)
{
    /*Type temp = arg1;
    arg1 = arg2;
    arg2 = temp;*/
    std::swap(arg1, arg2);
}

int main()
{
    int i1 = 5, i2 = 10;
    long l1 = 3, l2 = 7;
    double d1 = 1.5, d2 = 3.7;
    float f1 = 0.1, f2 = 9.3;
    char c1 = 'Q', c2 = '&';

    swaps(i1, i2);
    swaps(l1, l2);
    swaps(d1, d2);
    swaps(f1, f2);
    swaps(c1, c2);

    std::cout << "Now i1 = " << i1 << ", i2 = " << i2
        << "\nl1 = " << l1 << ", l2 = " << l2
        << "\nd1 = " << d1 << ", d2 = " << d2
        << "\nf1 = " << f1 << ", f2 = " << f2
        << "\nc1 = " << c1 << ", c2 = " << c2;
}
