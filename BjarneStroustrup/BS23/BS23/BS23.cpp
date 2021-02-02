#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>


//Exercise 0.1 --------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	std::ifstream in{ "file.txt" };
	if (!in)
		throw std::runtime_error("Cannot open the file");

	std::regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" };
	
	int lineno{ 0 };
	for (std::string line{}; std::getline(in, line);)
	{
		++lineno;
		std::smatch matches;
		if (std::regex_search(line, matches, pat))
		{
			std::cout << lineno << ": " << matches[0] << '\n';
			if (1 < matches.size() && matches[1].matched)
				std::cout << "\t:" << matches[1] << '\n';
		}
	}
}

//Exercise 1 --------------------------------------------------------------------------------------------------------------------------------------------------

using Line_iter = std::vector<std::string>::const_iterator;

class Message
{
private:
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2) : first{ p1 }, last{ p2 }{}
	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }
};

typedef std::vector<Message>::const_iterator  Mess_iter;

struct Mail_file
{
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;
	Mail_file(const std::string& n);
	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const std::string& n)
{
	std::ifstream in{ n };
	if (!in)
	{
		std::cerr << "No file " << n << '\n';
		std::exit(1);
	}

	for (std::string s; std::getline(in, s);)
		lines.push_back(s);

	auto first = lines.begin();
	for (auto p = lines.begin(); p != lines.end(); ++p)
	{
		if (*p == "----")
		{
			m.push_back(Message(first, p));
			first = p + 1;
		}
	}
}

int is_prefix(const std::string& s, const std::string& p)
{
	int n{ p.size() };
	if (std::string(s, 0, n) == p)
		return n;
	return 0;
}

bool find_from_addr(const Message* m, std::string& s)
{
	for(const auto& x : *m)
		if (int n = is_prefix(x, "From: "))
		{
			s = std::string(x, n);
			return true;
		}
	return false;
}

std::string find_subject(const Message* m)
{

}

main()
{
	Mail_file mfile("my_mail_file.txt");

	std::multimap<std::string, const Message*> sender;

	for (const auto& m : mfile)
	{
		std::string s;
		if (find_from_addr(&m, s))
			sender.insert(std::make_pair(s, &m));
	}

	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");

	for (auto p = pp.first; p != pp.second; ++p)
		std::cout << find_subject(p->second) << '\n';

}
