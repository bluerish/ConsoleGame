#include "Game.h"


int tempMap[20][30]; //�ӽ����� �迭
Map tempDefault;
int correct = 0;
Word tempWord;


vector<Word> easyW1{ cat, game, egg };
vector<int> easyD1{3,4,1,2,5,-1,5,5,1};

vector<Word> normalW1{ table, teapot, octopus, sunglasses, banana };
vector<int> normalD1{ 2, 3,1, 2,3,-1,6,3,1,6,9,-1,11,8,1 };


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
    cout << "> ���ӽ���";
    Gotoxy(x, temp + 1);
    cout << "��������";
    Gotoxy(x, temp + 2);
    cout << "����";

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
    cout << "���ܾ� ���μ��� ����" << endl;
}

void InfoDraw() {
    system("cls");

    cout << "���ܾ� ���μ��� �����Դϴ�." << endl;
    cout << "�־��� ������ ���� � ���� �ܾ����� �Է��ϴ� �����Դϴ�." << endl;
    cout << "�ݵ�� �ҹ��ڷ� �� ���ھ� �Է����ֽ� �� space�� �����ּ���." << endl;
    cout << "backspace �� ���ڸ� ����� �Է��� ������� ������" << endl;
    cout << "�߸� �Է��ϼ��� ��� space�� ������ �ʱ�ȭ���ּ���." << endl << endl;

    cout << "[]: ���� ������ ������ ���� �����Դϴ�." << endl;
    cout << "(): ���� ������ �Է� ������ �����Դϴ�." << endl<<endl;

    cout << "1: Ŀ���� ���� �����̰ų� " << endl;
    cout << "���� ������ �̵��մϴ�." << endl<<endl;
    cout << "2: Ŀ���� �Ʒ��� �����̰ų� " << endl;
    cout << "���� ������ �̵��մϴ�." <<endl<< endl;
    cout << "0: ������ �����ϴ�." << endl << endl;
    cout << "space: ���� ��ư." << endl;
    cout << "�ܾ �Է��� �ڿ� �ݵ�� space�� ������ ����˴ϴ�." << endl;

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
    cout << "> ����";
    Gotoxy(x, temp + 1);
    cout << "����";
    Gotoxy(x, temp + 2);
    cout << "�����";
    Gotoxy(x, temp + 3);
    cout << "�ڷ�";
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


void GameLoop(int mapCode) {
    int isPlaying = 1; //1�̸� ������, 0�̸� ���� ����
    bool infoEnd = true;
    int answerNum = 0;

    vector<char> playerAnswer;
    int keyC;


    switch (mapCode) {
    case 0: {
        tempDefault.SaveData(easyM1, easyW1, easyD1);            
        memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        break;
    }
    case 1:{
        tempDefault.SaveData(normalM1, normalW1, normalD1);
        memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        break;
    }
    case 2: {
        tempDefault.SaveData(easyM1, easyW1, easyD1);
        memcpy(tempMap, tempDefault.map, sizeof(tempMap));
        break;
    }
}
   
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
            cout << "������ ������ �����ϱ�?";
            Gotoxy(2, 27);
            cout << "0�� �� �� �� ������ ������ ������ �˴ϴ�.";

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
                cout << "�̹� ������ ���� �����Դϴ�.";
                Sleep(2000);
            }
            else {
                answerNum = answerNum + isCorrect(tempWord, playerAnswer);                
            }

            playerAnswer.clear();      
            ChangeMapState(tempWord);
            drawMap();
            drawUI(tempWord);
            Gotoxy(2, 26);


            if (answerNum == tempDefault.mapLength) {
                cout << "���� Ŭ����! �����մϴ�!";
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

int isCorrect(Word& w, vector<char>& playerAnswer) {

    if (w.length == playerAnswer.size()) {
        char c;
        for (int i = 0; i < w.length; i++) { 
            w.spell[i].getLetterSpelling(c);
            if (c != playerAnswer[i]) {
                cout << " �� ������ �ƴմϴ�." << endl;
                Sleep(2000);
                return 0;
            }
        }
        cout << " �� �����Դϴ�!" << endl;
        w.answer = true;
        Sleep(2000);
        return 1;
    }
    else {
        cout << " �� ������ �ƴմϴ�." << endl;
        Sleep(2000);
        return 0;
    }
}
