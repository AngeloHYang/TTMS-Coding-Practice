#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringRelated.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"
#include "usedVariableTypes.h"
#include "userRelated.h"
#include "ticketRelated.h"

void checkMovieMenu()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Today is %d\n", today);
		printf("How would you like to check the movies?\n\n");
		printf("1) View every movie in the database\n");
		printf("2) View movies available today\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			system("cls");
			printf("Here are %d movies in the database!\n", howManyMovies(movieStart));
			//struct movie* movieSwap;
			for (long long int whichOne = 1; whichOne <= howManyMovies(movieStart); whichOne++)
			{
				printf("%lld:\n", whichOne);
				printMovieByWhichOne(movieStart, whichOne);
			}
			system("pause");
		}
		else if (strcmp(userInput, "2") == 0)
		{
			system("cls");
			// Check if it's available today.
			struct movie* movieSwap;
			long long int availableTodayAll = 0;
			for (long long int whichOne = 1; whichOne <= howManyMovies(movieStart); whichOne++)
			{
				movieSwap = movieCheckByWhichOne(movieStart, whichOne);
				if (movieWhichOneIfAvailableToday(today, whichOne, movieStart) == 1)
				{
					availableTodayAll++;
				}
			}

			printf("Here are %lld movies available today!\n", availableTodayAll);
			
			long long int counter = 0;

			while (counter < availableTodayAll)
			{
				for (long long int whichOne = 1; whichOne <= howManyMovies(movieStart); whichOne++)
				{
					movieSwap = movieCheckByWhichOne(movieStart, whichOne);
					if (movieWhichOneIfAvailableToday(today, whichOne, movieStart) == 1)
					{
						printf("%lld:\n", whichOne);
						printMovieByWhichOne(movieStart, whichOne);
						counter++;
					}
				}
			}
			system("pause");
		}
	}
}

void addMovieMenu()
{
	system("cls");
	printf("Today is %d\n", today);
	printf("Are you ready to add a movie?(y/n)\n\n");
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	printf("Your choice:  ");
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "y") == 0)
	{
		printf("\nLet's do it!\n");

		printf("- Name: ");
		char inputName[1000];
		memset(inputName, '\0', sizeof(inputName));
		gets_s(inputName, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
			
		printf("- Price: ");
		int inputPrice;
		scanf_s("%d", &inputPrice);
			
		printf("- Begin Day: ");
		long long int inputBeginDay;
		scanf_s("%lld", &inputBeginDay);

		printf("- Last Playing Day: ");
		long long int inputEndDay;
		scanf_s("%lld", &inputEndDay);

		getchar();

		printf("\n\nAre you sure?(y/n)\n");
		//movieIDCounter++;
		printf("- Name: %s\n", inputName);
		printf("- Price: %d\n", inputPrice);
		printf("- Begin Day: %lld\n", inputBeginDay);
		printf("- Last Day Playing: %lld\n", inputEndDay);

		printf("Your choice: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);

		int fail = 0;
		printf("\n");
		if (strcmp(userInput, "y") == 0)
		{
			// Check if the movie already exist
			if (movieExistByName(inputName, movieStart) == 1)
			{
				printf("Movie Already exist!\n");
				fail = 1;
			}

			// If there's no name (If the user press "enter" without inputing anything)
			if (strlen(inputName) == 0)
			{
				printf("Please input the name!\n");
				fail = 1;
			}

			if (inputPrice < 0)
			{
				printf("Movies cost!\n");
				fail = 1;
			}

			if (inputBeginDay > inputEndDay)
			{
				printf("Wrong begin day and last playing day!\n");
				fail = 1;
			}

			//printf("Fail: %d\n", fail);
			if (fail == 0)
			{
				movieIDCounter++;
				movieStart = addMovie(movieStart, inputName, inputPrice, movieIDCounter, inputBeginDay, inputEndDay);
				printf("Added successfully!\n");
			}
			else
			{
				printf("Fail to add!\n");
			}
		}
		else
		{
			printf("We are going back!\n");
		}
		printf("\n");
		system("pause");
	}
	else
	{
		printf("We are going back!\n");
		system("pause");
	}
}

void deleteMovieMenu()
{
	system("cls");
	printf("Today is %d\n", today);
	printf("To delete a movie, you need to know the ID of it first!\n");
	printf("WARNING: If a movie is deleted, it'll never be able to be added once again!\n");
	printf("Are you ready to delete a movie?(y/n)\n\n");
	char userInput[1000];
	printf("Your choice:  ");
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "y") == 0)
	{
		printf("\nLet's do it!\n");
		printf("Please input the ID of the movie: ");
		long long int inputID;
		scanf_s("%lld", &inputID);
		getchar();
		struct movie* movieSwap = movieCheckByID(inputID);

		// Check if the ID exist
		if (movieSwap == NULL)
		{
			printf("The movie ID that you input doesn't seem to exist!\n");
			system("pause");
		}
		else
		{
			printMovieByWhichOne(movieSwap, 1); // Consider the current one as the first one for convenience.

			// Check if the movie is playing.
			int playingFlag = 0;
			for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
			{
				if (movieIDExistInStudioWhichOne(studioStart, inputID, whichOne) == 1)
				{
					playingFlag = 1;
					break;
				}
			}
			if (playingFlag == 1)
			{
				printf("The movie is playing at: \n");
				for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
				{
					if (movieIDExistInStudioWhichOne(studioStart, inputID, whichOne) == 1)
					{
						printStudioByWhichOne(studioStart, whichOne);
					}
				}
				printf("\nTo delete the movie, every sold out ticket will be forcely returned and marked as the cinema's bad.\n");
			}
			printf("Do you wish to delete the movie? (y/n)\n");
			printf("\nYour choice: ");
			memset(userInput, '\0', sizeof(userInput));
			gets_s(userInput, 1000);
			deleteSpaceInTheEnd(userInput, 1000);
			struct studio* studioSwap;
			struct ticketHistory* ticketHistorySwap;
			if (strcmp(userInput, "y") == 0)
			{
				printf("We are going to delete the movie...");

				// Clear studio and tickets
				if (playingFlag == 1)
				{
					for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
					{
						if (movieIDExistInStudioWhichOne(studioStart, inputID, whichOne) == 1)
						{
							studioSwap = studioCheckByWhichOne(studioStart, whichOne);

							// Deal with tickets
							for (long long int whichTicket = 1; whichTicket <= howManyTicketHistory(ticketHistoryStart); whichTicket++)
							{
								ticketHistorySwap = ticketHistoryCheckByWhichOne(ticketHistoryStart, whichTicket);
								if (ticketHistorySwap->studioID == studioSwap->ID && ticketHistorySwap->shouldWatchDay >= today)
								{
									ticketHistorySwap->status = 2;
								}
							}

							studioSwap->moviePlayingID = -1;
						}
					}
				}

				// Delete movie from movie database;

				movieStart = deleteMovieByWhichOne(movieStart, movieIDToWhichOne(inputID, movieStart));
				printf("done!\n");
				system("pause");
			}
			else
			{
				printf("Movie not deleted!\n");
				system("pause");
			}
		}
	} else
	{
		printf("We are going back!\n");
		system("pause");
	}
}

void manageMovieMenu()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Today is %d\n", today);
		printf("What are you going to do to the movie database?\n\n");
		printf("1) Check movies\n");
		printf("2) Add a movie\n");
		printf("3) Delete a movie\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			checkMovieMenu();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			addMovieMenu();
		}
		else if (strcmp(userInput, "3") == 0)
		{
			deleteMovieMenu();
		}
	}
}

void checkStudios()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Today: %d\n", today);
		printf("How would you like to check studios?\n");
		printf("1) Check all studios\n");
		printf("2) Check empty studios\n");
		printf("3) Check busy studios\n");
		printf("\n\nInput exit to quit\n\nYour input: ");
		memset(userInput, '\0', sizeof(userInput));
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		
		if (strcmp(userInput, "1") == 0)
		{
			system("cls");
			printf("Today: %d\n", today);
			printf("There are %d studios in all:\n", howManyStudios(studioStart));

			for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
			{
				printStudioByWhichOne(studioStart, whichStudio);
			}
			printf("\n\n");
			system("pause");
		}
		else if (strcmp(userInput, "2") == 0)
		{
			system("cls");
			printf("Today: %d\n", today);

			// Check how many empty studios are there
			long long int counter = 0;
			struct studio* studioSwap;
			for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
			{
				studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
				if (studioSwap->moviePlayingID == -1)
				{
					counter++;
				}
			}

			printf("There are %lld empty studios:\n", counter);
			for (long long int whichStudio = 1; whichStudio <= howManyStudios(studioStart); whichStudio++)
			{
				studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
				if (studioSwap->moviePlayingID == -1)
				{
					printStudioByWhichOne(studioStart, whichStudio);
				}
			}
			printf("\n\n");
			system("pause");
		}
		else if (strcmp(userInput, "3") == 0)
		{
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

			printf("There are %lld busy studios:\n", counter);
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
	}
}

void linkMovieMenu()
{
	system("cls");
	printf("Today is %d\n", today);
	printf("Let's pick a movie and make a studio play it!\n");
	printf("You need to remember the ID of the movie and the ID of the studio.\n");
	printf("Yes, it ain't easy to be a manager!\n");
	printf("Do you want to go back and check them out? (y/n)\n");
	printf("\nYour choice: ");
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
	{
		long long int inputStudioID;
		long long int inputMovieID;
		printf("\nPlease input the ID of the studio: ");
		scanf_s("%lld", &inputStudioID);
		getchar();
		long long int studioWhichOne = studioCheckByIDAndReturnWhichOne(studioStart, inputStudioID);
		if (studioWhichOne == -1)
		{
			printf("The studio doesn't exist!\n");
			printf("We are going back!\n\n");
			system("pause");
		}
		else
		{
			printStudioByWhichOne(studioStart, studioWhichOne);
			struct studio* studioSwap = studioCheckByWhichOne(studioStart, studioWhichOne);
			if (studioSwap->moviePlayingID != -1)
			{
				printf("There is a movie playing at the studio!\n");
				printf("\nWe are going back!\n");
				system("pause");
			}
			else
			{
				printf("\nPlease input the ID of the movie: ");
				scanf_s("%lld", &inputMovieID);
				getchar();
				struct movie* movieSwap = movieCheckByID(inputMovieID);
				if (movieSwap == NULL)
				{
					printf("The movie doesn't exist!\n");
					printf("We are going back!\n\n");
					system("pause");
				}
				else
				{
					long long int movieWhichOne = movieIDToWhichOne(inputMovieID, movieStart);
					if (movieWhichOneIfAvailableToday(today, movieWhichOne, movieStart) == 0)
					{
						printMovieByWhichOne(movieStart, movieWhichOne);
						printf("The movie %s isn't available today!\n", movieSwap->name);
						system("pause");
					}
					else
					{
						printMovieByWhichOne(movieStart, movieWhichOne);
						printf("Do you want to make this movie play at studio %lld?(y/n)\n", inputStudioID);
						printf("Your decision: ");
						memset(userInput, '\0', sizeof(userInput));
						gets_s(userInput, 1000);
						deleteSpaceInTheEnd(userInput, 1000);
						if (strcmp(userInput, "y") != 0)
						{
							printf("\nWe are going back!\n\n");
							system("pause");
						}
						else
						{
							printf("Alright then!\n");
							
							studioSwap->moviePlayingID = movieSwap->ID;

							//the ticket part!
							printf("Generating tickets...");
							for (long long int whichLine = 1; whichLine <= studioSwap->lines; whichLine++)
							{
								for (long long int whichColumn = 1; whichColumn <= studioSwap->columns; whichColumn++)
								{
									if (seatIsBrokenToday(brokenSeatHistoryStart, today, studioSwap->ID, whichLine, whichColumn) == 0)
									{
										ticketIDCounter++;
										ticketHistoryStart = addTicketHistory(ticketHistoryStart, studioSwap->ID, whichLine, whichColumn, today, ticketIDCounter, studioSwap->moviePlayingID, 0);
									}
								}
							}
							printf("done!\n");

							printf("Movie linked!\n");
							printStudioByWhichOne(studioStart, studioWhichOne);
							
							
							system("pause");
						}
					}
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

void unlinkMovieMenu()
{
	system("cls");
	printf("Today is %d\n", today);
	printf("Let's stop playing a movie at a studio!\n");
	printf("You need to know the ID of the studio.\n");
	printf("Do you want to go back and check it out? (y/n)\n");
	printf("\nYour choice: ");
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	gets_s(userInput, 1000);
	deleteSpaceInTheEnd(userInput, 1000);
	if (strcmp(userInput, "n") == 0)
	{
		printf("\nPlease input the ID of the studio: ");
		long long int inputStudioID;
		scanf_s("%lld", &inputStudioID);
		getchar();
		if (studioCheckByIDAndReturnWhichOne(studioStart, inputStudioID) == -1)
		{
			printf("The studio doesn't exist!\n");
			printf("\nWe are going back!\n");
			system("pause");
		}
		else
		{
			long long int whichStudio = studioCheckByIDAndReturnWhichOne(studioStart, inputStudioID);
			struct studio* studioSwap = studioCheckByWhichOne(studioStart, whichStudio);
			printStudioByWhichOne(studioStart, whichStudio);
			if (studioSwap->moviePlayingID == -1)
			{
				printf("There's no movie playing at this studio!\n");
				printf("\nWe are going back!\n");
				system("pause");
			}
			else
			{
				struct movie* movieSwap = movieCheckByID(studioSwap->moviePlayingID);
				struct ticketHistory* ticketHistorySwap;
				printf("Do you want to stop playing movie %s in this studio?(y/n)\n", movieSwap->name);
				printf("Your choice: ");
				memset(userInput, '\0', sizeof(userInput));
				gets_s(userInput, 1000);
				deleteSpaceInTheEnd(userInput, 1000);
				if (strcmp(userInput, "y") == 0)
				{
					studioSwap->moviePlayingID = -1;
					printStudioByWhichOne(studioStart, whichStudio);


					// Deal with tickets
					for (long long int whichTicket = 1; whichTicket <= howManyTicketHistory(ticketHistoryStart); whichTicket++)
					{
						ticketHistorySwap = ticketHistoryCheckByWhichOne(ticketHistoryStart, whichTicket);
						if (ticketHistorySwap->studioID == studioSwap->ID && ticketHistorySwap->shouldWatchDay == today)
						{
							ticketHistorySwap->status = 2;
						}
					}

					printf("Movie cancelled!\n");
					system("pause");
				}
				else
				{
					printf("\n%s will go on!\n", movieSwap->name);
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

void managePlayMenu()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Today is %d\n", today);
		printf("How would you like to put play movies?\n\n");
		printf("1) Check studios\n");
		printf("2) Make a movie play at a studio\n");
		printf("3) Stop playing a movie at a studio\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			checkStudios();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			linkMovieMenu();
		}
		else if (strcmp(userInput, "3") == 0)
		{
			unlinkMovieMenu();
		}
	}
}

void viewDataMenu()
{
	system("cls");
	printf("\033[1m\033[31m¹ã");
	printf("\033[4m\033[32m¸æ");
	printf("\033[5m\033[33mÎ»");
	printf("\033[2m\033[34mÕÐ");
	printf("\033[7m\033[35m×â");
	printf("\033[0m\n\n");
	system("pause");
}

static void changePasswordMenu()
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, 2);
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

void managerView()
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, 2);
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Welcome, %s\n", userSwap->username);
		printf("Today is %d\n", today);
		printf("What are you going to do?\n\n");
		printf("1) Manage movies\n");
		printf("2) Manage plays\n");
		printf("3) View data\n");
		printf("4) Change password\n");

		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			manageMovieMenu();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			managePlayMenu();
		}
		else if (strcmp(userInput, "3") == 0)
		{
			viewDataMenu();
		}
		else if (strcmp(userInput, "4") == 0)
		{
			changePasswordMenu();
		}
	}
}