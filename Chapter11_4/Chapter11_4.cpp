#include <iostream>
#include <string>
#include <vector>

double get_user_number()
{
    double temp;
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::runtime_error("Wrong input\n");
    }
    return temp;
}

std::string get_user_string()
{
    std::string temp;
    std::cin >> std::ws;
    std::getline(std::cin, temp);
    return temp;
}

double get_more_than_zero()
{
    double temp;
    while (1)
    {
        temp = get_user_number();
        if (temp < 0)
        {
            std::cout << "Cannot be less than 0. Again: ";
            continue;
        }
        return temp;
    }
}

constexpr int MAX_PAGES = 800;
constexpr int MAX_LASTING = 90;

class Publication
{
private:
    std::string m_name;
    double m_cost;
public:
    Publication() : m_name("N/A"), m_cost(0)
    {}
    Publication(const std::string& name, const double cost)
        : m_name(name), m_cost(cost)
    {
        if (cost < 0)
            throw std::runtime_error("Cost cannot be less than 0");
    }
    virtual void get_data()
    {
        std::cout << "Enter a name of the book: ";
        m_name = get_user_string();
        std::cout << "Enter cost of the book: ";
        m_cost = get_more_than_zero();
    }
    virtual void put_data() const
    {
        std::cout << "\nName: " << m_name << "\nCost: " << m_cost << '\n';
    }
    virtual bool isOversize() const = 0;
    virtual ~Publication()
    {}
};

class Book : public Publication
{
private:
    int m_pages;
public:
    Book() : Publication(), m_pages(0)
    {}
    Book(const std::string& name, const double cost, const int pages)
        : Publication(name, cost), m_pages(pages)
    {
        if (pages < 0)
            throw std::runtime_error("Pages cannot be less than 0");
    };
    void get_data()
    {
        Publication::get_data();
        std::cout << "Enter an amount of pages: ";
        m_pages = get_more_than_zero();
    }
    void put_data() const
    {
        Publication::put_data();
        std::cout << "Amount of pages: " << m_pages << '\n';
    }
    bool isOversize() const
    {
        return (m_pages > MAX_PAGES) ? true : false;
    }
};

class Tape : public Publication
{
private:
    double m_lasting;
public:
    Tape() : Publication(), m_lasting(0)
    {}
    Tape(const std::string& name, const double cost, double m_last)
        : Publication(name, cost), m_lasting(m_last)
    {
        if (m_last < 0)
            throw std::runtime_error("Lasting cannot be less than 0");
    }
    void get_data()
    {
        Publication::get_data();
        std::cout << "Enter lasting of the tape (min): ";
        m_lasting = get_more_than_zero();
    }
    void put_data() const
    {
        Publication::put_data();
        std::cout << "Lasting (min): " << m_lasting << '\n';
    }
    bool isOversize() const
    {
        return (m_lasting > MAX_LASTING) ? true : false;
    }
};

int main()
{
    std::vector<Publication*> v_pub;
    char choise = 'a';

    do
    {
        Publication* pub_ptr;
        std::cout << "Enter book type (b - book, t - tape): ";
        std::cin >> choise;
        if (choise == 'b')
            pub_ptr = new Book;
        else if(choise == 't')
            pub_ptr = new Tape;
        else
        {
            std::cout << "\'b\' or \'t\' are expected\n";
            continue;
        }
        pub_ptr->get_data();
        v_pub.push_back(pub_ptr);
        std::cout << "Continue?(y/n): ";
        std::cin >> choise;
        std::cout << '\n';
    } while (choise != 'n');

    for (auto& p : v_pub)
    {
        p->put_data();
        if(p->isOversize())
            std::cout << "Oversize!\n";
    }
}