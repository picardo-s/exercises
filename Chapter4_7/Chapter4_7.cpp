#include <iostream>

enum class etype {
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Employee
{
    int id;
    float salary;
    etype position;
    Date employmentDate;
};

int main()
{
    char slash, manip;
    int pos_num, cur_count = 0, max_count = 5;
    etype position;
    Employee* emp_arr = new Employee[max_count];

    std::cout << "Enter information (id, salary, a number of a position, employment date(d/m/y)) about Your employees.\n"
        << "Positions: 0 - laborer, 1 - secretary, 2 - manager, 3 - accountant, 4 - executive, 5 - researcher.\n";
    do
    {
        if (cur_count == max_count)
        {
            max_count += 5;
            Employee* emp_temp = new Employee[max_count];

            for (int i = 0; i != max_count - 5; ++i)
                emp_temp[i] = emp_arr[i];

            delete[] emp_arr;
            emp_arr = emp_temp;
        }

        std::cout << "\n#" << (cur_count + 1) << ": ";
        std::cin >> emp_arr[cur_count].id >> emp_arr[cur_count].salary >> pos_num >> emp_arr[cur_count].employmentDate.day >> slash >>
            emp_arr[cur_count].employmentDate.month >> slash >> emp_arr[cur_count].employmentDate.year;

        switch (pos_num)
        {
        case 0: emp_arr[cur_count].position = etype::laborer; break;
        case 1: emp_arr[cur_count].position = etype::secretary; break;
        case 2: emp_arr[cur_count].position = etype::manager; break;
        case 3: emp_arr[cur_count].position = etype::accountant; break;
        case 4: emp_arr[cur_count].position = etype::executive; break;
        case 5: emp_arr[cur_count].position = etype::researcher; break;
        default: std::cout << "Wrong number."; std::exit(0);
        }
        ++cur_count;
        std::cout << "Continue?(y/n):";
        std::cin >> manip;

    } while (manip != 'n');

    std::cout << std::endl;

    for (int i = 0; i != cur_count; ++i)
    {
        std::cout << "Employee #" << (i + 1) << ": id - " << emp_arr[i].id << ", salary - "
            << emp_arr[i].salary << ", position - ";
        switch (emp_arr[i].position)
        {
        case etype::laborer: std::cout << "laborer"; break;
        case etype::secretary: std::cout << "secretary"; break;
        case etype::manager: std::cout << "manager"; break;
        case etype::accountant: std::cout << "accountant"; break;
        case etype::executive: std::cout << "executive"; break;
        case etype::researcher: std::cout << "researcher"; break;
        default: std::cout << "Wrong number";
        }
        std::cout << ", employment date - " << emp_arr[i].employmentDate.day << "/" << emp_arr[i].employmentDate.month
            << "/" << emp_arr[i].employmentDate.year << '\n';
    }
}