extern int howManyUsersByKind(struct user* userStart, int userGroup);
// Find out how many users are in the given group

extern struct user* addUser(struct user* userStart, char username[1000], char password[1000], int userGroup);
// Don't forget to assign the result to userStart;

extern struct user* userCheckByWhichOne(struct user* userStart, long long int whihcOne);
// It returns turns the adress of the struct

extern struct user* deleteUserByWhichOne(struct user* userStart, long long int whichOne);
// Please make sure there are items before calling this function.
// Don't forget to assign the result to userStart;