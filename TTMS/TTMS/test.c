#include <stdio.h>
#include <string.h>
#include "stringRelated.h"
#include <stdlib.h>
void test()
{
	char testArray[1000] = "Hello, my love!     ";
	printf("%lld\n", strlen(testArray));
	//printf("Please input your password: ");
	//inputPassword(testArray, 1000);
	deleteSpaceInTheEnd(testArray, 1000);
	printf("%lld\n", strlen(testArray));
}