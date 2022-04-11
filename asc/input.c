#include"node_struct.h"
#include"delete_node.h"
#include"Console.h"
#include"Global.h"
#include"MainMenu.h"

#include<windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<wchar.h>

#pragma comment (lib,"winmm.lib")

int input(point *s) {// 인풋워드는 입력할 문자열변수, 워드인덱스는 문자열변수의 인덱스 
	int i = 0;
	int tmp1 = '\0', tmp2 = 0;
    double time=0, temp=0;

	node* p = s->head;

	showCursor();
	if (kbhit() == 1){
		tmp1 = getch();

		if (tmp1 == 13) { // 엔터입력시
			WordIndex = 0;
			gotoxy(Cusor_posX, Cusor_posY);
			printf("        ");

			while (p != NULL) {
				if (strcmp(InPutWord, p->item) == 0) {
					CheckEffect = p->effect;
					delete_node(s, p);

					PlaySound(TEXT("bells004.wav"), NULL, SND_ASYNC);
					score += (5 * score_prop);
					inputCount++;

					for (i = 0; i < STRLENGTH - 1; i++)
						InPutWord[i] = ' ';
					InPutWord[STRLENGTH - 1] = '\0';
					return 1;
				}
				p = p->link;
			}

			PlaySound(TEXT("ding.wav"), NULL, SND_ASYNC);
			for (i = 0; i < STRLENGTH; i++)
				InPutWord[i] = '\0';
		}
		
		else if (tmp1  > 127) { // 한글
			tmp2 = getch();
			InPutWord[WordIndex] = tmp1;
			if (WordIndex < STRLENGTH - 3) {
				InPutWord[++WordIndex] = tmp2;
				InPutWord[++WordIndex] = NULL;
			}
		}

	   	else if (tmp1 >= 40 && tmp1 <= 127) { //  알파벳
			if (WordIndex < STRLENGTH - 2) {
				InPutWord[WordIndex++] = tmp1;
				InPutWord[WordIndex] = NULL;
			}
		}
		
		if (tmp1 == 8) { // 백스페이스 일때
			InPutWord[WordIndex--] = '\0'; // 매번 글자입력시에 글자다음에 널문자를 넣어주기 때문에 일단 공백을 한번 지워야함.

			if (WordIndex > 0)
				InPutWord[WordIndex] = '\0';
			if (WordIndex>1 && (InPutWord[WordIndex]>127))	//한글일 경우 한바이트를 더삭제
				InPutWord[--WordIndex] = '\0';
			if (WordIndex <0) // 인덱스가 0이하로 떨어지는것을 방지
				WordIndex = 0;
		}
		
		if(tmp1 == 27) // ESC일때
			return -1;
	}

	return 0;
}
