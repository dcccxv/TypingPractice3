#include<windows.h>
#include <stdio.h>
#include <conio.h>
#include"Console.h"

void erase_arrow(void) {
	gotoxy(66, 12);
	printf("  ");
	gotoxy(66, 13);
	printf("  ");
	gotoxy(64, 14);
	printf("  ");
	gotoxy(62, 15);
	printf("  ");
	gotoxy(56, 16);
	printf("  ");
	gotoxy(50, 17);
	printf("  ");
}

void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void erase(int x, int y) {
	gotoxy(x, y);
	printf("  ");
}

void textcolor(int fg_color, int bg_color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void removeCursor(void) { // 커서를 안보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void showCursor(void) { // 커서를 보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void blue_black(int x, int y) {
	textcolor(BLUE2, BLACK);
	gotoxy(x, y);
	printf(" ");
	textcolor(BLACK, WHITE);
}


void border(void) {
	int i , j;
		for (i = 0; i < 150; i++) {
			blue_black(i, 29);
			blue_black(i, 0);
		}

		for (j = 1; j < 30; j++) {
			blue_black(0, j);
			blue_black(1, j);
			blue_black(148, j);
			blue_black(149, j);
		}

}


void box(int x1, int x2, int y1, int y2) {
	int i, j;

	for (i = x1; i <= x2; i++) {
		gotoxy(i, y1); printf(" ");
		gotoxy(i, y2); printf(" ");
	}

	for (j = y1; j <= y2; j++) {
		gotoxy(x1, j); printf("  ");
		gotoxy(x2-1, j); printf("  ");
	}
}



int CheckESC(void) {
	int tmp1;
if (kbhit() == 1) {
		tmp1 = getch();
		if(tmp1 == 27) // ESC일때
			return 1;	
}
  return 0;

}