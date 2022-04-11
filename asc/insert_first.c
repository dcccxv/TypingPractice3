#include"node_struct.h"
#include"delete_snode.h"

#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Global.h"

// 글자가 왼쪽부터 시작하기 때문에 맨끝에 글자가 닿으려면 단어가 5글자여야한다.
extern node* new_node;

void insert_first(point *s, spoint *t) { // 노드삽입 후 노드에 랜덤으로 뽑은 단어를 넣고 x, y값을 랜덤으로 입력
	int i = 0, g = 0, j = 0, h = 0;
	int random;
	int generation;
	int tempX;
	int arr[3] = { -1, -1, -1};
	node* p ;
	//node* new_node;
	snode* sp ;
	srand(time(NULL));
	generation = (rand() % gernerat_num) + 1;

	if (ef2 == 1) // ef2
		generation = 1;

	while (i++ != generation && t->length > 0) { // generation은 한번에 몇개의 단어를 생성할껀지 , t의 노드가 0이하가 되면 더 이상 생성안함.
		g = rand() % (100);
		p = s->head;
		sp = t->head;
		new_node = (node*)malloc(sizeof(node));

		if (p == NULL) {
			s->head = new_node;
			new_node->link = NULL;
		}
		else {
			while (p->link != NULL)
				p = p->link;// 마지막 노드 도착
			new_node->link = p->link;
			p->link = new_node;
		}
		//랜덤으로 t의 노드(sp)를 뽑아서 s에 집어넣음 / t에서 뽑은 노드는 삭제
		random = rand() % (t->length);
		if (random >= 0) {
			for (j = 0; j < random; j++) {
				sp = sp->link;
			}
			strcpy(new_node->item, sp->stem);
			delete_snode(t, sp);

			while (1) {
				tempX = ((rand() % 11) * 11) + 2; // 동시에 여러개의 단어 생성시 단어끼리 x좌표가 겹치지 않게
				if (tempX != arr[0] && tempX != arr[1] && tempX != arr[2])
					break;
			}
			if (ef2 == 1) // ef2
				new_node->x = ef2_xpos;
			else
				new_node->x = tempX;

			new_node->y = 0;

			if(Ef_swtich == 1)
			new_node->effect = (rand() % 120) + 1;

			else
			new_node->effect = 0;

			s->length++;
			arr[h++] = tempX;
		}
	}
}