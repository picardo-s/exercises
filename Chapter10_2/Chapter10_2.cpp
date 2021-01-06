#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>

class String
{
private:
    char* m_str;
public:
    String(const char* s)
    {
        int length = strlen(s);
        m_str = new char[length + 1];
        strcpy(m_str, s);
    }
    ~String()
    {
        std::cout << "Deleting the string\n";
        delete [] m_str;
    }
    void display()
    {
        std::cout << m_str << '\n';
    }
    void upit()
    {
        char* chstr = m_str;
        while (*chstr)
        {
            *chstr = toupper(*chstr);
            chstr++;
        }
    }
};

int main()
{
    const char* str = "What does 0 mean?";
    String s1(str);
    s1.upit();
    s1.display();
}
