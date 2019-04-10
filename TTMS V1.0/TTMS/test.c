#include <stdio.h>
#include <string.h>
#include "stringRelated.h"
#include <stdlib.h>
#include "userRelated.h"
#include "usedVariableTypes.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"
#include "ticketRelated.h"

void test()
{
	/*
	char testArray[1000] = "Hello, my love!     ";
	printf("%lld\n%sE\n", strlen(testArray), testArray);
	//printf("Please input your password: ");
	//inputPassword(testArray, 1000);
	deleteSpaceInTheEnd(testArray, 1000);
	printf("%lld\n%sE\n", strlen(testArray), testArray);
	*/

	//struct user* userStart = NULL;
	/*
	userStart = addUser(userStart, "Hello", "123", 1);
	userStart = addUser(userStart, "Bye", "123", 2);
	userStart = addUser(userStart, "God", "123", 0);

	userStart = deleteUserByWhichOne(userStart, 1);
	struct user* testUser = userStart;
	while (testUser != NULL)
	{
		printf("Name: %s, Group: %d\n", testUser->username, testUser->userGroup);
		testUser = testUser->next;
	}
	printf("There are %d users.\n", howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 2));
	
	printf("The NO.2 is %s\n", userCheckByWhichOne(userStart, 2)->username);
	*/
	/*
	printf("studios: %d\n", howManyStudios(studioStart));
	studioStart = addStudio(studioStart, 1, 3, 4, 5);
	studioStart = addStudio(studioStart, 2, 3, 5, 1);
	studioStart = addStudio(studioStart, 3, 6, 11, 14);
	printf("studios: %d\n", howManyStudios(studioStart));

	studioStart = deleteStudioByWhichOne(studioStart, 1);
	struct studio* swap;
	for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
	{
		swap = studioCheckByWhichOne(studioStart, whichOne);
		printf("%d) %d\n", whichOne, swap->ID);
	}*/
	//printf("counter: %lld\n", studioIDCounter);
	//studioIDCounter++;
	
	/*
	printf("Seat History: %d\n", howManyBrokenSeatHistory(brokenSeatHistoryStart));
	brokenSeatHistoryStart = addBrokenSeatHistory(brokenSeatHistoryStart, 1, 1, 2, 1, 6);
	brokenSeatHistoryStart = addBrokenSeatHistory(brokenSeatHistoryStart, 1, 3, 4, 1, 6);
	struct brokenSeatHistory* brokenSeatHistorySwap;
	for (int whichOne = 1; whichOne <= howManyBrokenSeatHistory(brokenSeatHistoryStart); whichOne++)
	{
		brokenSeatHistorySwap = brokenSeatHistoryCheckByWhichOne(brokenSeatHistoryStart, whichOne);
		printf("%d\n", brokenSeatHistorySwap->whichLine);
	}
	printf("Seat History: %d\n", howManyBrokenSeatHistory(brokenSeatHistoryStart));*/

	/*
	printf("There are %d tickets!\n", howManyTicketHistory(ticketHistoryStart));
	ticketHistoryStart = addTicketHistory(ticketHistoryStart, 1, 1, 1, 1, 1, 1, 1);
	printf("There are %d tickets!\n", howManyTicketHistory(ticketHistoryStart));
	printf("Counter: %lld\n", ticketIDCounter);
	ticketIDCounter++;
	*/
	char testArray[] = "123a21";
	printf("%d\n", inputStringToInt(testArray, 6));

	printf("The test is over!\n");
	system("pause");
}