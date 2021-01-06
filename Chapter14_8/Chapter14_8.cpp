#include <iostream>

constexpr int LIMIT = 10;

template<class Type>
class SafeArray
{
private:
    Type arr[LIMIT];
public:
    Type& operator[](const int n)
    {
        if (n < 0 || n >= LIMIT)
            throw OutOfBounds();
        return arr[n];
    }
    class OutOfBounds
    {};
};

int main()
{
    typedef double SA_type;
    try 
    {
        SafeArray<SA_type> safe_arr;

        for (int i = 0; i < 10; i++)
            safe_arr[i] = i + 1.1;

        for (int i = 0; i < 11; i++)
            std::cout << safe_arr[i] << " ";
    }
    catch (SafeArray<SA_type>::OutOfBounds)
    {
        std::cout << "\nOut of bounds";
    }
}
