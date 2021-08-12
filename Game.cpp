#include "Game.h"


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

int MenuDraw() {
    int x = 20;
    int y = 30;
    Gotoxy(x - 1, y);
    cout << "> 게임시작";
    Gotoxy(x, y + 1);
    cout << "게임정보";
    Gotoxy(x, y + 2);
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

int MaplistDraw() {
    system("cls");
    int x = 20;
    int y = 20;
    Gotoxy(x - 1, y);
    cout << "> 쉬움";
    Gotoxy(x, y + 1);
    cout << "보통";
    Gotoxy(x, y + 2);
    cout << "어려움";
    Gotoxy(x, y + 3);
    cout << "뒤로";

    while (1) {
        int n = KeyControl();
        switch (n) {
        case UP: {
            if (y > 20) {
                Gotoxy(x - 1, y);
                cout << " ";
                Gotoxy(x - 1, --y);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 23) {
                Gotoxy(x - 1, y);
                cout << " ";
                Gotoxy(x - 1, ++y);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return y - 20;
        }
        }
    }
}