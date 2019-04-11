#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stringRelated.h"


int printMiddleAddjusted(char* inputThings, int maxSize)
// Return 1 if successfully printed
{
	char* toDeal = (char*)malloc(sizeof(char) * ((long long int)maxSize + 1));
	if (toDeal != NULL)
	{
		// Receive the array
		int sizeofToDeal = sizeof(char) * ((long long int)maxSize + 1);
		memset(toDeal, '\0', sizeofToDeal);
		strcpy_s(toDeal, maxSize, inputThings);

		// Print
		int startPlace = 50 - strlen(toDeal);
		for (int whichCharacter = 1; whichCharacter < startPlace; whichCharacter++)
		{
			printf(" ");
		}
		printf("%s", toDeal);
		free(toDeal);
		return 1;
	}
	else
	{
		printf("Failed!\n");
		return 0;
	}
}

int printNumberAndContentWithStartplace(int number, char* inputThings, int startPlace, int maxSize)
// Return 1 if successfully printed
{
	char* toDeal = (char*)malloc(sizeof(char) * ((long long int)maxSize + 1));
	if (toDeal != NULL)
	{
		// Receive the array
		int sizeofToDeal = sizeof(char) * ((long long int)maxSize + 1);
		memset(toDeal, '\0', sizeofToDeal);
		strcpy_s(toDeal, maxSize, inputThings);

		// Print
		for (int whichCharacter = 1; whichCharacter < startPlace; whichCharacter++)
		{
			printf(" ");
		}
		printf("%d) ", number);
		printf("%s", toDeal);
		free(toDeal);
		return 1;
	}
	else
	{
		printf("Failed!\n");
		return 0;
	}
}

int printWithStartPlace(char* inputThings, int startPlace, int maxSize)
// Return 1 if successfully printed
{
	char* toDeal = (char*)malloc(sizeof(char) * ((long long int)maxSize + 1));
	if (toDeal != NULL)
	{
		// Receive the array
		int sizeofToDeal = sizeof(char) * ((long long int)maxSize + 1);
		memset(toDeal, '\0', sizeofToDeal);
		strcpy_s(toDeal, maxSize, inputThings);

		// Print
		for (int whichCharacter = 1; whichCharacter < startPlace; whichCharacter++)
		{
			printf(" ");
		}
		printf("%s", toDeal);
		free(toDeal);
		return 1;
	}
	else
	{
		printf("Failed!\n");
		return 0;
	}
}