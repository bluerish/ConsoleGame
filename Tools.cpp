
#include "Tools.h"



void Init() {
    system("mode con cols=80 lines=40");
    system("title AAA");

    //Ŀ�� ����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}



void Gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 2 * x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
