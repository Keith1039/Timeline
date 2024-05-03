#include <Event.h>

struct Timeline {
    Event* startingEvent;
    Event* endingEvent;
    int size = 0;
};

Timeline* createTimeline(Event*);
Timeline* createTimeline(Event**);
void sortTimeline(Timeline*);
bool addToTimelne(Timeline*, Event*);