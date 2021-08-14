#pragma once
#include <string>
#include <vector>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 30;

class Letters {
	//private:
	char letter;
	int location[2];

public:
	void getLetterSpelling(char letter) {
		this->letter = letter;
	}
	void getLetterLocation(int row, int col) {
		location[0] = row;
		location[1] = col;
	}

	void operator=(Letters item) {
		letter = item.letter;
	}
};


class Word {

public:
	Letters spell[16];
	string info;
	int length;

	Word(string name = "..." , string info = "...");
	void getWordLocation(int row, int col, int direction);
	void operator=(Word item);
	void getWordName(string name);
	void getWordInfo(string info);
};
