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
            throw OutOfBounds(n);
        return arr[n];
    }
    class OutOfBounds
    {
    public:
        const int error_ind;
        OutOfBounds(int er_ind) : error_ind(er_ind)
        {}
    };
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
            std::cout << safe_arr[i] << "[" << i << "]" << " ";
    }
    catch (SafeArray<SA_type>::OutOfBounds e)
    {
        std::cout << "\nThe index " << e.error_ind << " is out of bounds";
    }
}