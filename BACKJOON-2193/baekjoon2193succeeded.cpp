#include <iostream>

long long g_ResultTable[100][2] = {};

long long GetResult(int n)
{
	g_ResultTable[0][0] = 1;
	g_ResultTable[0][1] = 1;
	for (int count = 1; count <= n; ++count)
	{
		g_ResultTable[count][0] = g_ResultTable[count - 1][0] + g_ResultTable[count - 1][1];
		g_ResultTable[count][1] = g_ResultTable[count - 1][0];
	}

	return g_ResultTable[n-1][1];
}

int main()
{
	int input;
	std::cin >> input;

	std::cout << GetResult(input) << std::endl;
	
	return 0;
}
