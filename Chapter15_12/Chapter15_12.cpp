#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include <iterator>
#include <iomanip>

constexpr int MAX_FIELD = 7;

void get_file_name(std::string& fname_out)
{
    while (1)
    {
        std::cout << "Enter a text file's directory: ";
        while (1)
        {
            std::getline(std::cin, fname_out);
            if (std::cin.fail())
            {
                std::cout << "Something went wrong.\nAgain: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            break;
        }
        std::string f_format = fname_out.substr(fname_out.size() - 3, 3);
        for (int i = 0; i < f_format.size(); i++)
            f_format[i] = std::tolower(f_format[i]);
        if (f_format != "txt" && f_format != "rtf" && f_format != "doc" && f_format != "docx")
        {
            std::cout << "Wrong the file's format";
            continue;
        }
        break;
    }
}

void print_line(int width)
{
    for (int i = 0; i < (width + MAX_FIELD + 3); i++)
        std::cout << '-';
    std::cout << std::endl;
}

int main()
{
    std::map<std::string, int, std::less<std::string> > word_table;
    std::string file_name, temp = "";
    get_file_name(file_name);
    char ch;
    int max_width = 0;
    std::ifstream text_file(file_name, std::ios::_Nocreate);
    while (text_file)
    {
        text_file.get(ch);
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || 
               (ch >= '0' && ch <= '9') || ch == '-')
        {
            temp += std::tolower(ch);
            continue;
        }
        if (temp != "")
        {
            word_table[temp]++;
            if (temp.size() > max_width)
                max_width = temp.size();
            temp = "";
        }
    }
    std::map<std::string, int, std::less<std::string> >::iterator iter;
    iter = word_table.begin();
    print_line(max_width);
    std::cout.setf(std::ios::left);
    while (iter != word_table.end())
    {
        std::cout << "|" << std::setw(max_width) << (*iter).first << "|"
            << std::setw(MAX_FIELD) << (*iter).second << "|" << std::endl;
        print_line(max_width);
        iter++;
    }
    //std::istream_iterator<char> file_iter(text_file);
    //std::istream_iterator<char> end_of_file;

    //std::map<std::string, int, std::less<std::string> > word_table;
    //while (file_iter != end_of_file)
    //{
    //    /*if (*file_iter == " ")
    //        std::cout << 'Q';*/
    //    std::cout << *file_iter++;

    //}
    
}
