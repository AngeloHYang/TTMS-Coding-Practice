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
			struct movie* movieSwap;
			for (long long int whichOne = 1; whichOne <= howManyMovies(movieStart); whichOne++)
			{
				movieSwap = movieCheckByWhichOne(movieStart, whichOne);
				printf("%lld:\n", whichOne);
				printf("Name: %s", movieSwap->name);
				printf("Price: %d\n", movieSwap->price);
				printf("ID: %lld\n", movieSwap->ID);
				printf("Begin day: %lld\n", movieSwap->startDay);
				printf("End day: %lld\n", movieSwap->endDay);
				printf("\n");
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
						printf("%lld:\n", counter + 1);
						printf("Name: %s", movieSwap->name);
						printf("Price: %d\n", movieSwap->price);
						printf("ID: %lld\n", movieSwap->ID);
						printf("Begin day: %lld\n", movieSwap->startDay);
						printf("End day: %lld\n", movieSwap->endDay);
						printf("\n");
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

		printf("- Last Day Playing: ");
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
			//deleteMovieMenu();
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

		}
		else if (strcmp(userInput, "3") == 0)
		{

		}
	}
}