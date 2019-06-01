#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "stringRelated.h"
#include "usedVariableTypes.h"

#include <iostream>
using namespace std;

int howManyUsersByKind(struct user* userStart, int userGroup)
// Find out how many users are in the given group
{
	struct user* operate = userStart;
	int counter = 0;
	while (operate != NULL)
	{
		if (operate->userGroup == userGroup)
		{
			counter++;
		}
		operate = operate->next;
		//printf("Counter: %d\n", counter);
	}
	return counter;
}

struct user* addUser(struct user* userStart, char username[1000], char password[1000], int userGroup)
// Don't forget to assign the result to userStart;
{
	struct user* operate = userStart;
	struct user* last = NULL;

	while (operate != NULL)
	{
		last = operate;
		operate = operate->next;
	}

	operate = (struct user*) malloc(sizeof(struct user));
	operate->next = NULL;
	operate->userGroup = userGroup;

	strcpy_s(operate->username, 1000, username);
	strcpy_s(operate->password, 1000, password);

	if (last != NULL)
	{
		last->next = operate;
	}

	if (userStart == NULL)
	{
		return operate;
	}
	else
	{
		return userStart;
	}
}

struct user* userCheckByWhichOne(struct user* userStart, long long int whichOne)
// It returns turns the adress of the struct
{
	long long int counter = 1;
	struct user* operate = userStart;
	while (counter != whichOne)
	{
		counter++;
		operate = operate->next;
	}
	return operate;
}

struct user* deleteUserByWhichOne(struct user* userStart, long long int whichOne)
// Please make sure there are items before calling this function.
// Don't forget to assign the result to userStart;
{
	long long int counter = 1;
	struct user* operate = userStart;
	if (whichOne != 0)
	{
		if (whichOne == 1) // If we are going to delete the 1st item.
		{
			//printf("We are going to delete %d!\n", 1);
			operate = operate->next;
			free(userStart);
			return operate;
		}
		else
		{
			struct user* last = NULL;
			while (counter != whichOne)
			{
				counter++;
				last = operate;
				operate = operate->next;
			}
			last->next = operate->next;
			free(operate);
			return userStart;
		}
	}
	else
	{
		return userStart;
	}
}