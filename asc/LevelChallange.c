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
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include"Global.h"
#include"init.h"
#include"GameOver.h"
#include"Record.h"

void LevelChallange(void) {
	int WordIndex = 0;
	double checkST, checkFI, DelayST, DelayFI;
	int ch_re = 0;
	int tmp_score = score + 100;
	int tmp_level = 1;
	clock_t start = 0, finish = 0, checkTime = 0;
	point wordlist;
	spoint storelist;
	removeCursor();
	system("cls"); // ���Ӹ޴�ȭ�� ����� �ٸ����� �����ܰ迡�� ����
	system("color 30"); //������

	Flame = 1.5;
	Limit = 300;
	hp = 10;
	gernerat_num = 1;
	level = 1;
	Ef_swtich = 0;

	LeftTime = Limit;
	init(&wordlist);
	sinit(&storelist);

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
		LeftTime = ((start + Limit * 1000) - finish) / 1000;
		checkFI = finish / 1000;
		DelayFI = finish;

		if (checkFI - 1 == checkST) {
			checkST = checkFI;
			ShowElement(&storelist);// 1�ʸ��� HP, �ð� �� ���� �׸���
		}
		
			textcolor(BLACK, WHITE);
		    gotoxy(52, Cusor_posY - 2);
			printf("%02d          ", wordlist.length);
			gotoxy(Cusor_posX, Cusor_posY);
			printf("              ");
			gotoxy(Cusor_posX, Cusor_posY);
			printf("%s", InPutWord);

		tmp_level = level;
		if(score >= tmp_score) { // 100���� ������
			level++;
			tmp_score = score + 100;

			if(level-(tmp_level) == 1)
				Flame = Flame - 0.1;
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

		if (DelayFI - DelayST >= Flame * 1000) {
			DelayST = DelayFI;
			insert_first(&wordlist, &storelist);	// ���ο� �ܾ� �߰�
			move_word(&wordlist);	// �ܾ� ��ǥ ����
			ShowGame();	// �� �����
			ShowElement(&storelist);// HP, �ð� �� ���� �׸��� // HP�� 0�� �Ǵ¼����� ùIF���� ������ϱ� ������ ���⼭�� �߰�
			change_Board(&wordlist);	// �� �׸���
			if(wordlist.length == 0) {
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

