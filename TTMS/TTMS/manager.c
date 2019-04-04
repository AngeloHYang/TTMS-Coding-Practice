#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringRelated.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"
#include "usedVariableTypes.h"
#include "userRelated.h"

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
			if (strcmp(userInput, "y") == 0)
			{
				printf("We are going to delete the movie...");

				// Come back here and add what to do to tickets
				if (playingFlag == 1)
				{
					;
				}

				// Clear studio
				if (playingFlag == 1)
				{
					for (int whichOne = 1; whichOne <= howManyStudios(studioStart); whichOne++)
					{
						if (movieIDExistInStudioWhichOne(studioStart, inputID, whichOne) == 1)
						{
							studioSwap = studioCheckByWhichOne(studioStart, whichOne);
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

			printf("There are %d empty studios:\n", counter);
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

			printf("There are %d busy studios:\n", counter);
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
		printf("\nAlright then.\n");
		system("pause");
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
		printf("2) Make a movie playing at a studio\n");
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
			
		}
	}
}

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
		printf("What are you going to do?\n\n");
		printf("1) Manage movies\n");
		printf("2) Manage plays\n");
		printf("3) View data\n");

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

		}
	}
}