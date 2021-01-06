#include <iostream>
#include <string>

class String
{
private:
    static const int SZ = 80;
    char str[SZ];
public:
    String()
    {
        strcpy_s(str, "");
    }

    String(const char s[])
    {
        if (strlen(s) >= SZ)
            throw String::StringOverflow("Overflow! (1 arg constructor).");
        strcpy_s(str, s);
    }

    void display() const
    {
        std::cout << str;
    }

    String operator+(const String& ss) const
    {
        String temp;
        if (strlen(str) + strlen(ss.str) < SZ)
        {
            strcpy_s(temp.str, str);
            strcat_s(temp.str, ss.str);
        }
        else
            throw String::StringOverflow("Overflow! (operator+)");
        return temp;
    }

    class StringOverflow
    {
    public:
        const std::string str_err;
        StringOverflow(const char s[]) : str_err(s)
        {}
    };
};

int main()
{
    try
    {
        String s1("a");
        String s2("1111111111111111111111111111111111111111111111111111111111111111111111111111112");
        String s3 = s1 + s2;
        s3.display();
    }
    catch (String::StringOverflow e)
    {
        std::cout << "Exception: " << e.str_err;
    }
}
