#include <string>

using namespace std;

struct CharacterDetails{
    string name;  // name of the character
    int age;  // age of the character, assuming it isn't anything too big
    string details {};  // the details about that character, defaulted to empty string if not given
};
struct CharacterNode{
    CharacterDetails* details;  // struct containing information about the character
    CharacterNode* next = nullptr;  // next character
};

CharacterDetails* createCharacterDetails(string, int);
CharacterDetails* createCharacterDetails(string, int, string);
CharacterNode* createCharacterNode(CharacterDetails*);

