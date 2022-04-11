#include<stdio.h>
#include"Console.h"
#include"Global.h"

void ShowGame() { // 게임판 출력
	int i, j;
	textcolor(BLACK, CYAN2);
	gotoxy(0, 0);
	for (i = 1; i < COLS; i++) {
		if (ef1 == 1 &&  i < 9)
			gotoxy(2, i);
		else
			printf("\n");

		for (j = 0; j < ROWS; j++) {
			if (ef1 == 0)
				printf("%s", &Board[i][j]);
			else if (i >= 9)
				printf("%s", &Board[i][j]);
		}
	}
	gotoxy(Cusor_posX, Cusor_posY);
}