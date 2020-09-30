#include <stdio.h>                           //标准库
#include <string.h>                          //strcmp();
#include <stdlib.h>                          //system();srand();rand();
#include <unistd.h>                          //sleep();
#include <time.h>                            //time(NULL);
#include <sys/stat.h>
int ll;
struct data{
	int x;
	int x2;
	int g;
	int v;
}my={500,500,0,0},npc={500,500,0,0};
struct IF{
	char c;
	char s[20];
	int i;
};
struct save *new();
void cls();
void welcome();
void game();
void set();
void help();
float size();