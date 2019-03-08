#include <stdio.h>

int map[9][9];
int w = 9;
int h = 9;

int Correct(int val, int min, int max)
{
	if(val < min)
		val = min;
	if(val > max)
		val = max;
		
	return val; 
}

int GetNeighborMineNum (int x, int y)
{
	if(map[y][x] == 1)
		return -1;

	int left = Correct(x-1, 0, 8);
	int right = Correct(x+1, 0, 8);
	int top = Correct(y-1, 0, 8);
	int bottom = Correct(y+1, 0, 8);
	
	int mineNum = 0;
	for(int countY=top; countY<=bottom; ++countY)
		for(int countX=left; countX<=right; ++countX)
			mineNum += map[countY][countX];
			
	return mineNum;
}

int main ()
{
	int x, y;
	
	for(int countY=0; countY<9; ++countY)
		for(int countX=0; countX<9; ++countX)
			scanf("%d", &(map[countY][countX]));
	scanf("%d%d", &y, &x);
	
	--x;
	--y;
	
	printf("%d", GetNeighborMineNum(x, y));
	
	return 0;
}
