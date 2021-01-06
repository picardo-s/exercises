#include <iostream>

const int LIM = 100;

class SafeArray
{
private:
    int m_arr[LIM];
public:
    int& operator[](int n)
    {
        if (n < 0 || n >= LIM)
        {
            std::cout << "The index is out of bounds!";
            std::exit(1);
        }
        return m_arr[n];
    }
};

class SafeHilo : public SafeArray
{
private:
    int m_botLine;
    int m_upLine;
public:
    SafeHilo(int bot = 0, int up = 100) : m_botLine(bot), m_upLine(up)
    {
        if ((m_botLine >= m_upLine || (m_upLine - m_botLine) > 100) || ((m_botLine < 0) || (m_upLine < 0)))
        {
            std::cout << "The bounds are wrong!";
            std::exit(1);
        }
    }
    int getSize() const
    {
        return m_upLine - m_botLine;
    }
    int getBottomLine() const
    {
        return m_botLine;
    }
    int getUpperLine() const
    {
        return m_upLine;
    }
    int& operator[](int n)
    {
        if (n < m_botLine || n >= m_upLine)
        {
            std::cout << "The index is out of bounds!";
            std::exit(1);
        }
        n -= m_botLine;
        return SafeArray::operator[](n);
    }
};

int main()
{
    SafeHilo sa(30, 40);
    sa[35] = 21;
    sa[32] = 14;
    std::cout << sa[35] << " " << sa[32];
    std::cout << sa[12];
}
