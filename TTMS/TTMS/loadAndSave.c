#include "usedVariableTypes.h"
#include <stdlib.h>
#include <stdio.h>
#include "userRelated.h"

struct user* userStart;
int today;

void loadData()
{
	errno_t err;
	// Read movies
	/*
	FILE* movieFile = fopen("movies.dat", "rb+");
	if (movieFile == NULL)
	{
		struct movie* movieStart = NULL;
	}
	else
	{

	}
	*/
	
	// Read today
	printf("Reading today...");
	FILE* dayFile;
	err = fopen_s(&dayFile, "today.dat", "rb+");
	int* daySwap = (int *)malloc(sizeof(int));
	if (dayFile == NULL)
	{
		today = 1;
	}
	else
	{
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
	printf("Done\n");
	//printf("test: %s\n", userStart->username);
}

void saveData()
{
	errno_t err;

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
	printf("Done\n");
}