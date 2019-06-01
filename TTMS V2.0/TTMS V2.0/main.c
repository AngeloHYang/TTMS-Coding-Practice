#include <stdio.h>
#include <stdlib.h>
int main()
{
	//system("chcp 65001");
	extern void test();
	test();

	// Make everything normal
	printf("\033[0m");

	return 0;
}
