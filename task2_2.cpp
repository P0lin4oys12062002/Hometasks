#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <iterator>
#include <algorithm>

//По увеличению времени сортировки:
//1. array
//2. vector
//3. deque
//4. list

using namespace std;
using namespace chrono;

// шаблон функции для измерения времени сортировки контейнера
template<typename T>
auto measureSortingTime(T container)
{
    int startTime=clock();

    sort(container.begin(), container.end());

    int time = clock()-startTime;
    return (double)time/CLOCKS_PER_SEC;
}

// специализация шаблона для list
template<>
auto measureSortingTime(list<int> container)
{
    int startTime=clock();

    container.sort();

    int time = clock() - startTime;
    return (double)time/CLOCKS_PER_SEC;
}

int main()
{
    default_random_engine generator; //генератор случайных чисел
    uniform_int_distribution<int> distribution(0,10000); //равномерное распределение от 0 до 1000
    auto gen = [&distribution, &generator](){
                   return distribution(generator); // лямбда-функция, которая генерирует случайное число
               };

    //можно поэспериментировать с разными размерами контейнеров
    vector<int> v(100000);
    // заполнение вектора случайными числами
    generate(v.begin(), v.end(), gen);
    array<int, 100000> a;
    deque<int> d(100000);
    list<int> l(100000);
    // нам нужно, чтобы все контейнеры были запонены одинаковыми даннными
    // поэтому скопируем данные из вектора в другие контейнеры
    copy (v.begin(), v.end(), a.begin()); //копирование элементов вектора v в массив a
    copy (v.begin(), v.end(), d.begin());
    copy (v.begin(), v.end(), l.begin());
    //sort(v.begin(), v.end()); // сортировка у vector, array и deque
    //l.sort() // сортировка у list

    cout << "vector: " << measureSortingTime(v) << endl;
    cout << "array: " << measureSortingTime(a) << endl;
    cout << "deque: " << measureSortingTime(d) << endl;
    cout << "list: " << measureSortingTime(l) << endl;
    return 0;
}
