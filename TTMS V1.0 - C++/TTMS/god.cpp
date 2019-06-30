#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "usedVariableTypes.h"
#include "stringRelated.h"
#include "studioRelated.h"

#include <iostream>
using namespace std;

void nextDay()
{
	system("cls");
	printf("God wielded their magic stick and turned the day from %d into %d!\n\n", today, today + 1);
	today++;

	// Deal with studios
	struct studio* studioSwap;
	for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
	{
		studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
		studioSwap->moviePlayingID = -1;
	}

	system("pause");
}

void godView()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Welcome, God\n");
		printf("Today is %d\n", today);
		printf("What are you going to do?\n");
		printf("\n1) Next day");
		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			nextDay();
		}
	}
}