#include <set>
#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <random>

//сортировка вектора из N элементов быстрее, чем добавление N элементов в множество

int main()
{
	int startTime, time;

	//генератор чисел
	std::default_random_engine gen;
	std::uniform_real_distribution<double> dist(0.0,10000.0);

	//заполняем std::set и считаем время
	std::set<int> s;
	startTime = clock();
	
	for(int iter = 0; iter < 10000; ++iter)
	{
		s.insert(dist(gen));
	}

	time = clock() - startTime;
	std::cout << "set: " << (double)time/CLOCKS_PER_SEC << std::endl;

	//теперь создаем и сортируем вектор
	std::vector<int> v;
	for(int iter = 0; iter < 10000; ++iter)
	{
		v.push_back(dist(gen));
	}

	startTime = clock();
	std::sort(v.begin(), v.end());
	time = clock() - startTime;
//	for(int iter = 0; iter < v.size(); ++iter)
//	{
//		std::cout << v[iter] << std::endl;
//	}
        std::cout << "vector: " << (double)time/CLOCKS_PER_SEC << std::endl;
}
