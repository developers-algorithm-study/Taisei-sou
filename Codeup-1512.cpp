#include <stdio.h>

int Abs (int val)
{
	return val > 0 ? val : -val;
}

int main ()
{
	int size, x, y;
	scanf("%d%d%d", &size, &y, &x);
	
	--x;
	--y;
	
	for(int countY=0; countY<size; countY++)
	{
		for(int countX=0; countX<size; countX++)
		{
			printf("%d ", Abs(x-countX) + Abs(y-countY) + 1);
		}
		printf("\n");
	}
	
	return 0;
}
