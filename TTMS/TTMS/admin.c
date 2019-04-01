// Wht happens when a seat is fixed ahead of time?
// What happens when there are tickets and you are trying to delete a studio
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userRelated.h"
#include "usedVariableTypes.h"
#include "stringRelated.h"
#include "studioRelated.h"
#include "movieRelated.h"
#include "brokenSeatHistory.h"

//  Below are changing password related
void changePassword(int whichUser)
// Don't forger about 1 being 2
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, whichUser);
	system("cls");
	printf("We are going to change the password of user %s (within 20)\n", userSwap->username);

	char oldInput[1000];
	char newInput1[1000];
	char newInput2[1000];
	memset(oldInput, '\0', sizeof(oldInput));
	memset(newInput1, '\0', sizeof(newInput1));
	memset(newInput2, '\0', sizeof(newInput2));

	printf("\n\nPlease input the old password of user %s: ", userSwap->username);
	inputPassword(oldInput, 1000);
	printf("\n\nPlease input the new password of user %s: ", userSwap->username);
	inputPassword(newInput1, 1000);
	printf("\n\nPlease input the new password of user %s once again: ", userSwap->username);
	inputPassword(newInput2, 1000);
	if (strcmp(oldInput, userSwap->password) != 0)
	{
		printf("\n\nWrong old password!\nFail to reset password of user %s!", userSwap->username);
	}
	else if (strcmp(newInput1, newInput2) != 0)
	{
		printf("\n\nThe two new passwords don't match!\nFail to reset password of user %s!", userSwap->username);
	}
	else if (strlen(newInput1) == 0 || strlen(newInput1) > 20)
	{
		printf("\n\nInvalid new password!\nFail to reset password of user %s!", userSwap->username);
	} else
	{
		memset(userSwap->password, '\0', sizeof(userSwap->password));
		strcpy_s(userSwap->password, 1000, newInput2);
		printf("\n\nThe password of user %s! changed successfully!\n", userSwap->username);
	}
	printf("\n\n");
	system("pause");
}

void changePasswordMenu()
{
	char userInput[1000];
	while (strcmp(userInput, "exit") != 0)
	{
		memset(userInput, '\0', sizeof(userInput));
		system("cls");
		printf("Whose password do you feel like changing?\n\n");
		struct user* userSwap;
		for (int whichUser = 2; whichUser <= (howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 2) + howManyUsersByKind(userStart, 3)); whichUser++)
		{
			userSwap = userCheckByWhichOne(userStart, whichUser);
			whichUser--;
			printf("%d) %s\n", whichUser, userSwap->username);
			whichUser++;
		}
		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);

		if (strcmp(userInput, "1") == 0)
		{
			changePassword(2);
		}
		else if (strcmp(userInput, "2") == 0)
		{
			changePassword(3);
		}
		else if (strcmp(userInput, "3") == 0)
		{
			changePassword(4);
		}
	}
}

// Below are studio management related

void viewAll()
{
	char userInput[1000];

	struct studio* studioSwap;
	struct movie* movieSwap;

	while (strcmp(userInput, "exit") != 0)
	{
		memset(userInput, '\0', sizeof(userInput));
		system("cls");
		printf("Today: %d\n", today);
		printf("There are %d studios:\n", howManyStudios(studioStart));
		
		for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
		{
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


		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);

	}
}

void addStudioMenu()
{
	system("cls");
	printf("Today: %d\n", today);
	printf("We are going to add a studio!\n");
	printf("\n- How Many lines of seats will there be?\n");
	printf("- ");
	int lines;
	scanf_s("%d", &lines);
	printf("\n- How Many columns of seats will there be?\n");
	printf("- ");
	int columns;
	scanf_s("%d", &columns);
	getchar();

	if (lines > 0 && columns > 0)
	{
		studioIDCounter++;
		printf("\n\nIs this allright?(y/n)\n");
		printf("Studio ID: %lld\n", studioIDCounter);
		printf("Seats:\n");
		for (int whichLine = 1; whichLine <= lines; whichLine++)
		{
			for (int whichColumn = 1; whichColumn <= columns; whichColumn++)
			{
				printf("¡õ");
			}
			printf("\n");
		}
		printf("\n");
		printf("Your input: ");
		char inputSpace[1000];
		memset(inputSpace, '\0', sizeof(inputSpace));
		gets_s(inputSpace, 1000);
		deleteSpaceInTheEnd(inputSpace, 1000);
		if (strcmp(inputSpace, "y") == 0)
		{
			studioStart = addStudio(studioStart, studioIDCounter, lines, columns, -1);
			printf("\nAdded successfully!\n");
			system("pause");
		}
		else
		{
			printf("\nFail to add the studio!\n");
			system("pause");
		}
	}
	else
	{
		printf("\nStop what you are trying to do!\nWe are going back!\n");
		system("pause");
	}
}
	
	

void deleteStudioMenu()
// Danger
{
	system("cls");
	printf("Today: %d\n", today);
	printf("We are going to delete a studio!\n");

	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	printf("Feel like going back and check out the ID of the studio that you are going to delete?(y/n)\n");
	printf("Your input: ");
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
	// If the user knows the ID
	{
		printf("Please input the ID of the studio that you are going to delete: ");
		long long int inputID;
		scanf_s("%lld", &inputID);
		getchar();
		int studioWhichOne;
		studioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, inputID);
		if (studioWhichOne == -1)
		{
			printf("Input ID ERROR!\n");
			system("pause");
		}
		else
		{
			struct studio* studioSwap;
			studioSwap = studioCheckByWhichOne(studioStart, studioWhichOne);
			printf("\n\nAre you sure to delete this studio?(y/n)\n");
			printf("Studio ID: %lld\n", studioSwap->ID);
			printf("Movie Playing: ");
			struct movie* movieSwap = movieCheckByID(studioSwap->moviePlayingID);
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
					else
					{
						printf("¡õ");
					}
				}
				printf("\n");
			}
			printf("\n");
			printf("Your input: ");
			char inputSpace[1000];
			memset(inputSpace, '\0', sizeof(inputSpace));
			gets_s(inputSpace, 1000);
			deleteSpaceInTheEnd(inputSpace, 1000);
			if (strcmp(inputSpace, "y") == 0)
			{
				studioStart = deleteStudioByWhichOne(studioStart, studioWhichOne);
				printf("\nDeleted successfully!\n");
				system("pause");
			}
			else
			{
				printf("\nFail to delete the studio!\n");
				system("pause");
			}
		}
	}
	// If the user doesn't know the ID
	else
	{
		printf("We are going back now!\n");
		system("pause");
	}
}

// Below are broken seats related
void ReportABrokenSeatMenu()
{
	system("cls");
	printf("Today: %d\n", today);
	printf("We are going to report a broken seat!\n\n\n");
	printf("Do you wanna go back and check out the ID of the studio?(y/n)\n");
	printf("Your input: ");
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
		// If the user knows the ID
	{
		printf("Please input the ID of the studio which has a broken seat to report: ");
		long long int inputID;
		scanf_s("%lld", &inputID);
		long long int targetStudioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, inputID);
		if (targetStudioWhichOne != -1)
		{
			struct studio* studioSwap = studioCheckByWhichOne(studioStart, targetStudioWhichOne);
			printf("\n\nThe studio:\n");
			printf("Movie playing: ");
			if (studioSwap->moviePlayingID == -1)
			{
				printf("No movies playing!\n");
			}
			else
			{
				struct movie* movieSwap = movieCheckByID(studioSwap->moviePlayingID);
				printf("%s\n", movieSwap->name);
			}
			printf("Seats:\n");
			for (int whichLine = 1; whichLine <= studioSwap->lines; whichLine++)
			{
				for (int whichColumn = 1; whichColumn <= studioSwap->columns; whichColumn++)
				{
					if (seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, whichLine, whichColumn) == 1)
					{
						printf("¢ú");
					}
					else
					{
						printf("¡õ");
					}
				}
				printf("\n");
			}
			printf("\n");
			printf("Which seat do you want to report?\n");
			int inputLine, inputColumn;
			printf("- Line: ");
			scanf_s("%d", &inputLine);
			printf("\n- Column: ");
			scanf_s("%d", &inputColumn);
			long long int startDay, endDay;
			printf("\nBroken day(No earlier than today): ");
			scanf_s("%lld", &startDay);
			printf("\nLast day being broken: ");
			scanf_s("%lld", &endDay);
			if (startDay >= today && seatExist(studioStart, studioSwap->ID, inputLine, inputColumn) == 1 && seatIsBrokenInRange(brokenSeatHistoryStart, startDay, endDay, studioSwap->ID, inputLine, inputColumn) == 0 && endDay >= startDay)
			{
				printf("\nAre you sure?(y/n)\n");
				printf("Broken period: %lld-%lld", startDay, endDay);
				printf("\nSeats:\n");
				for (int whichLine = 1; whichLine <= studioSwap->lines; whichLine++)
				{
					for (int whichColumn = 1; whichColumn <= studioSwap->columns; whichColumn++)
					{
						if (whichLine == inputLine && whichColumn == inputColumn)
						{
							printf("¡î");
						}
						else if (seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, whichLine, whichColumn) == 1)
						{
							printf("¢ú");
						}
						else
						{
							printf("¡õ");
						}
					}
					printf("\n");
				}

				getchar();
				char inputSpace[1000];
				memset(inputSpace, '\0', sizeof(inputSpace));
				gets_s(inputSpace, 1000);
				deleteSpaceInTheEnd(inputSpace, 1000);
				if (strcmp(inputSpace, "y") == 0)
				{
					brokenSeatHistoryStart = addBrokenSeatHistory(brokenSeatHistoryStart, studioSwap->ID, inputLine, inputColumn, startDay, endDay);
					printf("\nReport successfully!\n");
					system("pause");
				}
				else
				{
					printf("\nFail to report the broken seat!\n");
					system("pause");
				}
			}
			else if (seatIsBrokenInRange(brokenSeatHistoryStart, startDay, endDay, studioSwap->ID, inputLine, inputColumn) == 1 && endDay >= startDay)
			{
				printf("The broken seat has been reported before!\nPlease come to report when a seat hasn't been reported.\n");
				system("pause");
			}
			else
			{
				printf("\n***Invalid input!\n");
				printf("We are going back!\n");
				system("pause");
			}
		}
		else
		{
			printf("\nInvalid studio ID!\n");
			printf("We are going back!\n");
			system("pause");
		}
	}
	else
	{
		printf("We are going back!\n");
		system("pause");
	}

	
}

void manageStudioMenu()
{
	char userInput[1000];
	while (strcmp(userInput, "exit") != 0)
	{
		memset(userInput, '\0', sizeof(userInput));
		system("cls");
		printf("Today: %d\n", today);
		printf("What do you want to do with the studios?\n\n");
		printf("1) View all\n");
		printf("2) Add a studio\n");
		printf("3) Delete a studio\n");
		//printf("4) Report a broken seat\n");


		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);

		// Process input
		if (strcmp(userInput, "1") == 0)
		{
			viewAll();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			addStudioMenu();
		}
		else if (strcmp(userInput, "3") == 0)
		{
			deleteStudioMenu();
		}
		else if (strcmp(userInput, "4") == 0)
		{
			//ReportABrokenSeatMenu();
		}
	}
}

void adminView()
{
	char userInput[1000];
	while (strcmp(userInput, "exit") != 0)
	{
		memset(userInput, '\0', sizeof(userInput));
		struct user* userSwap;
		userSwap = userCheckByWhichOne(userStart, 3);

		system("cls");
		printf("Welcome, %s\n", userSwap->username);
		printf("Today is %d\n", today);
		printf("What are you going to do?\n");

		printf("\n1) Change passwords");
		printf("\n2) Manage studios");


		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			changePasswordMenu();
		}
		if (strcmp(userInput, "2") == 0)
		{
			manageStudioMenu();
		}
	}
}