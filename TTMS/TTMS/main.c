#include <stdio.h>
#include <stdlib.h>

int main()
{
	//printf("hello, world!\n");
	extern char* inputPassword(char* inputStringSpace, int maxSize);
	char test[1000];
	inputPassword(test, 1000);

	system("pause");
	return 0;
}