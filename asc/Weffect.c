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

		if (CheckEffect > 0 && CheckEffect <= 3) { // 1��ȿ��// ������ ����� ����
			PlaySound(TEXT("Windows XP Battery Critical.wav"), NULL, SND_ASYNC);
			for(j = 1; j < 9; j++) { 
				gotoxy(2, j);
				for (k = 0; k < 15; k++) {
					if (k == 14)
						printf("������");
					else
						printf("�����");
				}
			}
			ef1 = 1;
			ef_start1 = ef_time;
			CheckEffect = 0;
		}
		else if (CheckEffect > 3 && CheckEffect <= 6) { // 2�� ȿ��//10�� ���� ������ �ܾ��� �Ѱ����� ���� , �ѹ��� ������ �ܾ��� ���� 1��
			PlaySound(TEXT("notify.wav"), NULL, SND_ASYNC);
			ef2 = 1;
			ef_start2 = ef_time;
			ef2_xpos = ((rand() % 11) * 11) + 2;
			CheckEffect = 0;
		}
		else if (CheckEffect > 6 && CheckEffect <= 9) { // 3�� ȿ��// 8�ʰ� ��� ������ �ι� 
			PlaySound(TEXT("Windows XP Logon Sound.wav"), NULL, SND_ASYNC);
			ef3 = 1;
			ef_start3 = ef_time;
			score_prop = 2;
			CheckEffect = 0;
		}
		else if (CheckEffect > 9 && CheckEffect <= 12) { // 4�� ȿ��
			PlaySound(TEXT("chimes.wav"), NULL, SND_ASYNC);
			ef4 = 1;
			ef_start4 = ef_time;
			CheckEffect = 0;
		}// 8�� ���� ���� �ϳ��� Ư���ܾ �ǰ�

		if (ef1 == 1) {
			if (ef_time - ef_start1 >= 6000)  // 6�ʰ� ������ ef1 ����
				ef1 = 0;
		}

		if (ef2 == 1) {
			if (ef_time - ef_start2 >= 10000) // 10�ʰ� ������ ef2 ����
				ef2 = 0;
		}


		if (ef3 == 1) {
			if (ef_time - ef_start3 >= 8000) { // 8�ʰ� ������ ȹ����������1, ef5 ����
				score_prop = 1;
				ef3 = 0;
			}
		}

		if (ef4 == 1) {
			if (ef_time - ef_start4 <= 4000) { // 4�� ���� �������� �ܾ AAAA�� �ٲ�
				p = wordlist->head;
				while (p != NULL) {
					strcpy(p->item, "aaa");
					p = p->link;
				}
			}
			else // 8�ʰ� ������ ef4 ����
				ef4 = 0;
		}
	}
}