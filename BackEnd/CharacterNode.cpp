#include <CharacterNode.h>

using namespace std;

// creates and returns a pointer to a CharacterDetails struct with attributes name and age
CharacterDetails* createCharacterDetails(string name, int age){
    CharacterDetails* character = (CharacterDetails*)malloc(sizeof(struct CharacterDetails));
    character->name = name;
    character->age = age;
    return character;
}

// creates and returns a pointer to a CharacterDetails struct with attributes name, age and details
CharacterDetails* createCharacterDetails(string name, int age, string details){
    CharacterDetails* character = (CharacterDetails*)malloc(sizeof(struct CharacterDetails));
    character->name = name;
    character->age = age;
    character->details = details;
    return character;
}

// creates the character node with the details for the character
CharacterNode* createCharacterNode(CharacterDetails* character){
    CharacterNode* charaNode = (CharacterNode*)malloc(sizeof(struct CharacterNode));
    charaNode->details = character;
    return charaNode; 
}

int main(){
    return 0;
}

