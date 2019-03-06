// CppConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//


#include "stdafx.h"

#include <stdio.h>

int main()
{
	int inputNum;
	int *inputBuffer;

	scanf("%d", &inputNum);
	inputBuffer = new int[inputNum];
	for (int count = 0; count < inputNum; ++count)
	{
		scanf("%d", inputBuffer + count);
	}

	for (int countY = 0; countY < inputNum; ++countY)
	{
		for (int countX = 0; countX < inputNum; ++countX)
		{
			printf("%d ", inputBuffer[(countX + countY) % inputNum]);
		}
		printf("\n");
	}

	delete[] inputBuffer;

	return 0;
}