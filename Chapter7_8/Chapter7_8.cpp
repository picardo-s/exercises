#include <iostream>

class SafeArray
{
private:
    static const int LIMIT = 10;
    int m_array[LIMIT];
public:
    void putel(int ind, int num)
    {
        if ((ind < 0) || (ind > LIMIT - 1))
        {
            std::cout << "The index is out of bounds!";
            std::exit(1);
        }
        m_array[ind - 1] = num;
    }
    int getel(int ind)
    {
        if ((ind < 0) || (ind > LIMIT - 1))
        {
            std::cout << "The index is out of bounds!";
            std::exit(1);
        }
        return m_array[ind - 1];
    }
};

int main()
{
    SafeArray sa;
    int number = 10;
    sa.putel(5, number);
    int ret = sa.getel(5);
    number = sa.getel(1); //unexpected number
    std::cout << ret << " " << number << '\n';
    ret = sa.getel(12);
}
