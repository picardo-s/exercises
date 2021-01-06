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
    void putdata()
    {
        std::cout << "\nName: " << m_name << "\nCost: " << m_cost << '\n';
    }
};

class Book : private Publication
{
private:
    int m_pages;
public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "Enter an amount of pages: ";
        std::cin >> m_pages;
    }
    void putdata()
    {
        Publication::putdata();
        std::cout << "Amount of pages: " << m_pages << '\n';
    }
};

class Type : private Publication
{
private:
    float m_lasting;
public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "Enter a lasting of the tape (min): ";
        std::cin >> m_lasting;
    }
    void putdata()
    {
        Publication::putdata();
        std::cout << "Lasting (min): " << m_lasting << '\n';
    }

};

int main()
{
    Book book;
    Type type;
    book.getdata();
    type.getdata();
    book.putdata();
    type.putdata();
}
