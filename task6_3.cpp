#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

//используется <dirent.h>, чтобы программа быстро работала на больших входах

void walk_recursive(std::string const &dirname, std::vector<std::string> &ret, std::vector<std::string>& dirs)
{
	DIR *dir = opendir(dirname.c_str());
	if (dir == nullptr) 
	{
//        	perror(dirname.c_str());
        	return;
    	}
    	for (dirent *de = readdir(dir); de != NULL; de = readdir(dir)) {
        	if (strcmp(".",de->d_name) == 0 || strcmp("..", de->d_name) == 0) continue;
        	if (de->d_type != DT_DIR)
		{
			ret.push_back(dirname + "/" + de->d_name);
		}
		else if (de->d_type == DT_DIR)
			dirs.push_back(dirname + "/" + de->d_name);
			walk_recursive(dirname + "/" + de->d_name, ret, dirs);
   	 }
   	 closedir(dir);
}

int main(int argc, char* argv[])
{
	//обработка исключения
	if(argc == 1)
	{
		throw std::runtime_error("Error: empty input");
	}

	//инициализация стартовой директории
	std::string dir = std::string(argv[1]);
	std::vector<std::string> ret;
	std::vector<std::string> dirs;

	//заполняем ret по ссылке
	walk_recursive(dir, ret, dirs);

	//распечатка информации о директориях
        for(int iter = 0; iter < dirs.size(); ++iter)
        {
                struct stat st;
                std::cout << "DIRECTORY: " << dirs[iter] << std::endl;
                stat (dirs[iter].c_str(), &st);
                time_t t = st.st_ctim.tv_sec;
                std::cout << "LAST UPDATE: " << ctime(&t) << std::endl << std::endl;
        }

	//распечатка информации о файлах
	for(int iter = 0; iter < ret.size(); ++iter)
	{
		struct stat st;
		std::cout << "FILE: " << ret[iter] << std::endl;
		stat (ret[iter].c_str(), &st);
                time_t t = st.st_ctim.tv_sec;
                std::cout << "LAST UPDATE: " << ctime(&t) << std::endl << std::endl;
	}
}
