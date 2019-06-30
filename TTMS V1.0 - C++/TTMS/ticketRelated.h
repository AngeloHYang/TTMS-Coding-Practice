extern int howManyTicketHistory(struct ticketHistory* ticketHistoryStart);

extern struct ticketHistory* addTicketHistory(struct ticketHistory* ticketHistoryStart, long long int studioID, int whichLine, int whichColumn, long long int shouldWatchDay, long long int ticketID, long long int movieID, int status);

extern struct ticketHistory* ticketHistoryCheckByWhichOne(struct ticketHistory* ticketHistoryStart, long long int whichOne);

extern struct ticketHistory* ticketHistoryCheckByID(long long int inputID);

extern struct ticketHistory* unsoldOrWatchedTicketHistoryCheckByStudioAndPlaceAndDay(struct ticketHistory* ticketHistoryStart, struct studio* studioSwap, int today, int whichLine, int whichColumn);

extern void printTicket(struct ticketHistory* ticketHistorySwap);