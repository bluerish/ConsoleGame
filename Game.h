#pragma once
#include"Tools.h"
#include <conio.h>

enum { UP, DOWN, LEFT, RIGHT, SUBMIT };

int KeyControl();

void TitleDraw();
int MenuDraw();
void InfoDraw();

int MaplistDraw();