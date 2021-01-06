#include <iostream>
#include <set>
#include <string>
#include <algorithm>

class Person
{
private:
    std::string lastName;
    std::string firstName;
    long phoneNumber;
public:
    Person() : lastName("-None-"), firstName("-None"), phoneNumber(0)
    {}
    Person(std::string lastN, std::string frstN, long phnNum)
       : lastName(lastN), firstName(frstN), phoneNumber(phnNum)
    {}
    void display_data() const
    {
        std::cout << "\"" << lastName << "\", \"" << firstName
            << "\", phone: " << phoneNumber;
    }
    void get_data()
    {
        std::cout << "Enter the last name: ";
        std::cin >> lastName;
        std::cin.ignore(1000, '\n');

        std::cout << "Enter the first name: ";
        std::cin >> firstName;
        std::cin.ignore(1000, '\n');

        while (1)
        {
            std::cout << "Enter a phone number: ";
            std::cin >> phoneNumber;
            if (std::cin.fail())
            {
                std::cout << "Wrong input.\nAgain: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else
            {
                std::cin.ignore(1000, '\n');
                break;
            }
        }
    }
    friend bool operator<(const Person& pers1,const Person& pers2);
};

bool operator<(const Person& pers1,const Person& pers2)
{
    if (pers1.lastName == pers2.lastName)
        return (pers1.firstName < pers2.firstName) ? true : false;
    return (pers1.lastName < pers2.lastName) ? true : false;
}

class comparePerson
{
public:
    bool operator()(const Person* ptrP1,const Person* ptrP2) const
    {
        return *ptrP1 < *ptrP2;
    }
};

int main()
{
    std::multiset<Person*, comparePerson> pers_mset;
    char manip;
    int count = 1;
    Person* tempPers;
    do
    {
        std::cout << "\nPerson #" << count++ << ":\n";
        tempPers = new Person;
        tempPers->get_data();
        pers_mset.insert(tempPers);

        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

    std::multiset<Person*, comparePerson>::iterator iter;
    iter = pers_mset.begin();
    count = 1;
    while (iter != pers_mset.end())
    {
        std::cout << std::endl << count++ << ": ";
        (**iter++).display_data();
    }
}
