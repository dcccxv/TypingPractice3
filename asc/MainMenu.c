#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Record.h"
#include"Global.h"
#include"GameStart.h"
#include"word_process.h"
#include"Setting_prac.h"
#include"practice.h"
#include"LevelChallange.h"
#include"Console.h"
#include"Title.h"
#include"node_struct.h"

node* new_node;
snode * new;
int inputCount=0; //����ܾ��
int KOR_ENG = 1; // ����
int back_KOR_ENG; // ��� ���� ESC������ ���� �� ����
int hp = 3; // ü��
double Flame = 0; // delay�Լ��� ���� ��
int score = 0; //����
int score_prop = 1; //��������
int Record;
char RecordName[21];
int Cusor_posX = 45; // �Է�â Ŀ�� x��ǥ
int Cusor_posY = 24;
int Limit; //���ѽð�
int LeftTime = 1;// �����ð�
int CheckEffect = 0; //�ܾ �ִ� ȿ������
int Ef_swtich = 1; //ȿ����� ON/ OFF
int WordNum = 200; // ���ӿ� ����� �ܾ��
int gernerat_num = 1; // �ѹ��� ������ �ܾ� ����
int level;
int level_Re_switch = 0;  //������带 �˸��� ����
int difficulty = 0; // ���̵� ���� ����
int ef_start1; // 1��ȿ�� Ÿ�̸�
int ef_start2; // 2��ȿ�� Ÿ�̸�
int ef_start3; // 3��ȿ�� Ÿ�̸�
int ef_start4; // 4�� ȿ�� Ÿ�̸�
int ef1 = 0; // 1��ȿ�� ����ġ
int ef2 = 0; // 2��ȿ�� ����ġ
int ef3 = 0; // 3��ȿ�� ����ġ
int ef4 = 0; // 4��ȿ�� ����ġ
int ef2_xpos; // 2�� ȿ���� �����Ǵ� �ܾ��� x��ǥ
int WordIndex = 0; // �Է��Լ� ���ڿ��� �ε���
char InPutWord[STRLENGTH] = { '\0' }; // �Է� ���ڿ�

char Board[COLS][ROWS][STRLENGTH] = {
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "��        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","  ��" },
	{ "�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢʢ�","�ʢʢ�" }
};


void MainMenu(void) {
	int select;
	unsigned char ch;
	int point = 0;
	int special_key = 0;
	int i = 0;
	int j = 0;
	int menu_cusorX = 65;
	int menu_cusorY = 18;
	int Languege_cusorX = 55;
	int Language_cusorY = 12;
	removeCursor(); //Ŀ�� �����

	Title(); // ���� ���

	while (1) {
		textcolor(WHITE, CYAN1);
		point = point % 6;

		switch(point) {
		case 0: 
			select = 1;
			gotoxy(menu_cusorX, menu_cusorY);
			printf("��");
			break;
		case 1:
			select = 2;
			gotoxy(menu_cusorX, menu_cusorY + 1);
			printf("��");
			break;
		case 2:
			select = 3;
			gotoxy(menu_cusorX, menu_cusorY + 2);
			printf("��");
			break;
		case 3:
			select = 4;
			gotoxy(menu_cusorX, menu_cusorY + 3);
			printf("��");
			break;
		case 4:
			select = 5;
			gotoxy(menu_cusorX, menu_cusorY + 4);
			printf("��");
			break;
		case 5:
			select = 6;
			gotoxy(menu_cusorX, menu_cusorY + 5);
			printf("��");
			break;
		default :
			point = 0;
			break;
		}

		if (kbhit() == 1) {  
			ch = getch(); 

			if (ch == SPECIAL1 || ch == SPECIAL2) { 
				special_key = 1;
				ch = getch();
			}

			if (ch == 13) { // �����Է½�
				goto BPOINT;
			}
		}
		else {
			Sleep(100); 
		}

		if (special_key) { 
			switch (ch) {
			case UP:
				erase(menu_cusorX, menu_cusorY + point);
				point += 5;
				special_key = 0;
				break;
			case DOWN:
				erase(menu_cusorX, menu_cusorY + point);
				point ++;
				special_key = 0;
				break;
			}
		}
	} // while�� ��

BPOINT:
	if (select == 1) {
		if(GameStart() == -1) // ���ӽ�ŸƮ ���� , esc �Է½� -1 ����
			return;
		word_process();
	}
	else if(select == 2) {
	    level_Re_switch = 1; 
		LevelChallange(); 
		level_Re_switch = 0; 
	}
	else if (select == 3) {
		if(Setting_prac() == -1) // ������� ����, esc �Է½� -1 ����
			return;
		practice();
	}
	else if (select == 4) {
		system("cls");
		ShowRecord();
		system("cls");
	}
	else if (select == 5) {
		removeCursor(); //Ŀ�� �����
		select = 7; // 7�� ��� MainMenu �Լ��� �����ϰ� ������ ���� �ٽ� ����
		back_KOR_ENG = KOR_ENG; // ESC ������ �������� ������� �ʰ�
		textcolor(BLACK, WHITE);
		gotoxy(Languege_cusorX, Language_cusorY-3);    printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY-2);    printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY-1);    printf("               ����               ");
		gotoxy(Languege_cusorX, Language_cusorY);      printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY + 1);  printf("               1. �ѱ�                ");
		gotoxy(Languege_cusorX, Language_cusorY + 2);  printf("               2. ����                ");
		gotoxy(Languege_cusorX, Language_cusorY + 3);  printf("                                      ");
		gotoxy(Languege_cusorX, Language_cusorY + 4);  printf("                                      ");

		textcolor(BLACK, BLACK);
		box(Languege_cusorX - 2, Languege_cusorX + 38, Language_cusorY - 3, Language_cusorY + 4); // �ڽ��׸���
		textcolor(BLACK, WHITE);
		

		while (1) { // �ѱ� ���� ���� UI
			textcolor(BLACK, WHITE);

			if (KOR_ENG > 2)
				KOR_ENG = 1;

			switch (KOR_ENG) {
			case 1: // �ѱ�
				gotoxy(Languege_cusorX + 12, Language_cusorY + 1);
				printf("��");
				break;
			case 2: // ����
				gotoxy(Languege_cusorX + 12, Language_cusorY + 2);
				printf("��");
				break;

			default:
				point = 0;
				break;
			}
		
			if (kbhit() == 1) {  // Ű���尡 ������ ������
				ch = getch(); 
		
				if(ch ==13) // ENTER
					break; // select�� 7�� �Ǳ� ������ Title�� ȣ����ص� ���θ޴��� ����ǰ� �ٽ� ���θ޴��� ȣ���.
				if(ch == 27) { // ESC ������ ���� ��������� �س��� Ż��
					KOR_ENG = back_KOR_ENG;
					break;
				}
				if (ch == SPECIAL1 || ch == SPECIAL2) { 
					special_key = 1;
					ch = getch();
				}

			}
			else 
				Sleep(100);

			if (special_key) {
				switch (ch) {
				case UP:
					erase(Languege_cusorX + 12, Language_cusorY + KOR_ENG);
					KOR_ENG++;
				    special_key = 0;
					break;

				case DOWN:
					erase(Languege_cusorX + 12, Language_cusorY + KOR_ENG);
					KOR_ENG++;
					special_key = 0;
					break;
				}
			}
		}
	}
	else if (select == 6)
		exit(0);
	else 
		; // ��⸦ ����
}
