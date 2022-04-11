#include"node_struct.h"
#include<string.h>
#include<stdlib.h>

void delete_node(point *s, node *removed) {//노드 삭제
	node* p = s->head;

	if (p == removed) { // 가장 앞을 삭제시
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
