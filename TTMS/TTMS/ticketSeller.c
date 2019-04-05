#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usedVariableTypes.h"
#include "brokenSeatHistory.h"
#include "movieRelated.h"
#include "stringRelated.h"
#include "studioRelated.h"
#include "userRelated.h"

void ticketSellerView()
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, 4);
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Welcome, %s\n", userSwap->username);
		printf("Today is %d\n", today);
		printf("What are you going to do?\n\n");
		printf("1) Check studios\n");
		printf("2) Sell a ticket\n");
		printf("3) Return a ticket\n");
		printf("4) View data\n");
		printf("5) Change password\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			
		}
		else if (strcmp(userInput, "2") == 0)
		{
			
		}
		else if (strcmp(userInput, "3") == 0)
		{
			
		}
		else if (strcmp(userInput, "4") == 0)
		{

		}
		else if (strcmp(userInput, "5") == 0)
		{

		}
	}
}