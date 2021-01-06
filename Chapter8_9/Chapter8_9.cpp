#include <iostream>

constexpr int LIMIT = 100;

class SafeArray
{
private:
    int m_botLine;
    int m_upLine;
    int m_arr[LIMIT];
public:
    SafeArray(int bot, int up) : m_botLine(bot), m_upLine(up)
    {
        if ((m_botLine >= m_upLine || (m_upLine - m_botLine) > 100) || ((m_botLine < 0) || (m_upLine < 0)))
           throw std::runtime_error("The bounds are wrong!");
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
            throw std::runtime_error("The index is out of bounds!");
        return m_arr[-m_botLine + n];
    }
};

int main()
{
    try
    {
        SafeArray sa(23, 54);
        for (int i = sa.getBottomLine(); i < sa.getUpperLine(); i++)
        {
            sa[i] = i;
            std::cout << "sa[" << i << "]: " << sa[i] << " ";
        }
        sa[5] = 12;
    }
    catch (std::exception& e)
    {
        std::cout << "\nException: " << e.what();
    }
}
