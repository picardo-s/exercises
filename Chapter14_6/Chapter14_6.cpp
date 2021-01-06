#include <iostream>

constexpr int LIMIT = 100;

template<class Type>
class SafeArray
{
private:
    Type arr[LIMIT];
public:
    Type& operator[](const int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            std::cout << "The index " << n << " is out of bounds";
            std::exit(1);
        }
        return arr[n];
    }
};

int main()
{
    SafeArray<char> sa_int;

    for (int i = 0; i < 10; i++)
        sa_int[i] = i +35.1;

    for (int i = 1; i < 10; i++)
        std::cout << sa_int[i] << " ";
}
