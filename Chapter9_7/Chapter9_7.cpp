#include <iostream>

class Counter
{
protected:
    unsigned int m_count;
public:
    Counter() : m_count(0)
    {}
    Counter(int c) : m_count(c)
    {}
    unsigned int get_count() const
    {
        return m_count;
    }
    Counter operator++()
    {
        return Counter(++m_count);
    }
};

class CountDn : public Counter
{
public:
    CountDn() : Counter()
    {}
    CountDn(int c) : Counter(c)
    {}
    CountDn operator--()
    {
        return CountDn(--m_count);
    }
};

class CountF : public CountDn
{
public:
    CountF() : CountDn()
    {}
    CountF(int c) : CountDn(c)
    {}
    using CountDn::operator++; //thanks to Scott Meyers
    using CountDn::operator--;
    CountF operator++(int)
    {
        return CountF(m_count++);
    }
    CountF operator--(int)
    {
        return CountF(m_count--);
    }
};

int main()
{
    CountF cf(5);
    ++cf;
    --cf;
    cf++;
    cf--;
    cf--;
    std::cout << cf.get_count();    
}
