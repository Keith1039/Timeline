#include <Timeline.h>

// create and return a Timeline struct from an inciding event
Timeline* createTimeline(Event* event){
    Timeline* timeline = (Timeline*)malloc(sizeof(Timeline));
    timeline->startingEvent = event;
    timeline->endingEvent = timeline->startingEvent;
    timeline->size++;
    return timeline;
}

// create a timeline from a set of pre-established events
Timeline* createTimeline(Event* events[]){
    Timeline* timeline = (Timeline*)malloc(sizeof(Timeline));
    int length = sizeof(events)/sizeof(events[0]);
    for (int i=0; length; i++){
        addToTimeline(timeline, events[i]); // add all the events in the array to the timeline
    }
}

// sorts the timeline
// this assumes that the head of the timeline is always the smallest value
void sortTimeline(Timeline* timeline){
    // we only care when we have 2 or more nodes
    if(timeline->size > 1){
        Event* tempNode = timeline->endingEvent;  // since this node is the newest, we check to sort it
        // if the new event happens earlier or at the same time, we make it the new head
        if(tempNode->startTime <= timeline->startingEvent->startTime){
            timeline->endingEvent = tempNode->prev;  // set the new tail
            tempNode->prev->next = nullptr;  // make the next tail point to null
            // fix the new starting event
            tempNode->next = timeline->startingEvent;
            timeline->startingEvent->prev = tempNode;
            timeline->startingEvent = tempNode;
        } else if(tempNode->startTime < tempNode->prev->startTime){
            bool spotFound = false;
            // if the new node is less the old tail we have to do some work
            timeline->endingEvent = tempNode->prev;  // set the new tail
            tempNode->prev->next = nullptr;  // make the next tail point to null
            // find a spot for this
            Event* travNode = timeline->startingEvent;
            // loop while we haven't found a spot
            while(!spotFound){
                travNode = travNode->next;  // move down 1 since the head has also been compared
                spotFound = tempNode->startTime <= travNode->startTime;  // compare the start times
            }
            // insert the values
            tempNode->prev = travNode->prev;
            travNode->prev = tempNode;
            tempNode->next = travNode;
        }
    }
}

bool addToTimeline(Timeline* timeline, Event* event){
    bool flag = false;
    if (event != nullptr){
        // set the event as the new head and tail of the timeline
        if(timeline->startingEvent == nullptr){
            timeline->startingEvent = event;
            timeline->endingEvent = timeline->startingEvent;
        } else {
            // set the new tail
            timeline->endingEvent->next = event;
            event->prev = timeline->endingEvent;
            timeline->endingEvent = timeline->endingEvent->next;
        }
        sortTimeline(timeline);  // sort the timeline everytime something is added
        timeline->size++;
        flag = true;
    }
    return flag;
}



