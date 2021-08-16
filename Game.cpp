#include "Game.h"


int tempMap[20][30]; //임시저장 배열
Map tempDefault;
int correct = 0;
Word tempWord;


vector<Word> easyW1{ cat, game, egg };
vector<int> D1{3,6,-1,4,4,1,6,6,-1};
int easyD1[3][3] = { {3,6,-1},{4,4,1},{6,6,-1}};
//Map easyMW1(easyM1, easyW1);

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
    case 'a':
    case 'A':
        return LEFT;
        break;
    case 'd':
    case 'D':
        return RIGHT;
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
    int h, w, temp = -1;
    system("cls");

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

void drawUI(Word& UI) {
    Gotoxy(2, 22);
    cout << "                          " << endl;
    cout << "                                 " << endl;
    Gotoxy(2, 22);
    cout << UI.info;
}


void GameLoop(int mapCode) {
    int isPlaying = 1; //1이면 게임중, 0이면 게임 종료
    bool infoEnd = true;

    switch (mapCode) {
    case 0: {
        tempDefault.SaveData(easyM1, easyW1, D1);            
        memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        break;
    }
    case 1:
        break;
    }
   
    CursorVisible(1);
    tempDefault.ResetList();
    tempDefault.GetCurrentItem(tempWord);

    drawMap();
    drawUI(tempWord);


    while (isPlaying) {


        //drawMap();
        //drawUI(tempWord);        
        Gotoxy(2, 26);


        switch (KeyControl()) {
        case RIGHT: {
            tempDefault.GetNextItem(infoEnd);
            if (infoEnd) {
                tempWord.info.clear();
                tempWord = tempDefault.GetCurrentItem();
                ChangeMapState(tempWord);
                drawMap();
                drawUI(tempWord);  
                break;
            }
            break;
        }
        case LEFT: {
            tempDefault.GetPreItem(infoEnd);
            if (infoEnd) {
                tempWord.info.clear();
                tempWord = tempDefault.GetCurrentItem();
                drawMap();
                drawUI(tempWord);
                break;
            }
            break;
        }
        case SUBMIT:
            isPlaying = 0;
            break;
        }
    }
}

void ChangeMapState(Word& w) {
    int row, col;
    char letter;

    for (int i = 0; i < w.length; i++) {
        w.spell[i].getLetterLocation(row, col);

        w.spell[i].getLetterSpelling(letter);
        cout << row << " " << col << " " << letter << endl;
        tempMap[row][col] = (int)letter;
    }
}