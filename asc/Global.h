#ifndef GLOBAL_H// 조건부 컴파일
#define GLOBAL_H

#define STRLENGTH 14
#define ROWS 16
#define COLS 20
#define HARDTIME 150
#define NOMALTIME 180
#define EASYTIME 210
#define ESC 0x1b
#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.
#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

extern int back_KOR_ENG;
extern int inputCount;
extern int KOR_ENG; // ***
extern char RecordName[21];
extern double Flame;// delay함수에 넣을 값
extern double typist; //분당 타수
extern int score; //점수
extern int score_prop;
extern int hp; // 체력
extern int Record;
extern int Cusor_posX; // 입력창 커서 x좌표
extern int Cusor_posY;
extern int Limit; //제한시간
extern int LeftTime; // 현재시간 
extern int WordNum;
extern int gernerat_num; // 한번에 생성할 단어 개수
extern char Board[COLS][ROWS][STRLENGTH];
extern int level;
extern int difficulty;
extern int CheckEffect;
extern int Ef_swtich;
extern int ef_start1;
extern int ef_start2;
extern int ef_start3;
extern int ef_start4;
extern int ef1;// 체인지보드함수에서  ef1이 1인 동안은  노드의 y좌표가 게임판의 반 상단인 경우 출력하지 않게
extern int ef2;
extern int ef3;
extern int ef4;
extern int ef2_xpos;
extern int WordIndex;
extern char InPutWord[STRLENGTH];
extern int level_Re_switch;
#endif