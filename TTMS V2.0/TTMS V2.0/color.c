#include <stdio.h>
#include <stdlib.h>

/*
ANSI控制码:
QUOTE:
  \033[0m   关闭所有属性   这个关闭的属性是指的之前通过ANSI控制码获得的属性，这些属性得后遇到\033[0m会关闭
  \033[1m   设置高亮度  （光标过出均变为背景色）
  \033[4m   下划线  
  \033[5m   闪烁  
  \033[7m   反显  
  \033[8m   消隐  
  \033[30m   --   \033[37m   设置前景色  
  \033[40m   --   \033[47m   设置背景色  
  \033[nA   光标上移n行  
  \03[nB   光标下移n行  
  \033[nC   光标右移n行  
  \033[nD   光标左移n行  
  \033[y;xH设置光标位置  
  \033[2J   清屏  
  \033[K   清除从光标到行尾的内容  
  \033[s   保存光标位置  
  \033[u   恢复光标位置  
  \033[?25l   隐藏光标  
  \33[?25h   显示光标
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