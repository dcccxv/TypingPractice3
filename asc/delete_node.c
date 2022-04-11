#include"node_struct.h"
#include<string.h>
#include<stdlib.h>

void delete_node(point *s, node *removed) {//��� ����
	node* p = s->head;

	if (p == removed) { // ���� ���� ������
		s->head = p->link;
		free(removed);
		s->length--;
	}
	else {
		while (p != NULL) {
			if (p->link == removed) {
				p->link = removed->link;
				break;
			}
			else
				p = p->link;
		}
		free(removed);
		s->length--;
	}
}
