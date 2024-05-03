#include <Timeline.h>

// create and return a Timeline struct from an inciding event
Timeline* createTimeline(Event* event){
    Timeline* timeline = (Timeline*)malloc(sizeof(Timeline));
    timeline->startingEvent = event;
    timeline->endingEvent = timeline->startingEvent;
    return timeline;
}