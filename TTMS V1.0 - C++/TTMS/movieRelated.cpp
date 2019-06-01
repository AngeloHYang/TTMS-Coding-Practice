#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "usedVariableTypes.h"
#include "stringRelated.h"

#include <iostream>
using namespace std;

int howManyMovies(struct movie* movieStart)
{
	struct movie* operate = movieStart;
	int counter = 0;
	while (operate != NULL)
	{
		counter++;
		operate = operate->next;
	}
	return counter;
}

struct movie* addMovie(struct movie* movieStart, char name[1000], int price, long long int movieID, long long int startDay, long long int endDay)
{
	struct movie* operate = movieStart;
	struct movie* last = NULL;

	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
	}

	operate = (struct movie*) malloc(sizeof(struct movie));
	operate->next = NULL;
	strcpy_s(operate->name, 1000, name);
	operate->price = price;
	operate->ID = movieID;
	operate->startDay = startDay;
	operate->endDay = endDay;

	if (last != NULL)
	{
		last->next = operate;
	}

	if (movieStart == NULL)
	{
		return operate;
	}
	else
	{
		return movieStart;
	}
}

struct movie* movieCheckByWhichOne(struct movie* movieStart, long long int whichOne)
	// It returns turns the adress of the struct
{
	long long int counter = 1;
	struct movie* operate = movieStart;
	while (counter < whichOne)
	{
		counter++;
		operate = operate->next;
	}
	return operate;
}

struct movie* deleteMovieByWhichOne(struct movie* movieStart, long long int whichOne)
	// Please make sure there are items before calling this function.
	// Don't forget to assign the result to movieStart;
{
	long long int counter = 1;
	struct movie* operate = movieStart;
	if (whichOne != 0)
	{
		if (whichOne == 1) // If we are going to delete the 1st item.
		{
			//printf("We are going to delete %d!\n", 1);
			operate = operate->next;
			free(movieStart);
			return operate;
		}
		else
		{
			struct movie* last = NULL;
			while (counter != whichOne)
			{
				counter++;
				last = operate;
				operate = operate->next;
			}
			last->next = operate->next;
			free(operate);
			return movieStart;
		}
	}
	else
	{
		return movieStart;
	}
}

struct movie* movieCheckByID(long long int inputID)
{
	struct movie* movieSwap;
	if (inputID == -1)
	{
		return NULL;
	}
	else
	{
		for (long long int whichMovie = 1; whichMovie <= howManyMovies(movieStart); whichMovie++)
		{
			movieSwap = movieCheckByWhichOne(movieStart, whichMovie);
			if (movieSwap->ID == inputID)
			{
				return movieSwap;
			}
		}
		return NULL;
	}
}

int movieWhichOneIfAvailableToday(int today, long long int whichOne, struct movie* movieStart)
// If available, return 1; else return 0
{
	struct movie* movieSwap = movieCheckByWhichOne(movieStart, whichOne);
	if (today >= movieSwap->startDay && today <= movieSwap->endDay)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int movieExistByName(char inputName[1000], struct movie* movieStart)
{
	for (int whichOne = 1; whichOne <= howManyMovies(movieStart); whichOne++)
	{
		struct movie* movieSwap;
		movieSwap = movieCheckByWhichOne(movieStart, whichOne);
		if (strcmp(movieSwap->name, inputName) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void printMovieByWhichOne(struct movie* movieStart, long long int whichOne)
{
	struct movie* movieSwap;

	movieSwap = movieCheckByWhichOne(movieStart, whichOne);
	printf("Name: %s\n", movieSwap->name);
	printf("Price: %d\n", movieSwap->price);
	printf("ID: %lld\n", movieSwap->ID);
	printf("Begin day: %lld\n", movieSwap->startDay);
	printf("End day: %lld\n", movieSwap->endDay);
	printf("\n");
}

long long int movieIDToWhichOne(long long int movieID, struct movie* movieStart)
// If the movie doesn't exist, return -1;
{
	long long int counter = 1;
	struct movie* movieSwap;

	for (long long int whichMovie = 1; whichMovie <= howManyMovies(movieStart); whichMovie++)
	{
		movieSwap = movieCheckByWhichOne(movieStart, whichMovie);
		if (movieSwap->ID == movieID)
		{
			return whichMovie;
		}
	}
	return -1;
}