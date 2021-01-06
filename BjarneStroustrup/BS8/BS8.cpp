#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Exercise 2 -----------------------------------------------

void print(const std::string& mark, const std::vector<int>& v)
{
    std::cout << mark << ": ";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}


//int main()
//{
//    std::string mark{ "Obj" };
//    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
//    print(mark, v);
//}

//Exercise 3 -----------------------------------------------

void fibonacci(int x, int y, std::vector<int>& v_out, int n)
{
    if (v_out.size() != 0)
        throw std::runtime_error("fibonacci: vector isn't empty");
    if (x > y || x < 0 || y <= 0)
        throw std::runtime_error("fibonacci: bad arguments x and y");
    if (n < 0)
        throw std::runtime_error("fibonacci: bad argument n");
    v_out.push_back(x);
    v_out.push_back(y);
    for (int i = 0; i < n; i++)
        v_out.push_back(v_out[i] + v_out[i + 1]);
}

//int main()
//{
//    try
//    {
//        int x{ 1 }, y{ 2 }, n{ 10 };
//        std::vector<int> v_fib;
//        fibonacci(x, y, v_fib, n);
//        print("Fibonacci", v_fib);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 4 -----------------------------------------------

//int main()
//{
//    try
//    {
//        int x{ 1 }, y{ 2 }, n{ 50 };
//        std::vector<int> v_fib;
//
//        fibonacci(x, y, v_fib, n);
//        for (int i = 0; i < v_fib.size(); i++)
//            if (v_fib[i] < 0)
//            {
//                std::cout << v_fib[i - 1] << " is close to the end max value of int";
//                break;
//            }
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 5 -----------------------------------------------

std::vector<int> reverse_const_vector(const std::vector<int>& v)
{
    std::vector<int> v_temp;
    for (int i = v.size() - 1; i >= 0; i--)
        v_temp.push_back(v[i]);
    return v_temp;
}

void reverse_vector(std::vector<int>& v_out)
{
    unsigned int v_size{ v_out.size() };
    for (int i = 0, j = v_size - 1; i < v_size / 2; i++, j--)
        std::swap(v_out[i], v_out[j]);
}

//int main()
//{
//    std::vector<int> v_test{1, 2, 3, 4, 5};
//    std::vector<int> v_curr{ reverse_const_vector(v_test) };
//    print("Reversed 1: ", v_curr);
//    reverse_vector(v_curr);
//    std::cout << '\n';
//    print("Reversed 2: ", v_curr);
//}

//Exercise 6 -----------------------------------------------

std::vector<std::string> reverse_const_vector(const std::vector<std::string>& v)
{
    std::vector<std::string> v_temp;
    for (int i = v.size() - 1; i >= 0; i--)
        v_temp.push_back(v[i]);
    return v_temp;
}

void reverse_vector(std::vector<std::string>& v_out)
{
    unsigned int v_size{ v_out.size() };
    for (int i = 0, j = v_size - 1; i < v_size / 2; i++, j--)
        std::swap(v_out[i], v_out[j]);
}

void print(const std::string& mark, const std::vector<std::string>& v)
{
    std::cout << mark << ": ";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}

//int main()
//{
//    std::vector<std::string> v_test{"one", "two", "three", "four", "five"};
//    std::vector<std::string> v_curr{ reverse_const_vector(v_test) };
//    print("Reversed 1: ", v_curr);
//    reverse_vector(v_curr);
//    std::cout << '\n';
//    print("Reversed 2: ", v_curr);
//}

//Exercise 7 -----------------------------------------------

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

int find_name(const std::vector<std::string>& v_str, const std::string& name)
{
    for (int i = 0; i < v_str.size(); i++)
        if (name == v_str[i])
            return i;
    return -1;
}

//int main()
//{
//    try
//    {
//        std::vector<std::string> name;
//        std::vector<int> age;
//        std::string temp{};
//
//        std::cout << "Enter names ('stop' to stop input):\n";
//        while (1)
//        {
//            temp = get_user_string();
//            if (temp == "stop")
//                break;
//            name.push_back(temp);
//        }
//
//        for (int i = 0; i < name.size(); i++)
//        {
//            std::cout << "Enter age for " << name[i] << ": ";
//            age.push_back(get_user_number<int>());
//        }
//
//        std::vector<std::string> name_copy{ name };
//        std::vector<int> age_copy{ age };
//        std::sort(name.begin(), name.end());
//
//        for (int i = 0; i < name.size(); i++)
//            age[i] = name[i] == name_copy[i] ? age_copy[i] : age_copy[find_name(name_copy, name[i])];
//
//        print("Names", name);
//        std::cout << '\n';
//        print("Age", age);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 8 -----------------------------------------------

double sum_double_vect(const std::vector<double> v1, const std::vector<double> v2)
{
    if (v1.size() != v2.size())
        throw std::runtime_error("sum_double_vect: vectors have different sizes");
    double sum{};
    for (int i = 0; i < v1.size(); i++)
    {
        sum += v1[i] * v2[i];
        if (sum < 0)
            throw std::runtime_error("sum_double_vect: the sum is less than 0");
    }
    return sum;
}

//int main()
//{
//    try
//    {
//        std::vector<double> price{ 1000, 5000, 1500 }, weight{ 3, 2, 1 };
//        std::cout << sum_double_vect(price, weight);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 9 -----------------------------------------------

double maxv(const std::vector<double> v)
{
    if (v.size() == 0)
        throw std::runtime_error("maxv: vector is empty");
    double max{v[0]};
    for (double d : v)
        if (d > max)
            max = d;
    return max;
}

//int main()
//{
//    std::vector<double> v{ 1, 5, 2, 5.4, 9.2, 8.2, 4.5 };
//    std::cout << maxv(v);
//}

//Exercise 10 -----------------------------------------------

struct gathered_result
{
    double min;
    double max;
    double avg;
    double mediana;
};

using std::vector;

double mediana(const vector<double>& v)
{
    vector<double> copy{ v };
    std::sort(copy.begin(), copy.end());
    return v.size() % 2 == 0 ? (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2 : v[v.size() / 2];
}

gathered_result solve_all(const vector<double>& v)
{
    gathered_result temp{};
    temp.max = maxv(v);
    temp.min = v[0];
    for (double d : v)
    {
        if (d < temp.min)
            temp.min = d;
        temp.avg += d;
    }
    temp.avg /= v.size(); 
    temp.mediana = mediana(v);
    return temp;
}

//int main()
//{
//    vector<double> v{ 1.0, 4.2, 5.8, 10, 6.7, 11.9, 7, 3.6, 5.4 };
//    gathered_result gr = solve_all(v);
//    std::cout << "Max value: " << gr.max << "\nMin value: " << gr.min
//        << "\nAverage value: " << gr.avg << "\nMediana: " << gr.mediana;
//}

//Exercise 11 -----------------------------------------------

void print_until_s(vector<std::string>& v, std::string& s)
{
    int count{};
    for (std::string str : v)
    {
        if (str == s)
            count++;
        if (count == 2)
            return;
        else std::cout << str << " ";
    }
}

//int main()
//{
//    std::string quit{ "quit" };
//    std::vector<std::string> strv{ "Monday", "Tuesday",
//                                  "Wednesday", "quit", "Thursday",
//                                  "Friday", "quit", "Saturday", "Sunday" };
//
//    print_until_s(strv, quit);
//}

//Exercise 12 -----------------------------------------------

using std::string;

struct gathered_result_str
{
    string shortest;
    string longest;
    string first;
    string last;
};

gathered_result_str solve_all_str(const vector<string>& v)
{
    if (v.size() == 0)
        throw std::runtime_error("solve_all_str: vector is empty");

    gathered_result_str temp{v[0], v[0], v[0], v[0]};
    for (string str : v)
    {
        if (str.length() < temp.shortest.length())
            temp.shortest = str;
        if (str.length() > temp.longest.length())
            temp.longest = str;
        if (str < temp.first)
            temp.first = str;
        if (str > temp.last)
            temp.last = str;
    }
    return temp;
}

vector<int> solve_length(const vector<string>& v)
{
    if (v.size() == 0)
        throw std::runtime_error("solve_length: vector is empty");

    vector<int> length;
    for (string str : v)
        length.push_back(str.length());
    return length;
}

//int main()
//{
//    vector<string> str{ "A", "a", "abc", "temp", "xi", "Xi", "longest", "pala" };
//    vector<int> length = solve_length(str);
//    gathered_result_str grs{ solve_all_str(str) };
//    
//    for (int i = 0; i < str.size(); i++)
//        std::cout << str[i] << " has " << length[i] << " char-s\n";
//    std::cout << "Shortest: " << grs.shortest << "\nLongest: " << grs.longest
//        << "\nFirst: " << grs.first << "\nLast: " << grs.last;
//}

//Exercise 13 -----------------------------------------------

void func(const int a)
{
    //a = 13; doesn't change const value
}

int main()
{

}