#include <iostream>
#include <vector>
#include <string>

//Exercise -1 ------------------------------------------------------------------------------------------------------------------------------------------

//struct X
//{
//    int val;
//
//    void out(const std::string& s, int nv)
//    {
//        std::cerr << this << "->" << s << ": " << val
//            << " (" << nv << ")\n";
//    }
//    X() { out("X()", 0); val = 0; }
//    X(int v) { val = v; out("X(int)", v); }
//    X(const X& x) { val = x.val; out("X(X&)", x.val); }
//    X& operator=(const X& a)
//    {
//        out("X::operator=", a.val);
//        val = a.val;
//        return *this;
//    }
//    ~X() { out("~X()", 0); }
//};
//
////X glob(2);
//
//X copy(X a) { return a; }
//
//X copy2(X a) { X aa = a; return aa; }
//
//X& ref_to(X& a) { return a; }
//
//X* make(int i) { X a(i); return new X(a); };
//
//struct XX { X a; X b; };

//int main()
//{
//    X loc(4);
//    X loc2(loc);
//    loc = X{ 5 };
//    loc2 = copy(loc);
//    loc2 = copy2(loc);
//    X loc3{ 6 };
//    X& r = ref_to(loc);
//    delete make(7);
//    delete make(8);
//    std::vector<X> v(4);
//    XX loc4;
//    X* p = new X{ 9 };
//    delete p;
//    X* pp = new X[5];
//    delete[] pp;
//}

//Exercise 0 ------------------------------------------------------------------------------------------------------------------------------------------

//ARRAYS----------------------------------------------------------

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int arr[], int n)
{
    int la[10];

    for (int i{}; i < 10; i++)
    {
        la[i] = ga[i];
        std::cout << la[i] << ' ';
    }
    std::cout << '\n';
    int* p = new int[n];
    for (int i{}; i < n; i++)
    {
        p[i] = ga[i];
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';
    delete[] p;
}

//END ARRAYS ----------------------------------------------------

//VECTORS -------------------------------------------------------

std::vector<int> gv{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(const std::vector<int>& v)
{
    std::vector<int> lv{};
    for (unsigned int i{}; i < v.size(); i++)
    {
        lv.push_back(gv[i]);
        std::cout << lv[i] << ' ';
    }
    std::cout << '\n';
    std::vector<int> lv2 = gv;
    for (auto& i : lv2)
        std::cout << i << ' ';
    std::cout << '\n';
}

//int main()
//{
//    f(ga, 10);
//
//    int aa[10];
//    for (int i{ 0 }; i < 10; i++)
//    {
//        if (i == 0)
//            aa[i] = i + 1;
//        else
//            aa[i] = aa[i - 1] * i;
//    }
//    f(aa, 10);
//    //-------------------------
//    f(gv);
//
//    std::vector<int> vv(10);
//    for (int i{}; i < vv.size(); i++)
//    {
//        if (i == 0)
//            vv[i] = i + 1;
//        else vv[i] = vv[i - 1] * i;
//    }
//    f(vv);
//}

//Exercise 1 ------------------------------------------------------------------------------------------------------------------------------------------

char* my_strdup(const char* s)
{
    int count{};
    for (; *(s + count) != '\0'; count++);
    char* str = new char[count + 1];
    for (int i{}; i <= count; i++)
        *(str + i) = *(s + i);
    return str;
}

//int main()
//{
//    char str[]{ "AMAZING!!!" };
//    char* ss{ my_strdup(str) };
//
//    for (int i{}; *(ss + i) != '\0'; i++)
//        std::cout << *(ss + i);
//    delete[] ss;
//}

//Exercise 2 ------------------------------------------------------------------------------------------------------------------------------

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
//    const char* str{ findx("parallel", "e") };
//    if (!str)
//        std::cout << "NULL";
//    else
//        std::cout << str;
//}

//Exercise 3 ------------------------------------------------------------------------------------------------------------------------------

int my_strcmp(const char* s1, const char* s2)
{
    for (unsigned int i{}; ; i++)
    {
        if (*(s1 + i) < *(s2 + i))
            return -1;
        else if (*(s1 + i) > * (s2 + i))
            return 1;
        else if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
            return 0;
    }
    return 0;
}

//int main()
//{
//    std::cout << my_strcmp("qwe", "qwe");
//}

//Exercise 4 ------------------------------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    int stack_int{ 100 };
//    int* dynamic_int = new int{ 100 };
//    char* stack_ch = reinterpret_cast<char*>(stack_int);
//    char* dynamic_ch = reinterpret_cast<char*>(*dynamic_int);
//
//    std::cout << my_strdup(stack_ch);
//    //std::cout << my_strdup(dynamic_ch);
//
//    //std::cout << findx(stack_ch, dynamic_ch);
//    //std::cout << findx(dynamic_ch, stack_ch);
//
//    //std::cout << my_strcmp(dynamic_ch, stack_ch);
//
//}

//Exercise 5 ------------------------------------------------------------------------------------------------------------------------------------------

std::string cat_dot(const std::string& s1, const std::string& s2)
{
    return (s1 + "." + s2);
}

//int main()
//{
//    std::cout << cat_dot("Nils", "Bor");
//}

//Exercise 6 ------------------------------------------------------------------------------------------------------------------------------------------

std::string cat_dot(const std::string& s1, const std::string& div, const std::string& s2)
{
    return (s1 + div + s2);
}

//int main()
//{
//    std::cout << cat_dot("Nils", "-", "Bor");
//}

//Exercise 7 ------------------------------------------------------------------------------------------------------------------------------------------

int count_length(const char* s)
{
    int count{};
    while (*(s + count)) ++count;
    return count;
}

char* cat_dot(const char* s1, const char* s2)
{
    int s1_len{ count_length(s1) }, s2_len{ count_length(s2) };
    int len = s1_len + s2_len + 2;
    char* str = new char[len];
    for (int i{}; i < len; i++)
    {
        if (i < s1_len)
            *(str + i) = *(s1 + i);
        else if (i == s1_len)
            *(str + i) = '.';
        else *(str + i) = *(s2 + i - (s1_len + 1));
    }
    return str;
}

char* cat_dot(const char* s1, const char* div, const char* s2)
{
    int s1_len{ count_length(s1) }, s2_len{ count_length(s2) }, div_len{ count_length(div) };
    int len = s1_len + s2_len + div_len + 1;
    char* str = new char[len];
    for (int i{}; i < len; i++)
    {
        if (i < s1_len)
            *(str + i) = *(s1 + i);
        else if (i >= s1_len && i < (s1_len + div_len))
            *(str + i) = *(div + i - s1_len);
        else *(str + i) = *(s2 + i - (s1_len + div_len));
    }
    return str;
}

//int main()
//{
//    char* str{ cat_dot("NilsQ", "Bor123") };
//    std::cout << str;
//    delete[] str;
//
//    std::cout << '\n';
//
//    str = cat_dot("Nils", "---", "Bor");
//    std::cout << str;
//    delete[] str;
//}

//Exercise 8 ------------------------------------------------------------------------------------------------------------------------------------------

bool is_palindrome(const std::string& s)
{
    std::string rev{};
    for(size_t i{ s.size() - 1 }; i < s.size(); i--)
        rev += s[i];
    return rev == s;
}

bool is_palindrome(const char s[], int n)
{
    std::string str{};
    for (int i{}, j{ n }; i < n; i++, j--)
        str += *(s + (j - 1));
    for (int i{}; i < n; i++)
        if(str[i] != *(s + i))
            return false;
    return true;
}

bool is_palindrome(const char* s1, const char* s2)
{
    int n{};
    while (*(s1 + n)) ++n;
    std::string str{};

    while (s2 != (s1 - 1))
        str += *(s2--);

    for (int i{}; i < n; i++)
        if (str[i] != *(s1 + i))
            return false;

    return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max)
{
    is.width(max);
    is >> buffer;
    return is;
}

//int main()
//{
    ////string
    //for (std::string s{}; getline(std::cin, s); )
    //{
    //    std::cout << s << " is";
    //    if (!is_palindrome(s)) std::cout << " not";
    //    std::cout << " a palindrome\n";
    //}

    ////array
    //constexpr int max{ 128 };
    //for (char s[max]; read_word(std::cin, s, max);)
    //{
    //    std::cout << s << " is";
    //    if (!is_palindrome(s, strlen(s))) std::cout << " not";
    //    std::cout << " a palindrome\n";
    //}

    ////pointer
    //constexpr int max{ 128 };
    //for (char s[max]; read_word(std::cin, s, max);)
    //{
    //    std::cout << s << " is";
    //    if (!is_palindrome(&s[0], &s[strlen(s) - 1])) std::cout << " not";
    //    std::cout << " a palindrome\n";
    //}
//}

//Exercise 9 ------------------------------------------------------------------------------------------------------------------------------------------

//int main()
//{
//    static int stat_arr[]{ 1, 2, 3, 4, 5 };
//    std::cout << "Static memory: ";
//    for (int i{}; i < 5; i++)
//        std::cout << (stat_arr + i) << ' '; // ascending
//    std::cout << '\n';
//
//    int loc_arr[]{ 1, 2, 3, 4, 5 };
//    std::cout << "Stack(local) memory: ";
//    for (int i{}; i < 5; i++)
//        std::cout << (loc_arr + i) << ' '; // ascending
//    std::cout << '\n';
//
//    int* dyn_arr = new int[] {1, 2, 3, 4, 5};
//    std::cout << "Dynamic memory: ";
//    for (int i{}; i < 5; i++)
//        std::cout << (dyn_arr + i) << ' '; // ascending
//    std::cout << '\n';
//}

//Exercise 10 ------------------------------------------------------------------------------------------------------------------------------------------


