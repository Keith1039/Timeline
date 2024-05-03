#include <Event.h>

using namespace std;

// creates and returns a pointer to event struct without an eventDetail string
Event* createEvent(time_t start, string eventName){
    Event* event = (Event*) malloc(sizeof(struct Event));
    event->startTime = start;
    event->eventName = eventName;
    return event;
}
// creates and returns a pointer to event struct with eventDetail
Event* createEvent(time_t start, string eventName, string eventDetail){
    Event* event = (Event*) malloc(sizeof(struct Event));
    event->startTime = start;
    event->eventName = eventName;
    event->eventDetail = eventDetail;
    return event;
}

// function that checks if the name already exists
bool checkForDuplicate(Event* event, string name){
    bool flag = true;
    CharacterNode* travNode = event->head;  // set the node
    while(travNode != nullptr & flag){
        flag = travNode->details->name != name;  // check the condition
    }
    return flag;
}

// function that adds a character to the linkedlist held by an event
// returns true if the character is successfully added, false otherwise
bool addCharacter(Event* event, CharacterNode* character){
    bool flag = false;
    // check for null pointers
    if (event != nullptr & character != nullptr){
        // if the head is empty set the character as the new head
        if(event->head == nullptr){
            event->head = character;  // set new head and tail
            event->tail = event->head;
            flag = true;  // set flag to true
        } else{
            CharacterNode* node = event->head;
            if (checkForDuplicate(event, character->details->name)){
                // set the new tail
                event->tail = character;
                event->tail = event->tail->next;
                flag = true;  // set flag to true
            }
        }
    }
    return flag;
}
