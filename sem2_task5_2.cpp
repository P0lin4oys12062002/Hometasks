#include <regex>
#include <string>
#include <iostream>
#include <fstream>

//YYYY.MM.DD

int main()
{
	std::string data;
	std::fstream read_text("datas");
	if(read_text.is_open())
	{
		while(getline(read_text, data))
		{
			std::regex address("^\\d{4}.(0[1-9]|1[0-2]).(0[1-9]|[12][0-9]|3[01])$");
			std::sregex_iterator pos(data.cbegin(), data.cend(), address);
			std::sregex_iterator end;
			for(; pos != end; ++pos){std::cout << pos->str() << std::endl;}
		}
		read_text.close();
		std::cout << "All matches detected" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Something went wrong" << std::endl;
		return 1;
	}
}
