#include "Game.h"


int tempMap[20][30]; //임시저장 배열

int map1[5][5] = {
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1}
};





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

//

int MenuDraw() {
    int x = (WIDTH / 2) - 2;
    int y = HEIGHT / 2;
    int temp = y;

    Gotoxy(x - 1, temp);
    cout << "> 게임시작";
    Gotoxy(x, temp + 1);
    cout << "게임정보";
    Gotoxy(x, temp + 2);
    cout << "종료";

    while (1) {
        int n = KeyControl();
        switch (n) {
        case UP: {
            if (temp > y) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, --temp);
                cout << ">";
                
            }
            break;
        }
        case DOWN: {
            if (temp < y+2) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, ++temp);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return temp - y;
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
    int x = (WIDTH / 2) - 2;
    int y = HEIGHT / 2;
    int temp = y;

    Gotoxy(x - 1, temp);
    cout << "> 쉬움";
    Gotoxy(x, temp + 1);
    cout << "보통";
    Gotoxy(x, temp + 2);
    cout << "어려움";
    Gotoxy(x, temp + 3);
    cout << "뒤로";
    Gotoxy(x, temp);


    while (1) {
        int n = KeyControl();
        switch (n) {
        case UP: {
            if (temp > y) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, --temp);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (temp < y+3) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, ++temp);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return temp - y;
        }
        }
    }
}

//

void drawMap() {
    system("cls");
    int h, w, temp = -1;

    for (h = 0; h < HEIGHT-10; h++) {
        for (w = 0; w < WIDTH; w++) {
            temp = tempMap[h][w];
            if (temp == 1)
                cout << "##";
            else if (temp == -1)
                cout << "[]";
            else if (temp == 0)
                cout << "  ";
            else
                cout << (char)temp<<" ";
        }
        cout << endl;
    }
}

void drawUI() {
    Gotoxy(2, 22);
    cout << "설명이 나옵니다.";
}


void GameLoop(int mapCode) {
    int isPlaying = 1; //1이면 게임중, 0이면 게임 종료

    switch (mapCode) {
    case 0:
        memcpy(tempMap, easy1, sizeof(tempMap));
        break;
    case 1:
        break;
    }

    drawMap();
    CursorVisible(1);

    while (isPlaying) {
        drawUI();
        Gotoxy(2, 26);

        switch (KeyControl()) {
        case SUBMIT:
            isPlaying = 0;
        }
    }
}