#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

//Exercise 2 -----------------------

constexpr double K = 273.15;

//double c_to_k(double c)
//{
//	double k = c + K;
//	return k;
//}

//int main()
//{
//	double c = 0;
//	std::cin >> c;
//	double k = c_to_k(c);
//	std::cout << k << '\n';
//}

//Exercise 3 -----------------------

//int main()
//{
//	try
//	{
//		double c = 0;
//		std::cin >> c;
//		if (c < -K)
//			throw std::runtime_error("Temperature in C cannot be less than -273.15");
//		double k = c_to_k(c);
//		std::cout << k << '\n';
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 4 -----------------------

//double c_to_k(double c)
//{
//	if (c < -K)
//		throw std::runtime_error("Temperature in C cannot be less than -273.15");
//	double k = c + K;
//	return k;
//}
//
//int main()
//{
//	try
//	{
//		double c = 0;
//		std::cin >> c;
//		double k = c_to_k(c);
//		std::cout << k << '\n';
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 5 -----------------------

//double k_to_c(double k)
//{
//	if(k < 0)
//		throw std::runtime_error("Temperature in K cannot be less than 0");
//	double c = k - K;
//	return c;
//}
//
//int main()
//{
//	try
//	{
//		double k;
//		std::cin >> k;
//		double c = k_to_c(k);
//		std::cout << c << '\n';
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 6 -----------------------

//double c_to_f(double c)
//{
//	if(c < -K)
//		throw std::runtime_error("Temperature in C cannot be less than -273.15");
//	double f = double(9)/5 * c + 32;
//	return f;
//}
//
//int main()
//{
//	try
//	{
//		double c;
//		std::cin >> c;
//		double f = c_to_f(c);
//		std::cout << f << '\n';
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 7 -----------------------

template<class T>
T get_user_number()
{
	T temp;
	std::cin >> temp;
	std::cin.ignore(1000, '\n');
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		throw std::runtime_error("Wrong input\n");
	}
	return temp;
}

std::string get_user_string()
{
	std::string temp;
	std::getline(std::cin, temp);
	return temp;
}

//void solve_quad_equation(double a, double b, double c)
//{
//	double x1{}, x2{}, discriminant{};
//
//	discriminant = (b * b) - (4 * a * c);
//	if (discriminant < 0.0)
//		throw std::runtime_error("There is no roots");
//
//	x1 = (-b + std::sqrt(discriminant)) / (2 * a);
//	x2 = (-b - std::sqrt(discriminant)) / (2 * a);
//	std::cout << "Roots: x1 = " << x1 << ", x2 = " << x2 << '\n';
//
//	x1 = (x1 * x1 * a) + (x1 * b) + c;
//	x2 = (x2 * x2 * a) + (x2 * b) + c;
//	std::cout << "Solved answers: " << x1 << ", " << x2;
//}
//
//int main()
//{
//	double a{}, b{}, c{};
//	std::cout << "In order to solve a quadratic equation (ax^2 + bx + c = 0)\n";
//	std::cout << "Enter \'a\': ";
//	a = get_user_number<double>();
//	std::cout << "Enter \'b\': ";
//	b = get_user_number<double>();
//	std::cout << "Enter \'c\': ";
//	c = get_user_number<double>();
//	try
//	{
//		solve_quad_equation(a, b, c);
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 8 -----------------------

//int main()
//{
//	std::vector<int> vect{};
//	int amount{}, temp{};
//	
//	try
//	{
//	std::cout << "Enter an amount of summary values: ";
//	amount = get_user_number<int>();
//	std::cout << "Enter an integer (or any non-number symbol to stop input): \n";
//	for (; std::cin >> temp;)
//		vect.push_back(temp);
//
//		if (vect.size() == 0)
//			throw std::runtime_error("The vector is empty");
//		temp = 0;
//		for (int i = 0; i < amount; i++)
//			temp += vect[i];
//		std::cout << "The sum of the first " << amount << " numbers is " << temp;
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 9 -----------------------

//int main()
//{
//	std::vector<double> vect{};
//	int amount{};
//	double temp{};
//
//	try
//	{
//		std::cout << "Enter an amount of summary values: ";
//		amount = get_user_number<int>();
//		std::cout << "Enter an integer (or any non-number symbol to stop input): \n";
//		for (; std::cin >> temp;)
//			vect.push_back(temp);
//
//		if (vect.size() == 0)
//			throw std::runtime_error("The vector is empty");
//		temp = 0;
//		for (int i = 0; i < amount; i++)
//			temp += vect[i];
//		if ((temp - int(temp)) == 0)
//			std::cout << "The sum of the first " << amount << " numbers is " << temp;
//		else
//			throw std::runtime_error("The sum has a decimal part");
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 10 -----------------------

//int main()
//{
//	std::vector<double> vect{};
//	std::vector<double> real_vect{};
//	int amount{};
//	double temp{};
//	
//	try
//	{
//	std::cout << "Enter an amount of summary values: ";
//	amount = get_user_number<int>();
//	std::cout << "Enter an integer (or any non-number symbol to stop input): \n";
//	for (; std::cin >> temp;)
//		vect.push_back(temp);
//
//		if (vect.size() == 0)
//			throw std::runtime_error("The vector is empty");
//		temp = 0.0;
//		for (int i = 0; i < amount; i++)
//			temp += vect[i];
//		std::cout << "The sum of the first " << amount << " numbers is " << temp << '\n';
//		
//		for (int i = 0; i < vect.size() - 1; i++)
//		{
//			real_vect.push_back(vect[i] - vect[i + 1]);
//			std::cout << real_vect[i] << " ";
//		}
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what();
//	}
//}

//Exercise 11 -----------------------

//int main()
//{
//	std::vector<int> v_fib{};
//	int temp{};
//	v_fib.push_back(1);
//	v_fib.push_back(1);
//	for (int i = 0; temp >= 0; i++)
//	{
//		temp = v_fib[i] + v_fib[i + 1];
//		v_fib.push_back(temp);
//	}
//
//	v_fib.pop_back();
//
//	for (int n : v_fib)
//		std::cout << n << " ";
//}

//Exercise 12-13 -----------------------

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
constexpr int LIMIT = 4;
constexpr int LOW = 1;
constexpr int HEIGH = 9;

int roll(int min, int max)
{
	std::uniform_int_distribution<> die{ min, max };
	return die(mersenne);
}

//bool is_unique(const std::vector<int>& v)
//{
//	int num{}, count{};
//	for (; num < 10 && v.size() <= LIMIT; num++)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (num == v[i])
//				count++;
//		}
//		if (count >= 2)
//			return false;
//		else count = 0;
//	}
//	return true;
//}
//
//void make_a_guess(std::vector<int>& out_v)
//{
//	std::string user_number{};
//	while(1)
//	{
//		user_number = get_user_string();
//		out_v.clear();
//		if (user_number.size() != LIMIT)
//			throw std::runtime_error("Wrong amount of numbers");
//		for (int i = 0; i < LIMIT; i++)
//		{
//			if (user_number[i] < '0' || user_number[i] > '9')
//				throw std::runtime_error("Wrong symbol");
//			out_v.push_back(user_number[i] - '0');
//		}
//
//		if (is_unique(out_v))
//			break;
//		else std::cout << "Only unique numbers are expected!\n";
//	}
//}
//
//int main()
//{
//	std::vector<int> v_num;
//	std::vector<int> v_user;
//	int bulls{}, cows{};
//
//	try
//	{
//		while (1)
//		{
//			std::cout << "I came up a number...\n";
//			do
//			{
//				v_num.clear();
//				for (int i = 0; i < LIMIT; i++)
//					v_num.push_back(roll(LOW, HEIGH));
//			} while (!is_unique(v_num));
//
//			std::cout << "Make a guess: ";
//			while (1)
//			{
//				make_a_guess(v_user);
//				for (int i = 0; i < LIMIT; i++)
//				{
//					for (int j = 0; j < LIMIT; j++)
//					{
//						if (v_user[i] == v_num[j] && i == j)
//						{
//							bulls++;
//							break;
//						}
//						else if (v_user[i] == v_num[j])
//						{
//							cows++;
//							break;
//						}
//					}
//				}
//				std::cout << "Bulls: " << bulls << ", cows: " << cows << '\n';
//				if (bulls == LIMIT)
//				{
//					std::cout << "You WON!!!\n\n";
//					break;
//				}
//				bulls = cows = 0;
//			}
//		}
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Oops..." << e.what();
//	}
//}

//Exercise 14 -----------------------

constexpr int DEF_NUM = 100;

enum class days
{
	mon, tue, wed, thu, fri, sat, sun, DEF
};

days check_string(std::string& str)
{
	static const std::vector<std::string> week_days{ "monday", "tuesday",
													"wednesday", "thursday",
													"friday", "saturday",
													"sunday"};
	if (str.size() < 3)
		return days::DEF;
	for (char& s : str)
		s = std::tolower(s);
	int i{};
	for (; i < week_days.size(); i++)
	{
		if (!week_days[i].find(str))
			return days(i);
	}
	return (days)i;
}

int solve_days(const std::vector<int> v)
{
	int sum{};
	for (int n : v)
		sum += n;
	return sum;
}

int main()
{
	std::vector<int> v_monday;
	std::vector<int> v_tuesday;
	std::vector<int> v_wednesday;
	std::vector<int> v_thursday;
	std::vector<int> v_friday;
	std::vector<int> v_saturday;
	std::vector<int> v_sunday;

	int dis_count{}, num{};
	std::string temp{};

	try
	{
		while (1)
		{
			std::getline(std::cin, temp, ' ');
			if (temp == "stop")
				break;
			//temp = get_user_string();
			num = get_user_number<int>();
			switch (check_string(temp))
			{
			case days::mon: v_monday.push_back(num); break;
			case days::tue: v_tuesday.push_back(num); break;
			case days::wed: v_wednesday.push_back(num); break;
			case days::thu: v_thursday.push_back(num); break;
			case days::fri: v_friday.push_back(num); break;
			case days::sat: v_saturday.push_back(num); break;
			case days::sun: v_sunday.push_back(num); break;
			case days::DEF: std::cout << "Declined\n"; dis_count++;
			default: std::cout << "Smth went wrong\n"; std::exit(1);
			}
		}
		
		std::cout << "Monday: " << solve_days(v_monday)
			<< "\nTuesday: " << solve_days(v_tuesday)
			<< "\nWednesday: " << solve_days(v_wednesday)
			<< "\nThursday: " << solve_days(v_thursday)
			<< "\nFriday: " << solve_days(v_friday)
			<< "\nSaturday: " << solve_days(v_saturday)
			<< "\nSunday: " << solve_days(v_sunday)
			<< "\nDeclined: " << dis_count;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what();
	}
}