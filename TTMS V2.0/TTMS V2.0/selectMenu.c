#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "stringRelated.h"
#include "printChoices.h"
#include "color.h"

int standardSelectMenuView(int currentBackGroundColor, int currentFontColor, char title[100], char** Menu, int menuItems)
// It returns the selection of the user
{
	int cursorPlace = 0;
	char pressedButton = '0';
	setBackgroundColor(currentBackGroundColor);

	while (pressedButton != 'q' && pressedButton != 'Q')
	{
		setBackgroundColor(currentBackGroundColor);
		setFontColor(currentFontColor);
		system("cls");
		printTitleWithCurrentTime(title, 100);
		anotherLine(5);

		for (long long int whichOne = 0; whichOne < menuItems; whichOne++)
		{
			if (whichOne == cursorPlace)
			{
				printMultipleTimes(' ', 45);
				startAsIfSelected();
				printf("%s", Menu[whichOne]);
				withDrawColor();
				setFontColor(currentFontColor);
				setFontBackGroudColor(currentBackGroundColor);
				printf("\n");
			}
			else
			{
				printMultipleTimes(' ', 45);
				printf("%s\n", Menu[whichOne]);
			}
		}

		anotherLine(6);
		print_(100);
		printf("\n\n ¡ñ Switch with \"W\", \"S\". Return with \"Q\". Select with \"Enter\".\n");

		pressedButton = _getch();
		if (cursorPlace < menuItems - 1 && (pressedButton == 's' || pressedButton == 'S'))
		{
			cursorPlace++;
		}
		if (cursorPlace > 0 && (pressedButton == 'w' || pressedButton == 'W'))
		{
			cursorPlace--;
		}
		


	}

}