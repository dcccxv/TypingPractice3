#ifndef NODE_STRUCT_H// 조건부 컴파일
#define NODE_STRUCT_H

#include"Global.h"

typedef struct node {
	char item[STRLENGTH];
	int x;
	int y;
	int effect;
	struct node *link;

}node;

typedef struct point {
	node *head;
	int length;
}point;

typedef struct snode {
	char stem[STRLENGTH];
	struct snode * link;
}snode;

typedef struct spoint {
	snode *head;
	int length;
}spoint;


#endif