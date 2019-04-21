#include <iostream>

using namespace std;

int *array;

int main ()
{
	int k, n, sum = 0;
	
	cin >> k >> n;
	
	array = new int[n];
	
	for(int count=0; count<k; ++count)
	{
		cin >> array[count];
		sum += array[count];	
	}
	
	int head = 0;
	for(int count=k; count<n; ++count)
	{
		sum = (sum+100007)%100007;
		array[count] = sum;
		sum -= array[head];
		sum += array[count];
		++head;
	}
	
	cout << array[n-1];
	
	return 0;
}
