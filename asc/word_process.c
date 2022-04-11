#include"word_process.h"
#include"node_struct.h"
#include"insert_first.h"
#include"move_word.h"
#include"ShowGame.h"
#include"change_Board.h"
#include"node_struct.h"
#include"ShowElement.h"
#include"All_word.h"
#include"Console.h"
#include"input.h"
#include"Record.h"

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include"Global.h"
#include"Weffect.h"
#include"init.h"
#include"GameOver.h"


void word_process(void) { 
	double checkST, checkFI, DelayST, DelayFI;
	int ch_re = 0;
	clock_t start = 0, finish = 0, checkTime = 0;
	point wordlist;
	spoint storelist;
	
	system("color 30"); //������
	LeftTime = Limit;
	init(&wordlist);
	sinit(&storelist);
	removeCursor();

	ShowGame();
	ShowElement(&storelist);

	textcolor(BLACK, BLACK);
	box(30, 90, 21, 27);

	textcolor(BLACK, WHITE);
	gotoxy(32, Cusor_posY - 2); printf("������ �ܾ� ����:                                        ");
	gotoxy(32, Cusor_posY-1); printf("                                                         ");
	gotoxy(32, Cusor_posY);   printf("  �Է¹��� :                                             ");
	gotoxy(32, Cusor_posY+1); printf("                                                         ");
	gotoxy(32, Cusor_posY+2); printf("                                                         ");
	WordNum = 200;
	All_word(&storelist);

	start = clock();
	checkST = start / 1000;
	DelayST = start;

	ShowGame();
	ShowElement(&storelist);

	while (LeftTime > 0 && hp > 0) {
		finish = clock();
		LeftTime = ((start + Limit * 1000) - finish) / 1000; // �����ð� ���
		checkFI = finish / 1000;
		DelayFI = finish;
		
		Weffect((int)finish, &wordlist); // ȿ�� Ȯ��/���� , input�Լ�����  ChcekEffect���� ��ȭ��
		
			textcolor(BLACK, WHITE);
		    gotoxy(52, Cusor_posY - 2);
			printf("%02d          ", wordlist.length);
			gotoxy(Cusor_posX, Cusor_posY);
			printf("              ");
			gotoxy(Cusor_posX, Cusor_posY);
			printf("%s", InPutWord);
		
		if(checkFI - checkST >= 1) {
			checkST = checkFI;
			ShowElement(&storelist);// HP, �ð� �� ���� �׸���
		}
		ch_re = input(&wordlist);
			
		if(ch_re == -1){
			GameOver();
			return;
		}
		else if(ch_re == 1) {
			ShowGame();	// �� �����
			ShowElement(&storelist);	// HP, �ð� �� ���� �׸���
			change_Board(&wordlist);	// ��ȭ�� �� �׸���		
		}

		if(DelayFI - DelayST >= Flame*1000) {
			DelayST = DelayFI;
			insert_first(&wordlist, &storelist);	// ���ο� �ܾ� �߰�
			move_word(&wordlist);	// �ܾ� ��ǥ ����
			ShowGame();	// �� �����
			ShowElement(&storelist);// HP, �ð� �� ���� �׸��� // HP�� 0�� �Ǵ¼����� ùIF���� ������ϱ� ������ ���⼭�� �߰�
			change_Board(&wordlist);	// �� �׸���

			if(wordlist.length == 0) { // �ܾ ���� �Ҹ� ������ ��������
				PrintGameOver();
	            SaveRecord(score);
	            GameOver();
				return;
			}		
		}
	}
	PrintGameOver();
	SaveRecord(score);
	GameOver();

}