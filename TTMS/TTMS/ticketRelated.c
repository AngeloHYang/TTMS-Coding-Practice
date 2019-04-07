// Ticket related
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brokenSeatHistory.h"
#include "movieRelated.h"
#include "stringRelated.h"
#include "studioRelated.h"
#include "usedVariableTypes.h"
#include "userRelated.h"

int howManyTicketHistory(struct ticketHistory* ticketHistoryStart)
{
	struct ticketHistory* operate = ticketHistoryStart;
	int counter = 0;
	while (operate != NULL)
	{
		counter++;
		operate = operate->next;
	}
	return counter;
}

struct ticketHistory* addTicketHistory(struct ticketHistory* ticketHistoryStart, long long int studioID, int whichLine, int whichColumn, long long int shouldWatchDay, long long int ticketID, long long int movieID, int status)
{
	struct ticketHistory* operate = ticketHistoryStart;
	struct ticketHistory* last = NULL;

	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
	}

	operate = (struct ticketHistory*) malloc(sizeof(struct ticketHistory));
	operate->next = NULL;
	operate->studioID = studioID;
	operate->whichLine = whichLine;
	operate->whichColumn = whichColumn;
	operate->status = status;
	operate->ticketID = ticketID;
	operate->movieID = movieID;
	operate->shouldWatchDay = shouldWatchDay;

	if (last != NULL)
	{
		last->next = operate;
	}

	if (ticketHistoryStart == NULL)
	{
		return operate;
	}
	else
	{
		return ticketHistoryStart;
	}
}

struct ticketHistory* ticketHistoryCheckByWhichOne(struct ticketHistory* ticketHistoryStart, long long int whichOne)
	// It returns turns the adress of the struct
{
	long long int counter = 1;
	struct ticketHistory* operate = ticketHistoryStart;
	while (counter < whichOne)
	{
		counter++;
		operate = operate->next;
	}
	return operate;
}

struct ticketHistory* ticketHistoryCheckByID(long long int inputID)
{
	struct ticketHistory* ticketHistorySwap;
	if (inputID == -1)
	{
		return NULL;
	}
	else
	{
		for (long long int whichTicket = 1; whichTicket <= howManyTicketHistory(ticketHistoryStart); whichTicket++)
		{
			ticketHistorySwap = ticketHistoryCheckByWhichOne(ticketHistoryStart, whichTicket);
			if (ticketHistorySwap->ticketID == inputID)
			{
				return ticketHistorySwap;
			}
		}
		return NULL;
	}
}