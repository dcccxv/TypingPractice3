#include"Global.h"
#include"Console.h"
#include"node_struct.h"
#include"MainMenu.h"
#include<Windows.h>
#include<stdio.h>

extern node* new_node;
extern snode * new;

void PrintGameOver() {
	int i = 5, j = 4, t = 0;
	textcolor(BLACK,BLACK);
	box(3, 136, 3, 17); // 박스그리는함수
	textcolor(RED1, YELLOW2);
	gotoxy(i, j++); printf("                                                                                                                                  ");
	gotoxy(i, j++); printf("　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　");
	gotoxy(i, j++); printf("　　■　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　　　　");
	gotoxy(i, j++); printf("　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　");
	gotoxy(i, j++); printf("　■　　　　　　　　　■■■　　　　■■■　■■■　　　　■■■　　　　　　　■　　　　　■　　■　　　■　　■■■　　　■　■　");
	gotoxy(i, j++); printf("　■　　■■■■　　■　　　■　　■　　　■　　　■　　■　　　■　　　　　　■　　　　　■　　■　　　■　■　　　■　　■■　　");
	gotoxy(i, j++); printf("　■　　　　　■　　　　　　■　　■　　　■　　　■　　■　　　■　　　　　　■　　　　　■　　■　　　■　■　　　■　　■　　　");
	gotoxy(i, j++); printf("　■　　　　　■　　　■■■■　　■　　　■　　　■　　■■■■■　　　　　　■　　　　　■　　　■　■　　■■■■■　　■　　　");
	gotoxy(i, j++); printf("　■　　　　　■　　■　　　■　　■　　　■　　　■　　■　　　　　　　　　　■　　　　　■　　　■　■　　■　　　　　　■　　　");
	gotoxy(i, j++); printf("　　■　　　■■　　■　　　■　　■　　　■　　　■　　■　　　■　　　　　　　■　　　■　　　　　■　　　■　　　■　　■　　　");
	gotoxy(i, j++); printf("　　　■■■　■　　　■■■■　　■　　　■　　　■　　　■■■　　　　　　　　　■■■　　　　　　■　　　　■■■　　　■　　　");
	gotoxy(i, j++); printf("                                                                                                                                  ");	
	gotoxy(i, j++); printf("                                                                                                                                  ");
	

	i += 28;
	j += 6;
	textcolor(BLACK, WHITE);
	gotoxy(i, j++); printf("획득한 점수: %d점", score);
	gotoxy(i, j++);
}

void GameOver(void) {//효과 값이 변화된 상태로 끝나지 않게
	int i;

	Flame = 0;
	ef1 = 0;
	ef2 = 0;
	ef3 = 0;
	ef4 = 0;
	CheckEffect = 0;
	WordIndex = 0;
	Ef_swtich = 1;
	score = 0;
	inputCount = 0;
	difficulty = 0;

	for(i = 0; i < STRLENGTH-1; i++)
		InPutWord[i] = '\0';

	free(new);
	free(new_node);
}