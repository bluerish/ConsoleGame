#pragma once
#include"Tools.h"
#include"Maps.h"
#include <conio.h>

enum { UP, DOWN, EXIT, SUBMIT };

int KeyControl();

void TitleDraw();
int MenuDraw();
void InfoDraw();

int MaplistDraw();
void drawMap();
void drawUI(Word& UI);

void ChangeMapState(Word& w);
int isCorrect(Word& w, vector<char>& playerAnswer);

void GameLoop(int);



