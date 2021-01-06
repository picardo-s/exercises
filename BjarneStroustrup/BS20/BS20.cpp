#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <memory>

//void copy(int* f1, int* e1, int* f2)
//{
//    for (int i{}; (f1 + i) != e1; i++)
//        *(f2 + i) = *(f1 + i);
//}
//
//int main()
//{
//    const int max = 10;
//    int f1[max]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//    int f2[max];
//    copy(f1, f1 + max, f2);
//    for (int i{}; i < max; i++)
//        std::cout << *(f2 + i) << ' ';
//}

//Exercise 0 ---------------------------------------------------------------------------------------------------------------------

//template<typename Iter1, typename Iter2>
//Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
//{
//	while (f1 != e1)
//		*f2++ = *f1++;
//	return f2;
//}
//
//template<typename Iter>
//void print(Iter begin, Iter end)
//{
//	while (begin != end)
//	{
//		std::cout << *begin << ' ';
//		begin++;
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	int arr_int[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::vector<int> v_int{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::list<int> l_int{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	int arr_int2[10];
//	for (int i{}; i < 10; i++)
//		*(arr_int2 + i) = *(arr_int + i);
//	std::vector<int> v_int2{ v_int };
//	std::list<int> l_int2{ l_int };
//
//	for (int i{}; i < 10; i++)
//		*(arr_int + i) *= 2;
//	for (auto& elem : v_int)
//		elem *= 3;
//	for (auto& elem : l_int)
//		elem *= 5;
//
//	my_copy(arr_int, arr_int + 10, v_int.begin());
//	my_copy(l_int.begin(), l_int.end(), arr_int);
//
//	auto p = find(v_int.begin(), v_int.end(), 3);
//	if (p != v_int.end())
//		std::cout << "Found!\n";
//	else std::cout << "Not Found!\n";
//
//	auto p1 = find(l_int.begin(), l_int.end(), 20);
//	if (p1 != l_int.end())
//	{
//		int count{};
//		std::list<int>::iterator count_iter = l_int.begin();
//		while (count_iter++ != p1)
//			count++;
//		std::cout << "Found at " << count << '\n';
//	}
//	else std::cout << "Not Found\n";
//
//	print(arr_int, arr_int + 10);
//	print(v_int.begin(), v_int.end());
//	print(l_int.begin(), l_int.end()); 
//}

//Exercise 2 ---------------------------------------------------------------------------------------------------------------------

double* get_from_jack(int* count)
{
	int size = 5;
	double* arr = new double[size];
	std::ifstream file{ "S:/perfect_circle/BjarneStroustrup/BS20/jack.txt" };
	for (double temp{}; file >> temp; (*count)++)
	{
		if (*count == size)
		{
			double* temp_arr = new double[size + (size / 2)];
			std::copy(arr, arr + size, temp_arr);
			delete[] arr;
			arr = temp_arr;
			size += size / 2;
		}
		*(arr + (*count)) = temp;
	}
	return arr;
}

std::vector<double>* get_from_jill()
{
	std::vector<double>* v = new std::vector<double>;
	std::ifstream file{ "S:/perfect_circle/BjarneStroustrup/BS20/jill.txt" };
	for (double temp; file >> temp;)
		v->push_back(temp);
	return v;
}

//double* highest(double* begin, double* end)
//{
//	if (begin == end) return end;
//	double* highest = begin;
//	while (begin != end)
//	{
//		if (*highest < *begin)
//			highest = begin;
//		begin++;
//	}
//	return highest;
//}

//int main()
//{
//	int count{0};
//	double* jack = get_from_jack(&count);
//	std::vector < double>* jill = get_from_jill();
//	std::vector<double>& v = *jill;
//	double* jack_high = highest(jack, jack + *count);
//	double* jill_high = highest(&v[0], &v[0] + jill->size());
//	std::cout << "Jack " << *jack_high << '\n' << "Jill " << *jill_high;
//}

//Exercise 4 ---------------------------------------------------------------------------------------------------------------------

template<typename Iter>
Iter highest(Iter first, Iter last)
{
	if (first == last) return last;
	Iter high = first;
	for (Iter p = first; p != last; ++p)
		if (*high < *p) high = p;
	return high;
}

//int main()
//{
//	//int count{0};
//	//double* jack = get_from_jack(&count);
//	//std::vector < double>* jill = get_from_jill();
//
//	//double* jack_high = highest(jack, jack + count);
//	//std::vector<double>& v = *jill;
//	//double* jill_high = highest(&v[0], &v[0] + v.size());
//
//	//std::cout << "Jack " << *jack_high << '\n' << "Jill " << *jill_high;
//
//	//delete[] jack;
//	//delete jill;
//
//	int count{0};
//	double* jack = get_from_jack(&count);
//	std::vector < double>* jill = get_from_jill();
//
//	double* jack_high = highest(jack, jack + count);
//	if (jack_high == (jack + count))
//		std::cout << "Not found\n";
//	else std::cout << "Jack " << *jack_high << '\n';
//
//	std::vector<double>& v = *jill;
//	double* jill_high = highest(&v[0], &v[0] + v.size());
//	if (jill_high == (&v[0] + v.size()))
//		std::cout << "Not found\n";
//	else std::cout << "Jill " << *jill_high << '\n';
//
//	//std::cout << "Jack " << *jack_high << '\n' << "Jill " << *jill_high;
//
//	delete[] jack;
//	delete jill;
//}

//Exercise 5 ---------------------------------------------------------------------------------------------------------------------

//template<typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
//{
//	for (auto& elem : v)
//		os << elem << ' ';
//	return os;
//}
//
//template<typename T>
//std::istream& operator>>(std::istream& is, std::vector<T>& v)
//{
//	for (T temp; std::cin >> temp;)
//		v.push_back(temp);
//	return is;
//}
//
//int main()
//{
//	std::vector<int> v;
//	std::cin >> v;
//	std::cout << '\n';
//	std::cout << v;
//}

//Exercise 6 ---------------------------------------------------------------------------------------------------------------------

//using Line = std::vector<char>;
//
//class Text_iterator
//{
//private:
//	std::list<Line>::iterator ln;
//	Line::iterator pos;
//public:
//	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) : ln{ ll }, pos{ pp }
//	{}
//	char& operator*()
//	{
//		return *pos;
//	}
//	Text_iterator& operator++();
//	bool operator==(const Text_iterator& other) const
//	{
//		return ln == other.ln && pos == other.pos;
//	}
//	bool operator!=(const Text_iterator& other) const
//	{
//		return !(*this == other);
//	}
//};
//
//Text_iterator& Text_iterator::operator++()
//{
//	++pos;
//	if (pos == (*ln).end())
//	{
//		++ln;
//		pos = (*ln).begin();
//	}
//	return *this;
//}
//
//struct Document
//{
//	std::list<Line> line;
//	Document()
//	{
//		line.push_back(Line{});
//	}
//	Text_iterator begin()
//	{
//		return Text_iterator(line.begin(), (*line.begin()).begin());
//	}
//	Text_iterator end()
//	{
//		return Text_iterator(line.end(), (line.end())->end());
//	}
//};
//
//std::istream& operator>>(std::istream& is, Document& d)
//{
//	for (char ch; is.get(ch);)
//	{
//		d.line.back().push_back(ch);
//		if (ch == '\n')
//			d.line.push_back(Line{});
//	}
//	if (d.line.back().size())
//		d.line.push_back(Line{});
//	return is;
//}
//
//void print(Document& d)
//{
//	for (auto p : d)
//		std::cout << p;
//	//for (auto list = d.line.begin(); list != d.line.end(); list++)
//	//	for (unsigned int i{ 0 }; i < (*list).size(); i++)
//	//		std::cout << (*list)[i];
//}
//
//int main()
//{
//	Document d;
//	if (d.begin() == d.end())
//		std::cout << "Equal";
//	//std::cin >> d;
//	//print(d);
//}

//Exercise 7 ---------------------------------------------------------------------------------------------------------------------

//template<typename Iter>
//Iter last_str(Iter begin, Iter end)
//{
//	if (begin == end) return end;
//	Iter max = begin;
//	while (begin != end)
//	{
//		if (*max < *begin)
//			max = begin;
//		++begin;
//	}
//	return max;
//}
//
//int main()
//{
//	std::vector<std::string> v_str;
//	for (std::string temp; std::cin >> temp;)
//		v_str.push_back(temp);
//	auto p = last_str(v_str.begin(), v_str.end());
//	if (p != v_str.end())
//		std::cout << *p;
//	else std::cout << "Not Found";
//}

//Exercise 10 ---------------------------------------------------------------------------------------------------------------------

//int count_words(const std::string& file_name, const std::string& white)
//{
//	std::vector<std::string> words;
//	std::ofstream file{ file_name };
//
//
//}
//
//int main()
//{
//
//}

//Exercise 11 ---------------------------------------------------------------------------------------------------------------------

int main()
{
	std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<double> v(l.size());
	std::copy(l.begin(), l.end(), v.begin());
	for (auto& elem : v)
		std::cout << elem << ' ';
}