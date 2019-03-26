#include <stdio.h>
#include <string.h>
#include "stringRelated.h"
#include <stdlib.h>
#include "userRelated.h"
#include "usedVariableTypes.h"
void test()
{
	/*
	char testArray[1000] = "Hello, my love!     ";
	printf("%lld\n%sE\n", strlen(testArray), testArray);
	//printf("Please input your password: ");
	//inputPassword(testArray, 1000);
	deleteSpaceInTheEnd(testArray, 1000);
	printf("%lld\n%sE\n", strlen(testArray), testArray);
	*/
	struct user* userStart = NULL;
	userStart = addUser(userStart, "Hello", "123", 1);
	userStart = addUser(userStart, "Bye", "123", 2);
	userStart = addUser(userStart, "God", "123", 0);

	struct user* testUser = userStart;
	while (testUser != NULL)
	{
		printf("Name: %s, Group: %d\n", testUser->username, testUser->userGroup);
		testUser = testUser->next;
	}
}