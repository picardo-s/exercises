#include <iostream>
#include <string>

class String
{
protected:
    static const int SZ = 80;
    char m_str[SZ];
public:
    String()
    {
        m_str[0] = '\0';
    }
    String(const char s[])
    {
        strcpy_s(m_str, s);
    }
    void display() const
    {
        std::cout << m_str;
    }
    operator char* ()
    {
        return m_str;
    }
};

class Pstring : public String
{
public:
    Pstring() : String()
    {}
    Pstring(const char s[])
    {
        strlen(s) > (SZ - 1) ? strncpy_s(m_str, s, SZ - 1) : strcpy_s(m_str, s);
    }
};

int main()
{
    Pstring s = "QWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEQWEqweqweqweqweqweqweqweqwe123456789";
    s.display();
    std::cout << '\n';
    Pstring ss = "qweasdzxc";
    ss.display();

}
