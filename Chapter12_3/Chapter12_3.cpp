#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong format! Expecting: \"...\program.exe\" way_to_file";
        exit(1);
    }

    std::ifstream infile(argv[1], std::ios::_Nocreate);
    if (!infile)
    {
        std::cerr << "File opening error!";
        std::exit(1);
    }

    infile.seekg(0, std::ios::end);
    std::cout << "Size of " << argv[1] << " is " << infile.tellg() << " bytes";
}
