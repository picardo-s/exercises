#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//int main()
//{
//    //int birth_year{ 1994 };
//    //std::cout << std::showbase << birth_year << '\t' << std::hex << birth_year <<
//    //    '\t' << std::oct << birth_year;
//    //std::cout << '\t' << std::dec << 25 << '\n';
//    //int a{}, b{}, c{}, d{};
//    //std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
//    //std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
//    //std::cout << std::setprecision(1);
//    //std::cout << std::showbase;
//    //std::cout << std::defaultfloat << 1234567.89 << ' ' <<
//    //    std::fixed << 1234567.89 << ' ' << std::scientific << 1234567.89 << '\n';
//    //std::cout << 1234567.89;
//
//    //std::cout << "Kondratchyk" << std::setw(20) <<
//    //    "Dzyanis" << std::setw(20) << "8491855" << std::setw(25) << "axelrevenge@gmail.com" << '\n';
//    //std::cout << "Romanteeva" << std::setw(20) <<
//    //    "Valentina" << std::setw(20) << "7041012" << std::setw(25) << "vkoltok95@gmail.com" << '\n';
//    //std::cout << "Jorjie" << std::setw(20) <<
//    //    "Dert" << std::setw(20) << "6661313" << std::setw(25) << "jjd@gmail.com";
//}

//Exercise 1 -------------------------------------------------------------------------------------------------

//int main()
//{
//	std::ifstream in_file{ "UPPER.txt" };
//	if (!in_file)
//		throw std::runtime_error("Cannot open the in_file");
//
//	std::ofstream out_file{ "lower.txt" };
//	if (!out_file)
//		throw std::runtime_error("Cannot open the out_file");
//
//	for (char ch; in_file.get(ch);)
//	{
//		ch = tolower(ch);
//		out_file << ch;
//	}
//
//	if (in_file.eof() && out_file)
//		std::cout << "Success";
//	else if (!in_file || !out_file)
//		std::cout << "Something went wrong";
//}

//Exercise 2 -------------------------------------------------------------------------------------------------

//void print_str(const std::string& str, const std::string& word, int count)
//{
//	std::vector<std::string> v;
//	std::stringstream ss{ str };
//	for (std::string s; ss >> s;)
//		v.push_back(s);
//	for(auto& s: v)
//		if (s == word)
//		{
//			std::cout << "#" << count << ": " << str << '\n';
//			break;
//		}
//}
//
//int main()
//{
//	std::string input_string{}, file_name{}, word{}, line{};
//	std::cout << "Enter an file name and a word: ";
//	std::getline(std::cin, input_string);
//
//	std::stringstream ss{ input_string };
//	ss >> file_name >> word;
//
//	std::ifstream file{ file_name };
//	if (!file)
//		throw std::runtime_error("Cannot open the file");
//
//	int count{ 1 };
//	while (file)
//	{
//		std::getline(file, line);
//		print_str(line, word, count++);
//	}
//	if (file.eof())
//		std::cout << "\nSuccess";
//	else throw std::runtime_error("Error");
//}

//Exercise 3 -------------------------------------------------------------------------------------------------

//bool isVowel(char ch)
//{
//	ch = tolower(ch);
//	switch (ch)
//	{
//	case 'e': case 'u': case 'i':
//	case'o': case 'a':
//		return true;
//		break;
//	}
//	return false;
//}
//
//int main()
//{
//	std::ifstream in_file{ "UPPER.txt" };
//	if (!in_file)
//		throw std::runtime_error("Cannot open the in_file");
//
//	std::ofstream out_file{ "lower.txt" };
//	if (!out_file)
//		throw std::runtime_error("Cannot open the out_file");
//
//	for (char ch; in_file.get(ch);)
//		if(!isVowel(ch))
//			out_file << ch;
//
//	if (in_file.eof() && out_file)
//		std::cout << "Success";
//	else if (!in_file || !out_file)
//		std::cout << "Something went wrong";
//}

//Exercise 4 -------------------------------------------------------------------------------------------------

//enum class scale
//{
//	dec, oct, hex
//};
//
//scale define_scale(const std::string& str)
//{
//	if (str.size() >= 3)
//	{
//		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
//			return scale::hex;
//		else if (str[0] == '0')
//			return scale::oct;
//		else return scale::dec;
//	}
//	if (str.size() >= 2 && str[0] == '0')
//		return scale::oct;
//	else return scale::dec;
//	
//	return scale::dec;
//}
//
//int main()
//{
//	int num{};
//	std::stringstream ss;
//	std::string user_str{};
//	while (true)
//	{
//		std::cin >> user_str;
//		//std::getline(std::cin, user_str);
//		ss.str(user_str);
//		switch (define_scale(user_str))
//		{
//		case scale::dec:
//			std::cout << "(dec)" << " turns in dec ";
//			ss >> num;
//			break;
//		case scale::oct:
//			std::cout << "(oct)" << " turns in dec ";
//			ss >> std::oct >> num;
//			break;
//		case scale::hex:
//			std::cout << "(hex)" << " turns in dec ";
//			ss >> std::hex >> num;
//			break;
//		}
//		std::cout << num << '\n';
//		ss.clear();
//	}
//}

//Exercise 5 -------------------------------------------------------------------------------------------------

