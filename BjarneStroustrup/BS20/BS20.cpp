#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <memory>
#include <chrono>

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

//int main()
//{
//	std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::vector<double> v(l.size());
//	std::copy(l.begin(), l.end(), v.begin());
//	for (auto& elem : v)
//		std::cout << elem << ' ';
//}

//Exercise 12 ---------------------------------------------------------------------------------------------------------------------

template<typename Elem>
struct Link
{
	Link* prev;
	Link* succ;
	Elem val;
	Link(const Elem& v) : val{ v }, prev{ nullptr }, succ{nullptr} {};
};

template <typename Elem> 
class List
{
private:
	Link<Elem>* first;
	Link<Elem>* current;
	int list_size;
public:
	List() : current{ nullptr }, first{ nullptr }, list_size{ 0 } {};

	class iterator
	{
	private:
		Link<Elem>* curr;
	public:
		iterator(Link<Elem>* p) : curr{ p } {}
		iterator& operator++() { curr = curr->succ; return *this; }
		iterator& operator--() { curr = curr->prev; return *this; }
		Elem& operator*() { return curr->val; }
		bool operator==(const iterator& b) const { return curr == b.curr; };
		bool operator!=(const iterator& b) const { return !(curr == b.curr); };
		friend class List;
	};

	iterator begin();
	iterator end();
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	void push_back(const Elem& v);
	void push_front(const Elem& v);
	void pop_front();
	void pop_back();
	Elem& front();
	Elem& back();
	int size() const { return list_size; }
};

template<typename Elem>
typename List<Elem>::iterator List<Elem>::begin()
{
	return first;
}

template<typename Elem>
typename List<Elem>::iterator List<Elem>::end()
{
	return nullptr;
}

template<typename Elem>
typename List<Elem>::iterator List<Elem>::insert(iterator p, const Elem& v)
{
	if (p == end()) return p;
	Link<Elem>* temp{p.curr->succ};
	p.curr->succ = new Link<Elem>(v);
	p.curr->succ->prev = p.curr;
	if (temp)
	{
		temp->prev = p.curr->succ;
		p.curr->succ->succ = temp;
	}
	list_size++;
	return p.curr->succ;
}

template<typename Elem>
typename List<Elem>::iterator List<Elem>::erase(iterator p)
{
	if (p == end()) return p;
	Link<Elem>* temp = p.curr->succ;
	p.curr->prev->succ = temp;
	if (temp)
		temp->prev = p.curr->prev;
	delete p.curr;
	p.curr = nullptr;
	list_size--;
	return temp;
}

template<typename Elem>
void List<Elem>::pop_front()
{
	if (first)
	{
		Link<Elem>* temp = first->succ;
		delete first;
		list_size--;
		if (list_size)
			first = temp;
		else first = current = nullptr;
	}
}

template<typename Elem>
void List<Elem>::pop_back()
{
	if (current)
	{
		Link<Elem>* temp = current->prev;
		delete current;
		list_size--;
		if (list_size)
			current = temp;
		else first = current = nullptr;
	}
}

template<typename Elem>
void List<Elem>::push_back(const Elem& v)
{
	if (!current)
	{
		current = new Link<Elem>(v);
		first = current;
	}
	else
	{
		current->succ = new Link<Elem>(v);
		current->succ->prev = current;
		current = current->succ;
	}
	list_size++;
}

template<typename Elem>
void List<Elem>::push_front(const Elem& v)
{
	Link<Elem>* new_link = new Link<Elem>(v);
	if (!current)
	{
		current = new_link;
		first = current;
	}
	else
	{
		first->prev = new_link;
		first->prev->succ = first;
		first = first->prev;
	}
	list_size++;
}

template<typename Elem>
Elem& List<Elem>::front()
{
	return first->val;
}

template<typename Elem>
Elem& List<Elem>::back()
{
	return current->val;
}

template<typename Iter>
Iter high(Iter first, Iter last)
{
	Iter high = first;
	for (Iter p = first; p != last; ++p)
		if (*high < *p) high = p;
	return high;
}

//void f_test_list()
//{
//	List<int> lst;
//	for (int x; std::cin >> x;)
//		lst.push_back(x);
//	List<int>::iterator p = high(lst.begin(), lst.end());
//	if (p == lst.end())
//		std::cout << "Empty List";
//	else std::cout << "The highest value in the List is " << *p;
//}

//int main()
//{
//	List<int> l;
//	l.push_back(100);
//	l.push_back(20);
//	l.push_back(30);
//	l.push_front(3);
//	l.push_front(1);
//	l.push_front(8);
//	//auto p = high(l.begin(), l.end());
//	//std::cout << *p;
//	auto p = l.begin();
//	//l.insert(p, 15);
//	//++p;
//	//l.insert(p, 18);
//	//p = l.begin();
//	while (p != l.end())
//	{
//		std::cout << *p << ' ';
//		++p;
//		std::cout << "\nfront: " << l.front()
//			<< "\nback: " << l.back() << '\n';
//		l.pop_back();
//		l.pop_front();
//		p = l.begin();
//	}
//}

//Exercise 15, 16 ---------------------------------------------------------------------------------------------------------------------

template<typename T>
class Allocator
{
public:
	T** allocate(int n);
	void deallocate(T** p, int n);
	void construct(T* p, const T& v);
	void destroy(T* p);
};

template<typename T>
T** Allocator<T>::allocate(int n)
{
	T** new_arr = new T * [n];
	for (int i{}; i < n; i++)
		new_arr[i] = new T{};
	return new_arr;

	//void* ptr = malloc(n * sizeof(T));
	//if (!ptr)
	//	throw std::runtime_error("Cannot allocate uninitialized memory");
	//return static_cast<T*>(ptr);
}

template<typename T>
void Allocator<T>::deallocate(T** p, int n)
{
	if (p)
	{
		for (int i{ 0 }; i < n; i++)
			delete p[i];
		delete[] p;
	}

	//free(p);
}

template<typename T>
void Allocator<T>::construct(T* p, const T& v)
{
	//p = new T{ v };
	new(p) T{ v };			//try-catch block??
}

template<typename T>
void Allocator<T>::destroy(T* p)
{
	delete p;
	p = nullptr;
	//p = nullptr;
	//p->~T();
}

template<typename T, typename A = Allocator<T>>
class Vector
{
private:
	A alloc;
	int sz;
	T** elem;
	int space;
public:
	Vector() : sz{ 0 }, elem{ nullptr }, space{0}
	{}
	explicit Vector(int s) : sz{ 0 }, elem{ alloc.allocate(s)}, space{ s }
	{
		for (int i = 0; i < sz; ++i)
			elem[i] = new int{ 0 };
	}
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	Vector(Vector&&);
	Vector& operator=(Vector&&);
	~Vector()
	{
		alloc.deallocate(elem, space);
	}
	T* operator[](int n)
	{
		return elem[n];
	}
	const T& operator[](int n) const
	{
		return elem[n];
	}
	int size() const
	{
		return sz;
	}
	int capacity() const
	{
		return space;
	}
	void resize(int newsize, T val = T());
	void push_back(const T& d);
	void reserve(int newalloc);
};

template<typename T, typename A>
Vector<T, A>::Vector(const Vector<T,A>& v)
	: sz{v.sz}, elem{ alloc.allocate(v.sz)}
{
	std::copy(v, v + sz, elem);
}

template<typename T, typename A>
Vector<T, A>& Vector<T, A>::operator=(const Vector<T, A>& v)
{
	if (this = &v) return *this;
	T** p = alloc.allocate(v.sz);
	copy(v.elem, v.elem + v.sz, p);
	alloc.deallocate(elem, elem);
	elem = p;
	sz = v.sz;
	return *this;
}

template<typename T, typename A>
Vector<T, A>::Vector(Vector<T,A>&& v)
	: sz{v.sz}, elem{v.elem}
{
	v.elem = nullptr;
}

template<typename T, typename A>
Vector<T, A>& Vector<T, A>::operator=(Vector&& v)
{
	alloc.deallocate(elem, elem);
	elem = v.elem;
	sz = v.sz;
	v.elem = nullptr;
	return *this;
}

template<typename T, typename A>
void Vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= space) return;
	T** p = alloc.allocate(newalloc);
	for (int i{0}; i < sz; ++i)
		alloc.construct(p[i], *elem[i]);
	//for (int i{0}; i < sz; ++i)
	//	alloc.destroy(elem[i]);
	alloc.deallocate(elem, space);
	elem = p;
	space = newalloc;
}

template<typename T, typename A>
void Vector<T, A>::push_back(const T& val)
{
	if (space == 0) reserve(8);
	else if (sz == space) reserve(2 * space);
	alloc.construct(elem[sz], val);
	++sz;
}

template<typename T, typename A>
void Vector<T, A>::resize(int newsize, T val)
{
	reserve(newsize);
	for (int i{ sz }; i < newsize; ++i)
		alloc.construct(elem[i], val);
	for (int i{ newsize }; i < sz; ++i)
		alloc.destroy(elem[i]);
	sz = newsize;
}

//int main()
//{
//	//int** arr = new int* [10];
//	//for (int i{ 0 }; i < 10; i++)
//	//	arr[i] = new int{ i };
//	//for (int i{ 0 }; i < 10; i++)
//	//{
//	//	if (i == 0)
//	//		std::cout << arr << '\n';
//	//	std::cout << *(*(arr + i)) << '\n';
//	//}
//	//for (int i{}; i < 10; i++)
//	//	delete *(arr + i);
//	//delete[] arr;
//
//	Vector<int> v;
//	for (int i{}; i < 10; i++)
//		v.push_back(i);
//	for (int i{ 0 }; i < v.size(); i++)
//		std::cout << *v[i] << '\n';
//}

//Exercise 20 ---------------------------------------------------------------------------------------------------------------------

int main()
{
	const unsigned long c = 10000000;

	auto t1 = std::chrono::system_clock::now();
	std::vector<unsigned long> v;
	for (unsigned long i{}; i < c; i++)
		v.push_back(i);
	auto d1 = std::chrono::system_clock::now();
	std::cout << "vector: " << std::chrono::duration_cast<std::chrono::microseconds>(d1 - t1).count();
	
	std::cout << '\n';

	auto t2 = std::chrono::system_clock::now();
	std::list<unsigned long> l;
	for (unsigned long i{}; i < c; i++)
		l.push_back(i);
	auto d2 = std::chrono::system_clock::now();
	std::cout << "list: " << std::chrono::duration_cast<std::chrono::microseconds>(d2 - t2).count();
}