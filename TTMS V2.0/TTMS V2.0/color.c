#include <stdio.h>
#include <stdlib.h>

/*
ANSI������:
QUOTE:
??\033[0m???�ر���������???����رյ�������ָ��֮ǰͨ��ANSI�������õ����ԣ���Щ���Եú�����\033[0m��ر�
??\033[1m???���ø�����??������������Ϊ����ɫ��
??\033[4m???�»���??
??\033[5m???��˸??
??\033[7m???����??
??\033[8m???����??
??\033[30m???--???\033[37m???����ǰ��ɫ??
??\033[40m???--???\033[47m???���ñ���ɫ??
??\033[nA???�������n��??
??\03[nB???�������n��??
??\033[nC???�������n��??
??\033[nD???�������n��??
??\033[y;xH���ù��λ��??
??\033[2J???����??
??\033[K???����ӹ�굽��β������??
??\033[s???������λ��??
??\033[u???�ָ����λ��??
??\033[?25l???���ع��??
??\33[?25h???��ʾ���
*/

int setBackgroundColor(int color)
// This clears the screen
// It returns the color value
{
	// 0 for Black
	// 1 for Red
	// 2 for Green
	// 3 for yello
	// 4 for blue
	// 5 for purple
	// 6 for dark green
	// 7 for white
	if (color >= 0 && color <= 7)
	{
		color += 40;
		printf("\033[%dm", color);
		color -= 40;
	}
	system("cls");
	return color;
}

int setFontColor(int color)
// It returns the color value
{
	// 0 for Black
	// 1 for Red
	// 2 for Green
	// 3 for yello
	// 4 for blue
	// 5 for purple
	// 6 for dark green
	// 7 for white
	if (color >= 0 && color <= 7)
	{
		color += 30;
		printf("\033[%dm", color);
		color -= 30;
	}
	return color;
}

int setFontBackGroudColor(int color)
// It returns the color value
{
	// 0 for Black
	// 1 for Red
	// 2 for Green
	// 3 for yello
	// 4 for blue
	// 5 for purple
	// 6 for dark green
	// 7 for white
	if (color >= 0 && color <= 7)
	{
		color += 40;
		printf("\033[%dm", color);
		color -= 40;
	}
	return color;
}

void startUnderLine()
{
	printf("\033[4m");
}

void startAsIfSelected()
{
	printf("\033[7m");
}

void withDrawColor()
{
	printf("\033[0m");
}