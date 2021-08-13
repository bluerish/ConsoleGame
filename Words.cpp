#pragma once
#include "Words.h"

Word::Word(string name, string info) {

	for (int i = 0; i < name.length(); i++) {
		spell[i].getLetterSpelling(name[i]);
	}

	length = name.length();
	this->info = info;
}

void Word::getWordLocation(int row, int col, int direction) {
	if (direction == 1) { //오른쪽 방향으로 생성됨
		for (int i = 0; i < length; i++) {
			spell[i].getLetterLocation(row, col+i);
		}
	}
	else if (direction == -1) { //아래쪽 방향으로 생성됨
		for (int i = 0; i < length; i++) {
			spell[i].getLetterLocation(row+i, col);
		}
	}
}


