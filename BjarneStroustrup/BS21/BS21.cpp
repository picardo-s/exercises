#include <iostream>
#include <vector>
#include <numeric>

struct Record
{
    double unit_price;
    int units;
};

double price(double v, const Record& r)
{
    return (v + r.unit_price * r.units);
}

int main()
{
    std::vector<Record> v;
    v.push_back({ 2.5, 2 });
    v.push_back({ 3, 1 });
    v.push_back({ 1.5, 2 });
    v.push_back({ 1, 5 });
    std::cout << std::accumulate(v.begin(), v.end(), 0.0, price);
}
