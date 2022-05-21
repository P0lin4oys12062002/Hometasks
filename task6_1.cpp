#include <fstream>
#include <string>
#include <stdexcept>

int main()
{
	//объявление переменных
	std::ifstream ffrom;
	std::ofstream fto;
	std::string line;
	bool flag{false}; //true, если встретилось начало многострочного комментария

	//подготовка к работе с файлами
	ffrom.open("readfrom");
	fto.open("writeto");
	if(!ffrom.is_open())
	{
		throw std::runtime_error("error while reading file");
	}

	if(!fto.is_open())
	{
		throw std::runtime_error("error while writing to file");
	}

	//чтение и запись
	while(!ffrom.eof())
	{
		line.clear();
		std::getline(ffrom, line);
//		std::cout << line << std::endl;
		if(line.find("//") == 0)
		{
			continue;
		}
		if(line.find("/*") == 0)
		{
			flag = true;
			continue;
		}
		if(line.find("*/") == line.size() - 2)
		{
			flag = false;
			continue;
		}

		if(!flag)
		{
//			std::cout << "written!" << std::endl;
			fto.write(line.c_str(), line.size());
			fto.write("\n", 1);
		}
	}

	//завершение работы
	ffrom.close();
	fto.close();
}
