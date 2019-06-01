// Ticket related
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "brokenSeatHistory.h"
#include "movieRelated.h"
#include "stringRelated.h"
#include "studioRelated.h"
#include "usedVariableTypes.h"
#include "userRelated.h"

#include <iostream>
using namespace std;

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

struct ticketHistory* unsoldOrWatchedTicketHistoryCheckByStudioAndPlaceAndDay(struct ticketHistory* ticketHistoryStart, struct studio* studioSwap, int today, int whichLine, int whichColumn)
{
	struct ticketHistory* ticketHistorySwap;
	for (long long int whichTicket = 1; whichTicket <= howManyTicketHistory(ticketHistoryStart); whichTicket++)
	{
		ticketHistorySwap = ticketHistoryCheckByWhichOne(ticketHistoryStart, whichTicket);
		if (ticketHistorySwap->studioID == studioSwap->ID && ticketHistorySwap->shouldWatchDay == today && ticketHistorySwap->whichColumn == whichColumn && ticketHistorySwap->whichLine == whichLine && (ticketHistorySwap->status == 0 || ticketHistorySwap->status == 1))
		{
			return ticketHistorySwap;
		}
	}
	return NULL;
}

void printTicket(struct ticketHistory* ticketHistorySwap)
{
	printf("Ticket ID: %lld\n", ticketHistorySwap->ticketID);
	struct movie* movieSwap = movieCheckByID(ticketHistorySwap->movieID);
	printf("Movie: %s\n", movieSwap->name);
	printf("Price: %d\n", movieSwap->price);
	printf("Studio ID: %lld\n", ticketHistorySwap->studioID);
	printf("Watch day: %lld\n", ticketHistorySwap->shouldWatchDay);
	printf("WhichLine: %d\n", ticketHistorySwap->whichLine);
	printf("WhichLine: %d\n", ticketHistorySwap->whichColumn);
	printf("Status: ");
	if (ticketHistorySwap->status == 0)
	{
		printf("Unsold\n");
	}
	else if (ticketHistorySwap->status == 1)
	{
		printf("Sold/Watched\n");
	}
	else if (ticketHistorySwap->status == 2)
	{
		printf("Error\n");
	}
	printf("\n");
}