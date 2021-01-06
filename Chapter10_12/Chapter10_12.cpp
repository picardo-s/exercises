#include <iostream>

constexpr int LIM = 100;

float fmemory[LIM]; //Why are these arrays global? As to me, I consider these ones (especially in this exercise) as a global memory
int pmemory[LIM]; // which can be available for accessing from any classes to be used.

class Float
{
private:
    int m_addr;
public:
    Float(float fl)
    {
        static int fmem_top = -1;
        ++fmem_top;
        if (fmem_top >= 100)
            throw std::runtime_error("fmemory overflow");
        fmemory[fmem_top] = fl;
        m_addr = fmem_top;
    }
    const int& operator&()
    {
        return m_addr;
    }
    const int& operator&() const
    {
        return m_addr;
    }
    friend std::ostream& operator<<(std::ostream&, const Float&);
};

std::ostream& operator<<(std::ostream& os, const Float& f)
{
    os << fmemory[f.m_addr];
    return os;
}

class ptrFloat
{
private:
    int m_addr;
public:
    ptrFloat(int adr)
    {
        static int pmem_top = -1;
        ++pmem_top;
        if (pmem_top >= 100)
            throw std::runtime_error("pmemory overflow");
        pmemory[pmem_top] = adr;
        m_addr = pmem_top;
    }
    float& operator*()
    {
        return fmemory[pmemory[m_addr]];
    }
    float& operator*() const
    {
        return fmemory[pmemory[m_addr]];
    }
    friend std::ostream& operator<<(std::ostream&, const ptrFloat&);
};

std::ostream& operator<<(std::ostream& os, const ptrFloat& p)
{
    os << p.m_addr;
    return os;
}

class Test
{
private:
    int a;
public:
    Test() : a{0}
    {}
    void set(int num)
    {
        a = num;
    }
    int get() const
    {
        return a;
    }
};

constexpr int MAX = 10;

int main()
{
    Float f = 2.5;
    std::cout << &f << ' ' << f;
    const ptrFloat pf = &f;
    *pf = 3.1;
    //pf = &f;
    std::cout << '\n' << pf << ' ' << *pf << '\n';

    Float var1 = 1.234;
    Float var2 = 5.678;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    std::cout << "*ptr1 = " << *ptr1;
    std::cout << "\n*ptr2 = " << *ptr2;

    *ptr1 = 7.123;
    *ptr2 = 8.456;

    std::cout << "\n*ptr1 = " << *ptr1;
    std::cout << "\n*ptr2 = " << *ptr2;
}
