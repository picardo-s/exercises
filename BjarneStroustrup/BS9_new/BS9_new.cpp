#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Date_ch.h"

template<class T>
T get_user_number()
{
    T temp;
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
    std::getline(std::cin, temp);
    return temp;
}

using std::vector;
using std::string;

//Exercise 2, 3 -----------------------------------------------

const string STOP_WORD{ "stop" };

class Name_pairs
{
private:
    vector<string> name{};
    vector<double> age{};
    int find_name(const vector<string>&, const string&);
public:
    void read_names();
    void read_ages();
    //void print() const;
    void sort();
    friend std::ostream& operator<<(std::ostream& os, Name_pairs& np);
    bool operator==(Name_pairs& np) const;
    bool operator!=(Name_pairs& np) const;
};

void Name_pairs::read_names()
{
    string temp{};
    std::cout << "Enter names (\'" << STOP_WORD << "\' to stop entering): ";
    while (1)
    {
        temp = get_user_string();
        if (temp == STOP_WORD)
            break;
        name.push_back(temp);
    }
}

void Name_pairs::read_ages()
{
    unsigned int current_name_iter{ age.size()-1 };
    int names_left{ static_cast<int>(name.size() - age.size()) };
    if (names_left == 0)
        throw std::runtime_error("read_ages: There is no initialized names");

    while (names_left--)
    {
        current_name_iter++;
        std::cout << "Enter age for \'" << name[current_name_iter] << "\': ";
        age.push_back(get_user_number<double>());
        if (names_left)
            std::cout << names_left << " name(s) left\n";
    }
}

//void Name_pairs::print() const
//{
//    if (name.size() == 0)
//        throw std::runtime_error("print: Vector of names is empty");
//
//    for (unsigned int i = 0; i < name.size(); i++)
//    {
//        std::cout << "(" << name[i] << ", ";
//        if (i < age.size())
//            std::cout << age[i];
//        else std::cout << "N/A";
//        std::cout << ")\n";
//    }
//}

int Name_pairs::find_name(const vector<string>& v_str, const string& str)
{
    for (unsigned int i = 0; i < v_str.size(); i++)
        if (str == v_str[i])
            return i;
    return -1;
}

void Name_pairs::sort()
{
    if (name.size() != age.size())
        throw std::runtime_error("sort: Vector of names' size doesn't match vector of age's one");

    std::vector<std::string> name_copy{ name };
    std::vector<double> age_copy{ age };
    std::sort(name.begin(), name.end());

    for (unsigned int i = 0; i < name.size(); i++)
        age[i] = name[i] == name_copy[i] ? age_copy[i] : age_copy[find_name(name_copy, name[i])];
}

std::ostream& operator<<(std::ostream& os, Name_pairs& np)
{
    if (np.name.size() == 0)
        throw std::runtime_error("print: Vector of names is empty");

    for (unsigned int i = 0; i < np.name.size(); i++)
    {
        std::cout << "(" << np.name[i] << ", ";
        if (i < np.age.size())
            std::cout << np.age[i];
        else std::cout << "N/A";
        std::cout << ")\n";
    }
}

bool Name_pairs::operator==(Name_pairs& np) const
{
    if (name.size() != np.name.size() && age.size() != np.age.size())
        return false;
    for (unsigned int i = 0; i < name.size(); i++)
        if (name[i] != np.name[i] || age[i] != np.age[i])
            return false;
    return true;
}

bool Name_pairs::operator!=(Name_pairs& np) const
{
    return !(*this == np);
}

//int main()
//{
//    try
//    {
//        Name_pairs np1{}, np2{};
//        np1.read_names();
//        np1.read_ages();
//        std::cout << np1;
//        np2.read_names();
//        np2.read_ages();
//        std::cout << np2;
//        std::cout << (np1 == np2) << '\n' << (np1 != np2);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 4 -----------------------------------------------

struct X
{
    void f(int x)
    {
        struct Y
        {
            int f()
            {
                return 1;
            }
            int m;
        };
        int m;
        m = x;
        Y m2;
        return f(m2.f());
    }
    int m;
    void g(int m)
    {
        if (m)
            f(m + 2);
        else
        {
            g(m + 2);
        }
    }
    X()
    {}
    void m3()
    {

    }
    void main()
    {
        X a;
        a.f(2);
    }
};

//Exercise 5 -----------------------------------------------

enum class Genre
{
    fantastic, prose, periodical,
    biography, for_children
};

class Library;

class Book
{
private:
    string isbn;
    string title;
    string author;
    Genre genre;
    Date copyright_date;
    bool is_given;
    bool check_isbn(const string&);
    //friend void set_giving(Book&);
public:
    Book(string, string, string, Genre, int, Month, int, bool);
    string get_isbn() const;
    string get_title() const;
    string get_author() const;
    Genre get_genre() const;
    Date get_copyright_date() const;
    bool isGiven() const;
    bool operator==(const Book&) const;
    bool operator!=(const Book&) const;
    friend std::ostream& operator<<(std::ostream&, const Book&);
};

bool Book::check_isbn(const string& isbn)
{
    int count_dash{ 3 };
    if (isbn[0] < '0' || isbn[0] > '9')
        return false;

    for (int i = 1; i < isbn.size(); i++)
    {
        if (count_dash)
            if (isbn[i] == '-' && (isbn[i - 1] != '-'))
                count_dash--;
            else if (isbn[i] >= '0' && isbn[i] <= '9')
                continue;
            else return false;
        else if ((isbn[i] < '0' || isbn[i] > '9') && (isbn[i] < 'a' || isbn[i] > 'z')
            || i != (isbn.size() - 1))
            return false;
    }
    return (count_dash == 0)? true : false;
}

//void Book::set_giving(bool is_giv)
//{
//    is_given = is_giv;
//}

Book::Book(string isbn_u, string title_u, string author_u, Genre gen,
    int year, Month month, int day, bool given) : isbn{isbn_u},
    title{ title_u }, author{ author_u }, genre{ gen }, 
    copyright_date{ Date(year, month, day) }, is_given{ given }
{
    if (!check_isbn(isbn_u))
        throw(std::runtime_error("Wrong ISBN"));
}

string Book::get_isbn() const
{
    return isbn;
}
string Book::get_title() const
{
    return title;
}
string Book::get_author() const
{
    return author;
}
Genre Book::get_genre() const
{
    return genre;
}
Date Book::get_copyright_date() const
{
    return copyright_date;
}
bool Book::isGiven() const
{
    return is_given;
}

bool Book::operator==(const Book& book) const
{
    return isbn == book.isbn;
}
bool Book::operator!= (const Book& book) const
{
    return isbn != book.isbn;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.isbn;
    return os;
}

//----------------

class Patron
{
private:
    string name;
    int card_number;
    double dues;
    bool check_dues(double d);
public:
    Patron(string, int, double);
    void set_dues();
    string get_name() const;
    int get_card_number() const;
    double get_dues() const;
    bool operator==(const Patron&) const;
    bool operator!=(const Patron&) const;
};

bool Patron::check_dues(double d)
{
    return (dues >= 0.0) ? true : false;
}

Patron::Patron(string name_u, int card_number_u, double dues_u)
    : name{ name_u }, card_number{ card_number_u }, dues{ dues_u }
{
    if (card_number_u < 1)
        throw std::runtime_error("Card number have to be 1 or more");
    if (!check_dues(dues_u))
        throw std::runtime_error("Dues cannot be less than 0");
}

void Patron::set_dues()
{
    std::cout << "\nEnter an amount of dues: ";
    while (1)
    {
        dues = get_user_number<double>();
        if (dues < 0)
            std::cout << "Dues cannot be less than 0. Again: ";
        else break;
    }
}

string Patron::get_name() const
{
    return name;
}
int Patron::get_card_number() const
{
    return card_number;
}
double Patron::get_dues() const
{
    return dues;
}

bool isPaid(const Patron& patron)
{
    return (patron.get_dues() > 0.0) ? true : false;
}

bool Patron::operator==(const Patron& patron) const
{
    return (card_number == patron.card_number) ? true : false;
}
bool Patron::operator!=(const Patron& patron) const
{
    return *this == patron;
}

//----------------

struct Transaction
{
    Book book;
    Patron patron;
    Date date;
};

class Library
{
private:
    vector<Book> v_book;
    vector<Patron> v_patron;
    vector<Transaction> v_transaction;
    //friend void set_giving(Book&);
public:
    void add_book(const Book);
    void add_patron(const Patron);
    void give_book(const Book&, const Patron&, const Date&);
    bool isGiven(const string&) const;
    vector<string> get_debtors() const;
};

//void set_giving(Book& book)
//{
//    book.is_given = true;
//}

void Library::add_book(const Book book)
{
    for (Book& temp : v_book)
        if (temp == book)
            throw std::runtime_error("This book is already exist");
    v_book.push_back(book);
    std::cout << "\nBook \"" << book.get_title() << "\"" << " successfully added";
}
void Library::add_patron(const Patron patron)
{
    for (Patron& temp : v_patron)
        if (temp == patron)
            throw std::runtime_error("This person is already exist");
    v_patron.push_back(patron);
    std::cout << "\nPerson \"" << patron.get_name() << "\"" << " successfully added";
}

void Library::give_book(const Book& book, const Patron& patron, const Date& date)
{
    bool book_flag{ false }, patron_flag{ false }, paid{ false };

    for (Book& temp : v_book)
        if (temp.get_isbn() == book.get_isbn())
        {
            book_flag = true;
            if (temp.isGiven())
                throw std::runtime_error("The book has been already given");
            else
                temp = Book(temp.get_isbn(), temp.get_title(), temp.get_author(), temp.get_genre(),
                    temp.get_copyright_date().year(), temp.get_copyright_date().month(), temp.get_copyright_date().day(), true);
        }

    for (Patron& temp : v_patron)
        if (temp.get_card_number() == patron.get_card_number())
        {
            patron_flag = true;
            paid = isPaid(temp);
        }

    if (!book_flag)
        throw std::runtime_error("There is no book with this isbn");
    if (!patron_flag)
        throw std::runtime_error("There is no person with this number");
    if (!paid)
        throw std::runtime_error("haven't paid dues");

    v_transaction.push_back(Transaction{ book, patron, date });
}

bool Library::isGiven(const string& isbn) const
{
    for (Book temp : v_book)
        if (isbn == temp.get_isbn())
            return temp.isGiven();
    throw std::runtime_error("There is no book with this isbn");
    return false;
}

vector<string> Library::get_debtors() const
{
    vector<string> debtors;
    for (Patron temp : v_patron)
        if (!isPaid(temp))
            debtors.push_back(temp.get_name());
    return debtors;
}

int main()
{
    try
    {
        Library lib;

        Book b1("22-7-315-g", "Leore", "Basph", Genre::for_children, 1998, Month::sep, 12, false);
        Book b2("12-1-2-a", "It", "King", Genre::fantastic, 1980, Month::feb, 28, false);

        Patron p1("Joe", 1234, 15);
        Patron p2("Bill", 800, 40);

        lib.add_book(b1);
        lib.add_book(b2);

        lib.add_patron(p1);
        lib.add_patron(p2);

        lib.give_book(b1, p1, Date(2020, Month::apr, 4));
        lib.give_book(b2, p2, Date(2020, Month::sep, 1));

        std::cout << '\n' << b1.isGiven() << '\n' << b2.isGiven();
        
        /*Patron patr("Joe", 1234, 5.2);
        std::cout << isPaid(patr) << '\n' << patr.get_dues();
        patr.set_dues();
        std::cout << isPaid(patr) << '\n' << patr.get_dues();*/
        /*Book b("22-7-315-g", "Leore", "Basph", Genre::for_children, 1998, Month::sep, 12, false);
        Book b2("12-1-2-a", "It", "King", Genre::fantastic, 1980, Month::feb, 28, false);
        std::cout << (b == b2) << '\n'; 
        std::cout << b2;*/
    }
    catch (std::exception& e)
    {
        std::cout << "\nException: " << e.what();
    }
}