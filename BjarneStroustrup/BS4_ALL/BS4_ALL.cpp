#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>


//Exercize 2 ----------

//int main()
//{
//	std::vector<double> vect;
//	for (double temp; std::cin >> temp; )
//		vect.push_back(temp);
//
//	std::sort(vect.begin(), vect.end());
//
//	if ((vect.size() & 2) == 0)
//		std::cout << "Mediana: " << (vect[(vect.size() / 2)] +
//			vect[(vect.size() / 2) - 1]) / 2;
//	else std::cout << "Mediana: " << vect[vect.size() / 2];
//}

//Exercize 3 -----------

//int main()
//{
//	std::vector<double> vect;
//	for (double temp; std::cin >> temp; )
//		vect.push_back(temp);
//
//	if (vect.size() == 0)
//  	 	throw std::runtime_error("Vector is empty");
//
//	double sum{}, min_dist{vect[0]}, max_dist{vect[0]}, avg{};
//
//	for (double d : vect)
//	{
//		sum += d;
//		if (d < min_dist)
//			min_dist = d;
//		if (d > max_dist)
//			max_dist = d;
//	}
//	avg = sum / vect.size();
//	std::cout << "Summary: " << sum << ", max: " << max_dist
//		<< ", min: " << min_dist << " average: " << avg;
//}

//Exercise 4 ----------

//?????????????

//Exercise 5 ----------

//int main()
//{
//	double num1, num2;
//	char oper;
//	while (1)
//	{
//		std::cout << "\nEnter 2 operands and an operator: ";
//		std::cin >> num1 >> num2 >> oper;
//		std::cin.ignore(1000, '\n');
//		if (std::cin.fail() || (oper != '+' && oper != '-' && oper != '/' && oper != '*'))
//		{
//			std::cout << "Wrong input\n";			
//			std::cin.clear();
//			std::cin.ignore(1000, '\n');
//			continue;
//		}
//
//		switch (oper)
//		{
//		case '+': std::cout << num1 << " + " << num2 << " = " << num1 + num2; break;
//		case '-': std::cout << num1 << " - " << num2 << " = " << num1 - num2; break;
//		case '/': std::cout << num1 << " / " << num2 << " = " << num1 / num2; break;
//		case '*': std::cout << num1 << " * " << num2 << " = " << num1 * num2; break;
//		}
//	}
//}

//Exercise 6 ----------

double get_user_number()
{
	double temp;
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
	char temp;
	std::cin >> temp;
	std::cin.ignore(100, '\n');
	return temp;
}

//int main()
//{
//	std::vector<std::string> str_vect = {"zero", "one", "two", "three", "four", "five",
//										 "six", "seven", "eight", "nine"};
//
//	int number{};
//	std::string str_number{};
//	bool flag{};
//	while (1)
//	{
//		try
//		{
//			std::cout << "Enter an integer: ";
//			number = get_user_number();
//			switch (number)
//			{
//			case 0: std::cout << str_vect[number]; break;
//			case 1: std::cout << str_vect[number]; break;
//			case 2: std::cout << str_vect[number]; break;
//			case 3: std::cout << str_vect[number]; break;
//			case 4: std::cout << str_vect[number]; break;
//			case 5: std::cout << str_vect[number]; break;
//			case 6: std::cout << str_vect[number]; break;
//			case 7: std::cout << str_vect[number]; break;
//			case 8: std::cout << str_vect[number]; break;
//			case 9: std::cout << str_vect[number]; break;
//			default: std::cout << "0 - 9 is expected\n";
//			}
//			std::cout << std::endl;
//
//			std::cout << "Enter a string number: ";
//			str_number = get_user_string();
//			flag = false;
//			for (int i = 0; i < str_vect.size(); i++)
//				if (str_number == str_vect[i])
//				{
//					std::cout << i << '\n';
//					flag = true;
//				}
//			if (!flag)
//				std::cout << "zero - nine is expected\n";
//		}
//		catch (std::exception& e)
//		{
//			std::cout << "Exception: " << e.what();
//		}
//	}
//}

//Exercise 7 ----------

//int main()
//{
//	std::vector<std::string> str_vect = { "zero", "one", "two", "three", "four", "five",
//												 "six", "seven", "eight", "nine"};
//	double num1{}, num2{};
//	std::string str_num1{}, str_num2{};
//	char choise{};
//	bool flag1{}, flag2{};
//	while (1)
//	{
//		num1 = num2 = 0;
//		flag1 = flag2 = false;
//		std::cout << "Digit(d) or string(s): ";
//		choise = get_user_char();
//
//		if (choise == 'd')
//		{
//			while (1)
//			{
//				std::cout << "\nEnter 2 numbers (0 - 9): ";
//				std::cin >> num1 >> num2;
//				std::cin.ignore(1000, '\n');
//				if (std::cin.fail() || num1 < 0 || num1 > 9 || num2 < 0 || num2 > 9)
//				{
//					std::cout << "Wrong input\n";
//					std::cin.clear();
//					std::cin.ignore(1000, '\n');
//					continue;
//				}
//				break;
//			}
//		}
//		else if (choise == 's')
//		{
//			while(1)
//			{
//				std::cout << "Enter the first string number: ";
//				str_num1 = get_user_string();
//				std::cout << "Enter the second string number: ";
//				str_num2 = get_user_string();
//				for (int i = 0; i < str_vect.size(); i++)
//				{
//					if (str_num1 == str_vect[i])
//					{
//						num1 = i;
//						flag1 = true;
//					}
//					if (str_num2 == str_vect[i])
//					{
//						num2 = i;
//						flag2 = true;
//					}
//				}
//				if (!flag1 || !flag2)
//				{
//					std::cout << "Wrong input.\n";
//					continue;
//				}
//				break;
//			}
//		}
//		else
//		{
//			std::cout << "Wrong letter\n";
//			continue;
//		}
//
//		while (1)
//		{
//			std::cout << "Enter an operator (+ - * /): ";
//			choise = get_user_char();
//			if (choise != '+' && choise != '-' && choise != '/' && choise != '*')
//			{
//				std::cout << "Wrong operator\n";
//				continue;
//			}
//			break;
//		}
//
//		switch (choise)
//		{
//		case '+': std::cout << num1 << " + " << num2 << " = " << num1 + num2; break;
//		case '-': std::cout << num1 << " - " << num2 << " = " << num1 - num2; break;
//		case '/': std::cout << num1 << " / " << num2 << " = " << num1 / num2; break;
//		case '*': std::cout << num1 << " * " << num2 << " = " << num1 * num2; break;
//		}
//		std::cout << std::endl;
//	}
//}

//Exercise 8 ----------

//int main()
//{
//	std::vector<int> v;
//	int cur_rice{ 1 }, prev_rice{}, count{ 1 };
//	int more1e3{1}, more1e6{1}, more1e9{1};
//	for (; cur_rice < 1000000000; cur_rice *= 2, count++)
//	{
//		if (cur_rice > 1000 && prev_rice < 1000)
//			std::cout << "You'll need " << count << " cells to get at least 1,000 rices\n";
//		if (cur_rice > 1000000 && prev_rice < 1000000)
//			std::cout << "You'll need " << count << " cells to get at least 1,000,000 rices\n";
//		prev_rice = cur_rice;
//	}
//	std::cout << "You'll need " << count << " cells to get at least 1,000,000,000 rices\n";
//}

//Exercise 9 ----------

//int main()
//{
//	int usual_int{1}, count{1};
//	double d{1.0};
//
//	for (; usual_int > 0; usual_int *= 2, count++);
//	std::cout << "The max amount of cells using int: " << --count;
//	count = 1;
//	for (; count < 64; d *= 2, count++);
//	std::cout << "\n64 cells contain " << d << " rices";
//}

//Exercise 10 ----------

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

int roll(int min, int max)
{
	std::uniform_int_distribution<> die{ min, max };
	return die(mersenne);
}

//constexpr int min = 0;
//constexpr int max = 2;
//
//int main()
//{
//	char choise{ 'y' };
//	do
//	{
//		switch (roll(min, max))
//		{
//		case 0: std::cout << "ROCK"; break;
//		case 1: std::cout << "PAPER"; break;
//		case 2: std::cout << "SCISSORS"; break;
//		default: std::cout << "hmm...smth went wrong!";
//		}
//		std::cout << "\nAgain?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//}

//Exercise 11 ----------

bool is_simple(int& num)
{
	for (int i = (num - 1); i > 1; i--)
	{
		if (num % i == 0)
			return false;
	}
	return num == 1? false : true;
}

//int main()
//{
//	std::vector<int> v_num;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (is_simple(i))
//			v_num.push_back(i);
//	}
//	for (int n : v_num)
//		std::cout << n << " ";
//}

//Exercise 12 ----------

//int main()
//{
//	int user_num{};
//	char choise{ 'y' };
//	std::vector<int> v_num;
//
//	do
//	{
//		std::cout << "Enter an integer: ";
//		user_num = get_user_number<int>();
//		for (int i = 1; i <= user_num; i++)
//		{
//			if (is_simple(i))
//				v_num.push_back(i);
//		}
//		for (int n : v_num)
//			std::cout << n << " ";
//		v_num.clear();
//
//		std::cout << "\nAgain?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//}

//Exercise 13 ----------

//int main()
//{
//	std::vector<int> v_num;
//	int spec_num{}, index{ 0 };
//	for (int i = 2; i <= 100; i++)
//		v_num.push_back(i);
//
//	for (; (v_num[index] * v_num[index]) <= 100; index++)
//	{
//		spec_num = v_num[index];
//		for (int i = index + 1; i < v_num.size(); i++)
//			if (v_num[i] % spec_num == 0)
//				v_num.erase(v_num.begin() + i);
//	}
//	for (int n : v_num)
//		std::cout << n << " ";
//}

//Exercise 14 ----------

//int main()
//{
//	int user_num{};
//	char choise{ 'y' };
//	std::vector<int> v_num;
//
//	do
//	{
//		while (1)
//		{
//			std::cout << "Enter an integer: ";
//			user_num = get_user_number<int>();
//			if (user_num < 2)
//			{
//				std::cout << "The smallest simple integer is 2\n";
//				continue;
//			}
//			break;
//		}
//
//		std::vector<int> v_num;
//		int spec_num{}, index{ 0 };
//		for (int i = 2; i <= user_num; i++)
//			v_num.push_back(i);
//
//		for (; (v_num[index] * v_num[index]) <= user_num; index++)
//		{
//			spec_num = v_num[index];
//			for (int i = index + 1; i < v_num.size(); i++)
//				if (v_num[i] % spec_num == 0)
//					v_num.erase(v_num.begin() + i);
//		}
//		for (int n : v_num)
//			std::cout << n << " ";
//		v_num.clear();
//
//		std::cout << "\nAgain?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//}

//Exercise 15 ----------

//int main()
//{
//	int user_num{};
//	char choise{ 'y' };
//	std::vector<int> v_num;
//
//	do
//	{
//		while (1)
//		{
//			std::cout << "Enter an integer and I'll show you the first \'n\' simple numbers: ";
//			user_num = get_user_number<int>();
//			if (user_num < 1)
//			{
//				std::cout << "Why are you using this program like that?\n";
//				continue;
//			}
//			break;
//		}
//
//		std::vector<int> v_num;
//		int spec_num{}, index{ 0 }, count{ 0 };
//		for (int i = 1; i > 0 && count < user_num; i++)
//		{
//			if (is_simple(i))
//			{
//				v_num.push_back(i);
//				count++;
//			}
//		}
//		for (int n : v_num)
//			std::cout << n << " ";
//		v_num.clear();
//
//		std::cout << "\nAgain?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//}

//Exercise 16 ----------

//int main()
//{
//	std::vector<int> vect;
//	int temp{}, count{}, max_count{}, number{}, moda{};
//	char choise{'a'};
//
//	do
//	{
//		std::cout << "Enter a positive integer: ";
//		temp = get_user_number<int>();
//		if (temp < 0)
//		{
//			std::cout << temp << " is NOT positive\n";
//			choise = 'y';
//			continue;
//		}
//		vect.push_back(temp);
//		std::cout << "Again?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//
//	if (vect.size() == 0)
//	{
//		std::cout << "There is no data";
//		std::exit(0);
//	}
//
//	for (int i = 0; vect.size() > 0;)
//	{
//		number = vect[i];
//		for (; i < vect.size(); i++)
//		{
//			if (vect[i] == number)
//			{
//				count++;
//				vect.erase(vect.begin() + (i--));
//			}
//		}
//		if (count > max_count)
//		{
//			max_count = count;
//			moda = number;
//		}
//		count = i = 0;
//	}
//	std::cout << "Moda " << moda << " was counted " << max_count << " times";
//}

//Exercise 17 ----------

//int main()
//{
//	std::vector<std::string> vect;
//	std::string temp{}, str{}, moda{}, max_str{}, min_str{};
//	int count{}, max_count{};
//	char choise{ 'a' };
//
//	do
//	{
//		std::cout << "Enter a string: ";
//		temp = get_user_string();
//		vect.push_back(temp);
//		std::cout << "Again?(y/n): ";
//		std::cin >> choise;
//		std::cin.ignore(1000, '\n');
//	} while (choise == 'y');
//
//	if (vect.size() == 0)
//	{
//		std::cout << "There is no data";
//		std::exit(0);
//	}
//
//	max_str = min_str = vect[0];
//
//	for (int i = 0; vect.size() > 0;)
//	{
//		str = vect[i];
//		max_str = str > max_str ? str : max_str;
//		min_str = str < min_str ? str : min_str;
//		for (; i < vect.size(); i++)
//		{
//			if (vect[i] == str)
//			{
//				count++;
//				vect.erase(vect.begin() + (i--));
//			}
//		}
//		if (count > max_count)
//		{
//			max_count = count;
//			moda = str;
//		}
//		count = i = 0;
//	}
//
//	std::cout << "Moda \'" << moda << "\' was counted " << max_count << " times.\n"
//		<< " max string: " << max_str << ", min string: " << min_str;
//}

//Exercise 18 ----------

//int main()
//{
//	double a{}, b{}, c{}, x1{}, x2{}, discriminant{};
//	std::cout << "In order to solve a quadratic equation (ax^2 + bx + c = 0)\n";
//	std::cout << "Enter \'a\': ";
//	a = get_user_number();
//	std::cout << "Enter \'b\': ";
//	b = get_user_number();
//	std::cout << "Enter \'c\': ";
//	c = get_user_number();
//
//	discriminant = (b * b) - (4 * a * c);
//
//	if (discriminant > 0)
//	{
//		x1 = (-b + std::sqrt(discriminant)) / (2 * a);
//		x2 = (-b - std::sqrt(discriminant)) / (2 * a);
//		std::cout << "Roots: x1 = " << x1 << ", x2 = " << x2;
//	}
//	else if (discriminant == 0)
//	{
//		x1 = x2 = -b / (2 * a);
//		std::cout << "Roots: x1 = x2 = " << x1;
//	}
//	else
//		std::cout << "There is no roots";
//}

//Exercise 19 ----------

//int main()
//{
//	std::vector<std::string> v_name;
//	std::vector<int> v_score;
//	std::string name{};
//	int score{};
//	bool flag{ true };
//
//	std::cout << "Enter a data (\'name\' score) or \'NoName 0\' to stop input: \n";
//	while (1)
//	{
//		flag = true;
//		std::getline(std::cin, name, ' ');
//		std::cin >> score;
//		std::cin.ignore(10, '\n');
//		if (name == "NoName" && score == 0)
//			break;
//		else
//		{
//			for (std::string nm : v_name)
//				if (name == nm)
//				{
//					std::cerr << "Error: " << name << " already exists.\n";
//					flag = false;
//				}
//			if (flag)
//			{
//				v_name.push_back(name);
//				v_score.push_back(score);
//			}
//		}
//	}
//	std::cout << "\nResult: ";
//	for (int i = 0; i < v_name.size(); i++)
//		std::cout << v_name[i] << " " << v_score[i] << '\n';
//}

//Exercise 20/21 ----------

//int main()
//{
//	std::vector<std::string> v_name;
//	std::vector<int> v_score;
//	std::string name{};
//	int score{};
//	bool flag{ true };
//	char choise{ 'a' };
//
//	std::cout << "Enter a data (\'name\' score) or \'NoName 0\' to stop input: \n";
//	while (1)
//	{
//		flag = true;
//		std::getline(std::cin, name, ' ');
//		std::cin >> score;
//		std::cin.ignore(10, '\n');
//		if (name == "NoName" && score == 0)
//			break;
//		else
//		{
//			for (std::string nm : v_name)
//				if (name == nm)
//				{
//					std::cerr << "Error: " << name << " already exists.\n";
//					flag = false;
//				}
//			if (flag)
//			{
//				v_name.push_back(name);
//				v_score.push_back(score);
//			}
//		}
//	}
//	
//
//	std::cout << "For searching by name enter 'n' or by score enter 's': ";
//	while (1)
//	{
//		std::cin >> choise;
//		std::cin.ignore(10, '\n');
//		if (choise == 'n')
//		{
//			std::cout << "Enter a name: ";
//			name = get_user_string();
//			for (int i = 0; i < v_name.size(); i++)
//				if (v_name[i] == name)
//				{
//					std::cout << v_name[i] << " " << v_score[i];
//					flag = false;
//				}
//			if (flag)
//				std::cout << name << " was not found";
//			break;
//		}
//		else if (choise == 's')
//		{
//			std::cout << "Enter a score: ";
//			score = get_user_number();
//			for (int i = 0; i < v_name.size(); i++)
//				if (v_score[i] == score)
//				{
//					std::cout << v_name[i] << " " << v_score[i];
//					flag = false;
//				}
//			if (flag)
//				std::cout << score << " was not found";
//			break;
//		}
//		else
//			std::cout << "n or s are expected\n";
//	}
//}