#include"Global.h"
#include"time.h"
#include"node_struct.h"
#include"Console.h"

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>

#pragma comment (lib,"winmm.lib")

void Weffect(int ef_time, point *wordlist) {
	node * p;
	int j, k;
	srand(time(NULL));
	removeCursor();
	textcolor(BLACK, GRAY1);

	if (Ef_swtich == 1) {

		if (CheckEffect > 0 && CheckEffect <= 3) { // 1번효과// 게임판 상단을 가림
			PlaySound(TEXT("Windows XP Battery Critical.wav"), NULL, SND_ASYNC);
			for(j = 1; j < 9; j++) { 
				gotoxy(2, j);
				for (k = 0; k < 15; k++) {
					if (k == 14)
						printf("■■■■■");
					else
						printf("■■■■");
				}
			}
			ef1 = 1;
			ef_start1 = ef_time;
			CheckEffect = 0;
		}
		else if (CheckEffect > 3 && CheckEffect <= 6) { // 2번 효과//10초 동안 나오는 단어의 한곳으로 고정 , 한번에 나오는 단어의 개수 1개
			PlaySound(TEXT("notify.wav"), NULL, SND_ASYNC);
			ef2 = 1;
			ef_start2 = ef_time;
			ef2_xpos = ((rand() % 11) * 11) + 2;
			CheckEffect = 0;
		}
		else if (CheckEffect > 6 && CheckEffect <= 9) { // 3번 효과// 8초간 얻는 점수량 두배 
			PlaySound(TEXT("Windows XP Logon Sound.wav"), NULL, SND_ASYNC);
			ef3 = 1;
			ef_start3 = ef_time;
			score_prop = 2;
			CheckEffect = 0;
		}
		else if (CheckEffect > 9 && CheckEffect <= 12) { // 4번 효과
			PlaySound(TEXT("chimes.wav"), NULL, SND_ASYNC);
			ef4 = 1;
			ef_start4 = ef_time;
			CheckEffect = 0;
		}// 8초 동안 전부 하나의 특정단어가 되게

		if (ef1 == 1) {
			if (ef_time - ef_start1 >= 6000)  // 6초가 지나면 ef1 종료
				ef1 = 0;
		}

		if (ef2 == 1) {
			if (ef_time - ef_start2 >= 10000) // 10초가 지나면 ef2 종료
				ef2 = 0;
		}


		if (ef3 == 1) {
			if (ef_time - ef_start3 >= 8000) { // 8초가 지나면 획득점수비율1, ef5 종료
				score_prop = 1;
				ef3 = 0;
			}
		}

		if (ef4 == 1) {
			if (ef_time - ef_start4 <= 4000) { // 4초 동안 게임판의 단어를 AAAA로 바꿈
				p = wordlist->head;
				while (p != NULL) {
					strcpy(p->item, "aaa");
					p = p->link;
				}
			}
			else // 8초가 지나면 ef4 종료
				ef4 = 0;
		}
	}
}