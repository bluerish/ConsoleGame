// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Init();
void TitleDraw();
int MenuDraw();
void InfoDraw();
void Gotoxy(int, int);

int KeyControl();

enum{UP, DOWN, LEFT, RIGHT, SUBMIT};

int main()
{
    Init();

    while (1) {
        TitleDraw();
        int menuCode = MenuDraw();
        switch (menuCode)
        {
        case 0:
            //게임시작
            break;
        case 1:
            InfoDraw();
            break;
        case 2:
            return 0;

        }
        system("cls");
    }

    return 0;
}

void Init() {
    system("mode con cols=80 lines=40");
    system("title AAA");
}

void TitleDraw() {
    cout << "Hello World!\n";
}

void InfoDraw() {
    system("cls");
    cout << "암튼 설명";

    while (1) {
        if (KeyControl() == SUBMIT) {
            break;
        }
    }
}

void Gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 2 * x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int MenuDraw() {
    int x = 20;
    int y = 30;
    Gotoxy(x-1, y);
    cout << "> 게임시작";
    Gotoxy(x, y+1);
    cout << "게임정보";
    Gotoxy(x, y+2);
    cout << "종료";

    while (1) {
        int n = KeyControl();
        switch (n) {
            case UP: {
                if (y > 30) {
                    Gotoxy(x - 1, y);
                    cout << " ";
                    Gotoxy(x - 1, --y);
                    cout << ">";
                }     
                break;
            }
            case DOWN: {
                if (y < 32) {
                    Gotoxy(x - 1, y);
                    cout << " ";
                    Gotoxy(x - 1, ++y);
                    cout << ">";
                }
                break;
            }
            case SUBMIT: {
                return y - 30;
            }
        }
    }
}

int KeyControl() {
    char temp = _getch();

    switch (temp)
    {
    case 'w':
    case 'W':
        return UP;
        break;
    case 's':
    case 'S':
        return DOWN;
        break;
    case ' ':
        return SUBMIT;
        break;
    default:
        break;
    }
}