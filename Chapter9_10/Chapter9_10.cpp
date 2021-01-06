#include <iostream>

const int LEN = 80;

class Student
{
private:
    char m_school[LEN];
    char m_degree[LEN];
public:
    void getedu()
    {
        std::cout << "Enter the graduated school: ";
        std::cin >> std::ws;
        std::cin.get(m_school, LEN);
        std::cout << "Enter the education level: ";
        std::cin >> std::ws;
        std::cin.get(m_degree, LEN);
    }
    void putedu() const
    {
        std::cout << "\nSchool: " << m_school;
        std::cout << "\nDegree: " << m_degree;
    }
};

class Employee
{
private:
    char m_name[LEN];
    unsigned long m_number;
public:
    void getdata()
    {
        std::cout << "Enter the surname: ";
        std::cin >> std::ws;
        std::cin.get(m_name, LEN);
        std::cout << "Enter the ID: ";
        std::cin >> m_number;
    }
    void putdata() const
    {
        std::cout << "\nSurname: " << m_name;
        std::cout << "\nID: " << m_number;
    }
};

class Manager : private Employee, private Student
{
private:
    char m_title[LEN];
    double m_dues;
public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "Enter the position: ";
        std::cin >> std::ws;
        std::cin.get(m_title, LEN);
        std::cout << "Enter the golf club dues: ";
        std::cin >> m_dues;
        Student::getedu();
    }
    void putdata() const
    {
        Employee::putdata();
        std::cout << "\nPosition: " << m_title;
        std::cout << "\nDues: " << m_dues;
        Student::putedu();
    }
};

class Scientist : private Employee, private Student
{
private:
    int m_pubs;
public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "Enter an amount of publications: ";
        std::cin >> m_pubs;
        Student::getedu();
    }
    void putdata() const
    {
        Employee::putdata();
        std::cout << "\nPublications: " << m_pubs;
        Student::putedu();
    }
};

class Laborer : private Employee
{

};

class Executive : private Manager
{
private:
    float m_prem;
    float m_share;
public:
    void getdata()
    {
        Manager::getdata();
        std::cout << "Enter the year premium: ";
        std::cin >> m_prem;
        std::cout << "Enter the amount of shares: ";
        std::cin >> m_share;
    }
    void putdata()
    {
        Manager::putdata();
        std::cout << "\nPremium: " << m_prem;
        std::cout << "\nShares: " << m_share;
    }
};

int main()
{
    Executive ex;
    ex.getdata();
    ex.putdata();
}
