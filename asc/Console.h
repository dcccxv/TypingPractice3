#ifndef CONSOLE_H// 조건부 컴파일
#define CONSOLE_H


#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15
void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void removeCursor(void);
void showCursor(void);
void erase_arrow(void);
void erase(int x, int y);
void blue_black(int x, int y);
void box(int x1, int x2, int y1, int y2);
void border(void);
#endif

