extern int howManyMovies(struct movie* movieStart);

extern struct movie* addMovie(struct movie* movieStart, char name[1000], int price, long long int movieID, long long int startDay, long long int endDay);

extern struct movie* movieCheckByWhichOne(struct movie* movieStart, long long int whichOne);

extern struct movie* deleteMovieByWhichOne(struct movie* movieStart, long long int whichOne);