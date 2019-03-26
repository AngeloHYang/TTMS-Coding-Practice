#include <stdio.h>
#include <stdlib.h>

extern void loadData();
extern void saveData();

int main()
{
	//printf("hello, world!\n");
	extern void test();
	test();

	//sloadData();
	//saveData();
	system("pause");
	return 0;
}