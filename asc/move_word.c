#include"node_struct.h"
#include"delete_node.h"
#include<string.h>

extern int hp;

void move_word(point *s) {
	node* p = s->head;
	node* tmp;
	int pos = 0;
	if (p == NULL)
		return;
	else
		while (p != NULL) {
			if (p->y >= 18) { // �ٴ� ���޽� �ܾ������, ��������
				tmp = p;
				p = p->link;
				delete_node(s, tmp);
				hp--;
				if (hp <= 0)
					hp = 0;
			}
			else { // �ܾ� ��ǥ ������
				(p->y)++;
				p = p->link;
			}
		}
}