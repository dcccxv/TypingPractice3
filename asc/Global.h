#ifndef GLOBAL_H// ���Ǻ� ������
#define GLOBAL_H

#define STRLENGTH 14
#define ROWS 16
#define COLS 20
#define HARDTIME 150
#define NOMALTIME 180
#define EASYTIME 210
#define ESC 0x1b
#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.
#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ���´�.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

extern int back_KOR_ENG;
extern int inputCount;
extern int KOR_ENG; // ***
extern char RecordName[21];
extern double Flame;// delay�Լ��� ���� ��
extern double typist; //�д� Ÿ��
extern int score; //����
extern int score_prop;
extern int hp; // ü��
extern int Record;
extern int Cusor_posX; // �Է�â Ŀ�� x��ǥ
extern int Cusor_posY;
extern int Limit; //���ѽð�
extern int LeftTime; // ����ð� 
extern int WordNum;
extern int gernerat_num; // �ѹ��� ������ �ܾ� ����
extern char Board[COLS][ROWS][STRLENGTH];
extern int level;
extern int difficulty;
extern int CheckEffect;
extern int Ef_swtich;
extern int ef_start1;
extern int ef_start2;
extern int ef_start3;
extern int ef_start4;
extern int ef1;// ü���������Լ�����  ef1�� 1�� ������  ����� y��ǥ�� �������� �� ����� ��� ������� �ʰ�
extern int ef2;
extern int ef3;
extern int ef4;
extern int ef2_xpos;
extern int WordIndex;
extern char InPutWord[STRLENGTH];
extern int level_Re_switch;
#endif