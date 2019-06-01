#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "studioRelated.h"
#include "stringRelated.h"
#include "usedVariableTypes.h"

#include <iostream>
using namespace std;

int seatIsBrokenToday(struct brokenSeatHistory* brokenSeatHistoryStart, int today, long long int studioID, int whichLine, int whichColumn)
// 1 stands for true, 0 stands for not broken
{
	struct brokenSeatHistory* operate = brokenSeatHistoryStart;
	while (operate != NULL)
	{
		if (operate->studioID == studioID && operate->whichLine == whichLine && operate->whichColumn == whichColumn && operate->startDay <= today && operate->endDay >= today)
		{
			return 1;
		}
		operate = operate->next;
	}
	return 0;
}

int seatIsBrokenInRange(struct brokenSeatHistory* brokenSeatHistoryStart, int from, int to, long long int studioID, int whichLine, int whichColumn)
{
	int flag = 0;
	for (int whichDay = from; whichDay <= to; whichDay++)
	{
		if (seatIsBrokenToday(brokenSeatHistoryStart, whichDay, studioID, whichLine, whichColumn) == 1)
		{
			return 1;
		}
	}
	return 0;
}

struct brokenSeatHistory* addBrokenSeatHistory(struct brokenSeatHistory* brokenSeatHistoryStart, long long int studioID, int whichLine, int whichOne, long long int startDay, long long int endDay)
{
	struct brokenSeatHistory* operate = brokenSeatHistoryStart;
	struct brokenSeatHistory* last = NULL;

	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
	}

	operate = (struct brokenSeatHistory*) malloc(sizeof(struct brokenSeatHistory));
	operate->next = NULL;
	operate->studioID = studioID;
	operate->whichLine = whichLine;
	operate->whichColumn = whichOne;
	operate->startDay = startDay;
	operate->endDay = endDay;

	if (last != NULL)
	{
		last->next = operate;
	}

	if (brokenSeatHistoryStart == NULL)
	{
		return operate;
	}
	else
	{
		return brokenSeatHistoryStart;
	}
}

struct brokenSeatHistory* brokenSeatHistoryCheckByWhichOne(struct brokenSeatHistory* brokenSeatHistoryStart, long long int whichOne)
	// It returns turns the adress of the struct
{
	long long int counter = 1;
	struct brokenSeatHistory* operate = brokenSeatHistoryStart;
	while (counter < whichOne)
	{
		counter++;
		operate = operate->next;
	}
	return operate;
}

int howManyBrokenSeatHistory(struct brokenSeatHistory* brokenSeatHistoryStart)
{
	struct brokenSeatHistory* operate = brokenSeatHistoryStart;
	int counter = 0;
	while (operate != NULL)
	{
		counter++;
		operate = operate->next;
	}
	return counter;
}