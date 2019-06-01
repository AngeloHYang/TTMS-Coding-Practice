#include "usedVariableTypes.h"
#include <cstdlib>
#include <cstdio>
#include "userRelated.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"
#include "ticketRelated.h"

#include <iostream>
using namespace std;

struct user* userStart;
int today;
struct movie* movieStart;
struct studio* studioStart;
long long int movieIDCounter;
long long int studioIDCounter;
struct brokenSeatHistory* brokenSeatHistoryStart;
long long int ticketIDCounter;
struct ticketHistory* ticketHistoryStart;


void loadData()
{
	errno_t err;

	// Read movies
	cout << "Reading movies...";
	FILE* movieFile;
	err = fopen_s(&movieFile, "movies.dat", "rb+");
	movieStart = NULL;
	if (movieFile == NULL)
	{
		movieStart = NULL;
	}
	else
	{
		struct movie* movieSwap = (struct movie*) malloc (sizeof(struct movie));
		fread(movieSwap, sizeof(struct movie), 1, movieFile);
		while (feof(movieFile) != 1)
		{
			movieStart = addMovie(movieStart, movieSwap->name, movieSwap->price, movieSwap->ID, movieSwap->startDay, movieSwap->endDay);
			fread(movieSwap, sizeof(struct movie), 1, movieFile);
		}
		free(movieSwap);
		fclose(movieFile);
	}
	cout << "Done!" << endl;
	
	// Read movieIDCounter
	cout << "Reading movieIDCounter...";
	FILE* movieIDCounterFile;
	err = fopen_s(&movieIDCounterFile, "movieIDCounter.dat", "rb+");
	if (movieIDCounterFile == NULL)
	{
		movieIDCounter = 0;
	}
	else
	{
		long long int* movieIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		fread(movieIDCounterSwap, sizeof(long long int), 1, movieIDCounterFile);
		movieIDCounter = *movieIDCounterSwap;
		free(movieIDCounterSwap);
		fclose(movieIDCounterFile);
	}
	cout << "Done!" << endl;

	// Read ticketIDCounter
	cout << "Reading ticketIDCounter...";
	FILE* ticketIDCounterFile;
	err = fopen_s(&ticketIDCounterFile, "ticketIDCounter.dat", "rb+");
	if (ticketIDCounterFile == NULL)
	{
		ticketIDCounter = 0;
	}
	else
	{
		long long int* ticketIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		fread(ticketIDCounterSwap, sizeof(long long int), 1, ticketIDCounterFile);
		ticketIDCounter = *ticketIDCounterSwap;
		free(ticketIDCounterSwap);
		fclose(ticketIDCounterFile);
	}
	cout << "Done!" << endl;


	// Read studios
	cout << "Reading studios...";
	FILE* studioFile;
	err = fopen_s(&studioFile, "studios.dat", "rb+");
	studioStart = NULL;
	if (studioFile == NULL)
	{
		studioStart = NULL;
	}
	else
	{
		struct studio* studioSwap = (struct studio*) malloc(sizeof(struct studio));
		fread(studioSwap, sizeof(struct studio), 1, studioFile);
		while (feof(studioFile) != 1)
		{
			studioStart = addStudio(studioStart, studioSwap->ID, studioSwap->lines, studioSwap->columns, studioSwap->moviePlayingID);
			fread(studioSwap, sizeof(struct studio), 1, studioFile);
		}
		free(studioSwap);
		fclose(studioFile);
	}
	cout << "Done!" << endl;

	// Read studioIDCounter
	cout << "Reading studioIDCounter...";
	FILE* studioIDCounterFile;
	err = fopen_s(&studioIDCounterFile, "studioIDCounter.dat", "rb+");
	if (studioIDCounterFile == NULL)
	{
		studioIDCounter = 0;
	}
	else
	{
		long long int* studioIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		fread(studioIDCounterSwap, sizeof(long long int), 1, studioIDCounterFile);
		studioIDCounter = *studioIDCounterSwap;
		free(studioIDCounterSwap);
		fclose(studioIDCounterFile);
	}
	cout << "Done!" << endl;

	// Read today
	cout << "Reading today...";
	FILE* dayFile;
	err = fopen_s(&dayFile, "today.dat", "rb+");
	if (dayFile == NULL)
	{
		today = 1;
	}
	else
	{
		int* daySwap = (int *)malloc(sizeof(int));
		fread(daySwap, sizeof(int), 1, dayFile);
		today = *daySwap;
		free(daySwap);
		fclose(dayFile);
	}
	cout << "Done!" << endl;

	// Read users
	cout << "Reading users...";
	FILE* userFile;
	err = fopen_s(&userFile, "users.dat", "rb+");
	//FILE* userFile = fopen("users.dat", "rb+");
	if (userFile == NULL)  // If the file doesn't exist.
	{
		userStart = NULL;
	}
	else
	{
		userStart = NULL;
		struct user* userSwap = (struct user*) malloc (sizeof(struct user));
		fread(userSwap, sizeof(struct user), 1, userFile);
		while (feof(userFile) == 0)
		{
			userStart = addUser(userStart, userSwap->username, userSwap->password, userSwap->userGroup);
			fread(userSwap, sizeof(struct user), 1, userFile);
			//printf("We just get %s\n", userSwap->username);
		}
		fclose(userFile);
		free(userSwap);
	}
	cout << "Done!" << endl;
	//printf("test: %s\n", userStart->username);

	// Read brokenSeatHistory
	brokenSeatHistoryStart = NULL;
	cout << "Reading broken seats' history...";
	FILE* brokenSeatHistoryFile;
	err = fopen_s(&brokenSeatHistoryFile, "brokenSeatHistory.dat", "rb+");
	if (brokenSeatHistoryFile == NULL)  // If the file doesn't exist.
	{
		brokenSeatHistoryStart = NULL;
	}
	else
	{
		brokenSeatHistoryStart = NULL;
		struct brokenSeatHistory* brokenSeatHistorySwap = (struct brokenSeatHistory*) malloc(sizeof(struct brokenSeatHistory));
		fread(brokenSeatHistorySwap, sizeof(struct brokenSeatHistory), 1, brokenSeatHistoryFile);
		while (feof(brokenSeatHistoryFile) == 0)
		{
			brokenSeatHistoryStart = addBrokenSeatHistory(brokenSeatHistoryStart, brokenSeatHistorySwap->studioID, brokenSeatHistorySwap->whichLine, brokenSeatHistorySwap->whichColumn, brokenSeatHistorySwap->startDay, brokenSeatHistorySwap->endDay);
			fread(brokenSeatHistorySwap, sizeof(struct brokenSeatHistory), 1, brokenSeatHistoryFile);
		}
		fclose(brokenSeatHistoryFile);
		free(brokenSeatHistorySwap);
	}
	cout << "Done!" << endl;

	// Read ticketHistory
	ticketHistoryStart = NULL;
	cout << "Reading tickets' history...";
	FILE* ticketHistoryFile;
	err = fopen_s(&ticketHistoryFile, "ticketHistory.dat", "rb+");
	if (ticketHistoryFile == NULL)  // If the file doesn't exist.
	{
		ticketHistoryStart = NULL;
	}
	else
	{
		ticketHistoryStart = NULL;
		struct ticketHistory* ticketHistorySwap = (struct ticketHistory*) malloc(sizeof(struct ticketHistory));
		fread(ticketHistorySwap, sizeof(struct ticketHistory), 1, ticketHistoryFile);
		while (feof(ticketHistoryFile) == 0)
		{
			ticketHistoryStart = addTicketHistory(ticketHistoryStart, ticketHistorySwap->studioID, ticketHistorySwap->whichLine, ticketHistorySwap->whichColumn, ticketHistorySwap->shouldWatchDay, ticketHistorySwap->ticketID, ticketHistorySwap->movieID, ticketHistorySwap->status);
			fread(ticketHistorySwap, sizeof(struct ticketHistory), 1, ticketHistoryFile);
		}
		fclose(ticketHistoryFile);
		free(ticketHistorySwap);
	}
	cout << "Done!" << endl;
}

void saveData()
{
	errno_t err;
	system("cls");

	// Save movies
	cout << "Saving movies...";
	FILE* movieFile;
	err = fopen_s(&movieFile, "movies.dat", "wb+");
	struct movie* movieSwap = movieStart;
	while (movieSwap != NULL)
	{
		fwrite(movieSwap, sizeof(struct movie), 1, movieFile);
		movieSwap = movieSwap->next;
	}
	fclose(movieFile);
	cout << "Done!" << endl;

	// Save movieIDCounter
	cout << "Saving movieIDCounter...";
	FILE* movieIDCounterFile;
	err = fopen_s(&movieIDCounterFile, "movieIDCounter.dat", "wb+");
	if (movieIDCounterFile == NULL)
	{
		printf("movieIDCounterFile error\n");
	}
	else
	{
		long long int* movieIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		*movieIDCounterSwap = movieIDCounter;
		fwrite(movieIDCounterSwap, sizeof(long long int), 1, movieIDCounterFile);
		free(movieIDCounterSwap);
		fclose(movieIDCounterFile);
	}
	cout << "Done!" << endl;

	// Save ticketIDCounter
	cout << "Saving ticketIDCounter...";
	FILE* ticketIDCounterFile;
	err = fopen_s(&ticketIDCounterFile, "ticketIDCounter.dat", "wb+");
	if (ticketIDCounterFile == NULL)
	{
		cout << "ticketIDCounterFile error" << endl;
	}
	else
	{
		long long int* ticketIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		*ticketIDCounterSwap = ticketIDCounter;
		fwrite(ticketIDCounterSwap, sizeof(long long int), 1, ticketIDCounterFile);
		free(ticketIDCounterSwap);
		fclose(ticketIDCounterFile);
	}
	cout << "Done!" << endl;

	// Save studios
	cout << "Saving studios...";
	FILE* studioFile;
	err = fopen_s(&studioFile, "studios.dat", "wb+");
	struct studio* studioSwap = studioStart;
	while (studioSwap != NULL)
	{
		fwrite(studioSwap, sizeof(struct studio), 1, studioFile);
		studioSwap = studioSwap->next;
	}
	fclose(studioFile);
	cout << "Done!" << endl;

	// Save studioIDCounter
	cout << "Saving studioIDCounter...";
	FILE* studioIDCounterFile;
	err = fopen_s(&studioIDCounterFile, "studioIDCounter.dat", "wb+");
	if (studioIDCounterFile == NULL)
	{
		cout << "studioIDCounterFile error" << endl;
	}
	else
	{
		long long int* studioIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		*studioIDCounterSwap = studioIDCounter;
		fwrite(studioIDCounterSwap, sizeof(long long int), 1, studioIDCounterFile);
		free(studioIDCounterSwap);
		fclose(studioIDCounterFile);
	}
	cout << "Done!" << endl;

	// Save today
	cout << "Saving today...";
	FILE* dayFile;
	err = fopen_s(&dayFile, "today.dat", "wb+");
	int* daySwap = (int *)malloc(sizeof(int));
	*daySwap = today;
	fwrite(daySwap, sizeof(int), 1, dayFile);
	fclose(dayFile);
	free(daySwap);
	cout << "Done!" << endl;

	// Save users
	cout << "Saving users...";
	FILE* userFile;
	err = fopen_s(&userFile, "users.dat", "wb+");
	struct user* userSwap = userStart;
	while (userSwap != NULL)
	{
		fwrite(userSwap, sizeof(struct user), 1, userFile);
		userSwap = userSwap->next;
	}
	fclose(userFile);
	cout << "Done!" << endl;

	// Save brokenSeatHistory
	cout << "Saving broken seats' history...";
	FILE* brokenSeatHistoryFile;
	err = fopen_s(&brokenSeatHistoryFile, "brokenSeatHistory.dat", "wb+");
	struct brokenSeatHistory* brokenSeatHistorySwap = brokenSeatHistoryStart;
	while (brokenSeatHistorySwap != NULL)
	{
		fwrite(brokenSeatHistorySwap, sizeof(struct brokenSeatHistory), 1, brokenSeatHistoryFile);
		brokenSeatHistorySwap = brokenSeatHistorySwap->next;
	}
	fclose(brokenSeatHistoryFile);
	cout << "Done!" << endl;

	// Save ticketHistory
	cout << "Saving tickets' history...";
	FILE* ticketHistoryFile;
	err = fopen_s(&ticketHistoryFile, "ticketHistory.dat", "wb+");
	struct ticketHistory* ticketHistorySwap = ticketHistoryStart;
	while (ticketHistorySwap != NULL)
	{
		fwrite(ticketHistorySwap, sizeof(struct ticketHistory), 1, ticketHistoryFile);
		ticketHistorySwap = ticketHistorySwap->next;
	}
	fclose(ticketHistoryFile);
	cout << "Done!" << endl;
}