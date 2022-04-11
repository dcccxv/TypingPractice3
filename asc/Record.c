#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"Global.h"
#include"MainMenu.h"
#include"Console.h"
#include<conio.h>

void ShowRecord() {
	int Record_cusorX = 55;
	int Record_cusorY = 12;
	int special_key = 0;
	int RecordSelect = 1;
	unsigned char ch;
	int i, j, R, tmp[100] = { 0, }, select = 0;
	FILE *fp;
	
	removeCursor(); //커서 지우기

	textcolor(BLACK, WHITE);

	gotoxy(Record_cusorX, Record_cusorY - 2);    printf("                                       ");
	gotoxy(Record_cusorX, Record_cusorY -1);		 printf("               랭킹 선택               ");
	gotoxy(Record_cusorX, Record_cusorY + 0);	 printf("                                       ");
	gotoxy(Record_cusorX, Record_cusorY + 1);	 printf("               1. 쉬움                 ");
	gotoxy(Record_cusorX, Record_cusorY + 2);	 printf("               2. 보통                 ");
	gotoxy(Record_cusorX, Record_cusorY + 3);	 printf("               3. 어려움               ");
	gotoxy(Record_cusorX, Record_cusorY + 4);    printf("               4. 레벨모드             ");
	gotoxy(Record_cusorX, Record_cusorY + 5);    printf("                                       ");
	//textcolor(BLACK, GRAY1);

	
	border(); //테두리 그리기
	textcolor(BLACK, BLACK);
    box(Record_cusorX - 1,  Record_cusorX + 38, Record_cusorY - 3, Record_cusorY + 6);
	textcolor(BLACK, WHITE);

	while (1) {
		if (RecordSelect > 4)
			RecordSelect = 1;
		if (RecordSelect < 1)
			RecordSelect = 4;

		switch (RecordSelect) {
		case 1:
			gotoxy(Record_cusorX + 12, Record_cusorY + 1);
			select = 1;
			printf("→");
			break;
		case 2:
			gotoxy(Record_cusorX + 12, Record_cusorY + 2);
			select = 2;
			printf("→");
			break;
		case 3:
			gotoxy(Record_cusorX + 12, Record_cusorY + 3);
			select = 3;
			printf("→");
			break;
		case 4:
			gotoxy(Record_cusorX + 12, Record_cusorY + 4);
			select = 4;
			printf("→");
			break;
		default:
			select = 1;
			break;
		}

		if (kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = getch();

			if (ch == SPECIAL1 || ch == SPECIAL2) {
				special_key = 1;
				ch = getch();
			}

			if (ch == 13) {// 엔터입력시
				goto SPOINT;
				break;
			}
			if (ch == 27)
				return;
		}
		else
			Sleep(200);

		if (special_key) {
			switch (ch) {
			case UP:
				erase(Record_cusorX + 12, Record_cusorY + RecordSelect);
				RecordSelect--;
				special_key = 0;
				break;

			case DOWN:
				erase(Record_cusorX + 12, Record_cusorY + RecordSelect);
				RecordSelect++;
				special_key = 0;
				break;
			}
		}
	}

SPOINT:
	if (select == 1)
		fp = fopen("RecordEasy.txt", "r");
	else if (select == 2)
		fp = fopen("RecordNormal.txt", "r");
	else if (select == 3)
		fp = fopen("RecordHard.txt", "r");
	else if (select == 4)
		fp = fopen("RecordLevel.txt", "r");

	system("cls");
	if (select == 1){
		gotoxy(70,2); printf("쉬움 랭킹\n");
	}
	else if (select == 2){
		gotoxy(70, 2); printf("보통 랭킹\n");
	}
	else if (select == 3){
		gotoxy(70, 2); printf("어려움 랭킹\n");
	}
	else if (select == 4){
		gotoxy(70, 2); printf("레벨모드 랭킹\n");
	}

	for (i = 0; i < 100; i++) {
		fscanf(fp, "%d", &Record);
		fscanf(fp, "%s", &RecordName);

		tmp[i] = Record;
		for (j = i; j >= 0; j--) {
			if (Record == tmp[j])
				R = j;
		}

		if (Record == 0)
			R = i;

		if (i < 25)
			gotoxy(3, i + 4);
		else if (i < 50) 
			gotoxy(39, i - 21);
		else if (i < 75)
			gotoxy(75, i - 46);
		else if (i < 100)
			gotoxy(111, i -71);

		printf("%3d등 %20s %4d점", R + 1, RecordName, Record);
	}
	fclose(fp);

	for (i = 0; i < 150; i++) {
		blue_black(i, 0);
		blue_black(i, 1);
	}

	for (j = 1; j < 30; j++) {
		blue_black(0, j);
		blue_black(1, j);
		blue_black(148, j);
		blue_black(149, j);
		if (j > 3) {
			blue_black(37, j);
			blue_black(73, j);
			blue_black(109, j);
		}
	}
	while(1) {
	ch = getch();
	if(ch == 27)
	break;
	}
}

void SaveRecord(int score) {
	FILE *fp;
	int i, j, temp = 0, n[100] = { 0, }, count = 0;
	char name[100][21] = { "없음", };
	char nameTemp[21] = { " ", };
	char nameInput[1000] = { 0, };

	if (level_Re_switch  == 1)
		fp = fopen("RecordLevel.txt", "r");
	else if (difficulty == 1)
		fp = fopen("RecordEasy.txt", "r");
	else if (difficulty == 2)
		fp = fopen("RecordNormal.txt", "r");
	else if (difficulty == 3)
		fp = fopen("RecordHard.txt", "r");

	if (score == 0) {
		printf("0점은 기록되지 않습니다\n");
		Sleep(5000);
		return;
	}
	for (i = 0; i < 100; i++) {
		fscanf(fp, "%d", &n[i]);
		fscanf(fp, "%s", &name[i]);
	}

	if (n[99] > score) {
		gotoxy(70, 23); printf("100등 초과입니다");
		return;
	}
	else {
		for (i = 0; i < 100; i++) {
			if (n[i] <= score) {
				gotoxy(70, 23); printf("등수: %d등\n", i + 1);
				break;
			}
		}
		n[99] = score;
		gotoxy(32, 24); printf("이름을 입력하세요(한글10자, 영어 20자 이하)");
		Sleep(800);

SCANF:
		gotoxy(33,25);
		scanf("%s", nameInput);

		for (i = 0; i < 100; i++) {
			if (strcmp(name[i], nameInput) == 0) {
				gotoxy(32, 24); printf("                                                ");
				gotoxy(32, 25); printf("                                                        ");
				gotoxy(32, 24); printf("중복된 이름입니다. 다시 입력하세요  ");
				goto SCANF;
			}
		}

		if (strlen(nameInput) > 20) {
			gotoxy(32, 24); printf("                                                ");
			gotoxy(32, 25); printf("                                                        ");
			gotoxy(32, 24); printf("한글10자, 영어 20자 이하로 입력하세요  ");
			goto SCANF;
		}

		strcpy(name[99], nameInput);
	}
	fclose(fp);

	for (i = 0; i < 100; i++) {//버블정렬 내림차순
		for (j = 0; j < 99; j++) {
			if (n[j] < n[j + 1]) {
				temp = n[j + 1];
				n[j + 1] = n[j];
				n[j] = temp;

				strcpy(nameTemp, name[j + 1]);
				strcpy(name[j + 1], name[j]);
				strcpy(name[j], nameTemp);
			}
		}
	}

	if (level_Re_switch == 1)
		fp = fopen("RecordLevel.txt", "w");
	else if (difficulty == 1)
		fp = fopen("RecordEasy.txt", "w");
	else if (difficulty == 2)
		fp = fopen("RecordNormal.txt", "w");
	else if (difficulty == 3)
		fp = fopen("RecordHard.txt", "w");

	for (i = 0; i < 100; i++) {
		fprintf(fp, "%d \n", n[i]);
		fprintf(fp, "%s \n", name[i]);
	}
	fclose(fp);
}