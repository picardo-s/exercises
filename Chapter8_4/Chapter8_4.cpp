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

    Int operator+(const Int& i);
    Int operator-(const Int& i);
    Int operator*(const Int& i);
    Int operator/(const Int& i);
    Int boundCheck(double num);
    operator double() const
    {
        return static_cast<double>(m_number);
    }
};

Int Int::operator+(const Int& i)
{
    Int temp;
    return temp.boundCheck(double(m_number) + i.m_number); 
}

Int Int::operator-(const Int& i)
{
    Int temp;
    return temp.boundCheck(double(m_number) - i.m_number);
}

Int Int::operator*(const Int& i)
{
    Int temp;
    return temp.boundCheck(double(m_number) * i.m_number);
}

Int Int::operator/(const Int& i)
{
    Int temp;
    return temp.boundCheck(double(m_number) / i.m_number);
}

Int Int::boundCheck(double num)
{
    if (num > 2147483647 || num < -2147483648)
    {
        std::cout << "Overflow!";
        std::exit(1);
    }
    return Int(num);
}

int main()
{
    Int a(50), b(10);
    Int c = a + b;
    c.print();
    c = a - b;
    c.print();
    c = a * b;
    c.print();
    c = a / b;
    c.print();

    a.set(2000000000);
    b.set(1000000000);
    c = a + b;
    c.print();
}
