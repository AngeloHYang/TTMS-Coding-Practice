#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usedVariableTypes.h"
#include "brokenSeatHistory.h"
#include "movieRelated.h"
#include "stringRelated.h"
#include "studioRelated.h"
#include "userRelated.h"
#include "ticketRelated.h"
extern void viewDataMenu();

static void checkStudios()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	system("cls");
	printf("Today: %d\n", today);

	// Check how many busy studios are there
	long long int counter = 0;
	struct studio* studioSwap;
	for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
	{
		studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
		if (studioSwap->moviePlayingID != -1)
		{
			counter++;
		}
	}

	printf("There are %lld studios available:\n", counter);
	for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
	{
		studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
		if (studioSwap->moviePlayingID != -1)
		{
			printStudioByWhichOne(studioStart, whichStudio);
		}
	}
	printf("\n\n");
	system("pause");
}

void sellTicketMenu()
{
	char userInput[1000];
	system("cls");
	printf("Today is %d\n", today);
	printf("To sell a ticket you need to know the ID of the studio first.\n");
	printf("Do you want to go back and check it out?(y/n)\nYour choice: ");
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
	{
		printf("Alright then!\n");
		printf("\nPlease input the ID of the studio: ");
		long long int inputStudioID;
		scanf_s("%lld", &inputStudioID);
		int studioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, inputStudioID);
		if (studioWhichOne == -1)
		{
			printf("\nThe ID doesn't exist!\n");
			printf("\nWe are going back!\n");
			system("pause");
		}
		else
		{
			printStudioByWhichOne(studioStart, studioWhichOne);
			struct studio* studioSwap = studioCheckByWhichOne(studioStart, studioWhichOne);
			if (studioSwap->moviePlayingID == -1)
			{
				printf("There's no movie playing right now!\n");
				printf("\nWe are going back!\n");
				system("pause");
			}
			else
			{
				printf("Which seat would you like?\n");
				int inputLine, inputColumn;
				printf("- Line: ");
				scanf_s("%d", &inputLine);
				printf("- Column: ");
				scanf_s("%d", &inputColumn);
				// Check if the seat is valid and not taken or broken
				if (seatExist(studioStart, studioSwap->ID, inputLine, inputColumn) == 1 && seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, inputLine, inputColumn) == 0 && seatTaken(studioSwap, today, inputLine, inputColumn, ticketHistoryStart) == 0)
				{
					printf("Are you gonna purchase this ticket?(y/n)\n");
					struct ticketHistory* ticketHistorySwap = unsoldOrWatchedTicketHistoryCheckByStudioAndPlaceAndDay(ticketHistoryStart, studioSwap, today, inputLine, inputColumn);
					printTicket(ticketHistorySwap);
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
							else if (seatTaken(studioSwap, today, whichLine, whichColumn, ticketHistoryStart) == 1)
							{
								printf("¨€");
							}
							else
							{
								printf("¡õ");
							}
						}
						printf("\n");
					}
					printf("Your choice: ");
					getchar();
					memset(userInput, '\0', sizeof(userInput));
					gets_s(userInput, 1000);
					deleteSpaceInTheEnd(userInput, 1000);
					if (strcmp(userInput, "y") == 0)
					{
						ticketHistorySwap->status = 1;
						printf("Ticket sold!\n");
						system("pause");
					}
					else
					{
						printf("Ticket not sold!\n");
						system("pause");
					}
				}
				else
				{
					printf("Invalid seat!\n");
					printf("\nWe are going back!\n");
					system("pause");
				}
			}
		}
	}
	else
	{
		printf("\nWe are going back!\n");
		system("pause");
	}
}

void checkTicketMenu()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Today is %d\n", today);
		printf("How would you like to check a ticket?\n\n");
		printf("1) By ID\n");
		printf("2) By studio\n\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		memset(userInput, '\0', sizeof(userInput));
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			system("cls");
			printf("Today is %d\n", today);
			printf("Please input the ID of the ticket: ");
			long long int inputTicketID;
			scanf_s("%lld", &inputTicketID);
			getchar();
			struct ticketHistory* ticketHistorySwap = ticketHistoryCheckByID(inputTicketID);
			if (ticketHistorySwap == NULL)
			{
				printf("The ticket doesn't exist!\n");
				system("pause");
			}
			else
			{
				printf("\n");
				printTicket(ticketHistorySwap);
				system("pause");
			}
		}
		else if (strcmp(userInput, "2") == 0)
		{
			system("cls");
			printf("Today is %d\n", today);
			printf("Please input the ID of the studio: ");
			long long int inputStudioID;
			scanf_s("%lld", &inputStudioID);
			getchar();
			long long int studioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, inputStudioID);
			if (studioWhichOne == -1)
			{
				printf("The studio doesn't exist!\n");
				system("pause");
			}
			else
			{
				struct studio* studioSwap = studioCheckByWhichOne(studioStart, studioWhichOne);
				printStudioByWhichOne(studioStart, studioWhichOne);
				long long int inputLine, inputColumn;
				printf("Please input the line and column of the seat:\n");
				printf("- Line: ");
				scanf_s("%lld", &inputLine);
				printf("- Column: ");
				scanf_s("%lld", &inputColumn);
				getchar();

				if (seatExist(studioStart, studioSwap->ID, inputLine, inputColumn) == 1 && seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, inputLine, inputColumn) == 0)
				{
					struct ticketHistory* ticketHistorySwap = unsoldOrWatchedTicketHistoryCheckByStudioAndPlaceAndDay(ticketHistoryStart, studioSwap, today, inputLine, inputColumn);
					printf("\n");
					printTicket(ticketHistorySwap);
					system("pause");
				}
				else
				{
					printf("Invalid seat!\n");
					printf("\nWe are going back!\n");
					system("pause");
				}
			}
		}
	}

}

void returnTicketMenu()
{
	char userInput[1000];
	system("cls");
	printf("Today is %d\n", today);
	printf("To return a ticket you need to know the ID of the ticket first.\n");
	printf("Do you want to go back and check it out?(y/n)\nYour choice: ");
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
	{
		printf("Please input the ID of the ticket: ");
		long long int inputTicketID;
		scanf_s("%lld", &inputTicketID);
		getchar();
		struct ticketHistory* ticketHistorySwap = ticketHistoryCheckByID(inputTicketID);
		if (ticketHistorySwap == NULL)
		{
			printf("Invalid ticket ID!\n");
			printf("\nWe are going back!\n");
			system("pause");
		}
		else
		{
			printf("\n");
			printTicket(ticketHistorySwap);			
			long long int studioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, ticketHistorySwap->studioID);
			if (studioWhichOne == -1)
			{
				printf("The studio which the ticket points to doesn't seem to exist!\n");
				printf("Has it been deleted?\n");
				printf("\nWe are going back!\n");
				system("pause");
			}
			else
			{
				// Print studio info
				struct studio* studioSwap;
				struct movie* movieSwap;
				studioSwap = studioCheckByWhichOne(studioStart, studioWhichOne);
				printf("Studio NO.%lld\n", studioWhichOne);
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

				
				for (int whichLine = 1; whichLine <= studioSwap->lines; whichLine++)
				{
					for (int whichColumn = 1; whichColumn <= studioSwap->columns; whichColumn++)
					{
						if (seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, whichLine, whichColumn) == 1)
						{
							printf("¢ú");
						}
						// consider use ¨€
						else if (whichLine == ticketHistorySwap->whichLine && whichColumn == ticketHistorySwap->whichColumn)
						{
							printf("¡î");
						}
						else if (seatTaken(studioSwap, today, whichLine, whichColumn, ticketHistoryStart) == 1)
						{
							printf("¨€");
						}
						else
						{
							printf("¡õ");
						}
					}
					printf("\n");
				}
				printf("\n\n");

				printf("Do you want to return this ticket?(y/n)\n");
				printf("Your choice: ");
				memset(userInput, '\0', sizeof(userInput));
				gets_s(userInput, 1000);
				deleteSpaceInTheEnd(userInput, 1000);

				if (strcmp(userInput, "y") == 0)
				{
					ticketHistorySwap->status = 0;
					printf("Ticket returned!\n");
				}
				else
				{
					printf("Ticket not returned!\n");
				}

				system("pause");
			}
		}

	}
	else
	{
		printf("\nWe are going back!\n");
		system("pause");
	}
}

static void changePasswordMenu()
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, 4);
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	system("cls");
	printf("Do you want to change your password?(y/n)\n");
	printf("Your choice: ");
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "y") == 0)
	{
		printf("Let's do it!(within 20)\n");

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
		}
		else
		{
			memset(userSwap->password, '\0', sizeof(userSwap->password));
			strcpy_s(userSwap->password, 1000, newInput2);
			printf("\n\nThe password of user %s changed successfully!\n", userSwap->username);
		}
		printf("\n\n");
		system("pause");
	}
	else
	{
		printf("\nWe are going back!\n");
		system("pause");
	}
}

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
		printf("3) Check a ticket\n");
		printf("4) Return a ticket\n");
		printf("5) View data\n");
		printf("6) Change password\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			checkStudios();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			sellTicketMenu();
		}
		else if (strcmp(userInput, "3") == 0)
		{
			checkTicketMenu();
		}
		else if (strcmp(userInput, "4") == 0)
		{
			returnTicketMenu();
		}
		else if (strcmp(userInput, "5") == 0)
		{
			viewDataMenu();
		}
		else if (strcmp(userInput, "6") == 0)
		{
			changePasswordMenu();
		}
	}
}