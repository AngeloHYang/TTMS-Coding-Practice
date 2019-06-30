#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "color.h"
#include "stringRelated.h"
#include "printChoices.h"
#include "timeRelated.h"

void test()
{
	// Size 20, 1024x768
	// abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV
	// 100 letters at most!
	
	char title[10] = "Test";
	char testMenu[5][10];
	memset(testMenu, '\0', sizeof(testMenu));

	char* pointers[5];
	for (long long int whichOne = 0; whichOne < 5; whichOne++)
	{
		pointers[whichOne] = testMenu[whichOne];
	}

	strcpy_s(pointers[0], 10, "One");
	strcpy_s(pointers[1], 10, "Two");
	strcpy_s(pointers[2], 10, "Three");
	strcpy_s(pointers[3], 10, "Four");
	strcpy_s(pointers[4], 10, "Five");

	extern int standardSelectMenuView(int currentBackGroundColor, int currentFontColor, char title[100], char** Menu, int menuItems);
	standardSelectMenuView(6, 7, title, pointers, 5);

	system("pause");
	system("cls");
	printTimeString(currentSecond());
	system("pause");
}