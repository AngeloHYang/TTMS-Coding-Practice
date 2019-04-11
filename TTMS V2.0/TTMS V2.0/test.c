#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"
#include "stringRelated.h"
#include "menuBar.h"

void test()
{
	// Size 20, 1024x768
	// abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV
	// 100 letters at most!
	
	printf("Hello, world!\n");
	printWithStartPlace("Aloha, ", 1, 1000);
	printf("\n");
	printWithStartPlace("'Oe", 5, 1000);

	system("pause");
}