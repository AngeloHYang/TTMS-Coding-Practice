#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

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