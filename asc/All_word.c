#include<malloc.h>
#include<string.h>
#include"node_struct.h"
#include"Global.h"
#include<stdio.h>
#include<Windows.h>

extern snode * new;

void All_word(spoint *t) { // s포인트 리스트는 모든단어가 있는 리스트
		int i, select=0;
		char temp[11];
		snode * p;
		//snode * new;
		FILE *fp;

		if(KOR_ENG == 1)
			fp = fopen("Words.txt", "r");
		else if(KOR_ENG == 2)
			fp = fopen("WordsENG.txt", "r");

		for (i = 0; i < WordNum; i++) {
			new = (snode*)malloc(sizeof(snode));
			p = t->head;
			new->link = p;
			t->head = new;

			fscanf(fp, "%s", &temp);

			strcpy(new->stem, &(temp));
			t->length++;
		}
		fclose(fp);					   
}