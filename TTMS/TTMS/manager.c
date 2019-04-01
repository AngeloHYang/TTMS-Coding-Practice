#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringRelated.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"
#include "usedVariableTypes.h"
#include "userRelated.h"

void managerView()
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, 3);
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Welcome, %s\n", userSwap->username);
		printf("Today is %d\n", today);
		printf("What are you going to do?\n");

		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
	}
}