#include "usedVariableTypes.h"
#include <stdlib.h>
#include <stdio.h>
#include "userRelated.h"
#include "movieRelated.h"
#include "studioRelated.h"
#include "brokenSeatHistory.h"

struct user* userStart;
int today;
struct movie* movieStart;
struct studio* studioStart;
long long int movieIDCounter;
long long int studioIDCounter;
struct brokenSeatHistory* brokenSeatHistoryStart;

void loadData()
{
	errno_t err;

	// Read movies
	printf("Reading movies...");
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
	printf("Done!\n");
	
	// Read movieIDCounter
	printf("Reading movieIDCounter...");
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
	printf("Done!\n");

	// Read studios
	printf("Reading studios...");
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
	printf("Done!\n");

	// Read studioIDCounter
	printf("Reading studioIDCounter...");
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
	printf("Done!\n");

	// Read today
	printf("Reading today...");
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
	printf("Done!\n");

	// Read users
	printf("Reading users...");	
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
	printf("Done!\n");
	//printf("test: %s\n", userStart->username);

	// Read brokenSeatHistory
	brokenSeatHistoryStart = NULL;
	printf("Reading broken seats' history...");
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
	printf("Done!\n");
}

void saveData()
{
	errno_t err;
	system("cls");

	// Save movies
	printf("Saving movies...");
	FILE* movieFile;
	err = fopen_s(&movieFile, "movies.dat", "wb+");
	struct movie* movieSwap = movieStart;
	while (movieSwap != NULL)
	{
		fwrite(movieSwap, sizeof(struct movie), 1, movieFile);
		movieSwap = movieSwap->next;
	}
	fclose(movieFile);
	printf("Done!\n");

	// Save movieIDCounter
	printf("Saving movieIDCounter...");
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
	printf("Done!\n");

	// Save studios
	printf("Saving studios...");
	FILE* studioFile;
	err = fopen_s(&studioFile, "studios.dat", "wb+");
	struct studio* studioSwap = studioStart;
	while (studioSwap != NULL)
	{
		fwrite(studioSwap, sizeof(struct studio), 1, studioFile);
		studioSwap = studioSwap->next;
	}
	fclose(studioFile);
	printf("Done!\n");

	// Save studioIDCounter
	printf("Saving studioIDCounter...");
	FILE* studioIDCounterFile;
	err = fopen_s(&studioIDCounterFile, "studioIDCounter.dat", "wb+");
	if (studioIDCounterFile == NULL)
	{
		printf("studioIDCounterFile error\n");
	}
	else
	{
		long long int* studioIDCounterSwap = (long long int*) malloc(sizeof(long long int));
		*studioIDCounterSwap = studioIDCounter;
		fwrite(studioIDCounterSwap, sizeof(long long int), 1, studioIDCounterFile);
		free(studioIDCounterSwap);
		fclose(studioIDCounterFile);
	}
	printf("Done!\n");

	// Save today
	printf("Saving today...");
	FILE* dayFile;
	err = fopen_s(&dayFile, "today.dat", "wb+");
	int* daySwap = (int *)malloc(sizeof(int));
	*daySwap = today;
	fwrite(daySwap, sizeof(int), 1, dayFile);
	fclose(dayFile);
	free(daySwap);
	printf("Done!\n");

	// Save users
	printf("Saving users...");
	FILE* userFile;
	err = fopen_s(&userFile, "users.dat", "wb+");
	struct user* userSwap = userStart;
	while (userSwap != NULL)
	{
		fwrite(userSwap, sizeof(struct user), 1, userFile);
		userSwap = userSwap->next;
	}
	fclose(userFile);
	printf("Done!\n");

	// Save brokenSeatHistory
	printf("Saving broken seats' history...");
	FILE* brokenSeatHistoryFile;
	err = fopen_s(&brokenSeatHistoryFile, "brokenSeatHistory.dat", "wb+");
	struct brokenSeatHistory* brokenSeatHistorySwap = brokenSeatHistoryStart;
	while (brokenSeatHistorySwap != NULL)
	{
		fwrite(brokenSeatHistorySwap, sizeof(struct brokenSeatHistory), 1, brokenSeatHistoryFile);
		brokenSeatHistorySwap = brokenSeatHistorySwap->next;
	}
	fclose(brokenSeatHistoryFile);
	printf("Done!\n");
}