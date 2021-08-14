#include "Maps.h"

Map::Map() {

    length = 0;    
    startData = NULL;
    lastData = NULL;

}

void Map::SaveData(const int mapContent[HEIGHT - 10][WIDTH], vector<Word>& gameWords) {
    
    //map 저장
    memcpy(map, mapContent, sizeof(map));

    //단어를 list에 저장
    int previous = 0;
    int current = 0;

    for (int i = 0; i < gameWords.size(); i++) {
        InsertItem(gameWords[i]);
    }
}

void Map::InsertItem(Word item)
// item is in the list; length has been incremented.
{
    WordType* location;

    location = new WordType;
    location->word = item;

    if (startData == NULL) {
        startData = location;       
    }
    else {
        location->back = lastData;
        location->next = NULL;
        lastData->next = location;
    }

    lastData = location;
    length++;
}

void Map::GetNextItem(bool& isEnd)
// Post:  Current position has been updated; item is current item.
{  
    if (currentWord == lastData) {
        isEnd = false;
    }
    else {
        currentWord = currentWord->next;
        isEnd = true;
    }
}

void Map::GetPreItem(bool& isEnd){
  
    if (currentWord == startData) {
        isEnd = false;
    }
    else {
        isEnd = true;
    }
}

void Map::GetCurrentItem(Word& item) {
    item = currentWord->word;
}

Word Map::GetCurrentItem() {
    return currentWord->word;
}


Map::~Map()
// Class destructor
{
    MakeEmpty();
}

void Map::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    WordType* tempPtr;

    for (int i = 0; i < length; i++) {
        tempPtr = startData;
        startData = startData->next;
        delete tempPtr;
    }

    length = 0;
}


void Map::ResetList()
// Post: Current position has been initialized.
{
    currentWord = startData;
}