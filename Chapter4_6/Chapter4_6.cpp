#include <iostream>

enum class etype {
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

int main()
{
    char letter;
    etype position;

    std::cout << "Enter the first letter of any position \n"
        << "(laborer, secretary, manager, accountant, executive, researcher):";
    std::cin >> letter;
    
    switch(letter)
    {
        case 'l': position = etype::laborer; break;
        case 's': position = etype::secretary; break;
        case 'm': position = etype::manager; break;
        case 'a': position = etype::accountant; break;
        case 'e': position = etype::executive; break;
        case 'r': position = etype::researcher; break;
        default: std::cout << "Wrong letter."; std::exit(0);
    }

    std::cout << "A whole name of the position is: ";

    switch (position)
    {
        case etype::laborer: std::cout << "laborer"; break;
        case etype::secretary: std::cout << "secretary"; break;
        case etype::manager: std::cout << "manager"; break;
        case etype::accountant: std::cout << "accountant"; break;
        case etype::executive: std::cout << "executive"; break;
        case etype::researcher: std::cout << "researcher"; break;
        default: std::cout << "Wrong letter";
    }
}
