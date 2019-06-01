#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stringRelated.h"
#include "timeRelated.h"


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

void anotherLine(int lines)
{
	for (long long int whichOne = 1; whichOne <= lines; whichOne++)
	printf("\n");
}

void printTitle(char* title, int maxSize)
// This takes three lines with no wordwarp
{
	int size = strlen(title);
	if (size > maxSize)
	{
		size = maxSize;
	}
	for (long long int whichOne = 1; whichOne <= strlen(title) + 6; whichOne++)
	{
		printf("-");
	}
	printf("\n");
	printf("-| ");
	printf("%s", title);
	printf(" |-\n");
	for (long long int whichOne = 1; whichOne <= strlen(title) + 6; whichOne++)
	{
		printf("-");
	}
}

void printMultipleTimes(char character, int times)
{
	for (long long int whichTime = 1; whichTime <= times; whichTime++)
	{
		printf("%c", character);
	}
}

void printTitleWithCurrentTime(char* title, int maxSize)
// This takes three lines with no wordwarp
{
	int size = strlen(title);
	if (size > maxSize)
	{
		size = maxSize;
	}
	for (long long int whichOne = 1; whichOne <= strlen(title) + 6; whichOne++)
	{
		printf("-");
	}
	printf("\n");
	printf("-| ");
	printf("%s", title);
	printf(" |-");
	printMultipleTimes(' ', 100 - timeStringLength(currentSecond()) - strlen(title) - 6);
	printTimeString(currentSecond());
	printf("\n");
	for (long long int whichOne = 1; whichOne <= strlen(title) + 6; whichOne++)
	{
		printf("-");
	}
}

void print_(int howMany)
{
	for (long long int whichOne = 1; whichOne <= howMany; whichOne++)
	{
		printf("_");
	}
}

