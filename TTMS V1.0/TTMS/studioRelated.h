extern int howManyStudios(struct studio* studioStart);

extern struct studio* addStudio(struct studio* studioStart, long long int ID, int lines, int columns, long long int moviePlayingID);

extern struct studio* studioCheckByWhichOne(struct studio* studioStart, long long int whichOne);

extern struct studio* deleteStudioByWhichOne(struct studio* studioStart, long long int whichOne);

extern int studioCheckByIDAndReturnWhichOne(struct studio* studioStart, long long int inputID);

extern int seatExist(struct studio* studioStart, long long int inputID, int whichLine, int whichColumn);

extern int seatTaken(struct studio* studioSwap, int today, int whichLine, int whichColumn, struct ticketHistory* ticketHistoryStart);

extern void printStudioByWhichOne(struct studio* studioStart, long long int whichStudio);

extern int movieIDExistInStudioWhichOne(struct studio* studioStart, long long int movieID, long long int whichOne);