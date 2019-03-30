extern int howManyStudios(struct studio* studioStart);

extern struct studio* addStudio(struct studio* studioStart, long long int ID, int lines, int columns, long long int moviePlayingID);

extern struct studio* studioCheckByWhichOne(struct studio* studioStart, long long int whichOne);

extern struct studio* deleteStudioByWhichOne(struct studio* studioStart, long long int whichOne);
