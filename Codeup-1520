// CppConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//


#include "stdafx.h"

#include <stdio.h>

class Person;

class Board
{
public:
	void Create(int w, int h);
	void Init(bool* initData);
	void Release();
	int GetW();
	int GetH();
	bool GetPersonState(int x, int y);
	void NextGeneration();
	void Print();
	void SetNextGenerationParams(int forBirth, int forSurvive, int forDead);
private:
	Person * * board;
	int w, h;
	int forBirth, forSurvive, forDead;
};

class Person
{
public:
	void NextGeneration(Board* board, int forBirth, int forSurvive, int forDead, int x, int y)
	{
		int w = board->GetW();
		int h = board->GetH();
		int left, up, right, down;

		left = x - 1;
		if (left<0)
			left = 0;

		up = y - 1;
		if (up<0)
			up = 0;

		right = x + 1;
		if (right >= w)
			right = w - 1;

		down = y + 1;
		if (down >= h)
			down = h - 1;

		int neighborCount = 0;
		for (int countH = up; countH <= down; ++countH)
			for (int countW = left; countW <= right; ++countW)
			{
				if (countH == y && countW == x)
					continue;
				if (board->GetPersonState(countW, countH))
					++neighborCount;
			}

		//살아 있다면 
		if (state)
		{
			if (neighborCount >= forDead)
				nextState = false;
			else if (neighborCount >= forSurvive)
				nextState = true;
			else
				nextState = false;
		}
		else
		{
			if (neighborCount == forBirth)
				nextState = true;
			else
				nextState = false;
		}
	}

	void Generate()
	{
		state = nextState;
	}

	void SetState(bool state)
	{
		this->state = state;
	}

	bool GetState()
	{
		return state;
	}
private:
	bool state;
	bool nextState;
};


void Board::Create(int w, int h)
{
	this->w = w;
	this->h = h;

	board = new Person*[h];
	board[0] = new Person[h*w];

	int stride = w;

	for (int countH = 0; countH<h; ++countH)
	{
		board[countH] = board[0] + stride * countH;
	}


}

void Board::Init(bool* initData)
{
	int idx = 0;

	for (int countH = 0; countH<h; ++countH)
	{
		for (int countW = 0; countW<w; ++countW)
		{
			board[countH][countW].SetState(initData[idx]);
			idx++;
		}
	}
}

void Board::Release()
{
	delete[] board[0];
	delete[] board;

	board = (Person**)0;
}

int Board::GetW() {
	return w;
}

int Board::GetH() {
	return h;
}

bool Board::GetPersonState(int x, int y)
{
	return board[y][x].GetState();
}

void Board::NextGeneration()
{
	for (int countH = 0; countH<h; ++countH)
	{
		for (int countW = 0; countW<w; ++countW)
		{
			board[countH][countW].NextGeneration(this, forBirth, forSurvive, forDead, countW, countH);
		}
	}

	for (int countH = 0; countH<h; ++countH)
	{
		for (int countW = 0; countW<w; ++countW)
		{
			board[countH][countW].Generate();
		}
	}
}

void Board::Print()
{
	for (int countH = 0; countH<h; ++countH)
	{
		for (int countW = 0; countW<w; ++countW)
		{
			if (board[countH][countW].GetState())
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
}
void Board::SetNextGenerationParams(int forBirth, int forSurvive, int forDead)
{
	this->forBirth = forBirth;
	this->forSurvive = forSurvive;
	this->forDead = forDead;
}

int main()
{
	int a, b;
	Board board;

	scanf("%d%d", &a, &b);
	board.Create(b, a);

	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	board.SetNextGenerationParams(x, y, z);

	int stateInput;
	int idxInitData;
	bool *initData = new bool[b*a];
	for (int count = 0; count<b*a; ++count)
	{
		scanf("%d", &stateInput);
		if (stateInput == 0)
		{
			initData[count] = false;
		}
		else
		{
			initData[count] = true;
		}
	}
	board.Init(initData);
	delete[] initData;

	int testGeneration;
	scanf("%d", &testGeneration);
	
	for (int count = 0; count<testGeneration; ++count)
	{
		board.NextGeneration();
	}
	board.Print();

	board.Release();

	return 0;
}
