#include <iostream>

long long g_ResultTable1[10];

void InitResultTable()
{
	for (int count = 0; count < 10; ++count)
	{
		g_ResultTable1[count] = 0;
	}
}

void Process1(int n)
{
	int mod;
	while (n > 0)
	{
		mod = n % 10;
		++g_ResultTable1[mod];
		n /= 10;
	}
}

int GetResult1(int n)
{
	for (int count = 1; count <= n; ++count)
	{
		Process1(count);
	}
	return 0;
}

void PrintResultTable(long long *resultTable)
{
	for (int count = 0; count < 10; ++count)
	{
		printf("%lld ", resultTable[count]);
	}
}

int main()
{
	InitResultTable();
	GetResult1(999999);
	PrintResultTable(g_ResultTable1);

	return 0;
}
