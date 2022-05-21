#include <iostream>
#include <thread>
#include <random>
#include <functional>
#include <cstdlib>

bool inCircle(double x, double y, double radius) //проверка на принадлежность кругу
{
	switch(x*x + y*y <= radius*radius)
	{
		case true: return true;
		case false: return false;
	}
}

void genDots(int radius, int quantity, int* result) //генерирует точки и проверяет на попадание в круг
{
	int numInCircle{0}; //число точек в круге
	
	for(int iter = 0; iter < quantity; ++iter) //генерация [quantity] точек
	{
		double x = std::rand() % radius;
		double y = std::rand() % radius;

		std::cout << x << " " << y << std::endl;
	
		switch(inCircle(x, y, radius))
		{
			case true:
				++numInCircle;
				break;
			case false:
				break;
		}
	}
	*result += numInCircle;
}

int main(int argc, char* argv[]) //первым параметром передаем радиус круга, вторым - число точек, третьим - число потоков
{
	int radius = std::atoi(argv[1]);
	int dotNum = std::atoi(argv[2]);
	int thrNum = std::atoi(argv[3]);
	int result{0};

	std::srand(time(0)); //инициализация рандомайзера

	std::vector<std::thread> threads;
	for(int iter = 0; iter < thrNum; ++iter){threads.emplace_back(genDots, radius, int(dotNum/thrNum), &result);} //инициализация потоков
	for(int iter = 0; iter < thrNum; ++iter){threads[iter].join();}
	std::cout << 4 * (double) result / (double)dotNum << std::endl;
}
