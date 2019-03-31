#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usedVariableTypes.h"
#include "stringRelated.h"

int howManyStudios(struct studio* studioStart)
{
	struct studio* operate = studioStart;
	int counter = 0;
	while (operate != NULL)
	{
		counter++;
		operate = operate->next;
	}
	return counter;
}

struct studio* addStudio(struct studio* studioStart, long long int ID, int lines, int columns, long long int moviePlayingID)
{
	struct studio* operate = studioStart;
	struct studio* last = NULL;

	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
	}

	operate = (struct studio*) malloc(sizeof(struct studio));
	operate->next = NULL;
	operate->ID = ID;
	operate->lines = lines;
	operate->columns = columns;
	operate->moviePlayingID = moviePlayingID;

	if (last != NULL)
	{
		last->next = operate;
	}

	if (studioStart == NULL)
	{
		return operate;
	}
	else
	{
		return studioStart;
	}
}

struct studio* studioCheckByWhichOne(struct studio* studioStart, long long int whichOne)
	// It returns turns the adress of the struct
{
	long long int counter = 1;
	struct studio* operate = studioStart;
	
	while (counter != whichOne)
	{
		counter++;
		operate = operate->next;
	}
	return operate;
}

struct studio* deleteStudioByWhichOne(struct studio* studioStart, long long int whichOne)
	// Please make sure there are items before calling this function.
{
	long long int counter = 1;
	struct studio* operate = studioStart;
	if (whichOne != 0)
	{
		if (whichOne == 1) // If we are going to delete the 1st item.
		{
			//printf("We are going to delete %d!\n", 1);
			operate = operate->next;
			free(studioStart);
			return operate;
		}
		else
		{
			struct studio* last = NULL;
			while (counter != whichOne)
			{
				counter++;
				last = operate;
				operate = operate->next;
			}
			last->next = operate->next;
			free(operate);
			return studioStart;
		}
	}
	else
	{
		return studioStart;
	}
}

int studioCheckByIDAndReturnWhichOne(struct studio* studioStart, long long int inputID)
{
	struct studio* studioSwap;
	for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
	{
		studioSwap = studioCheckByWhichOne(studioStart, whichOne);
		if (studioSwap->ID == inputID)
		{
			return whichOne;
		}
	}
	return -1;
}