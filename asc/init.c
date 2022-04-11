#include"node_struct.h"
#include<string.h>

void init(point *s) { // 리스트초기화
	s->head = NULL;
	s->length = 0;
}
void sinit(spoint *t) {
	t->head = NULL;
	t->length = 0;
}