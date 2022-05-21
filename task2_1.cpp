#include <iostream>
#include <vector>
#include <random>

using namespace std;

//установим, что размер вектора увеличивается на 1 при добавлении каждого нового элемента,
//при этом емкость вектора удваивается, когда не остается памяти для добавления нового элемента.
//Это позволяет значительно ускорить скорость работы с вектором, т.к. содержимое вектора не приходится копировать каждый раз.
//Таким образом, добавление элемента за O(1) в среднем, за O(n) в худшем случае.

int main()
{
    default_random_engine gen; //генератор случайных чисел
    //равномерное распределение от 0 до 10.0
    uniform_real_distribution<double> dist(0.0,10.0);
    vector<double> v1;

    //1. Определим, как меняется емкость вектора при добавлении элементов

    cout << "size: " << v1.size() << " capacity: " << v1.capacity() << std::endl;
    for(int iter = 0; iter < 30; ++iter)
    {
            v1.push_back(dist(gen));
            cout << "size: " << v1.size() << " capacity: " << v1.capacity() << std::endl;
    }

    vector<int> v2;

    /*2. Определим, как меняется емкость вектора при добавлении элементов, если установлена
         начальная емкость */

    v2.reserve(5);
    cout << "capacity: " << v2.capacity() << std::endl;
    for(int iter = 0; iter < 30; ++iter)
    {
            v2.push_back(dist(gen));
            cout << "capacity: " << v2.capacity() << std::endl;
    }

    return 0;
}
