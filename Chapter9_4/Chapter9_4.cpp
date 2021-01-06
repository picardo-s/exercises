#include <iostream>
#include <string>



class Publication
{
private:
    std::string m_name;
    float m_cost;
public:
    void getdata()
    {
        std::cout << "Enter the name of the book: ";
        std::cin >> std::ws;
        getline(std::cin, m_name);
        std::cout << "Enter the cost of the book: ";
        std::cin >> m_cost;
    }
    void putdata() const
    {
        std::cout << "\nName: " << m_name << "\nCost: " << m_cost << '\n';
    }
};

class Sales
{
private:
    static const int LIM = 3;
    float m_months[LIM];
public:
    void getdata()
    {
        for (int i = 0; i < LIM; i++)
        {
            std::cout << "Enter the " << (i + 1) << " income: ";
            std::cin >> m_months[i];
        }
    }
    void putdata() const
    {
        for (int i = 0; i < LIM; i++)
            std::cout << "Income #" << (i + 1) << ": " << m_months[i] << '\n';
    }

};

class Book : private Publication, private Sales
{
private:
    int m_pages;
public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "Enter an amount of pages: ";
        std::cin >> m_pages;
        Sales::getdata();
    }
    void putdata() const
    {
        Publication::putdata();
        std::cout << "Amount of pages: " << m_pages << '\n';
        Sales::putdata();
    }
};

class Tape : private Publication, private Sales
{
private:
    float m_lasting;
public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "Enter a lasting of the tape (min): ";
        std::cin >> m_lasting;
        Sales::getdata();
    }
    void putdata() const
    {
        Publication::putdata();
        std::cout << "Lasting (min): " << m_lasting << '\n';
        Sales::putdata();
    }

};

class Disk : private Publication, private Sales
{
private:
    enum dsk { cd, dvd, n =-1 };
    int m_diskType;
public:
    void getdata()
    {
        Publication::getdata();
        char type;
        std::cout << "Enter the disk type (c - cd, d - dvd): ";
        std::cin >> type;
        switch (type)
        {
        case 'c': m_diskType = dsk::cd; break;
        case 'd': m_diskType = dsk::dvd; break;
        default: m_diskType = dsk::n;
        }
        Sales::getdata();
    }
    void putdata() const
    {
        Publication::putdata();
        std::cout << "Disk type: ";
        switch (m_diskType)
        {
        case dsk::cd: std::cout << "CD\n"; break;
        case dsk::dvd: std::cout << "DVD\n"; break;
        case dsk::n: std::cout << "wrong type\n";
        }
        Sales::putdata();
    }
};

int main()
{
    Disk ds;
    ds.getdata();
    ds.putdata();
}
