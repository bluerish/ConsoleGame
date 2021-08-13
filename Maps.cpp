#include "Maps.h"

Map::Map(int mapContent[HEIGHT - 10][WIDTH], vector<Word>& gameWords) {

    length = 0;
    startData = NULL;
    lastData = NULL;
    currentWord = NULL;

    //map 저장
	memcpy(map, mapContent, sizeof(map));

    //단어를 list에 저장
    int previous = 0;
    int current = 0;


    for (int i = 0; i < gameWords.size(); i++) {

    }



}

void Map::InsertItem(Word item)
// item is in the list; length has been incremented.
{
    WordType* location;

    location = new WordType;
    location->word = item;

    if (startData == NULL) {
        location->back = NULL;
        location->next = NULL;
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

void Map::GetNextItem(Word& item)
// Post:  Current position has been updated; item is current item.
{

    currentWord = currentWord->next;
    item = currentWord->word;
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

    while (lastData != NULL)
    {
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