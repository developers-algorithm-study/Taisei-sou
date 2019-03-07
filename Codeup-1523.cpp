#include <stdio.h>

int map[9][9];
int w = 9;
int h = 9;

enum { NONE = 0, BUSH = 1, WAD = 2, WADSIGHT = 3 };

int Correct(int val, int min, int max)
{
	if(val < min)
		val = min;
	if(val > max)
		val = max;
		
	return val; 
}

void BushToWadSight(int x, int y)
{
	if(map[y][x] == BUSH)
	{
		map[y][x] = WADSIGHT;
		BushToWadSight(x-1, y);
		BushToWadSight(x, y-1);
		BushToWadSight(x+1, y);
		BushToWadSight(x, y+1);
	}
}

void Wad(int x, int y)
{
	int left = Correct(x-2, 0, 8);
	int top = Correct(y-2, 0, 8);
	int right =  Correct(x+2, 0, 8);
	int bottom = Correct(y+2, 0, 8);
	
	for(int countY=top; countY<=bottom; ++countY)
	{
		for(int countX=left; countX<=right; ++countX)
		{
			if(map[countY][countX] != BUSH)
				map[countY][countX] = WADSIGHT;
		}
	}
	if(map[y][x] == BUSH)
	{
		BushToWadSight(x, y);
	}
	map[y][x] = WAD;
}

void Lense(int x, int y)
{
	int left = Correct(x-2, 0, 8);
	int top = Correct(y-2, 0, 8);
	int right =  Correct(x+2, 0, 8);
	int bottom = Correct(y+2, 0, 8);
	
	bool foundWad = false;
	
	for(int countY=top; countY<=bottom; ++countY)
	{
		for(int countX=left; countX<=right; ++countX)
		{
			if(map[countY][countX] == WAD)
			{
				foundWad = true;
			}
			else if(map[countY][countX] == WADSIGHT)
				map[countY][countX] = NONE;
		}
	}
	
	if(foundWad)
	{
		for(int countY=0; countY<9; ++countY)
		{
			for(int countX=0; countX<9; ++countX)
			{
				map[countY][countX] = NONE;
			}
		}
	}
}

void Bush(int left, int top, int right, int bottom)
{
	for(int countY=top; countY<=bottom; ++countY)
	{
		for(int countX=left; countX<=right; ++countX)
		{
			map[countY][countX] = BUSH;
		}
	}
} 

int GetSight()
{
	int sight = 0;
	for(int countY=0; countY<9; ++countY)
	{
		for(int countX=0; countX<9; ++countX)
		{
			if(map[countY][countX] == WAD || map[countY][countX] == WADSIGHT)
				++sight;
		}
	}
	
	return sight;
}

int main ()
{
	int a1, a2, b1, b2, c1, c2, d1, d2;
	scanf("%d%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
	
	--a1, --a2, --b1, --b2, --c1, --c2, --d1, --d2;
	
	Bush(c1, c2, d1, d2);
	Wad(a1, a2);
	Lense(b1, b2);
	
	printf("%d", GetSight());
	
	return 0;
}
