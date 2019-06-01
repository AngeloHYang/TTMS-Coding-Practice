#include <stdio.h>
#include <time.h>
#include <string.h>

int currentSecond()
{
	time_t current;
	time(&current);

	return (int)current;
}

struct tm totalSecondToStruct_tm(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult;
}

int totalSecondToYear(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_year + 1900;
}

int totalSecondToMonth(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_mon + 1;
}

int totalSecondToYearDay(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_yday;
}

int totalSecondToMonthDay(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_mday;
}

int totalSecondToWeekDay(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_wday;
}

int totalSecondToHour(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_hour;
}

int totalSecondToMinute(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_min;
}

int totalSecondToSecond(int secondValue)
{
	time_t second = secondValue;

	struct tm timeResult;
	localtime_s(&timeResult, &second);

	return timeResult.tm_sec;
}

void printTimeString(int secondValue)
{
	time_t second = secondValue;
	errno_t test;
	char string[1000];
	memset(string, '\0', sizeof(string));
	test = ctime_s(string, 1000, &second);

	// cancel new line
	for (int whichOne = strlen(string) - 1; whichOne >= 0; whichOne--)
	{
		if (string[whichOne] == '\n')
		{
			string[whichOne] = '\0';
			break;
		}
	}
	printf("%s", string);
}

int timeStringLength(int secondValue)
{
	time_t second = secondValue;
	errno_t test;
	char string[1000];
	memset(string, '\0', sizeof(string));
	test = ctime_s(string, 1000, &second);

	// cancel new line
	for (int whichOne = strlen(string) - 1; whichOne >= 0; whichOne--)
	{
		if (string[whichOne] == '\n')
		{
			string[whichOne] = '\0';
			break;
		}
	}
	return strlen(string);
}