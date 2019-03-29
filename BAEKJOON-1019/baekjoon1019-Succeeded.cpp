#include <iostream>

long long g_ResultTable[10];

void InitResultTable()
{
	for (int count = 0; count < 10; ++count)
	{
		g_ResultTable[count] = 0;
	}
}

int GetResult(const int n)
{
	const long long limit = 1000000000L;
	long long iter = limit;

	long long quotient, remained, over, under;

	long long calcTable[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	while (iter>0)
	{
		//현재 단계의 몫과 나머지 구함
		quotient = n / iter;
		remained = n % iter;
		
		//몫이 유효할 때
		if (quotient > 0)
		{
			//초과값 구함
			over = quotient / 10;
			//언더값 구함
			under = quotient % 10;
			
			//오버 채우기 확정
			for (int count = 0; count<10; ++count)
			{
				/*if (count == 0 && over > 0)
					calcTable[count] += iter * (over - 1);
				else*/
					calcTable[count] += (quotient -1)/10 * iter;
			}

			//오버 채우기 미확정
			for (int count = 1; count <= 10; ++count)
			{
				if (count % 10 == under)
				{
					calcTable[count % 10] += remained + 1;
					break;
				}
				else
				{
					calcTable[count] += iter;
				}
			}
		}
		iter /= 10;
	}

	for (int count = 0; count < 10; ++count)
	{
		g_ResultTable[count] = calcTable[count];
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

	int input;
	std::cin >> input;

	GetResult(input);
	PrintResultTable(g_ResultTable);
	
	return 0;
}
