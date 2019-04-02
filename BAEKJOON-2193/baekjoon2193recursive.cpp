#include <iostream>

int g_CaseNum = 0;

void Recursive(bool prevIsOne, int level)
{
	if (level <= 0)
	{
		++g_CaseNum;
		return;
	}

	if (prevIsOne == false)
		Recursive(true, level - 1);
	Recursive(false, level - 1);
}

int GetResult(int n)
{
	g_CaseNum = 0;
	Recursive(true, n - 1);

	return g_CaseNum;
}

int main()
{
	int input;
	std::cin >> input;
	std::cout<<GetResult(input)<<std::endl;
  
	return 0;
}
