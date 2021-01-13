#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <fstream>
#include <algorithm>

//Exercises 0.1 ---------------------------------------------------------------------------------------------------------------------------------

//struct Record
//{
//    double unit_price;
//    int units;
//};
//
//double price(double v, const Record& r)
//{
//    return (v + r.unit_price * r.units);
//}
//
//int main()
//{
//    std::vector<Record> v;
//    v.push_back({ 2.5, 2 });
//    v.push_back({ 3, 1 });
//    v.push_back({ 1.5, 2 });
//    v.push_back({ 1, 5 });
//    std::cout << std::accumulate(v.begin(), v.end(), 0.0, price);
//}

//Exercises 0.2 ---------------------------------------------------------------------------------------------------------------------------------

//double weighted_value(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b)
//{
//	return a.second * b.second;
//}
//
//int main()
//{
//	std::map<std::string, double> dow_price
//	{
//		{"MMM", 81.86},
//		{"AA", 34.69},
//		{"MO", 54.45},
//		{"PC", 117.31},
//	};
//
//	std::map<std::string, double> dow_weight
//	{
//		{"MMM", 5.8549},
//		{"AA", 2.4808},
//		{"MO", 3.8940},
//		{"PC", 7.717}
//	};
//
//	std::map<std::string, std::string> dow_name
//	{
//		{"MMM", "3M Co."},
//		{"AA", "Alcoa Inc."},
//		{"MO", "Altria Group Inc."},
//		{"PC", "Perfect Circle Co."},
//	};
//
//	for (const auto& p : dow_price)
//	{
//		std::cout << p.first << '\t'
//			<< p.second << '\t'
//			<< dow_name[p.first] << '\n';
//	}
//	
//	double dji_index = std::inner_product
//	(
//		dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0, std::plus<>(), weighted_value
//	);
//
//	std::cout << dji_index;
//}

//Exercises 0.3 ---------------------------------------------------------------------------------------------------------------------------------

//int main()
//{
//	std::string from, to;
//	std::cin >> from >> to;
//
//	std::ifstream is{ from };
//	std::ofstream os{ to };
//
//	std::istream_iterator<std::string> ii{ is };
//	std::istream_iterator<std::string> eos;
//	std::ostream_iterator<std::string> oo{ os, "\n" };
//
//	std::vector<std::string> v{ ii, eos };
//	std::sort(v.begin(), v.end());
//	std::unique_copy(v.begin(), v.end(), oo);
//}

//Exercises 0.4 ---------------------------------------------------------------------------------------------------------------------------------

struct Item
{
	std::string name;
	int iid;
	double value;
};

struct byName
{
	bool operator()(const Item& a, const Item& b) { return a.name < b.name; }
};

void find_and_erase(std::vector<Item>& v, const std::string& n)
{
	auto p = std::find_if(v.begin(), v.end(), [&n](const Item& a) {return a.name == n; });
	if (p != v.end())
		v.erase(p);
}

void find_and_erase(std::vector<Item>& v, int n)
{
	auto p = std::find_if(v.begin(), v.end(), [n](const Item& a) {return a.iid == n; });
	if (p != v.end())
		v.erase(p);
}

template<typename C>
void print_map(const C& c)
{
	for (auto& elem : c)
		std::cout << elem.first << '\t' << elem.second << '\n';
}

void add_from_cin(std::map<std::string, int>& m)
{
	for (std::pair<std::string, int> p; std::cin >> p.first >> p.second;)
		m[p.first] = p.second;
}

int main()
{
	//std::string file_name;
	//std::cin >> file_name;
	//std::ifstream file{ file_name };

	//std::vector<Item> v;
	//for (Item it; file >> it.name >> it.iid >> it.value;)
	//	v.push_back(it);

	////std::sort(v.begin(), v.end(), byName());
	////std::sort(v.begin(), v.end(), [](const Item& a, const Item& b) {return a.iid < b.iid; });
	//std::sort(v.begin(), v.end(), [](const Item& a, const Item& b) {return b.value < a.value; });

	//v.push_back({ "horse shoe", 99, 12.34 });
	//v.push_back({ "Canon", 9988, 499.95 });

	//find_and_erase(v, "Roman");
	//find_and_erase(v, 3);

	//for (auto& elem : v)
	//	std::cout << elem.name << '\t' << elem.iid << '\t' << elem.value << '\n';
	//-------------------------------------------------------------------------------------

	std::map<std::string, int> msi
	{
		{"1030", 1},
		{"1050", 2 },
		{"1050ti", 3 },
		{"1060", 4},
		{ "1070", 5 },
		{ "1070ti", 6 },
		{ "1080", 7 },
	};
	print_map(msi);
	msi.erase("1050ti");
	std::cout << '\n';
	print_map(msi);
	add_from_cin(msi);
	print_map(msi);
	std::cout << '\n';

	int sum{};
	for (auto& elem : msi)
		sum += elem.second;
	std::cout << sum;

	std::map<int, std::string> mis;
	for (auto& elem : msi)
		mis[elem.second] = elem.first;
	std::cout << '\n';
	for (auto& elem : mis)
		std::cout << elem.first << '\t' << elem.second << '\n';
}



