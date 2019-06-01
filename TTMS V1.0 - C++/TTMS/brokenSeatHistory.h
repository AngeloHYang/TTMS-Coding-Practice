extern int seatIsBrokenToday(struct brokenSeatHistory* brokenSeatHistoryStart, int today, long long int studioID, int whichLine, int whichColumn);

extern struct brokenSeatHistory* addBrokenSeatHistory(struct brokenSeatHistory* brokenSeatHistoryStart, long long int studioID, int whichLine, int whichOne, long long int startDay, long long int endDay);

extern struct brokenSeatHistory* brokenSeatHistoryCheckByWhichOne(struct brokenSeatHistory* brokenSeatHistoryStart, long long int whichOne);

extern int howManyBrokenSeatHistory(struct brokenSeatHistory* brokenSeatHistoryStart);

extern int seatIsBrokenInRange(struct brokenSeatHistory* brokenSeatHistoryStart, int from, int to, long long int studioID, int whichLine, int whichColumn);