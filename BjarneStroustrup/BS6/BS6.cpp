#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

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

char get_user_char()
{
	char temp{};
	std::cin >> temp;
	std::cin.ignore(100, '\n');
	return temp;
}

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
constexpr int LIMIT = 4;
constexpr int LOW = 1;
constexpr int HEIGH = 4;

char roll(int min, int max)
{
	std::uniform_int_distribution<> die{ min, max };
	return die(mersenne);
}

//Exercise 8 -------------------------------------------

//bool is_unique(const std::vector<char>& v)
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
//void make_a_guess(std::vector<char>& out_v)
//{
//	std::string user_str{};
//	while(1)
//	{
//		user_str = get_user_string();
//		out_v.clear();
//		if (user_str.size() != LIMIT)
//			throw std::runtime_error("Wrong amount of characters");
//		for (int i = 0; i < LIMIT; i++)
//		{
//			if (user_str[i] < 'a' || user_str[i] > 'z')
//				throw std::runtime_error("Wrong symbol");
//			out_v.push_back(user_str[i]);
//		}
//
//		if (is_unique(out_v))
//			break;
//		else std::cout << "Only unique small characters are expected!\n";
//	}
//}
//
//int main()
//{
//	std::vector<char> v_sys;
//	std::vector<char> v_user;
//	int bulls{}, cows{};
//
//	try
//	{
//		while (1)
//		{
//			std::cout << "I came up a number...\n";
//			do
//			{
//				v_sys.clear();
//				for (int i = 0; i < LIMIT; i++)
//					v_sys.push_back(roll(LOW, HEIGH));
//			} while (!is_unique(v_sys));
//
//			/*for (auto c : v_num)
//				std::cout << c;*/
//
//			std::cout << "Make a guess: ";
//			while (1)
//			{
//				make_a_guess(v_user);
//				for (int i = 0; i < LIMIT; i++)
//				{
//					for (int j = 0; j < LIMIT; j++)
//					{
//						if (v_user[i] == v_sys[j] && i == j)
//						{
//							bulls++;
//							break;
//						}
//						else if (v_user[i] == v_sys[j])
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

//Exercise 9 -------------------------------------------

//std::string get_and_check_str()
//{
//	std::string temp{ get_user_string() };
//	if (temp.size() < LOW || temp.size() > HEIGH)
//		throw std::runtime_error("Wrong the number's size");
//
//	for (char ch : temp)
//		if (ch < '0' || ch > '9')
//			throw std::runtime_error("Wrong symbol");
//
//	return temp;
//}
//
//void display_num_digits(const std::vector<int> v)
//{
//	for (int i = (v.size() - 1); i >= 0; i--)
//	{
//		switch (i)
//		{
//		case 3: std::cout << v[i] << " thousand "; break;
//		case 2: std::cout << v[i] << " hundred "; break;
//		case 1: std::cout << v[i] << " ten "; break;
//		case 0: std::cout << v[i] << " one "; break;
//		}
//	}
//}
//
//int main()
//{
//	try
//	{
//		std::string user_str{};
//		std::vector<int> v_num;
//
//		std::cout << "Enter your number(0-9999): ";
//		user_str = get_and_check_str();
//
//		for (int i = user_str.size() - 1; i >=0; i--)
//			v_num.push_back(user_str[i] - '0');
//
//		display_num_digits(v_num);
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "Exception: " << e.what();
//	}
//}

//Exercise 10 -------------------------------------------

//permutation
//combination

int fact(int num)
{
	if (num < 0)
		throw std::runtime_error("Cannot solve factorial of negative integer");

	int sum{1};
	for (int i = num; i > 0; i--)
	{
		sum *= i;
		if (sum < 0)
			throw std::runtime_error("Overflow. Cannot solve factorial of this number");
	}

	return sum;
}

int solve_permutation(int set, int subset)
{
	if (set < subset)
		throw std::runtime_error("Set cannot be less than Subset");

	return (fact(set) / fact(set - subset));
}

int solve_combination(int set, int subset)
{
	return solve_permutation(set, subset) / fact(subset);
}

int main()
{
	try
	{
		std::cout << "Enter a size of a set: ";
		int set{ get_user_number<int>() };
		std::cout << "Enter a size of a subset: ";
		int subset{ get_user_number<int>() };

		std::cout << "To solve a permutation enter \'p\' or "
			<< " a combination enter \'c\' ('e' to exit): ";
	
	
		while (1)
		{
			switch (get_user_char())
			{
			case 'p': std::cout << "Probable amount of permutations: " << solve_permutation(set, subset); break;
			case 'c': std::cout << "Probable amount of combinations: " << solve_combination(set, subset); break;
			case 'e': std::exit(0);
			default: std::cout << "Wrong letter. Try again: "; continue;
			}
			break;
		}
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what();
	}
}