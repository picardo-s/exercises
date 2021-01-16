#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>

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

//struct Item
//{
//	std::string name;
//	int iid;
//	double value;
//};
//
//struct byName
//{
//	bool operator()(const Item& a, const Item& b) { return a.name < b.name; }
//};
//
//void find_and_erase(std::vector<Item>& v, const std::string& n)
//{
//	auto p = std::find_if(v.begin(), v.end(), [&n](const Item& a) {return a.name == n; });
//	if (p != v.end())
//		v.erase(p);
//}
//
//void find_and_erase(std::vector<Item>& v, int n)
//{
//	auto p = std::find_if(v.begin(), v.end(), [n](const Item& a) {return a.iid == n; });
//	if (p != v.end())
//		v.erase(p);
//}
//
//template<typename C>
//void print_map(const C& c)
//{
//	for (auto& elem : c)
//		std::cout << elem.first << '\t' << elem.second << '\n';
//}
//
//void add_from_cin(std::map<std::string, int>& m)
//{
//	for (std::pair<std::string, int> p; std::cin >> p.first >> p.second;)
//		m[p.first] = p.second;
//}
//
//
//int main()
//{
//	//std::string file_name;
//	//std::cin >> file_name;
//	//std::ifstream file{ file_name };
//
//	//std::vector<Item> v;
//	//for (Item it; file >> it.name >> it.iid >> it.value;)
//	//	v.push_back(it);
//
//	////std::sort(v.begin(), v.end(), byName());
//	////std::sort(v.begin(), v.end(), [](const Item& a, const Item& b) {return a.iid < b.iid; });
//	//std::sort(v.begin(), v.end(), [](const Item& a, const Item& b) {return b.value < a.value; });
//
//	//v.push_back({ "horse shoe", 99, 12.34 });
//	//v.push_back({ "Canon", 9988, 499.95 });
//
//	//find_and_erase(v, "Roman");
//	//find_and_erase(v, 3);
//
//	//for (auto& elem : v)
//	//	std::cout << elem.name << '\t' << elem.iid << '\t' << elem.value << '\n';
//
//	//-------------------------------------------------------------------------------------
//
//	/*std::map<std::string, int> msi
//	{
//		{"1030", 1},
//		{"1050", 2 },
//		{"1050ti", 3 },
//		{"1060", 4},
//		{ "1070", 5 },
//		{ "1070ti", 6 },
//		{ "1080", 7 },
//	};
//	print_map(msi);
//	msi.erase("1050ti");
//	std::cout << '\n';
//	print_map(msi);
//	add_from_cin(msi);
//	print_map(msi);
//	std::cout << '\n';
//
//	int sum{};
//	for (auto& elem : msi)
//		sum += elem.second;
//	std::cout << sum;
//
//	std::map<int, std::string> mis;
//	for (auto& elem : msi)
//		mis[elem.second] = elem.first;
//	std::cout << '\n';
//	for (auto& elem : mis)
//		std::cout << elem.first << '\t' << elem.second << '\n';*/
//
//		//-------------------------------------------------------------------------------------
//
//	std::string file_name;
//	std::cin >> file_name;
//
//	std::ifstream file{ file_name };
//
//	std::istream_iterator<double> ii{ file };
//	std::istream_iterator<double> eos;
//	std::ostream_iterator<double> oi{ std::cout, "\n" };
//
//	std::vector<double> vd{ ii, eos };
//	std::copy(vd.begin(), vd.end(), oi);
//
//	/*std::vector<int> vi(vd.size());
//	std::copy(vd.begin(), vd.end(), vi.begin());*/
//	std::vector<int> vi;
//	for (auto& elem : vd)
//		vi.push_back(elem);
//	for (std::vector<int>::size_type i{}; i < vd.size(); i++)	
//		std::cout << vd[i] << '\t' << vi[i] << '\n';
//	auto vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
//	auto vi_sum = std::accumulate(vi.begin(), vi.end(), 0);
//	std::cout << "vd - vi = " << vd_sum - vi_sum;
//	std::cout << '\n';
//	std::reverse(vd.begin(), vd.end());
//	std::copy(vd.begin(), vd.end(), oi);
//	std::cout << '\n';
//	double vd_avg = std::accumulate(vd.begin(), vd.end(), 0.0, [&vd](double v, double d) {return v + d / vd.size(); });
//	std::vector<double> vd2;
//	std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), [&vd_avg](double d) {return d < vd_avg; });
//	std::sort(vd2.begin(), vd2.end());
//	std::cout << "--------------\n";
//	std::copy(vd2.begin(), vd2.end(), oi);
//}

//Exercises 3, 4, 5 ---------------------------------------------------------------------------------------------------------------------------------

template<typename Iter, typename T>
typename Iter::difference_type my_count(Iter first, Iter last, const T& val)
{
	typename Iter::difference_type count{};
	while (first != last)
	{
		if (*first == val)
			count++;
		first++;
	}
	return count;
}

template<typename Iter, typename Pred>
typename Iter::difference_type my_count_if(Iter first, Iter last, Pred pred)
{
	typename Iter::difference_type count{};
	while (first != last)
	{
		if (pred(*first))
			count++;
		first++;
	}
	return count;
}

template<typename Iter, typename T>
bool strange_find(Iter& first, Iter last, const T& val)
{
	Iter temp = first;
	bool found{false};
	while (first++ != last)
	{
		if (*first == val)
		{
			found = true;
			break;
		}
	}
	if (!found)
		first = temp;
	return found;
}

//int main()
//{
//	std::vector<int> v{188, 2, 3, 1, 5, 6, 7, 10, 9, 1};
//	std::cout << my_count(v.begin(), v.end(), 1) << '\n';
//	std::cout << my_count_if(v.begin(), v.end(), [](int a) {return a > 1; });
//	
//	std::vector<int>::iterator begin{ v.begin() };
//	std::vector<int>::iterator end{ v.end() };
//	--end;
//	if (strange_find(begin, end, 8))
//		std::cout << '\n' << *begin;
//}

//Exercises 6 ---------------------------------------------------------------------------------------------------------------------------------

struct Fruit
{
	std::string name;
	int count;
	double unit_price;

};

std::ostream& operator<<(std::ostream& os, const Fruit& f)
{
	os << f.name << '\t' << f.count << '\t' << f.unit_price << '\n';
	return os;
}

struct Fruit_comparison
{
	bool operator()(const Fruit* const a, const Fruit* const b) const
	{
		return a->name < b->name;
	}
};

//int main()
//{
//	std::set<Fruit*, Fruit_comparison> market;
//	market.insert(new Fruit{ "Orange", 5, 3.5 });
//	market.insert(new Fruit{ "Grape", 3, 1.5 });
//	market.insert(new Fruit{ "Apple", 2, 5 });
//	market.insert(new Fruit{ "Watermelon", 15, 13.5 });
//	market.insert(new Fruit{ "Pineaplle", 25, 33.5 });
//	for (auto p = market.begin(); p != market.end(); ++p)
//		std::cout << *(*p) << '\n';
//}

//Exercises 7 ---------------------------------------------------------------------------------------------------------------------------------

//template<typename Iter, typename T>
//bool my_bin_search(Iter first, Iter last, const T& val)
//{
//	while (first != last && val >= *first)
//	{
//		Iter mid = first + (last - first) / 2;
//		if (*mid == val)
//			return true;
//		else if (*mid < val)
//		{
//			if(mid == (last - 1))
//				break;
//			first = mid;
//		}
//		else last = mid;
//	}
//	return false;
//}

//int main()
//{
//	std::list<int> v;
//	if (my_bin_search(v.begin(), v.end(), 902))
//		std::cout << "Found";
//	else std::cout << "Not found";
//}

//Exercises 8 ---------------------------------------------------------------------------------------------------------------------------------

void print_map(const std::map<std::string, int>& m)
{
	int max{ (*(m.begin())).second};

	for (const auto& p : m)
		if (p.second > max)
			max = p.second;

	for (int i{ 1 }; i <= max; i++)
		for (const auto& p : m)
			if (i == p.second)
				std::cout << p.second << ": " << p.first << '\n';
}

//int main()
//{
//	std::map<std::string, int> words;
//	for (std::string s; std::cin >> s;)
//		++words[s];
//	for (const auto& p : words)
//		std::cout << p.first << ": " << p.second << '\n';
//	print_map(words);
//}

//Exercises 9 ---------------------------------------------------------------------------------------------------------------------------------

constexpr char SPEC_SYMB = '*';

struct Birth_date
{
	int month;
	int day;
	int year;
};

std::istream& operator>>(std::istream& is, Birth_date& date)
{
	int m{}, d{}, y{};
	is >> m >> d >> y;
	date = { m, d, y };
	return is;
}

struct Purchase
{
	std::string name;
	double unit_price;
	int count;
};

std::istream& operator>>(std::istream& is, Purchase& p)
{
	std::string name{};
	double pr{};
	int c;
	char symb{};

	is >> symb;
	if (symb == SPEC_SYMB)
	{
		std::getline(is, name);
		is >> pr >> c;
		p = { name, pr, c };
	}
	else if(is)
	{
		is.unget();
		is.clear(std::ios_base::failbit);
	}
	return is;
}

class Order
{
private:
	std::string name;
	std::string addres;
	Birth_date b_date;
	std::vector<Purchase> purch;
public:
	Order() : name{ "N/A" }, addres{ "N/A" }, b_date{ 1, 1, 1900 } {};
	Order(const std::string& nm, const std::string& addr, const Birth_date& b_d,
		const std::vector<Purchase>& v_p) : name{ nm }, addres{ addr }, b_date{ b_d }, purch{ v_p }
	{};
	friend std::ostream& operator<<(std::ostream& os, const Order& ord);
};

std::ostream& operator<<(std::ostream& os, const Order& ord)
{
	os << "\nName: " << ord.name
		<< "\nAddres: " << ord.addres
		<< "\nBirth date: " << ord.b_date.month << "." << ord.b_date.day << "." << ord.b_date.year
		<< "\nPurchases:\n";
	for (auto& elem : ord.purch)
		os << elem.name << '\t' << elem.unit_price << '\t' << elem.count << '\n';
	return os;
}

std::vector<Order> read_from_file()
{
	std::string file_name{};
	std::cout << "Enter a file name to read: ";
	std::cin >> file_name;

	std::ifstream file{ file_name };
	if (!file)
		throw std::runtime_error("Wrong file direction");

	std::string name;
	std::string addres;
	Birth_date date;
	std::vector<Purchase> v_purch;
	std::vector<Order> v_order;

	while (1)
	{
		std::getline(file, name);
		std::getline(file, addres);
		file >> date;
		for (Purchase p; file >> p;)
			v_purch.push_back(p);
		v_order.push_back({ name, addres, date, v_purch });
		v_purch.clear();
		if (file.eof() || file.bad())
			break;
		else file.clear();
	}
	return v_order;
}

int main()
{
	//std::vector<Purchase> v{ {"orange", 12.2, 5}, {"apple", 102.2, 123}, {"Melon", 0.5, 3} };
	//Order order{ "Mark", "Ocean beach 123, Yamaha", {1, 16, 1991}, v };
	//std::cout << order;

	std::vector<Order> v{ read_from_file() };
	for (auto& elem : v)
		std::cout << elem;
}