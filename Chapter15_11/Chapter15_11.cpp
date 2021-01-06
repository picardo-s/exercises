#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>
#include <list>

constexpr int MAX = 10;

void get_file_name(std::string& out_str)
{
    while (1)
    {
        std::cin >> out_str;
        if (std::cin.fail())
        {
            std::cout << "Something went wrong.\nAgain: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    std::cin.ignore(1000, '\n');
}

//std::fstream get_stream_file(const std::string& f_name, const char* choise)
//{
//    if (choise == "in")
//    {
//        std::fstream file(f_name, std::ios::_Nocreate | std::ios::in);
//        if (!file)
//            throw std::runtime_error("Cannot open the source file");
//        return file;
//    }
//    else if (choise == "out")
//    {
//        std::fstream file(f_name, std::ios::trunc | std::ios::out);
//        if(!file)
//            throw std::runtime_error("Cannot open/create the destination file");
//        return file;
//    }
//    else
//        throw std::runtime_error("Wrong choise. \'in\' or \'out\' are expected");
//}

int main()
{
    int array[MAX];
    for (int i = 0; i < MAX; i++)
        array[i] = i + 10;

    std::ofstream file("S:/perfect_circle/Chapter15_11/nums.dat", std::ios::trunc);
    std::ostream_iterator<int> ositer(file, " ");
    std::copy(array, array + MAX, ositer);
    file.close();

    std::string src_file_name, dest_file_name;

    std::cout << "\nEnter an source file's directory: ";
    get_file_name(src_file_name);
    std::ifstream source_file(src_file_name, std::ios::_Nocreate);

    std::cout << "Enter a destination file's directory: ";
    get_file_name(dest_file_name);
    std::ofstream dest_file(dest_file_name, std::ios::trunc);

    /*std::fstream source_file, dest_file;
    while (1)
    {
        try
        {
            std::cout << "\nEnter an source file's directory: ";
            get_file_name(src_file_name);
            source_file = get_stream_file(src_file_name, "in");

            std::cout << "Enter a destination file's directory: ";
            get_file_name(dest_file_name);
            dest_file = get_stream_file(dest_file_name, "out");

            break;
        }
        catch (std::exception e)
        {
            std::cout << "Exception: " << e.what();
            continue;
        }    
    }*/

    std::istream_iterator<int> src_file_iter(source_file);
    std::istream_iterator<int> end_of_istr;

    std::ostream_iterator<int> out_iter(dest_file, " ");

    std::copy(src_file_iter, end_of_istr, out_iter);
    //or 
    /*while (src_file_iter != end_of_istr)
        *out_iter++ = *src_file_iter++;*/

    source_file.close();
    dest_file.close();
    std::cout << "--Succsessfully completed--";
}
