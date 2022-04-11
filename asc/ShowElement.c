#include<stdio.h>
#include"node_struct.h"
#include"Console.h"
#include<Windows.h>

void ShowElement(spoint *s) {
	textcolor(BLACK, WHITE);
	removeCursor();

	if(level_Re_switch == 1) {
		gotoxy(130, 1);//100
		printf("     레벨모드     ");
		gotoxy(130, 2);//100
		printf(" Level : %7d    ", level);
	}

	gotoxy(130, 2);
	if (difficulty == 1)
		printf("       쉬움       ");
	else if (difficulty == 2)
		printf("       보통       ");
	else if (difficulty == 3)
		printf("      어려움       ");
	gotoxy(Cusor_posX, Cusor_posY);

	gotoxy(130, 3);//100
	printf(" 남은시간 : %4d  ", LeftTime);
	gotoxy(Cusor_posX, Cusor_posY);

	gotoxy(130, 4);
	printf(" HP : %10d  ", hp);
	gotoxy(Cusor_posX, Cusor_posY);

	gotoxy(130, 5);
	printf(" 점수 : %8d  ", score);
	gotoxy(Cusor_posX, Cusor_posY);

	gotoxy(130, 6);
	printf(" 남은 개수 : %03d  ", s->length);
    gotoxy(Cusor_posX, Cusor_posY);

	gotoxy(130, 7);
	printf(" 입력 개수 : %3d  ", inputCount);
    gotoxy(Cusor_posX, Cusor_posY);
	
	if (level_Re_switch == 1) {
	    textcolor(BLACK, BLUE1);
	    box(128, 149, 0, 8);
	}
	else if(difficulty != 0){
		textcolor(BLACK, BLUE1);
		box(128, 149, 1, 8);
	}
	else {
		textcolor(BLACK, BLUE1);
	    box(128, 149, 2, 8);
	}
	
	if(Ef_swtich == 1) {
		int i;
		textcolor(BLACK, WHITE);
		for (i = 11; i < 18; i++) {
			gotoxy(130, i); printf("                  ");
		}

		gotoxy(135, 11); printf("효과설명");

		textcolor(BLACK, BLUE1);
		box(128, 149, 10, 18);
		gotoxy(131, 13); textcolor(WHITE, BLACK); printf("상단을 가림");
		gotoxy(131, 14); textcolor(BLACK, MAGENTA2); printf("한곳에만 낙하");
		gotoxy(131, 15); textcolor(BLACK, YELLOW2); printf("점수 획득량 2배");
		gotoxy(131, 16); textcolor(BLACK, RED2); printf("aaa로 변함");
	}
	textcolor(BLACK, BLACK);
	box(4, 25, 21, 27);
	
	gotoxy(6, 22);
	textcolor(BLACK, WHITE);
	printf("  적용중인 효과   ");
	
	gotoxy(6, 23);
	if(ef1==0) {textcolor(WHITE,WHITE); printf("                  ");}
	else {textcolor(WHITE, BLACK); printf("    EF1 is on     ");}
    
	gotoxy(6, 24);
	if(ef2==0) {textcolor(WHITE,WHITE); printf("                  ");}
	else {textcolor(BLACK, MAGENTA2); printf("    EF2 is on     ");}
	
	gotoxy(6, 25);
	if(ef3==0) {textcolor(WHITE,WHITE); printf("                  ");}
	else {textcolor(BLACK, YELLOW2); printf("    EF3 is on     ");}

	gotoxy(6, 26);
	if(ef4==0) {textcolor(WHITE,WHITE); printf("                  ");}
	else {textcolor(BLACK, RED2); printf("    EF4 is on     ");}

	textcolor(BLACK, GRAY1);
}
