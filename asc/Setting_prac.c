#include"practice.h"
#include"Global.h"
#include"Console.h"
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"Console.h"

int Setting_prac(void) {
	unsigned char ch; // Ư��Ű 0xe0 �� �Է¹������� unsigned char �� �����ؾ� ��
	int set_sp = 1;  // ���������� �ε���
	int set_hp = 1;
	int set_ef = 1;
	int set_Limit = 1;
	int set_wordnum = 1;
	int set_wordgern = 1;
	int point = 0;
	int special_key = 0;
	char set[6][3][6] = { {"EASY ", "NOMAL", "HARD "}, {"3", "5", "7"}, {"OFF", "ON "}, {"120 ", "150", "180"}, {"100", "150", "200"}, {"1", "2", "3"} };
	system("cls");

	
	
	textcolor(BLACK, WHITE);
	gotoxy(43, 9);
	printf("                                                            "); gotoxy(43, 10);
	printf("                           ����                             "); gotoxy(43, 11);
	printf("                                                            "); gotoxy(43, 12);
	printf("                                                            "); gotoxy(43, 13);
	printf("                                                            "); gotoxy(43, 14);
	printf("                                                            "); gotoxy(43, 15);
	printf("                                                            "); gotoxy(43, 16);
	printf("                                                            "); gotoxy(43, 17);
	printf("                                                            "); gotoxy(43, 18);
	printf("                                                            "); gotoxy(43, 19);
	printf("                                                            ");
	
	textcolor(BLACK,BLACK);
	box(43, 103, 8, 20);

	
	textcolor(BLACK,WHITE);
	gotoxy(69, 12); printf("�ӵ� : ��       ��");
	gotoxy(79, 12); printf("%s", &(set[0][set_sp]));

	gotoxy(69, 13); printf("ü�� : ��       ��");
	gotoxy(81, 13); printf("%s", &(set[1][set_hp]));

	gotoxy(67, 14); printf("����Ʈ : ��       ��");
	gotoxy(80, 14); printf("%s", &(set[2][set_ef]));

	gotoxy(65, 15); printf("���ѽð� : ��       ��");
	gotoxy(80, 15); printf("%s", &(set[3][set_Limit]));

	gotoxy(59, 16); printf("�� �ܾ��� ���� : ��       ��");
	gotoxy(80, 16); printf("%s", &(set[4][set_wordnum]));

	gotoxy(53, 17); printf("�ѹ��� ������ �ܾ�� : ��       ��");
	gotoxy(81, 17); printf("%s", &(set[5][set_wordgern]));
	
	while (1) {
		point = point % 6;
		set_sp = set_sp % 3;
		set_hp = set_hp % 3;
		set_ef = set_ef % 2;
		set_Limit = set_Limit % 3;
		set_wordnum = set_wordnum % 3;
		set_wordgern = set_wordgern % 3;
		removeCursor(); //Ŀ�� �����

		switch(point) {
		case 0: 
			gotoxy(66, 12);
			printf("��");
			gotoxy(79, 12); printf("%s", &(set[0][set_sp]));
			break;
		case 1:
			gotoxy(66, 13);
			printf("��");
			gotoxy(81, 13); printf("%s", &(set[1][set_hp]));
			break;
		case 2:
			gotoxy(64, 14);
			printf("��");
			gotoxy(80, 14); printf("%s", &(set[2][set_ef]));
			break;
		case 3:
			gotoxy(62, 15);
			printf("��");
			gotoxy(80, 15); printf("%s", &(set[3][set_Limit]));
			break;
		case 4:
			gotoxy(56, 16);
			printf("��");
			gotoxy(80, 16); printf("%s", &(set[4][set_wordnum]));
			break;
		case 5:
			gotoxy(50, 17);
			printf("��");
			gotoxy(81, 17); printf("%s", &(set[5][set_wordgern]));
			break;
		default :
			point = 0;
			break;
		}

		if (kbhit() == 1) {  
			ch = getch(); 
					
			if (ch == 27)
				return -1;


			if (ch == SPECIAL1 || ch == SPECIAL2) { 
				special_key = 1;
				ch = getch();
			}
	
			if (ch == 13) { // �����Է½�
				Flame = 1.6 - (set_sp*0.4);
				hp = atoi(&(set[1][set_hp]));
				Ef_swtich = set_ef;
				Limit = atoi(&(set[3][set_Limit]));
				WordNum = atoi(&(set[4][set_wordnum]));// �ܾ� ���� �߰��ؾ���
				gernerat_num = atoi(&(set[5][set_wordgern]));
				break;
			}


		}
		else {
			Sleep(200); // ��� ��� : Delay ���� ���̸� �ӵ��� ��������.
		}

		if (special_key) { // Ư��Ű
			switch (ch) {
			case UP:
				point += 5;
				erase_arrow();
				special_key = 0;
				break;
			case DOWN:
				point ++;
				erase_arrow();
				special_key = 0;
				break;
			case LEFT:
				switch (point) {
				case 0:
					set_sp += 2;
					break;
				case 1:
					set_hp += 2;
					break;
				case 2:
					set_ef++;
					break;
				case 3:
					set_Limit += 2;
					break;
				case 4:
					set_wordnum += 2;
					break;
				case 5:
					set_wordgern += 2;
					break;
				default:
					printf("error");
					break;
				}
				
				special_key = 0;
				break;

			case RIGHT:
				switch (point) {
				case 0:
					set_sp++;
					break;
				case 1:
					set_hp++;
					break;
				case 2:
					set_ef++;
					break;
				case 3:
					set_Limit++;
					break;
				case 4:
					set_wordnum++;
					break;
				case 5:
					set_wordgern++;
					break;
				default:
					printf("error");
					break;
				}
				special_key = 0;
				break;
			}
		}
	}
	system("cls");
	return 0;
}