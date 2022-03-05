#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int generator(){return rand() % 10;}
void print(std::vector<int> sequence)
{
	for(std::cout << "actual array values: "; auto element: sequence)
		std::cout << element << " ";
	std::cout << "\n";
}
bool ret_true(int value){return true;}
bool if_negative(int value){return (value < 0);}

int main()
{
	//первая задача
	std::vector<int> sequence = {1,2,3,4,5,6,7,8,9,10};
	int input;
	while(std::cin >> input){sequence.push_back(input);}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(sequence.begin(), sequence.end(), std::default_random_engine(seed));
	std::sort(sequence.begin(), sequence.end());
	std::vector<int>::iterator last = std::unique(sequence.begin(), sequence.end());
	sequence.erase(last, sequence.end());
	print(sequence);

	//вторая задача
	std::cout << "minimun: " << sequence[0] << std::endl;
	std::cout << "maximum: " << sequence[sequence.size() - 1] << std::endl;
	std::transform(sequence.begin(), sequence.end(), sequence.begin(),
			[](int value) -> int{return value*value;});
	print(sequence);

	//третья задача
	std::cout << std::endl;
	std::vector<int> sec_sequence(sequence.size());
	std::vector<int> third_sequence;
	std::generate(sec_sequence.begin(), sec_sequence.end(), generator);
	print(sec_sequence);
	std::cout << "sum in second array: " << std::accumulate(sec_sequence.begin(), sec_sequence.end(), 0) 
		<< std::endl;
	std::replace_if(sec_sequence.begin(), sec_sequence.begin()+5, ret_true, 1);
	print(sec_sequence);
	std::transform(sequence.begin(), sequence.end(), sec_sequence.begin(),
			std::back_inserter(third_sequence), std::minus<int>());
	print(third_sequence);
	
	//четвертая задача
	std::cout << std::endl;
	std::replace_if(third_sequence.begin(), third_sequence.end(), if_negative, 0);
	print(third_sequence);
}
