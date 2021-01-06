#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Wrong format! Expecting: \"...\Chapter12_2.exe\" way_to_source_file way_to_destination_file";
        exit(1);
    }

    std::ifstream infile(argv[1], std::ios::_Nocreate);
    if (!infile)
    {
        std::cerr << "Source_File opening error!";
        std::exit(1);
    }
    
    std::ofstream outfile(argv[2], std::ios::_Nocreate | std::ios::trunc);
    if (!outfile)
    {
        std::cerr << "Distination_File opening error!";
        std::exit(1);
    }

    outfile << infile.rdbuf();

    if (!outfile)
    {
        std::cerr << "Copying error";
        std::exit(1);
    }
    else
        std::cout << "Successfully!";
}
