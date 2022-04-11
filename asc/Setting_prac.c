#include"practice.h"
#include"Global.h"
#include"Console.h"
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"Console.h"

int Setting_prac(void) {
	unsigned char ch; // 특수키 0xe0 을 입력받으려면 unsigned char 로 선언해야 함
	int set_sp = 1;  // 설정값들의 인덱스
	int set_hp = 1;
	int set_ef = 1;
	int set_Limit = 1;
	int set_wordnum = 1;
	int set_wordgern = 1;
	int point = 0;
	int special_key = 0;
	char set[6][3][6] = { {"EASY ", "NOMAL", "HARD "}, {"3", "5", "7"}, {"OFF", "ON "}, {"120 ", "150", "180"}, {"100", "150", "200"}, {"1", "2", "3"} };
	system("cls");

	
	
	textcolor(BLACK, WHITE);
	gotoxy(43, 9);
	printf("                                                            "); gotoxy(43, 10);
	printf("                           설정                             "); gotoxy(43, 11);
	printf("                                                            "); gotoxy(43, 12);
	printf("                                                            "); gotoxy(43, 13);
	printf("                                                            "); gotoxy(43, 14);
	printf("                                                            "); gotoxy(43, 15);
	printf("                                                            "); gotoxy(43, 16);
	printf("                                                            "); gotoxy(43, 17);
	printf("                                                            "); gotoxy(43, 18);
	printf("                                                            "); gotoxy(43, 19);
	printf("                                                            ");
	
	textcolor(BLACK,BLACK);
	box(43, 103, 8, 20);

	
	textcolor(BLACK,WHITE);
	gotoxy(69, 12); printf("속도 : ◀       ▶");
	gotoxy(79, 12); printf("%s", &(set[0][set_sp]));

	gotoxy(69, 13); printf("체력 : ◀       ▶");
	gotoxy(81, 13); printf("%s", &(set[1][set_hp]));

	gotoxy(67, 14); printf("이펙트 : ◀       ▶");
	gotoxy(80, 14); printf("%s", &(set[2][set_ef]));

	gotoxy(65, 15); printf("제한시간 : ◀       ▶");
	gotoxy(80, 15); printf("%s", &(set[3][set_Limit]));

	gotoxy(59, 16); printf("총 단어의 개수 : ◀       ▶");
	gotoxy(80, 16); printf("%s", &(set[4][set_wordnum]));

	gotoxy(53, 17); printf("한번에 나오는 단어수 : ◀       ▶");
	gotoxy(81, 17); printf("%s", &(set[5][set_wordgern]));
	
	while (1) {
		point = point % 6;
		set_sp = set_sp % 3;
		set_hp = set_hp % 3;
		set_ef = set_ef % 2;
		set_Limit = set_Limit % 3;
		set_wordnum = set_wordnum % 3;
		set_wordgern = set_wordgern % 3;
		removeCursor(); //커서 지우기

		switch(point) {
		case 0: 
			gotoxy(66, 12);
			printf("→");
			gotoxy(79, 12); printf("%s", &(set[0][set_sp]));
			break;
		case 1:
			gotoxy(66, 13);
			printf("→");
			gotoxy(81, 13); printf("%s", &(set[1][set_hp]));
			break;
		case 2:
			gotoxy(64, 14);
			printf("→");
			gotoxy(80, 14); printf("%s", &(set[2][set_ef]));
			break;
		case 3:
			gotoxy(62, 15);
			printf("→");
			gotoxy(80, 15); printf("%s", &(set[3][set_Limit]));
			break;
		case 4:
			gotoxy(56, 16);
			printf("→");
			gotoxy(80, 16); printf("%s", &(set[4][set_wordnum]));
			break;
		case 5:
			gotoxy(50, 17);
			printf("→");
			gotoxy(81, 17); printf("%s", &(set[5][set_wordgern]));
			break;
		default :
			point = 0;
			break;
		}

		if (kbhit() == 1) {  
			ch = getch(); 
					
			if (ch == 27)
				return -1;


			if (ch == SPECIAL1 || ch == SPECIAL2) { 
				special_key = 1;
				ch = getch();
			}
	
			if (ch == 13) { // 엔터입력시
				Flame = 1.6 - (set_sp*0.4);
				hp = atoi(&(set[1][set_hp]));
				Ef_swtich = set_ef;
				Limit = atoi(&(set[3][set_Limit]));
				WordNum = atoi(&(set[4][set_wordnum]));// 단어 개수 추가해야함
				gernerat_num = atoi(&(set[5][set_wordgern]));
				break;
			}


		}
		else {
			Sleep(200); // 잠시 대기 : Delay 값을 줄이면 속도가 빨라진다.
		}

		if (special_key) { // 특수키
			switch (ch) {
			case UP:
				point += 5;
				erase_arrow();
				special_key = 0;
				break;
			case DOWN:
				point ++;
				erase_arrow();
				special_key = 0;
				break;
			case LEFT:
				switch (point) {
				case 0:
					set_sp += 2;
					break;
				case 1:
					set_hp += 2;
					break;
				case 2:
					set_ef++;
					break;
				case 3:
					set_Limit += 2;
					break;
				case 4:
					set_wordnum += 2;
					break;
				case 5:
					set_wordgern += 2;
					break;
				default:
					printf("error");
					break;
				}
				
				special_key = 0;
				break;

			case RIGHT:
				switch (point) {
				case 0:
					set_sp++;
					break;
				case 1:
					set_hp++;
					break;
				case 2:
					set_ef++;
					break;
				case 3:
					set_Limit++;
					break;
				case 4:
					set_wordnum++;
					break;
				case 5:
					set_wordgern++;
					break;
				default:
					printf("error");
					break;
				}
				special_key = 0;
				break;
			}
		}
	}
	system("cls");
	return 0;
}