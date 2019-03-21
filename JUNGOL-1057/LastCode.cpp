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

int main ()
{
    long long input;
    
    scanf("%lld", &input);
    
    printf("%lld", GetResult(input));
    
	return 0;
}
