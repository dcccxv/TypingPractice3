#define _CRT_SECURE_NO_WARNINGS  // to disable deprecation in vs2015

#include<windows.h>
#include<string.h>
#include<stdio.h>
#include"MainMenu.h"
#include"Global.h"

int main(void) {
	while (TRUE) {
		system("mode con:cols=150 lines=30"); 
		MainMenu();
	}
}