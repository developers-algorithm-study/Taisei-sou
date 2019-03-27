#include <iostream>

long long GaussSum(long long n)
{
	return n*(n + 1) / 2;
}

long long  GetResult(long long distance)
{
	long long result = 0;

	long long remainDistance = distance;
	long long speed = 0;

	while (remainDistance > 0)
	{
		if (GaussSum(speed) == remainDistance)
		{
			result += speed;
			break;
		}
		else if (GaussSum(speed + 1) <= remainDistance)
		{
			++speed;
			remainDistance -= speed;
		}
		else if (GaussSum(speed) <= remainDistance)
		{
			remainDistance -= speed;
		}
		else if (GaussSum(speed - 1) <= remainDistance)
		{
			--speed;
			remainDistance -= speed;
		}

		++result;
	}

	return result;
}

void Test()
{
	long long input1, input2;
	std::cin >> input1 >> input2;

	long long result = GetResult(input2-input1);
	std::cout << result << "\n";
}

int main()
{
	long long testCaseNum;

	std::cin >> testCaseNum;
	
	for (long long count = 0; count< testCaseNum; ++count)
	{
		Test();
	}

	return 0;
}
