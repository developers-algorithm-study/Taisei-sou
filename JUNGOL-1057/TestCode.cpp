#include <stdio.h>
#include <math.h>

long long GetResult (long long input)
{
	long long sqrtedInput = sqrt(input*2);
	
	long long step2 = sqrtedInput * (sqrtedInput + 1) / 2 ; 

	if(step2 < input)
		return sqrtedInput + 1;
	return sqrtedInput;
}

long long GetResult2 (long long input)
{
	long long sum = 0;
	long long n = 1;
	
	while(true)
	{
		sum += n;
		
		if(sum>=input)
		{
			return n;
		}
		
		++n;
	}
	
	return -1;
}

int main ()
{
    long long input;
    
    long long result1, result2;
    
    for(int count=0; count< 100000; ++count)
    {
    	for(int count2=0; count2< 10; ++count2)
    	{
    		result1 = GetResult(count*10 + count2 + 1);
    		result2 = GetResult2(count*10 + count2 + 1);
			if(result1!=result2)
			{
				printf("Error");
				getchar();
			}
		}
		printf("\n");
		
	}
    
	return 0;
}
