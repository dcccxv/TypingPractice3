#include"node_struct.h"
#include<string.h>
#include<stdlib.h>

void delete_snode(spoint *t, snode* removed) {//노드 삭제
	snode* p = t->head;

	if (p == removed) { // 가장 앞을 삭제시
		t->head = p->link;
		free(removed);
		t->length--;
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
		t->length--;
	}
}


