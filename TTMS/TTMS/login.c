#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userRelated.h"
#include "usedVariableTypes.h"
#include "stringRelated.h"

int loginWithPassword(struct user* userStart, int whichUser)
{
	system("cls");
	struct user* userSwap = userCheckByWhichOne(userStart, whichUser);
	printf("Please enter the password for user %s\n", userSwap->username);
	printf("- ");
	char userInput[1000];
	inputPassword(userInput, 1000);
	printf("\n");
	if (strcmp(userInput, userSwap->password) == 0)
	{
		printf("Correct!\n");
		system("pause");
		return 1;
	}
	else
	{
		printf("Incorrect!\n");
		system("pause");
		return 0;
	}
	
}
// If correct, return 1, else return 0;

struct  user* createUserWhenFirstLggingIn(struct user* userStart, char userName[1000], int userGroup)
{
	char passwordSpace[21];
	char passwordSpace2[21];
	char empty[21];
	memset(empty, '\0', sizeof(empty));
	memset(passwordSpace, '\0', sizeof(passwordSpace));
	memset(passwordSpace2, '\0', sizeof(passwordSpace2));
	while (strcmp(passwordSpace, passwordSpace2) != 0 || strcmp(passwordSpace, empty) == 0 || strcmp(passwordSpace2, empty) == 0)
	{
		system("cls");
		printf("We are going to add user \"%s\"\n\n", userName);
		printf("Can you come up with a password within 20?\n");
		printf("- Password: ");
		inputPassword(passwordSpace, 21);
		printf("\n- Once again: ");
		inputPassword(passwordSpace2, 21);
		printf("\n");
		if (strcmp(passwordSpace, passwordSpace2) != 0 || strcmp(passwordSpace, empty) == 0 || strcmp(passwordSpace2, empty) == 0 || strlen(passwordSpace) > 20)
		{
			printf("\nPASSWORDS INCOMPATIBLE!!!\n");
			system("pause");
		}
	}
	userStart = addUser(userStart, userName, passwordSpace, userGroup);
	printf("\nPassword for user \"%s\" added successfully.\n", userName);
	return userStart;
}

void hacker()
{
	char inputThings[1000];
	memset(inputThings, '\0', sizeof(inputThings));
	while (strcmp(inputThings, "exit") != 0)
	{
		memset(inputThings, '\0', sizeof(inputThings));
		system("cls");
		printf("Congratulations, People Hacker!\n");
		printf("You've successfully hacked into the system!\n");
		printf("Here are passwords of every user:\n");
		struct user* swap;

		for (int whichOne = 2; whichOne <= 4; whichOne++)
		{
			swap = userCheckByWhichOne(userStart, whichOne);
			printf("\n");
			printf("\n");
			printf("- username: %s\n", swap->username);
			printf("- password: %s\n", swap->password);
			printf("- Length: %lld\n", strlen(swap->password));
		}
		printf("\nInput exit to quit\n\nYour input: ");
		gets_s(inputThings, 1000);
		deleteSpaceInTheEnd(inputThings, 1000);
	}
}

void welcome()
{
	char userInput[1000];
	memset(userInput, '\0', sizeof(userInput));
	while (strcmp(userInput, "exit") != 0)
	{
		system("cls");
		printf("Welcome to Ticketing Management System (or TTMS as what they say)\n");
		printf("Today is %d\n", today);
		printf("\nThe first question is: Who are you?\n\n");
		
		struct user* userSwap;
		for (int whichUser = 1; whichUser <= (howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 2) + howManyUsersByKind(userStart, 3)); whichUser++)
		{
			userSwap = userCheckByWhichOne(userStart, whichUser);
			printf("%d) %s\n", whichUser, userSwap->username);
		}
		printf("%d) %s", (howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 2) + howManyUsersByKind(userStart, 3)) + 1, "People Hacker");
		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);
		if (strcmp(userInput, "1") == 0)
		{
			extern void godView();
			godView();
		}
		else if (strcmp(userInput, "2") == 0)
		{
			if (loginWithPassword(userStart, 2) == 1)
			{
				extern void managerView();
				managerView();
			}
		}
		else if (strcmp(userInput, "3") == 0)
		{
			if (loginWithPassword(userStart, 3) == 1)
			{
				extern void adminView();
				adminView();
			}
		}
		else if (strcmp(userInput, "4") == 0)
		{

		}
		else if (strcmp(userInput, "5") == 0)
		{
			hacker();
		}
	}
}

void login()
{
	system("cls");

	while ((howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 2) + howManyUsersByKind(userStart, 3)) == 0)
	{
		// If there are no users
		printf("NO USERS FOUND\n\n");
		printf("In order to launch this software, we'll help you add some users.\n\n");
		printf("There will be 4 kind of users: God, Manager, Admin, Ticket Seller.\n\n");
		printf("God is in charge of the date.\n");
		printf("And soon you'll learn what the other 3 users do.\n\n");
		printf("God doesn't require password. The other three DO.\n\n");
		system("pause");

		// Create users
		system("cls");
		userStart = addUser(userStart, "God", "God", 0);
		userStart = createUserWhenFirstLggingIn(userStart, "Manager", 2);
		system("pause");
		userStart = createUserWhenFirstLggingIn(userStart, "Admin", 1);
		system("pause");
		userStart = createUserWhenFirstLggingIn(userStart, "Ticket Seller", 3);
		system("pause");

		// When users are created.
		if ( (howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 2) + howManyUsersByKind(userStart, 3)) == 4)
		{
			system("cls");
			printf("Now that there are users\n");
			printf("Enjoy this program!\n");
			system("pause");
			system("cls");
		}
	}
	
	// If there users already exist
	welcome();
}