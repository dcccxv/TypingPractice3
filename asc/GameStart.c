#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Global.h"
#include"Console.h"

int GameStart(void) {
	int Difficulty_cusorX = 55;
	int Difficulty_cusorY = 12;
	int special_key = 0;
	int LevelSelect = 1;
	unsigned char ch;

	while (Flame == 0) {
		difficulty = 0;
		system("cls");

		removeCursor(); //커서 지우기
		textcolor(BLACK, WHITE);
		
		gotoxy(Difficulty_cusorX, Difficulty_cusorY - 2);    printf("                                      ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY-1);		 printf("             난이도 선택              ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY + 0);	 printf("                                      ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY + 1);	 printf("               1. 쉬움                ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY + 2);	 printf("               2. 보통                ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY + 3);	 printf("               3. 어려움              ");
		gotoxy(Difficulty_cusorX, Difficulty_cusorY + 4);    printf("                                      ");
		
        border(); //테두리 그리기

		textcolor(BLACK, BLACK);
		box(Difficulty_cusorX - 2, Difficulty_cusorX + 39, Difficulty_cusorY-3, Difficulty_cusorY + 5); // 박스 그리기
		textcolor(BLACK, WHITE);
		
		while (1) {
			textcolor(BLACK, WHITE);

			if (LevelSelect > 3)
				LevelSelect = 1;
			if (LevelSelect < 1)
				LevelSelect = 3;

			switch (LevelSelect) {
			case 1:
				gotoxy(Difficulty_cusorX + 12, Difficulty_cusorY + 1);
				difficulty = 1;
				printf("→");
				break;
			case 2:
				gotoxy(Difficulty_cusorX + 12, Difficulty_cusorY + 2);
				difficulty = 2;
				printf("→");
				break;
			case 3:
				gotoxy(Difficulty_cusorX + 12, Difficulty_cusorY + 3);
				difficulty = 3;
				printf("→");
				break;
			default:
				difficulty = 1;
				break;
			}

			if (kbhit() == 1) {  // 키보드가 눌려져 있으면
				ch = getch();

				if (ch == SPECIAL1 || ch == SPECIAL2) {
					special_key = 1;
					ch = getch();
				}

				if (ch == 13) {// 엔터입력시
					goto DPOINT;
					break;
				}

				if (ch == 27)
					return -1;
			}
			else
				Sleep(200);

			if (special_key) {
				switch (ch) {
				case UP:
					erase(Difficulty_cusorX + 12, Difficulty_cusorY + LevelSelect);
					LevelSelect--;
					special_key = 0;
					break;

				case DOWN:
					erase(Difficulty_cusorX + 12, Difficulty_cusorY + LevelSelect);
					LevelSelect++;
					special_key = 0;
					break;
				}
			}
		}

DPOINT:
		switch (difficulty) {
		case 1:
			Flame = 1.5;
			Limit = EASYTIME;
			hp = 7;
			gernerat_num = 1;
			system("cls");
			break;
		case 2:
			Flame = 1.2;
			Limit = NOMALTIME;
			hp = 5;
			gernerat_num = 2;
			system("cls");
			break;
		case 3:
			Flame = 0.9;
			Limit = HARDTIME;
			hp = 3;
			gernerat_num = 3;
			system("cls");
			break;
		default:
			system("cls");
			printf("잘못된 입력입니다.\n");
			Sleep(1500); 
			continue;
		}
	}

	return 0;
}