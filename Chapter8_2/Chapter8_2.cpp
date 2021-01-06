#include <iostream>
#include <string>

class String
{
private:
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
    void display()
    {
        std::cout << m_str << '\n';
    }
    String operator+=(const String& ss);
};

String String::operator+=(const String& ss)
{
    if (strlen(m_str) + strlen(ss.m_str) > SZ)
    {
        std::cout << "Overflow!";
        std::exit(1);
    }
    strcat_s(m_str, ss.m_str);
    return String(m_str);
}

int main()
{
    String s1("Radio");
    String s2("Active");
    String s3 = s1 += s2;
    s1.display();
    s3.display();

}
