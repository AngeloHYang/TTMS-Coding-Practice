// Every basic move you want to do to a string is here!

//#ifndef _stringRelated_
//#define _stringRelated_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void addLetterToString(char* inputStringSpace, int maxSize, char inputLetter) 
// If too long, exceeded letters will be ignored.
{
	int whichOne = 0;
	while (inputStringSpace[whichOne] != '\0' && whichOne < maxSize - 2)
	{
		whichOne++;
		if (whichOne >= maxSize - 2)
		{
			break;
		}
	}
	if (whichOne < maxSize - 2)
	{
		inputStringSpace[whichOne] = inputLetter;
	}
}

void removeLastLetterInString(char* inputStringSpace, int maxSize)
{
	int whichOne = maxSize - 1;
	while (whichOne >= 0 && inputStringSpace[whichOne] == '\0')
	{
		whichOne--;
	}
	inputStringSpace[whichOne] = '\0';
}

char* inputPassword(char* inputStringSpace, int maxSize)
{
	// Remember to put the * in a single line.
	memset(inputStringSpace, '\0', sizeof(char) * maxSize);
	char inputLetter = 'a';
	while (inputLetter != 13) //when the user doesn't press enter
	{
		inputLetter = _getch();
		if (inputLetter != 8 && inputLetter != 13)    // If not backspace, add the letter
		{
			addLetterToString(inputStringSpace, maxSize, inputLetter);
			printf("*");
		}
		else if (inputLetter != 13)
		{
			removeLastLetterInString(inputStringSpace, maxSize);
			printf("\b \b");
		}
		//printf("your input: %s\n", inputStringSpace);
	}
}

//#endif