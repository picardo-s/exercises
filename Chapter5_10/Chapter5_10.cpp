#include <iostream>

int globalCount;

void global();
void staticLocal();

int main()
{
    for (int i = 0; i < 10; ++i)
        global();
    
    std::cout << "\n";

    for (int i = 0; i < 10; ++i)
        staticLocal();
}

void global()
{
    ++globalCount;
    std::cout << "The global variable has been called " << globalCount << " times.\n";
}

void staticLocal()
{
    static int localCount;
    ++localCount;
    std::cout << "The static local variable has been called " << localCount << " times.\n";
}

//Answers:
//1. The static local variable is more preferable thanks to its local scope. The global variable may be called from
//any function after its definition. But it is still OK if it matches your intentions.
//2. Because of usual local variable's automatic class memory. The usual local variable is destroyed when its scope ends. 