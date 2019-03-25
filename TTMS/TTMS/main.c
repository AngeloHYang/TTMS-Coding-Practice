#include <stdio.h>
#include <stdlib.h>
int main()
{
	//printf("hello, world!\n");
	extern void test();
	test();

	system("pause");
	return 0;
}