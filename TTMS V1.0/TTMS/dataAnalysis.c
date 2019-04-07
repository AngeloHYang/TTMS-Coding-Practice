#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringRelated.h"
#include "brokenSeatHistory.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "ticketRelated.h"
#include "usedVariableTypes.h"
#include "userRelated.h"

struct ticketCounter
{
	long long int movieID;
	long long int counter;
	struct ticketCounter* next;
};

long long int howManyKind(struct ticketCounter* counterStart)
{
	struct ticketCounter* operate = counterStart;
	long long int counter = 0;
	while (operate != NULL)
	{
		counter++;
		operate = operate->next;
	}
	return counter;
}

struct ticketCounter* add(long long int inputMovieID, struct ticketCounter* counterStart)
{
	struct ticketCounter* operate = counterStart;
	struct ticketCounter* last = NULL;
	int exist = 0;
	for (long long int whichOne = 1; whichOne <= howManyKind(counterStart); whichOne++)
	{
		last = operate;
		if (operate->movieID == inputMovieID)
		{
			exist = 1;
			(operate->counter)++;
			break;
		}
		operate = operate->next;
	}
	if (exist == 0)
	{
		if (last == NULL)
		{
			struct ticketCounter* new = (struct ticketCounter*) malloc(sizeof(struct ticketCounter));
			new->movieID = inputMovieID;
			new->counter = 1;
			new->next = NULL;
			return new;
		}
		else
		{
			last->next = (struct ticketCounter*) malloc(sizeof(struct ticketCounter));
			last->next->counter = 1;
			last->next->movieID = inputMovieID;
			last->next->next = NULL;
			return counterStart;
		}
	}
	else
	{
		return counterStart;
	}
}

void deleteAll(struct ticketCounter* counterStart)
{
	struct ticketCounter* operate = counterStart;
	struct ticketCoutner* last = NULL;
	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
		free(last);
	}
}

void displayAll(struct ticketCounter* counterStart)
{
	struct movie* movieSwap;
	struct ticketCounter* operate = counterStart;
	long long int sum = 0;
	while (operate != NULL)
	{
		movieSwap = movieCheckByID(operate->movieID);
		printf("Movie: %s\n", movieSwap->name);
		printf("Counter: %lld\n", operate->counter);
		printf("Profit: %lld\n", (operate->counter) * (movieSwap->price));
		sum += (operate->counter) * (movieSwap->price);
		printf("\n");
		operate = operate->next;
	}
	printf("Total: %lld\n", sum);
}

void viewDataMenu()
{
	system("cls");
	printf("Today is %d\n", today);
	printf("This is the analysis data for today!\n\n");
	struct ticketCounter* counterStart = NULL;

	struct ticketHistory* ticketSwap;
	for (long long int whichTicket = 1; whichTicket <= howManyTicketHistory(ticketHistoryStart); whichTicket++)
	{
		ticketSwap = ticketHistoryCheckByWhichOne(ticketHistoryStart, whichTicket);
		if (ticketSwap->shouldWatchDay == today && ticketSwap->status == 1)
		{
			counterStart = add(ticketSwap->movieID, counterStart);
		}
	}

	displayAll(counterStart);
	deleteAll(counterStart);

	system("pause");
}