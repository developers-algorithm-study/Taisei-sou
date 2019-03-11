#include <iostream>

int g_ValuesNum;
long long g_Values[100000];
long long g_MaximumResult;

void UpdateMaximumResult(long long maximumCandidate)
{
	if (maximumCandidate > g_MaximumResult)
		g_MaximumResult = maximumCandidate;
}

void Process_OptimizeRecursive(int idxLeft, int idxRight)
{
	if (idxLeft == idxRight)
	{
		UpdateMaximumResult(g_Values[idxLeft] * g_Values[idxLeft]);
	}
	else
	{
		int idxDividePoint = (idxLeft + idxRight)/2;

		long long inRangeMin = g_Values[idxDividePoint];
		long long inRangeSum = g_Values[idxDividePoint];
		long long inRangeMaximumResult = g_Values[idxDividePoint] * g_Values[idxDividePoint];

		int idxExtendToLeft = idxDividePoint-1;
		int idxExtendToRight = idxDividePoint+1;
		bool leftEnd = idxDividePoint < idxLeft;
		bool rightEnd = idxDividePoint > idxRight;

		while (leftEnd == false || rightEnd == false)
		{
			if (leftEnd == false && rightEnd == false)
			{
				long long leftExtendValue = g_Values[idxExtendToLeft];
				long long rightExtendValue = g_Values[idxExtendToRight];
				
				if (leftExtendValue > rightExtendValue)
				{
					inRangeSum += leftExtendValue;
					if (inRangeMin > leftExtendValue)
						inRangeMin = leftExtendValue;

					--idxExtendToLeft;
					if (idxExtendToLeft < idxLeft)
						leftEnd = true;
				}
				else
				{
					inRangeSum += rightExtendValue;
					if (inRangeMin > rightExtendValue)
						inRangeMin = rightExtendValue;

					++idxExtendToRight;
					if (idxExtendToRight > idxRight)
						rightEnd = true;
				}
			}
			else if(leftEnd == false)
			{
				long long leftExtendValue = g_Values[idxExtendToLeft];

				inRangeSum += leftExtendValue;
				if (inRangeMin > leftExtendValue)
					inRangeMin = leftExtendValue;

				--idxExtendToLeft;
				if (idxExtendToLeft < idxLeft)
					leftEnd = true;
			}
			else //rightEnd == false
			{
				long long rightExtendValue = g_Values[idxExtendToRight];

				inRangeSum += rightExtendValue;
				if (inRangeMin > rightExtendValue)
					inRangeMin = rightExtendValue;

				++idxExtendToRight;
				if (idxExtendToRight > idxRight)
					rightEnd = true;
			}
			UpdateMaximumResult(inRangeSum * inRangeMin);
		}
		Process_OptimizeRecursive(idxLeft, idxDividePoint);
		Process_OptimizeRecursive(idxDividePoint+1, idxRight);
	}
}

void Process_Optimize()
{
	Process_OptimizeRecursive(0, g_ValuesNum - 1);
}

void Input()
{
    std::cin>>g_ValuesNum;
    
    for(int count=0; count<g_ValuesNum; ++count)
        std::cin>>g_Values[count];
}

int main()
{
    Input();
	Process_Optimize();
	std::cout << g_MaximumResult ;
	return 0;
}
