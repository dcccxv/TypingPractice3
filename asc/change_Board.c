#include<string.h>
#include<stdio.h>
#include"Global.h"
#include"Console.h"
#include"node_struct.h"

void change_Board(point *s) {
	node* p = s->head;

	removeCursor();
	if (p == NULL)
		return;
	else {
		while (p != NULL) {
			gotoxy(p->x, p->y);
			if (ef1 == 1) { //ef1
				if (p->y >= 9) {
					if (p->effect <= 3 && p->effect > 0) {
						textcolor(WHITE, BLACK);
						printf("%s", p->item);
						textcolor(BLACK, GRAY1);
					}
					else if (p->effect <= 6 && p->effect > 3) {
						textcolor(BLACK, MAGENTA2);
						printf("%s", p->item);
						textcolor(BLACK, GRAY1);
					}
					else if (p->effect <= 9 && p->effect > 6) {
						textcolor(BLACK, YELLOW2);
						printf("%s", p->item);
						textcolor(BLACK, GRAY1);
					}
					else if (p->effect <= 12 && p->effect > 9) {
						textcolor(BLACK, RED2);
						printf("%s", p->item);
						textcolor(BLACK, GRAY1);
					}
					else {
						textcolor(BLACK, GRAY1);
						printf("%s", p->item);
						textcolor(BLACK, WHITE);
					}
				}
			}
			else {
				if (p->effect <= 3 && p->effect > 0) {
					textcolor(WHITE, BLACK);
					printf("%s", p->item);
					textcolor(BLACK, GRAY1);
				}
				else if (p->effect <= 6 && p->effect > 3) {
					textcolor(BLACK, MAGENTA2);
					printf("%s", p->item);
					textcolor(BLACK, GRAY1);
				}
				else if (p->effect <= 9 && p->effect > 6) {
					textcolor(BLACK, YELLOW2);
					printf("%s", p->item);
					textcolor(BLACK, GRAY1);
				}
				else if (p->effect <= 12 && p->effect > 9) {
					textcolor(BLACK, RED2);
					printf("%s", p->item);
					textcolor(BLACK, GRAY1);
				}
				else{
				    textcolor(BLACK, GRAY1);
					printf("%s", p->item);
					textcolor(BLACK, WHITE);
				}
			}
			p = p->link;
			gotoxy(Cusor_posX, Cusor_posY); // 커서위치가 튀는걸 방지하기 위해
		}
	}
}
