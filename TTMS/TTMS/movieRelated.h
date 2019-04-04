extern int howManyMovies(struct movie* movieStart);

extern struct movie* addMovie(struct movie* movieStart, char name[1000], int price, long long int movieID, long long int startDay, long long int endDay);

extern struct movie* movieCheckByWhichOne(struct movie* movieStart, long long int whichOne);

extern struct movie* deleteMovieByWhichOne(struct movie* movieStart, long long int whichOne);

extern struct movie* movieCheckByID(long long int inputID);

extern int movieWhichOneIfAvailableToday(int today, long long int whichOne, struct movie* movieStart);

extern int movieExistByName(char inputName[1000], struct movie* movieStart);

extern void printMovieByWhichOne(struct movie* movieStart, long long int whichOne);

extern long long int movieIDToWhichOne(long long int movieID, struct movie* movieStart);