#include <vector>
#include <iostream>

int main()
{
	std::vector<int> ForArray = {3, 0, 2, 0, 4};
	int volume = 0;

	//найдем абсолютный максимум высоты
	int maxHeight = ForArray[0];
	int maxHeightIndex = 0;
	for(int iter = 0; iter < ForArray.size(); ++iter)
	{
		if(ForArray[iter] > maxHeight)
		{
			maxHeight = ForArray[iter];
			maxHeightIndex = iter;
		}
	}

	//теперь пройдем слева до абсолютного максимума
	int leftBorder = 0;
	for(int iter = 1; iter < maxHeightIndex; ++iter)
	{
		int difference = ForArray[leftBorder] - ForArray[iter];
		if(difference >=0)
		{
			volume += difference;
		}
		else
		{
			leftBorder = iter;
		}
	}

	//теперь пройдем справа до абсолютного максимума
	int rightBorder = ForArray.size() - 1;
	for(int iter = rightBorder; iter > maxHeightIndex; --iter)
	{
		int difference = ForArray[rightBorder] - ForArray[iter];
		if(difference >= 0)
		{
			volume += difference;
		}
		else
		{
			rightBorder = iter;
		}
	}

	std::cout << volume << std::endl;
}
