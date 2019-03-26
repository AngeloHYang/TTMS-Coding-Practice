extern int howManyUsersByKind(struct user* userStart, int userGroup);

extern struct user* addUser(struct user* userStart, char username[1000], char password[1000], int userGroup);