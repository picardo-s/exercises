#include <iostream>

class ClassCount
{
private:
    int m_personNumber;
    static int m_classCount;
public:
    ClassCount() : m_personNumber(++m_classCount)
    {}

    void displayPersonalNumber()
    {
        std::cout << "My personal number is: " << m_personNumber << '\n';
    }
};

int ClassCount::m_classCount = 0;

int main()
{
    ClassCount cc1, cc2, cc3;
    cc1.displayPersonalNumber();
    cc2.displayPersonalNumber();
    cc3.displayPersonalNumber();
}

