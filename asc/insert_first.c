#include"node_struct.h"
#include"delete_snode.h"

#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Global.h"

// ���ڰ� ���ʺ��� �����ϱ� ������ �ǳ��� ���ڰ� �������� �ܾ 5���ڿ����Ѵ�.
extern node* new_node;

void insert_first(point *s, spoint *t) { // ������ �� ��忡 �������� ���� �ܾ �ְ� x, y���� �������� �Է�
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

	while (i++ != generation && t->length > 0) { // generation�� �ѹ��� ��� �ܾ �����Ҳ��� , t�� ��尡 0���ϰ� �Ǹ� �� �̻� ��������.
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
				p = p->link;// ������ ��� ����
			new_node->link = p->link;
			p->link = new_node;
		}
		//�������� t�� ���(sp)�� �̾Ƽ� s�� ������� / t���� ���� ���� ����
		random = rand() % (t->length);
		if (random >= 0) {
			for (j = 0; j < random; j++) {
				sp = sp->link;
			}
			strcpy(new_node->item, sp->stem);
			delete_snode(t, sp);

			while (1) {
				tempX = ((rand() % 11) * 11) + 2; // ���ÿ� �������� �ܾ� ������ �ܾ�� x��ǥ�� ��ġ�� �ʰ�
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