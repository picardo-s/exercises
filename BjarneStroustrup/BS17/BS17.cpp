#include <iostream>
#include <vector>

//Exercise 0 ----------------------------------------------------------------------------------------------------------------------

constexpr int LEN = 20;

void print_array(std::ostream& os, int* arr, int n)
{
    for (int i{ 0 }; i < n; i++)
        os << *(arr + i) << " ";
    std::cout << std::endl;
}

//int main()
//{
//    int* p1 = new int[10];
//    for (int i{}, j{ 1 }; i < 10; i++, j *= 2)
//        p1[i] = j;
//    
//    int* p2 = new int[10];
//    for (int i{}; i < 10; i++)
//        p2[i] = p1[i];
//
//    print_array(std::cout, p1, 10);
//    print_array(std::cout, p2, 10);
//
//    std::cout << sizeof(int) << " " << sizeof(double) << " " << sizeof(bool);
//
//    delete[] p1;
//    delete[] p2;
//}

//Exercise 3 ----------------------------------------------------------------------------------------------------------------------

void to_lower(char* s)
{
    for (int i{ }; *(s + i) != '\0'; i++)
        *(s + i) = tolower(*(s + i));
}

//int main()
//{
//    char str[]{ "Hello, World! QWEFF SDFNO W" };
//    to_lower(str);
//    std::cout << str;
//}

//Exercise 4 ----------------------------------------------------------------------------------------------------------------------

char* strdupp(const char* s)
{
    if (s == nullptr)
    {
        char* temp = nullptr;
        return temp;
    }
    int length{};
    for (int i{}; *(s + i) != '\0'; i++)
        length++;

    char* temp = new char[length + 1];

    for (int i{}; i <= length; i++)
        *(temp + i) = *(s + i);
    return temp;
}

//int main()
//{
//    char str[]{ "Hello, World!" };
//    char* new_str = strdupp(str);
//    std::cout << new_str << " " << strlen(new_str);
//}

//Exercise 5 ----------------------------------------------------------------------------------------------------------------------

//char* findx(const char* s, const char* x)
//{
//    const char* temp{ nullptr };
//    if (!s || !x)
//        return const_cast<char*>(temp);
//    for (int i{}, j{}; *(s + i) != '\0'; i++, j = 0)
//    {
//        if (*(s + i) == *x)
//        {
//            for (; *(s + i + j) == *(x + j); j++);
//            if (*(x + j) == '\0')
//            {
//                temp = (s + i);
//                return const_cast<char*>(temp);
//            }
//        }
//    }
//    return const_cast<char*>(temp);
//}

const char* findx(const char* s, const char* x)
{
    const char* temp{ nullptr };
    if (!s || !x)
        return temp;
    for (int i{}, j{}; *(s + i) != '\0'; i++, j = 0)
    {
        if (*(s + i) == *x)
        {
            for (; *(s + i + j) == *(x + j); j++);
            if (*(x + j) == '\0')
            {
                temp = (s + i);
                return temp;
            }
        }
    }
    return temp;
}

//int main()
//{
//    const char str1[]{ "Hello, World!" };
//    const char str2[]{ "ello" };
//    char* new_str = findx(str1, str2);
//    *new_str = 'X';
//    std::cout << str1 << '\n';
//    if (new_str)
//        std::cout << *new_str << *(new_str + 1); //<< " " << strlen(new_str);
//    else std::cout << "Null";
//}

//Exercise 6 ----------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    int i{};
//    while (true)
//    {
//        double* d = new double[1000];
//        std::cout << ++i << "    ";
//    } // almost 2GB!!!!
//}

//Exercise 7 ----------------------------------------------------------------------------------------------------------------------

void copy_str(char* dest, char* source, int n)
{
    int i{};
    for (; i < n; i++)
        dest[i] = source[i];
}

//int main()
//{
//    char* arr = new char[] {'\0'};
//    char* str = nullptr;
//
//    int i{1};
//    for (char ch{}; std::cin >> ch && ch != '!'; i++)
//    {
//        str = new char[i];
//        copy_str(str, arr, i);
//        delete[] arr;
//        arr = new char[i + 1];
//        copy_str(arr, str, i);
//        *(arr + i) = ch;
//        delete[] str;
//    }
//    //for (char ch{}; std::cin.get(ch) && ch != '!'; i++)
//    //    *(arr + i) = ch;
//
//    for (int j{}; j < i; j++)
//        std::cout << *(arr + j);
//}

//Exercise 8 ----------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    std::string str{};
//
//    for (char ch{}; std::cin >> ch && ch != '!';)
//        str += ch;
//    std::cout << str;
//}

//Exercise 9 ----------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    std::vector<int*> v_pi;
//    
//    for (int i{}; i < 15; i++)
//    {
//        int* pi = new int{ i };
//        v_pi.push_back(pi);
//    }
//    for (auto i : v_pi)
//        std::cout << i << ' ';
//    //up?
//}

//Exercise 10 ----------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    char* arr = new char[3];
//    int i{};
//    for (char ch; std::cin >> ch; i++)
//        *(arr + i) = ch;
//}

//Exercise 10, 11, 12 ----------------------------------------------------------------------------------------------------------------------

class Link
{
private:
    Link* prev;
    Link* succ;
public:
    std::string value;
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{ v }, prev{ p }, succ{ s } {}
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    const Link* find(const std::string& s) const;
    const Link* advance(int n) const;
    Link* next() const { return succ; };
    Link* previous() const { return prev; };
};

Link* Link::insert(Link* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->prev = this;
    if (succ)
    {
        n->succ = succ;
        n->succ->prev = n;
    }
    succ = n;
    return this;
}

Link* Link::erase()
{
    if (this == nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ =succ;
    return succ;
}

Link* Link::find(const std::string& s)
{
    std::cout << '\n' << "usual" << '\n';
    Link* temp = this;
    while (temp)
    {
        if (temp->value == s) return temp;
        temp = temp->succ;
    }
    return nullptr;
}

const Link* Link::find(const std::string& s) const
{
    std::cout << '\n' << "const" << '\n';
    return const_cast<Link*>(this)->find(s);
}

const Link* Link::advance(int n) const
{
    if (this == nullptr) return nullptr;
    const Link* temp = this;
    if(0 < n)
        while(n--)
        {
            if (temp->succ == nullptr) return nullptr;
            temp = temp->succ;
        }
    else if(n < 0)
        while (n++)
        {
            if (temp->prev == nullptr) return nullptr;
            temp = temp->prev;
        }
    return temp;
}

void print_all(Link* p)
{
    std::cout << "{ ";
    while (p)
    {
        std::cout << p->value;
        if (p = p->next()) std::cout << ", ";
    }
    std::cout << " }";
}

//int main()
//{
//    Link* norse_gods = new Link{ "Thor" };
//    norse_gods = norse_gods->insert(new Link{ "Odin" });
//    norse_gods = norse_gods->insert(new Link{ "Zeus" });
//    norse_gods = norse_gods->insert(new Link{ "Freia" });
//
//    Link* greek_gods = new Link{ "Hera" };
//    greek_gods = greek_gods->insert(new Link{ "Athena" });
//    greek_gods = greek_gods->insert(new Link{ "Mars" });
//    greek_gods = greek_gods->insert(new Link{ "Poseidon" });
//
//    Link* p = greek_gods->find("Mars");
//    if (p) p->value = "Ares";
//
//    greek_gods = greek_gods->add(new Link{ "Neptun" });
//    greek_gods = greek_gods->add(new Link{ "Germes" });
//
//    Link* d = greek_gods->next();
//    d->add(new Link{ "Dionis" });
//
//    //std::cout << '\n';
//    //std::cout << norse_gods->value;
//    //const Link* z = norse_gods->advance(3);
//    //if(z)
//    //    std::cout << '\n' << z->advance(-1)->value;
//    //std::cout << '\n';
//
//    const Link* belarus_gods = new Link{ "Perun" };
//    const Link* s = belarus_gods->find("Perun");
//    std::cout << s->value;
//
//    print_all(norse_gods);
//    std::cout << '\n';
//
//    print_all(greek_gods);
//}

//Exercise 13 ----------------------------------------------------------------------------------------------------------------------

struct God
{
    std::string name;
    std::string myphology;
    std::string vehicle;
    std::string weapon;

    bool operator==(const God& g);
    bool operator!=(const God& g);
    bool operator>(const God& g);
    bool operator<(const God& g);
};

bool God::operator==(const God& g)
{
    if (name == g.name && myphology == g.myphology
        && vehicle == g.vehicle && weapon == g.weapon)
        return true;
    else return false;
}

bool God::operator!=(const God& g)
{
    return !(*this == g);
}

bool God::operator>(const God& g)
{
    return (name > g.name) ? true : false;
}

bool God::operator < (const God& g)
{
    return !(*this > g);
}

std::ostream& operator<<(std::ostream& s, const God& g)
{
    s << "Name: " << g.name
        << "\nMyphology: " << g.myphology
        << "\nVehicle: " << g.vehicle
        << "\nWeapon: " << g.weapon << std::endl << std::endl;
    return s;
}

class LinkGod
{
private:
    LinkGod* prev;
    LinkGod* succ;
public:
    God god;
    LinkGod(const God& g, LinkGod* p = nullptr, LinkGod* s = nullptr)
        : god{ g }, prev{ p }, succ{ s } {}
    LinkGod* insert(LinkGod*);
    LinkGod* add(LinkGod*);
    LinkGod* add_ordered(LinkGod*);
    LinkGod* erase();
    LinkGod* find(const God&);
    const LinkGod* find(const God&) const;
    const LinkGod* advance(int) const;
    LinkGod* next() const { return succ; };
    LinkGod* previous() const { return prev; };
};

LinkGod* LinkGod::insert(LinkGod* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;

    while (n->prev)
        n = n->prev;
    return n;
}

LinkGod* LinkGod::add(LinkGod* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->prev = this;
    if (succ)
    {
        n->succ = succ;
        n->succ->prev = n;
    }
    succ = n;

    while(n->prev)
        n = n->prev;
    return n;
}

LinkGod* LinkGod::add_ordered(LinkGod* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    LinkGod* temp = this;
    while (temp)
    {
        if (temp->god < n->god)
            if (temp->succ)
            {
                temp = temp->succ;
                continue;
            }
            else return temp->add(n);
        else return insert(n);
    }
    return nullptr;
}

LinkGod* LinkGod::erase()
{
    if (this == nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

LinkGod* LinkGod::find(const God& g)
{
    LinkGod* temp = this;
    while (temp)
    {
        if (temp->god == g) return temp;
        temp = temp->succ;
    }
    return nullptr;
}

const LinkGod* LinkGod::find(const God& g) const
{
    return const_cast<LinkGod*>(this)->find(g);
}

const LinkGod* LinkGod::advance(int n) const
{
    if (this == nullptr) return nullptr;
    const LinkGod* temp = this;
    if (0 < n)
        while (n--)
        {
            if (temp->succ == nullptr) return nullptr;
            temp = temp->succ;
        }
    else if (n < 0)
        while (n++)
        {
            if (temp->prev == nullptr) return nullptr;
            temp = temp->prev;
        }
    return temp;
}

void print_all(LinkGod* g)
{
    while (g)
    {
        std::cout << g->god;
        g = g->next();
    }
}

int main()
{

    LinkGod* gods = new LinkGod{ {"Odin", "North", "Volvo", "Spear"} };
    gods = gods->insert(new LinkGod{ {"Loki", "North", "Jeep", "Jokes"} });
    gods = gods->insert(new LinkGod{ {"Zeus", "Greek", "Tachanka", "Lightnings"} });
    gods = gods->insert(new LinkGod{ {"Freia", "North", "Fiat", "Sword"} });
    gods = gods->insert(new LinkGod{ {"Anubis", "Egypt", "Lincoln", "Death"} });
    gods = gods->insert(new LinkGod{ {"Ra", "Egypt", "Daewoo", "Sun"} });
    gods = gods->insert(new LinkGod{ {"Gefest", "Greek", "BMW", "Fire"} });
    gods = gods->insert(new LinkGod{ {"Poseidon", "Greek", "Shell", "Water"} });
    gods = gods->insert(new LinkGod{ {"Min", "Egypt", "Tiger", "Dedicating"} });

    LinkGod* greek_gods{}, * north_gods{}, * egypt_gods{};

    while (gods)
    {
        if (gods->god.myphology == "North")
        {
            if (!north_gods)
                north_gods = new LinkGod{ gods->god };
            else north_gods = north_gods->add_ordered(new LinkGod(gods->god));
        }
        else if (gods->god.myphology == "Greek")
        {
            if (!greek_gods)
                greek_gods = new LinkGod{ gods->god };
            else greek_gods = greek_gods->add_ordered(new LinkGod(gods->god));
        }
        else
        {
            if (!egypt_gods)
                egypt_gods = new LinkGod{ gods->god };
            else egypt_gods = egypt_gods->add_ordered(new LinkGod(gods->god));
        }
        gods = gods->next();
    }

    std::cout << "NORTH:\n";
    print_all(north_gods);

    std::cout << "GREEK:\n";
    print_all(greek_gods);

    std::cout << "EGYPT:\n";
    print_all(egypt_gods);
}

