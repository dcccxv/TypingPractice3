#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Record.h"
#include"Global.h"
#include"GameStart.h"
#include"word_process.h"
#include"Setting_prac.h"
#include"practice.h"
#include"LevelChallange.h"
#include"Console.h"
#include"Title.h"
#include"node_struct.h"

node* new_node;
snode * new;
int inputCount=0; //맞춘단어개수
int KOR_ENG = 1; // 언어선택
int back_KOR_ENG; // 언어 선택 ESC누를시 원래 값 고정
int hp = 3; // 체력
double Flame = 0; // delay함수에 넣을 값
int score = 0; //점수
int score_prop = 1; //점수배율
int Record;
char RecordName[21];
int Cusor_posX = 45; // 입력창 커서 x좌표
int Cusor_posY = 24;
int Limit; //제한시간
int LeftTime = 1;// 남은시간
int CheckEffect = 0; //단어에 넣는 효과변수
int Ef_swtich = 1; //효과모드 ON/ OFF
int WordNum = 200; // 게임에 사용할 단어개수
int gernerat_num = 1; // 한번에 생성할 단어 개수
int level;
int level_Re_switch = 0;  //레벨모드를 알리는 변수
int difficulty = 0; // 난이도 선택 변수
int ef_start1; // 1번효과 타이머
int ef_start2; // 2번효과 타이머
int ef_start3; // 3번효과 타이머
int ef_start4; // 4번 효과 타이머
int ef1 = 0; // 1번효과 스위치
int ef2 = 0; // 2번효과 스위치
int ef3 = 0; // 3번효과 스위치
int ef4 = 0; // 4번효과 스위치
int ef2_xpos; // 2번 효과로 고정되는 단어의 x좌표
int WordIndex = 0; // 입력함수 문자열의 인덱스
char InPutWord[STRLENGTH] = { '\0' }; // 입력 문자열

char Board[COLS][ROWS][STRLENGTH] = {
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ▧" },
	{ "▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧▧","▧▧▧" }
};


void MainMenu(void) {
	int select;
	unsigned char ch;
	int point = 0;
	int special_key = 0;
	int i = 0;
	int j = 0;
	int menu_cusorX = 65;
	int menu_cusorY = 18;
	int Languege_cusorX = 55;
	int Language_cusorY = 12;
	removeCursor(); //커서 지우기

	Title(); // 제목 출력

	while (1) {
		textcolor(WHITE, CYAN1);
		point = point % 6;

		switch(point) {
		case 0: 
			select = 1;
			gotoxy(menu_cusorX, menu_cusorY);
			printf("→");
			break;
		case 1:
			select = 2;
			gotoxy(menu_cusorX, menu_cusorY + 1);
			printf("→");
			break;
		case 2:
			select = 3;
			gotoxy(menu_cusorX, menu_cusorY + 2);
			printf("→");
			break;
		case 3:
			select = 4;
			gotoxy(menu_cusorX, menu_cusorY + 3);
			printf("→");
			break;
		case 4:
			select = 5;
			gotoxy(menu_cusorX, menu_cusorY + 4);
			printf("→");
			break;
		case 5:
			select = 6;
			gotoxy(menu_cusorX, menu_cusorY + 5);
			printf("→");
			break;
		default :
			point = 0;
			break;
		}

		if (kbhit() == 1) {  
			ch = getch(); 

			if (ch == SPECIAL1 || ch == SPECIAL2) { 
				special_key = 1;
				ch = getch();
			}

			if (ch == 13) { // 엔터입력시
				goto BPOINT;
			}
		}
		else {
			Sleep(100); 
		}

		if (special_key) { 
			switch (ch) {
			case UP:
				erase(menu_cusorX, menu_cusorY + point);
				point += 5;
				special_key = 0;
				break;
			case DOWN:
				erase(menu_cusorX, menu_cusorY + point);
				point ++;
				special_key = 0;
				break;
			}
		}
	} // while문 끝

BPOINT:
	if (select == 1) {
		if(GameStart() == -1) // 게임스타트 실행 , esc 입력시 -1 리턴
			return;
		word_process();
	}
	else if(select == 2) {
	    level_Re_switch = 1; 
		LevelChallange(); 
		level_Re_switch = 0; 
	}
	else if (select == 3) {
		if(Setting_prac() == -1) // 연습모드 설정, esc 입력시 -1 리턴
			return;
		practice();
	}
	else if (select == 4) {
		system("cls");
		ShowRecord();
		system("cls");
	}
	else if (select == 5) {
		removeCursor(); //커서 지우기
		select = 7; // 7일 경우 MainMenu 함수를 종료하고 루프에 의해 다시 실행
		back_KOR_ENG = KOR_ENG; // ESC 누를시 설정값이 변경되지 않게
		textcolor(BLACK, WHITE);
		gotoxy(Languege_cusorX, Language_cusorY-3);    printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY-2);    printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY-1);    printf("               언어선택               ");
		gotoxy(Languege_cusorX, Language_cusorY);      printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY + 1);  printf("               1. 한글                ");
		gotoxy(Languege_cusorX, Language_cusorY + 2);  printf("               2. 영어                ");
		gotoxy(Languege_cusorX, Language_cusorY + 3);  printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY + 4);  printf("                                      ");

		textcolor(BLACK, BLACK);
		box(Languege_cusorX - 2, Languege_cusorX + 38, Language_cusorY - 3, Language_cusorY + 4); // 박스그리기
		textcolor(BLACK, WHITE);
		

		while (1) { // 한글 영어 선택 UI
			textcolor(BLACK, WHITE);

			if (KOR_ENG > 2)
				KOR_ENG = 1;

			switch (KOR_ENG) {
			case 1: // 한글
				gotoxy(Languege_cusorX + 12, Language_cusorY + 1);
				printf("→");
				break;
			case 2: // 영어
				gotoxy(Languege_cusorX + 12, Language_cusorY + 2);
				printf("→");
				break;

			default:
				point = 0;
				break;
			}
		
			if (kbhit() == 1) {  // 키보드가 눌려져 있으면
				ch = getch(); 
		
				if(ch ==13) // ENTER
					break; // select가 7이 되기 때문에 Title을 호출안해도 메인메뉴가 종료되고 다시 메인메뉴가 호출됨.
				if(ch == 27) { // ESC 누를시 원래 설정값대로 해놓고 탈출
					KOR_ENG = back_KOR_ENG;
					break;
				}
				if (ch == SPECIAL1 || ch == SPECIAL2) { 
					special_key = 1;
					ch = getch();
				}

			}
			else 
				Sleep(100);

			if (special_key) {
				switch (ch) {
				case UP:
					erase(Languege_cusorX + 12, Language_cusorY + KOR_ENG);
					KOR_ENG++;
				    special_key = 0;
					break;

				case DOWN:
					erase(Languege_cusorX + 12, Language_cusorY + KOR_ENG);
					KOR_ENG++;
					special_key = 0;
					break;
				}
			}
		}
	}
	else if (select == 6)
		exit(0);
	else 
		; // 대기를 위해
}
