#include <iostream>

class Stack
{
protected:
    static const int MAX = 10;
    int m_st[MAX];
    int m_top;
public:
    Stack() : m_top(-1)
    {}
    void push(int var)
    {
        m_st[++m_top] = var;
    }
    int pop()
    {
        return m_st[m_top--];
    }
};

class Stack2 : public Stack
{
public:
    void push(int var)
    {
        if (m_top >= MAX - 1)
        {
            std::cout << "Stack is full!";
            std::exit(1);
        }
        Stack::push(var);
    }
    int pop()
    {
        if (m_top < 0)
        {
            std::cout << "Stack is empty!";
            std::exit(1);
        }
        return Stack::pop();
    }
};

struct Pair
{
    int x;
    int y;
};

class PairStack : private Stack2
{
public:
    void push(const Pair& p)
    {
        Stack2::push(p.x);
        Stack2::push(p.y);
    }
    Pair& pop()
    {
        Pair temp;
        temp.y = Stack2::pop();
        temp.x = Stack2::pop();
        return temp;
    }
};

int main()
{
    Pair p1{ 10, 35 };
    Pair p2{ -5, 0 };
    PairStack ps;
    ps.push(p1);
    ps.push(p2);
    Pair p3 = ps.pop();
    std::cout << "( " << p3.x << " ; " << p3.y << " )" << '\n';
    p3 = ps.pop();
    std::cout << "( " << p3.x << " ; " << p3.y << " )" << '\n';
}
