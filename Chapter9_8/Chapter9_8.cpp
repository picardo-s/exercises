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

class Pstring2 : public Pstring
{
public:
    Pstring2() : Pstring()
    {}
    Pstring2(const char s[]) : Pstring(s)
    {}
    Pstring2& left(const Pstring2& pstr, int num)   //I don't understand the extra credit of this exercise...for now!
    {
        if (num >= SZ || num > strlen(pstr.m_str))
        {
            std::cout << "Too many characters!";
            std::exit(1);
        }
        int mStrLen = strlen(m_str);
        for (int i = 0; i < num; i++)
            m_str[i] = pstr.m_str[i];
        if(mStrLen < num)
            m_str[num] = '\0';
        return *this;
    }
    Pstring2& mid(const Pstring2& pstr, int start, int num)
    {
        if (start + num >= SZ || start + num > strlen(pstr.m_str))
        {
            std::cout << "Too many characters!";
            std::exit(1);
        }
        int mStrLen = strlen(m_str);
        for (int i = 0; i < num; i++)
            m_str[i] = pstr.m_str[start + i];
        if (mStrLen < num)
            m_str[num] = '\0';
        return *this;
    }
    Pstring2& right(const Pstring2& pstr, int num)
    {
        if (num >= SZ || num > strlen(pstr.m_str))
        {
            std::cout << "Too many characters!";
            std::exit(1);
        }
        int mStrLen = strlen(m_str);
        int pstrLen = strlen(pstr.m_str);
        for (int i = 0; i < num; i++)
            m_str[i] = pstr.m_str[strlen(pstr.m_str) - num + i];
        if (mStrLen < num)
            m_str[num] = '\0';
        return *this;
    }
};

int main()
{
    Pstring2 s1("I can't believe this is truth!"); 
    Pstring2 s2("What was that??");
    s1.left(s2, 4);
    s1.display();
    std::cout << '\n';
    s1.mid(s2, 5, 3);
    s1.display();
    std::cout << '\n';
    s1.right(s2, 6);
    s1.display();
}
