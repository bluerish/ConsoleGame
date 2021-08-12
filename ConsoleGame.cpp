// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "ConsoleGame.h"
#include "Game.h"

using namespace std;







int main()
{
    Init();

    while (1) {
        TitleDraw();
        int menuCode = MenuDraw();
        int level = -1;
        switch (menuCode)
        {
        case 0:
            //게임시작
            level = MaplistDraw();
            switch (level) 
            {
            case 0:
                cout << " 쉬움 선택함" << endl;
                Sleep(1000);
                break;
            case 1:
                cout << " 보통 선택함" << endl;
                Sleep(1000);
                break;
            case 2:
                cout << " 어려움 선택함" << endl;
                Sleep(1000);
                break;
            defalut:
                break;
            }
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
