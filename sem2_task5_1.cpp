#include <regex>
#include <string>
#include <iostream>
#include <fstream>

int main()
{
	std::string data;
	std::ifstream read_text("adr");
	if(read_text.is_open()) //если файл открыт, осуществляется чтение
	{
		while(getline(read_text, data))
		{
			std::regex address("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); //регулярное выражение
			std::sregex_iterator pos(data.cbegin(), data.cend(), address);
			std::sregex_iterator end;
			for(; pos != end; ++pos){std::cout << pos->str(4)<< pos->str(5) << std::endl;}
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
