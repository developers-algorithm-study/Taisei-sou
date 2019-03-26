#include <iostream>

int GaussSum(int n)
{
	return n*(n + 1) / 2;
}

int GetResult(int distance, int speed=0)
{
	int result = 2147483647;
	int remainDistance = distance;
	int speed2, resultGaussSum;

	if (distance == 0 && speed == 1)
		return 0;

	//속도가 빨라질 때
	if (distance >= (resultGaussSum = GaussSum(speed+1)))
	{
		speed2 = speed + 1;
		int resultInc = GetResult(distance - speed2, speed2);
		if (result > resultInc)
			result = resultInc;
	}

	//속도가 유지될 때
	if (speed > 0 && distance >= (resultGaussSum = GaussSum(speed)))
	{
		speed2 = speed;
		int resultNonwork = GetResult(distance - speed2, speed2);
		if (result > resultNonwork)
			result = resultNonwork;
	}

	//속도가 줄어들 때
	if (speed > 1 && distance >= (resultGaussSum = GaussSum(speed-1)))
	{
		speed2 = speed - 1;
		int resultDec = GetResult(distance - speed2, speed2);
		if (result > resultDec)
			result = resultDec;
	}

	return result+1;
}

void Test()
{
	int input1, input2;
	std::cin >> input1 >> input2;

	int result = GetResult(input2-input1);
	std::cout << result << "\n";
}

int main()
{
	int testCaseNum;

	std::cin >> testCaseNum;
	
	for (int count = 0; count< testCaseNum; ++count)
	{
		Test();
	}

	return 0;
}
