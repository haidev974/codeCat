#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void gotoxy(int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void SetColor(int n) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, n);
}
void show(){
	printf("====================================\n");
	printf("==                                ==\n");
	printf("==                                ==\n");
	printf("==        PassWord:               ==\n");
	printf("==                                ==\n");
	printf("==                                ==\n");
	printf("==                                ==\n");
	printf("====================================\n");
}
void play(int i) {
	system("cls");
	gotoxy(0,0);
	FILE *f;
	char read[1000];
	switch(i){
		case 0: f = fopen("cat0.txt","r"); break;
		case 1: f = fopen("cat1.txt","r"); break;
		case 2: f = fopen("cat2.txt","r"); break;
		case 3: f = fopen("cat3.txt","r"); break;
		case 4: f = fopen("cat4.txt","r"); break;
		case 5: f = fopen("cat5.txt","r"); break;
		case 6: f = fopen("cat6.txt","r"); break;
		case 7: f = fopen("cat7.txt","r"); break;
		case 8: f = fopen("cat8.txt","r"); break;
		case 9: f = fopen("cat9.txt","r"); break;
	}
//read
	while (!feof(f)) {
		fgets(read,1000,f);
		printf("%s",read);
	}
	Sleep(20);
	fclose(f);
}

int main() {
	char key[4];
	printf("Enter password có 4 chu so . . .\n\n");
	show();
//luu y cach nhap password da duoc tac gia giau di ko chia se :))
	do{
		gotoxy(20,5);
		for(int i = 0; i < 4; i++){
			key[i] = getch();
			printf("*");
		}
		if(strcmp(key,"1111") != 0){
			gotoxy(11,7);
			printf("Error pasword!");
			gotoxy(20,5);
			printf("       ");
		}
	} while(strcmp(key,"1111") != 0);
	gotoxy(10,7);
	printf("Correct password!");
	getch();
	system("cls");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	Sleep(500);
	int color = 1;
	while(1){
		SetColor(color);
		color++;
		if(color>=16)	color=1;
		for(int i = 0; i <=9; i++){
			play(i);
		}
	}
	printf("\n\n\n");
}
