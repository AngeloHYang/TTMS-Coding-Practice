#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringRelated.h"
#include "usedVariableTypes.h"

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
			operate = operate->next;
		}
	}
	return counter;
}

struct user* addUser(struct user* userStart, char username[1000], char password[1000], int userGroup)
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

//struct userStart* deleteUser(struct user* userStart, char username[1000], char password[1000], int userGroup)
//{
	//;
//}