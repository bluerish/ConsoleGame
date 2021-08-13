#pragma once
#include"Tools.h"
#include"Maps.h"
#include <conio.h>

enum { UP, DOWN, LEFT, RIGHT, SUBMIT };

int KeyControl();

void TitleDraw();
int MenuDraw();
void InfoDraw();

int MaplistDraw();
void drawMap();
void drawUI();

void GameLoop(int);



