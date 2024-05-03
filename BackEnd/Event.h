#include <iostream>
#include <ctime>
#include <CharacterNode.h>
#include <CharacterNode.h>

using namespace std;

struct Event {
    time_t startTime;  // time when this event began, this is what we sort by
    string eventName;  // name of the event
    string eventDetail {};  // details on the event
    Event* next = nullptr;  // point to the next event, defaulted as nullptr
    Event* prev = nullptr;  // point to the previous event, defaulted as nullptr
    CharacterNode* head = nullptr;  // head of the character linked list
    CharacterNode* tail = nullptr;  // tail of the character linked list 
};

Event* createEvent(time_t, string);
Event* createEvent(time_t, string, string);
bool checkForDuplicates(Event*, string);
bool addCharacter(Event* event, CharacterNode* character);

