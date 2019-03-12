#include <iostream>

void Test() 
{
	int input;
	std::cin >> input;

	for (int countY = 0; countY < input; ++countY)
	{
		for (int countX = 0; countX < input; ++countX)
			std::cout << (countY % 2 == 0 ? countY * input + countX : countY * input + input - 1 - countX) + 1 << ' ';
		std::cout << std::endl;
	}
}

int main()
{
	Test();

	return 0;
}
