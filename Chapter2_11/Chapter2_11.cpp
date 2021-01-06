#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setw(10) << setiosflags(ios::left) << "Surname" << setw(8) << "Name"
        << setw(15) << "Adress" << setw(15) << "Country" << endl
        << "----------------------------------------------" << endl
        << setw(10) << "Petrov" << setw(8) << "Vasily" << setw(15) << "Klenovaya 16" << setw(15) << "St.Peterburg" << endl
        << setw(10) << "Ivanov" << setw(8) << "Sergey" << setw(15) << "Osinovaya 3" << setw(15) << "Nahodka" << endl
        << setw(10) << "Sidorov" << setw(8) << "Ivan" << setw(15) << "Berezovaya 21" << setw(15) << "Kaliningrad";
}

