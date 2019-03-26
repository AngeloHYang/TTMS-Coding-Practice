#include "usedVariableTypes.h"
#include <stdlib.h>
#include <stdio.h>
#include "userRelated.h"

struct user* userStart;

void loadData()
{
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
	
	// Read users
	printf("Reading users...");
	errno_t err;
	FILE* userFile;
	err = fopen_s(&userFile, "users.dat", "rb+");
	//FILE* userFile = fopen("users.dat", "rb+");
	if (userFile == NULL)
	{
		userStart = NULL;
	}
	else
	{
		userStart = NULL;
		struct user* swap = (struct user*) malloc (sizeof(struct user));
		fread(swap, sizeof(struct user), 1, userFile);
		while (feof(userFile) == 0)
		{
			addUser(userStart, swap->username, swap->password, swap->userGroup);
			fread(swap, sizeof(struct user), 1, userFile);
		}
		fclose(userFile);
		free(swap);
	}
	printf("Done\n");
}

void saveData()
{
	;
}