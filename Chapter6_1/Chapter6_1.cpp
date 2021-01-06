#include <iostream>

class Int
{
private:
    int m_number;
public:
    Int() : m_number(0)
    {}
    Int(int num) : m_number(num)
    {}
    void setZero() { m_number = 0; }
    void set(int num) { m_number = num; }
    void print() const
    {
        std::cout << m_number << '\n';
    }
    void add(Int a, Int b);
};

void Int::add(Int a, Int b)
{
    m_number += (a.m_number + b.m_number);
}

int main()
{
    
    Int int1(10), int2(15), int3;

    std::cout << sizeof(int1) << " " << sizeof(int2) << '\n';

    int3.add(int1, int2);
    int3.print();
}
