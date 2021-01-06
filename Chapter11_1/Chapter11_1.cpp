#include <iostream>
#include <string>

class Publication
{
private:
    std::string m_name;
    float m_cost;
public:
    virtual void getdata()
    {
        std::cout << "Enter the name of the book: ";
        std::cin >> std::ws;
        getline(std::cin, m_name);
        std::cout << "Enter the cost of the book: ";
        std::cin >> m_cost;
    }
    virtual void putdata()
    {
        std::cout << "\nName: " << m_name << "\nCost: " << m_cost << '\n';
    }
};

class Book : public Publication
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

class Type : public Publication
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
    Publication* pubArr[100];
    int n = 0;
    char choise = 'a';

    do
    {
        std::cout << "Enter the type (b - book, t - type): ";
        std::cin >> choise;
        if (choise == 'b')
            pubArr[n] = new Book;
        else
            pubArr[n] = new Type;
        pubArr[n++]->getdata();
        std::cout << "Continue?(y/n): ";
        std::cin >> choise;
        std::cout << '\n';
    } while (choise != 'n');

    for (int i = 0; i < n; i++)
        pubArr[i]->putdata();
}
