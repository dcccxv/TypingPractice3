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

int input(point *s) {// ��ǲ����� �Է��� ���ڿ�����, �����ε����� ���ڿ������� �ε��� 
	int i = 0;
	int tmp1 = '\0', tmp2 = 0;
    double time=0, temp=0;

	node* p = s->head;

	showCursor();
	if (kbhit() == 1){
		tmp1 = getch();

		if (tmp1 == 13) { // �����Է½�
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
		
		else if (tmp1  > 127) { // �ѱ�
			tmp2 = getch();
			InPutWord[WordIndex] = tmp1;
			if (WordIndex < STRLENGTH - 3) {
				InPutWord[++WordIndex] = tmp2;
				InPutWord[++WordIndex] = NULL;
			}
		}

	   	else if (tmp1 >= 40 && tmp1 <= 127) { //  ���ĺ�
			if (WordIndex < STRLENGTH - 2) {
				InPutWord[WordIndex++] = tmp1;
				InPutWord[WordIndex] = NULL;
			}
		}
		
		if (tmp1 == 8) { // �齺���̽� �϶�
			InPutWord[WordIndex--] = '\0'; // �Ź� �����Է½ÿ� ���ڴ����� �ι��ڸ� �־��ֱ� ������ �ϴ� ������ �ѹ� ��������.

			if (WordIndex > 0)
				InPutWord[WordIndex] = '\0';
			if (WordIndex>1 && (InPutWord[WordIndex]>127))	//�ѱ��� ��� �ѹ���Ʈ�� ������
				InPutWord[--WordIndex] = '\0';
			if (WordIndex <0) // �ε����� 0���Ϸ� �������°��� ����
				WordIndex = 0;
		}
		
		if(tmp1 == 27) // ESC�϶�
			return -1;
	}

	return 0;
}
