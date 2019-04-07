#include <stdio.h>
#include <stdlib.h>

extern void loadData();
extern void saveData();

int main()
{
	//printf("hello, world!\n");
	


	loadData();

	extern void test();
	test();

	extern void login();
	login();
	
	saveData();
	system("pause");
	return 0;
}