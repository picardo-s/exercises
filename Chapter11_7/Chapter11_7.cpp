#include <iostream>
#include <cstring>
#include <string>

std::string get_user_string()
{
    std::cin.exceptions(std::cin.exceptions() | std::cin.badbit | std::cin.failbit);
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

char get_user_char()
{
    std::cin.exceptions(std::cin.exceptions() | std::cin.badbit | std::cin.failbit);
    char ch;
    std::cin >> ch;
    std::cin.ignore(100, '\n');
    return ch;
}

constexpr int MAX = 20;

class Token
{
public:
    virtual double getNumber() const = 0;
    virtual char getOperator() const = 0;
    virtual ~Token()
    {}
};

class Operator : public Token
{
private:
    char m_oper;
    double getNumber() const
    {
        return 0;
    }
public:
    Operator(char op) : m_oper(op)
    {}
    char getOperator() const
    {
        return m_oper;
    }
};

class Number : public Token
{
private:
    double m_num;
    char getOperator() const
    {
        return '0';
    }
public:
    Number(double fnum) : m_num(fnum)
    {}
    double getNumber() const
    {
        return m_num;
    }
};

class Stack
{
private:
    Token* m_st[MAX];
    int m_top;
public:
    Stack()
    {
        m_top = -1;
    }
    void push(Token* var)
    {
        if (m_top >= MAX - 1)
            throw std::runtime_error("Stack: overflow");
        m_st[++m_top] = var;
    }
    Token* pop()
    {
        if (m_top < 0)
            throw std::runtime_error("Stack: empty");
        return m_st[m_top--];
    }
    int getTop() const
    {
        return m_top;
    }
};

int isTokenOperator(Token* pUnknown)
{
    Operator* oper;
    if (oper = dynamic_cast<Operator*>(pUnknown))
        return 1;
    else return 0;
}

class Express
{
private:
    Stack m_s;
    Token* m_pStr[MAX];
    int m_len;
public:
    Express(const char* ptr);
    void parse();
    double solve();
};

Express::Express(const char* ptr) : m_len(0)
{
    int i = 0;
    while (*(ptr + i) != '\0')
    {
        if (isspace(*(ptr + i)))
        {
            i++;
            continue;
        }
        else if (isdigit(*(ptr + i)) || *(ptr + i) == '.')
        {
            std::string ch_num{};
            for (; isdigit(*(ptr + i)) || *(ptr + i) == '.'; i++)
                ch_num += *(ptr + i);
            *(m_pStr + m_len++) = new Number(atof(ch_num.c_str()));
        }
        else if (*(ptr + i) == '+' || *(ptr + i) == '-' || *(ptr + i) == '*' || *(ptr + i) == '/')
        {
            *(m_pStr + m_len++) = new Operator(*(ptr + i++));
        }
        else
            throw std::runtime_error("Wrong symbol");
    }
}
void Express::parse()
{
    double lastVal;
    char lastOp;
    Token* tokenPtr;

    for (int j = 0; j < m_len; j++)
    {
        if (j == 0 && isTokenOperator(*(m_pStr + j)))
            throw std::runtime_error("Starts from Operator");

        if (!isTokenOperator(*(m_pStr + j)))
            m_s.push(*(m_pStr + j));
        else
        {
            if (m_s.getTop() == 0)
                m_s.push(*(m_pStr + j));
            else
            {
                tokenPtr = m_s.pop();
                lastVal = tokenPtr->getNumber();
                delete tokenPtr;
                tokenPtr = m_s.pop();
                lastOp = tokenPtr->getOperator();
                delete tokenPtr;
                if (((*(m_pStr + j))->getOperator() == '*' || (*(m_pStr + j))->getOperator() == '/') && (lastOp == '+' || lastOp == '-'))
                {
                    m_s.push(new Operator(lastOp));
                    m_s.push(new Number(lastVal));
                }
                else
                {
                    tokenPtr = m_s.pop();
                    switch (lastOp)
                    {
                    case '+': m_s.push(new Number(tokenPtr->getNumber() + lastVal)); break;
                    case '-': m_s.push(new Number(tokenPtr->getNumber() - lastVal)); break;
                    case '*': m_s.push(new Number(tokenPtr->getNumber() * lastVal)); break;
                    case '/': m_s.push(new Number(tokenPtr->getNumber() / lastVal)); break;
                    default: throw std::runtime_error("Wrong symbol");
                    }
                    delete tokenPtr;
                }
                m_s.push(*(m_pStr + j));
            }
        }
    }
}

double Express::solve()
{
    double lastVal;
    char lastOp;
    Token* tokenPtr;

    while (m_s.getTop() > 0)
    {
        tokenPtr = m_s.pop();
        lastVal = tokenPtr->getNumber();
        delete tokenPtr;
        tokenPtr = m_s.pop();
        lastOp = tokenPtr->getOperator();
        delete tokenPtr;
        tokenPtr = m_s.pop();
        switch (lastOp)
        {
        case '+': m_s.push(new Number(tokenPtr->getNumber() + lastVal)); break;
        case '-': m_s.push(new Number(tokenPtr->getNumber() - lastVal)); break;
        case '*': m_s.push(new Number(tokenPtr->getNumber() * lastVal)); break;
        case '/': m_s.push(new Number(tokenPtr->getNumber() / lastVal)); break;
        default: throw std::runtime_error("Wrong symbol");
        }
        delete tokenPtr;
    }
    tokenPtr = m_s.pop();
    lastVal = tokenPtr->getNumber();
    delete tokenPtr;
    return lastVal;
}

int main()
{
    char ans;
    std::string str;
    try
    {
        do
        {
            std::cout << "Enter an expression: ";
            str = get_user_string();
            Express exp(str.c_str());
            exp.parse();
            std::cout << "Result: " << exp.solve();
            std::cout << "\nContinue?(y/n): ";
            ans = get_user_char();           
        } while (ans == 'y');
    }
    catch(std::exception& e)
    {
        std::cout << "Exception! " << e.what();
    }
}