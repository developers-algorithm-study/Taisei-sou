#include <stdio.h>

struct BuildingInfo
{
	int buildingTreeCount;
	int buildingTime;
	int *buildingTree;

	int calcedTime;
	bool isCalced;
};

int *buildTreeBuffer = NULL;
BuildingInfo *buildInfo = NULL;

void AddBuildingTree(BuildingInfo *buildingInfo, int nextLevelBuildingNum)
{
	buildingInfo->buildingTree[buildingInfo->buildingTreeCount] = nextLevelBuildingNum;
	++buildingInfo->buildingTreeCount;
}

int fastestPathLength;
int targetBuildingNum;

int Recursive(int enterBuildingNum, int length)
{
	int buildingTreeCount = buildInfo[enterBuildingNum].buildingTreeCount;
	int *builingTree = buildInfo[enterBuildingNum].buildingTree;
	length += buildInfo[enterBuildingNum].buildingTime;

	int prevTechBuildingMax = 0;
	int prevTechBuildingResult = 0;

	if (buildInfo[enterBuildingNum].isCalced == true)
		return buildInfo[enterBuildingNum].calcedTime;

	for (int count = 0; count<buildingTreeCount; count++)
	{
		if (buildInfo[builingTree[count]].isCalced == true)
		{
			if (buildInfo[builingTree[count]].calcedTime > prevTechBuildingMax)
				prevTechBuildingMax = buildInfo[builingTree[count]].calcedTime;
		}
		else
		{
			prevTechBuildingResult = Recursive(builingTree[count], length);
			if (prevTechBuildingResult > prevTechBuildingMax)
				prevTechBuildingMax = prevTechBuildingResult;
		}
	}


	if (length + prevTechBuildingMax > fastestPathLength)
	{
		fastestPathLength = length + prevTechBuildingMax;
	}

	buildInfo[enterBuildingNum].isCalced = true;
	buildInfo[enterBuildingNum].calcedTime = buildInfo[enterBuildingNum].buildingTime + prevTechBuildingMax;

	return buildInfo[enterBuildingNum].buildingTime + prevTechBuildingMax;
}

int Test()
{
	int buildingNum, buildingTreeSize;

	//Inputing
	scanf("%d%d", &buildingNum, &buildingTreeSize);

	//Memory allocating
	buildTreeBuffer = new int[buildingNum * buildingTreeSize];
	buildInfo = new BuildingInfo[buildingNum];

	for (int count = 0; count<buildingNum; ++count)
	{
		buildInfo[count].buildingTree = buildTreeBuffer + buildingTreeSize * count;
		buildInfo[count].buildingTreeCount = 0;
		buildInfo[count].isCalced = false;
		buildInfo[count].calcedTime = 0;
		scanf("%d", &(buildInfo[count].buildingTime));
	}

	int prevBuildingNum, nextBuildingNum;
	for (int count = 0; count<buildingTreeSize; ++count)
	{
		scanf("%d%d", &prevBuildingNum, &nextBuildingNum);
		--prevBuildingNum;
		--nextBuildingNum;
		//AddBuildingTree(buildInfo + prevBuildingNum, nextBuildingNum);
		//Reverse Teching
		AddBuildingTree(buildInfo + nextBuildingNum, prevBuildingNum);
	}
	
	//Inputing Target Building Number
	scanf("%d", &targetBuildingNum);
	--targetBuildingNum;

	fastestPathLength = 0;

	//Processing
	Recursive(targetBuildingNum, 0);

	//Memory releasing
	delete[] buildInfo;
	buildInfo = NULL;
	delete[] buildTreeBuffer;
	buildTreeBuffer = NULL;

	//Return result;
	return fastestPathLength;
}

int *testCaseResultBuffer;

int main()
{
	int testCase = 0;
	scanf("%d", &testCase);

	testCaseResultBuffer = new int[testCase];

	for (int count = 0; count < testCase; ++count)
	{
		testCaseResultBuffer[count] = Test();
	}

	//Printing result
	for (int count = 0; count < testCase; ++count)
	{
		printf("%d\n", testCaseResultBuffer[count]);
	}

	delete[] testCaseResultBuffer;

	return 0;
}
