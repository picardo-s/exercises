#include <iostream>
#include <string>
#include <vector>
#include <memory>
//Exercise 0 -------------------------------------------------------------------------------------------------------------------

//template<typename T>
//struct S
//{
//private:
//    T val;
//public:
//    S(T value) : val{ value }
//    {};
//
//    T& get();
//    const T& get() const;
//    void set(T);
//    S<T>& operator=(const T&);
//};
//
//template<typename T>
//T& S<T>::get()
//{
//    return val;
//}
//
//template<typename T>
//const T& S<T>::get() const
//{
//    return val;
//}
//
//template<typename T>
//void S<T>::set(T new_val)
//{
//    val = new_val;
//}
//
//template<typename T>
//S<T>& S<T>::operator=(const T& s)
//{
//    if (*this == s) return this;
//    val = s.val;
//    return this;
//}
//
//template<typename T>
//void read_val(T& v)
//{
//    std::cout << "Enter data: ";
//    std::cin >> v;
//    std::cout << "Successfully\n";
//}
//
//int main()
//{
//    S<int> s_int(5);
//    S<char> s_ch('a');
//    S<double> s_d(3.5);
//    S<std::string> s_str("Beez");
//    S<std::vector<int>> s_v{ {1, 2, 3, 4, 5} };
//
//    read_val(s_int.get());
//    read_val(s_ch.get());
//    read_val(s_d.get());
//    read_val(s_str.get());
//
//    std::cout << s_int.get() << '\n'
//        << s_ch.get() << '\n'
//        << s_d.get() << '\n'
//        << s_str.get() << '\n';
//    for (auto n : s_v.get())
//        std::cout << n << " ";
//
//    S<int> s_int2(30);
//    s_int.set(20);
//    s_int = s_int;
//    std::cout << s_int.get() << '\n';
//    s_int = s_int2;
//    std::cout << s_int.get() << '\n';
//}

//Exercise 1, 2 -------------------------------------------------------------------------------------------------------------------

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2)
{
	for (unsigned int i{}; i < v1.size() && i < v2.size(); i++)
		v1[i] += v2[i];
}

template<typename T, typename U>
T v_sum(const std::vector<T>& v1, const std::vector<U>& v2)
{
	T sum{};
	for (unsigned int i{}; i < v1.size() && i < v2.size(); i++)
		sum += v1[i] * v2[i];
	return sum;
}

//int main()
//{
//	std::vector<int> v1{ 1,2,3,4,5,6,7 };
//	std::vector<int> v2{ 2,3,4,5,6 };
//	std::vector<char> v3{ 'z', 'b', 'c' };
//	//f(v1, v2);
//	//for (auto n : v1)
//	//	std::cout << n << ' ';
//	std::cout << v_sum(v1, v3);
//}

//Exercise 3 -------------------------------------------------------------------------------------------------------------------

//template <typename T, typename U>
//struct Pair
//{
//	T name;
//	U value;
//};
//
//template<typename T, typename U>
//U get_value(const std::vector <Pair<T, U>>& vector, const T& name)
//{
//	for (Pair<T, U> a : vector)
//		if (a.name == name)
//			return a.value;
//	throw std::runtime_error("Undefined value");
//}
//
//template<typename T, typename U>
//void add_value(std::vector<Pair<T, U>>& vector, const Pair<T, U> p)
//{
//	for (Pair<T, U>& a : vector)
//		if (a.name == p.name)
//			throw std::runtime_error("Already defined name");
//	vector.push_back(p);
//}
//
//template<typename T, typename U>
//void set_value(std::vector<Pair<T, U>>& vector, const Pair<T, U> p)
//{
//	for (Pair<T, U>& a : vector)
//		if (a.name == p.name)
//		{
//			a.value = p.value;
//			return;
//		}
//	throw std::runtime_error("Undefined name");
//}

//int main()
//{
//	std::vector<Pair<char, int>> pairs;
//	Pair<char, int> p{ 'a', 100 };
//	add_value(pairs, p);
//	add_value(pairs, { 'e', 2 });
//	std::cout << get_value(pairs, 'a') << ' ' << get_value(pairs, 'e');
//	set_value(pairs, { 'a', 43 });
//	std::cout << '\n' << get_value(pairs, 'a');
//}

//Exercise 4 -------------------------------------------------------------------------------------------------------------------

//struct God
//{
//    std::string name;
//    std::string myphology;
//    std::string vehicle;
//    std::string weapon;
//
//    bool operator==(const God& g);
//    bool operator!=(const God& g);
//    bool operator>(const God& g);
//    bool operator<(const God& g);
//};
//
//bool God::operator==(const God& g)
//{
//    if (name == g.name && myphology == g.myphology
//        && vehicle == g.vehicle && weapon == g.weapon)
//        return true;
//    else return false;
//}
//
//bool God::operator!=(const God& g)
//{
//    return !(*this == g);
//}
//
//bool God::operator>(const God& g)
//{
//    return (name > g.name) ? true : false;
//}
//
//bool God::operator < (const God& g)
//{
//    return !(*this > g);
//}
//
//std::ostream& operator<<(std::ostream& s, const God& g)
//{
//    s << "Name: " << g.name
//        << "\nMyphology: " << g.myphology
//        << "\nVehicle: " << g.vehicle
//        << "\nWeapon: " << g.weapon << std::endl << std::endl;
//    return s;
//}
//
//template<typename T>
//class Link
//{
//private:
//    Link* prev;
//    Link* succ;
//public:
//    T value;
//    Link(const T& val, Link* p = nullptr, Link* s = nullptr)
//        : value{ val }, prev{ p }, succ{ s } {}
//    Link* insert(Link*);
//    Link* add(Link*);
//    Link* add_ordered(Link*);
//    Link* erase();
//    Link* find(const T&);
//    const Link* find(const T&) const;
//    const Link* advance(int) const;
//    Link* next() const { return succ; };
//    Link* previous() const { return prev; };
//};
//
//template<typename T>
//Link<T>* Link<T>::insert(Link<T>* n)
//{
//    if (n == nullptr) return this;
//    if (this == nullptr) return n;
//    n->succ = this;
//    if (prev) prev->succ = n;
//    n->prev = prev;
//    prev = n;
//
//    while (n->prev)
//        n = n->prev;
//    return n;
//}
//
//template<typename T>
//Link<T>* Link<T>::add(Link<T>* n)
//{
//    if (n == nullptr) return this;
//    if (this == nullptr) return n;
//    n->prev = this;
//    if (succ)
//    {
//        n->succ = succ;
//        n->succ->prev = n;
//    }
//    succ = n;
//
//    while (n->prev)
//        n = n->prev;
//    return n;
//}
//
//template<typename T>
//Link<T>* Link<T>::add_ordered(Link<T>* n)
//{
//    if (n == nullptr) return this;
//    if (this == nullptr) return n;
//    Link<T>* temp = this;
//    while (temp)
//    {
//        if (temp->value < n->value)
//            if (temp->succ)
//            {
//                temp = temp->succ;
//                continue;
//            }
//            else return temp->add(n);
//        else return insert(n);
//    }
//    return nullptr;
//}
//
//template<typename T>
//Link<T>* Link<T>::erase()
//{
//    if (this == nullptr) return nullptr;
//    if (succ) succ->prev = prev;
//    if (prev) prev->succ = succ;
//    return succ;
//}
//
//template<typename T>
//Link<T>* Link<T>::find(const T& val)
//{
//    Link<T>* temp = this;
//    while (temp)
//    {
//        if (temp->value == val) return temp;
//        temp = temp->succ;
//    }
//    return nullptr;
//}
//
//template<typename T>
//const Link<T>* Link<T>::find(const T& val) const
//{
//    return const_cast<Link<T>*>(this)->find(val);
//}
//
//template<typename T>
//const Link<T>* Link<T>::advance(int n) const
//{
//    if (this == nullptr) return nullptr;
//    const Link<T>* temp = this;
//    if (0 < n)
//        while (n--)
//        {
//            if (temp->succ == nullptr) return nullptr;
//            temp = temp->succ;
//        }
//    else if (n < 0)
//        while (n++)
//        {
//            if (temp->prev == nullptr) return nullptr;
//            temp = temp->prev;
//        }
//    return temp;
//}
//
//template<typename T>
//void print_all(Link<T>* link)
//{
//    while (link)
//    {
//        std::cout << link->value;
//        link = link->next();
//    }
//}
//
//int main()
//{
//
//    Link<God>* gods = new Link<God>{ {"Odin", "North", "Volvo", "Spear"} };
//    gods = gods->insert(new Link<God>{ {"Loki", "North", "Jeep", "Jokes"} });
//    gods = gods->insert(new Link<God>{ {"Zeus", "Greek", "Tachanka", "Lightnings"} });
//    gods = gods->insert(new Link<God>{ {"Freia", "North", "Fiat", "Sword"} });
//    gods = gods->insert(new Link<God>{ {"Anubis", "Egypt", "Lincoln", "Death"} });
//    gods = gods->insert(new Link<God>{ {"Ra", "Egypt", "Daewoo", "Sun"} });
//    gods = gods->insert(new Link<God>{ {"Gefest", "Greek", "BMW", "Fire"} });
//    gods = gods->insert(new Link<God>{ {"Poseidon", "Greek", "Shell", "Water"} });
//    gods = gods->insert(new Link<God>{ {"Min", "Egypt", "Tiger", "Dedicating"} });
//
//    Link<God>* greek_gods{}, * north_gods{}, * egypt_gods{};
//
//    while (gods)
//    {
//        if (gods->value.myphology == "North")
//        {
//            if (!north_gods)
//                north_gods = new Link<God>{ gods->value };
//            else north_gods = north_gods->add_ordered(new Link<God>(gods->value));
//        }
//        else if (gods->value.myphology == "Greek")
//        {
//            if (!greek_gods)
//                greek_gods = new Link<God>{ gods->value };
//            else greek_gods = greek_gods->add_ordered(new Link<God>(gods->value));
//        }
//        else
//        {
//            if (!egypt_gods)
//                egypt_gods = new Link<God>{ gods->value };
//            else egypt_gods = egypt_gods->add_ordered(new Link<God>(gods->value));
//        }
//        gods = gods->next();
//    }
//
//    std::cout << "NORTH:\n";
//    print_all(north_gods);
//
//    std::cout << "GREEK:\n";
//    print_all(greek_gods);
//
//    std::cout << "EGYPT:\n";
//    print_all(egypt_gods);
//}

//Exercise 6, 7 -------------------------------------------------------------------------------------------------------------------

template<typename T>
class Number
{
private:
	T value;
public:
	Number();
	Number(T);
	T get_value() const;
	Number& operator=(const Number&);
	const Number& operator+=(const Number&);
	const Number& operator-=(const Number&);
	const Number& operator*=(const Number&);
	const Number& operator/=(const Number&);
	operator T() const;
	bool operator==(const Number&);
	bool operator!=(const Number&);
	bool operator>(const Number&);
	bool operator<(const Number&);
	//friend const Number operator*(const Number& ln, const Number& rn)
	//{
	//	return ln.get_value() * rn.get_value();
	//}
};

template<typename T>
Number<T>::Number() : value{ 0 }
{}

template<typename T>
Number<T>::Number(T val) : value{ val }
{}

template<typename T>
Number<T>& Number<T>::operator=(const Number<T>& num)
{
	if (this == &num) return *this;
	value = num.value;
	return *this;
}

template<typename T>
T Number<T>::get_value() const
{
	return value;
}

template<typename T>
const Number<T> operator*(const Number<T>& ln, const Number<T>& rn)
{
	return ln.get_value() * rn.get_value();
}

template<typename T>
const Number<T> operator/(const Number<T>& ln, const Number<T>& rn)
{
	return ln.get_value() / rn.get_value();
}

template<typename T>
const Number<T> operator+(const Number<T>& ln, const Number<T>& rn)
{
	return ln.get_value() + rn.get_value();
}

template<typename T>
const Number<T> operator-(const Number<T>& ln, const Number<T>& rn)
{
	return ln.get_value() - rn.get_value();
}

template<typename T>
const Number<T>& Number<T>::operator+=(const Number<T>& num)
{
	value += num.value;
	return *this;
}

template<typename T>
const Number<T>& Number<T>::operator-=(const Number<T>& num)
{
	value -= num.value;
	return *this;
}

template<typename T>
const Number<T>& Number<T>::operator*=(const Number<T>& num)
{
	value *= num.value;
	return *this;
}

template<typename T>
const Number<T>& Number<T>::operator/=(const Number<T>& num)
{
	value /= num.value;
	return *this;
}

template<typename T>
bool Number<T>::operator==(const Number& num)
{
	return (value == num.value) ? true : false;
}

template<typename T>
bool Number<T>::operator!=(const Number& num)
{
	return !(*this == num);
}

template<typename T>
bool Number<T>::operator>(const Number& num)
{
	return (value > num.value) ? true : false;
}

template<typename T>
bool Number<T>::operator<(const Number& num)
{
	if (*this != num && !(*this > num))
		return true;
	else return false;
}

template<typename T>
Number<T>::operator T() const
{
	return value;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Number<T>& num)
{
	os << num.get_value();
	return os;
}

int main()
{
	Number<int> n_int(15);
	Number<int> n2_int(3), n3_int, n4_int;
	n4_int = n3_int = n2_int;
	std::cout << n4_int << ' ' << n3_int << '\n';
	Number<double> n_doub(2.5);
	std::cout << n_int / n2_int << '\n';
	std::cout << 2 * n2_int << '\n';
	std::vector<Number<double>> v_d{ 1.1, 2.2, 3.3 };
	std::vector<Number<int>> v_d2{ 2, 3, 4 };
	std::cout << v_sum(v_d, v_d2);
	std::cout << '\n';
	std::cout << (n_int *= 2);
	
}

//Exercise 8 -------------------------------------------------------------------------------------------------------------------

template<typename T>
class Allocator
{
public:
	T* allocate(int n);
	void deallocate(T* p);
	void construct(T* p, const T& v);
	void destroy(T* p);
};

template<typename T>
T* Allocator<T>::allocate(int n)
{
	void* ptr = malloc(n * sizeof(T));
	if (!ptr)
		throw std::runtime_error("Cannot allocate uninitialized memory");
	return static_cast<T*>(ptr);
}

template<typename T>
void Allocator<T>::deallocate(T* p)
{
	free(p);
}

template<typename T>
void Allocator<T>::construct(T* p, const T& v)
{
	new(p) T{ v };			//try-catch block??
}

template<typename T>
void Allocator<T>::destroy(T* p)
{
	p->~T();
}

//template<typename T, typename A = Allocator<T>>
//class Vector
//{
//private:
//	A alloc;
//	int sz;
//	T* elem;
//	int space;
//public:
//	Vector() : sz{ 0 }, elem{ nullptr }, space{0}
//	{}
//	explicit Vector(int s) : sz{ 0 }, elem{ alloc.allocate(s)}, space{ s }
//	{
//		for (int i = 0; i < sz; ++i)
//			elem[i] = 0;
//	}
//	Vector(const Vector&);
//	Vector& operator=(const Vector&);
//	Vector(Vector&&);
//	Vector& operator=(Vector&&);
//	~Vector()
//	{
//		alloc.deallocate(elem, space);
//	}
//	T& operator[](int n)
//	{
//		return elem[n];
//	}
//	const T& operator[](int n) const
//	{
//		return elem[n];
//	}
//	int size() const
//	{
//		return sz;
//	}
//	int capacity() const
//	{
//		return space;
//	}
//	void resize(int newsize, T val = T());
//	void push_back(const T& d);
//	void reserve(int newalloc);
//};
//
//template<typename T, typename A>
//Vector<T, A>::Vector(const Vector<T,A>& v)
//	: sz{v.sz}, elem{ alloc.allocate(v.sz)}
//{
//	std::copy(v, v + sz, elem);
//}
//
//template<typename T, typename A>
//Vector<T, A>& Vector<T, A>::operator=(const Vector<T, A>& v)
//{
//	if (this = &v) return *this;
//	T* p = alloc.allocate(v.sz);
//	copy(v.elem, v.elem + v.sz, p);
//	alloc.deallocate(elem, space);
//	elem = p;
//	sz = v.sz;
//	return *this;
//}
//
//template<typename T, typename A>
//Vector<T, A>::Vector(Vector<T,A>&& v)
//	: sz{v.sz}, elem{v.elem}
//{
//	v.elem = nullptr;
//}
//
//template<typename T, typename A>
//Vector<T, A>& Vector<T, A>::operator=(Vector&& v)
//{
//	alloc.deallocate(elem, space);
//	elem = v.elem;
//	sz = v.sz;
//	v.elem = nullptr;
//	return *this;
//}
//
//template<typename T, typename A>
//void Vector<T, A>::reserve(int newalloc)
//{
//	if (newalloc <= space) return;
//	T* p = alloc.allocate(newalloc);
//	for (int i{0}; i < sz; ++i)
//		alloc.construct(&p[i], elem[i]);
//	for (int i{0}; i < sz; ++i)
//		alloc.destroy(&elem[i]);
//	alloc.deallocate(elem, space);
//	elem = p;
//	space = newalloc;
//}
//
//template<typename T, typename A>
//void Vector<T, A>::push_back(const T& val)
//{
//	if (space == 0) reserve(8);
//	else if (sz == space) reserve(2 * space);
//	alloc.construct(&elem[sz], val);
//	++sz;
//}
//
//template<typename T, typename A>
//void Vector<T, A>::resize(int newsize, T val)
//{
//	reserve(newsize);
//	for (int i{ sz }; i < newsize; ++i)
//		alloc.construct(&elem[i], val);
//	for (int i{ newsize }; i < sz; ++i)
//		alloc.destroy(&elem[i]);
//	sz = newsize;
//}
//
//int main()
//{
//	Vector<int> v(3);
//	std::cout << v.capacity() << " " << v.size() << '\n';
//	for (int i{}; i < 5; i++)
//		v.push_back(i);
//	for (int i{}; i < 5; i++)
//		std::cout << v[i] << ' ';
//	std::cout << '\n';
//	std::cout << v.capacity() << " " << v.size() << '\n';
//}

//Exercise 10 -------------------------------------------------------------------------------------------------------------------

//template<typename T>
//class Unique_ptr
//{
//private:
//	T* source;
//	Unique_ptr(const Unique_ptr&);
//	Unique_ptr(Unique_ptr&&);
//	Unique_ptr& operator=(const Unique_ptr&);
//	Unique_ptr& operator=(Unique_ptr&&);
//public:
//	Unique_ptr(T*);
//	~Unique_ptr();
//	T* release();
//	T& operator*();
//	const T& operator*() const;
//	T& operator->();
//	const T& operator->() const;
//};
//
//template<typename T>
//Unique_ptr<T>::Unique_ptr(T* val) : source{ val }
//{}
//
//template<typename T>
//Unique_ptr<T>::~Unique_ptr()
//{
//	if (source)
//		delete source;
//}
//
//template<typename T>
//T* Unique_ptr<T>::release()
//{
//	T* temp_ptr{ source };
//	source = nullptr;
//	return temp_ptr;
//}
//
//template<typename T>
//T& Unique_ptr<T>::operator*()
//{
//	return *source;
//}
//
//template<typename T>
//const T& Unique_ptr<T>::operator*() const
//{
//	return *source;
//}
//
//template<typename T>
//T& Unique_ptr<T>::operator->()
//{
//	return *source;
//}
//
//template<typename T>
//const T& Unique_ptr<T>::operator->() const
//{
//	return *source;
//}
//
//int main()
//{
//	Unique_ptr<int> ui(new int{ 7 });
//	Unique_ptr<std::vector<int>> uv(new std::vector<int>);
//	//Unique_ptr < std::vector<int>> uv2;
//	for (int i{}; i < 10; i++)
//	{
//		(*uv).push_back(i);
//		(*uv)[i] *= *(ui);
//	}
//	for (auto n : (*uv))
//		std::cout << n << ' ';
//}

//Exercise 11 -------------------------------------------------------------------------------------------------------------------

constexpr int LAST_NUM = 1;

class ptr_counter
{
private:
	int count;
	void check_value()
	{
		if (count < LAST_NUM) throw std::runtime_error("ptr_counter: wrong value");
	}
public:
	ptr_counter() : count{ LAST_NUM }
	{}
	int get_value() const
	{
		return count;
	}
	void increase()
	{
		++count;
		check_value();
	}
	void decrease()
	{
		--count;
		check_value();
	}
	bool is_last() const
	{
		return (count == LAST_NUM) ? true : false;
	}
	//void operator++()
	//{
	//	++count;
	//}
	//void operator--()
	//{
	//	--count;
	//	check_value(count);
	//}
};

template<typename T>
class Counted_ptr
{
private:
	T* source;
	ptr_counter* counter;
	void del_last() const;
public:
	Counted_ptr();
	Counted_ptr(const T*);
	Counted_ptr(const Counted_ptr&);
	Counted_ptr(Counted_ptr&&);
	~Counted_ptr();
	Counted_ptr& operator=(const Counted_ptr&);
	Counted_ptr& operator=(Counted_ptr&&);
	T* get() const;
	int use_count() const;
	void reset(const T*);
	T& operator*() const;
	T* operator->() const;
};

template<typename T>
void Counted_ptr<T>::del_last() const
{
	if (counter)
	{
		if (counter->is_last())
		{
			delete source;
			delete counter;
			std::cout << "\ndeleted ptr\n";
		}
		else counter->decrease();
	}
}

template<typename T>
Counted_ptr<T>::Counted_ptr() : source{ nullptr }, counter{ nullptr }
{
	std::cout << "\nconstructor without args\n";
}

template<typename T>
Counted_ptr<T>::Counted_ptr(const T* arg)
	: source{new T{*arg}}, counter{new ptr_counter{}}
{
	std::cout << "\nconstructor with arg\n";
}

template<typename T>
Counted_ptr<T>::Counted_ptr(const Counted_ptr& arg)
{
	std::cout << "\ncopy constructor\n";
	source = arg.source;
	counter = arg.counter;
	counter->increase();
}

template<typename T>
Counted_ptr<T>::Counted_ptr(Counted_ptr&& arg)
{
	std::cout << "\nmove constr\n";
	source = arg.source;
	counter = arg.counter;
	arg.source = nullptr;
	arg.counter = nullptr;
}

template<typename T>
Counted_ptr<T>::~Counted_ptr()
{
	del_last();
}

template<typename T>
Counted_ptr<T>& Counted_ptr<T>::operator=(const Counted_ptr& arg)
{
	std::cout << "\ncopy assign\n";
	if (this == &arg) return *this;
	del_last();
	source = arg.source;
	counter = arg.counter;
	counter->increase();
	return *this;
}

template<typename T>
Counted_ptr<T>& Counted_ptr<T>::operator=(Counted_ptr&& arg)
{
	std::cout << "\nmove assign\n";
	del_last();
	source = arg.source;
	counter = arg.counter;
	arg.source = nullptr;
	arg.counter = nullptr;
	return *this;
}

template<typename T>
T* Counted_ptr<T>::get() const
{
	return source;
}

template<typename T>
int Counted_ptr<T>::use_count() const
{
	return counter->get_value();
}

template<typename T>
void Counted_ptr<T>::reset(const T* arg)
{
	del_last();
	source = arg;
	counter = new ptr_counter{};
}

template<typename T>
T& Counted_ptr<T>::operator*() const
{
	return *source;
}

template<typename T>
T* Counted_ptr<T>::operator->() const
{
	return source;
}

template<typename T, typename U>
bool operator==(const Counted_ptr<T>& larg, const Counted_ptr<U>& rarg)
{
	return larg.get() == rarg.get();
}

template<typename T, typename U>
bool operator!=(const Counted_ptr<T>& larg, const Counted_ptr<U>& rarg)
{
	return !(larg == rarg);
}

template<typename T, typename U>
bool operator<(const Counted_ptr<T>& larg, const Counted_ptr<U>& rarg)
{
	return std::less<>()(larg.get(), rarg.get());
}

template<typename T>
Counted_ptr<T> make_counted(const T& arg)
{
	Counted_ptr<T> temp{ new T(arg) };
	return temp;
}

template<typename T>
void test(Counted_ptr<T> arg)
{

}

//int main()
//{
//	const std::shared_ptr<int> i = std::make_shared<int>(42);
//	*(i.get()) = 15;
//	std::cout << *(i.get());
//	//Counted_ptr<std::vector<int>> v{new std::vector<int>};
//	//Counted_ptr<int> i1{ new int{12} };
//	//Counted_ptr<int> i2{ new int{3} };
//	//std::vector<int> vv;
//	//std::vector<int> vv2;
//	//Counted_ptr<std::vector<int>> v2{ make_counted<std::vector<int>>(vv) };
//	//v2->push_back(10);
//	//v2->push_back(15);
//	//Counted_ptr<std::vector<int>> v5{ v2 };
//	//Counted_ptr<std::vector<int>> v3{ new std::vector<int> };
//	//std::cout << (i1 < i2);
//	//v3 = v2;
//	//test(v3);
//}

//Exercise 12 -------------------------------------------------------------------------------------------------------------------

class Tracer
{
private:
	std::string str;
public:
	Tracer(const std::string& s) : str{s}
	{
		std::cout << '\n' << str << '\n';
	}
	~Tracer()
	{
		std::cout << '\n' << str << '\n';
	}
};

class ForTracer
{
private:
	Tracer tr;
public:
	ForTracer(const std::string& str) : tr{ str }
	{}
};

void tracer_test(const Tracer& t)
{
	Tracer function("local_func");
	ForTracer fr_func("fr_local_func");
	static ForTracer stat_fr_func("stat_fr_local_func");
	static Tracer stat_func("stat_local_func");
}

//Tracer global("global");
//static Tracer stat_global("static_global");
//static ForTracer stat_fr_global("stat_fr_global");

//int main()
//{
//	Tracer local_main("local_main");
//	std::string func_arg{ "function_argument" };
//	tracer_test(func_arg);
//	Tracer* dynamic = new Tracer("dynamic_main");
//	static Tracer static_main("static_local_main");
//	ForTracer fr_main("fr_local_main");
//	static ForTracer stat_main("stat_fr_local_main");
//	delete dynamic;
//}
