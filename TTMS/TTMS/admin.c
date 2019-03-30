#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userRelated.h"
#include "usedVariableTypes.h"
#include "stringRelated.h"

void changePassword(int whichUser)
// Don't forger about 1 being 2
{
	struct user* userSwap;
	userSwap = userCheckByWhichOne(userStart, whichUser);
	system("cls");
	printf("We are going to change the password of user %s\n", userSwap->username);

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
	else if (strlen(newInput1) == 0)
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

void manageStudioMenu()
{
	char userInput[1000];
	while (strcmp(userInput, "exit") != 0)
	{
		memset(userInput, '\0', sizeof(userInput));
		system("cls");
		printf("Today: %d\n", today);
		printf("What do you want to do with studios?\n\n");
		printf("1) View all\n");
		printf("2) Add a studio\n");
		printf("3) Delete a studio\n");
		printf("4) Report a broken seat\n");


		printf("\n\nInput exit to quit\n\nYour input: ");
		gets_s(userInput, 1000);
		deleteSpaceInTheEnd(userInput, 1000);

		// Process input
		if (strcmp(userInput, "1") == 0)
		{
			
		}
		else if (strcmp(userInput, "2") == 0)
		{
			
		}
		else if (strcmp(userInput, "3") == 0)
		{
			
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