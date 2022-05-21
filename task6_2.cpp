#include <fstream>
#include <string>
#include <iostream>

int main()
{
	//объявление переменных
	std::ifstream file;
	size_t lineLen;
	int position;
	std::string line;

	//подготовка к работе с файлом
	file.open("62Test");
	if(!file.is_open())
        {
                throw std::runtime_error("error while reading file");
        }

	std::cin >> position;
	if(position == 1)
	{
		std::getline(file, line);
		std::cout << line << std::endl;
	}
	else
	{
		std::getline(file, line);
		lineLen = line.size() + 1;
		line.clear();

		file.seekg((position - 2) * lineLen, std::ios::cur);
		std::getline(file, line);
		std::cout << line << std::endl;
	}
}
