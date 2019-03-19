#include <stdio.h>

long long ResultTable[32][32];

void InitResultTable()
{
	for(int countY=0; countY<32; ++countY)
		for(int countX=0; countX<32; ++countX)
			ResultTable[countY][countX] = -1;
}

long long GetResult(int m, int n)
{
	int m2=m, n2=n;
	
	if(m < 1)
		return 0;
	
	if(m == 1)
		return n;
		
	--m;
	--n;
	
	long long result = 0;
	long long recursiveResult;
	
	if(ResultTable[n2][m2] == -1)
	{
		while(m<=n)
		{
			recursiveResult = GetResult(m, n);
			result += recursiveResult;
			ResultTable[n2][m2] = result;
			--n;
		}
	}
	else
		result = ResultTable[n2][m2];
		
	return result;
}

void Test()
{
	int m, n;
	
	//입력 
	scanf("%d%d", &m, &n);
	
	//처리 및 출력
	printf("%lld\n", GetResult(m,n));
}

int main ()
{
	int t;
	
	InitResultTable();
	
	//테스트 회수 입력 
	scanf("%d", &t);
	
	//테스트 진행 
	while(t>0)
	{
		Test();
		--t;
    }
    
	return 0;
}
