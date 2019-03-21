#pragma once
struct movie
{
	char name[1000];
	int price;
	long long int ID;
	long long int startDay;
	long long int endDay;
	struct movie* next;
};

struct studio
{
	long long int ID;
	int lines;
	int columns;
	long long int moviePlayingID;
	struct studio* next;
};

struct ticketHistory
{
	long long int TicketID;
	long long int movieID;
	long long int shouldWatchDay;
	int status; // 0 for not sold, 1 for sold, 2 for watched, 3 for returned.
	struct ticketHistory* next;
};

struct brokenSeatHistory
{
	long long int brokenSeatID;
	long long int studioID;
	int whichLine;
	int whichColumn;
	long long int startDay;
	long long int endDay;
};