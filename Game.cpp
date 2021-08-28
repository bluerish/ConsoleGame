#include "Game.h"


int tempMap[20][30]; //임시저장 배열
Map tempDefault;
int correct = 0;
Word tempWord;


vector<Word> easyW1{ cat, game, egg };
vector<int> easyD1{3,4,1,2,5,-1,5,5,1};

vector<Word> easyW2{ rain, night,hat, ant };
vector<int> easyD2{ 4,16,-1,6,15,1, 6,18,-1,4,19,-1 };

vector<Word> easyW3{ fire, rhythm, bicycle };
vector<int> easyD3{10,8,1,10,10,-1,12,7,1};

vector<Word> normalW1{ table, teapot, octopus, sunglasses, banana };
vector<int> normalD1{ 2, 3,1, 2,3,-1,6,3,1,6,9,-1,11,8,1 };

vector<Word> normalW2{ wallet, tissue, mask, mango, penguin, pencil };
vector<int> normalD2{3,4,-1,8,4,1,6,6,-1,6,6,1,4,8,-1,4,8,1};

vector<Word> normalW3{spoon, rose, curtain, chair,airplane,ruler };
vector<int> normalD3{3,12,-1,5,11,1,7,6,1,7,6,-1,7,10,-1,11,8,1};

vector<Word> hardW1{ aquarium,mosquito,museum,monument,navigation,vegetable, apple};
vector<int> hardD1{2,7,-1,3,4,1,3,4,-1,8,4,1,8,10,-1,10,10,1,10,15,-1};

vector<Word> hardW2{blizzard,pizza, doughnut, playground, classroom,radio,sword,omelet };
vector<int> hardD2{ 4,7,1,2,10,-1,4,14,-1,10,7,1,9,8,-1,10,12,-1,12,8,1,14,12,1 };

vector<Word> hardW3{ patient,physics,chemistry,mercury,psychology,sapphire,pearl };
vector<int> hardD3{ 3,4,1,3,4,-1,8,4,1, 8,7,-1,6,12,-1,7,12,1,6,19,-1};



int KeyControl() {
    char temp = _getch();

    switch (temp)
    {
    case '1':
        return UP;
        break;
    case '2':
        return DOWN;
        break;
    case '0':
        return EXIT;
        break;
    case ' ':
        return SUBMIT;
        break;
    default:
        return (int)temp;
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
        case EXIT: {
            return 2;
        }
        }
    }
}

void TitleDraw() {
    Gotoxy(10, 10);
    cout << "영단어 가로세로 퍼즐" << endl;
}

void InfoDraw() {
    system("cls");

    cout << "영단어 가로세로 퍼즐입니다." << endl;
    cout << "주어진 설명을 보고 어떤 영어 단어인지 입력하는 게임입니다." << endl;
    cout << "반드시 소문자로 한 글자씩 입력해주신 뒤 space를 눌러주세요." << endl;
    cout << "backspace 등 글자를 지우는 입력이 적용되지 않으니" << endl;
    cout << "잘못 입력하셨을 경우 space를 눌러서 초기화해주세요." << endl << endl;

    cout << "[]: 아직 정답을 맞추지 못한 문제입니다." << endl;
    cout << "(): 현재 정답을 입력 가능한 문제입니다." << endl<<endl;

    cout << "1: 커서를 위로 움직이거나 " << endl;
    cout << "이전 문제로 이동합니다." << endl<<endl;
    cout << "2: 커서를 아래로 움직이거나 " << endl;
    cout << "다음 문제로 이동합니다." <<endl<< endl;
    cout << "0: 게임을 나갑니다." << endl << endl;
    cout << "space: 결정 버튼." << endl;
    cout << "단어를 입력한 뒤에 반드시 space를 눌러야 적용됩니다." << endl;

    while (1) {
        if ((KeyControl() == SUBMIT) || (KeyControl() == EXIT)) {
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
        case EXIT: {
            return 3;
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
            else if (temp == 5)
                cout << "[]";
            else if (temp == 6)
                cout << "()";
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

void setMapCode(int mapCode) {
    int randCode=0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,2);

    randCode = dis(gen);

    if (mapCode == 0) {
        if (randCode == 0) {
            tempDefault.SaveData(easyM1, easyW1, easyD1);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 1) {
            tempDefault.SaveData(easyM2, easyW2, easyD2);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 2) {
            tempDefault.SaveData(easyM3, easyW3, easyD3);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
    }
    else if (mapCode == 1) {
        if (randCode == 0) {
            tempDefault.SaveData(normalM1, normalW1, normalD1);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 1) {
            tempDefault.SaveData(normalM2, normalW2, normalD2);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 2) {
            tempDefault.SaveData(normalM3, normalW3, normalD3);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
    }
    else if (mapCode == 2) {
        if (randCode == 0) {
            tempDefault.SaveData(hardM1, hardW1, hardD1);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 1) {
            tempDefault.SaveData(hardM2, hardW2, hardD2);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
        else if (randCode == 2) {
            tempDefault.SaveData(hardM3, hardW3, hardD3);
            memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        }
    }

}

void GameLoop(int mapCode) {
    int isPlaying = 1; //1이면 게임중, 0이면 게임 종료
    bool infoEnd = true;
    int answerNum = 0;

    vector<char> playerAnswer;
    int keyC;

    setMapCode(mapCode);

   
    CursorVisible(1);
    tempDefault.ResetList();
    tempWord = tempDefault.GetCurrentItem();

    ChangeMapState(tempWord);
    drawMap();
    drawUI(tempWord);
    Gotoxy(2, 26);


    while (isPlaying) {


        //drawMap();
        //drawUI(tempWord);        
        
        keyC = KeyControl();
        switch (keyC) {
        case DOWN: {
            tempDefault.GetNextItem(infoEnd);
            if (infoEnd) {
                tempWord.info.clear();
                ChangeMapState(tempWord);
                tempWord = tempDefault.GetCurrentItem();
                ChangeMapState(tempWord);
                drawMap();
                drawUI(tempWord);
                Gotoxy(2, 26);
                break;
            }
            break;
        }
        case UP: {
            tempDefault.GetPreItem(infoEnd);
            if (infoEnd) {
                tempWord.info.clear();
                ChangeMapState(tempWord);
                tempWord = tempDefault.GetCurrentItem();
                ChangeMapState(tempWord);
                drawMap();
                drawUI(tempWord);
                Gotoxy(2, 26);
                break;
            }
            break;
        }
        case EXIT: {
            Gotoxy(2, 26);
            cout << "                    ";
            Gotoxy(2, 26);
            cout << "정말로 게임을 나갑니까?";
            Gotoxy(2, 27);
            cout << "0을 한 번 더 누르면 게임을 나가게 됩니다.";

            keyC = KeyControl();
            if(keyC == EXIT)
                isPlaying = 0;
            else {
                drawMap();
                drawUI(tempWord);
                Gotoxy(2, 26);
            }
            break;
        }
        case SUBMIT: {
            if (tempWord.answer) {
                cout << "                 ";
                Gotoxy(2, 26);
                cout << "이미 정답을 맞춘 문제입니다.";
                Sleep(2000);
            }
            else {
                if (isCorrect(tempWord, playerAnswer)) {
                    answerNum++;
                    ChangeMapState(tempWord);
                }                                
            }
            drawMap();
            drawUI(tempWord);
            playerAnswer.clear();      
            Gotoxy(2, 26);


            if (answerNum == tempDefault.mapLength) {
                cout << "게임 클리어! 축하합니다!";
                Sleep(5000);
                isPlaying = 0;
            }

            break;
        }
        default: {
            playerAnswer.push_back(keyC);
            cout << (char)keyC << " ";
            break;
        }
        }
    }

    tempDefault.MakeEmpty();
}

void ChangeMapState(Word& w) {
    int row, col;
    char letter;

    if (w.answer) {
        for (int i = 0; i < w.length; i++) {
            w.spell[i].getLetterLocation(row, col);

            w.spell[i].getLetterSpelling(letter);
            cout << row << " " << col << " " << letter << endl;
            tempMap[row][col] = (int)letter;
        }
    }
    else {
        for (int i = 0; i < w.length; i++) {
            w.spell[i].getLetterLocation(row, col);

            if (tempMap[row][col] == 5) {
                tempMap[row][col] = 6;
            }
            else if (tempMap[row][col] == 6) {
                tempMap[row][col] = 5;
            }
        }
    }
}

bool isCorrect(Word& w, vector<char>& playerAnswer) {

    if (w.length == playerAnswer.size()) {
        char c;
        for (int i = 0; i < w.length; i++) { 
            w.spell[i].getLetterSpelling(c);
            if (c != playerAnswer[i]) {
                cout << " 은 정답이 아닙니다." << endl;
                Sleep(2000);
                return false;
            }
        }
        cout << " 은 정답입니다!" << endl;
        w.answer = true;
        tempDefault.SaveAnswer();
        Sleep(2000);
        return true;
    }
    else {
        cout << " 은 정답이 아닙니다." << endl;
        Sleep(2000);
        return false;
    }
}
