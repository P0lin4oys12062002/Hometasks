#include <string>
#include <cstdio>
#include <iostream>
#include <map>
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "Russian");
	std::map<std::string, std::string> letters = {{"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"},
		{"д", "d"}, {"е", "e"}, {"ж", "gh"}, {"з", "z"},
		{"и", "i"}, {"й", "j"}, {"к", "k"}, {"л", "l"},
		{"м", "m"}, {"н", "n"}, {"о", "o"}, {"п", "p"},
		{"р", "r"}, {"с", "s"}, {"т", "t"}, {"у", "u"},
		{"ф", "f"}, {"х", "h"}, {"ц", "c"}, {"ч", "ch"},
		{"ш", "sh"}, {"щ", "sch"}, {"ы", "y"}, {"э", "e"},
		{"ю", "yu"}, {"я", "ya"}};

	std::string text;
	std::string new_text; //текст после транслитерации
	std::map<std::string, std::string>::iterator map_iterator = letters.end(); //итератор по словарю
	std::string buffer; //буфер для чтения символов
	while(true)
	{
		std::getline(std::cin, text);
		if(std::cin.eof()){return 1;} //выход по ctrl+D (Linux)
		for(std::string::iterator iter = text.begin(); iter != text.end(); ++iter) //итерация по тексту
		{
			buffer.push_back(*iter);
			map_iterator = letters.find(buffer);
			if(map_iterator == letters.end()) //если нет соответствия
			{
				std::cout << "incorrect symbol" << std::endl;
				return 1;
			}
			std::cout << map_iterator->second; //вывод соответствия
			buffer.clear();
		}
		std::cout << std::endl << std::endl;
	}
}
