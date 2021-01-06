#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::string firstName;
    std::string lastName;
    std::string middleInit;
    unsigned long id;
    std::ofstream outFile("S:/perfect_circle/Chapter12_4/namedata.txt", std::ios::trunc);
    char manip;

    do
    {
        std::cout  << "\nEnter name: ";
        std::cin >> firstName;
        std::cout << "Enter middle initial: ";
        std::cin >> middleInit;
        std::cout << "Enter surname: ";
        std::cin >> lastName;
        std::cout << "Enter ID: ";
        std::cin >> id;
        outFile << firstName << " " << middleInit << " " << lastName << " " << id;

        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
    } while (manip == 'y');

    outFile.close();

    std::ifstream inFile("S:/perfect_circle/Chapter12_4/namedata.txt");
    while (!inFile.eof())
    {
        inFile >> firstName >> middleInit >> lastName >> id;
        std::cout << "\nName: " << firstName << std::endl
            << "Middle initial: " << middleInit << std::endl
            << "Surname: " << lastName << std::endl
            << "ID: " << id << std::endl;
    }
}
