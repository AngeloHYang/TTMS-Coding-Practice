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

	//struct user* userStart = NULL;
	/*
	userStart = addUser(userStart, "Hello", "123", 1);
	userStart = addUser(userStart, "Bye", "123", 2);
	userStart = addUser(userStart, "God", "123", 0);

	userStart = deleteUserByWhichOne(userStart, 1);
	struct user* testUser = userStart;
	while (testUser != NULL)
	{
		printf("Name: %s, Group: %d\n", testUser->username, testUser->userGroup);
		testUser = testUser->next;
	}
	printf("There are %d users.\n", howManyUsersByKind(userStart, 1) + howManyUsersByKind(userStart, 0) + howManyUsersByKind(userStart, 2));
	
	printf("The NO.2 is %s\n", userCheckByWhichOne(userStart, 2)->username);
	*/
	printf("The test is over!\n");
	system("pause");
}