#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usedVariableTypes.h"
#include "stringRelated.h"
#include "movieRelated.h"
#include "brokenSeatHistory.h"

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
	
	while (counter < whichOne)
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

int seatExist(struct studio* studioStart, long long int inputID, int whichLine, int whichColumn)
{
	struct studio* studioSwap = studioCheckByWhichOne(studioStart, studioCheckByIDAndReturnWhichOne(studioStart, inputID));
	if (whichColumn <= studioSwap->columns && whichColumn >= 1 && whichLine <= studioSwap->lines && whichColumn >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printStudioByWhichOne(struct studio* studioStart, long long int whichStudio)
{
	struct studio* studioSwap;
	struct movie* movieSwap;
	studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
	printf("Studio NO.%lld\n", whichStudio);
	printf("Studio ID: %lld\n", studioSwap->ID);
	printf("Movie playing: ");
	movieSwap = movieCheckByID(studioSwap->moviePlayingID);
	if (movieSwap == NULL)
	{
		printf("No movie playing now\n");
	}
	else
	{
		printf("%s\n", movieSwap->name);
	}
	printf("Seats:\n");

	// Are you forgetting something?
	for (int whichLine = 1; whichLine <= studioSwap->lines; whichLine++)
	{
		for (int whichColumn = 1; whichColumn <= studioSwap->columns; whichColumn++)
		{
			if (seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, whichLine, whichColumn) == 1)
			{
				printf("¢ú");
			}
			// consider use ¨€
			else
			{
				printf("¡õ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

int movieIDExistInStudioWhichOne(struct studio* studioStart, long long int movieID, long long int whichOne)
{
	struct studio* studioSwap = studioCheckByWhichOne(studioStart, whichOne);
	if (studioSwap->moviePlayingID == movieID)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}