#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct Point
{
    int x;
    int y;
    /*friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, Point&);*/
};

std::istream& operator>>(std::istream& is, Point& p)
{
    is.exceptions(is.exceptions() | std::ios::badbit);
    is >> p.x >> p.y;
    if (!is)
        throw std::runtime_error("Point: input error");
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p)
{
    return os << p.x << ' ' << p.y << '\n';
}

using std::vector;
using std::string;

//int main()
//{
//    try
//    {
//        vector<Point> original_points;
//        Point user_point;
//        std::cout << "Enter 7 points:\n";
//        for (int i = 0; i < 7; i++)
//        {
//            std::cout << "#" << i + 1 <<": ";
//            std::cin >> user_point;
//            original_points.push_back(user_point);
//        }
//
//        for (auto& p : original_points)
//            std::cout << "(" << p.x << " " << p.y << ")\n";
//
//        std::ofstream out_file{ "my_data.txt" };
//        for (auto& p : original_points)
//            out_file << p;
//        out_file.close();
//
//        vector<Point> processed_points;
//        std::ifstream in_file{ "my_data.txt" };
//        while (in_file >> user_point.x >> user_point.y)
//            processed_points.push_back(user_point);
//
//        for (auto& p : processed_points)
//            std::cout << "(" << p.x << " " << p.y << ")\n";
//
//        if (original_points.size() != processed_points.size())
//           throw std::runtime_error("Different size");
//        for (int i = 0; i < original_points.size(); i++)
//            if (original_points[i].x != processed_points[i].x
//                || original_points[i].y != processed_points[i].y)
//               throw std::runtime_error("Different points");
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what();
//    }
//}

//Exercise 1 ------------------------------------------------------------------------------------------

//int main()
//{
//    int sum{}, temp{};
//    std::ifstream in_file{ "my_data.txt" };
//    while (in_file >> temp)
//        sum += temp;
//    if (in_file.eof())
//        std::cout << sum;
//    else std::cout << "Error";
//}

//Exercise 2,3 ------------------------------------------------------------------------------------------

//struct Reading
//{
//    int hour;
//    double temperature;
//};
//
//std::istream& operator>>(std::istream& is, Reading& r)
//{
//    is.exceptions(is.exceptions() | std::ios::badbit);
//    int hour{};
//    double temperature{};
//    is >> hour >> temperature;
//    if (!is) return is;
//    if (hour < 0 || 23 < hour)
//        throw std::runtime_error("Wrong hour");
//    r = Reading{ hour, temperature };
//    return is;
//}
//
//void end_of_input(std::istream& is, char term, const string& message)
//{
//    if (is.fail())
//    {
//        is.clear();
//        char ch;
//        if (is >> ch && ch == term) return;
//        throw std::runtime_error(message);
//    }
//}
//
//void writing_into_file(const string& f_name, char term)
//{
//    std::ofstream file{ f_name };
//    if (!file)
//        throw std::runtime_error("Cannot open the file for writing");
//
//    std::cout << "Enter an hour and temperature (\'" << term
//        << "\' to stop):\n";
//    for (Reading r; std::cin >> r;)
//        file << r.hour << ' ' << r.temperature << '\n';
//
//    if (!file)
//        throw std::runtime_error("Writing error");
//
//    end_of_input(std::cin, term, "Wrong termination of input");
//}
//
//void reading_from_file(const string& f_name, vector<Reading>& v)
//{
//    std::ifstream file{ f_name };
//    if (!file)
//        throw std::runtime_error("Cannot open the file for reading");
//
//    for (Reading r; file >> r;)
//        v.push_back(r);
//
//    if (file.eof()) return;
//    if (file.fail())
//        throw std::runtime_error("Reading error");
//}
//
//double avg_temperature(vector<Reading>& r)
//{
//    double sum{};
//    for (Reading& rd : r)
//        sum += rd.temperature;
//    return sum / r.size();
//}
//
//int main()
//{
//    try
//    {
//        writing_into_file("raw_temps.txt", '|');
//        vector<Reading> v_read;
//        reading_from_file("raw_temps.txt", v_read);
//        std::cout << "Average temperature: " << avg_temperature(v_read);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception! " << e.what();
//    }
//}

constexpr double MIN_TEMP_F{-459};
constexpr double MAX_TEMP_F{392};
constexpr double MIN_TEMP_C{-273};
constexpr double MAX_TEMP_C{200};

struct Reading
{
    int hour;
    char scale;
    double temperature;
};

//inline double c_to_f(double t)
//{
//    return (9 / 5 * t + 32);
//}
//
//Reading Reading_check(int hour, char scale, double temp)
//{
//    if (hour < 0 || 23 < hour)
//        throw std::runtime_error("Wrong hour");
//    if (scale != 'c' && scale != 'f')
//        throw std::runtime_error("Wrong temperature scale");
//    switch (scale)
//    {
//    case 'c': 
//        if (temp < MIN_TEMP_C || temp > MAX_TEMP_C)
//            throw std::runtime_error("Wrong temperature C");
//        break;
//    case 'f': 
//        if (temp < MIN_TEMP_F || temp > MAX_TEMP_F)
//            throw std::runtime_error("Wrong temperature F");
//        break;
//    }
//    return Reading{ hour, scale, temp };
//}
//
//std::istream& operator>>(std::istream& is, Reading& r)
//{
//    is.exceptions(is.exceptions() | std::ios::badbit);
//    int hour{};
//    double temperature{};
//    char scale{};
//    is >> hour >> scale >> temperature;
//    if (!is) return is;
//    r = Reading_check(hour, scale, temperature);
//    return is;
//}
//
//void end_of_input(std::istream& is, char term, const string& message)
//{
//    if (is.fail())
//    {
//        is.clear();
//        char ch;
//        if (is >> ch && ch == term) return;
//        throw std::runtime_error(message);
//    }
//}
//
//void writing_into_file(const string& f_name, char term)
//{
//    std::ofstream file{ f_name };
//    if (!file)
//        throw std::runtime_error("Cannot open the file for writing");
//
//    std::cout << "Enter an hour and temperature (\'" << term
//        << "\' to stop):\n";
//    for (Reading r; std::cin >> r;)
//        file << r.hour << ' ' << r.scale << r.temperature << '\n';
//
//    if (!file)
//        throw std::runtime_error("Writing error");
//
//    end_of_input(std::cin, term, "Wrong termination of input");
//}
//
//void reading_from_file(const string& f_name, vector<Reading>& v)
//{
//    std::ifstream file{ f_name };
//    if (!file)
//        throw std::runtime_error("Cannot open the file for reading");
//
//    for (Reading r; file >> r;)
//    {
//        if (r.scale == 'c')
//        {
//            r.scale = 'f';
//            r.temperature = c_to_f(r.temperature);
//        }
//        v.push_back(r);
//    }
//
//    if (file.eof()) return;
//    if (file.fail())
//        throw std::runtime_error("Reading error");
//}
//
//double avg_temperature(vector<Reading>& r)
//{
//    double sum{};
//    for (Reading& rd : r)
//        sum += rd.temperature;
//    return sum / r.size();
//}
//
//int main()
//{
//    try
//    {
//        writing_into_file("raw_temps_with_scale.txt", '|');
//        vector<Reading> v_read;
//        reading_from_file("raw_temps_with_scale.txt", v_read);
//        std::cout << "Average temperature: " << avg_temperature(v_read);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception! " << e.what();
//    }
//}

// Exercise 8 ---------------------------------------------------------------------------

std::string get_user_string()
{
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

//void write_file(std::ofstream& out_file)
//{
//    std::cout << "Enter file's name: ";
//    std::ifstream file{ get_user_string() };
//    if (!file)
//        throw std::runtime_error("Cannot open or find the file");
//
//    for (char ch; file.get(ch);)
//        out_file << ch;
//
//    if (file.eof())
//    {
//        std::cout << "Successfully completed\n";
//        return;
//    }
//    if (!file || !out_file)
//        throw std::runtime_error("Error");
//}
//
//int main()
//{
//    try
//    {
//
//        std::ofstream out_file{ "concat_file.txt" };
//        if (!out_file)
//            throw std::runtime_error("Cannot create the out file");
//
//        write_file(out_file);
//        write_file(out_file);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception! " << e.what();
//    }
//}

// Exercise 9 ---------------------------------------------------------------------------

//void write_file(std::ofstream& out_file)
//{
//    std::cout << "Enter the first file's name: ";
//    std::ifstream file_1{ get_user_string() };
//    if (!file_1)
//        throw std::runtime_error("Cannot open or find the file");
//
//    std::cout << "Enter the second file's name: ";
//    std::ifstream file_2{get_user_string()};
//    if (!file_2)
//        throw std::runtime_error("Cannot open or find the file");
//
//    while (true)
//    {
//        for (char ch; file_1.get(ch) && ch != ' ';)
//            out_file << ch;
//        out_file << ' ';
//
//        for (char ch; file_2.get(ch) && ch != ' ';)
//            out_file << ch;
//        out_file << ' ';
//
//        if (file_1.eof() && file_2.eof())
//        {
//            std::cout << "Successfully completed\n";
//            return;
//        }
//        if (!file_1 || !file_2 || !out_file)
//            throw std::runtime_error("Error");
//    }
//}
//
//int main()
//{
//    try
//    {
//        std::ofstream out_file{ "concat_file.txt" };
//        if (!out_file)
//            throw std::runtime_error("Cannot create the out file");
//        write_file(out_file);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception! " << e.what();
//    }
//}

// Exercise 10 ---------------------------------------------------------------------------

int sum_numbers(const string& f_name)
{
    int sum{}, temp{};
    std::ifstream file{ f_name };
    if (!file)
        throw std::runtime_error("Cannot open or find the file");
    file.exceptions(file.exceptions() | std::ios_base::badbit);

    while (true)
    {
        if (file >> temp)
            sum += temp;
        else
        {
            if (file.eof())
                return sum;
            if (file.fail())
            {
                file.clear();
                for (char ch; file >> ch;)
                    if (isdigit(ch))
                    {
                        file.unget();
                        break;
                    }
            }
        }
    }
}

int main()
{
    try
    {
        std::cout << "The sum is " << sum_numbers("mixed.txt");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception! " << e.what();
    }
}